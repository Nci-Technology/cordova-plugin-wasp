//
//  WaspRadioChannel.h
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
#import <NpeGate/NPEAttributes.h>
#import <NpeGate/NPEANT.h>

@class WaspRadio;

/**
 Determines the Status of the Channel
 */
typedef NS_ENUM(NSInteger, WaspRadioChannelStatus) {
    /** Radio Channel Status is Reserved */
    WaspRadioChannelStatusReserved      = -1,
    /** Radio Channel Status is Unassigned */
    WaspRadioChannelStatusUnassigned    = 0,
    /** Radio Channel Status is Assigned */
    WaspRadioChannelStatusAssigned      = 1,
    /** Radio Channel Status is Searching */
    WaspRadioChannelStatusSearching     = 2,
    /** Radio Channel Status is Tracking */
    WaspRadioChannelStatusTracking      = 3,
    /** Radio Channel Status is Pending */
    WaspRadioChannelStatusPending       = 4
};

NS_ASSUME_NONNULL_BEGIN

/**
 The Maximum Radio Channel Frequency for the United States

 @since 2.0.10
 */
FOUNDATION_EXPORT const NSInteger MaximumRadioChannelFrequencyForUnitedStates;

/**
 Defines the Individual Channel Object of the WASP Radio
 */
@interface WaspRadioChannel : NSObject

/**
 Reference to the WaspRadio Object that owns the Channel
 
 @since 2.0.6
 */
@property (nonatomic, readonly, weak) WaspRadio *waspRadioRef;

/**
 Status of the Radio Channel
 
 @since 2.0.6
 */
@property (nonatomic, readonly) WaspRadioChannelStatus status;

/**
 The Channel Number of the Radio Channel
 
 @since 2.0.6
 */
@property (nonatomic, readonly) NSInteger channelNumber;

///---------------------------------------------------------------------------------------
/// @name Channel Commands
///---------------------------------------------------------------------------------------

/**
 Sends command to the Radio Channel to Update Status
 
 @since 2.0.6
 */
- (void)channelStatusOnSuccess:(void (^ _Nullable)(NSInteger channelNumber, WaspRadioChannelStatus status))success onFailure:(void (^ _Nullable)(NSError * _Nonnull error))failure;

/**
 Sends command to the Radio Channel to Assign Channel
 
 @since 2.0.6
 */
- (void)assignChannelOnSuccess:(void (^ _Nullable)(NSInteger channelNumber))success onFailure:(void (^ _Nullable)(NSError * _Nonnull error))failure;

/**
 Sends command to the Radio Channel to UnAssign Channel
 
 @since 2.0.6
 */
- (void)unAssignChannelOnSuccess:(void (^ _Nullable)(NSInteger channelNumber))success onFailure:(void (^ _Nullable)(NSError * _Nonnull error))failure;

@end
NS_ASSUME_NONNULL_END
