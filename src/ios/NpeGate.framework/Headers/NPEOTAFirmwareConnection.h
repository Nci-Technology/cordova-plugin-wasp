//
//  NPEOTAFirmwareConnection.h
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
#import <NpeGate/NPEAntfsProtocol.h>
#import <NpeGate/NPESensorConnection.h>
#import <NpeGate/NPEANT.h>

/**
 OTA Firmware File types

 @since 3.0.7
 */
typedef NS_OPTIONS(NSInteger, NPEDeviceFirmwareFileType) {
    /** Application Image */
    NPEDeviceFirmwareFileTypeApplication    = 1 << 0,
    /** Bootloader Image */
    NPEDeviceFirmwareFileTypeBootloader     = 1 << 1,
    /** Softdevice Image */
    NPEDeviceFirmwareFileTypeeSoftdevice    = 1 << 2
};

/**
 OTA File Index

 @since 3.0.7
 */
typedef NS_ENUM(UInt16, NPEAntFSOTAFileIndex) {
    /** File Index for Application File */
    NPEAntFSOTAFileIndexApp         = 0xFB01,
    /** File Index for Bootloader File */
    NPEAntFSOTAFileIndexBootLoader  = 0xFB02,
    /** File Index for Softdevice File */
    NPEAntFSOTAFileIndexSoftDevice  = 0xFB03,
    /** File Index for combined Bootloader Softdevie File */
    NPEAntFSOTAFileIndexBootSoft    = 0xFB06,
};

@protocol NPEOTAFirmwareDataSource;

/**
 NPEOTAFirmwareConnection is a Connection that can perform OTA Updates

 @since 3.0.7
 */
@interface NPEOTAFirmwareConnection : NPESensorConnection <NPEAntfsProtocol>

///---------------------------------------------------------------------------------------
/// @name ANT-FS Packet Information
///---------------------------------------------------------------------------------------

/**
 ANT-FS Packet
 */
@property (nonatomic, readonly) NPEPacketAntFS *antFSPacket;

/**
 ANT-FS Beacon

 @since 3.0.7
 */
@property (nonatomic, readonly) NPEAntFsBeacon *beacon;

/**
 Firmware OTA Data source delegate

 @since 3.0.7
 */
@property (nonatomic, weak) id<NPEOTAFirmwareDataSource> otaDataSource;

@end

@protocol NPEOTAFirmwareDataSource <NSObject>

/**
 Indicates which files the Application has available for Uploading to the ANT-FS Client

 @since 3.0.7
 */
- (NPEDeviceFirmwareFileType)filesAvailableForUpload;

/**
 If application indicates it has <i>filesAvailableForUpload</i> it will request each file individually

 @since 3.0.7
 */
- (NPESUFFile *)sufForFirmwareType:(NPEDeviceFirmwareFileType)filetype forConnection:(NPEOTAFirmwareConnection *)connection;

@end
