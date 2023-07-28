//
//  NPEAntfsProtocol.h
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
#import <NpeGate/NPEANT.h>

@protocol NPEAntfsDelegate;

@class NPEPacketAntFS;
@class NPEAntFsBeacon;
@class NPESensorConnection;

/**
 Sensors/Devices which conform to the NPEAntfsProtocol provide the ANT-FS Interface

 @since 3.0.7
 */
@protocol NPEAntfsProtocol <NSObject>

/**
 Delegate Methods for ANT-FS Devices

 @since 3.0.7
 */
@property (nonatomic, weak) id<NPEAntfsDelegate> antFsDelegate;

///---------------------------------------------------------------------------------------
/// @name ANT-FS Beacon Information
///---------------------------------------------------------------------------------------

/**
 ANT-FS Packet
 */
@property (nonatomic, readonly) NPEPacketAntFS *antFSPacket;

/**
 ANT-FS Beacon
 */
@property (nonatomic, readonly) NPEAntFsBeacon *beacon;

///---------------------------------------------------------------------------------------
/// @name ANT-FS Client Commands
///---------------------------------------------------------------------------------------

/**
 Issue the Link command to the ANT-FS Device

 @since 3.0.7
 */
- (void)issueLinkCommand;

@end

/**
 Delegates for ANT-FS
 */
@protocol NPEAntfsDelegate <NSObject>

@optional

/**
 Provides Feedback on ANT-FS Authentication

 @param connection Sensor Connection
 @param authenticated If the Sensor Authenticated
 */
- (void)antFSConnection:(NPESensorConnection *)connection didAuthenticate:(BOOL)authenticated;

/**
 Provides Error Feedback for the ANT-FS Sensor

 @param connection Sensor Connection
 @param error Error Message upon Error conditions
 */
- (void)antFSConnection:(NPESensorConnection *)connection didReceiveError:(NSError *)error;

/**
 Provides State Changes for the ANT-FS Sensor

 @param connection Sensor Connection
 @param state ANT-FS State
 */
- (void)antFSConnection:(NPESensorConnection *)connection didChangeState:(NPEAntFsState)state;

/**
 Provides Response Information for ANT-FS Sensor

 @param connection Sensor Connection
 @param response ANT-FS Response Message
 */
- (void)antFSConnection:(NPESensorConnection *)connection didReceiveResponse:(NPEAntFsResponseMessage)response;

/**
 Provides Upload progress ANT-FS Sensor

 @param connection Sensor Connection
 @param progress Progress of Upload
 */
- (void)antFSConnection:(NPESensorConnection *)connection uploadProgress:(double)progress;

@end
