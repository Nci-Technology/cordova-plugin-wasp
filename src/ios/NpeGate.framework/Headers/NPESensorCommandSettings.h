//
//  NPESensorCommandSettings.h
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
 Default Retries of 5
 */
FOUNDATION_EXPORT const int NPESensorCommandSettingsDefaultRetries;
/**
 Default Timeout Value (2.5 seconds)
 */
FOUNDATION_EXPORT const NSTimeInterval NPESensorCommandSettingsDefaultTimeout;

NS_ASSUME_NONNULL_BEGIN
/**
 Settings for Sensor Commands
 
 @since 2.1.0
 */
@interface NPESensorCommandSettings : NSObject

- (instancetype)init NS_UNAVAILABLE;

/**
 Creates an instance of NPESensorCommandSettings with the Default Values
 
 @since 2.1.0
 */
+ (instancetype)defaultSettings;

/**
 Creates an instance of NPESensorCommandSettings
 
 @param retries The Number of times to retry the command.
 @param timeout The time in seconds to wait for response.
 */
- (instancetype)initWithRetries:(NSInteger)retries andTimeout:(NSTimeInterval)timeout;

/**
 The number of times the WASP should attempt to send a message to a Sensor prior to calling it a failed message.
 
 @since 2.1.0
 */
@property (nonatomic, readonly) NSInteger retries;

/**
 The time in Seconds to wait for a successful response from the Sensor before we retry or fail the command.
 
 @since 2.1.0
 */
@property (nonatomic, readonly) NSTimeInterval timeout;

@end
NS_ASSUME_NONNULL_END
