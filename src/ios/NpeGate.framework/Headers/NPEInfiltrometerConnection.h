//
//  NPEInfiltrometerConnection.h
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

#import <NpeGate/NPESensorConnection.h>

@class NPEInfiltrometerSensorData;

NS_ASSUME_NONNULL_BEGIN
///---------------------------------------------------------------------------------------
/// Sensor Command Keys
///
/// Supports Common Commands:
///    NPESensorCmdKeySetTime
///    NPESensorCmdKeyRequestFiles
///    NPESensorCmdKeyRequestTime
///
///---------------------------------------------------------------------------------------
/** Sensor Command Key for Erasing Infiltrometer */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeySetInfiltrometerErase;
/** Sensor Command Key for Setting Longitude */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeySetLongitude;
/** Sensor Command Key for Setting Latitude */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeySetLatitude;
/** Sensor Command Key for Setting Tank Parameters */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeySetTankParams;
/** Sensor Command Key for Setting Location Name */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeySetLocationName;
/** Sensor Command Key for Setting Set Bulk And Initial Moisture */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeySetBulkAndInitalMoisture;
/** Sensor Command Key for Requesting Longitude */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyRequestLongitude;
/** Sensor Command Key for Requesting Latitude */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyRequestLatitude;
/** Sensor Command Key for Requesting Tank Parameters */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyRequestTankParameters;
/** Sensor Command Key for Requesting Location Name */
FOUNDATION_EXPORT NPESensorCmdKey const NPESensorCmdKeyRequestLocationName;


///---------------------------------------------------------------------------------------
/// Sensor Command Parameter Keys
///---------------------------------------------------------------------------------------
/** Sensor Command Parameter Key for Setting the Tank Radius */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeyTankRadius;
/** Sensor Command Parameter Key for Setting the Tube Diameter */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeyTubeDiameter;
/** Sensor Command Parameter Key for Setting Plant Depth */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeyPlantDepth;
/** Sensor Command Parameter Key for Setting Longitude */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeyLongitude;
/** Sensor Command Parameter Key for Setting Latitude */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeyLatitude;
/** Sensor Command Parameter Key for Setting Moisture Level */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeyMoisture;
/** Sensor Command Parameter Key for Setting Bulk */
FOUNDATION_EXPORT NPESensorCommandParameterKey const NPESensorCommandParameterKeyBulk;


/**
 * Represents a connection to an ANT-FS Up Stream Technologies Infiltrometer sensor.
 */
@interface NPEInfiltrometerConnection : NPESensorConnection

@end
NS_ASSUME_NONNULL_END
