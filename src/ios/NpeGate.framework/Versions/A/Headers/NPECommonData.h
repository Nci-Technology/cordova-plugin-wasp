//
//  NPECommonData.h
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
#endif

@class NPECommonDataError;
@class NPECommonDataPairedDevice;
@class NPEManufacturer;

NS_ASSUME_NONNULL_BEGIN
/**
 Defines the Battery data of Invalid
 */
FOUNDATION_EXPORT const float NPE_COMMON_BATTERY_INVALID;

///---------------------------------------------------------------------------------------
/// Sensor Data Parameter Keys
///
/// Supports Common Data Parameter Keys:
///     NPESensorDataParameterKeyCurrentTemp
///     NPESensorDataParameterKeyCurrentPressure
///     NPESensorDataParameterKeyCurrentHumidity
///     NPESensorDataParameterKeyWindSpeed
///     NPESensorDataParameterKeyWindDirection
///     NPESensorDataParameterKeyLocation
///
///---------------------------------------------------------------------------------------

/** Defines the Sensor Data Parameter Key for Cumulative Operating Time */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyCOTime;
/** Defines the Sensor Data Parameter Key for Manufacturers ID */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyManufacturerID;
/** Defines the Sensor Data Parameter Key for Manufacturers Name (String Value) */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyManufacturerName;
/** Defines the Sensor Data Parameter Key for Serial Number */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeySerialNumber;
/** Defines the Sensor Data Parameter Key for Hardware Version */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyHardwareVersion;
/** Defines the Sensor Data Parameter Key for Software Version */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeySoftwareVersion;
/** Defines the Sensor Data Parameter Key for Model Number */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyModelNumber;
/** Defines the Sensor Data Parameter Key for Battery Percentage */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyBatteryPercent;
/** Defines the Sensor Data Parameter Key for Battery Voltage */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyBatteryVoltage;
/** Defines the Sensor Data Parameter Key for Battery Status */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyBatteryStatus;
/** Defines the Sensor Data Parameter Key for Number of Batteries */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyNumberOfBatteries;
/** Defines the Sensor Data Parameter Key for Time read from the device */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyCommonTime;
/** Defines the Sensor Data Parameter Key for Minimum Operating Temperature */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyMinOperatingTemperature;
/** Defines the Sensor Data Parameter Key for Maximum Operating Temperature */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyMaxOperatingTemperature;
/** Defines the Sensor Data Parameter Key for Charging Cycles */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyChargingCycles;
/** Defines the Sensor Data Parameter Key for Memory Level Percentage */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyMemoryLevelPercent;
/** Defines the Sensor Data Parameter Key for Memory Level Size */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyMemoryLevelTotalSize;
/** Defines the Sensor Data Parameter Key for User Age */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyUserAge;
/** Defines the Sensor Data Parameter Key for User Weight */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyUserWeight;
/** Defines the Sensor Data Parameter Key for User Height */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyUserHeight;
/** Defines the Sensor Data Parameter Key for Latest Button Press Event  @see ScoscheRhythmPlusButtonTapEvent */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyButtonPressEvent;
/** Defines the Sensor Data Parameter Key for The Number of Button Press Events */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyButtonPressEventCount;
/** Defines the Sensor Data Parameter Key for The Screen Number */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyScreenNumber;

///---------------------------------------------------------------------------------------
/// GEM
///---------------------------------------------------------------------------------------
/** Defines the Sensor Data Parameter Key for GEM Manufacturer ID */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyGEMManufacturerID;
/** Defines the Sensor Data Parameter Key for GEM Manufacturer Name */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyGEMManufacturerName;
/** Defines the Sensor Data Parameter Key for GEM Hardware Version */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyGEMHardwareVersion;
/** Defines the Sensor Data Parameter Key for GEM Model Number */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyGEMModelNumber;
/** Defines the Sensor Data Parameter Key for GEM Equipment Serial Number */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyGemEquipmentSerialNumber;
/** Defines the Sensor Data Parameter Key for GEM Equipment Software Version */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyGEMEquipmentSoftwareVersion;
/** Defines the Sensor Data Parameter Key for GEM Equipment Utilization */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyGEMEquipmentUtilization;
/** Defines the Sensor Data Parameter Key for GEM Equipment Odometer */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyGEMEquipmentOdometer;
/** Defines the Sensor Data Parameter Key for GEM Equipment Error Code */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyGEMEquipmentErrorCode;


///---------------------------------------------------------------------------------------
/// BLE Specific Sensor Data Parameter Keys
///---------------------------------------------------------------------------------------
/** Defines the Sensor Data Parameter Key for the BLE Peer Address (String) */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyBLEPeerAddress;
/** Defines the Sensor Data Parameter Key for the BLE Appearance */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyBLEAppearance;
/** Defines the Sensor Data Parameter Key for the BLE Scan Mode (BOOL: 1 if it is Active Scan, 0 Passive) */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyBLEActiveScan;
/** Defines the Sensor Data Parameter Key to determine if Sensor has been Active Scanned at least once (BOOL) */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyBLEHasActiveScanned;
/** Defines the Sensor Data Parameter Key for BLE Short Local Name (String) */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyBLEShortLocalName;
/** Defines the Sensor Data Parameter Key for BLE Complete Local Name (String) */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyBLECompleteLocalName;
/** Defines the Sensor Data Parameter Key for BLE Services (NSArray)  */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyBLEServices;

/**
 * Describes the status of the battery in the ANT sensor.
 */
typedef NS_ENUM(NSInteger, NPEBatteryStatus) {
    /** No battery status information is available. */
    NPEBatteryStatusNotAvailable        = 0,
    /** The battery is in new condition. */
    NPEBatteryStatusNew                 = 1,
    /** The battery is in good condition. */
    NPEBatteryStatusGood                = 2,
    /** The battery in in acceptable condition. */
    NPEBatteryStatusOk                  = 3,
    /** The battery is in low condition. */
    NPEBatteryStatusLow                 = 4,
    /** The battery is in critical condition. */
    NPEBatteryStatusCritical            = 5,
};

/**
 * Represents the metadata for the sensor, available from most ANT+ sensors.
 */
@interface NPECommonData : NSObject

///---------------------------------------------------------------------------------------
/// @name Operating Time
///---------------------------------------------------------------------------------------

/**
 * The cummulative operating time of the sensor since the last battery
 * replacement.
 *
 * Increments every 2 or 16 seconds and is reset on battery replacement.
 */
@property (nonatomic, readonly) NSUInteger operatingTime;

/**
 * Indicates if the operating time of the sensor increments every 2 
 * seconds, or 16 seconds.
 *
 * If <b>TRUE</b> the time will be in 16 second increments
 * If <b>FALSE</b> the time will be in 2 second increments
 */
@property (nonatomic, readonly) BOOL operatingTimeInc;

///---------------------------------------------------------------------------------------
/// @name Manufacturer Information
///---------------------------------------------------------------------------------------

/**
 Manufacturer Information

 @since 3.0
 */
@property (nonatomic, readonly, nullable) NPEManufacturer *manufacturer;

/**
 * The ID number of the device manufacturer.
 */
@property (nonatomic, readonly) uint16_t manufacturerId __deprecated_msg("Use manufacturer.companyID 3.0");

/**
 The name of the device manufacturer (read-only)
 */
@property (nonatomic, readonly, nullable) NSString *manufacturerName __deprecated_msg("Use manufacturer.name 3.0");

/**
 * The manufacturer specified device hardware version.
 */
@property (nonatomic, readonly) u_char hardwareVersion;

/**
 * The device model number.
 */
@property (nonatomic, readonly) u_short modelNumber;

/**
 * The manufacturer specified device software version.
 */
@property (nonatomic, readonly) NSInteger softwareVersion;

///---------------------------------------------------------------------------------------
/// @name Serial Number Information
///---------------------------------------------------------------------------------------

/**
 * The the lower 16 bits of a 32 bit device serial number.
 *
 * The device serial number is typically composed of a 16-bit manufacturer
 * defined serial number seed (upper two bytes), and the 16-bit device
 * number (lower two bytes).  this property provides a convenient access
 * to the lower 16-bits of the serial number.
 */
@property (nonatomic, readonly) u_short serialNumberLower __deprecated_msg("use serialNumber. 3.0");

/**
 * The the upper 16 bits of a 32 bit device serial number.
 *
 * The device serial number is typically composed of a 16-bit manufacturer
 * defined serial number seed (upper two bytes), and the 16-bit device
 * number (lower two bytes).  this property provides a convenient access
 * to the upper 16-bits of the serial number.
 */
@property (nonatomic, readonly) u_short serialNumberUpper __deprecated_msg("use serialNumber. 3.0");

/**
 * The the full 32 bit device serial number.
 */
@property (nonatomic, readonly) NSInteger serialNumber;

///---------------------------------------------------------------------------------------
/// @name Battery Information
///---------------------------------------------------------------------------------------

/**
 * The current battery voltage.
 *
 * @note This property is not available for all sensors.  A value of
 * <b>NPE_COMMON_BATTERY_INVALID</b> indicates invalid, or unavailable data.
 */
@property (nonatomic, readonly) float batteryVoltage;

/**
 * The current battery status.
 */
@property (nonatomic, readonly) NPEBatteryStatus batteryStatus;

/**
 * The Sensor connection associated with the common data
 */
@property (nonatomic, readonly, nonnull) NPESensorConnection *connection;

///---------------------------------------------------------------------------------------
/// @name Time Information
///---------------------------------------------------------------------------------------

/**
 * The current device time.
 *
 * @note This property is not available for all sensors.  A value of
 * null indicates invalid, or unavailable data.
 *
 * @since 2.1.0
 */
@property (nonatomic, readonly, nullable) NSDate *time;

///---------------------------------------------------------------------------------------
/// @name Device Error
///---------------------------------------------------------------------------------------

/**
 Device Error Message
 
 @since 2.2.0
 */
@property (nonatomic, readonly, nullable) NPECommonDataError *deviceError;

///---------------------------------------------------------------------------------------
/// @name Device Error
///---------------------------------------------------------------------------------------

/**
 Paired Device Information
 
 @since 3.0
 */
@property (nonatomic, readonly, nullable) NPECommonDataPairedDevice *pairedDevice;

///---------------------------------------------------------------------------------------
/// @name Device Memory Level
///---------------------------------------------------------------------------------------

/**
 Percentage of Memory Used

 @since 2.2.0
 */
@property (nonatomic, readonly) CGFloat memoryUsedPercentage;

/**
 String Value of the remaining Memory Level

 @since 2.2.0
 */
@property (nonatomic, readonly, nullable) NSString *memoryLevel;

@end
NS_ASSUME_NONNULL_END
