//
//  NPEActivityConnection.h
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
#import <NpeGate/NPESensorConnection.h>

///---------------------------------------------------------------------------------------
/// Sensor Command Keys
///
/// Supports Common Commands:
///  NPESensorCmdKeyRequestManufacturerInfo
///  NPESensorCmdKeyRequestProductInfo
///  NPESensorCmdKeyRequestBatteryStatus
///  NPESensorCmdKeyRequestTime
///  NPESensorCmdKeySetTime
///  NPESensorCmdKeySetPersonalData
///  NPESensorCmdKeyRequestPersonalData
///
///---------------------------------------------------------------------------------------

/** Sensor Commad Key for Request Personal Settings */
FOUNDATION_EXPORT NPESensorCmdKey _Nonnull const NPESensorCmdKeyRequestPersonalSettings;
/** Command Key to Set Personal Settings */
FOUNDATION_EXPORT NPESensorCmdKey _Nonnull const NPESensorCmdKeySetPersonalSettings;
/** Command Key to Set AssessTrak Specific Values */
FOUNDATION_EXPORT NPESensorCmdKey _Nonnull const NPESensorCmdKeySetAssessTrak;
/** Command Key to Reset AssessTrak Accumulated Values */
FOUNDATION_EXPORT NPESensorCmdKey _Nonnull const NPESensorCmdKeyRestartSession;
/** Command key to request the active screen on the AssessTrak HW */
FOUNDATION_EXPORT NPESensorCmdKey _Nonnull const NPESensorCmdKeyRequestActiveScreen;

///---------------------------------------------------------------------------------------
/// Sensor Command Parameter Keys
///
/// Supports Common Parameter Keys:
///     NPESensorCommandParameterKeyUserWeight
///     NPESensorCommandParameterKeyUserAge
///
///---------------------------------------------------------------------------------------
/** Sensor Data Parameter Key - Gender */
FOUNDATION_EXPORT NPESensorCommandParameterKey _Nonnull const NPESensorCommandParameterKeyGender;
/** Sensor Data Parameter Key - Age */
FOUNDATION_EXPORT NPESensorCommandParameterKey _Nonnull const NPESensorCommandParameterKeyAge;
/** Sensor Data Parameter Key - Height */
FOUNDATION_EXPORT NPESensorCommandParameterKey _Nonnull const NPESensorCommandParameterKeyHeight;
/** Sensor Data Parameter Key - Stride Length */
FOUNDATION_EXPORT NPESensorCommandParameterKey _Nonnull const NPESensorCommandParameterKeyStrideLength;
/** Sensor Data Parameter Key - MVPA Threshold */
FOUNDATION_EXPORT NPESensorCommandParameterKey _Nonnull const NPESensorCommandParameterKeyMvpaThreshold;
/** Sensor Data Parameter Key - Steps Goal */
FOUNDATION_EXPORT NPESensorCommandParameterKey _Nonnull const NPESensorCommandParameterKeyStepsGoal;
/** Sensor Data Parameter Key - Active Display */
FOUNDATION_EXPORT NPESensorCommandParameterKey _Nonnull const NPESensorCommandParameterKeyActiveDisplay;
/** Sensor Data Parameter Key - Operational State */
FOUNDATION_EXPORT NPESensorCommandParameterKey _Nonnull const NPESensorCommandParameterKeyOperationalState;
/** Sensor Data Parameter Key - Lock State */
FOUNDATION_EXPORT NPESensorCommandParameterKey _Nonnull const NPESensorCommandParameterKeyLockState;


/**
 Activity Connection Gender
 
 @since 3.0
 */
typedef NS_ENUM(NSInteger, NPEActivityConnectionGender) {
    /** Gender Male */
    NPEActivityConnectionGenderMale     = 0,
    /** Gender Female */
    NPEActivityConnectionGenderFemale   = 1
};

/**
 Activity Connection Display State
 
 @since 3.0
 */
typedef NS_ENUM(NSInteger, NPEActivityConnectionDisplayState) {
    /** Display State MVPA */
    NPEActivityConnectionDisplayStateMvpa       = 0,
    /** Display state Distance */
    NPEActivityConnectionDisplayStateDistance   = 1,
    /** Display state Time */
    NPEActivityConnectionDisplayStateTime       = 2,
    /** Display state Steps */
    NPEActivityConnectionDisplayStateSteps      = 3,
    /** Display state Goal */
    NPEActivityConnectionDisplayStateGoal       = 4
};

/**
 Activity Connection Lock State
 
 @since 3.0
 */
typedef NS_ENUM(NSInteger, NPEActivityConnectionLockState) {
    /** No Request */
    NPEActivityConnectionLockStateNone      = 0,
    /** Lock */
    NPEActivityConnectionLockStateLock      = 1,
    /** Unlock */
    NPEActivityConnectionLockStateUnlock    = 2

};

/**
 * Represents a connection to an ANT+ Activity Monitor sensor.
 *
 * @since 2.2.0
 */
@interface NPEActivityConnection : NPESensorConnection


@end
