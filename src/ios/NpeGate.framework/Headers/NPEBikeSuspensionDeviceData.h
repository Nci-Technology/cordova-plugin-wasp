//
//  NPEBikeSuspensionDeviceData.h
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
#import <NpeGate/NpeGate.h>

/** Invalid Value for Counts */
FOUNDATION_EXPORT const NSInteger NPEBikeSuspensionInvalidCount;
/** Invalid Value for Time */
FOUNDATION_EXPORT const NSInteger NPEBikeSuspensionInvalidTime;
/** Invalid Value for Temperature */
FOUNDATION_EXPORT const NSInteger NPEBikeSuspensionInvalidTemp;


/**
 Bike Suspension Device Type

 @since 2.2.0
 */
typedef NS_ENUM(NSInteger, NPEBikeSuspensionDeviceType) {
    /** Fork */
    NPEBikeSuspensionDeviceTypeFork             = 0,
    /** Rear Shock */
    NPEBikeSuspensionDeviceTypeRearShock        = 1,
    /** Both Fork and Rear Shock */
    NPEBikeSuspensionDeviceTypeForkAndRearShock = 2,
};

/**
 Represents the Specific Bike Suspension Device Types data
 
 @since 2.2
 */
@interface NPEBikeSuspensionDeviceData : NSObject

/**
 The Bike Suspension Device Type
 
 @since 2.2
 */
@property (nonatomic, readonly) NPEBikeSuspensionDeviceType suspensionDevice;

///---------------------------------------------------------------------------------------
/// @name Suspension Status
///---------------------------------------------------------------------------------------

/**
 Damping Factor
 
 Values from 0 to 1.0
 
 @since 2.2
 */
@property (nonatomic, readonly) CGFloat dampingFactor;

/**
 Auto Unlock Mode Enabled
 
 @since 2.2
 */
@property (nonatomic, readonly) BOOL autoUnlockEnabled;

///---------------------------------------------------------------------------------------
/// @name Manual Actions
///---------------------------------------------------------------------------------------

/**
 Total number of manual lock/unlock actions performed.
 
 @since 2.2
 @note Invalid = NPEBikeSuspensionInvalidCount
 */
@property (nonatomic, readonly) NSInteger manualActionCount;

/**
 Duration of Operation in Manual Mode in Minutes.
 
 @since 2.2
 @note Invalid = NPEBikeSuspensionInvalidTime
 */
@property (nonatomic, readonly) NSInteger minutesInManualMode;


///---------------------------------------------------------------------------------------
/// @name Auto Actions
///---------------------------------------------------------------------------------------

/**
 Total number of auto lock/unlock actions performed.

 @since 2.2
 @note Invalid = NPEBikeSuspensionInvalidCount
 */
@property (nonatomic, readonly) NSInteger autoActionCount;

/**
 Duration of Operation in Audo Mode in Minutes.

 @since 2.2
 @note Invalid = NPEBikeSuspensionInvalidTime
 */
@property (nonatomic, readonly) NSInteger minutesInAutoMode;


///---------------------------------------------------------------------------------------
/// @name Free Fall Summary
///---------------------------------------------------------------------------------------

/**
 Total Number of detected free falls.
 
 @since 2.2
 @note Invalid = NPEBikeSuspensionInvalidCount
 */
@property (nonatomic, readonly) NSInteger totalFreeFalls;

/**
 Time of the Longest detected free fall in miliseconds.
 
 @since 2.2
 @note Invalid = NPEBikeSuspensionInvalidTime
 */
@property (nonatomic, readonly) NSInteger longestFreeFallTime;

///---------------------------------------------------------------------------------------
/// @name System Information
///---------------------------------------------------------------------------------------

/**
 Number of Charging Cycles
 
 @since 2.2
 @note Invalid = NPEBikeSuspensionInvalidCount
 */
@property (nonatomic, readonly) NSInteger numberOfChargingCycles;

/**
 Minimum Operating Temperature
 
 Temperature between -100 and 100 Deg C
 
 @since 2.2
 @note Invalid = NPEBikeSuspensionInvalidTemp
 */
@property (nonatomic, readonly) NSInteger minimumOperatingTemp;

/**
 Maximum Operating Temperature

 Temperature between -100 and 100 Deg C

 @since 2.2
 @note Invalid = NPEBikeSuspensionInvalidTemp
 */
@property (nonatomic, readonly) NSInteger maximumOperatingTemp;

@end
