//
//  NPEBikePowerConnection.h
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
#import <NpeGate/NPESensorConnection.h>


///---------------------------------------------------------------------------------------
/// Sensor Command Keys
///
/// Supports Common Commands:
///     NPESensorCmdKeyRequestManufacturerInfo
///     NPESensorCmdKeyRequestVersionInfo
///     NPESensorCmdKeyRequestBatteryStatus
///
///---------------------------------------------------------------------------------------
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdCalibrationRequest;
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdAutoZeroConfig;
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdRequestCustomCalibration;
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdSetCustomCalibration;
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdSetSlope;
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdSetSerialNumber;
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdSetCrankParams;
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdGetCrankParams;


///---------------------------------------------------------------------------------------
/// Sensor Command Parameter Keys
///
/// Support Common Command Parameter Keys:
///
///---------------------------------------------------------------------------------------
FOUNDATION_EXPORT NSString * const NPESensorCommandParameterAutoZero __deprecated_msg("use NPESensorCommandParameterKeyAutoZero 3.0");
FOUNDATION_EXPORT NSString * const NPESensorCommandParameterCrankLength __deprecated_msg("use NPESensorCommandParameterKeyCrankLength 3.0");
FOUNDATION_EXPORT NSString * const NPESensorCommandParameterManufacturerSpecific __deprecated_msg("use NPESensorCommandParameterKeyManufacturerSpecific 3.0");
FOUNDATION_EXPORT NSString * const NPESensorCommandParameterSerialNumber __deprecated_msg("use NPESensorCommandParameterKeySerialNumber 3.0");
FOUNDATION_EXPORT NSString * const NPESensorCommandParameterSlopeValue __deprecated_msg("use NPESensorCommandParameterKeySlopeValue 3.0");

/** Sensor Data Parameter Key - Auto Zero */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeyAutoZero;
/** Sensor Data Parameter Key - Crank Length */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeyCrankLength;
/** Sensor Data Parameter Key - Manufacturer Specific Info */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeyManufacturerSpecific;
/** Sensor Data Parameter Key - Serial Number */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeySerialNumber;
/** Sensor Data Parameter Key - Slope Value */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeySlopeValue;


/**
 * Represents a connection to an ANT+ Bike Power sensor.
 */
@interface NPEBikePowerConnection : NPESensorConnection

/**
 * Gets or sets a boolean value indicating whether the NPEBikePowerConnection
 * should automatically calibrate when calibration data is received from the
 * device.
 *
 * @note The default value is <b>TRUE</b>.
 */
@property (nonatomic, assign) BOOL autoCalibrate;


@end
