//
//  WaspRadioCapabilities.h
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

///---------------------------------------------------------------------------------------
/// ANT Capabilities
///---------------------------------------------------------------------------------------

/**
 Standard Options for Radio
 */
typedef NS_OPTIONS(uint8_t, ANTCapabilitiesStdOptions) {
    ANTCapabilitiesStdOptionsNoRXChannels      = 0x01,
    ANTCapabilitiesStdOptionsNoTXChannels      = 0x02,
    ANTCapabilitiesStdOptionsNoRXMessages      = 0x04,
    ANTCapabilitiesStdOptionsNoTXMessages      = 0x08,
    ANTCapabilitiesStdOptionsNoAckdMessages    = 0x10,
    ANTCapabilitiesStdOptionsNoBurstTransfer   = 0x20,

};

/**
 Advanced Options for Radio
 */
typedef NS_OPTIONS(uint8_t, ANTCapabilitiesAdvOptions) {
    ANTCapabilitiesAdvOptionsNetworkEnabled         = 0x02,
    ANTCapabilitiesAdvOptionsSerialNumberEnabled    = 0x08,
    ANTCapabilitiesAdvOptionsPerChannelTXEnabled    = 0x10,
    ANTCapabilitiesAdvOptionsLowPriSearchEnabled    = 0x20,
    ANTCapabilitiesAdvOptionsScriptEnabled          = 0x40,
    ANTCapabilitiesAdvOptionsSearchListEnabled      = 0x80,
};

/**
 Advanced Options 2 for Radio
 */
typedef NS_OPTIONS(uint8_t, ANTCapabilitiesAdvOptionsTwo) {
    ANTCapabilitiesAdvOptionsTwoLEDEnabled          = 0x01,
    ANTCapabilitiesAdvOptionsTwoExtMessageEnabled   = 0x02,
    ANTCapabilitiesAdvOptionsTwoScanModeEnabled     = 0x04,
    ANTCapabilitiesAdvOptionsTwoReserved            = 0x08,
    ANTCapabilitiesAdvOptionsTwoProxSearchEnabled   = 0x10,
    ANTCapabilitiesAdvOptionsTwoExtAssignEnabled    = 0x20,
    ANTCapabilitiesAdvOptionsTwoAntFsEnabled        = 0x40,
    ANTCapabilitiesAdvOptionsTwoFITOneEnabled       = 0x80,
};

/**
 Advanced Options 3 for Radio
 */
typedef NS_OPTIONS(uint8_t, ANTCapabilitiesAdvOptionsThree) {
    ANTCapabilitiesAdvOptionsThreeAdvBurstEnabled       = 0x01,
    ANTCapabilitiesAdvOptionsThreeEventBuffering        = 0x02,
    ANTCapabilitiesAdvOptionsThreeEventFiltering        = 0x04,
    ANTCapabilitiesAdvOptionsThreeHighDutySearch        = 0x08,
    ANTCapabilitiesAdvOptionsThreeSearchSharing         = 0x10,
    ANTCapabilitiesAdvOptionsThreeReserved              = 0x20,
    ANTCapabilitiesAdvOptionsThreeSelectiveDataUpdates  = 0x40,
    ANTCapabilitiesAdvOptionsThreeEncryptedChannels     = 0x80,
};

/**
 Advanced Options 4 for Radio
 */
typedef NS_OPTIONS(uint8_t, ANTCapabilitiesAdvOptionsFour) {
    ANTCapabilitiesAdvOptionsFourRFActiveNotifications  = 0x01,
};


/**
 Defines the WASP Radio Capabilities for ANT Radios
 
 @since 2.1.0
 */
@interface WaspRadioCapabilities : NSObject

/**
 Number of ANT Channels Available
 
 @since 2.1.0
 */
@property (nonatomic, readonly) NSInteger maxChannels;

/**
 Number of Networks Available
 
 @since 2.1.0
 */
@property (nonatomic, readonly) NSInteger maxNetworks;

/**
 Number of SensRcore Channels Available
 
 @since 2.1.0
 */
@property (nonatomic, readonly) NSInteger maxSensRcoreChannels;


///---------------------------------------------------------------------------------------
/// @name Options
///---------------------------------------------------------------------------------------

/**
 Standard Radio Options
 
 @since 2.1.0
 */
@property (nonatomic, readonly) ANTCapabilitiesStdOptions standardCapabilities;

/**
 Advanced Radio Options
 
 @Since 2.1.0
 */
@property (nonatomic, readonly) ANTCapabilitiesAdvOptions advancedCapabilities;

/**
 Advanced 2 Radio Options

 @Since 2.1.0
 */
@property (nonatomic, readonly) ANTCapabilitiesAdvOptionsTwo advancedTwoCapabilities;

/**
 Advanced 3 Radio Options

 @Since 2.1.0
 */
@property (nonatomic, readonly) ANTCapabilitiesAdvOptionsThree advancedThreeCapabilities;

/**
 Advanced 4 Radio Options

 @Since 2.1.0
 */
@property (nonatomic, readonly) ANTCapabilitiesAdvOptionsFour advancedFourCapabilities;


@end
