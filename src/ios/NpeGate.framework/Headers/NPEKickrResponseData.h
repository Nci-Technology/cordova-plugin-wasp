//
//  NPEKickrResponseData.h
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
 Describes the Kickr Status Codes
 
 @since 2.1.0
 */
typedef NS_ENUM(NSInteger, KickrStatusCode) {
    /** Status Code of Success */
    KickrStatusCodeSuccess              = 0x00,
    /** Unspecified Error */
    KickrStatusCodeUnspecifiedError     = 0x01,
    /** Kickr in Wrong Mode */
    KickrStatusCodeWrongMode            = 0x02,
    /** Range Error */
    KickrStatusCodeRangeError           = 0x04,
    /** Wrong State */
    KickrStatusCodeWrongState           = 0x05,
    /** Invalid Param Sent to Kickr */
    KickrStatusCodeInvalidParam         = 0x06,
    /** ANT Config Error */
    KickrStatusCodeAntConfigError       = 0x07,
    /** Control Disabled */
    KickrStatusCodeControlDisabled      = 0x08,
    /** ANT Channel Error */
    KickrStatusCodeAntChannelError      = 0x09,
    /** Status Code of Success */
    KickrStatusCodeResponseSuccess      = 0x80
};

/**
 Describes the mode in which the trainer is currently running.
 
 @since 2.1.0
 */
typedef NS_ENUM(NSInteger, KickrMode) {
    /** Trainer mode not specified. */
    KickrModeNone       = 0,
    /** Standard Mode will mimic a typical fluid trainer's resistance curve. */
    KickrModeStandard,
    /** Erg mode will maintain a constant target power output regardless of speed. */
    KickrModeErg,
    /** Sim mode will simulate real world riding conditions. */
    KickrModeSim,
    /** Resistance mode will allow direct control of the trainer's resistance. */
    KickrModeResistance,
};


/**
 Describes the Kickr Command OpCodes
 
 @since 2.1.0
 */
typedef NS_ENUM(NSInteger, KickrCommand) {
    /** Read Temperature */
    KickrCommandReadTemperature         = 0x08,
    /** Set Resistance Mode */
    KickrCommandSetResistanceMode       = 0x40,
    /** Set Standard Mode */
    KickrCommandSetStandardMode         = 0x41,
    /** Set ERG Mode */
    KickrCommandSetErgMode              = 0x42,
    /** Set SIM Mode */
    KickrCommandSetSimMode              = 0x43,
    /** Set CRR */
    KickrCommandSetCrr                  = 0x44,
    /** Set C */
    KickrCommandSetC                    = 0x45,
    /** Set Grade */
    KickrCommandSetGrade                = 0x46,
    /** Set Wind Speed */
    KickrCommandSetWindSpeed            = 0x47,
    /** Set Wheel Circumference */
    KickrCommandSetWheelCircumference   = 0x48,
    /** Set INIT Spindown */
    KickrCommandSetInitSpindown         = 0x49,
    /** Read Mode */
    KickrCommandReadMode                = 0x4A,
    /** Set FTP Mode */
    KickrCommandSetFtpMode              = 0x4B,
    /** Connect ANT Sensor */
    KickrCommandSetAntSensor            = 0x4F,
    /** Test OP */
    KickrCommandTestOp                  = 0x50,
    /** Set Control Passcode */
    KickrCommandSetControlPasscode      = 0x51,
    /** Reset Control Passcode */
    KickrCommandResetControlPasscode    = 0x52,
    /** Kickr Enable Control */
    KickrCommandEnableControl           = 0x53,
    /** Set Feature Enable state */
    KickrCommandSetFeatureEnableState   = 0x54,
    /** Read Feature Enable State */
    KickrCommandReadFeatureEnableState  = 0x55,
    /** Spindown Result */
    KickrCommandSpindownResult          = 0x5A
};


/**
 The NPEKickrResponseData describes the Response from a Kickr after a command is sent to it.
 
 @since 2.1.0
 */
@interface NPEKickrResponseData : NSObject

- (instancetype)init NS_UNAVAILABLE;

/**
 Raw Data for the Response 
 
 @since 2.1.0
 */
@property (nonatomic, readonly) NSData *rawData;

/**
 Raw Response Code Value
 
 @since 2.1.0
 */
@property (nonatomic, readonly) uint8_t responseCode;

/**
 Status Code Provided by the Kickr
 
 @since 2.1.0
 */
@property (nonatomic, readonly) KickrStatusCode statusCode;

/**
 String Value for the Kickr Status Code
 
 @since 2.1.0
 */
- (NSString *)stringValueForStatusCode;

/**
 Command that Kickr is Responding To.
 
 @since 2.1.0
 */
@property (nonatomic, readonly) KickrCommand command;

/**
 Response Sequence Number
 
 @since 2.1.0
 */
@property (nonatomic, readonly) uint8_t sequence;

/**
 Response Data 0
 
 @since 2.1.0
 */
@property (nonatomic, readonly) uint8_t responseData0;

/**
 Response Data 1

 @since 2.1.0
 */
@property (nonatomic, readonly) uint8_t responseData1;

/**
 Response Data 2

 @since 2.1.0
 */
@property (nonatomic, readonly) uint8_t responseData2;

/**
 Response Data 3

 @since 2.1.0
 */
@property (nonatomic, readonly) uint8_t responseData3;

@end
