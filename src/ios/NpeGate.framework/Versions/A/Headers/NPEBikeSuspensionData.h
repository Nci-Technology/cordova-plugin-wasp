//
//  NPEBikeSuspensionData.h
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

#import <NpeGate/NpeGate.h>


@class NPEBikeSuspensionDeviceData;

///---------------------------------------------------------------------------------------
/// Sensor Data Parameter Keys
///
/// Supports Common Data Parameter Keys:
///     NPESensorDataParameterKeyRawData
///     NPESensorDataParameterKeyMinOperatingTemperature
///     NPESensorDataParameterKeyMaxOperatingTemperature
///     NPESensorDataParameterKeyChargingCycles
///
/// See also: NPECommonData
///---------------------------------------------------------------------------------------

/** Defines the Sensor Data Parameter Key for Suspension Device Type */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeySuspensionDeviceType;
/** Defines the Sensor Data Parameter Key for Damping Factor */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyDampingFactor;
/** Defines the Sensor Data Parameter Key for Auto-Unlock Enabled */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyAutoUnlockEnabled;
/** Defines the Sensor Data Parameter Key for Time in Manual Mode */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyTimeInManualMode;
/** Defines the Sensor Data Parameter Key for Accumulated Auto Actions */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyAccumAutoActions;
/** Defines the Sensor Data Parameter Key for Time in Auto Mode */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyTimeInAutoMode;
/** Defines the Sensor Data Parameter Key for Accumulated Free Falls */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyAccumFreeFalls;
/** Defines the Sensor Data Parameter Key for Longest Detected Free Fall */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyLongestFreeFallTime;


/**
 Represents Data for a Bike Suspension Sensor
 
 @since 2.2
 */
@interface NPEBikeSuspensionData : NPESensorData

/**
 Suspension Data for The Fork
 
 @since 2.2
 */
@property (nonatomic, readonly, nullable) NPEBikeSuspensionDeviceData *forkData;

/**
 Suspension Data for The Rear Shock

 @since 2.2
 */
@property (nonatomic, readonly, nullable) NPEBikeSuspensionDeviceData *rearShockData;

/**
 Suspension Data for The Combined Fork & Rear Shock

 @since 2.2
 */
@property (nonatomic, readonly, nullable) NPEBikeSuspensionDeviceData *forkRearShockData;

@end
