//
//  NPECommonDataError.h
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
 ANT Common Data Error Description Error Level

 @since 2.2.0
 */
typedef NS_ENUM(NSInteger, NPECommonDataErrorLevel) {
    /** Reserved */
    NPECommonDataErrorLevelReserved     = 0,
    /** Device will recover automatically from the error state */
    NPECommonDataErrorLevelWarning      = 1,
    /** Device will not automatically recover from the error state. User action may be required */
    NPECommonDataErrorLevelCritical     = 2
};

/** Defines the System Component Index Error of Type General System Error.  Non Component */
FOUNDATION_EXPORT const NSInteger NPECommonDataErrorSystemComponentErrorSystem;


/**
 Defines the ANT Common Data Error Description Object
 
 @since 2.2.0
 */
@interface NPECommonDataError : NSObject

- (instancetype _Nonnull) init NS_UNAVAILABLE;

/**
 Index of the Manufacturer Defined System Component
 
 @note If value == NPECommonDataErrorSystemComponentErrorSystem, the error is System based.
 @since 2.2.0
 */
@property (nonatomic, readonly) NSInteger systemComponentIndex;

/**
 Error Level
 
 @since 2.2.0
 */
@property (nonatomic, readonly) NPECommonDataErrorLevel errorLevel;

/**
 ANT+ Device Profile Specific Error Code
 
 @since 2.2.0
 */
@property (nonatomic, readonly, nullable) NSNumber *profileErrorCode;

/**
 Manufacturer Specific Error Code
 
 Integer value error Code defined by the Manufactuer.
 
 @since 2.2.0
 */
@property (nonatomic, readonly, nullable) NSNumber *manufacturerErrorCode;

@end
