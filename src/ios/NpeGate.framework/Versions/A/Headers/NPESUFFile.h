//
//  NPESUFFile.h
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
#import <NpeGate/NPEANTFSDefines.h>

/**
 OTA SUF File Format

 @since 3.0
 */
@interface NPESUFFile : NSObject

- (instancetype __nonnull)init NS_UNAVAILABLE;

/**
 Creates the SUF File from a given Path

 @param filePath The Filepath to the .SUF file
 @returns An instance of NPESUFFile or Nil if not found or Not Valid
 */
+ (NPESUFFile * __nullable)sufFromFilePath:(NSString * __nonnull)filePath;

/**
 Create the SUF File from given Intel Binary Data.

 @param fileData Binary Data
 @return an instance of NPESUFFile or Nil if data is not valid
 */
+ (NPESUFFile * __nullable)sufFromData:(NSData * __nonnull)fileData;

/**
 SUF File Structure Version
 */
@property (nonatomic, readonly, nonnull) NSString *version;

/**
 SUF Data
 */
@property (nonatomic, readonly, nonnull) NSData *fileData;

/**
 CRC Value for the SUF Data
 */
@property (nonatomic, readonly) UInt16 crc;

/// TODO: KAH is this needed anymore?
//@property (nonatomic, readonly) UInt32 maxSize;

/**
 Image Types included in the SUF File
 */
@property (nonatomic, readonly) NPEAntFsFirmwareFileType imageTypes;

/**
 Size of the Softdevice
 */
@property (nonatomic, readonly) UInt32 softDeviceSize;

/**
 Size of the Bootloader
 */
@property (nonatomic, readonly) UInt32 bootLoaderSize;

/**
 Size of the Application
 */
@property (nonatomic, readonly) UInt32 applicationSize;

@end
