//
//  NPEBLEServices.h
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

NS_ASSUME_NONNULL_BEGIN

typedef NSString * BLEServices;

///---------------------------------------------------------------------------------------
/// @name BLE Services
///
/// Defines the Well known BLE Services
///
///---------------------------------------------------------------------------------------

/** BLE Alert Notificaiton Service. org.bluetooth.service.alert_notification */
FOUNDATION_EXPORT BLEServices const BLEServicesAlertNotificationService;
/** BLE Automation IO Service. org.bluetooth.service.automation_io */
FOUNDATION_EXPORT BLEServices const BLEServicesAutomationIOService;
/** BLE Battery Service. org.bluetooth.service.battery_service */
FOUNDATION_EXPORT BLEServices const BLEServicesBatteryService;
/** BLE Blood Pressure. org.bluetooth.service.blood_pressure */
FOUNDATION_EXPORT BLEServices const BLEServicesBloodPressure;
/** BLE Body Composition. org.bluetooth.service.body_composition */
FOUNDATION_EXPORT BLEServices const BLEServicesBodyComposition;
/** BLE Bond Management. org.bluetooth.service.bond_management */
FOUNDATION_EXPORT BLEServices const BLEServicesBondManagement;
/** BLE Continuous Glucose Monitoring. org.bluetooth.service.continuous_glucose_monitoring */
FOUNDATION_EXPORT BLEServices const BLEServicesGlucoseContinuous;
/** BLE Current Time Service. org.bluetooth.service.current_time */
FOUNDATION_EXPORT BLEServices const BLEServicesCurrentTime;
/** BLE Cycling Power. org.bluetooth.service.cycling_power */
FOUNDATION_EXPORT BLEServices const BLEServicesCyclingPower;
/** BLE Cycling Speed and Cadence. org.bluetooth.service.cycling_speed_and_cadence */
FOUNDATION_EXPORT BLEServices const BLEServicesCyclingSpeedCadence;
/** BLE Device Information. org.bluetooth.service.device_information */
FOUNDATION_EXPORT BLEServices const BLEServicesDeviceInformation;
/** BLE Environmental Sensing. org.bluetooth.service.environmental_sensing */
FOUNDATION_EXPORT BLEServices const BLEServicesEnvironmental;
/** BLE Generic Access. org.bluetooth.service.generic_access */
FOUNDATION_EXPORT BLEServices const BLEServicesGenericAccess;
/** BLE Generic Attribute. org.bluetooth.service.generic_attribute */
FOUNDATION_EXPORT BLEServices const BLEServicesGenericAttribute;
/** BLE Glucose. org.bluetooth.service.glucose */
FOUNDATION_EXPORT BLEServices const BLEServicesGlucose;
/** BLE Health Thermometer. org.bluetooth.service.health_thermometer */
FOUNDATION_EXPORT BLEServices const BLEServicesHealthThermometer;
/** BLE Heart rate. org.bluetooth.service.heart_rate */
FOUNDATION_EXPORT BLEServices const BLEServicesHeartRate;
/** BLE Human Interface Device (HID). org.bluetooth.service.human_interface_device */
FOUNDATION_EXPORT BLEServices const BLEServicesHumanInterfaceDevice;
/** BLE Immediate Alert. org.bluetooth.service.immediate_alert */
FOUNDATION_EXPORT BLEServices const BLEServicesImmediateAlert;
/** BLE Indoor Positioning. org.bluetooth.service.indoor_positioning */
FOUNDATION_EXPORT BLEServices const BLEServicesIndoorPositioning;
/** BLE Internet Protocol Support. org.bluetooth.service.internet_protocol_support */
FOUNDATION_EXPORT BLEServices const BLEServicesInternetProtocolSupport;
/** BLE Loss Link. org.bluetooth.service.link_loss */
FOUNDATION_EXPORT BLEServices const BLEServicesLossLink;
/** BLE Location and Navigation. org.bluetooth.service.location_and_navigation */
FOUNDATION_EXPORT BLEServices const BLEServicesLocationNavigation;
/** BLE Next DST Change Service. org.bluetooth.service.next_dst_change */
FOUNDATION_EXPORT BLEServices const BLEServicesNextDSTChangeService;
/** BLE Object Transfer Service. org.bluetooth.service.object_transfer */
FOUNDATION_EXPORT BLEServices const BLEServicesObjectTransferService;
/** BLE Phone Alert Status Service. org.bluetooth.service.phone_alert_status */
FOUNDATION_EXPORT BLEServices const BLEServicesPhoneAlertStatusService;
/** BLE Pulse Oximeter Service.  org.bluetooth.service.pulse_oximeter */
FOUNDATION_EXPORT BLEServices const BLEServicesPulseOximeterService;
/** BLE Reference Time Update Service. org.bluetooth.service.reference_time_update */
FOUNDATION_EXPORT BLEServices const BLEServicesReferenceTimeUpdate;
/** BLE Running Speed and Cadence. org.bluetooth.service.running_speed_and_cadence */
FOUNDATION_EXPORT BLEServices const BLEServicesRunningSpeedCadence;
/** BLE Scan Parameters. org.bluetooth.service.scan_parameters */
FOUNDATION_EXPORT BLEServices const BLEServicesScanParameters;
/** BLE Transport Discovery. org.bluetooth.service.transport_discovery */
FOUNDATION_EXPORT BLEServices const BLEServicesTransportDiscoveryService;
/** BLE Transmit Power. org.bluetooth.service.tx_power */
FOUNDATION_EXPORT BLEServices const BLEServicesTXPower;
/** BLE User Data. org.bluetooth.service.user_data */
FOUNDATION_EXPORT BLEServices const BLEServicesUserData;
/** BLE Weight Scale. org.bluetooth.service.weight_scale */
FOUNDATION_EXPORT BLEServices const BLEServicesWeightScale;

///---------------------------------------------------------------------------------------
/// @name BLE Other Services
///
/// Defines the Other BLE Services
///
///---------------------------------------------------------------------------------------

/** Apple Bluetooth Low Energy MIDI Service */
FOUNDATION_EXPORT BLEServices const BLEServicesAppleMidiService;
/** BLE Apple HAP (Home Kit) Pairing Service */
FOUNDATION_EXPORT BLEServices const BLEServicesHAPPairingService;
/** BLE Apple HAP (Home Kit) Accessory Info Service */
FOUNDATION_EXPORT BLEServices const BLEServicesHAPAccessoryInfoService;
/** BLE UriBeacon Service */
FOUNDATION_EXPORT BLEServices const BLEServicesUriBeaconService;
/** BLE EddyStone Service */
FOUNDATION_EXPORT BLEServices const BLEServicesEddyStoneBeaconService;
/** BLE Dropcam Service */
FOUNDATION_EXPORT BLEServices const BLEServicesDropcam;
/** BLE North Pole Engineering Serial Service */
FOUNDATION_EXPORT BLEServices const BLEServicesNPESerial;
/** BLE Cable Configuration. com.npe-inc.service.cable_config */
FOUNDATION_EXPORT BLEServices const BLEServicesCableConfiguration;
/** BLE BLAST IMU Configuration. com.npe-inc.service.blast_imu_config */
FOUNDATION_EXPORT BLEServices const BLEServicesBlastImuService;
/** BLE BLAST DFU. com.npe-inc.service.blast_dfu*/
FOUNDATION_EXPORT BLEServices const BLEServicesBlastDfuService;

/**
 Defines the BLE Services.  Both the well known BLE Services and other.
 */
@interface NPEBLEServices : NSObject

/**
 String value for BLE Service UUID
 
 @param serviceUUID The Service UUID
 @returns A String value for the serviceUUID
 @since 2.0
 */
+ (NSString *)nameForBLEService:(BLEServices)serviceUUID;

@end
NS_ASSUME_NONNULL_END
