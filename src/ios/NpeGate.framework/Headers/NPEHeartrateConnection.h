//
//  NPEHeartrateConnection.h
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

@class NPEHeartrateConnection;

NS_ASSUME_NONNULL_BEGIN
///---------------------------------------------------------------------------------------
/// Sensor Command Keys
///
/// Support Common Commands:
///  NPESensorCmdKeyRequestManufacturerInfo
///  NPESensorCmdKeyRequestVersionInfo
///  NPESensorCmdKeyRequestBatteryStatus
///  NPESensorCmdKeyPowerDown
///  NPESensorCmdKeySetPersonalData
///  NPESensorCmdKeyRequestPersonalData
///
///---------------------------------------------------------------------------------------

/** Sensor Command for Setting Mode */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeySetSportMode;
/** Sensor Command Key for Enabling Gym Mode */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyEnableGymMode;
/** Sensor Command Key for Requesting Capabilities */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyRequestHeartRateCapabilities;
/** Sensor Command Key for Requesting Zone Capabilities */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyRequestZoneCapabilities;
/** Sensor Command Key for Requesting Enabling Interval Mode */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyEnableIntervalMode;
/** Sensor Command Key for Requesting Resetting the interval information */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyResetInterval;
/** Sensor Command Key for Requesting Setting the Zone Thresholds */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeySetZoneThreshold0;
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeySetZoneThreshold1;
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeySetZoneThreshold2;
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeySetZoneThreshold3;
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeySetZoneThreshold4;
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeySetZoneThreshold5;
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeySetZoneThreshold6;
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeySetZoneThreshold7;
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeySetZoneThreshold8;
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeySetZoneThreshold9;
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeySetZoneThreshold10;
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeySetZoneThreshold11;
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeySetZoneThreshold12;
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeySetZoneThreshold13;
/** Sensor Command Key for Requesting Save of zone settings */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeySaveZoneThresholds;
/** Sensor Command Key for Requesting Resetting the Time In Zone information  */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyResetTimeInZones;
/** Sensor Command Key for Requesting Zone Set points information  */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyRequestZoneThresholds;
/** Sensor Command Key for Requesting the Time In Zones information  */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyRequestTimeInZones;
/** Sensor Command Key for Requesting the Time In Zone information  */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyRequestTimeInZone;
/** Sensor Command Key for Requesting the Button Press information  */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyRequestButtonPressInformation;
/** Sensor Command Key for Request Download Files - Sync Session */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyRequestDownloadFiles;
/** Sensor Command Key for Sending AWE Workout Data (points, calories) */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeySetAWEWorkoutData;

///---------------------------------------------------------------------------------------
/// Sensor Command Parameter Keys
///
/// Support Common Command Parameter Keys:
///     NPESensorCommandParameterKeyUserWeight
///     NPESensorDataParameterKeyCalories
///     NPESensorDataParameterKeyPoints
///---------------------------------------------------------------------------------------
/** Command Parameter for setting the Sport Mode of the HeartRate Monitor */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeySportMode;
/** Command Parameter for enabling Gym Mode of the HeartRate Monitor */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeyOperationalMode;
/** Command Parameter for enabling Interval Mode of the HeartRate Monitor */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeyEnableIntervalMode;
/** Sensor Command Key for Getting Zone by Index */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeyGetZoneIndex;
/** Sensor Command Key for Zone Index */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeySetZoneIndex;
/** Sensor Command Key for Setting Zone Value */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeySetZoneValue;
/** Sensor Command Key for Zone Enablement */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeySetZoneEnable;
/** Sensor Command Key for Resting HR */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeyRestingHeartRate;
/** Sensor Command Key for Max HR */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeyMaxHeartRate;
/** Sensor Command Key for Heart Rate in BPM */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeyHeartRate;
/** Sensor Command Key for Heart Rate Threshold */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeyHeartRateThreshold;
/** Sensor Command Key for Command */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeyCommand;
/** Sensor Command Key for User Alert Data */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeyUserAlertData;

/**
 Specific Heart Rate Device
 
 @since 2.0
 */
typedef NS_ENUM(NSInteger, SpecificHeartRateDevice) {
    SpecificHeartRateDeviceGenericANTHeartRateMonitor       = 0,
    SpecificHeartRateDeviceScoscheRhythmPlus                = 1,
    ScoscheRhythmPlus   __deprecated_enum_msg("use SpecificHeartRateDeviceScoscheRhythmPlus") = SpecificHeartRateDeviceScoscheRhythmPlus,

    SpecificHeartRateDevicePolarH7                          = 2,
    SpecificHeartRateDevicePolarH10                         = 3,

    SpecificHeartRateDeviceSuunto                           = 4,
    SpecificHeartRateDeviceAppleWatch                       = 5,
    SpecificHeartRateDeviceScoscheRhythm24                  = 6,
    SpecificHeartRateDevicePolarOH1                         = 7,
    SpecificHeartRateDeviceScoscheRhythmPlusVersionThree    = 8,
    /// North Pole Engineering ANT Watch Enabler
    SpecificHeartRateDeviceNpeAwe                           = 9,

};

/**
 Heart Rate Sport Modes
 
 @since 2.0.10
 */
typedef NS_ENUM(uint8_t, HeartRateSportMode) {
    /** HeartRate Mode - NONE or Not Supported */
    HeartRateSportModeNone              = 0x00,
    /** HeartRate Sport Mode Running */
    HeartRateSportModeRunning           = 0x01,
    /** HeartRate Sport Mode Cycling */
    HeartRateSportModeCycling           = 0x02,
    /** HeartRate Sport Mode Swimming */
    HeartRateSportModeSwimming          = 0x05,
    /** HeartRate Sport Mode Valencell Diag */
    HeartRateSportModeValencellDiag     = 0x0F,
};

/**
 Heart Rate Operational Modes
 
 @since 2.1.0
 */
typedef NS_OPTIONS(uint8_t, HearRateOperationalMode) {
    /** HeartRate Optional Mode - Gym Mode Enabled */
    HearRateOperationalModeGymMode          = 1 << 7,
    /** HeartRate Optional Mode - Interval Mode */
    HearRateOperationalModeIntervalMode     = 1 << 6,
};

/**
 Defines the Scosche Rhythm Plus Button Tap Events

 @since 2.1.0
 */
typedef NS_ENUM(uint8_t, ScoscheRhythmPlusButtonTapEvent) {
    /** NO Button Tap Event */
    ScoscheRhythmPlusButtonTapEventNone                 = 0,
    /** Single Button Tap Event */
    ScoscheRhythmPlusButtonTapEventSingleTap            = 1,
    /** Double Button Tap Event */
    ScoscheRhythmPlusButtonTapEventDoubleTap            = 2,
    /** Triple Button Tap Event */
    ScoscheRhythmPlusButtonTapEventTripleTap            = 3,
    /** Single Button Tap with a Hold Event */
    ScoscheRhythmPlusButtonTapEventSingleTapWithHold    = 4,
    /** Double Button Tap with a Hold Event */
    ScoscheRhythmPlusButtonTapEventDoubleTapWithHold    = 5,
    /** Triple Button Tap with a Hold Event */
    ScoscheRhythmPlusButtonTapEventTripleTapWithHold    = 6,
};


/**
 Typedef for Button Press Observation
 
 @since 2.1.0
 */
typedef void (^NPEHeartrateButtonTapObserverBlock)(NPEHeartrateConnection *connection, ScoscheRhythmPlusButtonTapEvent event, NSInteger eventCount, NSInteger rawEventCount);

/**
 * Represents a connection to a Heart Rate Monitor sensor.
 */
@interface NPEHeartrateConnection : NPESensorConnection

/**
 Allows you to specificaly tell the framework which type of Heartrate Monitor you are using.  Certain heart rate monitors provide more data then just HR, this will allow the framework to start decoding that data right away without having to find out which device it is first.
 
 @since 2.0
 */
@property (nonatomic, assign) SpecificHeartRateDevice specificDevice;

///---------------------------------------------------------------------------------------
/// @name Modes
///---------------------------------------------------------------------------------------

/**
 The Current Sport mode of the Heart Rate Sensor
 
 @since 2.1.0
 */
@property (nonatomic, readonly) HeartRateSportMode sportMode;

/**
 The Current Operational Mode of the Heart Rate Sensor
 
 @since 2.1.0
 */
@property (nonatomic, readonly) HearRateOperationalMode operationalMode;


///---------------------------------------------------------------------------------------
/// @name Commands
///---------------------------------------------------------------------------------------
/**
 Allows the application to force the accumulated time in zone commands to be enabled if the sensor is know to support them.

 @since 3.0
 */
-(void)forceZonesSupported:(NSInteger)zones withThresholds:(NSInteger)thresholds;

/**
 Allows the application to force the Setting of Sport Mode commands to be enabled if the sensor is know to support them.

 @since 3.0
 */
-(void)forceSetSportMode;


///---------------------------------------------------------------------------------------
/// @name Button Tap Observer
///---------------------------------------------------------------------------------------

/**
 A weakified HRM Button Tap Event Observer
 
 Provides a method to observe button taps on the HRM Device
 
 @param observer The observer who is observing the Button Tap events.
 @param callback The block to perform on receipt of button tap event.
 @since 2.1.0
 */
- (void)addButtonTapEventObserver:(id _Nonnull)observer handler:(NPEHeartrateButtonTapObserverBlock _Nullable)callback;

/**
 Remove the Button Tap Event Observer
 
 @param observer The Observer Object to remove from notifications
 @since 2.1.0
 */
- (void)removeButtonTapEventObserver:(id _Nonnull)observer;

@end
NS_ASSUME_NONNULL_END
