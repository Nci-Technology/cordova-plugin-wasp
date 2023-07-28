//
//  NPEPedometerData.h
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
#import <NpeGate/NPESensorData.h>

@class NPECommonData;

NS_ASSUME_NONNULL_BEGIN
///---------------------------------------------------------------------------------------
/// Sensor Data Parameter Keys
///
/// Supports Common Data Parameter Keys:
///   NPESensorDataParameterKeyDataAvailable
///   NPESensorDataParameterKeyRawData
///   NPESensorDataParameterKeyMVPA
///
/// See also: NPECommonData
///---------------------------------------------------------------------------------------

/** Sensor Data Parameter Key - Pedometer Major Version */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyPedometerMajorVersion;
/** Sensor Data Parameter Key - Error Status Hardware Error */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyHardwareError;
/** Sensor Data Parameter Key - Error Status GET Data Error */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyGetFailure;
/** Sensor Data Parameter Key - Error Status SET Data Error */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeySetFailure;

/** Sensor Data Parameter Key - Pedometer is Busy.  NO Command should be sent at this time */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyPedometerBusy;
/** Sensor Data Parameter Key - No Steps have been recorded */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyNoStepsRecorded;

/** Sensor Data Parameter Key - User ID.  If UserID == NPEPedometerInvalidUserId, data should not be used */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyUserId;
/** Sensor Data Parameter Key - TAG ( 0xFF - Not Valid) */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyTag;
/** Sensor Data Parameter Key - SPM ( 0xFF - Not Valid) */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeySpm;
/** Sensor Data Parameter Key - Time */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyTime;
/** Sensor Data Parameter Key - Pedometer received data after request (bool)*/
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyPedometerReceivedData;


///---------------------------------------------------------------------------------------
/// EEProm Data
///---------------------------------------------------------------------------------------
/** Defines the Sensor Data Parameter Key for the EEProm Read Time  */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyEReadTime;
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyETagSpm;
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyEUserId;
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyETripStep;
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyETripAct;
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyETripMvpa;
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyESpm60;
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyESpm80;
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyESpm90;
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyESpm100;
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyESpm110;
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyESpm120;
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyESpm130;
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyESpm140;
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyESpm150;
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyESpm160;


///---------------------------------------------------------------------------------------
/// Sensor Data Constants
///---------------------------------------------------------------------------------------

/** Invalid User ID Constant */
FOUNDATION_EXPORT const uint32_t NPEPedometerInvalidUserId;
/** Invalid TAG Constant */
FOUNDATION_EXPORT const uint8_t  NPEPedometerInvalidTag;
/** Invalid SPM Constant */
FOUNDATION_EXPORT const uint8_t  NPEPedometerInvalidSpm;


/**
 * Represents the most commonly used data available from the ANT+ Pedometer sensor.
 *
 * ANT+ sensors send data in multiple packets.  The NPEPedometerData combines the
 * most commonly used of this data into a single entity.  The data represents
 * the latest of each data type sent from the sensor.
 *
 * See Header Files for Sensor Data Parameter Keys
 */
@interface NPEPedometerData : NPESensorData

/**
 The Major Version Number for the Firmware

 @since 3.0.0
 */
@property (nonatomic, readonly) NSInteger majorVersion;

///---------------------------------------------------------------------------------------
/// @name Pedometer Time Information
///---------------------------------------------------------------------------------------

/**
 * The date and time the data was collected from the pedometer.
 */
@property (nonatomic, readonly, nullable) NSString *readTime;

///---------------------------------------------------------------------------------------
/// @name Pedometer Step Information
///---------------------------------------------------------------------------------------

/**
 * The number of steps recorded on the pedometer
 */
@property (nonatomic, readonly) int steps;

///---------------------------------------------------------------------------------------
/// @name MVPA Data
///---------------------------------------------------------------------------------------

/**
 Users SPM Value from Pedometer

 @since 3.0
 */
@property (nonatomic, readonly) UInt16 spm;

/**
 Users TAG Value from Pedometer

 @since 3,0
 */
@property (nonatomic, readonly) UInt8 tag;

/**
 * The time in seconds spent in Moderate to Vigorous Physical Activity (MVPA) according
 * to the spm setting on the pedometer. 
 */
@property (nonatomic, readonly) double mvpa;

/**
 * The time in seconds spend in motion.
 */
@property (nonatomic, readonly) double actTime;

/**
 * The time in seconds spent around 60 steps per minute.
 */
@property (nonatomic, readonly) double mvpa60;

/**
 * The MVPA time in seconds spent around 80 steps per minute.
 */
@property (nonatomic, readonly) double mvpa80;

/**
 * The MVPA time in seconds spent around 90 steps per minute.
 */
@property (nonatomic, readonly) double mvpa90;

/**
 * The MVPA time in seconds spent around 100 steps per minute.
 */
@property (nonatomic, readonly) double mvpa100;

/**
 * The MVPA time in seconds spent around 110 steps per minute.
 */
@property (nonatomic, readonly) double mvpa110;

/**
 * The MVPA time in seconds spent around 120 steps per minute.
 */
@property (nonatomic, readonly) double mvpa120;

/**
 * The MVPA time in seconds spent around 130 steps per minute.
 */
@property (nonatomic, readonly) double mvpa130;

/**
 * The MVPA time in seconds spent around 140 steps per minute.
 */
@property (nonatomic, readonly) double mvpa140;

/**
 * The MVPA time in seconds spent around 150 steps per minute.
 */
@property (nonatomic, readonly) double mvpa150;

/**
 * The MVPA time in seconds spent around 160 steps per minute.
 */
@property (nonatomic, readonly) double mvpa160;

@end
NS_ASSUME_NONNULL_END
