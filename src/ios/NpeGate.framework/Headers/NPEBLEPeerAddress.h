//
//  NPEBLEPeerAddress.h
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
#import <NpeGate/NPEBLE.h>

/**
 NPEBLEPeerAddress Object provides information for the BLE Peer Address.  
 
 This is the actual Peer Address for the BLE Sensors.
 
 @since 2.0.6
 */
@interface NPEBLEPeerAddress : NSObject


/**
 The Peer Address Type
 
 @since 2.0.6
 */
@property (nonatomic, readonly) BLEPeerAddressType addressType;

/**
 The String value of the Peer Address
 
 @since 2.0.6
 */
@property (nonatomic, readonly) NSString *stringValue;

/**
 A pseudo deviceID Generated from the PeerAddress
 
 @since 2.0.6
 */
@property (nonatomic, readonly) NSInteger deviceID;

/**
 The Organizationally Unique Identifier (OUI/MA) portion of the Peer Address
 
 @since 2.0.6
 */
@property (nonatomic, readonly) NSString *oui;

/**
 The Company name associated with the OUI
 
 @since 2.0.6
 */
@property (nonatomic, readonly) NSString *ouiCompanyName;

/**
 The Company Assigned portion of the Peer Address
 
 @since 2.0.6
 */
@property (nonatomic, readonly) NSString *companyAssigned;

@end
