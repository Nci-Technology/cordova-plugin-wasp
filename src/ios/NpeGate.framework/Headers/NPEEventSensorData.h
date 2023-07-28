//
//  NPEEventSensorData.h
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
#import <NpeGate/NPEEvent.h>
#import <NpeGate/npe_hardware_connector_types.h>

/**
 The NPEEventSensorData Object represents a Data Event for the Sensor.
 
 It provides information about a Data Event and how many times it has occurred
 
 @since 2.1
 */
@interface NPEEventSensorData : NPEEvent

/**
 The name of the page.

 For SensorData Events the name will be the ANT Page Number or the BLE Advertisment Flag (0xFF - Manufacturer Specific Data or 0x16 Service Data)

 @since 2.1
 @note Default is a HEX Value
 */
@property (nonatomic, readonly, nonnull) NSString *pageName;

/**
 The Raw data for the Event
 
 @since 2.1
 */
@property (nonatomic, readonly, nonnull) NSData *data;

/**
 Provides a Total Received Bytes

 @since 2.1
 */
@property (nonatomic, readonly) NSUInteger totalBytesReceived;

/**
 The Sensor Protocol which the Data came in as.
 
 @since 2.1
 */
@property (nonatomic, readonly) NPESensorProtocolType dataProtocol;

@end
