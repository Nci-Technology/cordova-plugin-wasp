//
//  NPEFootpodData.h
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
#import <NpeGate/NPESensorLocationProtocol.h>

@class NPECommonData;

NS_ASSUME_NONNULL_BEGIN
///---------------------------------------------------------------------------------------
/// Sensor Data Parameter Keys
///
/// Supports Common Data Parameter Keys:
///   NPESensorDataParameterKeyAccumStrides
///   NPESensorDataParameterKeyAccumDistance
///   NPESensorDataParameterKeyCapabilities
///   NPESensorDataParameterKeySpeed
///   NPESensorDataParameterKeyCalories
///   NPESensorDataParameterKeyLocation
///   NPESensorDataParameterKeyTotalDistance
///   NPESensorDataParameterKeyRawData
///   NPESensorDataParameterKeyCadence
///
/// See also: NPECommonData
///---------------------------------------------------------------------------------------

/** Sensor Data Parameter Key for Total Strides */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyTotalStrides;
/** Sensor Data Parameter Key for Virtual Speed */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyVirtualSpeed;
/** Sensor Data Parameter Key for Update Latency */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyUpdateLatency;
/** Sensor Data Parameter Key for Sensor Health */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyDeviceHealth;


/**
 The health of the Footpod
 
 @since 2.1.0
 */
typedef NS_ENUM(NSInteger, FootpodHealth) {
    /** Footpod is Ok */
    FootpodHealthOk         = 0,
    /** Footpod has an Error */
    FootpodHealthError      = 1,
    /** Footpod has a warning */
    FootpodHealthWarning    = 2,
    /** Reserved Value */
    FootpodHealthReserved   = 3
};


/**
 * Represents the most commonly used data available from the ANT+ Stride sensor.
 *
 * ANT+ sensors send data in multiple packets.  The NPEFootpodData combines the
 * most commonly used of this data into a single entity.  The data represents
 * the latest of each data type sent from the sensor.
 *
 * See Header Files for Sensor Data Parameter Keys
 */
@interface NPEFootpodData : NPESensorData <NPESensorLocationProtocol>

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
 Health of the Footpod Device

 @since 2.1.0
 */
@property (nonatomic, readonly) FootpodHealth health;

///---------------------------------------------------------------------------------------
/// @name Speed Cadence Data
///---------------------------------------------------------------------------------------

/**
 * The instantaneous speed in meters per second.
 */
@property (nonatomic, readonly) float instantaneousSpeed;

/**
 * The measure of strides accumulated in time (strides per minute).
 */
@property (nonatomic, readonly) float cadence;

///---------------------------------------------------------------------------------------
/// @name Distance Data
///---------------------------------------------------------------------------------------

/**
 * The accumulated distance measurement.
 *
 * When available, this value is similar to the NPEFootpodRawData::distance
 * value, but with a larger roll over value.
 */
@property (nonatomic, readonly) float accumulatedDistance;

/**
 * The accumulated distance measurement.
 *
 * When available, this value is the total distance measured since the last 
 * battery change.
 */
@property (nonatomic, readonly) float totalDistance;


///---------------------------------------------------------------------------------------
/// @name Stride Data
///---------------------------------------------------------------------------------------

/**
 * The accumulated stride count.
 *
 * When available, this value is similar to the NPEFootpodRawData::strideCount
 * value, but with a larger roll over value.
 */
@property (nonatomic, readonly) NSUInteger accumulatedStride;

/**
 * The accumulated stride count.
 *
 * When available, this value is the total number of strides since the last
 * battery change.
 */
@property (nonatomic, readonly) NSUInteger totalStride;


///---------------------------------------------------------------------------------------
/// @name Step Data
///---------------------------------------------------------------------------------------

/**
 Accumulated Steps
 
 @since 2.2
 */
@property (nonatomic, readonly) NSUInteger accumulatedSteps;

/**
 Total Step Count
 
 @since 2.2
 */
@property (nonatomic, readonly) NSUInteger totalSteps;


/**
 Steps per Minute
 
 @since 2.2
 */
@property (nonatomic, readonly) float stepsPerMinute;

@end
NS_ASSUME_NONNULL_END
