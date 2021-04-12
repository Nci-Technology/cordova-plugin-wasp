//
//  PageData.h
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
 The ANT+ Page Data
 */
@interface PageData : NSObject

/**
 The Page Data coming from the Network
 */
@property (nonatomic, readonly) NSData *pageData;

/**
 A RSSI associated with the data
 */
@property (nonatomic, readonly) NSNumber *rssiNum;

/**
 Identifier string for the WASP which is sending the PageData
 */
@property (nonatomic, readonly) NSString *waspID;

/**
 The WASP Hardware Type associated with the PageData
 
 @since 1.3.4
 */
@property (nonatomic, readonly) WaspProductType waspType;

@end
