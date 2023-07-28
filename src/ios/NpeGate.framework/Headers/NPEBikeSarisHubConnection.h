//
//  NPEBikeSarisHubConnection.h
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
//  Joe Tretter
//  221 North First St. Ste. 310
//  Minneapolis, Minnesota 55401
//
//  Information contained in this software has been created or obtained by North Pole Engineering,
//  Inc. from sources believed to be reliable.  However, North Pole Engineering, Inc. does not
//  guarantee the accuracy or completeness of the information published herein nor shall
//  North Pole Engineering, Inc. be liable for any errors, omissions, or damages arising
//  from the use of this software.
//

#import <NpeGate/NpeGate.h>

///---------------------------------------------------------------------------------------
/// Sensor Command Keys
///
/// Support Common Commands:
///     NPESensorCmdKeyRequestManufacturerInfo
///     NPESensorCmdKeyRequestVersionInfo
///     NPESensorCmdKeyRequestBatteryStatus
///
///---------------------------------------------------------------------------------------

/** Command Key to perform a ConfigurationRequest to a Saris Hub */
FOUNDATION_EXPORT NPESensorCmdKey _Nonnull const NPESensorCmdKeyConfigurationRequest;


///---------------------------------------------------------------------------------------
/// Sensor Command Parameter Keys
///
/// Supports Common Parameter Keys:
///
///---------------------------------------------------------------------------------------

FOUNDATION_EXPORT NPESensorCommandParameterKey _Nonnull const NPESensorCommandParameterKeyOff;
FOUNDATION_EXPORT NPESensorCommandParameterKey _Nonnull const NPESensorCommandParameterKeyOn;
FOUNDATION_EXPORT NPESensorCommandParameterKey _Nonnull const NPESensorCommandParameterKeyFreeHub;
FOUNDATION_EXPORT NPESensorCommandParameterKey _Nonnull const NPESensorCommandParameterKeyFixedGear;


/**
 Saris Hub Calibration ID
 
 @since 3.0.7
 */
typedef NS_ENUM(NSInteger, NPESarisHubCalibrationId) {
    /** Manual Zero  */
    NPESarisHubCalibrationIdManualZero                      = 0xAA,
    /** Auto Zero Configuration Request */
    NPESarisHubCalibrationIdAutoZeroConfigurationRequest    = 0xAB,
    /**  Auto Zero Mode Set */
    NPESarisHubCalibrationIdAutoZeroModeSet                 = 0xE0
};

/**
 Saris Hub AutoZero Off/On
 
 @since 3.0.7
 */
typedef NS_ENUM(NSInteger, NPESarisHubAutoZero) {
    /** Auto Zero Off */
    NPESarisHubAutoZeroOff     = 0x00,
    /** Gender Female */
    NPESarisHubAutoZeroOn      = 0x01,
};

/**
 Saris Hub AutoZero Mode
 
 @since 3.0.7
 */
typedef NS_ENUM(NSInteger, NPESarisHubAutoZeroMode) {
    /** Auto Zero Free Hub */
    NPESarisHubAutoZeroModeFreeHub     = 0x02,
    /** Fixed Gear */
    NPESarisHubAutoZeroModeFixedGear   = 0x04,
};

/**
 Represents a Bike Saris Hub Sensor
 
 @since 3.0.7
 */
@interface NPEBikeSarisHubConnection : NPESensorConnection

@end
