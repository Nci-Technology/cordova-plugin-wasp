//
//  WaspNetQuality.h
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

/**
 Describes the Network Quality for a WASP Object
 
 @since 2.1.0
 */
@interface WaspNetQuality : NSObject

/**
 Last Round Trip Time over the connection period.

 Provides the last RTT.  This can be used to pace sending commands to the WASP.

 @note Time is in MSEC.  Valid only if in Connection.
 @since 2.1.0
 */
@property (nonatomic, readonly) NSTimeInterval currentRTT;

/**
 Minimum Round Trip Time over the connection period.

 Provides the Minimum RTT.  This can be used to pace sending commands to the WASP.

 @note Time is in MSEC.  Valid only if in Connection.
 @since 2.1.0
 */
@property (nonatomic, readonly) NSTimeInterval minimumRTT;

/**
 Maximum Round Trip Time over the connection period.

 Provides the Command RTT.  This can be used to pace sending commands to the WASP.

 @note Time is in MSEC.  Valid only if in Connection.
 @since 2.1.0
 */
@property (nonatomic, readonly) NSTimeInterval maximumRTT;

/**
 Average Round Trip Time over the connection Period.

 Provides the Average RTT.  This can be used to pace sending commands to the WASP.

 @note Time is in MSEC.  Valid only if in Connection.
 @since 2.1.0
 */
@property (nonatomic, readonly) NSTimeInterval averageRTT;

/**
 Standard Deviation of Round Trip Time over the connection Period.

 Provides the Standard Deviation of RTT.  This can be used to pace sending commands to the WASP.

 @note Time is in MSEC.  Valid only if in Connection.
 @since 2.1.0
 */
@property (nonatomic, readonly) NSTimeInterval stddevRTT;

@end
