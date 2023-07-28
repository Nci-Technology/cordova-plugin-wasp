//
//  NPERunningDynamicsData.h
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
#if TARGET_OS_IPHONE
#import <UIKit/UIKit.h>
#elif TARGET_OS_MAC
#import <Cocoa/Cocoa.h>
#import <AppKit/AppKit.h>
#endif

NS_ASSUME_NONNULL_BEGIN
///---------------------------------------------------------------------------------------
/// Sensor Data Parameter Keys
///
/// Supports Common Data Parameter Keys:
///     NPESensorDataParameterKeyTotalSteps
///
/// See also: NPECommonData
///---------------------------------------------------------------------------------------
/** Defines the Sensor Data Parameter Key Running */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyRunning;
/** Defines the Sensor Data Parameter Key Walking */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyWalking;
/** Defines the Sensor Data Parameter Key Vertical Oscillation */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyVerticalOscillation;
/** Defines the Sensor Data Parameter Key Ground Contact Time */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyGroundContactTime;
/** Defines the Sensor Data Parameter Key Instantaneous Stance Time */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyInstantaneousStanceTime;
/** Defines the Sensor Data Parameter Key Ground Contact Balance */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyGroundContactBalance;
/** Defines the Sensor Data Parameter Key Vertical Ratio */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyVerticalRatio;
/** Defines the Sensor Data Parameter Key Step Length */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyStepLength;
/** Defines the Sensor Data Parameter Key Session Leader ID */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeySessionLeaderId;

/**
 Module Orientation

 @since 3.0
 */
typedef NS_ENUM(NSInteger, RunningDynamicsModuleOrientation) {
    /** Module is Right Side Up */
    RunningDynamicsModuleOrientationRightSideUp = 0,
    /** Module is Upside Down */
    RunningDynamicsModuleOrientationUpsideDown = 1,
};


/**
 Represents the data available for the ANT+ Running Dynamics sensor.

 ANT+ sensors send data in multiple packets.  The NPERunningDynamicsData combines the
 most commonly used of this data into a single entity.  The data represents
 the latest of each data type sent from the sensor.

 See Header Files for Sensor Data Parameter Keys

 @since 3.0.6
 */
@interface NPERunningDynamicsData : NPESensorData

/**
 Determinss if the user is Running or Walking

 @since 3.0
 */
@property (nonatomic, readonly) BOOL isRunning;

/**
 Determines if the sensor supports Bidirectional Channel

 @since 3.0
 */
@property (nonatomic, readonly) BOOL biDirectionalChannel;

/**
 Filtered Instantaneous Vertical Oscillation (mm)

 @since 3.0
 */
@property (nonatomic, readonly) CGFloat verticalOscillation;

/**
 Filtered Instantaneous Ground Contact Time (ms)

 @since 3.0
 */
@property (nonatomic, readonly) NSInteger groundContactTime;

/**
 Filtered Instantaneous Stance Time Percentage

 @since 3.0
 */
@property (nonatomic, readonly) CGFloat instantaneousStanceTime;

/**
 Total Step Count

 @since 3.0
 */
@property (nonatomic, readonly) NSUInteger totalSteps;

/**
 Filtered Instantaneous Ground Contact Balance (%)

 @since 3.0
 */
@property (nonatomic, readonly) CGFloat groundContactBalance;

/**
 Vertical Ratio (%))

 @since 3.0
 */
@property (nonatomic, readonly) CGFloat verticalRatio;

/**
 Step Length (mm)

 @since 3.0
 */
@property (nonatomic, readonly) NSInteger stepLength;

/**
 The Orientation of the Sensor

 @since 3.0
 */
@property (nonatomic, readonly) RunningDynamicsModuleOrientation moduleOrientation;

/**
 Session Leaders ID

 If 0, no leader is assigned

 @since 3.0
 */
@property (nonatomic, readonly) NSInteger sessionLeader;

@end
NS_ASSUME_NONNULL_END
