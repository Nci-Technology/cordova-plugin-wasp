//
//  npe_hardware_connector_types.h
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

#ifndef __NPE_HARDWARE_CONNECTOR_TYPES_H__
#define __NPE_HARDWARE_CONNECTOR_TYPES_H__

///---------------------------------------------------------------------------------------
/// NPE Notifications
///---------------------------------------------------------------------------------------

/** Defines when a New Sensor Connection has been discovered on the network.  Sends back userInfo. */
FOUNDATION_EXPORT NSString * _Nonnull const NPE_NOTIFICATION_DISCOVERED_SENSOR __deprecated_msg("No Longer Supported as of 3.0.  use WaspStateChangeObserver");
FOUNDATION_EXPORT NSString * _Nonnull const NPE_NOTIFICATION_SENSOR_REMOVED __deprecated_msg("No Longer Supported as of 3.0.  use WaspStateChangeObserver");
/** Framework has connected to a Network */
FOUNDATION_EXPORT NSString * _Nonnull const NPE_NOTIFICATION_HW_CONNECTED;
/** The network the framework was connected to has changed, or disconnected  */
FOUNDATION_EXPORT NSString * _Nonnull const NPE_NOTIFICATION_HW_DISCONNECTED;
/** Defines when a New WASP has been discovered on the network.  Sends back userInfo <i>@{@"WASP": waspObj}</i> where waspObj is the Wasp Object. */
FOUNDATION_EXPORT NSString * _Nonnull const NPE_NOTIFICATION_DISCOVERED_WASP __deprecated_msg("No Longer Supported as of 3.0.  use WaspStateChangeObserver");
/** Defines when a WASP has updated information. May send back optional userinfo <i>@{@"RemoveWasp":removeIP}</i> where removeIP is the ip of the Wasp that was removed from the network */
FOUNDATION_EXPORT NSString * _Nonnull const NPE_NOTIFICATION_WASP_INFO __deprecated_msg("No Longer Supported as of 3.0");
FOUNDATION_EXPORT NSString * _Nonnull const NPE_NOTIFICATION_WASP_CONFIG_UPDATED;


/**
 Minimum RSSI Value
 */
FOUNDATION_EXPORT NSInteger const NPEMinimumRssiValue;

typedef NS_ENUM(NSInteger, WTMsgType) {
    WTMsgTypeUnknown    = 0,
    WTMsgType_12        = 1,
    WTMsgType_13        = 2,
    WTMsgType_15        = 3,
    WTMsgType_Flex      = 4,
    WTMsgType_14        = 5,
    WTMsgType_16        = 6,
};

/**
 Defines the NPE Sensor Type

 @since 2.1.0
 */
typedef NS_ENUM(NSUInteger, NPESensorType) {
    /** Specifies a non-existent Sensor */
    NPESensorTypeNone                       = 0,
    /** Specifies a Bike Power Sensor */
    NPESensorTypeBikePower                  = 0x00000001,
    /** Specifies the Generic Bike Speed sensor. */
    NPESensorTypeBikeSpeed                  = 0x00000002,
    /** Specifies the bike cadence sensor. */
    NPESensorTypeBikeCadence                = 0x00000004,
    /** Specifies the Generic combined Bike Speed and Cadence sensor. */
    NPESensorTypeBikeSpeedCadence           = 0x00000008,
    /** Specifies the Generic FootPod - Stride and Distance sensor. */
    NPESensorTypeFootpod                    = 0x00000010,

    /** Specifies the Generic Heart Rate monitor sensor. */
    NPESensorTypeHeartrate                  = 0x00000020,
    /** Specifies the Suunto Heart Rate monitor sensor. */
    NPESensorTypeHeartrateSuunto            = 0x00000021,
    /** Specifies the BLE Polar Heart Rate monitor sensor. */
    NPESensorTypeHeartratePolar             = 0x00000022,

    /** Specifies the ANT Saris HUB Trainer. */
    NPESensorTypeBikeSarisHub               = 0x00000030,
    /** Specifies the ANT Saris PowerBeam Trainer. */
    NPESensorTypeBikeSarisPowerBeam         = 0x00000031,

    /** Specifies the Generic Weight Scale monitor sensor */
    NPESensorTypeWeightScale                = 0x00000040,
    /** Specifies a Generic ANT FS device. */
    NPESensorTypeAntFs                      = 0x00000080,
    /** Specifics a ANT FS OTA Device */
    NPESensorTypeAntFsOta                   = 0x00000081,
    
    /** Specifies the Generic GPS location sensor. */
    NPESensorTypeLocation                   = 0x00000100,
    /** Specifies the Generic Calorimeter sensor. */
    NPESensorTypeCalorimeter                = 0x00000200,
    /** Specifies the Generic GeoCache sensor. */
    NPESensorTypeGeoCache                   = 0x00000400,

    /** Specifies the Fitness Equipment sensor. */
    NPESensorTypeFitnessEquipment           = 0x00000800,

    /** Specifies the Generic Multi-Sport Speed and Distance sensor. */
    NPESensorTypeMultisportSpeedDistance    = 0x00001000,

    /** Specifies the BLE Proximity sensor. */
    NPESensorTypeProximity                  = 0x00002000,
    /** Specifies the Apple iBeacon sensor. */
    NPESensorTypeiBeacon                    = 0x00002001,
    /** Specifies the Google Eddystone sensor. */
    NPESensorTypeEddystone                  = 0x00002002,
    /** Specifies the Tracker Sensor */
    NPESensorTypeTracker                    = 0x00002003,
    /** Specifies the AltBeacon */
    NPESensorTypeAltBeacon                  = 0x00002004,

    /** Specifies the BTLE Health Thermometer sensor. */
    NPESensorTypeHealthTherometer           = 0x00004000,
    /** Specifies the BTLE Blood Pressure sensor. */
    NPESensorTypeBloodPressure              = 0x00008000,
    /** Specifies the ANT+ Light Electric Vehicle (LEV) Sensor. */
    NPESensorTypeElectricVehicle            = 0x00010000,
    /** Specifies the ANT+ Blood Glucose Monitor sensor. */
    NPESensorTypeGlucose                    = 0x00020000,
    /** Specifies the Environmental Monitor sensor. */
    NPESensorTypeEnvironmental              = 0x00040000,

    /** Specifies the Bike Light Sensor . */
    NPESensorTypeBikeLights                 = 0x00080000,
    /** Specifies the Bike Shifting Sensor . */
    NPESensorTypeBikeShifting               = 0x00080001,
    /** Specifies the Bike Radar Sensor . */
    NPESensorTypeBikeRadar                  = 0x00080002,
    /** Specifies the Bike Dropper Seatpost Sensor . */
    NPESensorTypeBikeDropperSeatpost        = 0x00080003,
    /** Specifies the Bike Suspension Sensor . */
    NPESensorTypeBikeSuspension             = 0x00080004,

    /** Specifies the ANT+ Pressure Sensor Array. */
    NPESensorTypePressureSensorArray        = 0x00100000,

    /** Specified the Wahoo KICKR */
    NPESensorTypeKickr                      = 0x00200000,
    /** Specifies the NPE Accel test platform */
    NPESensorTypeAccel                      = 0x00400000,
    /** Specifies the GARMIN Fore Runner Watch Beacon */
    NPESensorTypeForeRunnerWatch            = 0x00800000,
    /** Specifies A Muscle Oxygen Sensor */
    NPESensorTypeMuscleOxygen               = 0x01000000,

    /** Specifies the Running Dynamics Sensor. */
    NPESensorTypeRunningDynamics            = 0x02000000,
    /** Specifies the HR-Running Dynamics Sensor. */
    NPESensorTypeHrRunningDynamics          = 0x02000001,

    /** Specifies the ANT+ Aerostick sensor. */
    NPESensorTypeAerostick                  = 0x04000000,

    /** Reserved for Future Use. */
    NPESensorTypeReservedSensor             = 0x08000000,

    /** Reserved for Future Use. */
    NPESensorTypeReservedSensorTwo          = 0x10000000,

    /** Reserved for Future Use. */
    NPESensorTypeReservedSensorThree        = 0x20000000,

    /** Specifies a Custom Sensor. */
    NPESensorTypeCustom                     = 0x40000000,
    /** Specifies the NPE Paring Pod. */
    NPESensorTypePairingPod                 = 0x40000001,
    /** Specifies the ANT-FS Up Stream Technologies Infiltrometer. */
    NPESensorTypeUpStreamInfiltrometer      = 0x40000002,
    /** Specifies the ANT+ Pedometer Sensor. */
    NPESensorTypePedometer                  = 0x40000004,
    /** Specifies the NPE CABLE Sensor. */
    NPESensorTypeCable                      = 0x40000005,
    /** Specifies the NPE Activity Monitor Sensor. */
    NPESensorTypeActivityMonitor            = 0x40000006,

    /** Specifies Generic BLE Sensors . */
    NPESensorTypeGenericBLESensor           = 0x80000000,
    /** Specifies Apple BLE Sensors */
    NPESensorTypeApple                      = 0x80000001,
    /** Specifies AppleTV BLE Sensors */
    NPESensorTypeAppleTv                    = 0x80000002,
    /** Specifies Dropcam */
    NPESensorTypeDropcam                    = 0x80000005,
    /** Specifies Nike BLE Sensors */
    NPESensorTypeNike                       = 0x80000006,

    /** Unknown Sensor Type **/
    NPESensorTypeUnknown                    = 0xFFFFFFFF,
};

/**
 * Describes the network the sensor device was discovered on.
 */
typedef NS_ENUM(NSInteger, NPESensorProtocolType) {
    /** The network type is not specified. */
    NPESensorProtocolTypeUnspecified        = 0,
    /** Default, ANT+ standard network */
    NPESensorProtocolTypeANTPlus            = 1,
    /** Defines, BLE Local - Machine */
    NPESensorProtocolTypeBLELocal           = 2,
    /** Defines, BLE WASP */
    NPESensorProtocolTypeBLEWASP            = 3,
};


#ifndef _NPE_CONNECTOR_ERROR_DOMAIN_
#define _NPE_CONNECTOR_ERROR_DOMAIN_
/** Error domain for the NPEGate. */
FOUNDATION_EXPORT NSString * _Nonnull const NpeGateErrorDomain;

/**
 NPE Error Codes
 */
typedef NS_ENUM(NSInteger, NpeGateError) {
    /** No error has occurred. */
    NpeGateErrorNone = 0,

    //---------------------------------
    // WASP Command Error Codes
    //---------------------------------
    /** The Command Sent to the WASP is not Valid for WASP */
    NpeGateErrorWaspCommandInvalid                      = 2000,
    /** The Command Sent to the WASP Requires a USB Connection */
    NpeGateErrorWaspCommandRequiresUsbConnection        = 2001,

    //---------------------------------
    // Sensor Command Error Codes
    //---------------------------------
    /** The Command Sent to the Sensor is not Valid for Sensor */
    NpeGateErrorSensorCommandInvalid                    = 3000,
    /** The Amount of Parameters for a Sensor Command does not Match */
    NpeGateErrorSensorCommandInvalidParamCount          = 3001,
    /** The Param for the Sensor Command is not valid for Command */
    NpeGateErrorSensorParamsInvalid                     = 3002,
    /** No Setting Value Found for Sensor Command */
    NpeGateErrorSensorSettingNotFoundForCommand         = 3003,
    /** Setting for Sensor Command is out of Bounds */
    NpeGateErrorSensorSettingValueOutOfBounds           = 3004,
    /** Sensor Connection is Invalid - NO command can be sent */
    NpeGateErrorSensorConnectionInvalid                 = 3005,
    /** Sensor Command Failed due to Unknown Reason */
    NpeGateErrorSensorCommandFailedUnknown              = 3010,
    /** Sensor Command Failed due to too many Retries */
    NpeGateErrorSensorCommandFailedRetries              = 3011,
    /** Sensor Command Failed - Hit Timeout waiting for response */
    NpeGateErrorSensorCommandFailedTimeout              = 3012,
    /** Sensor Command Failed - Transmit Transfer Failure */
    NpeGateErrorSensorCommandFailedTransmitTransfer     = 3013,
    /** Sensor Command Failed - Receive Transfer Failure */
    NpeGateErrorSensorCommandFailedReceiveTransfer      = 3014,
    /** Sensor Command Failed - Channel Collision Failure */
    NpeGateErrorSensorCommandFailedChannelCollision     = 3015,
    /** No WASP Available at this time for command */
    NpeGateErrorSensorCommandNoWaspAvailable            = 3016,

    //---------------------------------
    // ANT-FS Error Codes
    //---------------------------------
    /**  Error in the ANT-FS Session  */
    NpeGateErrorAntfsSessionError                   = 7000,
    /** ANT-FS Invalid Request */
    NpeGateErrorAntfsInvalidRequest                 = 7001,
    /** ANT-FS Download Data Does not Exist */
    NpeGateErrorAntfsDownloadDataDoesNotExist       = 7100,
    /** ANT-FS Download Data not Downloadable */
    NpeGateErrorAntfsDownloadDataNotDownloadable    = 7101,
    /** ANT-FS Download not Ready */
    NpeGateErrorAntfsDownloadNotReady               = 7102,
    /** ANT-FS Download Incorrect CRC */
    NpeGateErrorAntfsDownloadCRCIncorrect           = 7103,
    /** ANT-FS Invalid Upload File */
    NpeGateErrorAntFsUploadFileInvalid              = 7200,
    /** ANT-FS Upload Index not found */
    NpeGateErrorAntFsUploadIndexNotFound            = 7201,
    /** ANT-FS Upload Index not writeable */
    NpeGateErrorAntFsUploadIndexNotWriteable        = 7202,
    /** ANT-FS No Space for Upload */
    NpeGateErrorAntFsUploadNoSpaceAvailable         = 7203,
    /** ANT-FS Invalid Request for Upload */
    NpeGateErrorAntFsUploadRequestInvalid           = 7204,
    /** ANT-FS Upload Not Ready */
    NpeGateErrorAntFsUploadNotReady                 = 7205,
    /** ANT-FS Not Tracking during upload Request  */
    NpeGateErrorAntFsUploadRequestNotTracking       = 7206,


    //---------------------------------
    // WASP Firmware Update Error Codes
    //---------------------------------
    /**  The Wrong Bundle Type was given to the WASP for updating */
    NpeGateErrorWrongBundleTypeForWasp          = 8000,
    /** Could not connect to POE for Firmware Update */
    NpeGateErrorNoConnectionToPOE               = 8001,
    /** Firmware Read Socket Error */
    NpeGateErrorFirmwareReadSocketError         = 8002,
    /** Firmware Upgrade Not Available */
    NpeGateErrorFirmwareNotAvailable            = 8003,
    /** Firmware PoE Response Error */
    NpeGateErrorFirmwareResponseError           = 8004,
    /** Firmware Update Failure Error */
    NpeGateErrorFirmewareFailure                = 8005,
    /** Firmware Download Failed */
    NpeGateErrorFirmewareDownloadFail           = 8006,
    /** Firmware PoE Failed CRC Check */
    NpeGateErrorFirmewareCRCFailure             = 8007,
    /** Firmware Update Stopped by User */
    NpeGateErrorFirmewareUserStopped            = 8008,
    /** Firmware Update Wrong Version - Typically if trying to downgrade firmware */
    NpeGateErrorFirmewareWrongVersion           = 8009,

    
    //---------------------------------
    // WASP Radio Command Error Codes
    //---------------------------------
    /** The Radios Firmware is not compatible with Command */
    NpeGateErrorRadioFirmwareNotCompatible          = 9000,
    /** Radio Command timeout prior to sending back information */
    NpeGateErrorRadioCommandTimeout                 = 9001,
    /** Radio Command received an Invalid Message Error */
    NpeGateErrorRadioCommandInvalidMessage          = 9002,
    /** Invalid Radio Network Key Requested */
    NpeGateErrorRadioCommandInvalidNetworkKey       = 9003,
    /** UserDefined Radio Network Key not Set */
    NpeGateErrorRadioCommandUserDefinedKeyNotSet    = 9004,
    /** Radio Command received an Invalid Parameter Error */
    NpeGateErrorRadioCommandInvalidParameter        = 9005,
    /** Radio Command received an Invalid Channel State Error */
    NpeGateErrorRadioCommandWrongChannelState       = 9006,
    /** Radio Command received an Invalid Channel Radio Freq Error */
    NpeGateErrorRadioCommandInvalidChannelRadioFreq = 9007,
    /** Radio Command failed to receive valid Information */
    NpeGateErrorRadioCommandInvalidData             = 9008,
    
    
};
#endif  // _NPE_CONNECTOR_ERROR_DOMAIN_
#endif  // __NPE_HARDWARE_CONNECTOR_TYPES_H__
