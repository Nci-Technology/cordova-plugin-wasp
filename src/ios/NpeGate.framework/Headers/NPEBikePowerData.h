//
//  NPEBikePowerData.h
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

@class NPEBikePowerPowerOnlyData;
@class NPEBikePowerWheelTorqueData;
@class NPEBikePowerCrankTorqueData;
@class NPEBikePowerCTFData;


NS_ASSUME_NONNULL_BEGIN
///---------------------------------------------------------------------------------------
/// Sensor Data Parameter Keys
///
/// Support Common Bike Parameter Keys:
///   NPESensorDataParameterKeyBikeGear
///   NPESensorDataParameterKeyAverageTorque
///   NPESensorDataParameterKeyAngularVelocity
///   NPESensorDataParameterKeyPedalPowerPercent
///   NPESensorDataParameterKeyRightPedalPower
///   NPESensorDataParameterKeyLeftPedalPower
///   NPESensorDataParameterKeyLeftPedalSmoothness
///   NPESensorDataParameterKeyRightPedalSmoothness
///   NPESensorDataParameterKeyCombinedPedalSmoothness
///   NPESensorDataParameterKeyLeftTorqueEffectiveness
///   NPESensorDataParameterKeyRightTorqueEffectiveness
///   NPESensorDataParameterKeyTorqueFrequency
///   NPESensorDataParameterKeyZeroOffset
///   NPESensorDataParameterKeyCrankRotations
///
/// Supports Common Data Parameter Keys:
///   NPESensorDataParameterKeyAveragePower
///   NPESensorDataParameterKeySlope
///   NPESensorDataParameterKeyCapabilities
///   NPESensorDataParameterKeyCalories
///   NPESensorDataPareterKeyLastCalibration
///   NPESensorDataParameterKeyInstantPower
///   NPESensorDataParameterKeyDistance
///   NPESensorDataParameterKeyCurrentTemp (KICKR)
///   NPESensorDataParameterKeyWindSpeed
///   NPESensorDataParameterKeyRawData
///
/// See also: NPECommonData
///---------------------------------------------------------------------------------------

/** Values from the Kickr when sending commands */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyKickrResponse;
/** Kickr Mode of Operation */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyKickrMode;
/** Sensor Data Key for Average Speed */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyAverageSpeed;
/** Sensor Data Key for Calibration ID */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyCalibrationID;
/** Sensor Data Key for Calibration Data */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyCalibrationData;
/** Sensor Data Key for Auto Zero Enabled */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyAutoZeroEnable;
/** Sensor Data Key for Auto Zero Status */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyAutoZeroStatus;
/** Sensor Data Key for Slope Ack */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeySlopeAck;
/** Sensor Data Key for Serial Ack */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeySerialAck;
/** Sensor Data Key for Crank Length */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyCrankLength;
/** Sensor Data Key for Sensor Status */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeySensorStatus;
/** Sensor Data Key for Measurement Output */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyMeasurementOutput;


/** Describes the type of Bike Power Meter. */
typedef NS_ENUM(NSInteger, NPEBikePowerType) {
    /** Indicates that the power meter type has not been determined. */
    NPEBikePowerTypeUnidentified            = 0,
    /** Indicates the Power Only power meter type. */
    NPEBikePowerTypePowerOnly               = 1,
    /** Indicates the Crank Torque power meter type. */
    NPEBikePowerTypeCrankTorque             = 2,
    /** Indicates the Wheel Torque power meter type. */
    NPEBikePowerTypeWheelTorque             = 3,
    /** Indicates the Crank Torque Frequency power meter type. */
    NPEBikePowerTypeCrankTorqueFrequency    = 4,
    /** Indicates the Schwinn power meter type. */
    NPEBikePowerTypeSchwinn                 = 5,
};

/**
 * Describes calibration information for a Bike Power sensor.
 */
typedef struct
{
    /** Specifies the type of calibration data. */
    u_char calibrationId;
    /** varies depending on the calibration ID. */
    u_char reserved1;
    /** varies depending on the calibration ID. */
    u_char reserved2;
    /** varies depending on the calibration ID. */
    u_char reserved3;
    /** varies depending on the calibration ID. */
    u_char reserved4;
    /** varies depending on the calibration ID. */
    u_char reserved5;
    /** varies depending on the calibration ID. */
    u_char reserved6;
    
} NPEBikePowerCalibrationData_t;


/**
 * Represents the most commonly used data available from the ANT+ Bike Power sensor.
 *
 * ANT+ sensors send data in multiple packets.  The NPEBikePowerData combines the
 * most commonly used of this data into a single entity.  The data represents
 * the latest of each data type sent from the sensor.
 *
 * See Header Files for Sensor Data Parameter Keys
 */
@interface NPEBikePowerData : NPESensorData

/**
 * Indicates the type of the power meter.
 *
 * @note After the sensor connects, or is reset, it will take several
 * messages from the device before the sensor type can be determined.
 */
@property (nonatomic, readonly) NPEBikePowerType powerMeterType;

/**
 * The total accumulated torque in Nm.
 *
 * Accumulated torque is the sum of the average torque for each update period.
 * For example, in wheel-based power sensors, it is the sum of the average
 * torque for each wheel revolution.
 *
 * @note The accumulator is initialized when the sensor is first connected.
 */
@property (nonatomic, readonly) float fpAccumulatedTorque;

/**
 * The total accumulated revolutions measured by the sensor.
 *
 * This source of this value depends on the sensor type.  The value will be
 * wheel revolutions for wheel-based sensors, and crank revolutions for
 * crank based sensors.
 */
@property (nonatomic, readonly) NSUInteger ulAccumulatedTicks;

/**
 * The total calculated crank revolutions.
 *
 * This value is available only for certain types of wheel-based sensors.
 */
@property (nonatomic, readonly) float fpCalculatedCrankTicks;

/**
 * The instantaneous crank cadence, in RPM.
 */
@property (nonatomic, readonly) u_char ucInstCadence;

/**
 * The average power measured over the last revolution.
 *
 * The span of this value depends on the type of sensor (wheel revolution for
 * wheel-based sensors, and crank revolution for crank-based sensors).
 */
@property (nonatomic, readonly) NSUInteger ulAveragePower;

/**
 * The event counter value.
 *
 * See the event counter value of the specific power meter type for more
 * about this value (NPEBikePowerCTFData, NPEBikePowerCrankTorqueData,
 * and NPEBikePowerWheelTorqueData).
 */
@property (nonatomic, readonly) u_char ucEventCount;

/**
 * Contains the calibration data sent from the sensor.
 */
@property (nonatomic, readonly) NPEBikePowerCalibrationData_t calibrationData;

/**
 * Data provided by the Power-Only sensor.  Most types of Bike Power
 * sensors provide this data.
 */
@property (nonatomic, readonly) NPEBikePowerPowerOnlyData *powerOnlyData;

/**
 * Data provided by the Wheel-Torque type of Bike Power sensor.
 */
@property (nonatomic, readonly) NPEBikePowerWheelTorqueData *wheelTorqueData;

/**
 * Data provided by the Crank-Torque type of Bike Power sensor.
 */
@property (nonatomic, readonly) NPEBikePowerCrankTorqueData *crankTorqueData;

/**
 * Data provided by the Crank-Torque-Frequency type of Bike Power sensor.
 */
@property (nonatomic, readonly) NPEBikePowerCTFData *crankTorqueFreqData;

/**
 * TRUE if the left torque effectiveness is valid.
 */
@property (nonatomic, readonly) BOOL leftTorqueEffValid;

/**
 * TRUE if the right torque effectiveness is valid.
 */
@property (nonatomic, readonly) BOOL rightTorqueEffValid;

/**
 * TRUE if the left pedal smoothness is valid.
 */
@property (nonatomic, readonly) BOOL leftPedalSmoothValid;

/**
 * TRUE if the right pedal smoothness is valid.
 */
@property (nonatomic, readonly) BOOL rightPedalSmoothValid;

/**
 * TRUE if the combined pedal smoothness is valid.
 */
@property (nonatomic, readonly) BOOL combinedPedalSmoothValid;

/**
 * TRUE if the last message received was a calibration message.
 */
@property (nonatomic, readonly) BOOL calibrationJustReceived;

@end
NS_ASSUME_NONNULL_END
