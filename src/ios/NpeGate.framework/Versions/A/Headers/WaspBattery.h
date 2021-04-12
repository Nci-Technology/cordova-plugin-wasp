//
//  WaspBattery.h
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
#if TARGET_OS_IPHONE
#import <UIKit/UIKit.h>
#elif TARGET_OS_MAC
#import <AppKit/AppKit.h>
#endif

///---------------------------------------------------------------------------------------
/// Battery Information
///---------------------------------------------------------------------------------------
/** Describes the Battery Low Voltage value */
FOUNDATION_EXPORT const CGFloat BATTERY_LOW_VOLTAGE;
/** Describes the Battery High Voltage value */
FOUNDATION_EXPORT const CGFloat BATTERY_HIGH_VOLTAGE;


/**
 Defines the WASP Battery Information
 
 @since 2.2
 */
@interface WaspBattery : NSObject

///---------------------------------------------------------------------------------------
/// @name Battery Information
///---------------------------------------------------------------------------------------

/**
 Battery Voltage
 
 @since 2.2
 */
@property (nonatomic, readonly) float batteryVoltage;

/**
 Battery Percentage from 0 to 1
 
 @since 2.2
 */
@property (nonatomic, readonly) float batteryPercentage;

/**
 Determines if the Battery is Charging
 
 @since 2.2
 */
@property (nonatomic, readonly, getter=isBatteryCharging) BOOL batteryCharging;

/**
 Connected to Power
 
 @since 2.2
 */
@property (nonatomic, readonly, getter=isConnectedToPower) BOOL connectedToPower;


@end
