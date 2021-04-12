//
//  NPEWaspPoeDistressBeacon.h
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
#import <NpeGate/NpeGate.h>

/**
 System State of the PoE during a distress event.
 
 @since 2.2.0
 */
typedef NS_ENUM(NSInteger, WaspPoeDistressState) {
    /** Bootloader Running */
    WaspPoeDistressStateBootloaderRunning         = 0,
    /** Maximum Watchdog Timeouts Occurred */
    WaspPoeDistressStateMaximumWatchdog           = 1,
    /** Bad Application CRC */
    WaspPoeDistressStateApplicationCrcError       = 2,
    /** Bad Application Stack Pointer */
    WaspPoeDistressStateApplicationStackError     = 3,
    /** Bad Application Symbols Table */
    WaspPoeDistressStateApplicationSymbolError    = 4,
    /** Application Running */
    WaspPoeDistressStateApplicationRunning        = 5
};

/**
 Impliments the WASP PoE Distress Beacon
 
 When a WASP PoE running bootloader 1.7+ detects that no application is loaded it will send out a distress beacon.  This indicates that firmware needs to be reloaded on the WASP. 
 
 @note Requires at least PoE Bootloader 1.7 and Application 2.4.0
 @since 2.2.0
 */
@interface NPEWaspPoeDistressBeacon : NSObject

/**
 IP Address of the PoE WASP
 
 @since 2.2.0
 */
@property (nonnull, nonatomic, readonly) NSString *ipAddress;

/**
 Bootloader Version
 
 The version of the Bootloader on the PoE.
 
 @since 2.2.0
 */
@property (nonnull, nonatomic, readonly) NSString *bootloaderVersion;

/**
 Application Version of the last running Application on the PoE.
 
 If the property is null then no applicaiton has been detected.

 @since 2.2.0
 */
@property (nullable, nonatomic, readonly) NSString *applicationVersion;

/**
 Current System State
 
 @since 2.2.0
 */
@property (nonatomic, readonly) WaspPoeDistressState systemState;

/**
 MAC Address of the PoE WASP
 
 @since 2.2.0
 */
@property (nonnull, nonatomic, readonly) NSString *macAddress;

/**
 Bootloader Hash Value
 
 @since 2.2.0
 */
@property (nonnull, nonatomic, readonly) NSString *bootloaderHash;

/**
 Application Hash Value
 
 @since 2.2.0
 */
@property (nonnull, nonatomic, readonly) NSString *applicationHash;

/**
 The count of Watchdog resets the application has had since the last successful run, power on, or software reset.
 
 @since 2.2.0
 */
@property (nonatomic, readonly) NSInteger currentWatchDogCount;

/**
 The count of total Watchdog resets the application has had since powering on, or software reset.
 */
@property (nonatomic, readonly) NSInteger totalWatchDogCount;

@end
