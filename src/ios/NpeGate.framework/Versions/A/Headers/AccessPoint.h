//
//  AccessPoint.h
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
#import <NpeGate/Wasp.h>

/**
 WiFi Access Point Object as provided by the Framework on WiFi Scan from the WASP
 */
@interface AccessPoint : NSObject

/**
 * String representing the SSID of the Access Point returned during a scan
 */
@property (nonatomic, readonly) NSString *sSSID;

/**
 * String representing the bSSID of the Access Point returned during a scan
 */
@property (nonatomic, readonly) NSString *sBSSID;

/**
 * Represents the relative signal strength of the Access Point returned during a scan
 */
@property (nonatomic, readonly) NSInteger rssi;

/**
 * The channel number of the Access Point returned during a scan
 */
@property (nonatomic, readonly) NSInteger channel;

/**
 * String representing the network of the Access Point returned during a scan
 */
@property (nonatomic, readonly) NSString *network;

/**
 * String representing the security mode of the Access Point returned during a scan
 */
@property (nonatomic, readonly) NSString *security;

/**
 Security Mode of the Access Point
 */
@property (nonatomic, readonly) SecurityMode securityMode;

/**
 * Time is took to scan for the Access Point returned during a scan
 */
@property (nonatomic, readonly) NSInteger scanTimer;

@end
