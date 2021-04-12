//
//  NPEFrData.h
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

@class NPECommonData;

///---------------------------------------------------------------------------------------
/// Sensor Data Parameter Keys
///
/// Supports Common Data Parameter Keys:
///   NPESensorDataParameterKeyRawData
///
/// See also: NPECommonData
///---------------------------------------------------------------------------------------


/**
 * Represents the most commonly used data available from the ANT+ Forerunner sensor.
 *
 * ANT+ sensors send data in multiple packets.  The NPEFrData combines the
 * most commonly used of this data into a single entity.  The data represents
 * the latest of each data type sent from the sensor.
 *
 * See Header Files for Sensor Data Parameter Keys
 */
@interface NPEFrData : NPESensorData

/**
 * The time of the last distance and/or speed computation.
 *
 * Time starts when SDM is powered ON and continues until it is powered OFF.
 * The integral component of the time data from the sensor is a single byte.
 * Therefore, the time value will roll over after 256 seconds.  This should
 * be taken into account when calculating time offsets.
 */
@property (nonatomic, readonly) float lastTime;

/**
 * The instantaneous speed in meters per second.
 */
@property (nonatomic, readonly) float instantaneousSpeed;

/**
 * The measure of strides accumulated in time (strides per minute).
 */
@property (nonatomic, readonly) float cadence;

/**
 * The accumulated distance measurement.
 *
 * When available, this value is similar to the NPEFrRawData::distance
 * value, but with a larger roll over value.
 */
@property (nonatomic, readonly) float accumulatedDistance;

/**
 * The accumulated stride count.
 *
 * When available, this value is similar to the NPEFrRawData::strideCount
 * value, but with a larger roll over value.
 */
@property (nonatomic, readonly) NSUInteger accumulatedStride;

@end
