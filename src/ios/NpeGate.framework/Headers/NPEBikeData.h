//
//  NPEBikeData.h
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

#import <NpeGate/NPESensorData.h>


///---------------------------------------------------------------------------------------
/// Sensor Data Parameter Keys
///---------------------------------------------------------------------------------------

/** Defines the Sensor Data Parameter Key for Wheel RPM */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyWheelRRM;
/** Defines the Sensor Data Parameter Key for Accumulated Wheel Rotations */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyWheelRotations;
/** Defines the Sensor Data Parameter Key for Accumulated Crank Rotations */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyCrankRotations;
/** Defines the Sensor Data Parameter Key for Bike Gear  */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyBikeGear;
/** Defines the Sensor Data Parameter Key for Average Torque data  */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyAverageTorque;
/** Defines the Sensor Data Parameter Key for Accumulated Torque data  */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyAccumTorque;
/** Defines the Sensor Data Parameter Key for Angular Velocity data  */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyAngularVelocity;
/** Defines the Sensor Data Parameter Key for Pedal Power Percentage data  */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyPedalPowerPercent;
/** Defines the Sensor Data Parameter Key for Right Pedal Power data  */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyRightPedalPower;
/** Defines the Sensor Data Parameter Key for Left Pedal Power data  */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyLeftPedalPower;
/** Defines the Sensor Data Parameter Key for Right Pedal Smoothness data  */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyRightPedalSmoothness;
/** Defines the Sensor Data Parameter Key for Left Pedal Smoothness data  */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyLeftPedalSmoothness;
/** Defines the Sensor Data Parameter Key for Combined Pedal Smoothness data  */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyCombinedPedalSmoothness;
/** Defines the Sensor Data Parameter Key for Left Torque Effectiveness data  */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyLeftTorqueEffectiveness;
/** Defines the Sensor Data Parameter Key for Right Torque Effectiveness data  */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyRightTorqueEffectiveness;
/** Defines the Sensor Data Parameter Key for Torque Frequency data  */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyTorqueFrequency;
/** Defines the Sensor Data Parameter Key for Sensor Orientation in degrees  */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeySensorOrientation;
/** Defines the Sensor Data Parameter Key for Rider Position  */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyRidingPosition;
/** Defines the Sensor Data Parameter Key for Diplay Zones  */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyDisplayZones;
/** Defines the Sensor Data Parameter Key for Accumulation Zones  */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyAccumulationZones;
/** Defines the Sensor Data Parameter Key for Bike Wheel Circumference  */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyBikeWheelCircumference;
/** Defines the Sensor Data Parameter Key for Bike Wheel Diameter Offset  */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyBikeWheelDiameterOffset;
/** Defines the Sensor Data Parameter Key for Bike Weight  */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyBikeWeight;
/** Defines the Sensor Data Parameter Key for Bike Gear Ratio  */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyBikeGearRatio;
/** Defines the Sensor Data Parameter Key for Zero Offset Data  */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyZeroOffset;


/**
 * Represents the most commonly used data available from ANT+ Bike Sensors
 *
 * ANT+ sensors send data in multiple packets.  The NPEBikeData combines the
 * most commonly used of this data into a single entity.  The data represents
 * the latest of each data type sent from the sensor.
 *
 * See Header Files for Common Bike Sensor Data Parameter Keys
 */
@interface NPEBikeData : NPESensorData

@end
