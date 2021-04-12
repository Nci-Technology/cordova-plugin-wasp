//
//  NPECommonDataPairedDevice.h
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
#import <NpeGate/NPEANTDefines.h>

/**
 ANT Common Data Paired Status

 @since 3.0
 */
typedef NS_ENUM(NSInteger, NPECommonDataPairStatus) {
    /** Not Paired */
    NPECommonDataPairStatusNotPaired    = 0,
    /** Paired */
    NPECommonDataPairStatusPaired       = 1,
};

/**
 ANT Common Data Paired Connection State
 
 @since 3.0
 */
typedef NS_ENUM(NSInteger, NPECommonDataConnectionState) {
    /** Closed Channel */
    NPECommonDataConnectionStateClosedChannel       = 0,
    /** Searching */
    NPECommonDataConnectionStateSearching           = 1,
    /** Synchronised */
    NPECommonDataConnectionStateSynchronised        = 2
};

/**
 ANT Common Data Paired Network Key
 
 @since 3.0
 */
typedef NS_ENUM(NSInteger, NPECommonDataNetworkKey) {
    /** Public Key */
    NPECommonDataNetworkKeyPublic       = 0,
    /** Private Key */
    NPECommonDataNetworkKeyPrivate      = 1,
    /** ANT+ Managed */
    NPECommonDataNetworkKeyAntPlus      = 2,
    /** ANT-FS */
    NPECommonDataNetworkKeyAntFS        = 3
};

/**
 Describes other ANT Devices that are paired to the device
 
 @since 3.0
 */
@interface NPECommonDataPairedDevice : NSObject

/**
 Device Index
 
 If multiple devices are in the system, this provides an index to which device is referenced.
 
 @since 3.0
 */
@property (nonatomic, readonly) NSInteger deviceIndex;

/**
 Defines if the Pairing Status of the Device
 
 @since 3.0
 */
@property (nonatomic, readonly) NPECommonDataPairStatus pairStatus;

/**
 Connection State
 
 @since 3.0
 */
@property (nonatomic, readonly) NPECommonDataConnectionState connectionState;

/**
 ANT Network Key type
 
 @since 3.0
 */
@property (nonatomic, readonly) NPECommonDataNetworkKey networkKey;

/**
 Device Number of the Peripheral device
 
 @since 3.0
 */
@property (nonatomic, readonly) NSInteger deviceNumber;

/**
Transmission Type of the Peripheral device

 @since 3.0
 */
@property (nonatomic, readonly) NPEAntTransType transmissionType;

/**
 Device Type of the Peripheral device

 @since 3.0
 */
@property (nonatomic, readonly) NPEAntDeviceType deviceType;

@end
