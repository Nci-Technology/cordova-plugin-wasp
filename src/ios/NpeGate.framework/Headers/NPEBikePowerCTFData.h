//
//  NPEBikePowerCTFData.h
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
 * Represents the data available from the Crank Torque Frequency type ANT+ Bike Power sensor.
 *
 * ANT+ sensors send data in multiple packets.  The NPEBikePowerCTFData
 * combines this data into a single entity.  The data represents the latest of
 * each data type sent from the sensor.
 */
@interface NPEBikePowerCTFData : NPESensorData

/**
 * Rotation event counter increments with each completed pedal revolution.
 */
@property (nonatomic, readonly) u_char eventCount;

/**
 * Slope defines the variation of the output frequency.
 */
@property (nonatomic, readonly) u_short slope;

/**
 * Time of most recent rotation event (1/2000s resolution).
 */
@property (nonatomic, readonly) u_short timestamp;

/**
 * The average cadence.
 */
@property (nonatomic, readonly) float averageCadence;

/**
 * The calibration offset value stored on the sensor.
 *
 * This value is determined by the device during calibration, and returned
 * in response to a calibration request.  This value should be stored at
 * the application level, and used when initializing the sensor.  This
 * is done via the NPEWifiInterface::setBikePowerCalibrationOffset: method.
 */
@property (nonatomic, readonly) u_short calibrationOffset;

/**
 *  The average power, in watts.
 */
@property (nonatomic, readonly) float averagePower;

///---------------------------------------------------------------------------------------
/// @name Torque Data
///---------------------------------------------------------------------------------------

/**
 * Count of most recent torque event.
 */
@property (nonatomic, readonly) u_short torqueTickStamp;

/**
 * The torque frequency.
 */
@property (nonatomic, readonly) float torqueFrequency;

/**
 * The total number of crank revolutions measured since the sensor was
 * connected or reset.
 */
@property (nonatomic, readonly) NSUInteger accumulatedCrankTicks;

/**
 * The average torque at the crank.
 */
@property (nonatomic, readonly) float averageTorque;

/**
 * The total accumulated torque in Nm.
 *
 * Accumulated torque is the sum of the average torque for each update period.
 * For example, in wheel-based power sensors, it is the sum of the average
 * torque for each wheel revolution.
 *
 * @note The accumulator is initialized when the sensor is first connected.
 */
@property (nonatomic, readonly) float accumulatedTorque;

@end
