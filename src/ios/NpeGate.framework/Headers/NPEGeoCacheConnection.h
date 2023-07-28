//
//  NPEGeoCacheConnection.h
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

NS_ASSUME_NONNULL_BEGIN
///---------------------------------------------------------------------------------------
/// Sensor Command Keys
///
/// Support Common Commands:
///  NPESensorCmdKeyPingTest
///  NPESensorCmdKeyRequestManufacturerInfo
///  NPESensorCmdKeyRequestVersionInfo
///  NPESensorCmdKeyRequestBatteryStatus
///
///---------------------------------------------------------------------------------------

/** Command Key to Requst Page One */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyRequestPageOne;
/** Command Key to Request a Specific Page Number */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyRequestPageN;
/** Command Key to Request to Get all Programmed Pages */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyGetProgrammedPages;
/** Command Key to Set the PIN  */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeySetPin;
/** Command Key to Set the Identification  */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeySetIdentification;


///---------------------------------------------------------------------------------------
/// Sensor Command Parameter Keys
///
/// Support Common Command Parameter Keys:
///     NPESensorCommandParameterKeyPings
///---------------------------------------------------------------------------------------
/** Sensor Data Parameter Key - GeoCache Page Number */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeyPageNumber;
/** Sensor Data Parameter Key - GeoCache Identification */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeyIdentification;
/** Sensor Data Parameter Key - GeoCache PIN Number */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeyPinNumber;


/**
 * Represents a connection to an ANT+ GeoCache sensor.
 */
@interface NPEGeoCacheConnection : NPESensorConnection


@end
NS_ASSUME_NONNULL_END
