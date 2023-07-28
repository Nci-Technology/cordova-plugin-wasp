//
//  NPESensorData.h
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
#import <NpeGate/npe_hardware_connector_types.h>

@class NPESensorConnection;
@class NPECommonData;
@class NPEEventSensorData;

NS_ASSUME_NONNULL_BEGIN

///---------------------------------------------------------------------------------------
/// Sensor Data Parameter List Keys
///---------------------------------------------------------------------------------------

typedef NSString * NPESensorDataParameterListKey NPE_STRING_ENUM;

/** Defines the Title Used for the Sensor Data ParamLabel */
FOUNDATION_EXPORT NPESensorDataParameterListKey const NPESensorDataParameterListKeyLabel;
/** Defines the Units Used for the Sensor Data Value */
FOUNDATION_EXPORT NPESensorDataParameterListKey const NPESensorDataParameterListKeyUnits;
/** The Value for the Data point */
FOUNDATION_EXPORT NPESensorDataParameterListKey const NPESensorDataParameterListKeyValue;
/** A WTCaptureData object used to save data */
FOUNDATION_EXPORT NPESensorDataParameterListKey const NPESensorDataParameterListKeyHistory;
FOUNDATION_EXPORT NPESensorDataParameterListKey const NPESensorDataParameterListKeyFilterMax;
FOUNDATION_EXPORT NPESensorDataParameterListKey const NPESensorDataParameterListKeyFilterMin;
/* Flag to indicate the parameter is static data */
FOUNDATION_EXPORT NPESensorDataParameterListKey const NPESensorDataParameterListKeyMetaData;
/* Flag to indicate if the parameter should be recorded when capturing data */
FOUNDATION_EXPORT NPESensorDataParameterListKey const NPESensorDataParameterListKeyRecord;
/* A NSDate timestamp of when the Data came in to the framework */
FOUNDATION_EXPORT NPESensorDataParameterListKey const NPESensorDataParameterListKeyTimestamp;
/* A BOOL Value to indicate if the Data Value is a Valid Value or not */
FOUNDATION_EXPORT NPESensorDataParameterListKey const NPESensorDataParameterListKeyValidData;


///---------------------------------------------------------------------------------------
/// Common Sensor Data Parameter Keys
///---------------------------------------------------------------------------------------
typedef NSString * NPESensorDataParameterKey NPE_STRING_ENUM;

/** Defines the Sensor Data Parameter Key for Packets Per Second data */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyPPS;
/** Defines the Sensor Data Parameter Key for RSSI data - Value of 0 to -127, with -128 when no RSSI */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyRSSI;
/** Defines the Sensor Data Parameter Key for the 8 byte Raw ANT data payload  (String) */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyRawData;
/** Defines the Sensor Data Parameter Key for The Sensors ID */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeySensorID;
/** Defines the Sensor Data Parameter Key for Sensors Type */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeySensorType;
/** Defines the Sensor Data Parameter Key for Data Available */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyDataAvailable;
/** Defines the Sensor Data Parameter Key for Last Command ID */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyLastCommandID;
/** Defines the Sensor Data Parameter Key for Sequence Number */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeySequenceNumber;
/** Defines the Sensor Data Parameter Key for Command Status */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyCommandStatus;
/** Defines the Sensor Data Parameter Key for Response Data */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyResponseData;
/** Defines the Sensor Data Parameter Key for Sensor */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyCapabilities;
/** Defines the Sensor Data Parameter Key for Cadence */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyCadence;
/** Defines the Sensor Data Parameter Key for Average Cadence */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyAverageCadence;
/** Defines the Sensor Data Parameter Key for Speed */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeySpeed;
/** Defines the Sensor Data Parameter Key for Heart Rate */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyHeartRate;
/** Defines the Sensor Data Parameter Key for Zone */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyZone;
/** Defines the Sensor Data Parameter Key for Average Heart Rate */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyAverageHeartRate;
/** Defines the Sensor Data Parameter Key for MVPA */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyMVPA;
/** Defines the Sensor Data Parameter Key for Power */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyPower;
/** Defines the Sensor Data Parameter Key for Average Power */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyAveragePower;
/** Defines the Sensor Data Parameter Key for Instant Power */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyInstantPower;
/** Defines the Sensor Data Parameter Key for Distance data  */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyDistance;
/** Defines the Sensor Data Parameter Key for Total Distance */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyTotalDistance;
/** Defines the Sensor Data Parameter Key for Accumulative Distance */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyAccumDistance;
/** Defines the Sensor Data Parameter Key for Accumulative Strides */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyAccumStrides;
/** Defines the Sensor Data Parameter Key for Strides per Minute  */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyStridesPerMin;
/** Defines the Sensor Data Parameter Key for Accumulative Jumps */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyAccumJumps;
/** Defines the Sensor Data Parameter Key for Accumulative Revolutions */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyAccumRevolutions;
/** Defines the Sensor Data Parameter Key for Calories */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyCalories;
/** Defines the Sensor Data Parameter Key for Accumulative Calories */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyAccumCalories;
/** Defines the Sensor Data Parameter Key for Points */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyPoints;
/** Defines the Sensor Data Parameter Key for Slope  */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeySlope;
/** Defines the Sensor Data Parameter Key for Accumulative Steps */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyAccumSteps;
/** Defines the Sensor Data Parameter Key for Steps per Minute  */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyStepsPerMin;
/** Defines the Sensor Data Parameter Key for Total Steps  */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyTotalSteps;
/** Defines the Sensor Data Parameter Key for Last Calibration */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyLastCalibration;
/** Defines the Sensor Data Parameter Key for Height data  */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyHeight;
/** Defines the Sensor Data Parameter Key for Location data  */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyLocation;
/** Defines the Sensor Data Parameter Key for Session Time  */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeySessionTime;
/** Defines the Sensor Data Parameter Key for Session Distance */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeySessionDistance;
/** Defines the Sensor Data Parameter Key for Stage Distance */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyStageDistance;
/** Defines the Sensor Data Parameter Key for Stage Time */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyStageTime;
/** Defines the Sensor Data Parameter Key for Current Temprature */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyCurrentTemp;
/** Defines the Sensor Data Parameter Key for Wind Speed */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyWindSpeed;
/** Defines the Sensor Data Parameter Key for Wind Direction */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyWindDirection;
/** Defines the Sensor Data Parameter Key for Current Pressure. */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyCurrentPressure;
/** Defines the Sensor Data Parameter Key for Current Humidity */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyCurrentHumidity;
/** Defines the Sensor Data Parameter Key for Notification Event From a sensor */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyNotification;
/** Defines the Sensor Data Parameter Key for Notification Event Counts From a sensor */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyNotificationCount;
/** Defines the Sensor Data Parameter Key for User Alerts From a sensor */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyAlert;
/**
 Block for Observing Sensor Data via a NPESensorDataParameterKey
 
 @since 2.0
 */
typedef void (^NPESensorDataParameterObserverBlock)(NPESensorConnection *sensor, NSDictionary *data);


/**
 * This is the abstract base class for all types of ANT sensor data.
 */
@interface NPESensorData : NSObject

/**
 * Common sensor data, provides information about the sensor.
 */
@property (nonatomic, readonly, getter=getCommonData) NPECommonData *commonData;

/**
 A timestamp of the last received data from the sensor.  
 
 This is based off of the <i>timeIntervalSince1970</i>, which is January 1, 1970 at 12:00 a.m. GMT.
 
 @since 2.0
 */
@property (nonatomic, readonly) NSTimeInterval lastDataTime;

/**
 Refers back to the NPESensorConnection that owns the data.
 */
@property (nonatomic, readonly) NPESensorConnection *connection;


/** <b>TRUE</b> if data is considered stale, otherwise <b>FALSE</b>. */
@property (nonatomic, readonly) BOOL isDataStale;


/**
 * Parameter List
 *
 * The Parameter list contains specific information for each type of sensor
 * The Key/Value pair details out the data available for each parameter.
 *
 * Parameter key is defined by a <i>NPESensorDataParameterKey...</i>, for example the key
 * for Cadence is <i>NPESensorDataParameterKeyCadence</i>.  These keys may be used by multiple
 * sensor types that provide cadence data.
 *
 *
 * Three specific defines are used as keys into the dictionary for each element
 *   ***SEE: Sensor Data Parameter List Keys
 *   NPESensorDataParameterListKeyUnits:    A NSString used for the units of the value.
 *   NPESensorDataParameterListKeyValue:    A NSNumber for the parameter
 *   NPESensorDataParameterListKeyHistory:  A WTCaptureData object used to save data
 *   NPESensorDataParameterListKeyRecord:   Flag to indicate if the parameter should be recorded when capturing data
 *   NPESensorDataParameterListKeyMetaData: Flag to indicate the parameter is static data.
 *   NPESensorDataParameterListKeyValidData:Flag to indicate if Data Value is Valid
 *
 *
 *  Heart Rate Monitor
 *    "Heart Rate"
 *
 *  Bike Speed & Cadence
 *    "Cadence"
 *    "Wheel RPM"
 */
@property (nonatomic, readonly) NSDictionary<NSString *, NSMutableDictionary<NSString *, id> *> *parameterList;


@property (nonatomic, readonly) NSArray *parameterListCapture;

/**
 Gets the kParamValue for the Key from the Sensors Parameter List Dictionary.

 @param key The ParameterKey for the Value you are looking for.  These are the NPESensorDataParameterKeyXXXX keys
 @return The Value for the key
 @since 1.3.5
 */
- (nullable id)getParameterValueForKey:(NSString *)key __deprecated_msg("use getParameterValueForKey:(NSString *)key onlyIfValid:(BOOL)valid 3.0");

/**
 Gets the kParamValue for the Key from the Sensors Parameter List Dictionary.

 @param key The ParameterKey for the Value you are looking for.  These are the NPESensorDataParameterKeyXXXX keys
 @param valid Only return value if it is Marked Valid, otherwise return nil

 @return The Value for the key
 @since 3.0
 */
- (nullable id)getParameterValueForKey:(NSString *)key onlyIfValid:(BOOL)valid;

/**
 Reset the accumlated data for the sensor if the sensor stores accumulated data.
 */
- (void)resetAccumulatedData;

/**
 Dictionary of the last page data
 */
@property (nonatomic, readonly) NSDictionary<NSString *, NSData *> *pageDataSave __deprecated_msg("use dataEvents 2.1");

/**
 Array of NPEEventSensorData for the Sensor
 
 Each Sensor Data Event provides information about the Data pages we have received.
 
 @since 2.1
 @seealso NPEEventSensorData
 */
@property (nonatomic, readonly) NSArray<NPEEventSensorData *> *dataEvents;

/**
 Reponse message from Sensor Data
 */
@property (nonatomic, readonly) id responseMsg;

///---------------------------------------------------------------------------------------
/// @name Sensor Data/Response Observers
///---------------------------------------------------------------------------------------

/**
 Creates an Observer of Data for a specific Sensor Data ParameterKey.
 
 @param observer The Observer for the data
 @key The Sensor Data Parameter Key to observe
 @queue The Queue which to send back the dispatch.  If set <b>nil</b> it will return on the main_queue
 @block The block to run
 @since 2.0
 */
+ (void)addSensorObserver:(id)observer forSensorDataParameterKey:(NPESensorDataParameterKey)key resultsQueue:(dispatch_queue_t _Nullable)queue resultsBlock:(NPESensorDataParameterObserverBlock _Nullable)block;

/**
 Removes the Observer of the Data Parameter Key
 
 @param observer The observer that is removing the Observation of the key
 @param key The Data Parameter key to stop observing
 @since 2.0
 */
+ (void)removeSensorObserver:(id)observer forSensorDataParameterKey:(NSString *)key;

@end
NS_ASSUME_NONNULL_END
