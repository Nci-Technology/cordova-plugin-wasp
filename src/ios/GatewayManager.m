//
//  GatewayManager.m
//  ShowSensorsObjc
//
//  NPEGATE SAMPLE Copyright © 2012-2016 by North Pole Engineering, Inc.  All rights reserved.
//
//  Printed in the United States of America.  Except as permitted under the United States
//  Copyright Act of 1976, no part of this software may be reproduced or distributed in
//  any form or by any means, without the prior written permission of North Pole
//  Engineering, Inc., unless such copying is expressly permitted by federal copyright law.
//
//  Address copying inquires to:
//  North Pole Engineering, Inc.
//  Joe Tretter
//  221 North First St. Ste. 310
//  Minneapolis, Minnesota 55401
//
//  Information contained in this software has been created or obtained by North Pole Engineering,
//  Inc. from sources believed to be reliable.  However, North Pole Engineering, Inc. does not
//  guarantee the accuracy or completeness of the information published herein nor shall
//  North Pole Engineering, Inc. be liable for any errors, omissions, or damages arising
//  from the use of this software.
//

#import "GatewayManager.h"
#import "SensorSet.h"


NSString * const kNewSensorFound = @"kNewSensorFound";

@interface GatewayManager () <NPESensorConnectionDelegate>{
    NSMutableArray *_SensorSets;
}

@property (nonatomic, strong) NPEHardwareConnector *gatewayConection;
@property (nonatomic, strong) NSMutableArray *sensorsArray;
@property (nonatomic, strong) NSMutableArray *sensorSetArray;

@end

@implementation GatewayManager


+ (instancetype)sharedManager {
    static dispatch_once_t onceToken;
    static GatewayManager *instance;
    
    dispatch_once(&onceToken, ^{
        instance = [[self alloc] initManager];
    });
    
    return instance;
}

- (instancetype)init {
    NSLog(@"Init should not be called directly.  Use one of the designated Shared instance methods");
    [super doesNotRecognizeSelector:_cmd];
    return nil;
}

- (instancetype)initManager {
    self = [super init];
    
    if (self != nil) {
        
        _enablePosts = TRUE;
        [NPELogEvents sharedLogger].loggingMask = NPELogEventMaskAll;
        
        _gatewayConection = [NPEHardwareConnector sharedConnector];

        //New for 2.1
        //Allows for only monitoring specific Services (WASP, Keiser Multibike Receiver, and USB for macOS)
        [_gatewayConection startMonitoringNetworkWithServices:NPEGatewayServicesAll];

        _sensorsArray = [[NSMutableArray alloc] init];
        _sensorSetArray = [[NSMutableArray alloc] init];

        [self setupConnectionToGateway];
    }
    return self;
}

- (void)setupConnectionToGateway {

    __weak __typeof(self)weakSelf = self;

    [self.gatewayConection addWaspStateChangeObserver:self onStateChange:^(Wasp * _Nonnull wasp, WaspDiscoveryState state) {
        /// Here you could create your own set of WASPS
    }];

    [self.gatewayConection addSensorStateChangeObserver:self onStateChange:^(NPESensorConnection * _Nonnull sensor, SensorDiscoveryState state) {

        switch (state) {
            case SensorDiscoveryStateConnected: {

                NSString *sName = [NPEHardwareConnector stringValueForSensorType:sensor.typeOfSensor];

                //Add the Connection to our Sensors array
                [weakSelf.sensorsArray addObject:sensor];


                //Now Lets add it to the SensorSets array or Create a new set
                BOOL found = FALSE;

                for (SensorSet *senset in [weakSelf.sensorSets copy]) {
                    if ([senset.name isEqualToString:sName]) {
                        [senset addSensorsObject:sensor];
                        sensor.delegate = weakSelf;

                        found = TRUE;
                        break;
                    }
                }

                if (found != TRUE) {
                    SensorSet *newset = [[SensorSet alloc] initWithName:sName];
                    [newset addSensorsObject:sensor];

                    sensor.delegate = weakSelf;
                    [weakSelf.sensorSetArray addObject:newset];
                }

                if(weakSelf.enablePosts) { [[NSNotificationCenter defaultCenter] postNotificationName:kNewSensorFound object:weakSelf userInfo:nil]; }

                break;
            }
                
            case SensorDiscoveryStateDisconnecting: {
                
                NSLog(@"SensorDiscoveryStateDisconnecting");
                
                NSString *sName = [NPEHardwareConnector stringValueForSensorType:sensor.typeOfSensor];
                [weakSelf.sensorsArray removeObject:sensor];
                
                for (SensorSet *senset in [weakSelf.sensorSets copy]) {
                    
                    if ([senset.name isEqualToString:sName]) {
                        
                        [senset removeSensorsObject:sensor];
                        break;
                    }
                }
                if(weakSelf.enablePosts) { [[NSNotificationCenter defaultCenter] postNotificationName:kNewSensorFound object:weakSelf userInfo:nil]; }
                break;
            }
                
            default:
                break;
        }

    }];
}

- (NSArray<Wasp *> *)allWasps {
    return [self.gatewayConection.knownWasps allObjects];
}

- (NSArray<NPESensorConnection *> *)sesnsor {
    return self.sensorsArray.copy;
}

- (NSArray<SensorSet *> *)sensorSets {
    return self.sensorSetArray.copy;
}

#pragma - SensorCon Delegate

- (void)connection:(NPESensorConnection *)connectionInfo didReceiveData:(NPESensorData *)data {
    
//    NSLog(@"DATA: %@", data.parameterList);
    [self.gatewayConection removeAllInactiveSensors];
}


@end
