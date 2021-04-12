//
//  NPEBLEDefines.h
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

/**
 BLE GAP Advertisement Flag Types
 
 @since 2.0.6
 */
typedef NS_OPTIONS(UInt8, BLEAdvertisementTypeFlag) {
    /** Limited Discoverable Mode */
    BLEAdvertisementTypeFlagLimitedDiscoverableMode         = 1 << 0,
    /** General Discoverable Mode */
    BLEAdvertisementTypeFlagGeneralDiscoverableMode         = 1 << 1,
    /** BR/EDR Not Supported */
    BLEAdvertisementTypeFlagBREDRNotSupported               = 1 << 2,
    /** Simultaneous LE and BR/EDR to Same Device Capable (Controller) */
    BLEAdvertisementTypeFlagSimultaneousCapableController   = 1 << 3,
    /** Simultaneous LE and BR/EDR to Same Device Capable (Host) */
    BLEAdvertisementTypeFlagSimultaneousCapableHost         = 1 << 4,
};

/**
 BLE Security Manager Out of Band data type flags
 
 @since 2.0.6
 */
typedef NS_OPTIONS(UInt8, BLEAdvertisementOOBFlag) {
    /** OOB Flags Field (0 = OOB data not present, 1 = OOB data present) */
    BLEAdvertisementOOBFlagPresent          = 1 << 0,
    /** LE supported (Host) (i.e. bit 65 of LMP Extended Feature bits Page 1 */
    BLEAdvertisementOOBFlagLESupported      = 1 << 1,
    /** Simultaneous LE and BR/EDR to Same Device Capable (Host) (i.e. bit 66 of LMP Extended Feature bits Page 1) */
    BLEAdvertisementOOBFlagSimultaneousLE   = 1 << 2,
    /** Address type (0 = Public Address, 1 = Random Address) */
    BLEAdvertisementOOBFlagRandomAddress    = 1 << 3,
};


/**
 Defines the Role of the BLE Device
 
 @since 2.0
 */
typedef NS_ENUM(NSInteger, BLERole) {
    /* Only Peripheral Role supported */
    BLERolePeripheralOnly       = 0,
    /* Only Central Role supported */
    BLERoleCentralOnly          = 1,
    /* Peripheral and Central Role supported, Peripheral Role preferred for connection establishment */
    BLERolePeripheralPreferred  = 2,
    /* Peripheral and Central Role supported, Central Role preferred for connection establishment */
    BLERoleCentralPreferred     = 3,
};

/**
 Defines the Peer Address Types
 
 @since 2.0
 */
typedef NS_ENUM(NSInteger, BLEPeerAddressType) {
    /** BLE Peer Address Public */
    BLEPeerAddressTypePublic                        = 0,
    /** BLE Peer Address Random Static */
    BLEPeerAddressTypeRandomStatic                  = 1,
    /** BLE Peer Address Private Resolvable */
    BLEPeerAddressTypeRandomPrivateResolvable       = 2,
    /** BLE Peer Address Private Non Resolvable */
    BLEPeerAddressTypeRandomPrivateNonResolvable    = 3,
};

/**
 Defines the Gap Advertising Type
 
 @since 2.0
 */
typedef NS_ENUM(NSInteger, BLEGapAdvertisingEventType) {
    /** Event - Connectable undirected advertising */
    BLEGapAdvertisingEventTypeConnectable           = 0,
    /** Event - Connectable directed advertising */
    BLEGapAdvertisingEventTypeConnectableDirected   = 1,
    /** Event - Scannable undirected advertising */
    BLEGapAdvertisingEventTypeTypeScannable         = 2,
    /** Event - Non Connectable undirected advertising */
    BLEGapAdvertisingEventTypeNonConnectable        = 3,
    /** Event - Scan Response */
    BLEGapAdvertisingEventTypeScanResponse          = 4,
};


/**
 Defines the BLE Scan Modes
 
 @since 2.0
 */
typedef NS_ENUM(NSInteger, BLEScanMode) {
    /** Stops all BLE Scanning Modes, both Passive and Active Scans */
    BLEScanModeStop         = 0,
    /** Passive, non-selective Scan mode.  This is the Default Scan mode when the WASP Starts with a BLE Radio active */
    BLEScanModePassive      = 1,
    /** RESERVED FOR Passive, selective Scan mode.  */
    BLEScanModeSelective    = 2,
    /** BLE Active Scan Mode.  */
    BLEScanModeActive       = 3,
};

/**
 Describes the BLE Appearance
 
 @since 2.0
 */
typedef NS_ENUM(NSInteger, BLEAppearance) {
    /** Unknown of unspecified appearance type */
    BLEAppearanceUnknown                            = 0,
    /** Generic Phone */
    BLEAppearanceGeneric_Phone                      = 64,
    /** Generic Computer */
    BLEAppearanceGeneric_Computer                   = 128,
    /** Generic Watch */
    BLEAppearanceGeneric_Watch                      = 192,
    /** Sports Watch */
    BLEAppearanceWatch_SportsWatch                  = 193,
    /** Generic Clock */
    BLEAppearanceGeneric_Clock                      = 256,
    /** Generic Display */
    BLEAppearanceGeneric_Display                    = 320,
    /** Generic Remote Control */
    BLEAppearanceGeneric_RemoteControl              = 384,
    /** Generic Eye Glasses */
    BLEAppearanceGeneric_EyeGlasses                 = 448,
    /** Generic Tag */
    BLEAppearanceGeneric_Tag                        = 512,
    /** Generic Keyring */
    BLEAppearanceGeneric_Keyring                    = 576,
    /** Generic Media Player */
    BLEAppearanceGeneric_MediaPlayer                = 640,
    /** Generic Barcode Scanner */
    BLEAppearanceGeneric_BarcodeScanner             = 704,
    /** Generic Thermometer */
    BLEAppearanceGeneric_Thermometer                = 768,
    /** Ear Thermometer */
    BLEAppearanceThermometerEar                     = 769,
    /** Generic Heart Rate Sensor */
    BLEAppearanceGeneric_HeartRateSensor            = 832,
    /** Belt Heart Rate Sensor */
    BLEAppearanceHeartRateSensorBelt                = 833,
    /** Generic Blood Pressure */
    BLEAppearanceGeneric_BloodPressure              = 896,
    /** Arm Blood Pressure */
    BLEAppearanceBloodPressureArm                   = 897,
    /** Wrist Blood Pressure */
    BLEAppearanceBloodPressureWrist                 = 898,
    /** Human Interface Device (HID) */
    BLEAppearanceHIDDevice                          = 960,
    /** Keyboard */
    BLEAppearanceKeyboard                           = 961,
    /** Mouse */
    BLEAppearanceMouse                              = 962,
    /** Joystick */
    BLEAppearanceJoystick                           = 963,
    /** Gamepad */
    BLEAppearanceGamePad                            = 964,
    /** Digitizer Tablet */
    BLEAppearanceDigitizerTablet                    = 965,
    /** Card Read */
    BLEAppearanceCardReader                         = 966,
    /** Digital Pen */
    BLEAppearanceDigitalPen                         = 967,
    /** Barcode Scanner */
    BLEAppearanceBarcodeScanner                     = 968,
    /** Generic Glucose Meter */
    BLEAppearanceGeneric_GlucoseMeter               = 1024,
    /** Generic Running/Walking Sensor */
    BLEAppearanceGeneric_RunningWalkingSensor       = 1088,
    /** In Shoe Running/Walking Sensor */
    BLEAppearanceRunningWalkingSensorInShoe         = 1089,
    /** On Shoe Running/Walking Sensor */
    BLEAppearanceRunningWalkingSensorOnShoe         = 1090,
    /** On Hip Running/Walking Sensor */
    BLEAppearanceRunningWalkingSensorOnHip          = 1091,
    /** Generic Cycling */
    BLEAppearanceGeneric_Cycling                    = 1152,
    /** Cycling Computer */
    BLEAppearanceCyclingComputer                    = 1153,
    /** Cycling Speed Senspr */
    BLEAppearanceCyclingSpeedSensor                 = 1154,
    /** Cycling Cadence Sensor */
    BLEAppearanceCyclingCadenceSensor               = 1155,
    /** Cycling Power Sensor */
    BLEAppearanceCyclingPowerSensor                 = 1156,
    /** Cycling Speed and Cadence Sensor */
    BLEAppearanceCyclingSpeedCadenceSensor          = 1157,
    /** Generic Pulse Oximeter */
    BLEAppearanceGeneric_PulseOximeter              = 3136,
    /** Fingertip Pulse Oximeter */
    BLEAppearancePulseOximeterFingerTip             = 3137,
    /** Wrist Worn Pulse Oximeter */
    BLEAppearancePulseOximeterWristWorn             = 3138,
    /** Generic Outdoor */
    BLEAppearanceGeneric_Outdoor                    = 5184,
    /** Outdoor Location Display Device */
    BLEAppearanceOutdoorLocationDisplay             = 5185,
    /** Outdoor Location and Navigation Display Device */
    BLEAppearanceOutdoorLocationNavigationDisplay   = 5186,
    /** Outdoor Location Pod */
    BLEAppearanceLocationPOD                        = 5187,
    /** Outdoor Location and Navigation Pod */
    BLEAppearanceLocationNavigationPOD              = 5188
};


/**
 Describes the Alert Category ID Values
 
 @since 2.0
 */
typedef NS_ENUM(UInt8, BLEAlertCategory) {
    /** BLE Alert Category ID = Simple Alert: General text alert or non-text alert */
    BLEAlertCategorySimpleAlert           = 0,
    /** BLE Alert Category ID = Email: Alert when Email messages arrives */
    BLEAlertCategoryEmail                 = 1,
    /** BLE Alert Category ID = News: News feeds such as RSS, Atom */
    BLEAlertCategoryNews                  = 2,
    /** BLE Alert Category ID = Call: Incoming call */
    BLEAlertCategoryCall                  = 3,
    /** BLE Alert Category ID = Missed call: Missed Call */
    BLEAlertCategoryMissedCalled          = 4,
    /** BLE Alert Category ID = SMS/MMS: SMS/MMS message arrives */
    BLEAlertCategorySMS_MMS               = 5,
    /** BLE Alert Category ID = Voice mail: Voice mail */
    BLEAlertCategoryVoiceMail             = 6,
    /** BLE Alert Category ID = Schedule: Alert occurred on calendar, planner */
    BLEAlertCategorySchedule              = 7,
    /** BLE Alert Category ID = High Prioritized Alert: Alert that should be handled as high priority */
    BLEAlertCategoryHighPrioritizedAlert  = 8,
    /** BLE Alert Category ID = Instant Message: Alert for incoming instant messages */
    BLEAlertCategoryInstantMessage        = 9,
};

/**
 The Alert Level characteristic defines the level of alert.
 
 The level of an alert a device is to sound
 
 @since 2.0
 */
typedef NS_ENUM(UInt8, BLEAlertLevel) {
    /** BLE Alert Level None - NO Alert */
    BLEAlertLevelNone       = 0,
    /** BLE Alert Level Mild - Mild Alert */
    BLEAlertLevelMild       = 1,
    /** BLE Alert Level High - High Alert */
    BLEAlertLevelHigh       = 2
};

/**
 The Command ID for the Control point of the Alert Notification server.
 
 This represents the first octet of the Alert Notification Control Point
 
 @since 2.0
 */
typedef NS_ENUM(UInt8, BLEAlertCommand) {
    /** BLE Alert Command ID - Enable New Incoming Alert Notification */
    BLEAlertCommandEnableNewIncoming        = 0,
    /** BLE Alert Command ID - Enable Unread Category Status Notification */
    BLEAlertCommandEnableUnread             = 1,
    /** BLE Alert Command ID - Disable New Incoming Alert Notification */
    BLEAlertCommandDisableNewIncoming       = 2,
    /** BLE Alert Command ID - Disable Unread Category Status Notification */
    BLEAlertCommandDisableUnread            = 3,
    /** BLE Alert Command ID - Notify New Incoming Alert immediately */
    BLEAlertCommandNotifyNewIncoming        = 4,
    /** BLE Alert Command ID - Notify Unread Category Status immediately */
    BLEAlertCommandNotifyUnread             = 5,
};



/**
 Defines the BLE Barometric Pressure Trend.
 
 @since 2.0
 */
typedef NS_ENUM(UInt8, BLEBarometricPressure) {
    /** BLE Barometric Pressure Trend - Unknown */
    BLEBarometricPressureUnknown                = 0,
    /** BLE Barometric Pressure Trend - Continuously falling */
    BLEBarometricPressureContinuouslyFailing    = 1,
    /** BLE Barometric Pressure Trend - Continuously rising */
    BLEBarometricPressureContinuouslyRising     = 2,
    /** BLE Barometric Pressure Trend - Falling, then steady */
    BLEBarometricPressureFalling                = 3,
    /** BLE Barometric Pressure Trend - Rising, then steady */
    BLEBarometricPressureRising                 = 4,
    /** BLE Barometric Pressure Trend - Falling before a lesser rise */
    BLEBarometricPressureFallingLesserRise      = 5,
    /** BLE Barometric Pressure Trend - Falling before a greater rise */
    BLEBarometricPressureFallingGreaterRise     = 6,
    /** BLE Barometric Pressure Trend - Rising before a greater fall */
    BLEBarometricPressureRisingGreaterFall      = 7,
    /** BLE Barometric Pressure Trend - Rising before a lesser fall */
    BLEBarometricPressureRisingLesserFall       = 8,
    /** BLE Barometric Pressure Trend - Steady */
    BLEBarometricPressureSteady                 = 9
};


/**
 Defines the BLE Glucose Concentration Type.
 
 @since 2.0
 */
typedef NS_ENUM(UInt8, BLEBGlucoseConcentrationType) {
    /** BLE Glucose Concentration Type - Reserved */
    BLEBGlucoseConcentrationTypeReserved                = 0,
    /** BLE Glucose Concentration Type - Capillary Whole blood */
    BLEBGlucoseConcentrationTypeCapillaryWhole          = 1,
    /** BLE Glucose Concentration Type - Capillary Plasma */
    BLEBGlucoseConcentrationTypeCapillaryPlasma         = 2,
    /** BLE Glucose Concentration Type - Venous Whole blood */
    BLEBGlucoseConcentrationTypeVenousWhole             = 3,
    /** BLE Glucose Concentration Type - Venous Plasma */
    BLEBGlucoseConcentrationTypeVenousPlasma            = 4,
    /** BLE Glucose Concentration Type - Arterial Whole blood */
    BLEBGlucoseConcentrationTypeArterialWhole           = 5,
    /** BLE Glucose Concentration Type - Arterial Plasma */
    BLEBGlucoseConcentrationTypeArterialPlasma          = 6,
    /** BLE Glucose Concentration Type - Undetermined Whole blood */
    BLEBGlucoseConcentrationTypeUndeterminedWhole       = 7,
    /** BLE Glucose Concentration Type - Undetermined Plasma */
    BLEBGlucoseConcentrationTypeUndeterminedPlasma      = 8,
    /** BLE Glucose Concentration Type - Interstitial Fluid (ISF) */
    BLEBGlucoseConcentrationTypeInterstitialFluid       = 9,
    /** BLE Glucose Concentration Type - Control Solution */
    BLEBGlucoseConcentrationTypeControlSolution         = 10,
};


/**
 Defines the BLE DST Offset.
 
 @since 2.0
 */
typedef NS_OPTIONS(UInt8, BLEDaylightSavingsOffset) {
    /** BLE DST Offset - Standard Time */
    BLEDaylightSavingsOffsetStandard            = 0,
    /** BLE DST Offset - Half An Hour Daylight Time (+0.5h) */
    BLEDaylightSavingsOffsetHalfHourDaylight    = 2,
    /** BLE DST Offset - Daylight Time (+1h) */
    BLEDaylightSavingsOffsetDaylight            = 4,
    /** BLE DST Offset - Double Daylight Time (+2h) */
    BLEDaylightSavingsOffsetDoubleDaylight      = 8
};

/**
 Defines the BLE Sport Type for Aerobic and Anaerobic Thresholds.
 
 @since 2.0
 */
typedef NS_OPTIONS(UInt8, BLESportTypeThreshold) {
    /** BLE Sport Type for Aerobic and Anaerobic Thresholds - Unknown */
    BLESportTypeThresholdUnknown                 = 0,
    /** BLE Sport Type for Aerobic and Anaerobic Thresholds - Running (Treadmill) */
    BLESportTypeThresholdRunning                 = 1,
    /** BLE Sport Type for Aerobic and Anaerobic Thresholds - Cycling (Ergometer) */
    BLESportTypeThresholdCycling                 = 2,
    /** BLE Sport Type for Aerobic and Anaerobic Thresholds - Rowing (Ergometer)  */
    BLESportTypeThresholdRowing                  = 3,
    /** BLE Sport Type for Aerobic and Anaerobic Thresholds - Cross Training (Elliptical) */
    BLESportTypeThresholdCrossTraining           = 4,
    /** BLE Sport Type for Aerobic and Anaerobic Thresholds - Climbing */
    BLESportTypeThresholdClimbing                = 5,
    /** BLE Sport Type for Aerobic and Anaerobic Thresholds - Skiing */
    BLESportTypeThresholdSkiing                  = 6,
    /** BLE Sport Type for Aerobic and Anaerobic Thresholds - Skating */
    BLESportTypeThresholdSkating                 = 7,
    /** BLE Sport Type for Aerobic and Anaerobic Thresholds - Arm exercising */
    BLESportTypeThresholdArm                     = 8,
    /** BLE Sport Type for Aerobic and Anaerobic Thresholds - Lower body exercising */
    BLESportTypeThresholdLowerBody               = 9,
    /** BLE Sport Type for Aerobic and Anaerobic Thresholds - Upper body exercising */
    BLESportTypeThresholdUpperBody               = 10,
    /** BLE Sport Type for Aerobic and Anaerobic Thresholds - Whole body exercising */
    BLESportTypeThresholdWholeBody               = 11,
};

/**
 Defines the BLE Temperature Type.
 
 @since 2.0
 */
typedef NS_OPTIONS(UInt8, BLETemperatureType) {
    /** BLE Temperature Type - Reserved for future use */
    BLETemperatureTypeReserved          = 0,
    /** BLE Temperature Type - Armpit */
    BLETemperatureTypeArmpit            = 1,
    /** BLE Temperature Type - Body (general) */
    BLETemperatureTypeBody              = 2,
    /** BLE Temperature Type - Ear (usually ear lobe) */
    BLETemperatureTypeEar               = 3,
    /** BLE Temperature Type - Finger */
    BLETemperatureTypeFinger            = 4,
    /** BLE Temperature Type - Gastro-intestinal Tract */
    BLETemperatureTypeGastro            = 5,
    /** BLE Temperature Type - Mouth */
    BLETemperatureTypeMouth             = 6,
    /** BLE Temperature Type - Rectum */
    BLETemperatureTypeRectum            = 7,
    /** BLE Temperature Type - Toe */
    BLETemperatureTypeToe               = 8,
    /** BLE Temperature Type - Tympanum (ear drum) */
    BLETemperatureTypeTympanum          = 9,
};


/**
 Defines the BLE Time Source.
 
 @since 2.0
 */
typedef NS_OPTIONS(UInt8, BLETimeSource) {
    /** BLE Time Source - Unknown */
    BLETimeSourceUnknown                = 0,
    /** BLE Time Source - Network Time Protocol */
    BLETimeSourceNetworkTimeProtocol    = 1,
    /** BLE Time Source - GPS */
    BLETimeSourceGPS                    = 2,
    /** BLE Time Source - Radio Time Signal */
    BLETimeSourceRadioTimeSignal        = 3,
    /** BLE Time Source - Manual */
    BLETimeSourceManual                 = 4,
    /** BLE Time Source - Atomic Clock */
    BLETimeSourceAtomicClock            = 5,
    /** BLE Time Source - Cellular Network */
    BLETimeSourceCellularNetwork        = 6
};


