//
//  NPESensorConnectionDelegate.h
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

#import <NpeGate/npe_hardware_connector_types.h>
#import <NpeGate/NPECmdQueueMsg.h>
#import <NpeGate/NPEAttributes.h>

@class NPESensorConnection;
@class NPESensorData;
@class PageData;
@protocol NPEDevicePacketProtocol;

NS_ASSUME_NONNULL_BEGIN

/**
 * Provides the interface for callback methods used by the NPESensorConnection.
 */
@protocol NPESensorConnectionDelegate <NSObject>

@optional

/**
 * Invoked when the NPESensorConnection has new data available.
 *
 * @param connectionInfo The NPESensorConnection instance.
 *
 * @param data A NPESensorData instance containing the data for the sensor.
 */
- (void)connection:(NPESensorConnection *)connectionInfo didReceiveData:(NPESensorData *)data;

/**
 * Invoked when the NPESensorConnection has received a new packet.
 *
 * @param connectionInfo The NPESensorConnection instance.
 *
 * @param pageData A PageData instance containing the latest page data from the sensor.
 */
- (void)connection:(NPESensorConnection *)connectionInfo pageData:(PageData *)pageData;

/**
 Invoked when the NPESensorConnection has new Packets available.
 
 @param connectionInfo Instance of the NPESensorConnection
 @param packet the Packet Protocol received
 @since 2.1.0
 */
- (void)connection:(NPESensorConnection *)connectionInfo didReceivePacket:(id<NPEDevicePacketProtocol>)packet;

@end
NS_ASSUME_NONNULL_END
