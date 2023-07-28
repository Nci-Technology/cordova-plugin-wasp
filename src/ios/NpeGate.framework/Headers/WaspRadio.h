//
//  WaspRadio.h
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
#import <NpeGate/NPEAttributes.h>

@class WaspRadioCapabilities;
@class WaspRadioChannel;

FOUNDATION_EXPORT const NSTimeInterval WaspRadioTimeoutInterval;

/**
 WASP Radio FW Mode
 
 @since 2.0
 */
typedef NS_ENUM(NSInteger, RadioFirmwareMode) {
    /** Invalid */
    RadioFirmwareModeInvalid                = -1,
    /** Radio Not Populated Firmware Mode */
    RadioFirmwareModeNotPopulated           = 0,
    /** Radio's firmware is set to ANT/ANT+ Mode */
    RadioFirmwareModeANT                    = 1,
    /** Radio's firmware is set to BLE Passive Scan Only Mode */
    RadioFirmwareModeBLEPassiveScan         = 2,
    /** Radio's firmware is set to BLE with Passive and Active Scan Modes */
    RadioFirmwareModeBLEPassiveActiveScan   = 3,
    /** Radio's firmware is set to BLE with All Scan Modes & Connnections */
    RadioFirmwareModeBLEConnection          = 4,
    /** RAdio's Firmware is set to BLE Beacons (iBeacon/Eddystone) */
    RadioFirmwareModeBeacon                 = 5,

    /** Radio Firmware Mode is Unknown */
    RadioFirmwareModeUnknown                = 254,
    /** Radio Not Supported Firmware Mode */
    RadioFirmwareModeNotSupported           = 255
};

/**
 WASP Radio Mode
 
 @since 2.0.4
 */
typedef NS_ENUM(UInt8, RadioMode) {
    /** Radio Mode Off */
    RadioModeOff        = 0x00,
    /**
     Radio Mode: Standalone.
     
     Automatically configured to listen in continuous scan mode with key and channel specified in configuration. 
     */
    RadioModeStandAlone = 0x01,
    /** Radio Mode: Controlled. 
     
     Fully controlled via control socket 
     */
    RadioModeControlled = 0x02,
    /** 
     Radio Mode: Hybrid.  Full Controll over radios, but defaults to configuration per the WASP config 
     
     @since 2.1.0
     @note Requires PoE Firmware version 2.2.44 or WASP-N 5.4.25
     */
    RadioModeHybrid     = 0x03,
};

/**
 ANT Radio Network Keys

 @since 2.0.10
 */
typedef NS_ENUM(NSInteger, WaspRadioNetworkKey) {
    /** ANT Public Key */
    WaspRadioNetworkKeyPublicKey    = 0,
    /** ANT+ Network Key */
    WaspRadioNetworkKeyANTPlus      = 1,
    /** ANT-FS Network Key */
    WaspRadioNetworkKeyANTFS        = 2,
    /** Other Key */
    WaspRadioNetworkKeyOther        = 3
};

/**
 ANT Radio Setup Modes

 @since 2.0.10
 */
typedef NS_ENUM(NSInteger, WaspRadioSetupMode) {
    /** ANT+ default mode - Listen for all beacons in continuous scan mode*/
    WaspRadioSetupModeAntPlusScan           = 0,
    /** ANT+ Mode setup for Bursts.  This will setup the Radio to use the Radios control freq */
    WaspRadioSetupModeAntPlusBurst          = 1,
    /** ANT-FS mode that listens for all Beacons in continuous scan mode */
    WaspRadioSetupModeAntFsScan             = 2,
    /** ANT-FS mode that listens for all Beacons in Background scan mode */
    WaspRadioSetupModeAntFsBackgroundScan   = 3,
    /**
     NPE Pedometer Radio Mode
     @since 3.0.0
     */
    WaspRadioSetupModeNpePedometerMode      = 4,
    /**
     NPE Other Radio Mode
     @since 3.0.0
     */
    WaspRadioSetupModeNpeOtherMode          = 5,
  
};

/**
 Defines the WASP Radio Events
 
 @since 2.1.0
 */
typedef NS_ENUM(NSInteger, WaspRadioEvent) {
    /** Version Number Information */
    WaspRadioEventVersionNumber             = 0x3E,
    /** Channel Event Message */
    WaspRadioEventChannelEventMessage       = 0x40,
    /** Unassign Channel Event */
    WaspRadioEventUnassignChannel           = 0x41,
    /** Assign Channel Event */
    WaspRadioEventAssignChannel             = 0x42,
    /** Channel Perdiod */
    WaspRadioEventChannelPeriod             = 0x43,
    /** Search Timeout */
    WaspRadioEventSearchTimeout             = 0x44,
    /** Chanel Radio Frequency */
    WaspRadioEventChanelRadioFrequency      = 0x45,
    /** Network Key */
    WaspRadioEventNetworkKey                = 0x46,
    /** Transmit Power */
    WaspRadioEventTransmitPower             = 0x47,
    /** System Reset */
    WaspRadioEventSystemReset               = 0x4A,
    /** Open Channel */
    WaspRadioEventOpenChannel               = 0x4B,
    /** Close Channel */
    WaspRadioEventCloseChannel              = 0x4C,
    /** Request Message */
    WaspRadioEventRequestMessage            = 0x4D,
    /** Broadcast Data */
    WaspRadioEventBroadcastData             = 0x4E,
    /** Acknowledge Data */
    WaspRadioEventAcknowledgeData           = 0x4F,
    /** Burst Data */
    WaspRadioEventBurstData                 = 0x50,
    /** SetChannel Identifier */
    WaspRadioEventSetChannelIdentifer       = 0x51,
    /** Channel Status */
    WaspRadioEventChannelStatus             = 0x52,
    /** Radio Capabilities */
    WaspRadioEventCapabilities              = 0x54,
    /** Open RX Scan */
    WaspRadioEventOpenRxScan                = 0x5B,
    /** Extended Broadcast Data */
    WaspRadioEventExtendedBroadcastData     = 0x5D,
    /** Extended Acknowledged Data */
    WaspRadioEventExtendedAcknowledgedData  = 0x5E,
    /** Extended Burst Data */
    WaspRadioEventExtendedBurstData         = 0x5F,
    /** Serial Number Information */
    WaspRadioEventSerialNumber              = 0x61,
    /** Low Priority Search Timeout */
    WaspRadioEventLowPrioritySearchTimeout  = 0x63,
    /** Enable Extended RX Messages */
    WaspRadioEventExtendedRxMessages        = 0x66,
    /** ANT Lib Config */
    WaspRadioEventAntLibConfig              = 0x6E,
    /** Startup Message */
    WaspRadioEventStartupMessage            = 0x6F,
    /** Advanced Burst Capabilities */
    WaspRadioEventAdvancedBurstCapabilities = 0x78,
};

/**
 Defines the WASP Radio Response/Event Messages
 
 @since 2.1.0
 */
typedef NS_ENUM(NSInteger, WaspRadioResponse) {
    /** No Error */
    WaspRadioResponseNoError                = 0x00,
    /** Receive Channel Search Timeout */
    WaspRadioResponseRxSearchTimeout        = 0x01,
    /** Receive Channel Missed Message */
    WaspRadioResponseRxFail                 = 0x02,
    /** Broadcast Message Transmitted Sucessfully */
    WaspRadioResponseTxSuccess              = 0x03,
    /** Receive Transfer Failed */
    WaspRadioResponseTransferRxFailed       = 0x04,
    /** Transfer Transmit Completed */
    WaspRadioResponseTransferTxCompleted    = 0x05,
    /** Transfer Transmit Failed */
    WaspRadioResponseTransferTxFailed       = 0x06,
    /** Channel Closed */
    WaspRadioResponseChannelClosed          = 0x07,
    /** Channel Dropped to Search mode */
    WaspRadioResponseRxFailedGotoSearch     = 0x08,
    /** Channel Collision */
    WaspRadioResponseChannelCollision       = 0x09,
    /** Transfer Tx Start */
    WaspRadioResponseTransferTxStart        = 0x0A,
    /** Transfer Next Data Block */
    WaspRadioResponseTransferNextDataBlock  = 0x11,
    /** Channel In Wrong State */
    WaspRadioResponseChannelInWrongState    = 0x15,
    /** Channel Not Open */
    WaspRadioResponseChannelNotOpen         = 0x16,
    /** Channel ID not Set */
    WaspRadioResponseChannelIdNotSet        = 0x18,
    /** Close All Channels */
    WaspRadioResponseCloseAllChannels       = 0x19,
    /** Transfer In Progress */
    WaspRadioResponseTransferInProgress     = 0x1F,
    /** Transfer Sequenece Number Error */
    WaspRadioResponseTransferSeqNumberError = 0x20,
    /** Transfer In Error */
    WaspRadioResponseTransferInError        = 0x21,
    /** Message Size Exceeds limit */
    WaspRadioResponseMessageSizeLimit       = 0x27,
    /** Invalid Message */
    WaspRadioResponseInvalidMessage         = 0x28,
    /** Invalid Network Number */
    WaspRadioResponseInvalidNetworkNumber   = 0x29,
    /** Invalid List ID */
    WaspRadioResponseInvalidListId          = 0x30,
    /** Invalid Scan TX Channel */
    WaspRadioResponseInvalidScanTxChannel   = 0x31,
    /** Invalid Parameter Provided */
    WaspRadioResponseInvalidParamProvided   = 0x33,
};


NS_ASSUME_NONNULL_BEGIN
/**
 Defines the Radio Object for the WASP.
 
 Each WASP may have multiple Radio Objects.
 
 @since 2.0
 */
@interface WaspRadio : NSObject

/**
 The Radio Firmware Version
 
 @since 2.0
 */
@property (nonatomic, readonly) NSString *fimrwareVersion;

/**
 The Radio Serial Number
 
 @since 2.0
 */
@property (nonatomic, readonly) UInt32 serialNumber;

/**
 The Frequency for the Radio
 
 @since 2.0
 */
@property (nonatomic, readonly) NSInteger frequency;

/**
 The Frequency for the Radio in WASP Control Mode
 
 @since 2.0
 */
@property (nonatomic, readonly) NSInteger controlFrequency;


/**
 Defines the Radio Capabilities if Radio is ANT
 
 @since 2.1.0
 */
@property (nonatomic, readonly, nullable) WaspRadioCapabilities *radioCapabilities;

///---------------------------------------------------------------------------------------
/// @name Radio Channels
///---------------------------------------------------------------------------------------

/**
 Array of the Radio Channel Objects
 
 @since 2.0.6
 */
@property (nonatomic, readonly) NSArray<WaspRadioChannel *> *channels;


///---------------------------------------------------------------------------------------
/// @name Radio Commands
///---------------------------------------------------------------------------------------


/**
 Sends command to the Radio to Reset itself
 
 @since 2.0.5
 */
- (void)resetRadio;

/**
 Sets the User Defined Network Key.

 This sets the UserDefined Network key for use with updating the Radios Network Key

 @param userDefinedNetworkKey The 8 byte ANT Network Key
 @since 2.0.10
 */
- (void)setUserDefinedNetworkKey:(NSData *)userDefinedNetworkKey;

/**
 Updates the ANT Radio with default Settings for the Given Radio Setup Mode.

 It will then configure the Radio for the default settings for that NetworkKey.  
 The scan will be a wildcard scan.

 @param mode The Network Mode Radio
 @param success The success block
 @param failure The failure block
 @see setUserDefinedNetworkKey:
 @see WaspRadioNetworkKey
 @note This is a Runtime configuration.  It will not change the Default setup for the Radio.
 @since 2.0.10
 */
- (void)configureRadioWithMode:(WaspRadioSetupMode)mode onSuccess:(void (^ _Nullable)(WaspRadio * _Nonnull radio))success onFailure:(void (^ _Nullable)(WaspRadio * _Nonnull radio, NSError * _Nonnull error))failure;

///---------------------------------------------------------------------------------------
/// @name Firmware Mode
///---------------------------------------------------------------------------------------

/**
 The Firmware Mode for the Radio
 
 @since 2.0
 */
@property (nonatomic, readonly) RadioFirmwareMode firmwareMode;

/**
 Determines if the Radio is a BLE Radio Firmware type
 
 @since 2.0
 */
@property (nonatomic, readonly) BOOL isRadioFirmwareBLE;

/**
 Changes the Firmware Mode of the Radio on the next WASP Config update
 
 @param mode The RadioFirmwareMode to change the Radio to
 @since 2.0
 */
- (void)changeRadioFirmwareMode:(RadioFirmwareMode)mode;

/**
 Provides back the RadioFirmwareMode that has been requested
 
 @since 2.0.6
 */
@property (nonatomic, readonly) RadioFirmwareMode requestedModeChange;

/**
 Determines if the Radio has been requested to change the Firmware type
 
 @since 2.0.6
 */
@property (nonatomic, readonly) BOOL isRadioFirmwareChangeRequested;

/**
 Provides a String Value for the Radio Firmware Mode
 
 Values: 
 <table>
    <tr><th>Mode</th><th>Meaning</th></tr>
    <tr><td>Not Populated</td><td>No Radio in the slot</td></tr>
    <tr><td>ANT</td><td>ANT+ Radio</td></tr>
    <tr><td>BLE-P</td><td>BLE Radio in Passive Scan Only Mode</td></tr>
    <tr><td>BLE-A</td><td>BLE Radio in Active and Passive Scan Mode</td></tr>
    <tr><td>BLE-C</td><td>BLE Radio capable of making connections and both scan modes</td></tr>
    <tr><td>UNK</td><td>Unknown Radio Mode</td></tr>
 </table>
 
 @since 2.0
 */
@property (nonatomic, readonly) NSString *firmwareModeStringValue;

/**
 Provides a String Value for the Radio Firmware Mode
 
 @param mode The Radios Firmware Mode
 @returns String Value for the mode
 @see firmwareModeStringValue
 @since 2.0
 */
+ (NSString *)stringForFirmwareMode:(RadioFirmwareMode)mode;

///---------------------------------------------------------------------------------------
/// @name Radio Mode
///---------------------------------------------------------------------------------------

/**
 The Current Mode for the Radio
 
 @since 2.0
 */
@property (nonatomic, readonly) RadioMode radioMode;

/**
 Provides a String Value for the Radio Mode
 
 @since 2.0.4
 */
+ (NSString *)stringforRadioMode:(RadioMode)mode;

///---------------------------------------------------------------------------------------
/// @name Packet Information
///---------------------------------------------------------------------------------------

/**
 Total Packets Received on the Radio Interface
 
 @since 2.0
 */
@property (nonatomic, readonly) NSUInteger packetsReceived;

@end
NS_ASSUME_NONNULL_END
