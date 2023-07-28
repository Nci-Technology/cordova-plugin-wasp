//
//  NPEFirmwareBundle.h
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

@class Wasp;

/**
 Defines The Firmware Bundle Type

 @since 2.1.0
 */
typedef NS_ENUM(NSInteger, NPEFirmwareWaspType) {

    NPEFirmwareWaspTypeNone     = 0,
    /** Firmware for a WASP-N Type WASP */
    NPEFirmwareWaspTypeWaspN    = 1,
    /** Firmware for a WASP PoE Type WASP */
    NPEFirmwareWaspTypeWaspPoe  = 2
};


NS_ASSUME_NONNULL_BEGIN

///---------------------------------------------------------------------------------------
/// Notifications
///---------------------------------------------------------------------------------------
/** Sent out when WASP Firmware Bundles are Available for upgrading */
FOUNDATION_EXPORT NSString * const NPENotificationWaspFirmwareBundlesAvailable;

/**
 The NPEFirmwareBundle describes a WASP Firmware Bundle.
 
 @since 2.0
 */
@interface NPEFirmwareBundle : NSObject

/**
 Convienance Method to create a NPEFirmwareBundle from a single Firmware zip file.
 
 This method may be used if NPE provided you with a Firmware zip file.
 
 @param filePath The filepath for the Firmware zip file
 @returns A NPEFirmwareBundle
 @note Will return nil if it is not a vaild Firmware bundle
 @since 2.0
 */
+ (NPEFirmwareBundle * _Nullable)initWithZipFile:(NSString *)filePath;

///---------------------------------------------------------------------------------------
/// @name Firmware Information
///---------------------------------------------------------------------------------------

/**
 The Short name of the Firmware Bundle
 
 @since 2.0
 */
@property (nonatomic, readonly) NSString *name;

/**
 A Description of the Firmware for the WASP
 
 @since 2.0
 */
@property (nonatomic, readonly) NSString *firmwareDescription;

/**
 The Version of the Firmware for the WASP
 
 @since 2.0
 */
@property (nonatomic, readonly) NSString *version;


/**
 The type of WASP Firmware Bundle
 
 @since 2.1.0
 */
@property (nonatomic, readonly) NPEFirmwareWaspType bundleType;

/**
 This is a Beta Release of the Firmware
 
 @since 2.0.6
 */
@property (nonatomic, readonly) BOOL betaVersion;

///---------------------------------------------------------------------------------------
/// @name Firmware Bundles
///---------------------------------------------------------------------------------------

/**
 Provies an Array of NPEFirmwareBundle objects for a specific Wasp Object.
 
 This command will only return Bundles for the specific Wasp Objects
 
 @param wasp The Wasp Object
 @returns An array of NPEFiremwareBundle Objects
 @since 2.0
 */
+ (NSArray<NPEFirmwareBundle *> * _Nullable)firmwareBundlesForWasp:(Wasp *)wasp;

/**
 Provides the Current Firmware Version for the WASP
 
 @param wasp The Wasp Object to determine the current firmware for
 @returns String Value of the Current Firmware version.  Nil represents not available at the moment.
 @since 2.0.6
 */
+ (NSString * _Nullable)currentFirmwareForWasp:(Wasp *)wasp;

@end
NS_ASSUME_NONNULL_END
