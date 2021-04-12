//
//  NPEHardwareConnector.h
//  NpeGate
//
//  NPEGATE Copyright © 2012-2018 by North Pole Engineering, Inc.  All rights reserved.
//
//  Printed in the United States of America.  Except as permitted under the United States
//  Copyright Act of 1976, no part of this software may be reproduced or distributed in
//  any form or by any means, without the prior written permission of North Pole
//  Engineering, Inc., unless such copying is expressly permitted by federal copyright law.
//
//  Address copying inquires to:
//  North Pole Engineering, Inc.
//  npe@npe-inc.com
//  221 North First St. Ste. 310
//  Minneapolis, Minnesota 55401
//
//  Information contained in this software has been created or obtained by North Pole Engineering,
//  Inc. from sources believed to be reliable.  However, North Pole Engineering, Inc. does not
//  guarantee the accuracy or completeness of the information published herein nor shall
//  North Pole Engineering, Inc. be liable for any errors, omissions, or damages arising
//  from the use of this software.
//

#import <Foundation/Foundation.h>
#import <NpeGate/NPEHardwareConnectorDelegate.h>
#import <NpeGate/NPESensorConnection.h>
#import <NpeGate/NPESensorImage.h>
#import <NpeGate/NPEANT.h>

NS_ASSUME_NONNULL_BEGIN
/**
 Keys for The Connected Sensors Dictionary
 */
FOUNDATION_EXPORT NSString * const kNPEConnectedSensorsDeviceTypeKey;
FOUNDATION_EXPORT NSString * const kNPEConnectedSensorsDeviceIDKey;
FOUNDATION_EXPORT NSString * const kNPEConnectedSensorsSensorTypeKey;
FOUNDATION_EXPORT NSString * const kNPEConnectedSensorsDeviceTypeCategoryKey;
FOUNDATION_EXPORT NSString * const kNPEConnectedSensorsTransmissionTypeKey;
FOUNDATION_EXPORT NSString * const kNPEConnectedSensorsSensorConnectionKey;
FOUNDATION_EXPORT NSString * const kNPEConnectedSensorsVirtualParentKey;


@class NPESensorConnection;
@class NPESensorData;
@class Wasp;
@class NPEReachability;
@class NPEWaspPoeDistressBeacon;
@class NPESensorFilter;

@protocol NPEHardwareConnectorDelegate;

/**
 Defines the Gateway Services for the Framework
 
 @since 2.1
 */
typedef NS_OPTIONS(NSInteger, NPEGatewayServices) {
    /** WASP Gateway Service */
    NPEGatewayServicesWasp              = 1 << 0,
    /** USB WASP Gateway Service */
    NPEGatewayServicesWaspUsb           = 1 << 1,
    /** Keiser Multibike Receiver Service */
    NPEGatewayServicesKeiserReceiver    = 1 << 2,

    /** All Available Services */
    NPEGatewayServicesAll               = (NPEGatewayServicesWasp | NPEGatewayServicesWaspUsb | NPEGatewayServicesKeiserReceiver)
};

/**
 Describes the Discovery States of the WASP Hardware
 
 @since 2.0
 */
typedef NS_ENUM(NSInteger, WaspDiscoveryState) {
    WaspDiscoveryStateUnknown       = 0,
    /** A WASP has been found but we don't have all information yet */
    WaspDiscoveryStateFound         = 1,
    /** WASP has been discovered and Information regarding itself has been read */
    WaspDiscoveryStateKnown         = 2,
    /** WASP is being released.  The WASP is no longer present on the network */
    WaspDiscoveryStateReleasing     = 3,
};


///---------------------------------------------------------------------------------------
/// Block Typedefs
///---------------------------------------------------------------------------------------

typedef BOOL (^WaspFliterBlock)(Wasp *wasp);

/**
 WASP Discovery Observer Block 
 
 @param wasp The WASP that is changing state
 @param state The State the WASP has changed to.
 @since 2.1.0
 */
typedef void (^WaspStateChangeObserverBlock)(Wasp *wasp, WaspDiscoveryState state);

/**
 NPESensorConnection Discovery Observer Block

 @param sensor The Sensor that is changing state
 @param state The State the Sensor has changed to.
 @since 3.0
 */
typedef void (^SensorStateChangeObserverBlock)(NPESensorConnection *sensor, SensorDiscoveryState state);

/**
 WASP PoE Distress Beacon Observer Block
 
 @param beacon The WASP PoE Distress Beacon
 @since 2.2.0
 */
typedef void (^WaspPoeDistressObserverBlock)(NPEWaspPoeDistressBeacon *beacon);


/**
 * The NPEHardwareConnector represents the bridge between the WASP network device
 * and the application.
 *
 * The connector, along with the NPEHardwareConnectorDelegate protocol, provide
 * an interface to the WASP hardware.  The connector is used to configure
 * the device and obtain the latest data from the sensors.  The delegate
 * protocol updates the delegate of status changes to the sensors and data
 * availability.
 */
@interface NPEHardwareConnector: NSObject


/**
 * Returns the singleton NPEHardwareConnector instance.
 *
 * The NPEHardwareConnector is enforced as a singleton.
 * This method may be used to obtain a reference to that instance.  If the
 * instance does not yet exist when this method is invoked, it will be created.
 *
 * @return The NPEHardwareConnector singleton instance.
 */
+ (NPEHardwareConnector *)sharedConnector;

/**
 Unavailable. Use `+sharedConnector` to retrieve the shared Connector.
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 * Gets or sets the NPEHardwareConnectorDelegate which will handle delegated
 * methods from the NPEHardwareConnector.
 */
@property (nonatomic, weak) id <NPEHardwareConnectorDelegate> delegate;

/**
 * Gets the current WASP API version string.
 */
@property (nonatomic, readonly) NSString *apiVersion;

/**
 Starts Monitoring for the list of provided Services and starts processing the Sensor Data.
 
 @note If you have an OEM Branded WASP you will need to use startMonitoringWithOEMKeys:andServices
 @since 2.1
 */
- (void)startMonitoringNetworkWithServices:(NPEGatewayServices)services;

///---------------------------------------------------------------------------------------
/// @name OEM Setup
///---------------------------------------------------------------------------------------

/**
 If you are using a OEM Branded WASP, you will need to start the Monitoring of the Network with your provided OEM Key(s).

 @param oemKeys An array of OEM Keys
 @param services Bitmask of the Gateway Services to monitor
 @note If you are using a NPE Branded WASP use startMonitoringNetworkWithServices:
 @since 2.1
*/
- (void)startMonitoringNetworkWithOEMKeys:(NSArray *)oemKeys andServices:(NPEGatewayServices)services;


///---------------------------------------------------------------------------------------
/// @name Multicast
///---------------------------------------------------------------------------------------

/** 
 The Multicast Group IP.
 
 This should not be changed unless you have specifically changed the WASP route tables to send the UDP packets on the non default address.
 
 @since 2.0
 */
@property (nonatomic, strong) NSString *multicastGroupIP;

/**
 The port to use for Multicast listening.
 
 This should not be changed unless you have specifically changed the WASP route tables to send the UDP packets on the none default multicast port.
 
 @note default is 51113
 @since 2.0
 */
@property (nonatomic, assign) NSInteger multicastPort;


///---------------------------------------------------------------------------------------
/// @name Network Information
///---------------------------------------------------------------------------------------

/**
 * Holds the current ip Address of the device running the Framework in an array
 */
@property (nonatomic, readonly) NSArray<NSString *> *ipAddr __deprecated_msg("no longer supported");

/**
 String Value of the IP Address of the current host running the Framework
 
 @since 2.0
 */
@property (nonatomic, readonly, nullable) NSString *ipAddress;

/**
 * Holds the current SSID of the connected WiFi network in a string
 */
@property (nonatomic, readonly, strong, nullable) NSString *networkName;

/**
 Gets a boolean value indicating whether the device has hardware support for Wifi.
 On macOS machines this will indicate that no IP address was found.

 */
@property (nonatomic, readonly) BOOL hasWifiSupport;

///---------------------------------------------------------------------------------------
/// @name Data Access
///---------------------------------------------------------------------------------------
#pragma mark - NPEHardwareConnector Data Access Methods

/**
 * All sensors have a device type declared in the Framework.
 *
 * This method returns the defined sensor type based on the char received
 * in the extended data of the ANT message.
 *
 * @param devType The ANT Device Type
 * @return NPESensorType representing the sensor type.
 */
+ (NPESensorType)getDeviceType:(NPEAntDeviceType)devType;

/**
 * All sensors have a device type declared in the Framework.
 *
 * This method returns the defined sensor type based on the char received
 * in the extended data of the ANT message.
 *
 * @param devType The ANT Device Type
 * @param transType The ANT Transmission Type
 * @return NPESensorType representing the sensor type.
 */
+ (NPESensorType)getDeviceType:(NPEAntDeviceType)devType withTransType:(NPEAntTransType)transType;

/**
 Provides a String Value for the NPESensorType

 @param type The NPESensorType
 @returns String Value for the Sensor Type
 */
+ (NSString *)stringValueForSensorType:(NPESensorType)type;

/**
 Provides the ANT Device Type for a Given NPESensorType
 
 @param sensorType The NPESensorType 
 @returns The char value of the ANT Device Type
 */
+ (NPEAntDeviceType)rtnDevType:(NPESensorType)sensorType;


///---------------------------------------------------------------------------------------
/// @name Sensors Information
///---------------------------------------------------------------------------------------

/**
 Array of all of the NPESensorConnection objects
 
 @since 2.0.6
 */
@property (nonatomic, readonly) NSArray<NPESensorConnection *> *connections;

/**
 * Returns a dictionary of NPESensorConnection instances for all connected sensors
 * of the specified type.
 *
 * @param sensorType The type of sensor for which to get connections.  If this
 * parameter is <b>NPESensorTypeNone</b>, all connections for any type are returned.
 *
 * @return An NSDictionary containing the matching NPESensorConnection instances.
 */
- (NSDictionary<NSString *, NPESensorConnection *> *)getSensorConnectionDictionary:(NPESensorType)sensorType;

/**
 * Checks all of the active sensor connections and returns the device
 * with the strongest signal strength
 *
 * @param sensorType The type of sensor for which to get strongest signal.  If this
 * parameter is <b>NPESensorTypeNone</b>, all connections for any type are checked.
 *
 * @return NPESensorConnection of the strongest sensor
 */
- (NPESensorConnection * _Nullable)getStrongestSensorConnection:(NPESensorType)sensorType;

/**
 * Checks all of the active sensor connections and returns the device
 * with the strongest signal strength using a specific Pairing Pod
 *
 * @param sensorType The type of sensor for which to get strongest signal.  If this
 * parameter is <b>NPESensorTypeNone</b>, all connections for any type are checked.
 *
 * @return NPESensorConnection of the strongest sensor
 */
- (NPESensorConnection * _Nullable)getStrongestSensorConnection:(NPESensorType)sensorType usingPairingPod:(NSString *)pairingPodID;

/**
 * Manually remove all of the inactive sensor connections in the Hardware Connector
 *
 * This method allows the appliation to remove all of the inactive sensors from the
 * list of known sensors if they have become stale and do not have any recorded data
 */
- (void)removeAllInactiveSensors;

/**
 Provides a list of the supported sensor connections for the Hardware Connector.
 
 @returns A NSArray of supported sensor names.
 @since 1.3.4
 */
+ (NSArray<NSString *> *)supportedSensorNames;


///---------------------------------------------------------------------------------------
/// @name WASP (Gateway) Information
///---------------------------------------------------------------------------------------


/**
 Contains a set of Wasp Objects of WASP Devices that we have Discovered on the
 network.  In this state we have not yet received enough information to know about
 the WASP itself, or it has not yet started to send data.
 
 @since 2.0.6
 */
@property (nonatomic, readonly) NSSet<Wasp *> *discoveredWasps;


/**
 Contains a set of Wasp Objects of WASP Devices that we have detected on the network
 and succesfully decoded.
 
 @since 2.0
 */
@property (nonatomic, readonly) NSSet<Wasp *> *knownWasps;


/**
 * Ask the Hardware connector to issue a query looking for any WASP to respond
 *
 */
- (void)lookForAnyWasp;

/**
 Sends a command to a WASP matching the IP Address passed in to identify itself.
 
 @param ipAddress The IP Address of the WASP you want to have send back its Query Response
 */
- (void)lookforWaspWithIPAddress:(NSString *)ipAddress;

/**
 * Manually remove the instance of the WASP from the list of know WASPs
 *
 * This method allows the application to remove a WASP from the active list
 * of discovered WASPs.  This would be used to clear the list out and allow
 * it to refill when the WASP is discovered again
 *
 * @param IPAddress of the WASP to remove
 */
- (void)removeWasp:(NSString *)IPAddress;

///---------------------------------------------------------------------------------------
/// @name WASP Observation
///---------------------------------------------------------------------------------------

/**
 Observer for WASP State Change Events
 
 @param observer The Observer
 @param completionHandler The block to run on state changes
 @since 2.1.0
 */
- (void)addWaspStateChangeObserver:(id)observer onStateChange:(WaspStateChangeObserverBlock _Nullable)completionHandler;

/**
 Remove the WASP State change observer
 
 @param observer The Observer to remove
 @since 2.1.0
 */
- (void)removeWaspStateChangeObserver:(id)observer;

///---------------------------------------------------------------------------------------
/// @name NPESensorConnection State Observation
///---------------------------------------------------------------------------------------

/**
 Observer for NPESensorConnection State Change Events

 @param observer The Observer of State Changes
 @param completionHandler The block to run on state change
 @since 3.0
 */
- (void)addSensorStateChangeObserver:(id)observer onStateChange:(SensorStateChangeObserverBlock)completionHandler;

/**
 Remove the NPESensorConnection State Change Observer

 @param observer The Observer to remove
 @since 3.0
 */
- (void)removeSensorStateChangeObserver:(id)observer;

///---------------------------------------------------------------------------------------
/// @name Filtering
///---------------------------------------------------------------------------------------

/**
 Provides the ability to filter processing data from specific WASP devices.
 
 The block provides back the Wasp Object that data is coming in from, you
 can then filter that based on IP Address, Mac Address or any variable
 the Wasp provides.
 
 @param filter The block which is used to determine the filter
 */
- (void)setTrafficFilter:(WaspFliterBlock _Nullable)filter;

/**
 An array of <i>NPESensorType</i> which the NPEHardwareConnector should
 process if found on the network.
 
 By Default the NPEHardwareConnector will listen to and create a NPESensorConnection
 for all sensors it finds.  By providing an array of NPESensorType, the NPEHardwareConnector
 will only process those sensor types.  This can be helpful if your application is
 specifically designed to listen to and report on only a subset of the sensors that
 may be on the network.
 
 @param whitelist An NSArray of NPESensorType to process.  All others will be ignored
 @note Setting to nil is the same as not setting the whitelist and NPEHardwareConnector will process all Sensors
 @since 1.3.5
 */
- (void)setSensorTypeWhitelistArray:(NSArray *)whitelist __deprecated_msg("use: setSensorFilterWhiteList 3.0");

/**
 An Array of <i>NPESensorFilter</i> objects which the NPEHardwareConnector
 should process if found on the network.

 By Default the NPEHardwareConnector will listen to and create a NPESensorConnection
 for all sensors it finds.  By providing an array of NPESensorFilter, the
 NPEHardwareConnector will only process those sensor that match the filters.
 This can be helpful if your application is specifically designed to listen to
 and report on only a subset of the sensors that may be on the network.


 @param whitelist Array of NPESensorFilter Objects.
 @note Setting to nil is the same as not setting the whitelist and NPEHardwareConnector will process all Sensors
 @since 3.0
 */
- (void)setSensorFilterWhiteList:(NSArray<NPESensorFilter *> * _Nullable)whitelist;

/**
 Current Sensor Filter Whitelist

 @since 3.0
 */
@property (nonatomic, readonly, nullable) NSArray<NPESensorFilter *> *sensorFilterWhitelist;

/**
 A Readonly Set of Wasp Objects that are part of the Wasp White List
 
 The Framework will only consider the Wasp Objects in this list as valid Wasps
 to listen for sensors.  The knownWasps Set will still contain all Wasp Objects
 that the framework has found.

 @since 2.0.4
 */
@property (nonatomic, readonly) NSSet<Wasp *> *waspWhitelist;

/**
 Adds a Wasp Object to the Wasp White list.  
 
 @since 2.0.4
 */
- (void)insertIntoWaspWhitelist:(Wasp *)wasp;

/**
 Removes a Wasp Object from the Wasp White List
 
 @since 2.0.4
 */
- (void)removeFromWaspWhiteList:(Wasp *)wasp;


///---------------------------------------------------------------------------------------
/// @name PoE Distress Observation
///---------------------------------------------------------------------------------------

/**
 Observer for WASP PoE Distress Beacons.
 
 When a WASP PoE detects an issue with the Application it will send out a distress beacon.

 @note PoE must be version 2.4.0+ in order to send out the Distress Beacons.
 @param observer          The Observer of the Distress Beacon
 @param completionHandler Block to run on completion.
 @since 2.2.0
 */
- (void)addWaspPoeDistressObserver:(id)observer onCompletion:(WaspPoeDistressObserverBlock _Nullable)completionHandler;

/**
 Removes the observer for the WASP PoE Distress Beacon Observer

 @param observer Observer that was observing the Distress Beacons
 @since 2.2.0
 */
- (void)removeWaspPoeDistressObserver:(id)observer;

///---------------------------------------------------------------------------------------
/// @name Logging
///---------------------------------------------------------------------------------------

/**
 Sets the NSFileHandle for the Log file
 */
- (void)setFileHandle:(NSFileHandle *)fileHandle __deprecated_msg("no longer supported 3.0");

/**
 When called NPEHardwareConnector will store device information into the Filehandle that you provided
 
 @returns <b>TRUE</b> If messages received and is logging.
 @see setFileHandle:
 */
- (BOOL)openLogFile __deprecated_msg("no longer supported 3.0");

/**
 When called NPEHardwareConnector will stop saving messages to the log file and close the file.
 */
- (void)closeLogFile __deprecated_msg("no longer supported 3.0");

/**
 * True if hardware connector is loging data to a file.
 */
@property (nonatomic, readonly) BOOL bLogToFile __deprecated_msg("no longer supported 3.0");


///---------------------------------------------------------------------------------------
/// @name Reachability
///---------------------------------------------------------------------------------------

/**
 * Reachability information for host access.
 *
 * Refer to the Reachability documentation at developer.apple.com
 */
@property (nonatomic, readonly) NPEReachability *hostReachability;

/**
 * Reachability information about internet accessibility.
 *
 * Refer to the Reachability documenation at developer.apple.com
 */
@property (nonatomic, readonly) NPEReachability *internetReachability;

/**
 * Reachability information the state of the WiFi connection.
 *
 * Refer to the Reachability documenation at developer.apple.com
 */
@property (nonatomic, readonly) NPEReachability *wifiReachability;

@end
NS_ASSUME_NONNULL_END
