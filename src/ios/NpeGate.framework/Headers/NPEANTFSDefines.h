//
//  NPEANTFSDefines.h
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
 ANT-FS Device Types

 @since 3.0.7
 */
typedef NS_ENUM(UInt8, NPEAntFSDeviceType) {
    /** Defines The ANT-FS OTA Firmware Updates Device */
    NPEAntFSDeviceTypeOTAFirmware       = 0x10,
};

/**
 OTA Firmware File types

 @since 2.1
 */
typedef NS_OPTIONS(NSInteger, NPEAntFsFirmwareFileType) {
    /** Application Image */
    NPEAntFsFirmwareFileTypeApplication     = 1 << 0,
    /** Bootloader Image */
    NPEAntFsFirmwareFileTypeBootloader      = 1 << 1,
    /** Softdevice Image */
    NPEAntFsFirmwareFileTypeSoftdevice      = 1 << 2
};


/**
 Defines the ANT-FS Response Messages
 
 @since 2.0.6
*/
typedef NS_ENUM(NSInteger, NPEAntFsResponseMessage) {
    
    /** ANT-FS Response - No response. */
    NPEAntFsResponseMessageNone                         = 0,
    /** ANT-FS Response - The line was opened successfully. */
    NPEAntFsResponseMessageOpenPass                     = 1,
    /** ANT-FS Response - The line was initialized successfully. */
    NPEAntFsResponseMessageInitPass                     = 2,
    /** ANT-FS Response - Failed to initialize the serial line. */
    NPEAntFsResponseMessageSerialFail                   = 3,
    /** ANT-FS Response - The request for a session failed. */
    NPEAntFsResponseMessageRequestSessionFail           = 4,
    /** ANT-FS Response - Client beacon opened. */
    NPEAntFsResponseMessageBeaconOpen                   = 5,
    /** ANT-FS Response - Client beacon closed. */
    NPEAntFsResponseMessageBeaconClosed                 = 6,
    /** ANT-FS Response - Connection succeeded. */
    NPEAntFsResponseMessageConnectPass                  = 7,
    /** ANT-FS Response - Disconnect succeeded. */
    NPEAntFsResponseMessageDisconnectPass               = 8,
    /** ANT-FS Response - Broadcast disconnect succeeded. */
    NPEAntFsResponseMessageDisconnectBroadcastPass      = 9,
    /** ANT-FS Response - The connection was lost. */
    NPEAntFsResponseMessageConnectionLost               = 10,
    /** ANT-FS Response - Authentication is not available. */
    NPEAntFsResponseMessageAuthenticateNotAvailable     = 11,
    /** ANT-FS Response - Authentication passed. */
    NPEAntFsResponseMessageAuthenticatePass             = 12,
    /** ANT-FS Response - The authentication was rejected by the client. */
    NPEAntFsResponseMessageAuthenticateReject           = 13,
    /** ANT-FS Response - Authentication failed. */
    NPEAntFsResponseMessageAuthenticateFail             = 14,
    /** ANT-FS Response - Request for pairing. */
    NPEAntFsResponseMessagePairingRequest               = 15,
    /** ANT-FS Response - Pairing request timed out. */
    NPEAntFsResponseMessagePairingTimeout               = 16,
    /** ANT-FS Response - Request for download. */
    NPEAntFsResponseMessageDownloadRequest              = 17,
    /** ANT-FS Response - The download request passed. */
    NPEAntFsResponseMessageDownloadPass                 = 18,
    /** ANT-FS Response - The download request was rejected by the client. */
    NPEAntFsResponseMessageDownloadReject               = 19,
    /** ANT-FS Response - Invalid file index. */
    NPEAntFsResponseMessageDownloadInvalidIndex         = 20,
    /** ANT-FS Response - Requested file cannot be read. */
    NPEAntFsResponseMessageDownloadFileNotReadable      = 21,
    /** ANT-FS Response - Download not ready. */
    NPEAntFsResponseMessageDownloadNotReady             = 22,
    /** ANT-FS Response - The download failed. */
    NPEAntFsResponseMessageDownloadFail                 = 23,
    /** ANT-FS Response - Upload request. */
    NPEAntFsResponseMessageUploadRequest                = 24,
    /** ANT-FS Response - The upload request passed. */
    NPEAntFsResponseMessageUploadPass                   = 25,
    /** ANT-FS Response - The upload request was rejected. */
    NPEAntFsResponseMessageUploadReject                 = 26,
    /** ANT-FS Response - Invalid file index. */
    NPEAntFsResponseMessageUploadInvalidIndex           = 27,
    /** ANT-FS Response - Requested upload cannot be written. */
    NPEAntFsResponseMessageUploadFileNotWriteable       = 28,
    /** ANT-FS Response - Insufficient space to write the requested upload. */
    NPEAntFsResponseMessageUploadInsufficientSpace      = 29,
    /** ANT-FS Response - The upload failed. */
    NPEAntFsResponseMessageUploadFail                   = 30,
    /** ANT-FS Response - Request to erase a file. */
    NPEAntFsResponseMessageEraseRequest                 = 31,
    /** ANT-FS Response - The erase request passed. */
    NPEAntFsResponseMessageErasePass                    = 32,
    /** ANT-FS Response - The erase request was rejected. */
    NPEAntFsResponseMessageEraseReject                  = 33,
    /** ANT-FS Response - The erase request failed. */
    NPEAntFsResponseMessageEraseFail                    = 34,
    /** ANT-FS Response - The manual transfer request passed. */
    NPEAntFsResponseMessageManualTransferPass           = 35,
    /** ANT-FS Response - Manual request transmit failed. */
    NPEAntFsResponseMessageManualTransferTransmitFail   = 36,
    /** ANT-FS Response - Manual request response failed. */
    NPEAntFsResponseMessageManualTransferResponseFail   = 37,
    /** ANT-FS Response - The request to cancel has been processed. */
    NPEAntFsResponseMessageCancelDone                   = 38
};

/**
 Defines the ANT-FS Device State
 
 @since 2.0.6
 */
typedef NS_ENUM(NSInteger, NPEAntFsState) {
    /** ANT-FS Device State - The device is idle. */
    NPEAntFsStateIdle               = 0,
    /** ANT-FS Device State - Polling USB for available device. */
    NPEAntFsStateIdlePollingUSB     = 1,
    /** ANT-FS Device State - The line is open. */
    NPEAntFsStateOpen               = 2,
    /** ANT-FS Device State - The device is disconnecting. */
    NPEAntFsStateDisconnecting      = 3,
    /** ANT-FS Device State - The device is searching for a peer device. */
    NPEAntFsStateSearching          = 4,
    /** ANT-FS Device State - The device is connected to a peer device. */
    NPEAntFsStateConnected          = 5,
    /** ANT-FS Device State -  Authentication state. */
    NPEAntFsStateAuthenticating     = 5,
    /** ANT-FS Device State - Transport state. */
    NPEAntFsStateTransport          = 6,
    /** ANT-FS Device State - Downloading state. */
    NPEAntFsStateDownloading        = 7,
    /** ANT-FS Device State - Uploading state. */
    NPEAntFsStateUploading          = 8,
    /** ANT-FS Device State - Erase state. */
    NPEAntFsStateErasing            = 9,
    /** ANT-FS Device State - The ANT-FS device is sending data. */
    NPEAntFsStateSending            = 10,
    /** ANT-FS Device State - The ANT-FS device is receiving data. */
    NPEAntFsStateReceiving          = 11
};


