/********* WaspHRMCollectorPlugin.m Cordova Plugin Implementation *******/

#import <Cordova/CDV.h>
#import "GatewayManager.h"
#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <NetworkExtension/NetworkExtension.h>
#import <SystemConfiguration/CaptiveNetwork.h>


@interface WaspHRMCollectorPlugin : CDVPlugin <CLLocationManagerDelegate> {
    // Member variables go here.
}

- (void)doBind:(CDVInvokedUrlCommand*)command;
- (void)stopListener:(CDVInvokedUrlCommand*)command;
- (void)requestWaspConfig:(CDVInvokedUrlCommand*)command;
- (void)getCurrentWaspConfig:(CDVInvokedUrlCommand*)command;
- (void)scanForWifiNetworks:(CDVInvokedUrlCommand*)command;
- (void)setWifiConfig:(CDVInvokedUrlCommand*)command;

@end

#pragma mark - Constants + Util Funcs

static NSString* securityModeStringFrom(SecurityMode securityMode) {
    NSDictionary *supportedSecurityModeStrings = @{ 
        [NSNumber numberWithInteger:SecurityModeNone]:    @"NONE",
        [NSNumber numberWithInteger:SecurityModeWPA]:     @"WPA",
        [NSNumber numberWithInteger:SecurityModeWPA2]:    @"WPA2",
        [NSNumber numberWithInteger:SecurityModeWEPShared]:     @"WEP",
    };

    NSNumber *primarySecurityNum = [NSNumber numberWithInteger:securityMode];
    NSString *primarySecurityString = [supportedSecurityModeStrings objectForKey: primarySecurityNum];
    if (!primarySecurityString) primarySecurityString = @"OTHER";
    return primarySecurityString;
}

#pragma mark - Implementation 

@implementation WaspHRMCollectorPlugin


CDVPluginResult *pluginResult = nil;
CDVInvokedUrlCommand *lastCommand = nil;

Wasp *selectedWasp;
BOOL gotWasp = false;
BOOL ignoreWifiPrefixCheck = false;

NSString *waspCurrentState;
NSString * const TAG = @"WHRMCPlugin";

NSDictionary *waspConfig;
NSInteger selectedMethod;
NSMutableArray *sensorArray = nil;
NSMutableArray *sensorDataArray = nil;
CLLocationManager *locationManager = nil;

typedef enum Methods {
    
    DoBind = 1,
    RequestWaspConfig,
    GetCurrentWaspConfig,
    ScanForWifi,
    SetWifiConfig,
    ResetToOemDefaults,
    
} MethodName;


#pragma mark - Cordova Methods

- (void)doBind:(CDVInvokedUrlCommand*)command {
    
    NSLog(@"%@: doBind/startListener", TAG);
    lastCommand = command;
    selectedMethod = DoBind;
    
    if (sensorArray == nil) {
        NSLog(@"%@: doBind/startListener inited...", TAG);
        sensorArray = [NSMutableArray array];
        sensorDataArray = [NSMutableArray array];
        [[[GatewayManager sharedManager] gatewayConection] setSensorFilterWhiteList:[NSArray arrayWithObject:[NPESensorFilter initWithDeviceType:NPESensorTypeHeartrate]]];
        [[GatewayManager sharedManager] setEnablePosts:FALSE]; // Manually enable with other related setup later
    }

    if ([[GatewayManager sharedManager] enablePosts]) {
        NSLog(@"%@: doBind/startListener reissue!", TAG);
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"E100: doBind()/startListener() reissue!"];
        [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
    } else {
        // This section called both during first start as well as restarts
        NSLog(@"%@: doBind/startListener add observers...", TAG);
        [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(actionSensorConnectDisconnect) name:kNewSensorFound object:nil];
        [[GatewayManager sharedManager] setEnablePosts:TRUE];

        // No pluginResult sent here, success callbacks receive sensorData periodically
        [self populateSensorArraysAndObservers];
    }
}


- (void)stopListener:(CDVInvokedUrlCommand*)command {
    
    NSLog(@"%@: stopListener", TAG);
    if (sensorArray == nil || ![[GatewayManager sharedManager] enablePosts]) {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"E101: stopListener() while stopped!"];
        [pluginResult setKeepCallbackAsBool:NO];
        [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
        return;
    }

    [[GatewayManager sharedManager] setEnablePosts:FALSE];
    [self clearSensorArraysAndObservers];

    [[NSNotificationCenter defaultCenter] removeObserver:self name:kNewSensorFound object:nil];
    pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
    [pluginResult setKeepCallbackAsBool:NO];
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}


- (void)requestWaspConfig:(CDVInvokedUrlCommand*)command {
    
    lastCommand = command;
    ignoreWifiPrefixCheck = false;
    NSString* echo = [command.arguments objectAtIndex:0];
    NSLog(@"%@: requestWaspConfig: echo: %@", TAG, echo);
    selectedMethod = RequestWaspConfig;
    if(locationManager == nil) { [self actionLocationAccess]; }
    [self checkWifiSSIDAndContinue];
}


- (void)getCurrentWaspConfig:(CDVInvokedUrlCommand*)command {
    
    lastCommand = command;
    ignoreWifiPrefixCheck = true;
    NSString* echo = [command.arguments objectAtIndex:0];
    NSLog(@"%@: getCurrentWaspConfig: echo: %@", TAG, echo);
    selectedMethod = GetCurrentWaspConfig;
    if(locationManager == nil) { [self actionLocationAccess]; }
    [self checkWifiSSIDAndContinue];
}


- (void)scanForWifiNetworks:(CDVInvokedUrlCommand*)command {
    
    lastCommand = command;
    ignoreWifiPrefixCheck = false;
    NSString* echo = [command.arguments objectAtIndex:0];
    NSLog(@"%@: scanForWifiNetworks: echo: %@", TAG, echo);
    selectedMethod = ScanForWifi;
    if(locationManager == nil) { [self actionLocationAccess]; }
    [self checkWifiSSIDAndContinue];
}


- (void)setWifiConfig:(CDVInvokedUrlCommand*)command {
    
    lastCommand = command;
    ignoreWifiPrefixCheck = false;
    NSDictionary* echo = [command.arguments objectAtIndex:0];
    NSLog(@"%@: setWifiConfig: echo: %@", TAG, echo);
    waspConfig = echo;
    selectedMethod = SetWifiConfig;
    if(locationManager == nil) { [self actionLocationAccess]; }
    [self checkWifiSSIDAndContinue];
}

- (void)resetToOemDefaults:(CDVInvokedUrlCommand*)command {
    
    lastCommand = command;
    ignoreWifiPrefixCheck = false;
    NSDictionary* echo = [command.arguments objectAtIndex:0];
    NSLog(@"%@: resetToOemDefaults : echo: %@", TAG, echo);
    selectedMethod = ResetToOemDefaults;
    if(locationManager == nil) { [self actionLocationAccess]; }
    [self checkWifiSSIDAndContinue];
}

#pragma mark - User Def Methods

- (void)clearSensorArraysAndObservers {
    for(NPESensorConnection *sensor in sensorArray)
        [sensor removeSensorDataObserver:self];
    [sensorArray removeAllObjects];
    [sensorDataArray removeAllObjects];
}

- (void)populateSensorArraysAndObservers {
    SensorSet *senSet = [GatewayManager sharedManager].sensorSets[0];
    for(NPESensorConnection *sensor in senSet.sensors) {

        [sensorArray addObject:sensor];
        NSDictionary *dict = [NSDictionary dictionaryWithObjectsAndKeys:sensor.deviceIDString, @"deviceNumber",
                     @"", @"rssi",
                     @"", @"packetsPerSecond",
                     @"", @"heartRate",
                     @"", @"lastSeenTimestampMS",
                     @"0", @"lastHeartBeatCount",
                     @"", @"version",
                     nil];
        [self addSensorDataObserverFor:sensor];
        [sensorDataArray addObject:dict];
    }
}

- (void)actionSensorConnectDisconnect {
    
    NSLog(@"%@: actionSensorConnectDisconnect", TAG);

    [self clearSensorArraysAndObservers];

    if([GatewayManager sharedManager].sensorSets.count > 0) {
        
        SensorSet *senSet = [GatewayManager sharedManager].sensorSets[0];
        if(senSet.sensors.count > 0) {
            
            [self populateSensorArraysAndObservers];

            NSData *jsonData = [NSJSONSerialization dataWithJSONObject:sensorDataArray options:NSJSONWritingPrettyPrinted error:nil];
            NSString *jsonString = [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
            
            pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:jsonString];
            [pluginResult setKeepCallbackAsBool:YES];
            [self.commandDelegate sendPluginResult:pluginResult callbackId:lastCommand.callbackId];
        }
        else {
            
            NSLog(@"%@: actionSensorConnectDisconnect: No HR Sensors Found", TAG);
            NSData *jsonData = [NSJSONSerialization dataWithJSONObject:[NSArray array] options:NSJSONWritingPrettyPrinted error:nil];
            NSString *jsonString = [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
            pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:jsonString];
            [pluginResult setKeepCallbackAsBool:YES];
            [self.commandDelegate sendPluginResult:pluginResult callbackId:lastCommand.callbackId];
        }
    }
    else {
        
        NSLog(@"%@: actionSensorConnectDisconnect: No SensorSets Found", TAG);
        NSData *jsonData = [NSJSONSerialization dataWithJSONObject:[NSArray array] options:NSJSONWritingPrettyPrinted error:nil];
        NSString *jsonString = [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:jsonString];
        [pluginResult setKeepCallbackAsBool:YES];
        [self.commandDelegate sendPluginResult:pluginResult callbackId:lastCommand.callbackId];
    }
}


- (void)addSensorDataObserverFor:(NPESensorConnection *)sensor {
    
    __weak __typeof(sensor) weakSensor = sensor;
    NSString *sID = sensor.deviceIDString;
    [sensor addSensorDataObserver:self block:^(NPESensorData *data) {
        
        NSInteger rssi = [[data getParameterValueForKey:NPESensorDataParameterKeyRSSI onlyIfValid:YES] integerValue];
        double pps = [[data getParameterValueForKey:NPESensorDataParameterKeyPPS onlyIfValid:YES] doubleValue];
        NSString *hr = [[data getParameterValueForKey:NPESensorDataParameterKeyHeartRate onlyIfValid:YES] stringValue];
        NSTimeInterval lastHBtime = data.lastDataTime;
        
        NSDictionary *dict = [NSDictionary dictionaryWithObjectsAndKeys:sID, @"deviceNumber",
                              [NSString stringWithFormat:@"%ld",(long)rssi], @"rssi",
                              [NSString stringWithFormat:@"%f",pps], @"packetsPerSecond",
                              hr, @"heartRate",
                              [NSString stringWithFormat:@"%f",lastHBtime], @"lastSeenTimestampMS",
                              @"0", @"lastHeartBeatCount",
                              nil];
        
        dispatch_async(dispatch_get_main_queue(), ^{
            
            if([sensorArray containsObject:weakSensor]) {
                
                NSUInteger index = [sensorArray indexOfObject:weakSensor];
                [sensorDataArray replaceObjectAtIndex:index withObject:dict];
                
                NSData *jsonData = [NSJSONSerialization dataWithJSONObject:sensorDataArray options:NSJSONWritingPrettyPrinted error:nil];
                NSString *jsonString = [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
                
                pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:jsonString];
                [pluginResult setKeepCallbackAsBool:YES];
                [self.commandDelegate sendPluginResult:pluginResult callbackId:lastCommand.callbackId];
            }
        });
    }];
}


- (void)actionLocationAccess {
    
    locationManager = [CLLocationManager new];
    [locationManager requestWhenInUseAuthorization];
    locationManager.delegate = self;
    [locationManager requestLocation];
}


- (void)checkWifiSSIDAndContinue {
    
    NSString *wifiSSID = nil;
    NSArray *ifs = (__bridge_transfer id)CNCopySupportedInterfaces();
    for (NSString *ifnam in ifs) {
        NSDictionary *info = (__bridge_transfer id)CNCopyCurrentNetworkInfo((__bridge CFStringRef)ifnam);
        if (info[@"SSID"]) {
            wifiSSID = info[@"SSID"];
        }
    }
    NSLog(@"%@: checkWifiSSIDAndContinue : SSID : %@", TAG,wifiSSID);
    
    if([[wifiSSID lowercaseString] hasPrefix:@"wasp"] || ignoreWifiPrefixCheck) {
        
        gotWasp = true;
        [[[GatewayManager sharedManager] gatewayConection] lookForAnyWasp];
        NSLog(@"%@: checkWifiSSIDAndContinue : -> actionWaspStatusChange()", TAG);
        [self actionWaspStatusChange];
    }
    else {
        
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"E200: Unrecoginised WASP SSID prefix"];
        [pluginResult setKeepCallbackAsBool:YES];
        [self.commandDelegate sendPluginResult:pluginResult callbackId:lastCommand.callbackId];
    }
}


- (void)actionWaspStatusChange {
    NSLog(@"%@: actionWaspStatusChange", TAG);
    
    NSArray *waspArray =  [[GatewayManager sharedManager] allWasps];
    if(waspArray.count > 0) {
        
        selectedWasp = waspArray[0];
        [selectedWasp addWaspConnectionStatusObserver:self withBlock:^(Wasp *waspObj, NSString *state) {
            
            waspCurrentState = state;
            NSLog(@"%@: waspConnectionStatusObserver: %@", TAG, state);

            if([state isEqual:@"Requesting"]) {
                
            }
            else if([state isEqual:@"Not Available"]) {
                [self actionWaspError:state];
            }
            else if([state isEqual:@"Connected"]) {
                [self actionWaspRequestReady];
            }
            else if([state isEqual:@"Busy"]) {
                [self actionWaspError:state];
            }
            else if([state isEqual:@"Available"]) {
                [self actionWaspRequestReady];
            }
            else {
                
            }
        }];
        NSLog(@"%@: actionWaspStatusChange: -> requestDataConnection()", TAG);
        [selectedWasp requestDataConnection];
    }
    else {
        NSLog(@"%@: actionWaspStatusChange: No Wasps!", TAG);
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"E201: No Wasps Found"];
        [self.commandDelegate sendPluginResult:pluginResult callbackId:lastCommand.callbackId];
    }
}


- (void)actionWaspError:(NSString*)state {
    NSString *errorString = [NSString stringWithFormat:@"%@ %@", @"E202: Wasp com error: ", state];
    pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:errorString];
    [self.commandDelegate sendPluginResult:pluginResult callbackId:lastCommand.callbackId];
}


- (void)actionWaspRequestReady {
    NSLog(@"%@: actionWaspRequestReady", TAG);

    [selectedWasp removeWaspConnectionStatusObserver:self];
    
    switch (selectedMethod) {
            
        case RequestWaspConfig: {
            pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@"Success"];
            [self.commandDelegate sendPluginResult:pluginResult callbackId:lastCommand.callbackId];
            break;
        }
            
        case GetCurrentWaspConfig: {
            NSDictionary *dict = [NSDictionary dictionaryWithObjectsAndKeys:
                selectedWasp.name, @"waspName",
                selectedWasp.ipAddress, @"ipAddress",
                selectedWasp.primarySSID, @"primarySSID",
                selectedWasp.vendorName, @"vendorName",
                selectedWasp.vendorHardwareName, @"vendorHardwareName",
                selectedWasp.firmwareVersion, @"firmwareVersion",
                securityModeStringFrom(selectedWasp.primarySecurity), @"primarySecurity",
                nil];
            NSData *jsonData = [NSJSONSerialization dataWithJSONObject:dict options:NSJSONWritingPrettyPrinted error:nil];
            NSString *jsonString = [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
            pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:jsonString];
            [self.commandDelegate sendPluginResult:pluginResult callbackId:lastCommand.callbackId];
            break;
        }
            
        case ScanForWifi: {
            [NSTimer scheduledTimerWithTimeInterval:30 target:self selector:@selector(actionStopWifi) userInfo:nil repeats:NO];
            [selectedWasp scanForWifiNetworks:^(NSArray *accessPoints, BOOL *stop) {
                
                [NSObject cancelPreviousPerformRequestsWithTarget:self selector:@selector(actionStopWifi) object:nil];
                [NSTimer scheduledTimerWithTimeInterval:30 target:self selector:@selector(actionStopWifi) userInfo:nil repeats:NO];
                
                NSMutableArray *arrayWifi = [NSMutableArray array];
                NSLog(@"%@: selectedWasp: scanForWifiNetworks: stop : %@", TAG, *stop?@"Yes":@"No");
                if(*stop == NO) {
                    
                    for(AccessPoint *accPoint in accessPoints) {
                        
                        NSMutableDictionary *dict = [NSMutableDictionary dictionary];
                        [dict setValue:accPoint.sSSID forKey:@"ssid"];
                        [dict setValue:[NSNumber numberWithInteger:accPoint.rssi] forKey:@"rssi"];
                        [dict setValue:accPoint.security forKey:@"security"];
                        [arrayWifi addObject:dict];
                    }
                    
                    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:arrayWifi options:NSJSONWritingPrettyPrinted error:nil];
                    NSString *jsonString = [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
                    pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:jsonString];
                    [pluginResult setKeepCallbackAsBool:YES];
                    [self.commandDelegate sendPluginResult:pluginResult callbackId:lastCommand.callbackId];
                }
                else {
                    
                    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:[NSMutableArray array] options:NSJSONWritingPrettyPrinted error:nil];
                    NSString *jsonString = [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
                    pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:jsonString];
                    [self.commandDelegate sendPluginResult:pluginResult callbackId:lastCommand.callbackId];
                }
            }];
            break;
        }
            
        case SetWifiConfig: {
            if(waspConfig) {
                [selectedWasp openControlSession];
                selectedWasp.primarySSID = [waspConfig objectForKey:@"primarySSID"];
                selectedWasp.primaryPassPhrase = [waspConfig objectForKey:@"primaryPassPhrase"];
                NSDictionary *supportedSecurityModes = @{ 
                    @"NONE": [NSNumber numberWithInteger:SecurityModeNone],
                     @"WPA": [NSNumber numberWithInteger:SecurityModeWPA],
                    @"WPA2": [NSNumber numberWithInteger:SecurityModeWPA2],
                     @"WEP": [NSNumber numberWithInteger:SecurityModeWEPShared],
                };
                NSNumber *sm = [supportedSecurityModes objectForKey:[waspConfig objectForKey:@"securityMode"]];
                if (!sm) sm = [NSNumber numberWithInteger:SecurityModeWPA2];
                selectedWasp.primarySecurity = [sm integerValue];
                if (selectedWasp.controlSocketOpened) {
                    [selectedWasp updateWaspConfig:YES];
                    pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@"Issued"];
                    [self.commandDelegate sendPluginResult:pluginResult callbackId:lastCommand.callbackId];
                } else {
                    pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"E203: Control grab failed"];
                    [self.commandDelegate sendPluginResult:pluginResult callbackId:lastCommand.callbackId];
                }
                [selectedWasp endControlSession];
            }
            break;
        }

        case ResetToOemDefaults: {
                [selectedWasp openControlSession];
                [selectedWasp resetToOemDefaults];
                if (selectedWasp.controlSocketOpened) {
                    [selectedWasp updateWaspConfig:YES];
                    pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@"Issued"];
                    [self.commandDelegate sendPluginResult:pluginResult callbackId:lastCommand.callbackId];
                } else {
                    pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"E203: Control grab failed"];
                    [self.commandDelegate sendPluginResult:pluginResult callbackId:lastCommand.callbackId];
                }
                [selectedWasp endControlSession];
            break;
        }
            
        default:
            break;
    }
}


- (void)actionStopWifi {
    
    pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@"Wifi scan done"];
    [self.commandDelegate sendPluginResult:pluginResult callbackId:lastCommand.callbackId];
}


- (void)locationManager:(CLLocationManager *)manager didUpdateLocations:(NSArray<CLLocation *> *)locations {
    
    if(gotWasp) { return; }
    
    switch (selectedMethod) {
            
        case DoBind:
            break;
            
        case RequestWaspConfig:
            [self requestWaspConfig:lastCommand];
            break;
            
        case GetCurrentWaspConfig:
            [self getCurrentWaspConfig:lastCommand];
            break;
            
        case ScanForWifi:
            [self scanForWifiNetworks:lastCommand];
            break;
            
        case SetWifiConfig:
            [self setWifiConfig:lastCommand];
            break;

        case ResetToOemDefaults:
            [self resetToOemDefaults:lastCommand];
            break;
            
        default:
            break;
    }
}


- (void)locationManager:(CLLocationManager *)manager didFailWithError:(NSError *)error {
    
    if(gotWasp) { return; }
    
    [locationManager requestWhenInUseAuthorization];
    [locationManager requestLocation];
}


@end
