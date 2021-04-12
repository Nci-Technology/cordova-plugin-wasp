//
//  NPEBLEManufacturerData.h
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
#import <NpeGate/NPEManufacturer.h>

NS_ASSUME_NONNULL_BEGIN
/**
 BLE Manufacturer Specific Data Object
 
 @since 2.0.6
 */
@interface NPEBLEManufacturerData : NSObject


/**
 The Raw Manufacturer Data
 
 @since 2.0.6
 */
@property (nonatomic, readonly) NSData *rawData;

/**
 The Company Identification portion of the Manufacturer Specific Data
 
 @since 2.0.6
 */
@property (nonatomic, readonly) UInt16 companyID __deprecated_msg("Use manufacturer.companyID 3.0");

/**
 Company name from the Manufacturer Specific Data's Company Identifier
 
 @since 2.0.6
 */
@property (nonatomic, readonly, nullable) NSString *manufacturerName __deprecated_msg("Use manufacturer.name 3.0");

/**
 Manufacturer Information
 
 @since 3.0
 */
@property (nonatomic, readonly, nullable) NPEManufacturer *manufacturer;

@end
NS_ASSUME_NONNULL_END
