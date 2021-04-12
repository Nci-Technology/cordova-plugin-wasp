//
//  NPEEnvironmentalData.h
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
#import <NpeGate/NPESensorData.h>
#if TARGET_OS_IPHONE
#import <UIKit/UIKit.h>
#elif TARGET_OS_MAC
#import <Cocoa/Cocoa.h>
#import <AppKit/AppKit.h>
#endif

@class NPECommonData;


///---------------------------------------------------------------------------------------
/// Sensor Data Parameter Keys
///
/// Supports Common Data Parameter Keys:
///   NPESensorDataParameterKeyCurrentTemp
///   NPESensorDataParameterKeyRawData
///   NPESensorDataParameterKeyCurrentPressure
///   NPESensorDataParameterKeyCurrentHumidity
///
/// See also: NPECommonData
///---------------------------------------------------------------------------------------

/** Defines the Sensor Data Parameter Key for 24h High Temperature */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKey24HourHighTemperature;
/** Defines the Sensor Data Parameter Key for 24h Low Temperature */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKey24HourLowTemperature;


/**
 * Describes the status of the time support in the ANT sensor.
 */
typedef NS_ENUM(NSInteger, NPEEnvTime) {
    /** No time information is available. */
    NPEEnvTimeNotSupported              = 0,
    /** The time is supported but not set. */
    NPEEnvTimeSupportNotSet             = 1,
    /** The  time is supported but not set. */
    NPEEnvTimeSupportAndSet             = 2,
};


/**
 * Represents the data available from the ANT+ Environmental sensor.
 *
 * ANT+ sensors send data in multiple packets.  The NPEEnvironmentalData
 * combines this data into a single entity.  The data represents the latest of
 * each data type sent from the sensor.
 *
 * See Header Files for Sensor Data Parameter Keys
 */
@interface NPEEnvironmentalData : NPESensorData

/**
 * Local Time Support.
 *
 * @note The three valid results are 
 * 0 - Local Time Not Supported
 * 1 - Local Time Supported But Not Set
 * 2 - Local Time Supported And Set
 */
@property (nonatomic, readonly) NPEEnvTime localTimeSupport;

/**
 * UTC Time Support.
 *
 * @note The three valid results are 
 * 0 - UTC Time Not Supported
 * 1 - UTC Time Supported But Not Set
 * 2 - UTC Time Supported And Set
 */
@property (nonatomic, readonly) NPEEnvTime utcTimeSupport;

/**
 * Supported Pages.
 *
 * @note Each Bit represents a supported page 0-31 
 */
@property (nonatomic, readonly) NSUInteger supportedPages;

/**
 * Event counter increments with each information update.
 */
@property (nonatomic, readonly) u_char eventCount;

/**
 * Default Tx Rate.
 *
 * @note The two valid results are
 * 0 - 0.5 Hz
 * 1 - 4 Hz
 */
@property (nonatomic, readonly) float defaultTxRate;

///---------------------------------------------------------------------------------------
/// @name Temperature Information
///---------------------------------------------------------------------------------------

/**
 *  Current Temperature in (NPEUnitTypeCelsius)
 *
 *  Signed Integer representing the current temperature
 *  -327.67 - 327.67
 */
@property (nonatomic, readonly) CGFloat currentTemp;

/**
 *  24 Hour High Temperature in (NPEUnitTypeCelsius)
 *
 *  Signed Integer representing the highest temperature recorded
 *  over the last 24 hours
 *  -204.7 - 204.7C
 */
@property (nonatomic, readonly) CGFloat highTemp24;

/**
 *  24 Hour Low Temperature in (NPEUnitTypeCelsius)
 *
 *  Signed Integer representing the lowest temperature recorded
 *  over the last 24 hours
 *  -204.7 - 204.7C
 */
@property (nonatomic, readonly) CGFloat lowTemp24;

///---------------------------------------------------------------------------------------
/// @name Humidity Information (%RH)
///---------------------------------------------------------------------------------------

/**
 *  Current Humidity
 *
 *  Signed Integer representing the current humidity
 *
 */
@property (nonatomic, readonly) NSInteger currentHumid;

/**
 *  24 Hour High Humidity
 *
 *  Signed Integer representing the higest humidity recorded
 *  over the last 24 hours
 */
@property (nonatomic, readonly) NSInteger highHumid24;

/**
 *  24 Hour Low Humidity
 *
 *  Signed Integer representing the lowest humidity recorded
 *  over the last 24 hours
 */
@property (nonatomic, readonly) NSInteger lowHumid24;

///---------------------------------------------------------------------------------------
/// @name Pressure Information (psi)
///---------------------------------------------------------------------------------------

/**
 *  Current Pressure
 *
 *  Signed Integer representing the current pressure
 *
 */
@property (nonatomic, readonly) NSInteger currentPress;

/**
 *  24 Hour High Pressure
 *
 *  Signed Integer representing the higest pressure recorded
 *  over the last 24 hours
 */
@property (nonatomic, readonly) NSInteger highPress24;

/**
 *  24 Hour Low Pressure
 *
 *  Signed Integer representing the lowest pressure recorded
 *  over the last 24 hours
 */
@property (nonatomic, readonly) NSInteger lowPress24;

@end
