//
//  NPEBLEAdvertisement.h
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
#import <NpeGate/NPEBLE.h>
#import <NpeGate/NPEDevicePacketProtocol.h>

@class NPEBLEPeerAddress;
@class NPEBLEManufacturerData;

/**
 The NPEBLEAdvertisement Object represents all of the BLE Advertisement Information provided by a Sensor
 
 @since 2.0.6
 */
@interface NPEBLEAdvertisement : NSObject <NPEDevicePacketProtocol>

/**
 Peer address of the Advertisment Packet
 
 @since 2.0.6
 */
@property (nonatomic, readonly) NPEBLEPeerAddress *peerAddress;

/**
 The GAP Advertisement type
 
 @since 2.0.6
 */
@property (nonatomic, readonly) BLEGapAdvertisingEventType eventType;

/**
 The RAW Advertisment Packet
 
 @since 2.0.6
 */
@property (nonatomic, readonly) NSData *rawAdvertismentPacket;

/**
 The BLE Advertisement Flags
 
 @since 2.0.6
 */
@property (nonatomic, readonly) BLEAdvertisementTypeFlag flags;

///---------------------------------------------------------------------------------------
/// @name Active Scan
///---------------------------------------------------------------------------------------

/**
 Determins if the current Packet is in response to an Active Scan
 
 @since 2.0.6
 */
@property (nonatomic, readonly) BOOL activeScan;

/**
 If we have received at least one active scan from the device this will be <b>TRUE</b>
 
 @since 2.0.6
 */
@property (nonatomic, readonly) BOOL receivedActiveScan;


///---------------------------------------------------------------------------------------
/// @name Service Information
///---------------------------------------------------------------------------------------

/**
 Array of BLE Services.  This will contain all 16Bit, 32Bit and 128Bit Services.
 
 @note Service Constants can be found in NPEBLEServices.h
 @since 2.0.6
 */
@property (nonatomic, readonly) NSArray<NSString *> *services;

/**
 Array of BLE Solicited Services.  This will contain all 16Bit, 32Bit and 128Bit Services.
 
 A Peripheral device may send the Service Solicitation data type to invite Central devices that expose one or more of the services specified in the Service Solicitation data to connect
 
 @note Service Constants can be found in NPEBLEServices.h
 @since 2.0.6
 */
@property (nonatomic, readonly) NSArray<NSString *> *solicitedServices;

/**
 The Service Data data type consists of a service UUID with the data associated with that service.
 
 @since 2.0.6
 */
@property (nonatomic, readonly) NSData *serviceData;


///---------------------------------------------------------------------------------------
/// @name Name Information
///---------------------------------------------------------------------------------------

/**
 The Short version of the Local Name.
 
 @since 2.0.6
 */
@property (nonatomic, readonly) NSString *shortLocalName;

/**
 The Complete version of the Local Name.
 
 @since 2.0.6
 */
@property (nonatomic, readonly) NSString *completeLocalName;

///---------------------------------------------------------------------------------------
/// @name TX Power Level
///---------------------------------------------------------------------------------------

/**
 The TX Power Level data type indicates the transmitted power level of the packet containing the data type. The TX Power Level data type may be used to calculate path loss on a received packet
 
 @since 2.0.6
 */
@property (nonatomic, readonly) SInt8 txPowerLevel;

///---------------------------------------------------------------------------------------
/// @name Security Manager OOB Flags
///---------------------------------------------------------------------------------------

/**
 The Security Manager Out of Band data type allows an out of band mechanism to be used by the Security Manager to communicate discovery information as well as other information related to the pairing process.
 
 @since 2.0.6
 */
@property (nonatomic, readonly) BLEAdvertisementOOBFlag oobFlags;


///---------------------------------------------------------------------------------------
/// @name Appearance Data
///---------------------------------------------------------------------------------------

/**
 The Appearance data type defines the external appearance of the device.
 
 @since 2.0.6
 */
@property (nonatomic, readonly) BLEAppearance appearance;

///---------------------------------------------------------------------------------------
/// @name Advertising Interval
///---------------------------------------------------------------------------------------

/**
  Advertising Interval in msec.
 
 @since 2.0.6
 */
@property (nonatomic, readonly) NSTimeInterval advertisingInterval;


///---------------------------------------------------------------------------------------
/// @name BLE Role Capabilities
///---------------------------------------------------------------------------------------

/**
 Defines the BLE role capabilities of the device
 
 @since 2.0.6
 */
@property (nonatomic, readonly) BLERole capabilities;

///---------------------------------------------------------------------------------------
/// @name Manufacturer Specific Data
///---------------------------------------------------------------------------------------

/**
 Manufacturer Specific Data portion of the Advertisment Packet
 
 @since 2.0.6
 */
@property (nonatomic, readonly) NPEBLEManufacturerData *manufacturerData;

@end
