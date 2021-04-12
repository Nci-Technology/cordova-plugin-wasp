//
//  NPEActivityData.h
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
#import <NpeGate/NPEActivityConnection.h>


///---------------------------------------------------------------------------------------
/// Sensor Data Parameter Keys
///
/// Supports Common Data Parameter Keys:
///   NPESensorDataParameterKeyRawData
///
///---------------------------------------------------------------------------------------

/** Defines the Sensor Data Parameter Key for Activity State */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyActivityState;
/** Defines the Sensor Data Parameter Key for Activity Capabilities */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyActivityCapabilities;
/** Defines the Sensor Data Parameter Key for Activity Configurations */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyActivityConfigurations;
/** Defines the Sensor Data Parameter Key for Activity Steps */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyActivitySteps;
/** Defines the Sensor Data Parameter Key for Activity Distance */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyActivityDistance;
/** Defines the Sensor Data Parameter Key for Activity Time */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyActivityTime;
/** Defines the Sensor Data Parameter Key for Activity Step Rate */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyActivityStepRate;
/** Defines the Sensor Data Parameter Key for MVPA Percent */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyMvpaPercent;
/** Defines the Sensor Data Active Display screen */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyActiveDisplay;
/** Defines the Sensor Data Users Gender */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyGender;
/** Defines the Sensor Data Users Age */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyAge;
/** Defines the Sensor Data Users Stride Length */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyStrideLength;
/** Defines the Sensor Data Users MVPA Threshold */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyMvpaThreshold;
/** Defines the Sensor Data Users Steps Goal */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyStepsGoal;

/**
 * Represents the most commonly used data available from the ANT+ Activity Monitor.
 *
 * ANT+ sensors send data in multiple packets.  The NPEActivityData combines the
 * most commonly used of this data into a single entity.  The data represents
 * the latest of each data type sent from the sensor.
 *
 * @since 2.2.0
 */
@interface NPEActivityData : NPESensorData


/**
 Steps
 
 @since 2.2.0
 */
@property (nonatomic, readonly) NSInteger activityState;

/**
 Steps
 
 @since 2.2.0
 */
@property (nonatomic, readonly) NSInteger activitySteps;

/**
 Activity Time in seconds
 
 @since 2.2.0
 */
@property (nonatomic, readonly) NSInteger activityTime;

/**
 Activity Step Rate
 
 @since 2.2.0
 */
@property (nonatomic, readonly) NSInteger activityStepRate;

/**
 Stride Length

 @since 2.2.0
 */
@property (nonatomic, readonly) NSInteger strideLength;

/**
 Active Display
 
 @since 2.2.0
 */
@property (nonatomic, readonly) NPEActivityConnectionDisplayState activeDisplay;

/**
 Active Distance in 0.01km
 
 @since 2.2.0
 */
@property (nonatomic, readonly) NSInteger activityDistance;

/**
 Active Goal
 
 @since 2.2.0
 */
@property (nonatomic, readonly) NSInteger activityGoal;

/**
 Active Device Capabilities
 
 @since 2.2.0
 */
@property (nonatomic, readonly) NSInteger activityCapabilities;

/**
 Active Device Configurations
 
 @since 2.2.0
 */
@property (nonatomic, readonly) NSInteger activityConfigurations;

///---------------------------------------------------------------------------------------
/// @name User Information
///---------------------------------------------------------------------------------------

/**
 Gender
 
 @since 2.2.0
 */
@property (nonatomic, readonly) NPEActivityConnectionGender gender;

/**
 Age
 
 @since 2.2.0
 */
@property (nonatomic, readonly) NSInteger age;

/**
 Height
 
 @since 2.2.0
 */
@property (nonatomic, readonly) NSInteger height;

/**
 Weight
 
 @since 2.2.0
 */
@property (nonatomic, readonly) NSInteger weight;

///---------------------------------------------------------------------------------------
/// @name MVPA Information
///---------------------------------------------------------------------------------------

/**
 Activity MVPA Percentage

 @since 2.2.0
 */
@property (nonatomic, readonly) NSInteger activityMvpaPercent;

/**
 MVPA Threshold
 
 @since 2.2.0
 */
@property (nonatomic, readonly) NSInteger mvpaThreshold;

@end
