//
//  NPENikeData.h
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

@class NPEBLEAdvertisement;


NS_ASSUME_NONNULL_BEGIN
/////---------------------------------------------------------------------------------------
///// Sensor Data Parameter Keys
/////
///// Supports Common Data Parameter Keys:
/////   NPESensorDataParameterKeyRawData
/////
///// See also: NPECommonData
/////---------------------------------------------------------------------------------------
/** Defines the Sensor Data Parameter Key for Nike Fuel Rate From a sensor */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyFuelRate;
/** Defines the Sensor Data Parameter Key for Nike Session Fuel From a sensor */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeySessionFuel;
/** Defines the Sensor Data Parameter Key for Nike Session Work From a sensor */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeySessionWork;
/** Defines the Sensor Data Parameter Key for Nike Heart Rate Strain From a sensor */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyHeartRateStrain;

/**
 Represents the data available from a Nike Sensor

 @since 3.0.8
 */
@interface NPENikeData : NPESensorData

/**
 If the Sensor is a Group Sensor

 @since 3.0.8
 */
@property (nonatomic, readonly) BOOL isGroupSensor;

/**
 Elapsed Time

 @since 3.0.8
 */
@property (nonatomic, nonnull, readonly) NSNumber *elapsedTime;

/**
 Elapsed Time

 @since 3.0.8
 */
@property (nonatomic, nonnull, readonly) NSNumber *heartRate;

/**
 Current Power

 @since 3.0.8
 */
@property (nonatomic, nonnull, readonly) NSNumber *currentPower;

/**
 Nike Fuel Rate

 @since 3.0.8
 */
@property (nonatomic, nonnull, readonly) NSNumber *fuelRate;

/**
 Nike Fuel Rate

 @since 3.0.8
 */
@property (nonatomic, nonnull, readonly) NSNumber *sessionFuel;

/**
 Nike Fuel Rate

 @since 3.0.8
 */
@property (nonatomic, nonnull, readonly) NSNumber *sessionWork;

/**
 Nike Fuel Rate

 @since 3.0.8
 */
@property (nonatomic, nonnull, readonly) NSNumber *sessionHrStrain;

@end
NS_ASSUME_NONNULL_END
