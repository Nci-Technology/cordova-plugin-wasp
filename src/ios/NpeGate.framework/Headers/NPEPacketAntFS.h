//
//  NPEPacketAntFS.h
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
#import <NpeGate/NPEDevicePacketProtocol.h>
#import <NpeGate/NPEANT.h>

@class NPEAntFsBeacon;

/**
 The NPEPacketAntFS Object represents an ANT-FS Data Packet

 @since 3.0.7
 */
@interface NPEPacketAntFS : NSObject <NPEDevicePacketProtocol>

/**
 ANT-FS Beacon

 @since 3.0.7
 */
@property (nonatomic, readonly) NPEAntFsBeacon *beacon;

/**
 The Trasmission Type of the device

 @since 3.0.7
 */
@property (nonatomic, readonly) NPEAntTransType transmissionType;

/**
 Device Type as defined by ANT-FS

 @since 3.0.7
 */
@property (nonatomic, readonly) NPEAntFSDeviceType deviceType;

/**
 The Device Number

 @since 3.0.7
 */
@property (nonatomic, readonly) NSInteger deviceNumber;

/**
 RxTimestamp Value

 @since 3.0.7
 */
@property (nonatomic, readonly) UInt16 rxTimestamp;

@end
