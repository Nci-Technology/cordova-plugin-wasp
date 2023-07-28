//
//  NPEWeightScaleData.h
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
#import <NpeGate/NPEWeightScaleConnection.h>
#import <NpeGate/NPESensorData.h>

FOUNDATION_EXPORT const float NPESensorDataWeightScaleInvalid;
FOUNDATION_EXPORT const float NPESensorDataWeightScaleComputing;


///---------------------------------------------------------------------------------------
/// Sensor Data Parameter Keys
///
/// Supports Common Data Parameter Keys:
///   NPESensorDataParameterKeyRawData
///
/// See also: NPECommonData
///---------------------------------------------------------------------------------------

/** Defines the Sensor Data Parameter Key for Weight data */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyWeight;
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyHydration;
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyBodyFat;
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyActiveMetabolicRate;
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyBasalMetabolicRate;
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyMuscleMass;
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyBoneMass;


/**
 * Represents the data available from the ANT+ Weight Scale sensor.
 *
 * ANT+ sensors send data in multiple packets.  The NPEWeightScaleData
 * combines this data into a single entity.  The data represents the latest of
 * each data type sent from the sensor.
 *
 * See Header Files for Sensor Data Parameter Keys
 */
@interface NPEWeightScaleData : NPESensorData

/** User profile data. */
@property (nonatomic, readonly) NPEWeightScaleUserProfileStruct userProfile;

/** User profile ID number. */
@property (nonatomic, readonly) uint16_t userProfileId;

/**
 * Measured body weight (in kg).
 *
 * @note Two special values exist.  When the weight scale is computing the user's
 * weight, the value will be <b>NPESensorDataWeightScaleComputing</b>.  If the weight
 * scale has not recorded a valid value, the value will be
 * <b>NPE_WEIGHT_SCALE_INVALID</b>. Otherwise, the value is the weight in kilograms.
 */
@property (nonatomic, readonly) float bodyWeight;

/** 
 Is the display capable of exchanging user profile data. 
 */
@property (nonatomic, readonly) BOOL hasDisplayExchangeProfile;

/** 
 Is the scale capable of exchanging user profile data. 
 */
@property (nonatomic, readonly) BOOL hasScaleExchangeProfile;

/** 
 Is the scale capable of ANT FS data exchange. 
 */
@property (nonatomic, readonly) BOOL hasAntFS;

/** 
 Has the user profile been selected. 
 */
@property (nonatomic, readonly) BOOL isUserProfileSelected;

///---------------------------------------------------------------------------------------
/// @name Advanced data
///---------------------------------------------------------------------------------------

/**
 * Body hydration percentage.
 *
 * @note Two special values exist.  When the weight scale is computing the user's
 * measurements, the value will be <b>NPESensorDataWeightScaleComputing</b>.  If the weight
 * scale has not recorded a valid value, the value will be
 * <b>NPESensorDataWeightScaleInvalid</b>. Otherwise, the value is the body hydration
 * percentage.
 */
@property (nonatomic, readonly) float hydrationPercent;

/**
 * Body fat percentage.
 *
 * @note Two special values exist.  When the weight scale is computing the user's
 * measurements, the value will be <b>NPESensorDataWeightScaleComputing</b>.  If the weight
 * scale has not recorded a valid value, the value will be
 * <b>NPESensorDataWeightScaleInvalid</b>. Otherwise, the value is the body fat percentage.
 */
@property (nonatomic, readonly) float bodyFatPercent;

/**
 * Active metabolic Rate.
 *
 * @note Two special values exist.  When the weight scale is computing the user's
 * measurements, the value will be <b>NPESensorDataWeightScaleComputing</b>.  If the weight
 * scale has not recorded a valid value, the value will be
 * <b>NPESensorDataWeightScaleInvalid</b>. Otherwise, the value is the metabolic rate,
 * in kilocalories.
 */
@property (nonatomic, readonly) float activeMetabolicRate;

/**
 * Basal Metabolic Rate.
 *
 * @note Two special values exist.  When the weight scale is computing the user's
 * measurements, the value will be <b>NPESensorDataWeightScaleComputing</b>.  If the weight
 * scale has not recorded a valid value, the value will be
 * <b>NPESensorDataWeightScaleInvalid</b>. Otherwise, the value is the metabolic rate,
 * in kilocalories.
 */
@property (nonatomic, readonly) float basalMetabolicRate;

/**
 * Muscle mass (in kg).
 *
 * @note Two special values exist.  When the weight scale is computing the user's
 * measurements, the value will be <b>NPESensorDataWeightScaleComputing</b>.  If the weight
 * scale has not recorded a valid value, the value will be
 * <b>NPESensorDataWeightScaleInvalid</b>. Otherwise, the value is the muscle mass, in kg.
 */
@property (nonatomic, readonly) float muscleMass;

/**
 * Bone mass (in kg).
 *
 * @note Two special values exist.  When the weight scale is computing the user's
 * measurements, the value will be <b>NPESensorDataWeightScaleComputing</b>.  If the weight
 * scale has not recorded a valid value, the value will be
 * <b>NPESensorDataWeightScaleInvalid</b>. Otherwise, the value is the bone mass, in kg.
 */
@property (nonatomic, readonly) float boneMass;

@end
