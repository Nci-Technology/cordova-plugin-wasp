//
//  Wasp.h
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
#if TARGET_OS_IPHONE
#import <UIKit/UIKit.h>
#elif TARGET_OS_MAC
#import <AppKit/AppKit.h>
#endif
#import <NpeGate/WaspRadio.h>
#import <NpeGate/NPEBLEDefines.h>
#import <NpeGate/NPESensorImage.h>

@class NPEFlexMsg;
@class NPECmdQueueMsg;
@class NPESensorConnection;
@class NPEFirmwareBundle;
@class AccessPoint;
@class Wasp;
@class WaspBattery;
@class WaspNetQuality;


NS_ASSUME_NONNULL_BEGIN

/**
 Provides Status for Firmware Updates
 
 @since 2.0.6
 */
typedef NS_ENUM(NSInteger, WaspFirmwareUpdateStatus) {
    /** Update Status Started */
    WaspFirmwareUpdateStatusStarted     = 0,
    /** Update Status Finished */
    WaspFirmwareUpdateStatusFinished    = 1,
    /** Update Status Downloading */
    WaspFirmwareUpdateStatusDownloading = 2,
    /** Update Status In Progress */
    WaspFirmwareUpdateStatusInProgress  = 3,
    /** Update Status Failed */
    WaspFirmwareUpdateStatusFailed      = 4,
    /** Update Status Stopped */
    WaspFirmwareUpdateStatusStopped     = 5
};

///---------------------------------------------------------------------------------------
/// Block Typedefs
///---------------------------------------------------------------------------------------

/**
 WASP Wifi Scan Block
 
 'NSArray *accessPoints, BOOL *stop'
 
 @since 2.0
 */
typedef void (^WaspScanWifiBlock)(NSArray<AccessPoint *> *accessPoints, BOOL *stop);

/**
 WASP Firmware Updater Block
 
 'NSError * _Nullable error, NSInteger bytesSent, NSInteger totalBytes, WaspFirmwareUpdateStatus status, BOOL stop'
 
 @since 2.0
 */
typedef void (^WaspFirmwareUpdateBlock)(NSError * _Nullable error, NSInteger bytesSent, NSInteger totalBytes, WaspFirmwareUpdateStatus status, BOOL *stop);

/**
 WASP Notification Block
 @since 2.0
 */
typedef void (^WaspIdentificationBlock)(Wasp *wasp);

/**
 WASP Connection Status Observation
 
 @since 2.1.0
 */
typedef void (^WaspConnectionStatusObserverBlock)(Wasp *wasp, NSString *connectionStatus);

/**
Radio Event Oservation
 
 @since 2.1
 */
typedef void (^NPEWaspRadioEventObserver)(Wasp *wasp, WaspRadio *radio, WaspRadioEvent event, NSData * _Nullable eventData);

/**
 Block for Disable Encryption

 @since 3.0.8
 */
typedef void (^WaspDisableEncryptionBlock)(Wasp *wasp, BOOL success, NSError * _Nullable error);

///---------------------------------------------------------------------------------------
/// BLE Scan Time
///---------------------------------------------------------------------------------------
/** Maximum Number of Seconds allowed for a BLE Active Scan */
FOUNDATION_EXPORT const NSInteger BLE_MAX_ACTIVE_SCAN_SEC;


///---------------------------------------------------------------------------------------
/// WASP Notification
///---------------------------------------------------------------------------------------
FOUNDATION_EXPORT NSString * const NPE_NOTIFICATION_WASP_GAINED_CONTROL;
FOUNDATION_EXPORT NSString * const NPE_NOTIFICATION_WASP_RELEASE_CONTROL;

///---------------------------------------------------------------------------------------
/// WASP Keys
///---------------------------------------------------------------------------------------
FOUNDATION_EXPORT NSString * const NPEWaspKeyIPAddress;
FOUNDATION_EXPORT NSString * const NPEWaspKeyData;

/**
 WASP Connection Information Mask
 
 Provides information on Connections to the WASP
 
 @since 2.0.6
 */
typedef NS_OPTIONS(UInt8, WaspConnectionInfo) {
    /**
     TCP Connection to the WASP is in use.
     */
    WaspConnectionInfoTcpInUse              = 0x01,
    /**
     User Generated Button Press on WASP
     */
    WaspConnectionInfoUserGeneratedButton   = 0x02,
    /**
     WASP-N is in Basestation Mode
     */
    WaspConnectionInfoBasestationEnabled    = 0x04,
};


/**
 WASP Operation Mode Configuration Mask
 
 Determins specific modes of operation for the WASP
 
 @since 2.0.4
 */
typedef NS_OPTIONS(UInt8, WaspOperationModeMask) {
    /**
     Selects if WASP should be a DHCP Client 
     
     @note Enabled by Default
     */
    WaspOperationModeMaskDHCPEnabled              = 0x01,
    /**
     Selects between either AdHoc or Simple AP mode when creating the provisioning network.
     
     0 = AdHoc 1 = Limited AP
     */
    WaspOperationModeMaskProvisioningStartUp      = 0x02,
    /**
     When packet saver mode is enabled, multiple encapsulated messages are included in one UDP datagram.
     
     @note Enabled by Default
     */
    WaspOperationModeMaskPacketSaverEnabled       = 0x04,
    /**
     Enables the RSSI
     
     @note Enabled by Default
     */
    WaspOperationModeMaskRSSIEnabled              = 0x08,
    /**
     Enable ANT debug stream and create TCP listen socket that clients may connect to.
     */
    WaspOperationModeMaskAntDebugStream           = 0x10,
    /**
     The archive ignore mode allows the WASP to ignore the archive bit when building the directory download list. Normally a file is ignored if the archive bit is set. With this mode enabled, the file is included in the download set.
     */
    WaspOperationModeMaskAntFSArchiveIgnore       = 0x20,
    /**
     Infrastucture Enabled
    
     @note Enabled by Default
     */
    WaspOperationModeMaskInfrastructureEnabld     = 0x40,
    /**
     ANT-FS Protocol 
     */
    WaspOperationModeMaskAntFsEnabled             = 0x80
};

#pragma pack(1)
typedef struct
{
    uint8_t     SECURE;
    uint8_t     SSID_LEN;
    uint8_t     SSID_NAME[31];
    uint8_t     SECURE_LEN;
    uint8_t     SECURE_KEY[63];
    uint8_t     PROX_LEVEL;
    uint8_t     AH_SEC_LEN;
    uint8_t     AH_SEC_KEY[26];
    uint8_t     AH_SEC_TYPE;
    uint32_t    STATIC_IP;
    uint32_t    STATIC_SUB;
    uint32_t    STATIC_GATE;
    uint8_t     ADHOC_CHAN;
    WaspOperationModeMask OP_MASK;
    uint8_t     WASP_NAME_LEN;
    uint8_t     WASP_NAME[32];
    uint8_t     NETWORK_KEY;
    uint8_t     OP_MODE;                    //Reserved
    uint32_t    ROUTE0_IP;
    uint16_t    ROUTE0_PORT;
    uint32_t    ROUTE1_IP;
    uint16_t    ROUTE1_PORT;
    uint8_t     OTHER_NETWORK_KEY[8];       // User Network Key
    uint8_t     ANT_CHAN;
    uint32_t    ANTFS_DEST_IP;
    uint16_t    ANTFS_DEST_PORT;
    uint8_t     ANTFS_APP_DISCONNECT;
    int8_t      ANTFS_RSSI_THRESHOLD;
    uint8_t     ANT_CHANS[3];
    uint8_t     RES4[11];
    uint32_t    PKT_WH_LIST[8];
    uint32_t    PKT_BL_LIST[8];
    uint16_t    ANTFS_WH_LIST[8];
    uint16_t    ANTFS_BL_LIST[8];
    uint8_t     ANTFS_DELAY_TIME;
    uint8_t     ANTFS_PERMISSION_KEY[16];
    uint32_t    ROUTE2_IP;
    uint16_t    ROUTE2_PORT;
    uint32_t    ROUTE3_IP;
    uint16_t    ROUTE3_PORT;
    uint8_t     RADIO_0_FW_TYPE;            //added 2.0
    uint8_t     RADIO_1_FW_TYPE;            //added 2.0
    uint8_t     RADIO_2_FW_TYPE;            //added 2.0
    uint8_t     RADIO_3_FW_TYPE;            //added 2.0
    uint8_t     SNMP_RO_COMM_STR_LEN;       //Added PoE 2.6.0
    uint8_t     SNMP_RO_COMM_STRING[32];    //Added PoE 2.6.0
}configStruct_t;
#pragma pack()


/**
 WiFi Security Modes
 */
typedef NS_ENUM(NSInteger, SecurityMode) {
    SecurityModeInvalid         = -1,
    SecurityModeNone            = 0,
    None                        __deprecated_enum_msg("use SecurityModeNone 3.0") = SecurityModeNone,
    SecurityModeWPA             = 1,
    WPA                         __deprecated_enum_msg("use SecurityModeWPA 3.0") = SecurityModeWPA,
    SecurityModeWPA2            = 2,
    WPA2                        __deprecated_enum_msg("use SecurityModeWPA2 3.0") = SecurityModeWPA2,
    SecurityModeWEPShared       = 3,
    WEP_Shared                  __deprecated_enum_msg("use SecurityModeWepShared 3.0") = SecurityModeWEPShared,
    SecurityModeWEPOpen         = 4,
    WEP_Open                    __deprecated_enum_msg("use SecurityModeWEPOpen 3.0") = SecurityModeWEPOpen,
    SecurityModeWPAEnterprise   = 5,
    WPA_Enterprise              __deprecated_enum_msg("use SecurityModeWPAEnterprise 3.0") = SecurityModeWPAEnterprise,
    SecurityModeWPA2Enterprise  = 6,
    WPA2_Enterprise             __deprecated_enum_msg("use SecurityModeWPA2Enterprise 3.0") = SecurityModeWPA2Enterprise
};

/**
 The type of WASP Hardware
 */
typedef NS_ENUM(NSInteger, ProductType_t) {
    /** WASP-B Hardware */
    WiFi_1011                   = 0,
    /** WASP Power over Ethernet Hardware - C7 */
    PoE_STM32F107_C7            = 1,
    /** WASP-N Dual Radio (b/g/n) - N548 */
    WiFi_2011                   = 2,
    /** Garmin WASP-N Hardware */
    WiFi_2011_Garmin            = 3,
    /** WASP Power over Ethernet Hardware - N548 */
    PoE_STM32F107_N548          = 4,
    /** WASP-N Dual Radio (b/g/n) - N550 */
    WiFi_2011_N550              = 5,
    /** WASP Power over Ethernet Hardware - N550 */
    PoE_STM32F107_N550          = 6,
    /** WASP-N Single Radio (b/g/n) - N550 */
    WiFi_2011_N550_N1           = 7,
    /** WASP Power over Ethernet Hardware - STM407-N550 */
    PoE_STM32F407_N550          = 8,
    
    /** Specialized WASP Simulator software */
    WASPSimulator               = 253,
    /** Keiser Multibike Receiver */
    KeiserMultiBikeReceiver     = 254,
    /** RESERVED */
    RESERVEDWasp                = 255
} __deprecated_msg("use WaspProductType 3.0");

typedef NS_ENUM(NSInteger, WaspProductType) {
    /** WASP-B Hardware */
    WaspProductTypeWaspB                    = 0,
    /** WASP Power over Ethernet Hardware - C7 */
    WaspProductTypeWaspPoE_STM32F107_C7     = 1,
    /** WASP-N Dual Radio (b/g/n) - N548 */
    WaspProductTypeWaspN                    = 2,
    /** Garmin WASP-N Hardware */
    WaspProductTypeGarmin                   = 3,
    /** WASP Power over Ethernet Hardware - N548 */
    WaspProductTypeWaspPoE_STM32F107_N548   = 4,
    /** WASP-N Dual Radio (b/g/n) - N550 */
    WaspProductTypeWaspN_N550               = 5,
    /** WASP Power over Ethernet Hardware - N550 */
    WaspProductTypeWaspPoE_STM32F107_N550   = 6,
    /** WASP-N Single Radio (b/g/n) - N550 */
    WaspProductTypeWaspN_N550_N1            = 7,
    /** WASP Power over Ethernet Hardware - STM407-N550 */
    WaspProductTypeWaspPoE_STM32F407_N550   = 8,
    /** BLAST3 */
    WaspProductTypeBlastThree               = 9,

    /** NPE CABLE */
    WaspProductTypeCable                    = 32,
    /** KABLE */
    WaspProductTypeKable                    = 33,
    // 34 - 63 Reserved
    /** NPE ANT Watch Enabler */
    WaspProductTypeAwe                      = 64,
    WaspProductTypeAweOt                    = 65,
    WaspProductTypeAweLt                    = 66,
    WaspProductTypeAweFitMetrix             = 67,
    WaspProductTypeAweReserved              = 73,
    //68 to 73 Reserved for AWE

    /** Headless Console - Rower */
    WaspProductTypeHeadlessConsoleRower     = 74,
    /** Team Fight */
    WaspProductTypeTeamFight                = 75,
    /** BLAST Sensor Simulator */
    WaspProductTypeBlastSensorSimulator     = 76,

    /** Specialized WASP Simulator software */
    WaspProductTypeWASPSimulator            = 253,
    /** Keiser Multibike Receiver */
    WaspProductTypeKeiserMultiBikeReceiver  = 254,
    /** RESERVED */
    WaspProductTypeRESERVED                 = 255
};

@protocol WaspConnectionDelegate;

/**
 The Wasp object represents the NPE WASP gateway device.
 */
@interface Wasp : NSObject

@property (nonatomic, strong) NSString              *host;

@property (nonatomic, strong) NSString              *primarySSID;
@property (nonatomic, strong) NSString              *primaryPassPhrase;
@property (nonatomic, strong) NSString              *primaryWepKey;
@property (nonatomic, assign) SecurityMode          primarySecurity;

/**
 Wifi AdHoc SSID
 
 This will follow the Format of WASP-MAC.

 @note As of Firmware 5.3.8 this can be changed for OEM Versions of the WASP
 */
@property (nonatomic, readonly) NSString            *adhocSSID;

@property (nonatomic, strong) NSString              *adhocWepKey;
@property (nonatomic, assign) SecurityMode          adhocSecurity;
@property (nonatomic, assign) NSInteger             adhocChannel;
@property (nonatomic, assign) unsigned int          iStaticIP;
@property (nonatomic, assign) unsigned int          iStaticSubNet;
@property (nonatomic, assign) unsigned int          iStaticGateway;
@property (nonatomic, strong) NSDictionary          *whiteBlackList;

@property (nonatomic, strong) NSString              *staticIP;
@property (nonatomic, strong) NSString              *subnetMask;
@property (nonatomic, strong) NSString              *gatewayIP;
@property (nonatomic, strong) NSString              *otherNetworkKey;

@property (nonatomic, copy) NSMutableArray<NSString *> *routeIP;
@property (nonatomic, copy) NSMutableArray<NSString *> *routePort;

@property (nonatomic, strong) NSString              *antfsIp;
@property (nonatomic, strong) NSString              *antfsPort;
@property (nonatomic, assign) uint8_t               antfsDelayTime;
@property (nonatomic, assign) uint8_t               antfsAppDisconnect;
@property (nonatomic, assign) int8_t                antfsRssiThreshold;

@property (nonatomic, assign) WaspOperationModeMask ctrlReg;
@property (nonatomic, assign) BOOL                  pktTimeEnabled;

@property (nonatomic, assign) BOOL                  waitingForConnect;

@property (nonatomic, assign) NSInteger             operatingMode;
@property (nonatomic, assign) NSInteger             proximityLevel;

@property (nonatomic, readonly) configStruct_t      configData;

@property (nonatomic, strong) NSMutableArray        *antNetworkKeyArr;
@property (nonatomic, strong) NSMutableArray        *antChanArr;


- (void)dhcpEnable:(BOOL)enable;
- (void)packetSaverEnable:(BOOL)enable;
- (void)antFsEnable:(BOOL)enable;
- (void)antFsAchiveIgnore:(BOOL)enable;
- (void)rssiEnable:(BOOL)enable;
- (void)antDebugEnable:(BOOL)enable;

/*
 Creates a Virtual Wasp Instance 
 
 @param ipAddr The IpAddress to use for the WASP
 @since 2.0
 @returns A Wasp Instance
 */
- (instancetype)createVirtualWaspWithIp:(NSString *)ipAddr;

/**
 WASP Connection Delegate
 
 @since 2.0
 */
@property (nonatomic, weak, nullable) id <WaspConnectionDelegate> delegate;

///---------------------------------------------------------------------------------------
/// @name WASP Vendor Information
///---------------------------------------------------------------------------------------

/**
 The WASP Vendors name.
 
 @since 2.0
 */
@property (nonatomic, readonly) NSString *vendorName;

/**
 The WASP Vendors Long name.
 
 @since 2.0
 */
@property (nonatomic, readonly) NSString *vendorLongName;

/**
 The name the Vendor uses to describe the WASP Hardware
 
 @since 2.0
 */
@property (nonatomic, readonly) NSString *vendorHardwareName;

/**
 A Logo Image for the WASP Hardware
 
 @since 2.0.6
 */
@property (nonatomic, readonly) GKImage *vendorHardwareImage;

/**
 The Label Image for the WASP Hardware

 @since 2.0.10
 */
@property (nonatomic, readonly) GKImage *vendorHardwareLabelImage;


///---------------------------------------------------------------------------------------
/// @name WASP Control
///---------------------------------------------------------------------------------------

/**
 If this WASP object is in control of the client hardware connection for control purpose
 
 @since 2.0
 */
@property (nonatomic, readonly) BOOL controlSocketOpened;

/**
 If the WASP hardware has a client connected to it for control purpose
 
 @since 2.0
 */
@property (nonatomic, readonly) BOOL clientConnected;

/**
 If the WASP is being controlled by the active application.
 */
@property (nonatomic, assign) BOOL controlled;

/**
 Returns a String value of the status of the WASP connection
 
 The Available Strings are: "Not Available", "Connected", "Requesting", "Busy", "Available"

 */
@property (nonatomic, readonly, copy) NSString *ConnectionStatus;

/**
 Provides Information on the Connection Status Information of the WASP
 
 @since 2.0.6
 */
@property (nonatomic, readonly) WaspConnectionInfo connectionInfo;

/**
 Provides Information on the IP Address that is Connected to the WASP.
 
 Value of 0.0.0.0 indicates that no one is connected (Also if WASP firmware doesn't support feature)
 Value of 255.255.255.255 indicates that it is being controlled via USB
 
 @since 2.0.10
 @note Requires WASP-N Firmware version 5.3.8 / WASP PoE Firmware version 2.3.5
 */
@property (nonatomic, readonly) NSString *connectedIpAddress;

/**
 Opens the Control Session to the WASP
 
 This allows you to send Configuration Messages to the WASP
 
 @since 2.0.10
 */
- (void)openControlSession;

/**
 Closes the Control Session from the WASP
 
 Ends Control session with the WASP 
 
 @since 2.0.10
 */
- (void)endControlSession;

/**
 Power Cycle the WASP
 
 @note This works on PoE Firmware 2.2.47, WASP-N 5.5.2 and Higher
 @since 2.1.0
 */
- (void)powerCycleWasp;

/**
 Request a Control Connection.
 
 This will open a control session to the WASP and set the Data to route back to the requesting device.

 @return TRUE if connection established.
 @since 2.0
 */
- (BOOL)requestDataConnection;

/**
 Turns off Encryption during the Control Session

 @param completion Block to run after completion
 @note Only available to macOS
 @since 3.0.8
 */
- (void)disableEncryptionWithCompletion:(WaspDisableEncryptionBlock)completion API_AVAILABLE(macosx(10.9));


///---------------------------------------------------------------------------------------
/// @name Hardware Information
///---------------------------------------------------------------------------------------

/**
 The name of the WASP
 */
@property (nonatomic, strong) NSString *name;

/**
 The type of WASP
 */
@property (nonatomic, readonly) ProductType_t productType __deprecated_msg("Use hardwareType (3.0)");

/**
 The type of WASP Hardware
 */
@property (nonatomic, readonly) WaspProductType hardwareType;

/**
 The MAC Address of the WASP as a String value.
 */
@property (nonatomic, readonly) NSString *macAddress;

/**
 The IP Address of the WASP when connected over TCP/IP.
 
 @note If the connection is over USB (macOS) this will be the USB SerialNumber.
 */
@property (nonatomic, strong) NSString *ipAddress;


/**
 Cumulative Operating Time of the WASP in miliSeconds
 
 @since 2.0.10
 @note Only Available on WASP-N 5.3.8+
 */
@property (nonatomic, readonly) NSTimeInterval cumulativeOperatingTime;


///---------------------------------------------------------------------------------------
/// @name Firmware Information
///---------------------------------------------------------------------------------------

/**
 String Value of the WASP Firmware Version
 
 @since 2.0
 */
@property (nonatomic, readonly) NSString *firmwareVersion;

/**
 Updates the WASP with the firmware bundle
 
 @params bundle The NPEFirmwareBundle object to use to upgrade the WASP
 @params handler The Completion Block.  Error will indicate any issues with the Upload, nil will serve as no issues.
 @since 2.0
 */
- (void)updateFirmwareWithBundle:(NPEFirmwareBundle *)bundle completionHandler:(WaspFirmwareUpdateBlock)handler;

///---------------------------------------------------------------------------------------
/// @name Power Information
///---------------------------------------------------------------------------------------

/**
 Determines if the WASP is plugged into power
 */
@property (nonatomic, readonly) BOOL powered __deprecated_msg("Use battery object 2.2");

/**
 Determinss if the WASP is currently charging
 */
@property (nonatomic, readonly) BOOL charging __deprecated_msg("Use battery object 2.2");

/**
 The Voltage of the battery for the WASP.
 */
@property (nonatomic, readonly) float batteryVoltage __deprecated_msg("Use battery object 2.2");

/**
 Provides a battery level from 0 to 1.
 */
@property (nonatomic, readonly) float fuelGauge __deprecated_msg("Use battery object 2.2");

/**
 Provides WASP Battery Information
 
 @since 2.2
 */
@property (nonatomic, readonly) WaspBattery *battery;


///---------------------------------------------------------------------------------------
/// @name Packet Information
///---------------------------------------------------------------------------------------

/**
 Provides a Total Received Sensor Packets Count for ANT/ANT+ Packets
 */
@property (nonatomic, readonly) NSUInteger totalANTPacketsReceived;

/**
 Provides a Total Received Sensor Packets Count for BLE Packets
 
 @since 2.0
 */
@property (nonatomic, readonly) NSUInteger totalBLEPacketsReceived;

/**
 Provides a Total Received Sensor Packets Count across ANT and BLE
 
 @since 2.0
 */
@property (nonatomic, readonly) NSUInteger totalPacketsReceived;

/**
 Provides a Total Received Bytes across ANT and BLE
 
 @since 2.0
 */
@property (nonatomic, readonly) NSUInteger totalBytesReceived;

/**
 Count of Total Received UDP Packets
 
 @since 2.0
 */
@property (nonatomic, readonly) NSUInteger receivedUDPPackets;

/**
 Percentage of Total Missed UDP Packets
 
 @since 2.0
 */
@property (nonatomic, readonly) float percentUDPPacketsMissed;

/**
 Timestamp of the First Receivd UDP Packet
 
 @since 2.0
 */
@property (nonatomic, readonly, null_resettable) NSDate *firstPacketTime;


/**
 Packets Per Second Received From the WASP
 
 @since 2.0
 */
@property (nonatomic, readonly) float packetsPerSecond;

///---------------------------------------------------------------------------------------
/// @name Network Quality
///---------------------------------------------------------------------------------------

/**
 Provides Network Quality Information.
 
 Provides information on the Round Trip Time from device to WASP during a Control Connection.
 This will provide information of network quality and understand how long it is taking to send
 and receive commands from the WASP to your application.
 
 @note nil if no Connection to WASP is valid.
 @since 2.1.0
 */
@property (nonatomic, readonly, nullable) WaspNetQuality *networkQuality;

///---------------------------------------------------------------------------------------
/// @name WIFI Information
///---------------------------------------------------------------------------------------

/**
 Provides the SecurityMode for the given String Value of the Security Mode
 
 @param mode The String value for the Security Mode
 @returns SecurityMode enum
 @since 2.0
 */
- (SecurityMode)securityModeForStringValue:(NSString *)mode __deprecated_msg("no longer supported (3.0)");

- (void)infrastructureAtStartup:(BOOL)enable;

- (void)limitedApEnable:(BOOL)enable;


///---------------------------------------------------------------------------------------
/// @name Commands
///---------------------------------------------------------------------------------------

/*
 Sets the IP Routes in the WASP.  Will assign the IP and Port to the next available empty slot.  IF all slots are already filled with an ip address it will take the next available slot based on the least recent entry and overwrite it.
 
 @param ip The IP Address to assign
 @param port The port number to assign
 @since 2.0
 */
- (void)sendSetRouteMsgIp:(NSString *)ip port:(NSString *)port;

/**
 Sends a reqest to get the WASP Configuration
 
 @param inRam If set <b>TRUE</b> will get config in RAM, otherwise in FLASH
 */
- (void)requestConfig:(BOOL)inRam;

- (void)sessionConfig:(Byte)cmd Data:(NSData * _Nullable)data;

/**
 Reset the WASP to OEM Defaults
 
 @note this will wipe out any config you have made and restore to DEFAULT setup
 */
- (void)resetToOemDefaults;

/**
 Commands the WASP to start to scan for WIFI Access Points that it can be attached to.
 
 This sends back a sorted Array of Access Points as they are discovered on the Network.  If you are looking for a particular network you can stop the scan after you have seen it come back by setting the stop in the block.
 
 @params completion The Block to run on completion of the Scans.
 @since 2.0
 */
- (void)scanForWifiNetworks:(WaspScanWifiBlock _Nullable)completion;

/**
 Updates the WASP config to the current value of the WASP object.
 
 @param withReset Tells the WASP To reset itself after configuration.
 @since 2.0
 */
- (void)updateWaspConfig:(BOOL)withReset;

/**
 Updates the WASP config using the config struct sent to the WASP object.
 
 @param configStruct The modified config struct used to feed the update.
 @param withReset Tells the WASP To reset itself after configuration.
 @since 2.0.6
 */
- (void)updateWaspConfigUsingStruct:(configStruct_t)configStruct withReset:(BOOL)withReset;


///---------------------------------------------------------------------------------------
/// @name BLE Commands
///---------------------------------------------------------------------------------------

/**
 Issues the BLE ScanMode to all BLE Radios for a Specific amount of time
 
 ScanMode <i>BLEScanModeActive</i> will only work for Radios that have Mode: <i>RadioFirmwareModeBLEPassiveActiveScan</i> or <i>RadioFirmwareModeBLEConnection</i>
 
 @param mode The BLEScan mode to use
 @param seconds The length of time to use.  <i>Setting to 0 will use the Defaults (forever in Passive and 30 seconds in Active)</i>
 @note Max Seconds for Active Scan is <b>BLE_MAX_ACTIVE_SCAN_SEC</b>
 @since 2.0
 */
- (void)sendBLEScanMode:(BLEScanMode)mode forSeconds:(NSInteger)seconds;

/**
 Issues the BLE ScanMode to the Radio for a Specific amount of time
 
 ScanMode <i>BLEScanModeActive</i> will only work for Radios that have Mode: <i>RadioFirmwareModeBLEPassiveActiveScan</i> or <i>RadioFirmwareModeBLEConnection</i>
 
 @param mode The BLEScan mode to use
 @param seconds The length of time to use.  <i>Setting to 0 will use the Defaults (forever in Passive and 30 seconds in Active)</i>
 @param radio  A Nil terminated list of the WaspRadio to send the BLE Scan to.
 @note Max Seconds for Active Scan is <b>BLE_MAX_ACTIVE_SCAN_SEC</b>
 @since 2.0
 */
- (void)sendBLEScanMode:(BLEScanMode)mode forSeconds:(NSInteger)seconds onRadio:(WaspRadio *)radio, ... NS_REQUIRES_NIL_TERMINATION;


///---------------------------------------------------------------------------------------
/// @name Radio Information
///---------------------------------------------------------------------------------------

/**
 An Array of WaspRadio Objects
 
 @since 2.0
 */
@property (nonatomic, readonly) NSArray<WaspRadio *> *radios;

/**
 Provides the RadioFirmwareMode for the Radio at the specific index
 
 @param index The index of a WaspRadio in the radios array
 @returns The Firmware Mode for the specified WaspRadio
 @see WaspRadio
 @since 2.0
 */
- (RadioFirmwareMode)getRadioFirmwareMode:(NSInteger)index;

///---------------------------------------------------------------------------------------
/// @name Sensor Messaging
///---------------------------------------------------------------------------------------

/**
 A Running count of Sensor Commands sent through this WASP
 */
@property (nonatomic, readonly) NSInteger cmdReqTotal;

/**
 A running count of Sucessful Sensor Commands sent through this WASP
 */
@property (nonatomic, readonly) NSInteger cmdSuccessTotal;

/**
 A running count of Sensor Commands that have failed
 */
@property (nonatomic, readonly) NSInteger cmdFailTotal;

/**
 A Running count of Sensor Commands that have been retried
 
 @since 2.0.5
 */
@property (nonatomic, readonly) NSInteger cmdRetryTotal;

///---------------------------------------------------------------------------------------
/// @name Sensors
///---------------------------------------------------------------------------------------

/**
 Array of the NPESensorConnections that the WASP is currently seeing.
 
 @since 2.1.0
 */
@property (nonatomic, readonly, nullable) NSArray<NPESensorConnection *> *sensors;

///---------------------------------------------------------------------------------------
/// @name SNMP
///---------------------------------------------------------------------------------------

/**
 The SNMP Read-Only Community String
 
 @since 3.0
 */
@property (nonatomic, strong, nullable) NSString *snmpReadOnlyCommunityString;

///---------------------------------------------------------------------------------------
/// @name Observers
///---------------------------------------------------------------------------------------

/**
 Adds a weakified observer to the WASP Identification Notification.
 
 With the WASP-N running at least version 5.0.6 a notifiction ping goes out when the button is pressed.  This can be used to identifiy a specific WASP device on the network.  You might use this to pair your application to traffic from a specific WASP.
 
 @param observer The Observer object which is listening for the Notification
 @param block The block to execute upon receiving the notification.
 @since 2.0
 @note Only works with WASP-N running 5.0.6 firmware or greater.
 */
- (void)addWaspIdentificationObserver:(id)observer withBlock:(WaspIdentificationBlock _Nullable)block;

/**
 Removes the observer which is watching for the WASP Identification Notification
 
 @param observer The Oberserver Object to remove from notifications
 @since 2.0
 */
- (void)removeWaspIdentificationObserver:(id)observer;

/**
 Adds a weakified observer to the WASP Connection Status Changes.
 
 @param observer The Observer object which is listening for Connection Status Changes
 @param block The block to perform upon receiving notification
 @since 2.1.0
 */
- (void)addWaspConnectionStatusObserver:(id)observer withBlock:(WaspConnectionStatusObserverBlock _Nullable)block;

/**
 Removes the Connection Status Obsever
 
 @param observer The observer to remove from Connection Status Events
 @since 2.1.0
 */
- (void)removeWaspConnectionStatusObserver:(id)observer;

///---------------------------------------------------------------------------------------
/// @name Radio Event Observation
///---------------------------------------------------------------------------------------

/**
 A weakified Wasp Radio Event Observer

 Provides a method for listening to events from the WASP Radios

 @param observer The observer who is observing for radio events
 @param event The specific event to listen for
 @param callback The block to perform on receipt of event
 @since 2.1.0
 */
- (void)addWaspRadioEventObserver:(id)observer forEvent:(WaspRadioEvent)event handler:(NPEWaspRadioEventObserver _Nullable)callback;

/**
 Removes the Observer for WASP Radio Events
 
 @param observer The Observer Object to remove from notifications
 @since 2.1.0
 */
- (void)removeWaspRadioEventObserver:(id)observer forEvent:(WaspRadioEvent)event;

///---------------------------------------------------------------------------------------
/// @name Debug
///---------------------------------------------------------------------------------------

/**
 Debug Stream Messages

 */
@property (nonatomic, readonly) NSArray<NSString *> *debugBuffer;

/**
 Clears the Debug Buffer
 */
- (void)clearDebug;

/**
 Opens the Debug Stream
 */
- (void)openDebugStream;

/**
 Close the Debug Stream
 */
- (void)closeDebugStream;

@end


/**
 Delegate Methods for The WASP Connection
 */
@protocol WaspConnectionDelegate <NSObject>

@optional
/**
 This is sent when a WASP has succesfully created a control session.
 
 @param wasp The WASP Object
 @param config The current Configuration structure of the wasp
 @since 2.0
 */
- (void)didStartCommandControlForWasp:(Wasp *)wasp withConfig:(configStruct_t *)config;

/**
 This is sent when you disconnect from the Command Control Socket to the WASP.
 
 An error will be sent back if there was one provided from the TCP socket
 
 @param wasp The WASP Object
 @param error Error Message if one is provided otherwise nil
 @since 2.0.5
 */
- (void)didEndCommandControlForWasp:(Wasp *)wasp withError:(NSError * _Nullable)error;

/**
 If another process has requested control of the WASP a countdown is started and will auto release once it hits zero.  You can give up control right away by returning <b>TRUE</b>
 
 @param wasp The WASP Object that is going to lose control
 @param seconds The time in seconds until a autorelease
 @return <b>TRUE</b> If you wish to give up control right away
 @since 2.0
 */
- (BOOL)shouldReleaseCommandControlForWasp:(Wasp *)wasp willAutoReleaseIn:(int)seconds;

/**
 This is sent back when you succesfully reject another incoming connection to the WASP, upon sending back a <i>TRUE</i> to the shouldReleaseCommandControlForWasp:willAutoReleaseIn
 
 @since 2.0.5
 */
- (void)didRejectIncomingConnectionRequestFromWasp:(Wasp *)wasp;

/**
 Called when a button press is detected to generate a WASP to notify itself on the Network.
 
 This can be used if you are looking for a specific WASP to perform actions on.
 
 @param wasp The Wasp Instance that is sending out the Notification
 @since 2.0
 @note This will fire up to 10 times on a Button Press
 */
- (void)didReceiveUserGeneratedQuery:(Wasp *)wasp;

/**
 This is sent when a WASP times out the connect request.
 
 @param wasp The WASP Object
 @since 2.0.6
 */
- (void)didTimeoutCommandControlRequestForWasp:(Wasp *)wasp;


@end
NS_ASSUME_NONNULL_END
