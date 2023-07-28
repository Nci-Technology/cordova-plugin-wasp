//
//  NPEBLECharacteristics.h
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

typedef NSString * BLECharacteristic;

NS_ASSUME_NONNULL_BEGIN
///---------------------------------------------------------------------------------------
/// @name BLE Characteristics
///
/// Defines the Well known BLE Characteristics
///
///---------------------------------------------------------------------------------------
/** BLE Aerobic Heart Rate Lower Limit Characteristic.  org.bluetooth.characteristic.aerobic_heart_rate_lower_limit (BPM) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicAerobicHeartRateLowerLimit;
/** BLE Aerobic Heart Rate Upper Limit Characteristic.  org.bluetooth.characteristic.aerobic_heart_rate_upper_limit (BPM) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicAerobicHeartRateUpperLimit;
/** BLE Aerobic Threshold Characteristic.  org.bluetooth.characteristic.aerobic_threshold (BPM) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicAerobicThreshold;
/** BLE Age Characteristic.  org.bluetooth.characteristic.age (Age) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicAge;
/** BLE Aggregate Characteristic.  org.bluetooth.characteristic.aggregate */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicAggregate;
/** BLE Alert Category ID Characteristic.  org.bluetooth.characteristic.alert_category_id (BLEAlertCategory enum) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicAlertCategoryID;
/** BLE Alert Category ID Bit Mask Characteristic.  org.bluetooth.characteristic.alert_category_id_bit_mask () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicAlertCategoryIDBitMask;
/** BLE Alert Level Characteristic.  org.bluetooth.characteristic.alert_level (BLEAlertLevel enum) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicAlertLevel;
/** BLE Alert Notification Control Point Characteristic.  org.bluetooth.characteristic.alert_notification_control_point (BLEAlertCommand enum) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicAlertNotificationControlPoint;
/** BLE Alert Status Characteristic.  org.bluetooth.characteristic.alert_status () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicAlertStatus;
/** BLE Altitude Characteristic.  org.bluetooth.characteristic.altitude () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicAltitude;
/** BLE Anaerobic Heart Rate Lower Limit Characteristic.  org.bluetooth.characteristic.anaerobic_heart_rate_lower_limit (BPM) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicAnaerobicHeartRateLowerLimit;
/** BLE Anaerobic Heart Rate Upper Limit Characteristic.  org.bluetooth.characteristic.anaerobic_heart_rate_upper_limit (BPM) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicAnaerobicHeartRateUpperLimit;
/** BLE Anaerobic Threshold Characteristic.  org.bluetooth.characteristic.anaerobic_threshold (BPM) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicAnaerobicThreshold;
/** BLE Apparent Wind Direction Characteristic.  org.bluetooth.characteristic.apparent_wind_direction (Degrees) 0 - 359.99 */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicApparentWindDirection;
/** BLE Apparent Wind Speed Characteristic.  org.bluetooth.characteristic.apparent_wind_speed (m/s) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicApparentWindSpeed;
/** BLE Appearance Characteristic.  org.bluetooth.characteristic.gap.appearance (BLEAppearance enum) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicAppearance;
/** BLE Barometric Pressure Trend Characteristic.  org.bluetooth.characteristic.barometric_pressure_trend (BLEBarometricPressure enum) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicBarometricPressureTrend;
/** BLE Battery Level Characteristic. org.bluetooth.characteristic.battery_level (PERCENTAGE) 0-100% */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicBatteryLevel;
/** BLE Blood Pressure Feature Characteristic. org.bluetooth.characteristic.blood_pressure_feature () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicBloodPressureFeature;
/** BLE Blood Pressure Measurement Characteristic. org.bluetooth.characteristic.blood_pressure_measurement () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicBloodPressureMeasurement;
/** BLE Body Composition Feature Characteristic. org.bluetooth.characteristic.body_composition_feature () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicBodyCompositionFeature;
/** BLE Body Composition Measurement Characteristic. org.bluetooth.characteristic.body_composition_measurement () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicBodyCompositionMeasurement;
/** BLE Body Sensor Location Characteristic. org.bluetooth.characteristic.body_sensor_location () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicBodySensorLocation;
/** BLE Bond Management Control Point Characteristic. org.bluetooth.characteristic.bond_management_control_point () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicBondManagementControlPoint;
/** BLE Bond Management Features Characteristic. org.bluetooth.characteristic.bond_management_feature () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicBondManagementFeatures;
/** BLE Boot Keyboard Input Report Characteristic. org.bluetooth.characteristic.boot_keyboard_input_report () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicBootKeyboardInputReport;
/** BLE Boot Keyboard Output Report Characteristic. org.bluetooth.characteristic.boot_keyboard_output_report () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicBootKeyboardOutputReport;
/** BLE Boot Mouse Output Report Characteristic. org.bluetooth.characteristic.boot_mouse_input_report () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicBootMouseInputReport;
/** BLE Central Address Resolution Characteristic. org.bluetooth.characteristic.gap.central_address_resolution () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicCentralAddressResolution;
/** BLE CGM Feature Characteristic. org.bluetooth.characteristic.cgm_feature () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicCGMFeature;
/** BLE CGM Measurement Characteristic. org.bluetooth.characteristic.cgm_measurement () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicCGMMeasurement;
/** BLE CGM Session Run Time Characteristic. org.bluetooth.characteristic.cgm_session_run_time () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicCGMSessionRunTime;
/** BLE CGM Session Start Time Characteristic. org.bluetooth.characteristic.cgm_session_start_time () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicCGMSessionStartTime;
/** BLE CGM Specific Ops Control Point Characteristic. org.bluetooth.characteristic.cgm_specific_ops_control_point () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicCGMSpecificOpsControlPoint;
/** BLE CGM Status Characteristic. org.bluetooth.characteristic.cgm_status () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicCGMStatus;
/** BLE CSC Feature Characteristic. org.bluetooth.characteristic.csc_feature () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicCSCFeature;
/** BLE CSC Measurement Characteristic. org.bluetooth.characteristic.csc_measurement () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicCSCMeasurement;
/** BLE Current Time Characteristic. org.bluetooth.characteristic.current_time () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicCurrentTime;
/** BLE Cycling Power Control Point Characteristic. org.bluetooth.characteristic.cycling_power_control_point () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicCyclingPowerControlPoint;
/** BLE Cycling Power Feature Characteristic. org.bluetooth.characteristic.cycling_power_feature () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicCyclingPowerFeature;
/** BLE Cycling Power Measurement Characteristic. org.bluetooth.characteristic.cycling_power_measurement () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicCyclingPowerMeasurement;
/** BLE Cycling Power Vector Characteristic. org.bluetooth.characteristic.cycling_power_vector () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicCyclingPowerVector;
/** BLE Database Change Increment Characteristic. org.bluetooth.characteristic.database_change_increment () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicDatabaseChangeIncrement;
/** BLE Date of Birth Characteristic. org.bluetooth.characteristic.date_of_birth () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicDateOfBirth;
/** BLE Date of Threshold Assessment Characteristic. org.bluetooth.characteristic.date_of_threshold_assessment () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicDateOfThresholdAssessment;
/** BLE Date Time Characteristic. org.bluetooth.characteristic.date_time () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicDateTime;
/** BLE Day Date Time Characteristic. org.bluetooth.characteristic.day_date_time () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicDayDateTime;
/** BLE Day of Week Characteristic. org.bluetooth.characteristic.day_of_week () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicDayOfWeek;
/** BLE Descriptor Value Changed Characteristic. org.bluetooth.characteristic.descriptor_value_changed () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicDescriptorValueChanged;
/** BLE Device Name Characteristic. org.bluetooth.characteristic.gap.device_name (UTF-8 String) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicDeviceName;
/** BLE Dew Point Characteristic. org.bluetooth.characteristic.dew_point (degrees celsius) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicDewPoint;
/** BLE Digital Characteristic. org.bluetooth.characteristic.digital () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicDigital;
/** BLE DST Offset Characteristic. org.bluetooth.characteristic.dst_offset () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicDSTOffset;
/** BLE Elevation Characteristic. org.bluetooth.characteristic.elevation (meters) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicElevation;
/** BLE Email Address Characteristic. org.bluetooth.characteristic.email_address (UTF-8 String) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicEmailAddress;
/** BLE Exact Time 256 Characteristic. org.bluetooth.characteristic.exact_time_256 () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicExactTime256;
/** BLE Fat Burn Heart Rate Lower Limit Characteristic. org.bluetooth.characteristic.fat_burn_heart_rate_lower_limit (BPM) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicFatBurnHeartRateLowerLimit;
/** BLE Fat Burn Heart Rate Upper Limit Characteristic. org.bluetooth.characteristic.fat_burn_heart_rate_upper_limit (BPM) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicFatBurnHeartRateUpperLimit;
/** BLE Firmware Revision String Characteristic. org.bluetooth.characteristic.firmware_revision_string (UTF-8 string) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicFirmwareRevisionString;
/** BLE First Name Characteristic. org.bluetooth.characteristic.first_name (UTF-8 string) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicFirstName;
/** BLE Five Zone Heart Rate Limits Characteristic. org.bluetooth.characteristic.five_zone_heart_rate_limits () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicFiveZoneHeartRateLimits;
/** BLE Floor Number Characteristic. org.bluetooth.characteristic.floor_number (0-255) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicFloorNumber;
/** BLE Gender Characteristic. org.bluetooth.characteristic.gender () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicGender;
/** BLE Glucose Feature Characteristic. org.bluetooth.characteristic.glucose_feature () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicGlucoseFeature;
/** BLE Glucose Measurement Characteristic. org.bluetooth.characteristic.glucose_measurement () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicGlucoseMeasurement;
/** BLE Glucose Measurement Context Characteristic.  org.bluetooth.characteristic.glucose_measurement_context () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicGlucoseMeasurementContext;
/** BLE Gust Factor Characteristic.  org.bluetooth.characteristic.gust_factor () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicGustFactor;
/** BLE Hardware Revision String Characteristic.  org.bluetooth.characteristic.hardware_revision_string (UTF-8 String) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicHardwareRevisionString;
/** BLE Heart Rate Control Point Characteristic.  org.bluetooth.characteristic.heart_rate_control_point () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicHeartRateControlPoint;
/** BLE Heart Rate Max Characteristic.  org.bluetooth.characteristic.heart_rate_max (BPM) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicHeartRateMax;
/** BLE Heart Rate Measurement Characteristic.  org.bluetooth.characteristic.heart_rate_measurement () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicHeartRateMeasurement;
/** BLE Heat Index Characteristic.  org.bluetooth.characteristic.heat_index (degrees celsius) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicHeatIndex;
/** BLE Height Characteristic.  org.bluetooth.characteristic.height (meters) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicHeight;
/** BLE HID Control Point Characteristic. org.bluetooth.characteristic.hid_control_point () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicHIDControlPoint;
/** BLE HID Information Characteristic. org.bluetooth.characteristic.hid_information () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicHIDInformation;
/** BLE Hip Circumference Characteristic. org.bluetooth.characteristic.hip_circumference (meters) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicHipCircumference;
/** BLE HTTP Control Point Characteristic. org.bluetooth.characteristic.http_control_point (uint8) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicHTTPControlPoint;
/** BLE HTTP Entity Body Characteristic. org.bluetooth.characteristic.http_entity_body (UTF-8 string) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicHTTPEntityBody;
/** BLE HTTP Headers Characteristic. org.bluetooth.characteristic.http_headers (UTF-8 string) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicHTTPHeaders;
/** BLE HTTP Status Code Characteristic. org.bluetooth.characteristic.http_status_code (uint8) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicHTTPStatusCode;
/** BLE HTTPS Security Characteristic. org.bluetooth.characteristic.https_security (boolean) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicHTTPSSecurity;
/** BLE Humidity Characteristic. org.bluetooth.characteristic.humidity (percent) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicHumidity;
/** BLE IEEE 11073-20601 Regulatory Certification Data List Characteristic. org.bluetooth.characteristic.ieee_11073-20601_regulatory_certification_data_list () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicIEEERegulatoryCertificationDataList;
/** BLE Indoor Positioning Configuration Characteristic. org.bluetooth.characteristic.indoor_positioning_configuration () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicIndoorPositioningConfiguration;
/** BLE Intermediate Cuff Pressure Characteristic. org.bluetooth.characteristic.intermediate_cuff_pressure () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicIntermediateCuffPressure;
/** BLE Intermediate Temperature Characteristic. org.bluetooth.characteristic.intermediate_temperature () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicIntermediateTemperature;
/** BLE Irradiance Characteristic. org.bluetooth.characteristic.irradiance (watt per square meter) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicIrradiance;
/** BLE Language Characteristic. org.bluetooth.characteristic.language (UTF-8 String) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicLanguage;
/** BLE Last Name Characteristic. org.bluetooth.characteristic.last_name (UTF-8 String) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicLastName;
/** BLE Latitude Characteristic. org.bluetooth.characteristic.latitude (WGS84 North coordinate) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicLatitude;
/** BLE LN Control Point Characteristic. org.bluetooth.characteristic.ln_control_point () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicLNControlPoint;
/** BLE LN Feature Characteristic. org.bluetooth.characteristic.ln_feature () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicLNFeature;
/** BLE Local East Coordinate Characteristic. org.bluetooth.characteristic.local_east_coordinate () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicLocalEastCoordinate;
/** BLE Local North Coordinate Characteristic. org.bluetooth.characteristic.local_north_coordinate () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicLocalNorthCoordinate;
/** BLE Local Time Information Characteristic. org.bluetooth.characteristic.local_time_information () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicLocalTimeInformation;
/** BLE Location and Speed Characteristic. org.bluetooth.characteristic.location_and_speed () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicLocationAndSpeedCharacteristic;
/** BLE Location Name Characteristic. org.bluetooth.characteristic.location_name (UTF-8 String) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicLocationName;
/** BLE Longitude Characteristic. org.bluetooth.characteristic.Longitude (WGS84 East coordinate) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicLongitude;
/** BLE Magnetic Declination Characteristic. org.bluetooth.characteristic.magnetic_declination (degrees) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicMagneticDeclination;
/** BLE Magnetic Flux Density - 2D Characteristic. org.bluetooth.characteristic.Magnetic_flux_density_2D (tesla) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicMagneticFluxDensity2D;
/** BLE Magnetic Flux Density - 3D Characteristic. org.bluetooth.characteristic.Magnetic_flux_density_3D (tesla) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicMagneticFluxDensity3D;
/** BLE Manufacturer Name String Characteristic. org.bluetooth.characteristic.manufacturer_name_string (UTF-8 String) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicManufacturerNameString;
/** BLE Maximum Recommended Heart Rate Characteristic. org.bluetooth.characteristic.maximum_recommended_heart_rate (BPM) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicMaximumRecommendedHeartRate;
/** BLE Measurement Interval Characteristic. org.bluetooth.characteristic.measurement_interval (1-65535 seconds) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicMeasurementInterval;
/** BLE Model Number String Characteristic. org.bluetooth.characteristic.model_number_string (UTF-8 String) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicModelNumberString;
/** BLE Navigation Characteristic. org.bluetooth.characteristic.navigation () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicNavigation;
/** BLE New Alert Characteristic. org.bluetooth.characteristic.new_alert () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicNewAlert;
/** BLE Peripheral Preferred Connection Parameters Characteristic. org.bluetooth.characteristic.gap.peripheral_preferred_connection_parameters () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicPeripheralPreferredConnectionParameters;
/** BLE Peripheral Privacy Flag Characteristic. org.bluetooth.characteristic.gap.peripheral_privacy_flag (BOOL) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicPeripheralPrivacyFlag;
/** BLE PLX Continuous Measurement Characteristic. org.bluetooth.characteristic.plx_continuous_measurement () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicPLXContinuousMeasurement;
/** BLE PLX Features Characteristic. org.bluetooth.characteristic.plx_features () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicPLXFeatures;
/** BLE PLX Spot-Check Measurement Characteristic. org.bluetooth.characteristic.plx_spot_check_measurement () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicPLXSpotCheckMeasurement;
/** BLE PnP ID Characteristic. org.bluetooth.characteristic.pnp_id () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicPnPID;
/** BLE Pollen Concentration Characteristic. org.bluetooth.characteristic.pollen_concentration (concentration count per cubic meter) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicPollenConcentration;
/** BLE Position Quality Characteristic. org.bluetooth.characteristic.position_quality () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicPositionQuality;
/** BLE Pressure Characteristic. org.bluetooth.characteristic.pressure (pascals) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicPressure;
/** BLE Protocol Mode Characteristic. org.bluetooth.characteristic.protocol_mode () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicProtocolMode;
/** BLE Rainfall Characteristic. org.bluetooth.characteristic.rainfall (meters) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicRainfall;
/** BLE Reconnection Address Characteristic. org.bluetooth.characteristic.gap.reconnection_address () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicReconnectionAddress;
/** BLE Record Access Control Point Characteristic. org.bluetooth.characteristic.record_access_control_point () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicRecordAccessControlPoint;
/** BLE Reference Time Information Characteristic. org.bluetooth.characteristic.reference_time_information () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicReferenceTimeInformation;
/** BLE Report Characteristic. org.bluetooth.characteristic.report () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicReport;
/** BLE Report Map Characteristic. org.bluetooth.characteristic.report_map () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicReportMap;
/** BLE Resting Heart Rate Characteristic. org.bluetooth.characteristic.resting_heart_rate (BPM) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicRestingHeartRate;
/** BLE Ringer Control point Characteristic. org.bluetooth.characteristic.ringer_control_point (enum) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicRingerControlPoint;
/** BLE Ringer Setting Characteristic. org.bluetooth.characteristic.ringer_setting () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicRingerSetting;
/** BLE RSC Feature Characteristic. org.bluetooth.characteristic.rsc_feature () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicRSCFeature;
/** BLE RSC Measurement Characteristic. org.bluetooth.characteristic.rsc_measurement () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicRSCMeasurement;
/** BLE SC Control Point Characteristic. org.bluetooth.characteristic.sc_control_point () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicSCControlPoint;
/** BLE Scan Interval Window Characteristic. org.bluetooth.characteristic.scan_interval_window () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicScanIntervalWindow;
/** BLE Scan Refresh Characteristic. org.bluetooth.characteristic.scan_refresh () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicScanRefresh;
/** BLE Sensor Location Characteristic. org.bluetooth.characteristic.sensor_location () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicSensorLocation;
/** BLE Serial Number String Characteristic. org.bluetooth.characteristic.serial_number_string (UTF-8 String) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicSerialNumberString;
/** BLE Service Changed Characteristic. org.bluetooth.characteristic.gatt.service_changed () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicServiceChanged;
/** BLE Software Revision String Characteristic. org.bluetooth.characteristic.software_revision_string (UTF-8 String) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicSoftwareRevisionString;
/** BLE Sport Type for Aerobic and Anaerobic Thresholds Characteristic. org.bluetooth.characteristic.sport_type_for_aerobic_and_anaerobic_thresholds (BLESportTypeThreshold) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicSportTypeAerobicAnaerobicThresholds;
/** BLE Supported New Alert Category Characteristic. org.bluetooth.characteristic.supported_new_alert_category () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicSupportedNewAlertCategory;
/** BLE Supported Unread Alert Category Characteristic. org.bluetooth.characteristic.supported_unread_alert_category () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicSupportedUnreadAlertCategory;
/** BLE System ID Characteristic. org.bluetooth.characteristic.system_id () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicSystemID;
/** BLE Temperature Characteristic. org.bluetooth.characteristic.temperature () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicTemperature;
/** BLE Temperature Measurement Characteristic. org.bluetooth.characteristic.temperature_measurement () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicTemperatureMeasurement;
/** BLE Temperature Type Characteristic. org.bluetooth.characteristic.temperature_type (BLETemperatureType) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicTemperatureType;
/** BLE Three Zone Heart Rate Limits Characteristic. org.bluetooth.characteristic.three_zone_heart_rate_limits () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicThreeZoneHeartRateLimits;
/** BLE Time Accuracy Characteristic. org.bluetooth.characteristic.time_accuracy () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicTimeAccuracy;
/** BLE Time Source Characteristic. org.bluetooth.characteristic.time_accuracy (BLETimeSource) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicTimeSource;
/** BLE Time Update Control Point Characteristic. org.bluetooth.characteristic.time_update_control_point () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicTimeUpdateControlPoint;
/** BLE Time Update State Characteristic. org.bluetooth.characteristic.time_update_state () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicTimeUpdateState;
/** BLE Time with DST Characteristic. org.bluetooth.characteristic.time_with_dst () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicTimeWithDST;
/** BLE Time Zone Characteristic. org.bluetooth.characteristic.time_zone () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicTimeZone;
/** BLE True Wind Direction Characteristic. org.bluetooth.characteristic.true_wind_direction (degrees) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicTrueWindDirection;
/** BLE True Wind Speed Characteristic. org.bluetooth.characteristic.true_wind_speed (meters per second) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicTrueWindSpeed;
/** BLE Two Zone Heart Rate Limit Characteristic. org.bluetooth.characteristic.two_zone_heart_rate_limit (BPM) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicTwoZoneHeartRateLimit;
/** BLE Tx Power Level Characteristic. org.bluetooth.characteristic.tx_power_level (db -100 to 20) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicTxPowerLevel;
/** BLE Uncertainty Characteristic. org.bluetooth.characteristic.uncertainty () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicUncertainty;
/** BLE Unread Alert Status Characteristic. org.bluetooth.characteristic.unread_alert_status () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicUnreadAlertStatus;
/** BLE User Control Point Characteristic. org.bluetooth.characteristic.user_control_point () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicUserControlPoint;
/** BLE User Index Characteristic. org.bluetooth.characteristic.user_index () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicUserIndex;
/** BLE UV Index Characteristic. org.bluetooth.characteristic.uv_index () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicUVIndex;
/** BLE VO2 Max Characteristic. org.bluetooth.characteristic.vo2_max (Milliliter per kilogram per minutes) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicVO2Max;
/** BLE Waist Circumference Characteristic. org.bluetooth.characteristic.waist_circumference (meters) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicWaistCircumference;
/** BLE Weight Characteristic. org.bluetooth.characteristic.weight (kilograms) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicWeight;
/** BLE Weight Measurement Characteristic. org.bluetooth.characteristic.weight_measurement () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicWeightMeasurement;
/** BLE Weight Scale Feature Characteristic. org.bluetooth.characteristic.weight_scale_feature () */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicWeightScaleFeature;
/** BLE Wind Chill Characteristic. org.bluetooth.characteristic.wind_chill (degrees Celsius) */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicWindChill;

///---------------------------------------------------------------------------------------
/// @name BLE Other Characteristics
///
/// Defines the Other BLE Characteristics
///
///---------------------------------------------------------------------------------------

/* Apple Bluetooth Low Energy MIDI I/O Characteristic */
FOUNDATION_EXPORT BLECharacteristic const BLECharacteristicAppleMidiIO;

@interface NPEBLECharacteristics : NSObject

/**
 String value for BLE Characteristics UUID
 
 @param characteristicsUUID The Characteristics UUID
 @returns A String value for the characteristicsUUID
 @since 2.0
 */
+ (NSString *)nameForBLECharacteristic:(BLECharacteristic)characteristicsUUID;

@end
NS_ASSUME_NONNULL_END
