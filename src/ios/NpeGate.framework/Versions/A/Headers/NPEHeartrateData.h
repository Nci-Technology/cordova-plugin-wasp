//
//  NPEHeartrateData.h
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
#import <NpeGate/NPESensorLocationProtocol.h>
#import <NpeGate/NPEHeartrateConnection.h>


NS_ASSUME_NONNULL_BEGIN
///---------------------------------------------------------------------------------------
/// Sensor Data Parameter Keys
///
/// Supports Common Data Parameter Keys:
///   NPESensorDataParameterKeyHeartRate
///   NPESensorDataParameterKeyStepsPerMin - If HR is ScoscheRhythmPlus
///   NPESensorDataParameterKeyTotalSteps - If HR is ScoscheRhythmPlus
///   NPESensorDataParameterKeyTotalDistance - If HR is ScoscheRhythmPlus
///   NPESensorDataParameterKeyLocation
///   NPESensorDataParameterKeyRawData
///   NPESensorDataParameterKeyUserAge
///   NPESensorDataParameterKeyUserWeight
///   NPESensorDataParameterKeyUserHeight
///   NPESensorDataParameterKeyButtonPressEvent  @see ScoscheRhythmPlusButtonTapEvent
///   NPESensorDataParameterKeySpeed
///   NPESensorDataParameterKeyAccumStrides
///   NPESensorDataParameterKeyStridesPerMin
///   NPESensorDataParameterKeyAccumDistance
///
/// See also: NPECommonData
///---------------------------------------------------------------------------------------

/** Defines the Sensor Data Parameter Key Beat Time, measured in ms */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyBeatTime;
/** Defines the Sensor Data Parameter Key Beat Count */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyBeatCount;
/** Defines the Sensor Data Parameter Key for RR Interval, measured in ms */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyRRInterval;
/** Defines the Sensor Data Parameter Key for RR Deviation, measured in ms */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyRRDeviation;
/** Defines the Sensor Data Parameter Key for Sensor Contact Status */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyContactStatus;
/** Defines the Sensor Data Parameter Key for Swim Interval Average Heart Rate */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyIntervalAvgHeartRate;
/** Defines the Sensor Data Parameter Key for Swim Interval Maximum Heart Rate */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyIntervalMaxHeartRate;
/** Defines the Sensor Data Parameter Key for Swim Session Average Heart Rate */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeySessionAvgHeartRate;
/** Defines the Sensor Data Parameter Key for Running Feature Supported */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyRunningFeatureSupported;
/** Defines the Sensor Data Parameter Key for Cycling Feature Supported */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyCyclingFeatureSupported;
/** Defines the Sensor Data Parameter Key for Swimming Feature Supported */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeySwimmingFeatureSupported;
/** Defines the Sensor Data Parameter Key for Gym Mode Feature Supported */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyGymModeFeatureSupported;
/** Defines the Sensor Data Parameter Key for Running Feature Enabled */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyRunningFeatureEnabled;
/** Defines the Sensor Data Parameter Key for Cycling Feature Enabled */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyCyclingFeatureEnabled;
/** Defines the Sensor Data Parameter Key for Swimming Feature Enabled */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeySwimmingFeatureEnabled;
/** Defines the Sensor Data Parameter Key for Gym Mode Feature Enabled */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyGymModeFeatureEnabled;
/** Defines the Sensor Data Parameter Key for Heartbeat Event Derivation Method */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyHeartbeatEventDerivation;
/** Defines the Sensor Data Parameter Key for Display Zones Supported */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyDisplayZonesSupported;
/** Defines the Sensor Data Param Key for Display Zones Enabled */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyDisplayZonesEnabled;
/** Defines the Sensor Data Param Key for Accumulation Zones Supported */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyAccumulationZonesSupported;
/** Defines the Sensor Data Param Key for Accumulation Zones Enabled */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyAccumulationZonesEnabled;

/** Defines the Sensor Data Parameter Key for T0 Set Point */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyT0SetPoint;
/** Defines the Sensor Data Parameter Key for T1 Set Point */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyT1SetPoint;
/** Defines the Sensor Data Parameter Key for T2 Set Point */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyT2SetPoint;
/** Defines the Sensor Data Parameter Key for T3 Set Point */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyT3SetPoint;
/** Defines the Sensor Data Parameter Key for T4 Set Point */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyT4SetPoint;
/** Defines the Sensor Data Parameter Key for T5 Set Point */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyT5SetPoint;
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyT6SetPoint;
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyT7SetPoint;
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyT8SetPoint;
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyT9SetPoint;
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyT10SetPoint;
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyT11SetPoint;
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyT12SetPoint;
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyT13SetPoint;
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyT14SetPoint;
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyT15SetPoint;
/** Defines the Sensor Data Parameter Key for Time Below Zone 1 */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyZone0Time;
/** Defines the Sensor Data Parameter Key for Time In Zone 1 */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyZone1Time;
/** Defines the Sensor Data Parameter Key for Time In Zone 2 */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyZone2Time;
/** Defines the Sensor Data Parameter Key for Time In Zone 3 */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyZone3Time;
/** Defines the Sensor Data Parameter Key for Time In Zone 4 */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyZone4Time;
/** Defines the Sensor Data Parameter Key for Time In Zone 5 */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyZone5Time;
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyZone6Time;
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyZone7Time;
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyZone8Time;
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyZone9Time;
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyZone10Time;
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyZone11Time;
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyZone12Time;
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyZone13Time;

/** Defines the Sensor Data Parameter Key for The Valencell Optical Input DC Level*/
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyOpticalInput;
/** Defines the Sensor Data Parameter Key for The Valencell Signal Quality*/
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyQuality;
/** Defines the Sensor Data Parameter Key for Resting Heartrate */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyRestingHeartRate;
/** Defines the Sensor Data Parameter Key for Max Heartrate */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyMaxHeartRate;

///---------------------------------------------------------------------------------------
/// Sensor Data Constants
///---------------------------------------------------------------------------------------

/** Invalid HeartRate */
FOUNDATION_EXPORT const NSInteger NPESensorDataInvalidHeartRate;

/**
 Defines the Heart Rate Sensor Contact to body
 
 @since 2.0
 */
typedef NS_ENUM(NSInteger, HeartRateSensorContact) {
    /** Heart Rate Sensor Contact - contact is not detected */
    HeartRateSensorContactNotConnected = 0,
    /** Heart Rate Sensor Contact - contact is detected */
    HeartRateSensorContactConnected = 1,
    /** Heart Rate Sensor Contact - contact is Unknown */
    HeartRateSensorContactUnknown = 2
};

/**
 Heartbat Event Timestamp Derivation Method
 
 @since 2.2
 */
typedef NS_ENUM(NSInteger, HeartRateEventDerivationMethod) {
    /** Derivation Method - Measured */
    HeartRateEventDerivationMethodMeasured      = 0,
    /** Derivation Method - Computed */
    HeartRateEventDerivationMethodComputed      = 1,
    /** Derivation Method - Unknonwn */
    HeartRateEventDerivationMethodUnknown       = 255,
};

/**
 Describes the Cycling Instantaneous Riding Position
 
 @since 2.2
 */
typedef NS_ENUM(NSInteger, HeartRateCyclingRidingPosition) {
    /** Riding Position - Not Available */
    HeartRateCyclingRidingPositionNotAvailable      = 0,
    /** Riding Position - Unknown */
    HeartRateCyclingRidingPositionUnknown           = 1,
    /** Riding Position - Sitting */
    HeartRateCyclingRidingPositionSitting           = 2,
    /** Riding Position - Standing */
    HeartRateCyclingRidingPositionStanding          = 3,
};

/**
 * Represents the most commonly used data available from the Heart Rate Monitor sensor.
 *
 * The NPEHeartrateData combines the most commonly used data into a single entity.
 * The data represents the latest of each data type sent from the sensor.
 *
 * See Header Files for Sensor Data Parameter Keys
 */
@interface NPEHeartrateData : NPESensorData <NPESensorLocationProtocol>

/**
 Provides a status of if the Sensor is in contact with the body.
 
 @since 2.0
 */
@property (nonatomic, readonly) HeartRateSensorContact contactStatus;

/**
 * Represents the time of the last valid heart beat event.
 *
 * The time units are 1/1024 seconds.  Since the values are stored in
 * two byte integers which have a maximum value of 65536, the value
 * will roll over at 64 seconds (65536 / 1024).  This should be taken
 * into consideration when determining the currency of the data.
 */
@property (nonatomic, readonly) NSInteger beatTime;

/**
 * Instantaneous heart rate, in (NPEUnitTypeBeatsPerMinute).
 *
 * The valid values are 1-255, a value of 0 represents invalid data.
 */
@property (nonatomic, readonly) int computedHeartrate;

/**
 * A 32-bit integer value which increments with each heart beat event.
 *
 * This value represents the same data as NPEHeartrateRawData::beatCount,
 * but stores values larger than 255.
 */
@property (nonatomic, readonly) NSUInteger accumBeatCount;

///---------------------------------------------------------------------------------------
/// @name Stride & Distance
///---------------------------------------------------------------------------------------

/**
 * The accumulated distance measurement.
 *
 * When available, this value is similar to the NPEFootpodRawData::distance
 * value, but with a larger roll over value.
 */
@property (nonatomic, readonly) float accumulatedDistance;

/**
 * The accumulated stride count.
 *
 * When available, this value is similar to the NPEFootpodRawData::strideCount
 * value, but with a larger roll over value.
 */
@property (nonatomic, readonly) NSUInteger accumulatedStride;

///---------------------------------------------------------------------------------------
/// @name Zone data
///---------------------------------------------------------------------------------------

/**
 * The number of zone thresholds the device supports.
 *
 * @since 2.1.0
 */
@property (nonatomic, readonly) NSUInteger supportedZones;

/**
 * The number of accumlation zones the device has enabled.
 */
@property (nonatomic, readonly) NSUInteger enabledZones;

/**
 * Array of values for the threshold points
 */
@property (nonatomic, nonnull, readonly) NSArray *thresholdValues;
@property (nonatomic, nonnull, readonly) NSArray *thresholdEnables;


///---------------------------------------------------------------------------------------
/// @name Extended Cycling Information
///---------------------------------------------------------------------------------------

/**
 Cadence
 
 @since 2.2
 */
@property (nonatomic, readonly) NSInteger cadence;

/**
 Instantaneous Position
 
 @since 2.2
 */
@property (nonatomic, readonly) HeartRateCyclingRidingPosition ridingPosition;


///---------------------------------------------------------------------------------------
/// @name Device Information
///---------------------------------------------------------------------------------------

/**
 How the Heartbeat event timestamp is derived on the device
 
 @since 2.2
 */
@property (nonatomic, readonly) HeartRateEventDerivationMethod heartbeatEventMethod;

///---------------------------------------------------------------------------------------
/// @name User Sub Field Data
///---------------------------------------------------------------------------------------

/**
 Resting Heart Rate stored on device
 
 @since 3.0
 */
@property (nonatomic, readonly) NSInteger userRestingHeartrate;

/**
 Maximum Heart Rate stored on device

 @since 3.0
 */
@property (nonatomic, readonly) NSInteger userMaximumHeartrate;

@end
NS_ASSUME_NONNULL_END

