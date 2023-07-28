//
//  NPEBikePowerPowerOnlyData.h
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
 * Represents the data available from the Power-Only type ANT+ Bike Power sensor.
 *
 * ANT+ sensors send data in multiple packets.  The NPEBikePowerPowerOnlyData
 * combines this data into a single entity.  The data represents the latest of
 * each data type sent from the sensor.
 */
@interface NPEBikePowerPowerOnlyData : NPESensorData

/**
 * Power event count, incremented each time the sensor takes a measurement.
 */
@property (nonatomic, readonly) u_char  eventCount;

/**
 * Cadence Supported.
 */
@property (nonatomic, readonly) BOOL cadenceSupported;

/**
 * Coasting or Stopped
 */
@property (nonatomic, readonly) BOOL coastStop;

/**
 * Crank cadence (RPMs) – if available.  Otherwise: 0xFF indicates invalid.
 */
@property (nonatomic, readonly) u_char  instantCadence;

/**
 * Accumulated power (1-watt resolution).
 */
@property (nonatomic, readonly) NSUInteger accumulatedPower;

/**
 * Instantaneous power (1-watt resolution).
 */
@property (nonatomic, readonly) u_short instantPower;

/**
 * Buffered power measurement (1-watt resolution).
 */
@property (nonatomic, readonly) NSUInteger  averagePower;

/**
 * Pedal power data availble.
 */
@property (nonatomic, readonly) BOOL pedalPowerSupported;

/**
 * Pedal Differentation - TRUE if pedal power used and power sensor is capable of differentiating between left and right.
 * Otherwise FALSE
 */
@property (nonatomic, readonly) BOOL pedalDifferentiation;

/**
 * Pedal power contribution between left and right pedals.
 * If pedalDifferentiation is TRUE, then value is for Right Pedal
 * Otherwise the sensor does not known if the value is for the Left or Right Pedal.
 */
@property (nonatomic, readonly) float pedalPowerContributionPercent;

/**
 * Gear Information
 */
@property (nonatomic, readonly) uint8_t gear;

/**
 Heartrate in BMP
 */
@property (nonatomic, readonly) NSUInteger  heartrate;

/**
 Chaloric infomration
 */
@property (nonatomic, readonly) NSUInteger  calories;

@end
