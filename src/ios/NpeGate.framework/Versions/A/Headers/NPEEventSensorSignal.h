//
//  NPEEventSensorSignal.h
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
#import <NpeGate/NPEEvent.h>

@class Wasp;

@interface NPEEventSensorSignal : NPEEvent

/**
 Reference to the WASP that provided the RSSI Event
 
 @since 2.1
 */
@property (nonatomic, readonly, weak) Wasp *waspRef;

/**
 The RSSI Value
 
 @since 2.1
 */
@property (nonatomic, readonly) NSInteger rssi;

/**
 Packets Per Second for the Event
 
 @since 2.1
 */
@property (nonatomic, readonly) CGFloat packetsPerSecond;

@end
