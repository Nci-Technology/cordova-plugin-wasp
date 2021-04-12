//
//  NPEConnectorSettings.h
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


/** Defines the RssiFilterOff Default */
FOUNDATION_EXPORT const NSInteger NPESettingsKeyRssiFilterOff;
/** Defines the Stale Data Timeout value of OFF */
FOUNDATION_EXPORT const NSInteger NPESettingsKeyStaleDataTimeoutOff;

/**
 * Provides a means of persisting settings for the NPEConnector.
 *
 *  Settings are saved in NSUserDefaults under a defined Suite
 */
@interface NPEConnectorSettings : NSObject

+ (NPEConnectorSettings *)sharedSettings;

- (instancetype)init NS_UNAVAILABLE;

/**
 * Resets all of the Settings to the Default Values and Saves for future runs.
 *
 * @since 2.0.10
 */
- (void)resetToDefaults;

///---------------------------------------------------------------------------------------
/// @name Bike Coasting Timeout
///---------------------------------------------------------------------------------------

/**
 * The bike coasting timeout, in seconds.
 * 
 * If no data is received for this duration, the bike is considered to
 * be coasting.
 *
 * @note The default value is 3 seconds.
 */
@property (nonatomic, readonly) NSTimeInterval bikeCoastingTimeout;

/**
 * Sets the Bike Coasting Timeout Value
 *
 * @params timeout The Timeout Value to use to consider the bike Coasting. Values of 1.0 or greater
 * @params save If the Value should be saved for Next Run.  If False it will be a runtime setting
 * @since 2.0.10
 */
- (void)setBikeCoastingTimeout:(NSTimeInterval)timeout saveState:(BOOL)save;


///---------------------------------------------------------------------------------------
/// @name Bike Wheel Circumference
///---------------------------------------------------------------------------------------

/**
 Bike Wheel Circumference In Millimeters

 @note The default value is 2070mm
 @since 3.0.8
 */
@property (nonatomic, readonly) NSInteger bikeWheelCircumferenceInMillimeters;

/**
 Sets the Bike Wheel Circumference in Millimeters

 @param circumference Circumference in Millimeters
 @param save If the Value should be saved for Next Run.  If False it will be a runtime setting
 @since 3.0.8
 */
- (void)setBikeWheelCircumferenceInMillimeters:(NSInteger)circumference saveState:(BOOL)save;


///---------------------------------------------------------------------------------------
/// @name Stale Data Timeout
///---------------------------------------------------------------------------------------

/**
 * The stale data timeout, in seconds.
 * 
 * If the time since the latest data was received from the sensor exceeds
 * this value, the data for that sensor will be considered "stale". A value
 * of NPESettingsKeyStaleDataTimeoutOff indicates data never goes stale.
 *
 * @note The default value is 10 Seconds.
 */
@property (nonatomic, readonly) NSTimeInterval staleDataTimeout;

/**
 * Sets the Stale Data Timeout
 *
 * @params timeout The Timeout Value to use to consider the data Stale
 * @params save If the Value should be saved for Next Run.  If False it will be a runtime setting
 * @since 2.0.10
 */
- (void)setStaleDataTimeout:(NSTimeInterval)timeout saveState:(BOOL)save;

///---------------------------------------------------------------------------------------
/// @name Invalid Data
///---------------------------------------------------------------------------------------

/**
 *  Provides the ability to Receive Invalid Data from a Sensor
 *
 *  If set to TRUE the framework will send both Valid and Invalid
 *  values from the sensor as it receives them.  It will be up to
 *  the developer to determine if the Application should use that 
 *  data to display.
 *
 *  As part of the SensorData Parameter List there is a Flag which
 *  will indicate if the value is determined to be valid.  This flag
 *  is: NPESensorDataParameterListKeyValidData
 *
 *  @note The Default value is FALSE
 *  @since 2.0.10
 */
@property (nonatomic, readonly) BOOL sendInvalidData;

/**
 * Sets the Send Invalid Flag
 *
 * @params sendInvalidData The Invalid Data Flag
 * @params save If the Value should be saved for Next Run.  If False it will be a runtime setting
 * @since 2.0.10
 */
- (void)setSendInvalidData:(BOOL)sendInvalidData saveState:(BOOL)save;

///---------------------------------------------------------------------------------------
/// @name RSSI Filtering
///---------------------------------------------------------------------------------------

/**
 * Sensor RSSI Discovery Filter Value
 *
 * The RSSI Value a sensor must hit prior to the Framework presenting it
 * as a valid Sensor Object.
 *
 * @note Default Value is NPESettingsKeyRssiFilterOff (OFF).  All Senesors will be detected
 * @since 2.0.10
 */
@property (nonatomic, readonly) NSInteger sensorRssiFilter;

/**
 * Sets the Sensor RSSI Discovery Filter
 *
 * Value of NPESettingsKeyRssiFilterOff will turn off Filtering
 *
 * @params filter The RSSI value a sensor needs to achive in order to be discovered
 * @params save If the Value should be saved for Next Run.  If False it will be a runtime setting
 * @since 2.0.10
 */
- (void)setSensorRssiFilter:(NSInteger)filter saveState:(BOOL)save;

@end
