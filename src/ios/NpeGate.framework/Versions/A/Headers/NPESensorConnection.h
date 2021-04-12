//
//  NPESensorConnection.h
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
#import <NpeGate/NPESensorImage.h>
#import <NpeGate/npe_hardware_connector_types.h>
#import <NpeGate/NPECmdQueueMsg.h>
#import <NpeGate/NPESensorConnectionDelegate.h>
#import <NpeGate/NPESensorData.h>

@class Wasp;
@class NPESensorData;
@class NPECmdQueueMsg;
@class NPEBLEAdvertisement;
@class NPEEventSensorSignal;
@class NPESensorSetting;
@class NPESensorCommandQueue;
@class NPESensorCommandSettings;
@class NPECommonDataPairedDevice;

NS_ASSUME_NONNULL_BEGIN

#define kParams @"kParams"                                      //Array of Command Characteristics
#define kType @"kType"                                          //Recommended UI component to represent the input
#define kParam @"kParam"                                        //Command Label
#define kUnits @"kUnits"                                        //Unit Type associated with the command input
#define kSetting @"kSetting"                                    //The Value to be set by the command
#define kSegments @"kSegments"                                  //If Command kType is Segment, this will include titles for the segment
#define kSegmentValues @"kSegmentValues"                        //If Command kType is Segment, this will include the accepted values
#define kPickerRowTitles @"kPickerRowTitles"                    //If Command kType is Picker, this will include titles for the rows
#define kPickerRowValues @"kPickerRowValues"                    //If Command kType is Picker, this will include the values to use for the command
#define kNumOfBytes @"kNumOfBytes"                              //Number of bytes for input
#define kByteOrder @"kByteOrder"                                //The expected byte order - Little/Big Endian
#define kMin @"kMin"                                            //Minimum Value for the kSetting
#define kMax @"kMax"                                            //Maximum Value for the kSetting
//Maximum Length of kSetting.  ex.  If set 9 and is a String type, it can have not more then 9 characters in the String
#define kCommandMaxSettingLength @"kCommandMaxSettingLength"
#define kOffset @"kOffset"
#define kStepBy @"kStepBy"                                      //If Command type is stepper, this will be the recommended amount to step by
#define kIndexedBy @"kIndexedBy"                                //If the parameter contains an array of values this parameter indicates which parameter setting to reference for the index into the array.
#define kDescription @"kDescription"                            //Description Field of the Commands
#define kAntPkt @"kAntPkt"

/**
 Describes the Discovery State of the Sensors

 @since 3.0
 */
typedef NS_ENUM(NSInteger, SensorDiscoveryState) {
    SensorDiscoveryStateUnknown         = 0,
    /// Sensor Has Been Discovered on the Network
    SensorDiscoveryStateConnected       = 1,
    /// Sensor Will Disconnect from the Network
    SensorDiscoveryStateDisconnecting   = 2,
};

///---------------------------------------------------------------------------------------
/// Common Sensor Command Keys
///---------------------------------------------------------------------------------------
typedef NSString * NPESensorCmdKey NPE_STRING_ENUM;

/** Sensor Command Key for Setting Time */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeySetTime;
/** Sensor Command Key for Requesting Time */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyRequestTime;
/** Sensor Command Key for Ping Testing a Sensor */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyPingTest;
/** Sensor Command Key for Requesting 4HZ Transmission Rate */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyRequest4HZ;
/** Sensor Command Key for Requesting Files */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyRequestFiles;
/** Sensor Command Key for Requesting a Power Down Equipment */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyPowerDown;
/** Sensor Command Key for Sensor Manufacturer Information */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyReqManufacturerInfo __deprecated_msg("use NPESensorCmdKeyRequestManufacturerInfo - 3.0");
/** Sensor Command Key for Sensor Manufacturer Information */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyRequestManufacturerInfo;
/** Sensor Command Key for Sensor Version Information */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyReqVersionInfo __deprecated_msg("use NPESensorCmdKeyRequestVersionInfo - 3.0");
/** Sensor Command Key for Sensor Version Information */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyRequestVersionInfo;
/** Sensor Command Key for Battery Status Information */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyReqBatteryStatus __deprecated_msg("use NPESensorCmdKeyRequestBatteryStatus - 3.0");
/** Sensor Command Key for Battery Status Information */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyRequestBatteryStatus;
/** Sensor Command Key for Sensor Product Information Information */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyRequestProductInfo;
/** Sensor Command Key for Sensor Location */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyRequestSensorLocation;
/** Sensor Commad Key for Request Personal Data */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyRequestPersonalData;
/** Command Key to Set Personal Data */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeySetPersonalData;

///---------------------------------------------------------------------------------------
/// Common Sensor Command Parameter Types (kType)
///
/// The Parameter types provide a UI hint of the optimal type of UI component
/// to use when displaying the command to the user
///---------------------------------------------------------------------------------------
typedef NSString * NPESensorCommandParameterType NPE_STRING_ENUM;

/** Sensor Comand Parameter Type of Stepper Component */
FOUNDATION_EXPORT NPESensorCommandParameterType const NPESensorCommandParameterTypeStepper;
/** Sensor Command Parameter Type of Picker Component */
FOUNDATION_EXPORT NPESensorCommandParameterType const NPESensorCommandParameterTypePicker;
/** Sensor Command Parameter Type of Segmented Control Component */
FOUNDATION_EXPORT NPESensorCommandParameterType const NPESensorCommandParameterTypeSegment;
/** Sensor Command Parameter Type of Text Field Component */
FOUNDATION_EXPORT NPESensorCommandParameterType const NPESensorCommandParameterTypeTextField;
/** Sensor Comand Parameter Type of Switch (On/Off) Component */
FOUNDATION_EXPORT NPESensorCommandParameterType const NPESensorCommandParameterTypeSwitch;
/** Sensor Comand Parameter Type of Picker & Switch (On/Off) Component */
FOUNDATION_EXPORT NPESensorCommandParameterType const NPESensorCommandParameterTypePickerSwitches;


///---------------------------------------------------------------------------------------
/// Common Sensor Command Parameter Keys
///---------------------------------------------------------------------------------------
typedef NSString * NPESensorCommandParameterKey NPE_STRING_ENUM;

/** Command Parameter for setting Grade */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeyGrade;
/** Command Parameter for setting number of Pings to a Sensor */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeyPings;
/** Command Parameter for setting Resistance */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeyResistance;
/** Command Parameter for setting Speed */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeySpeed;
/** Command Parameter for setting Wheel Circumference */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeyWheelCircumference;
/** Sensor Data Parameter Key - Weight */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeyUserWeight;
/** Sensor Data Parameter Key - Age */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeyUserAge;


/** An observer for the <responseData> property */
typedef void (^NPESensorResponseDataObserver)(NPESensorData *data);

/** An observer for the <sensorData> property */
typedef void (^NPESensorDataObserver)(NPESensorData *data);

/** Sensor Command Block Response */
typedef void (^NPESensorCommandResponseBlock)(NSInteger retries, NSTimeInterval roundTripTime, NSError * _Nullable error );

/** Observer for ANT Paired Devices */
typedef void (^NPESensorAntPairedDeviceObserver)(NPECommonDataPairedDevice *device, NPESensorData *data);


/**
 * Represents the connection for a sensor.
 *
 * The NPESensorConnection is the entry point for dealing with a sensor.
 * Once the instance is obtained, it can be used to determine connection state,
 * disconnect, or retrieve data.
 *
 */
@interface NPESensorConnection: NSObject

/**
 * Specifies the NPESensorConnectionDelegate instance which will handle callback
 * methods for this NPESensorConnection.
 */
@property (nonatomic, weak, nullable) id<NPESensorConnectionDelegate> delegate;

/**
 * Returns the Device ID of the connected sensor for both ANT and BTLE
 */
@property (nonatomic, readonly) NSString *deviceIDString;

/**
 * Gets the device ID of the connected sensor.
 */
@property (nonatomic, readonly) NSInteger deviceNumber;

/**
 Specifies the Device UUID String.
 
 @since 2.0
 */
@property (nonatomic, readonly) NSString *deviceUUID;

/**
 * Gets a boolean value indicating whether a connection timeout occurred.
 */
@property (nonatomic, readonly) BOOL didTimeout;

/**
 * <b>TRUE</b> if the sensor is currently connected, otherwise <b>FALSE</b>.
 */
@property (nonatomic, readonly) BOOL isConnected;

/**
 * Time in seconds from the last packet received by any WASP in the system to
 * mark the sensor as invalid.  Any packet received from the sensor resets the 
 * invalidate timer.
 *
 * Setting this value to zero disables the invalidate option for the sensor.
 *
 * @note This is a Runtime Setting. You can change the persistant setting in NPEConnectorSettings
 */
@property (nonatomic, assign) NSInteger invalidateTime;

/**
 * Time in seconds from the time a sensor is invalidated to when the sensor
 * is removed from the sensor connection list.  Any packet received from the sensor 
 * resets the invalidate timer and the removal timer.
 *
 * Setting this value to zero disables the removal option for the sensor.
 */
@property (nonatomic, assign) NSInteger removalTime;

/**
 * Gets a boolean value indicating whether this NPESensorConnection instance
 * is valid.
 *
 * The NPESensorConnection is invalidated when the sensor is stale.
 *
 */
@property (nonatomic, readonly) BOOL isValid;

/**
 Resets the isValid Flag to true
 */
- (void)validate;

/**
 Discovery State of the Sensor

 @since 3.0
 */
@property (nonatomic, readonly) SensorDiscoveryState discoveryState;


/**
 The Protocol that the sensor is Advertising on
 
 @since 2.1
 */
@property (nonatomic, readonly) NPESensorProtocolType sensorProtocol;

/**
 * Gets the NPE sensor type for this NPESensorConnection.
 */
@property (nonatomic, readonly) NPESensorType typeOfSensor;

/**
 * Gets the ANT transmission type of the connected sensor.
 */
@property (nonatomic, readonly) u_char transmissionType;

/**
 * Gets the raw ANT device type of the connected sensor.
 */
@property (nonatomic, readonly) u_char deviceType;

/**
 * Gets the rssi of the connected sensor.
 */
@property (nonatomic, readonly) NSInteger rssi;

/**
 * The sensor connection of the parent device for virtual devices.
 * This parameter is nil if it is not a virtual device.
 */
@property (nonatomic, readonly, nullable) NPESensorConnection *parentConnection;

@property (nonatomic, assign) BOOL bOutOfRangeHigh;
@property (nonatomic, assign) BOOL bOutOfRangeLow;

/**
 * Disconnects the sensor.
 */
- (void)disconnect;

/**
 * Retrieves the most current data available from the sensor.
 *
 * @note NPESensorData is an abstract base class for all sensor data types.
 * The specific type will be determined by the type of sensor.  The instance
 * returned must be cast to the specific type in order to be useful.
 */
@property (nonatomic, readonly, getter=getData) NPESensorData *data;

/**
 * Adds a sensor to the list of sensors actively monitoring the WASP network
 */
- (void)startObserving;

/**
 * Removes a sensor from the list of sensors actively monitoring the WASP network
 */
- (void)stopObserving;

/**
 * Returns the state of the sensors active montoring
 */
- (BOOL)isObserving;

/**
 * Manually validates a sensor again to prevent it from being deallocted from inactivity
 */
- (void)restoreConnection;

/**
 * Remove connection from the connection list.
 *
 * If the connection is still active, it will populate in the list again with the next reception of data
 */
- (void)removeConnection;

/**
 Returns a Wasp Instance of the Strongest Wasp for the Sensor

 @since 2.0.6
 */
- (Wasp * _Nullable)findStrongestWasp;

///---------------------------------------------------------------------------------------
/// @name Settings
///---------------------------------------------------------------------------------------

/**
 Contains an array of the NPESensorSetting Objects unique to this particular sensor
 
 @since 2.1.0
 */
@property (nonatomic, readonly) NSArray<NPESensorSetting *> *uniqueValues;

/**
 Update the setting value for the particular sensor connection

 @param setting The particular setting key that is being updated.
 @param value The value to use for updating the setting
 @since 2.1.0
 */
-(void)updateSetting:(NSString *)setting withValue:(id)value;

/**
 Retrieve the individual sensor setting for the key

 @param key The Key for the individual setting object
 @since 2.1.0
 */
-(NPESensorSetting * _Nullable)settingForKey:(NSString *)key;

///---------------------------------------------------------------------------------------
/// @name Diagnostics
///---------------------------------------------------------------------------------------

/**
 * Provides a read only value of the number of packets received from the sensor per second.
 * This is a five second rolling average
 */
@property (nonatomic, readonly) float pktPerSec;

/**
 The Expected Packts Per Second the Sensor should be transmitting at.

 @since 3.0.8
 */
@property (nonatomic, readonly) float expectedPacketsPerSecond;

/**
 Provides a Total Received Packets Count

 @since 2.1
 */
@property (nonatomic, readonly) NSUInteger totalPacketsReceived;

/**
 Provides a Total Received Bytes

 @since 2.1
 */
@property (nonatomic, readonly) NSUInteger totalBytesReceived;

/**
 Array of NPEEventSensorSignal for the Sensor

 Each Sensor Signal Event provides information about the RSSI/PPS from a WASP.

 @since 2.1
 @seealso NPEEventSensorSignal
 */
@property (nonatomic, readonly, nullable) NSArray<NPEEventSensorSignal *> *signalEvents;

///---------------------------------------------------------------------------------------
/// @name Sensor Commands
///---------------------------------------------------------------------------------------

/**
 The Command Queue for the Sensor
 
 @since 2.1.0
 */
@property (nonatomic, readonly) NPESensorCommandQueue *commandQueue;

/**
 Retrieves the commands as a String Value that can be sent to the sensor.
 */
@property (nonatomic, readonly, nullable) NSArray<NSString *> *sensorCommands;

/**
 * A Dictionary of Sensor Command Parameters that can be sent to the Sensor Connection.
 *
 * The Dictionary contains information on the values that can be sent to the sensor,
 * as well as a general hint as to what type of UI component that can be used to display the
 * settings.
 * The Values are:
 *      kParam - The Parameter that is being set
 *      kUnits - The type of Unit to set
 *      kType  - The UI Type recomended
 *      kMin   - The minimum value allowed
 *      kMax   - The maximum value allowed
 *      kStepBy - Unit step value
 *      kSetting - The value to set for the kParam (This is the only value you need to set)
 */
@property (nonatomic, readonly) NSMutableDictionary *sensorCommandDictionary;

/**
 Sends a Command to the sensor connection
 
 You can monitor the command resposes by subscribing to the Response Observer block.
 
 Example of use:
 <code>
    NSDictionary *value = @{
                @"RF Channel" : @{
                     kSetting : @(65)
                }};
 
    [_conn sendCmd:NPESensorCmdKeyRequestPedometerData withValues:value error:nil];
 </code>
 
 @param cmd The Command string to send to the sensor
 @param values Dictionary of the kParam and kSettings part of the Sensors sensorCommandDictionary
 @see addResponseObserver:block:
 @since 2.0
 */
- (BOOL)sendCmd:(NSString *)cmd withValues:(NSDictionary *)values error:(NSError **)error __deprecated_msg("use sendCommand:withValues:forNumberOfRetries:onCompletion 2.1");

/**
 Sends a Command to the sensor connection

 Example of use:
 <code>
 NSDictionary *value = @{
 @"RF Channel" : @{
    kSetting : @(65)
 }};

 [_conn sendCmd:NPESensorCmdKeyRequestPedometerData withValues:value error:nil];
 </code>

 @param command The Command string to send to the sensor
 @param values Dictionary of the kParam and kSettings part of the Sensors sensorCommandDictionary
 @param completionHandler Completion Block
 @see addResponseObserver:block:
 @since 2.0.6
 */
- (void)sendCommand:(NPESensorCmdKey)command withValues:(NSDictionary * _Nullable)values onCompletion:(NPESensorCommandResponseBlock _Nullable)completionHandler __deprecated_msg("use sendCommand:withValues:withSettings:onCompletion");

/**
 Sends a Command to the sensor connection

 Example of use:

 <code>
 NSDictionary *value = @{
 @"RF Channel" : @{
    kSetting : @(65)
 }};
 [_conn sendCmd:NPESensorCmdKeyRequestPedometerData withValues:value error:nil];
 </code>

 @param command The Command string to send to the sensor
 @param values Dictionary of the kParam and kSettings part of the Sensors sensorCommandDictionary
 @param settings The Command specific Settings.
 @param completionHandler Completion Block
 @see addResponseObserver:block:
 @since 2.1.0
 */
- (void)sendCommand:(NPESensorCmdKey)command withValues:(NSDictionary * _Nullable)values withSettings:(NPESensorCommandSettings *)settings onCompletion:(NPESensorCommandResponseBlock _Nullable)completionHandler;

/**
 Provides the array of command parameters for a given Sensor Command.  If the command does not have any parameters <b>nil</b> will be returned.
 
 The array of returned parameters can be used to create the Send Command Dictionary of Values
 
 @param command the Command string for the Sensor
 @returns Array of Command Parameters or nil if command takes no parameters
 @since 2.0.5
 */
- (NSArray<NSDictionary *> *)parametersForCommand:(NSString *)command;

/**
 Updates the setting value for the specified parameter in a command

 @param settingKey The setting key to look for in the command key.
 @param cmdKey The command key to look in.
 @param value the value to set in the setting
 @since 2.1.0
 */
-(void)updateSettingForParameter:(NSString *)settingKey inCmdKey:(NSString*)cmdKey withValue:(id)value;

///---------------------------------------------------------------------------------------
/// @name Sensor Images
///---------------------------------------------------------------------------------------

/**
 Provides an image to represent the sensor.
 
 The image will be correctly sized for the iOS display type you are using.
 
 @param size The Size of the image you wish to retrive.
 @return A GKImage (UIImage/NSImage) for the sensor otherwise nil if no image is available for the sensor.
 @see SensorImageSize
 @since 1.3.4
 */
- (GKImage *)sensorImageOfSize:(SensorImageSize)size;

/**
 Provides a 64x64px icon that represents the Sensors type.

 This is the high level icon for the sensor type.  Certain sensors like the Fitness equipment may provide a more detailed icon based on the type of fitness eqipment that is being used.  Once you have a sensor connection you can use the sensor connections <i>sensorImageOfSize:</i> method to retrieve the sensor specific icon.

 @param type The NPESensorType of the sensor you wish to get the icon for.
 @returns A GKImage (UIImage/NSImage) instance of the sensor
 @since 2.0.10
 */
+ (GKImage *)sensorIcon:(NPESensorType)type;

///---------------------------------------------------------------------------------------
/// @name BLE Information
///---------------------------------------------------------------------------------------

/**
 The BLE Advertisment Packet for the Sensor if the Sensor is of type BLE, otherwise nil.
 
 @since 2.0.6
 */
@property (nonatomic, readonly) NPEBLEAdvertisement *bleAdvertisment;


///---------------------------------------------------------------------------------------
/// @name Sensor Data/Response Observers
///---------------------------------------------------------------------------------------

/**
 A weakified Sensor Command Response Observer
 
 Once you have sent a command to a sensor you can observe the respose by using this method.  
 
 @param observer The Observer who is observing the responses from the sensor commands.
 @block The block to perform on receipt of the sensor command response
 @since 1.3.4
 */
- (void)addResponseObserver:(id)observer block:(NPESensorResponseDataObserver _Nullable)block;

/**
 Removes the sensor command response observer.
 
 Once you are done observing for command reposes you can unsubscribe from those notifcations.
 
 @param observer The observer to remove from the ResponseObservers stack
 @since 1.3.4
 */
- (void)removeResponseObserver:(id)observer;

/**
 A weakified Sensor Data Observer provides the ability to listen for sensor data events.
 
 Each time a sensor has new data to provide it will fire this method.
 
 @params observer The Observer which is listening for new sensor data
 @params block The block to perform on receipt of the new sensor data
 @since 1.3.4
 */
- (void)addSensorDataObserver:(id)observer block:(NPESensorDataObserver _Nullable)block;

/**
 Stops the observer from receiving anymore notifications on the Sensor Data Observer block.
 
 @param observer The observer you wish to remove from receiving Sensor Data to.
 @since 1.3.4
 */
- (void)removeSensorDataObserver:(id)observer;


///---------------------------------------------------------------------------------------
/// @name ANT Paired Sensor Observers
///---------------------------------------------------------------------------------------

/**
 A weakified Sensor Paired Device Observer
 
 When an ANT Device receives information about Paired Devices it will provide that devices informaiton.

 @param observer The Observer who is observing the responses from the sensor commands
 @param block The block to perform on receipt of the sensor command response
 @since 3.0
 */
- (void)addPairedDeviceObserver:(id)observer block:(NPESensorAntPairedDeviceObserver _Nullable)block;

/**
 Stops the observer from receiving anymore notifications on the Sensor Paired Device Observer block.

 @param observer The observer you wish to remove from receiving Sensor Paired Device to.
 @since 3.0
 */
- (void)removePairedDeviceObserver:(id)observer;

@end
NS_ASSUME_NONNULL_END
