//
//  NPEFitnessEquipmentData.h
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
#if TARGET_OS_IPHONE
#import <UIKit/UIKit.h>
#elif TARGET_OS_MAC
#import <Cocoa/Cocoa.h>
#import <AppKit/AppKit.h>
#endif

///---------------------------------------------------------------------------------------
/// Sensor Data Parameter Keys
///
/// Supports Common Data Parameter Keys:
///   NPESensorDataParameterKeyAccumDistance
///   NPESensorDataParameterKeySpeed
///   NPESensorDataParameterKeyHeartRate
///   NPESensorDataParameterKeyAccumCalories
///   NPESensorDataParameterKeyCadence
///   NPESensorDataParameterKeyPower
///   NPESensorDataParameterKeySlope
///   NPESensorDataPareterKeyLastCalibration
///   NPESensorDataParameterKeyAccumStrides
///   NPESensorDataParameterKeyDistance
///   NPESensorDataParameterKeyLastCommandID
///   NPESensorDataParameterKeySequenceNumber
///   NPESensorDataParameterKeyCommandStatus
///   NPESensorDataParameterKeyResponseData
///   NPESensorDataParameterKeyRawData
///   NPESensorDataParameterKeyAveragePower
///   NPESensorDataParameterKeyUserWeight
///
/// Support Common Bike Parameter Keys:
///   NPESensorDataParameterKeyBikeGear
///   NPESensorDataParameterKeyAverageTorque
///   NPESensorDataParameterKeyAccumTorque
///   NPESensorDataParameterKeyBikeWheelDiameter
///   NPESensorDataParameterKeyBikeWheelDiameterOffset
///   NPESensorDataParameterKeyBikeWeight
///   NPESensorDataParameterKeyBikeGearRatio
///   NPESensorDataParameterKeyZeroOffset
///
/// See also: NPECommonData
///---------------------------------------------------------------------------------------

/** Defines the Sensor Data Parameter Key for Accumulative Time results */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyAccumTime;
/** Defines the Sensor Data Parameter Key for Accumulative Negative results */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyAccumNegative;
/** Defines the Sensor Data Parameter Key for Accumulative Positive results */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyAccumPositive;
/** Defines the Sensor Data Parameter Key for Accumulative Strokes results */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyStrokes;
/** Defines the Sensor Data Parameter Key for Bike Identification  */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyBikeID;
/** Defines the Sensor Data Parameter Key for Major Version Number  */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyMajorVersion;
/** Defines the Sensor Data Parameter Key for Minor Version Number  */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyMinorVersion;
/** Defines the Sensor Data Parameter Key for Interval results  */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyInterval;
/** Defines the Sensor Data Parameter Key for Keiser Bike State */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyKeiserState;
/** Defines the Sensor Data Parameter Key for Fitness Equipment State. */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyFEStateEnum;
/** Defines the Sensor Data Parameter Key for Fitness Equipment State.  Output is NPEFitnessEquipmentKeiserState */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyFEState;
/** Defines the Sensor Data Parameter Key for Calibration Response  */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyCalibrationRSP;
/** Defines the Sensor Data Parameter Key for Temperature Data  */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyTemperature;
/** Defines the Sensor Data Parameter Key for Spin Down Time Data  */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeySpinDownTime;
/** Defines the Sensor Data Parameter Key for Calibration Status Data  */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyCalibrationStatus;
/** Defines the Sensor Data Parameter Key for Calibration Conditions Data  */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyCalibrationCond;
/** Defines the Sensor Data Parameter Key for Target Speed Data  */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyTargetSpeed;
/** Defines the Sensor Data Parameter Key for Target Spin-Down Time Data  */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyTargetSpinDownTime;
/** Defines the Sensor Data Parameter Key for Heart Rate Source Data  */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyHeartRateSource;
/** Defines the Sensor Data Parameter Key for Cycle Length Data  */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyCycleLength;
/** Defines the Sensor Data Parameter Key for Incline Data  */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyIncline;
/** Defines the Sensor Data Parameter Key for Resistance Level Data  */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyResistanceLevel;
/** Defines the Sensor Data Parameter Key for Metabolic Equivalent (METs) Data  */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyMETs;
/** Defines the Sensor Data Parameter Key for Caloric Burn Rate Data  */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyCaloricBurnRate;
/** Defines the Sensor Data Parameter Key for Stride Data  */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyStrides;
/** Defines the Sensor Data Parameter Key for Accumulated Power Data  */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyAccumPower;
/** Defines the Sensor Data Parameter Key for Bike Power Calibration Data  */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyBikePowerCalibration;
/** Defines the Sensor Data Parameter Key for Bike Resistance Calibration Data  */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyBikeResistanceCalibration;
/** Defines the Sensor Data Parameter Key for Bike Target Power Limits Data  */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyTargetPowerLimits;
/** Defines the Sensor Data Parameter Key for Bike User Configuration Data  */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyUserConfiguration;
/** Defines the Sensor Data Parameter Key for Maximum Resistance Data  */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyMaximumResitance;
/** Defines the Sensor Data Parameter Key for Supports Resistance Mode  */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeySupportResistanceMode;
/** Defines the Sensor Data Parameter Key for Supports Target Power Mode  */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeySupportsTargetPowerMode;
/** Defines the Sensor Data Parameter Key for Supports Simulation Mode  */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeySupportsSimulationMode;
/** Defines the Sensor Data Parameter Key for Accumulated Reps */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyAccumReps;
/** Defines the Sensor Data Parameter Key for Repetion Counter Type - see NPEFitnessEquipmentRepCounterType */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterKeyRepetitionCounterType;

//DATA for IHRSA
/** Defines the Sensor Data Parameter Key for Console Event Message */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterConsoleEventMessage;
/** Defines the Sensor Data Parameter Key for Console Event Message Counter */
FOUNDATION_EXPORT NPESensorDataParameterKey _Nonnull const NPESensorDataParameterConsoleEventMessageCount;


/** Describes the state of a Fitness Equipment machine. */
typedef NS_ENUM(NSInteger, NPEFitnessEquipmentState) {
    
    NPEFitnessEquipmentStateRESERVED        = 0,
    /** The FE machine is off. */
    NPEFitnessEquipmentStateAsleep          = 1,
    /** The FE machine is on, awaiting connection. */
    NPEFitnessEquipmentStateReady           = 2,
    /** The FE machine is in use, workout in progreas. */
    NPEFitnessEquipmentStateInUse           = 3,
    /**
     The workout is paused or finished.
     
     If the next state is NPEFitnessEquipmentStateInUse, interpret as paused, if
     the next state is NPEFitnessEquipmentStateReady, interpret as finished.
     */
    NPEFitnessEquipmentStateFinished        = 4,
};

/** Describes the type of Fitness Equipment machine. */
typedef NS_ENUM(NSInteger, NPEFitnessEquipmentType_t) {
    /** No FE type specified. */
    NPE_FETYPE_NONE                             = 0,
    /** Specifies the Punch Sensor */
    NPE_FETYPE_PUNCH                            = 1,

    /** Non-specific FE machine - should broadcast basic FE data. */
    NPE_FETYPE_GENERAL                          = 16,
    /** Specifies the treadmill. */
    NPE_FETYPE_TREADMILL                        = 19,
    /** Specifies the elliptical trainer. */
    NPE_FETYPE_ELLIPTICAL                       = 20,
    /** Specifies the stationary bike. */
    NPE_FETYPE_BIKE                             = 21,
    /** Specifies the rower. */
    NPE_FETYPE_ROWER                            = 22,
    /** Specifies the climber. */
    NPE_FETYPE_CLIMBER                          = 23,
    /** Specifies the Nordic Skier. */
    NPE_FETYPE_NORDIC_SKIER                     = 24,
    /** Specifies the Trainer */
    NPE_FETYPE_TRAINER                          = 25,
    /** Specifies the Trainer Torque */
    NPE_FETYPE_TRAINER_TORQUE                   = 26,
    /** Specifies the Rep Counter */
    NPE_FETYPE_REP_COUNTER                      = 27,
    /** KeiserMultiBike */
    NPE_KEISER_MULTI_BIKE                       = 1000,
    NPE_FETYPE_KEISER_MULTI_BIKE                = NPE_KEISER_MULTI_BIKE
};

/**
 Describes the state of the Keiser Bike Data.
 
 @since 2.0.10
 */
typedef NS_ENUM(NSInteger, NPEFitnessEquipmentKeiserState) {
    /** The Keiser machine is off. */
    NPEFitnessEquipmentKeiserStateReserved          = 0,
    /** The Keiser machine is providing real time data. */
    NPEFitnessEquipmentKeiserStateRealTime          = 1,
    /** The Keiser machine is providing entire ride averages.  User has Stopped Ride. */
    NPEFitnessEquipmentKeiserStateRideAverage       = 2,
    /** The Keiser machine is providing interval real time data. */
    NPEFitnessEquipmentKeiserStateIntervalActive    = 3,
    /** The Keiser machine is providing interval avgerage data. */
    NPEFitnessEquipmentKeiserStateIntervalAverage   = 4,
};

/**
 Describes the Type of Rep Counter
 
 @since 3.0
 */
typedef NS_ENUM(NSInteger, NPEFitnessEquipmentRepCounterType) {
    /** Push Up Counter - Counts number of push-ups */
    NPEFitnessEquipmentRepCounterTypePushUp         = 0,
    /** Curl Up Counter - Counts number of curl-ups */
    NPEFitnessEquipmentRepCounterTypeCurlUp         = 1,
    /** Pull Up Counter - Counts number of pull-ups */
    NPEFitnessEquipmentRepCounterTypePullUp         = 2,
    /** Trunk Lift Counter - Measures the amount of lift of the upper body off the floor */
    NPEFitnessEquipmentRepCounterTypeTrunkLift      = 3,
    /** Sit and Reach - Measures flexibility, and specifically, the flexibility of the lower back and hamstring muscles */
    NPEFitnessEquipmentRepCounterTypeSitAndReach    = 4,
    /** Vertical Jump - Measures the vertical distance of a jump */
    NPEFitnessEquipmentRepCounterTypeVerticalJump   = 5
};

/**
 * Represents the most commonly used data available from the ANT+ Fitness Equipment sensor.
 *
 * ANT+ sensors send data in multiple packets.  The NPEFitnessEquipmentData combines the
 * most commonly used of this data into a single entity.  The data represents
 * the latest of each data type sent from the sensor.
 * 
 * See Header Files for Sensor Data Parameter Keys
 */
@interface NPEFitnessEquipmentData : NPESensorData

/**
 * The type of the connected Fitness Equipment device.
 */
@property (nonatomic, readonly) NPEFitnessEquipmentType_t equipmentType;

/**
 The current state of the connected Fitness Equipment device.
 
 When the state is in NPEFitnessEquipmentStateReady, it will zero out the accumulated data from the device. Once the Equipment goes into NPEFitnessEquipmentStateInUse it will start to accumulate the Accumulated data..

 */
@property (nonatomic, readonly) NPEFitnessEquipmentState equipmentState;

/**
 Provides a String Value for the Fitness Equipment State

 @param state Fitness Equipment State
 @return String Value for State
 @since 3.0
 */
+ (NSString * _Nonnull)stringValueForFitnessEquipmentState:(NPEFitnessEquipmentState)state;

/**
 * The accumulated time since the workout was started, in 0.25 seconds.
 */
@property (nonatomic, readonly) float accumTime;

/**
 * The accumulated distance, in meters, since the workout was started.
 */
@property (nonatomic, readonly) float accumDistance;

/**
 * The instantaneous speed, in meters per second.
 */
@property (nonatomic, readonly) float instSpeed;

/**
 * The accumulated calories since the workout was started.
 */
@property (nonatomic, readonly) NSUInteger accumCalories;

///---------------------------------------------------------------------------------------
/// @name Heart Rate
///---------------------------------------------------------------------------------------

/**
 * The instantaneous heart rate, in NPEUnitTypeBeatsPerMinute.
 */
@property (nonatomic, readonly) u_char heartrate;

///---------------------------------------------------------------------------------------
/// @name Lap Information
///---------------------------------------------------------------------------------------

/**
 * The lap toggle event of the connected Fitness Equipment device.
 */
@property (nonatomic, readonly) uint8_t lapToggle;

/**
 * The current lap number.
 */
@property (nonatomic, readonly) NSInteger lapNumber;

///---------------------------------------------------------------------------------------
/// @name Treadmill Equipment
///---------------------------------------------------------------------------------------

/**
 * The instantaneous cadence, in strides per minute.
 */
@property (nonatomic, readonly) u_char treadmillCadence;

/**
 * The total negative vertial distance traveled, in 0.1 meters.
 */
@property (nonatomic, readonly) float treadmillAccumNegVertDist;

/**
 * The total positive vertical distance traveled, in 0.1 meters.
 */
@property (nonatomic, readonly) float treadmillAccumPosVertDist;

///---------------------------------------------------------------------------------------
/// @name Elliptical Equipment
///---------------------------------------------------------------------------------------

/**
 * The total positive vertical distance traveled, in 0.1 meters.
 */
@property (nonatomic, readonly) float ellipticalAccumPosVertDist;
/**
 * The total number of strides taken.
 */
@property (nonatomic, readonly) NSUInteger ellipticalAccumStrides;
/**
 * The instantaneous cadence, in strides per minute.
 */
@property (nonatomic, readonly) u_char ellipticalCadence;
/**
 * The instantaneous power, in watts.
 */
@property (nonatomic, readonly) NSInteger ellipticalInstPower;

///---------------------------------------------------------------------------------------
/// @name Bike Equipment
///---------------------------------------------------------------------------------------

/**
 * The instantaneous cadence, in RPMs.
 */
@property (nonatomic, readonly) u_char bikeCadence;

/**
 * The instantaneous power, in watts.
 */
@property (nonatomic, readonly) u_short bikeInstPower;


///---------------------------------------------------------------------------------------
/// @name Rower Equipment
///---------------------------------------------------------------------------------------

/**
 * The total stroke count.
 */
@property (nonatomic, readonly) NSUInteger rowerAccumStrokes;

/**
 * The instantaneous cadence, in strokes per minute.
 */
@property (nonatomic, readonly) u_char rowerCadence;

/**
 * The instantaneous power, in watts.
 */
@property (nonatomic, readonly) u_short rowerInstPower;


///---------------------------------------------------------------------------------------
/// @name Climber
///---------------------------------------------------------------------------------------

/**
 * The total stride count.
 */
@property (nonatomic, readonly) NSUInteger climberAccumCycles;

/**
 * The instantaneous cadence, in strokes per minute.
 */
@property (nonatomic, readonly) NSUInteger climberCadence;

/**
 * The instantaneous power, in watts.
 */
@property (nonatomic, readonly) u_short climberInstPower;


///---------------------------------------------------------------------------------------
/// @name Nordic Skier
///---------------------------------------------------------------------------------------

/**
 * The total stride count.
 */
@property (nonatomic, readonly) NSUInteger skierAccumStrides;
/**
 * The instantaneous cadence, in strokes per minute.
 */
@property (nonatomic, readonly) u_char skierCadence;
/**
 * The instantaneous power, in watts.
 */
@property (nonatomic, readonly) u_short skierInstPower;


///---------------------------------------------------------------------------------------
/// @name Trainer
///---------------------------------------------------------------------------------------

/**
 * The event counter
 */
@property (nonatomic, readonly) u_char trainerEventCount;

/**
 * The total accumulated power
 */
@property (nonatomic, readonly) NSUInteger trainerAccumPower;

/**
 * The total accumulated power
 */
@property (nonatomic, readonly) NSUInteger trainerAvgPower;

/**
 * The instantaneous cadence, in strokes per minute.
 */
@property (nonatomic, readonly) u_char trainerCadence;

/**
 * The instantaneous power, in watts.
 */
@property (nonatomic, readonly) u_short trainerInstPower;


///---------------------------------------------------------------------------------------
/// @name Trainer Torque
///---------------------------------------------------------------------------------------

/**
 * The event counter
 */
@property (nonatomic, readonly) long torqueEventCount;

/**
 * The total accumulated torque
 */
@property (nonatomic, readonly) NSUInteger torqueAccumTorque;

/**
 * The total accumulated wheel period
 */
@property (nonatomic, readonly) NSUInteger torqueAccumWheelPeriod;

/**
 * The wheel tick counts.
 */
@property (nonatomic, readonly) long torqueTicks;

/**
 * The average power, in watts.
 */
@property (nonatomic, readonly) float torqueAvgPower;

/**
 * The speed in km/h.
 */
@property (nonatomic, readonly) float torqueSpeed;

/**
 * The distance in meters.
 */
@property (nonatomic, readonly) float torqueDistance;

/**
 * Average Trainer Torque
 */
@property (nonatomic, readonly) float torqueAvgTorque;

/**
 * Average Trainer Angular Velocity
 */
@property (nonatomic, readonly) float torqueAvgAngularVelocity;


///---------------------------------------------------------------------------------------
/// @name Repetition Counter
///---------------------------------------------------------------------------------------

/**
 The Type of Repetition Counter
 
 @since 3.0
 */
@property (nonatomic, readonly) NPEFitnessEquipmentRepCounterType repCounterType;

/**
 Accumulated Distance

 Distance represents distance lifted, reached, or height jumpted based on the counter type.

 @since 3.0
 */
@property (nonatomic, readonly) NSInteger accumulatedRepDistanceInMilimeters;

/**
 Instantaneous Distance

 Distance represents distance lifted, reached, or height jumpted based on the counter type.

 @since 3.0
 */
@property (nonatomic, readonly) NSInteger instantaneousRepDistanceInMilimeters;


/**
 The Total number of Reps.

 */
@property (nonatomic, readonly) NSUInteger accumulatedRepCount;


///---------------------------------------------------------------------------------------
/// @name Punch Counte
///---------------------------------------------------------------------------------------

/**
 The Total number of Punches.

 @since 3.0
 */
@property (nonatomic, readonly) NSUInteger accumulatedPunchCount;

/**
 Accumulated Intensity

 Accumulated Intensity Level of the Punches.

 @since 3.0
 */
@property (nonatomic, readonly) NSUInteger accumulatedPunchIntensity;


/**
 Seconds Since Last Punch Event

 @since 3.0
 */
@property (nonatomic, readonly) CGFloat secondsBetweenPunches;


///---------------------------------------------------------------------------------------
/// @name Vertical Jump
///---------------------------------------------------------------------------------------

/**
 * The total jumps count.
 *
 * @since 2.2
 */
@property (nonatomic, readonly) NSUInteger vertJumpAccumJumps __deprecated_msg("3.0: Use accumulatedRepCount");

/**
 * The Vertical Jump Height in mm.
 *
 * @since 2.2
 */
@property (nonatomic, readonly) NSInteger vertJumpHeight __deprecated_msg("3.0: Use instantaneousRepDistanceInMilimeters");

- (void)resetAccumulatedData;

@end
