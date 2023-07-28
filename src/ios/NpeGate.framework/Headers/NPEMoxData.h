//
//  NPEMoxData.h
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

NS_ASSUME_NONNULL_BEGIN
///---------------------------------------------------------------------------------------
/// Sensor Data Parameter Keys
///
/// Supports Common Data Parameter Keys:
///   NPESensorDataParameterKeyRawData
///
/// See also: NPECommonData
///---------------------------------------------------------------------------------------

/** Defines the Sensor Data Parameter Key for Total Hemoglobin Concentration results */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyTotalHC;
/** Defines the Sensor Data Parameter Key for Previous Hemoglobin Saturation % results */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyPreviousHSP;
/** Defines the Sensor Data Parameter Key for Current Hemoglobin Saturation % results */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyCurrentHSP;
/** Defines the Sensor Data Parameter Key for Ambient light too high */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyAmbientLightTooHigh;


/**
 Invalid Total Hemoglobin
 
 @since 2.1.0
 */
FOUNDATION_EXPORT const NSInteger NPEMoxInvalidTotalHemoglobin;

/**
 Invalid Saturated Hemoglobin
 
 @since 2.1.0
 */
FOUNDATION_EXPORT const NSInteger NPEMoxInvalidSaturatedHemoglobin;


/**
 The Measurement Interval of the MOX Sensor
  
 @since 2.1.0
 */
typedef NS_ENUM(uint8_t, NPEMoxMeasurementInterval) {
    /** Interval of 0.25s */
    NPEMoxMeasurementInterval0_25Sec    = 0x01,
    /** Interval of 0.50s */
    NPEMoxMeasurementInterval0_50Sec    = 0x02,
    /** Interval of 1s */
    NPEMoxMeasurementInterval1Sec       = 0x03,
    /** Interval of 2s */
    NPEMoxMeasurementInterval2Sec       = 0x04
};


/**
 * Represents the most commonly used data available from the ANT+ Muscle Oxygen sensor.
 *
 * ANT+ sensors send data in multiple packets.  The NPEMoxData combines the
 * most commonly used of this data into a single entity.  The data represents
 * the latest of each data type sent from the sensor.
 *
 * See Header Files for Sensor Data Parameter Keys
 */
@interface NPEMoxData : NPESensorData

/*
 * Indicates if the UTC time has been set in the unit
 *
 * 0 – UTC time set
 * 1 – UTC time required
 */
@property (nonatomic, readonly) BOOL utcTimeSet;

/*
 * Indicates if the unit supports ANT-FS
 */
@property (nonatomic, readonly) BOOL antFsSupport;

/*
 * Indicates if the measurement interval for the unit
 */
@property (nonatomic, readonly) NPEMoxMeasurementInterval measurementInterval;

///---------------------------------------------------------------------------------------
/// @name Hemoglobin Concentration
///---------------------------------------------------------------------------------------

/**
 The Total Hemoglobin Concentration in (NPEUnitTypeGramsPerDeciliter)

 @note Invalid value == NPEMoxInvalidTotalHemoglobin
 */
@property (nonatomic, readonly) NSNumber *totalHemoglobin;

///---------------------------------------------------------------------------------------
/// @name Hemoglobin Saturation
///---------------------------------------------------------------------------------------

/**
 The Previous Saturated Hemoglobin Percentage.
 
 @note Invalid Value == NPEMoxInvalidSaturatedHemoglobin
 */
@property (nonatomic, readonly) NSNumber *prevHemoglobinSat;

/**
 The Current Saturated Hemoglobin Percentage.
 
 @note Invalid Value == NPEMoxInvalidSaturatedHemoglobin
 */
@property (nonatomic, readonly) NSNumber *currHemoglobinSat;

@end
NS_ASSUME_NONNULL_END
