//
//  NPEkickrConnection.h
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
#import <NpeGate/NPEBikePowerConnection.h>

@class NPEkickrConnection;
@class NPEBikePowerData;
@class NPEKickrResponseData;


NS_ASSUME_NONNULL_BEGIN
///---------------------------------------------------------------------------------------
/// Sensor Command Keys
///
/// Supports Common Commands:
///     NPESensorCmdKeyRequestManufacturerInfo
///     NPESensorCmdKeyRequestVersionInfo
///
///---------------------------------------------------------------------------------------
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeySetResistanceMode;
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeySetStandardMode;
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeySetERGMode;
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeySetFTPMode;
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeySetSIMMode;
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeySetCRR;
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeySetC;
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeySetGrade;
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeySetWindSpeed;
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeySetWheelCircum;
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyInitSpindown;
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyReadMode;
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyReadFeatures;
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyReadTemperature;
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyConsumeANTCadence;
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyRegulatePowerFromANT;
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyErgModeSpeedSimulation;
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeySimulateSpeedFromDownhill;


///---------------------------------------------------------------------------------------
/// Sensor Command Parameter Keys
///
/// Support Common Command Parameter Keys:
///     NPESensorCommandParameterKeyGrade
///     NPESensorCommandParameterKeyResistance
///     NPESensorCommandParameterKeySpeed
///     NPESensorCommandParameterKeyWheelCircumference
///
///---------------------------------------------------------------------------------------
/** Command Parameter for setting Level in NPESensorCmdKeySetStandardMode */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeyLevel;
/** Command Parameter for setting Power in NPESensorCmdKeySetERGMode */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeyPower;
/** Command Parameter for setting Simulated Speed in NPESensorCmdKeySetERGMode & NPESensorCmdKeyErgModeSpeedSimulation */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeySimulatedSpeed;
/** Command Parameter for setting FTP setting in NPESensorCmdKeySetFTPMode */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeyFTP;
/** Command Parameter for setting Percent setting in NPESensorCmdKeySetFTPMode */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeyPercent;
/** Command Parameter for setting Weight setting in NPESensorCmdKeySetSIMMode */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeyWeight;
/** Command Parameter for setting Wind Resistance Crr */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeyWindResistanceCrr;
/** Command Parameter for setting Rolling Resistance fC */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeyRollingResistancefC;
/** Command Parameter for setting Consume ANT for NPESensorCmdKeyConsumeANTCadence */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeyConsumeANT;
/** Command Parameter for setting Power From ANT for NPESensorCmdKeyRegulatePowerFromANT */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeyPowerFromANT;
/** Command Parameter for setting Downhill Simulation */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeySimulateDownhill;


/**
 Typedef for Radio Event Observation

 @since 2.1
 */
typedef void (^NPEKickrOpCodeObserver)(NPEkickrConnection *connection, NPEBikePowerData *data, NPEKickrResponseData *responseData);

/**
 * Represents a connection to a Wahoo Kicker Bike Power sensor.
 */
@interface NPEkickrConnection : NPEBikePowerConnection

///---------------------------------------------------------------------------------------
/// @name Kicker OPCode Observers
///---------------------------------------------------------------------------------------

/**
 A weakified Kickr OpCode Event Observer

 Provides a method for listening to the Kickr OPCodes

 @param observer The observer who is observing for kickr opcode events
 @param callback The block to perform on receipt of event
 @since 2.1.0
 */
- (void)addKickrOpCodeEventObserver:(id)observer handler:(NPEKickrOpCodeObserver _Nullable)callback;

/**
 Removes the Observer for Kickr OpCode Events

 @param observer The Observer Object to remove from notifications
 @since 2.1.0
 */
- (void)removeKickrOpCodeObserver:(id)observer;

@end
NS_ASSUME_NONNULL_END
