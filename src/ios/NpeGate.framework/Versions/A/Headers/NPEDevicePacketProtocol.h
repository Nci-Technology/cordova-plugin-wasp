//
//  NPEDevicePacketProtocol.h
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


@class WaspRadio;
@class Wasp;

/**
 Protocol for Device Packets
 
 @since 2.0.6
 */
@protocol NPEDevicePacketProtocol <NSObject>

/**
 Timestamp of the last data packet
 
 @since 2.0.6
 */
@property (nonatomic, readonly) NSDate *lastDataTime;

/**
 RSSI of the last data packet for the Advertisment.
 
 The value will range from 0 to -128
 
 @since 2.0.6
 */
@property (nonatomic, readonly) SInt8 rssi;

/**
 Raw Packet Data
 
 @since 2.0.6
 */
@property (nonatomic, readonly) NSData *rawData;

///---------------------------------------------------------------------------------------
/// @name Other Info
///---------------------------------------------------------------------------------------

/**
 Reference to the WASP Object that the packet is coming from
 
 @since 2.0.6
 */
@property (nonatomic, weak, readonly) Wasp *wasp;

/**
 Reference to the Radio Packet came in from
 
 @since 2.0.6
 */
@property (nonatomic, weak, readonly) WaspRadio *radio;

@end
