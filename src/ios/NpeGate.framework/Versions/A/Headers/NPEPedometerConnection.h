//
//  NPEPedometerConnection.h
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
#import <NpeGate/NPESensorConnection.h>

NS_ASSUME_NONNULL_BEGIN
///---------------------------------------------------------------------------------------
/// Sensor Command Keys
///
/// Supports Common Commands:
///     NPESensorCmdKeySetTime
///     NPESensorCmdKeyRequestTime
///     NPESensorCmdKeyRequestManufacturerInfo
///     NPESensorCmdKeyRequestVersionInfo
///     NPESensorCmdKeyRequestBatteryStatus
///---------------------------------------------------------------------------------------

/** Sensor Command to Clear the Data from the Pedometer (Clear may take up to 5 seconds to report back that the data did clear) */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyClearData;
/** Sensor Command to Request the Pedometer Re-Reads the Data and prepares for Transfer (Takes no Parameters) */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyReReadPedometerData;
/** Sensor Command to Set the UID and the TagSPM of the Pedometer */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeySetUIDTagSPM;
/** Sensor Command to Request the Pedometer Transfers over the Data */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyRequestPedometerData;
/** Sensor Command to Request the Device Firmware Update Mode (DFU) (Takes no Parameters)*/
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyRequestPedometerDFU;
/** Sensor Command to Request Device to Stop Beaconing */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyStopBeaconing;


///---------------------------------------------------------------------------------------
/// Sensor Command Parameter Keys
///
/// Support Common Command Parameter Keys:
///
///---------------------------------------------------------------------------------------
/** Command Parameter for setting the Hour in NPESensorCmdKeySetTime */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeyHour;
/** Command Parameter for setting the Minute in NPESensorCmdKeySetTime */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeyMinute;
/** Command Parameter for setting the Second in NPESensorCmdKeySetTime */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeySecond;
/** Command Parameter for setting the SPM value in NPESensorCmdKeySetUIDTagSPM */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeyPedometerSPM;
/** Command Parameter for setting the Tag value in NPESensorCmdKeySetUIDTagSPM */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeyPedometerTag;
/** Command Parameter for setting the UserID (high byte) value in NPESensorCmdKeySetUIDTagSPM */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeyPedometerUserIDHigh;
/** Command Parameter for setting the UserID (middle byte) value in NPESensorCmdKeySetUIDTagSPM */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeyPedometerUserIDMiddle;
/** Command Parameter for setting the UserID (low byte) value in NPESensorCmdKeySetUIDTagSPM */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeyPedometerUserIDLow;


/**
 * Represents a connection to an ANT+ Pedometer sensor.
 */
@interface NPEPedometerConnection : NPESensorConnection

/**
 Indicates that the Pedometer is Busy performing an operation.
 
 @since 2.1.0
 */
@property (nonatomic, readonly) BOOL isBusy;

@end
NS_ASSUME_NONNULL_END
