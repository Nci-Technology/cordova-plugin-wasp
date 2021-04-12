//
//  NPEBeaconData.h
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

@class NPEBLEAdvertisement;


NS_ASSUME_NONNULL_BEGIN
///---------------------------------------------------------------------------------------
/// Sensor Data Parameter Keys
///
/// Supports Common Data Parameter Keys:
///   NPESensorDataParameterKeyRawData
///
/// See also: NPECommonData
///---------------------------------------------------------------------------------------
/** Defines the Sensor Data Parameter Key for the Beacon Region  */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyBeaconRegion;
/** Defines the Sensor Data Parameter Key for the Beacons Manufacturer */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyBeaconManufacturer;
/** Defines the Sensor Data Parameter Key for the Beacons Measured Power - Calibrated Tx Power */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyBeaconMeasuredPower;


///---------------------------------------------------------------------------------------
/// iBeacon Sensor Data Parameter Keys
///---------------------------------------------------------------------------------------
/** Defines the Sensor Data Parameter Key for the Apple iBeacon Proximity UUID  */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyiBeaconProximityUUID;
/** Defines the Sensor Data Parameter Key for the Apple iBeacon Major ID  */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyiBeaconMajorID;
/** Defines the Sensor Data Parameter Key for the Apple iBeacon Minor ID  */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyiBeaconMinorID;


///---------------------------------------------------------------------------------------
/// Eddystone Sensor Data Parameter Keys
///---------------------------------------------------------------------------------------
/** Defines the Sensor Data Parameter Key for the Eddystone Frame ID  */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyEddystoneFrameType;
/** Defines the Sensor Data Parameter Key for the Eddystone UID Namespace  */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyEddystoneUIDNamespace;
/** Defines the Sensor Data Parameter Key for the Eddystone UID Instance  */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyEddystoneUIDInstance;
/** Defines the Sensor Data Parameter Key for the Eddystone TLM Temperature */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyEddystoneTemperature;
/** Defines the Sensor Data Parmeter Key for the Eddystone TLM Advertising PDU Count */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyEddystonePacketCount;
/*** Defines the Sensor Data Parmeter Key for the Eddystone Time since power-on or Reboot */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyEddystoneUptime;

///---------------------------------------------------------------------------------------
/// AltBeacon Sensor Data Parameter Keys
///---------------------------------------------------------------------------------------
/*** Defines the Sensor Data Parmeter Key for the AltBeacon Beacon Organizational Unit */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyAltBeaconOrganizationalUnit;
/*** Defines the Sensor Data Parmeter Key for the AltBeacon Beacon Identification Data */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyAltBeaconIdentificationData;


///---------------------------------------------------------------------------------------
/// iBeacon Proximity UUID Keys
///---------------------------------------------------------------------------------------
typedef NSString * NPEBeaconProximityUUID NPE_STRING_ENUM;

/** iBeacon Proximity UUID For North Pole Engineering */
FOUNDATION_EXPORT NPEBeaconProximityUUID const NPEBeaconProximityUUIDNorthPoleEng;
/** iBeacon Proximity UUID for Kontakt.io */
FOUNDATION_EXPORT NPEBeaconProximityUUID const NPEBeaconProximityUUIDKontakt;
/** iBeacon Proximity UUID for Estimote */
FOUNDATION_EXPORT NPEBeaconProximityUUID const NPEBeaconProximityUUIDEstimote;
/** iBeacon Proximity UUID for Radius */
FOUNDATION_EXPORT NPEBeaconProximityUUID const NPEBeaconProximityUUIDRadius;
/** iBeacon Proximity UUID for Reco */
FOUNDATION_EXPORT NPEBeaconProximityUUID const NPEBeaconProximityUUIDReco;
/** iBeacon Proximity UUID for Orange S.A. */
FOUNDATION_EXPORT NPEBeaconProximityUUID const NPEBeaconProximityUUIDOrangeSa;
/** iBeacon Proximity UUID for Beacon Bits */
FOUNDATION_EXPORT NPEBeaconProximityUUID const NPEBeaconProximityUUIDBeaconBits;
/** iBeacon Proximity UUID for Beacon Go */
FOUNDATION_EXPORT NPEBeaconProximityUUID const NPEBeaconProximityUUIDBeaconGo;
/** iBeacon Proximity UUID for Roximity */
FOUNDATION_EXPORT NPEBeaconProximityUUID const NPEBeaconProximityUUIDRoximity;
/** iBeacon Proximity UUID for eNote */
FOUNDATION_EXPORT NPEBeaconProximityUUID const NPEBeaconProximityUUIDEnote;
/** iBeacon Proximity UUID for Bright Beacon */
FOUNDATION_EXPORT NPEBeaconProximityUUID const NPEBeaconProximityUUIDBrightBeacon;
/** iBeacon Proximity UUID for Locos Lab */
FOUNDATION_EXPORT NPEBeaconProximityUUID const NPEBeaconProximityUUIDLocosLab;
/** iBeacon Proximity UUID For beaconstac */
FOUNDATION_EXPORT NPEBeaconProximityUUID const NPEBeaconProximityUUIDBeaconstac;
/** iBeacon Proximity Default UUID for Blue Sense */
FOUNDATION_EXPORT NPEBeaconProximityUUID const NPEBeaconProximityUUIDBlueSense;
/** iBeacon Proximity Default UUID for GeLo */
FOUNDATION_EXPORT NPEBeaconProximityUUID const NPEBeaconProximityUUIDGeLo;
/** iBeacon Proximity Default UUID For Essi */
FOUNDATION_EXPORT NPEBeaconProximityUUID const NPEBeaconProximityUUIDEssi;
/** iBeacon Proximity Default UUID For EKOOR-B */
FOUNDATION_EXPORT NPEBeaconProximityUUID const NPEBeaconProximityUUIDEkoorB;
/** iBeacon Proximity Default UUID For EKOOR-LR */
FOUNDATION_EXPORT NPEBeaconProximityUUID const NPEBeaconProximityUUIDEkoorLR;
/** iBeacon Proximity UUID for Brickyard Wireless */
FOUNDATION_EXPORT NPEBeaconProximityUUID const NPEBeaconProximityUUIDBrickyardWireless;


///---------------------------------------------------------------------------------------
/// Eddystone UID Keys
///---------------------------------------------------------------------------------------

typedef NSString * NPEBeaconEddyStoneUIDNamespace NPE_STRING_ENUM;

/** Eddystone UID Namespace for North Pole Engineering */
FOUNDATION_EXPORT NPEBeaconEddyStoneUIDNamespace const NPEBeaconEddyStoneUIDNamespaceNorthPoleEng;
/** Eddystone UID Namespace for EKOOR-B */
FOUNDATION_EXPORT NPEBeaconEddyStoneUIDNamespace const NPEBeaconEddyStoneUIDNamespaceEkorB;
/** Eddystone UID Namespace for EKOOR-LR */
FOUNDATION_EXPORT NPEBeaconEddyStoneUIDNamespace const NPEBeaconEddyStoneUIDNamespaceEkorLR;


/**
 Describes the NPEBeacon Region.  This is a circular region that the beacon is in
 
 @since 2.0
 */
typedef NS_ENUM(NSInteger, NPEBeaconRegion) {
    /** Beacon Region of Immediate, between 0 and 0.5 meters */
    NPEBeaconRegionImmediate,
    /** Beacon Region of Near, between 0.5 and 2 meters */
    NPEBeaconRegionNear,
    /** Beacon Region of Far, larger then 2 meters */
    NPEBeaconRegionFar,
    /** Beacon Region not able to be determined */
    NPEBeaconRegionUnknown
};

/**
 Describes the Eddystone Frame Type.

 @since 2.1
 */
typedef NS_ENUM(uint8_t, NPEEddystoneFrameType) {
    /** Eddystone Frame type of UID */
    NPEEddystoneFrameTypeUID   = 0x00,
    /** Eddystone Frame type of URL */
    NPEEddystoneFrameTypeURL   = 0x10,
    /** Eddystone Frame type of TLM */
    NPEEddystoneFrameTypeTLM   = 0x20,
    /** Eddystone Frame type of EID */
    NPEEddystoneFrameTypeEID   = 0x30,
};


/**
 Block for Observing Beacon UUID
 
 @since 2.0
 */
typedef void (^NPEBeaconUUIDObserverBlock)(NPESensorConnection *sensor, NSDictionary *parmList, NPEBLEAdvertisement *advertObj, NPEBeaconRegion region);


/**
 Represents the data available from a Beacon Sensor
 */
@interface NPEBeaconData : NPESensorData

///---------------------------------------------------------------------------------------
/// @name Eddystone encoders
///---------------------------------------------------------------------------------------

/**
 encodes Eddystone URL
 
 @param url A full URL to encode
 @returns Eddystone encoded URL
 @since 2.1.0
*/
+ (NSData * _Nullable)encodeEddystoneBeaconURL:(NSString *)url;

///---------------------------------------------------------------------------------------
/// @name Beacon Observers
///---------------------------------------------------------------------------------------

/**
 Creates a weakified Observer of Data for a specific Beacon UUID.
 
 @param observer The Observer for the data
 @uuid The Beacons UUID to start observing
 @queue The Queue which to send back the dispatch.  If set <b>nil</b> it will return on the main_queue
 @block The block to run
 @since 2.0
 */
+ (void)addSensorObserver:(id)observer forBeaconUUID:(NSString *)uuid resultsQueue:(dispatch_queue_t)queue resultsBlock:(NPEBeaconUUIDObserverBlock)block;

/**
 Removes the Observer of the Beacon UUID
 
 @param observer The observer that is removing the Observation of the key
 @param uuid The Beacons UUID to stop observing
 @since 2.0
 */
+ (void)removeSensorObserver:(id)observer forBeaconUUID:(NSString *)uuid;

@end
NS_ASSUME_NONNULL_END
