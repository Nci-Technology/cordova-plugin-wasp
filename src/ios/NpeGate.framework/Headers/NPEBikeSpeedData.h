//
//  NPEBikeSpeedData.h
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
#import <NpeGate/NPEBikeData.h>

///---------------------------------------------------------------------------------------
/// Sensor Data Parameter Keys
///
/// Supports Common Bike Data Parameter Keys:
///   NPESensorDataParameterKeyWheelRRM
///   NPESensorDataParameterKeyWheelRotations
///
/// Supports Common Data Parameter Keys:
///   NPESensorDataParameterKeySpeed
///   NPESensorDataParameterKeyTotalDistance
///   NPESensorDataParameterKeyRawData
///
/// See also: NPECommonData
///---------------------------------------------------------------------------------------

/**
 Bike Speed Flags

 @since 2.2
 */
typedef NS_OPTIONS(NSInteger, NPEBikeSpeedFlags) {
    /** Bike Speed Stop Indicator */
    NPEBikeSpeedFlagsStopped         = 1 << 0,
};


/**
 * Represents the most commonly used data available from the ANT+ Bike Speed sensor.
 *
 * ANT+ sensors send data in multiple packets.  The NPEBikeSpeedData combines the
 * most commonly used of this data into a single entity.  The data represents
 * the latest of each data type sent from the sensor.
 *
 * See Header Files for Sensor Data Parameter Keys
 */
@interface NPEBikeSpeedData : NPEBikeData

/**
 * The accumulated wheel revolutions since the sensor was connected or reset.
 */
@property (nonatomic, readonly) NSUInteger accumWheelRevolutions;

/**
 * The accumulated time (in NPEUnitTypeSeconds) since the sensor was connected or reset.
 */
@property (nonatomic, readonly) float accumSpeedTime;

/**
 * The instantaneous wheel RPM, based on the last two sensor measurements.
 */
@property (nonatomic, readonly) u_short instantWheelRPM;

/**
 * The instantaneous speed, based on the last two sensor measurements and wheel size in mm.
 */
@property (nonatomic, readonly) float instantSpeed;

/**
 Bike Speed Flags
 
 @since 2.2
 */
@property (nonatomic, readonly) NPEBikeSpeedFlags speedFlags;

@end
