//
//  NPEAntFsBeacon.h
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

@class NPEManufacturer;

/**
 Beacon Period

 @since 3.0.7
 */
typedef NS_ENUM(UInt8, NPEAntFsBeaconPeriod) {
    /** 0.5 Hz (65535) */
    NPEAntFsBeaconPeriodHalfHz          = 0,
    /** 1Hz (32768) */
    NPEAntFsBeaconPeriodOneHz           = 1,
    /** 2Hz (16384) */
    NPEAntFsBeaconPeriodTwoHz           = 2,
    /** 4Hz (8192) */
    NPEAntFsBeaconPeriodFourHz          = 3,
    /** 8Hz (4096) */
    NPEAntFsBeaconPeriodEightHz         = 4,

    NPEAntFsBeaconPeriodMatchChannel    = 7
};

/**
 Client State

 @since 3.0.7
 */
typedef NS_ENUM(NSInteger, NPEAntFsClientDeviceState) {
    NPEAntFsClientDeviceWaitingForLink      = -1,
    NPEAntFsClientDeviceStateLink           = 0,
    NPEAntFsClientDeviceStateAuth           = 1,
    NPEAntFsClientDeviceStateTrans          = 2,
    NPEAntFsClientDeviceStateBusy           = 3
};

/**
 ANT-FS Authentication Types

 @since 3.0.7
 */
typedef NS_ENUM(NSInteger, NPEAntFsAuthType) {
    NPEAntFsAuthTypePassThrough             = 0,
    NPEAntFsAuthTypeClientSerialRequest     = 1,
    NPEAntFsAuthTypePairingOnly             = 2,
    NpeAntFsAuthTypePasskeyPairing          = 3,
};

/**
 The NPEAntFsBeacon Object represents the ANT-FS Beacon

 The ANT-FS client device transmits a beacon message every channel period. The beacon informs the host of the clients current state and supported modes.

 @since 3.0.7
 */
@interface NPEAntFsBeacon : NSObject

///---------------------------------------------------------------------------------------
/// @name ANT-FS Beacon Status Information
///---------------------------------------------------------------------------------------

/**
 Indicates that the client device currently has data available for download to a host device

 @since 3.0.7
 */
@property (nonatomic, readonly) BOOL dataAvailable;

/**
 Indicates that the client device currently supports uploads

 @since 3.0.7
 */
@property (nonatomic, readonly) BOOL uploadEnabled;

/**
 Indicates that the client device will currently support a pairing operation,

 Typically involve user involvement with the client UI

 @since 3.0.7
 */
@property (nonatomic, readonly) BOOL pairingEnabled;

/**
 Beacon Period

 @since 3.0.7
 */
@property (nonatomic, readonly) NPEAntFsBeaconPeriod beaconPeriod;

/**
 Client State

 @since 3.0.7
 */
@property (nonatomic, readonly) NPEAntFsClientDeviceState clientState;

/**
 Authenticate Type for the Sensor

 @since 3.0.7
 */
@property (nonatomic, readonly) NPEAntFsAuthType authenticationType;

///---------------------------------------------------------------------------------------
/// @name ANT-FS Device Information
///---------------------------------------------------------------------------------------

/**
 Manufacturer Information

 This information is determined in the Link State
 */
@property (nonatomic, readonly, nullable) NPEManufacturer *linkManufacturer;

@end
