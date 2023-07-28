//
//  NPEBikePowerWheelTorqueData.h
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


/**
 * Represents the data available from the Wheel Torque type ANT+ Bike Power sensor.
 *
 * ANT+ sensors send data in multiple packets.  The NPEBikePowerWheelTorqueData
 * combines this data into a single entity.  The data represents the latest of
 * each data type sent from the sensor.
 */
@interface NPEBikePowerWheelTorqueData : NPESensorData

/**
 * Event counter increments with each information update.
 */
@property (nonatomic, readonly) u_char eventCount;

/**
 * Wheel tick count increments with each wheel revolution.
 */
@property (nonatomic, readonly) u_char wheelTicks;

/**
 * Cadence Supported?.
 */
@property (nonatomic, readonly) BOOL cadenceSupported;

/**
 * Coasting or Stopped
 */
@property (nonatomic, readonly) BOOL coastStop;

/**
 * Wheel cadence (RPMs) – if available. Otherwise: 0xFF indicates invalid.
 */
@property (nonatomic, readonly) u_char instantCadence;

/**
 * Accumulated wheel period (updated each event).
 */
@property (nonatomic, readonly) NSUInteger accumulatedWheelPeriod;

/**
 * The total accumulated torque in Nm.
 *
 * Accumulated torque is the sum of the average torque for each update period.
 * For example, in wheel-based power sensors, it is the sum of the average
 * torque for each wheel revolution.
 *
 * @note The accumulator is initialized when the sensor is first connected.
 */
@property (nonatomic, readonly) NSUInteger accumulatedTorque;

/**
 * The total number of wheel revolutions measured since the sensor was
 * connected or reset.
 */
@property (nonatomic, readonly) NSUInteger accumulatedWheelTicks;

/**
 * The total number of crank revolutions measured since the sensor was
 * connected or reset.
 *
 * @note This value is not availabe from all power meters.  The value
 * is not directly measured by the sensor, but calculated based on
 * the torque curve.
 */
@property (nonatomic, readonly) float calculatedCrankTicks;

/**
 * The average speed, in meters per second.
 *
 * @note This value assumes a wheel circumference.
 */
@property (nonatomic, readonly) float averageSpeed;

/**
 * Total distance traveled, in meters.
 *
 * @note This value assumes a wheel circumference.
 */
@property (nonatomic, readonly) NSUInteger distance;

/**
 * The angular velocity of the wheel.
 */
@property (nonatomic, readonly) float angularVelocity;

/**
 * The average torque at the wheel.
 */
@property (nonatomic, readonly) NSUInteger averageTorque;

/**
 * The average power, in watts.
 */
@property (nonatomic, readonly) float averagePower;

/**
 * The instantaneous wheel RPM.
 */
@property (nonatomic, readonly) u_short wheelRPM;

@end
