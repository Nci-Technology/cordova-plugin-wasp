//
//  NPEFitnessEquipmentConnection.h
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

@class NPEFitnessEquipmentData;

NS_ASSUME_NONNULL_BEGIN
///---------------------------------------------------------------------------------------
/// Sensor Command Keys
///
/// Supports Common Commands:
///  NPESensorCmdKeyRequestManufacturerInfo
///  NPESensorCmdKeyRequestProductInfo
///  NPESensorCmdKeyRequestBatteryStatus
///  NPESensorCmdKeyPowerDown
///
///---------------------------------------------------------------------------------------

/** Sensor Command Key for Requesting Calibration */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyRequestCalibration;
/** Sensor Command Key for Requesting User Configuration Data */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyRequestUserConfig;
/** Sensor Command Key for Requesting Fitness Equipment Capabilities */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyRequestFECapabilities;
/** Sensor Command Key for Requesting Command Status */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyRequestCommandStatus;
/** Sensor Command Key for setting resistance */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeySetResistance;
/** Sensor Command Key for setting target power */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeySetTargetPower;
/** Sensor Command Key for setting wind resistance */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeySetWindResistance;
/** Sensor Command Key for setting track resistance */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeySetTrackResistance;
/** Sensor Command Key for setting user configuration data */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeySetUserConfiguration;
/** Sensor Command Key for Turning on the Backlight */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyTurnOnBacklight;
/** Sensor Command Key for Sending the Faster Message */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeySendFasterMsg;
/** Sensor Command Key for Sending the Slower Message */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeySendSlowerMsg;
/** Sensor Command Key for Resetting the Accumulated Data */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyResetAccumulatedData;
/** Sensor Command Key for Requesting Device go into Firmware Update Mode */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyEnableDFU;
/** Sensor Command Key for Requesting Device leave Firmware Update Mode */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyDisableDFU;
/** Sensor Command Key for Enable Buttons */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyEnableButtons;
/** Sensor Command Key for Disable Buttons */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyDisableButtons;
/** Sensor Command Key for Enter Registration Mode */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyEnterReigstrationMode;
/** Sensor Command Key for Leave Registration Mode */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyLeaveReigstrationMode;
/** Sensor Command Key for Enter Manufacturing Test Mode */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyEnterManufacturingTestMode;

//Commands for IHRSA
/** Sensor Command Key for Calling Attendant */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyCallAttendant;
/** Sensor Command Key for Canceling Call to Attendant */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyCancelAttendant;


///---------------------------------------------------------------------------------------
/// Sensor Command Parameter Keys
///
/// Support Common Command Parameter Keys:
///     NPESensorCommandParameterKeyGrade
///     NPESensorCommandParameterKeyResistance
///     NPESensorCommandParameterKeySpeed
///     NPESensorCommandParameterKeyWheelCircumference
///     NPESensorCommandParameterKeyUserWeight
///
///---------------------------------------------------------------------------------------

/** Command Parameter for setting Coefficient */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeyCoefficient;
/** Command Parameter for setting Drag Factor */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeyDragFactor;
/** Command Parameter for setting Rolling resistance coefficient */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeyCoefRollingResistance;
/** Command Parameter for setting Gear Ratio */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeyGearRatio;
/** Command Parameter for setting Bike Weight */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeyBikeWeight;
/** Command Parameter for setting Wheel Diameter */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeyWheelDiameter;
/** Command Parameter for setting Wheel Diameter Offset */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeyWheelDiameterOffset;
/** Command Parameter for setting Spin Down */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeySpinDown;
/** Command Parameter for setting Zero Offset */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeyZeroOffset;


/**
 * Represents a connection to an ANT+ Fitness Equipment sensor.
 */
@interface NPEFitnessEquipmentConnection : NPESensorConnection

@end
NS_ASSUME_NONNULL_END
