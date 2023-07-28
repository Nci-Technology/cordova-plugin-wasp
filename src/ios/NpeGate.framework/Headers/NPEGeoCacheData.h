//
//  NPEGeoCacheData.h
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


NS_ASSUME_NONNULL_BEGIN
///---------------------------------------------------------------------------------------
/// Sensor Data Parameter Keys
///
/// Supports Common Data Parameter Keys:
///   NPESensorDataParameterKeyRawData
///
/// See also: NPECommonData
///---------------------------------------------------------------------------------------

/** Defines the Sensor Data Parameter Key for the GeoCode ID  */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyGeoCacheID;
/** Defines the Sensor Data Parameter Key for the GeoCode PIN number */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyPIN;
/** Defines the Sensor Data Parameter Key for the Authentication Token (Strin) */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyAuthenticationToken;
/** Defines the Sensor Data Parameter Key for the Last Visit Date */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyLastVistDate;
/** Defines the Sensor Data Parameter Key for the Latitude */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyLatitude;
/** Defines the Sensor Data Parameter Key for the Longitude */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyLongitude;
/** Defines the Sensor Data Parameter Key for the Next Stage Hint */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyNextStageHint;
/** Defines the Sensor Data Parameter Key for the Logged Visits */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyLoggedVisits;
/** Defines the Sensor Data Parameter Key for the Total Programmed pages */
FOUNDATION_EXPORT NPESensorDataParameterKey const NPESensorDataParameterKeyProgrammedPages;


///---------------------------------------------------------------------------------------
/// Sensor Data Constants
///---------------------------------------------------------------------------------------

/** Invalid GeoCache Pin Number */
FOUNDATION_EXPORT const NSInteger NPESensorDataInvalidGeoCachePin;


/**
 * Represents the data available from the ANT+ GeoCache sensor.
 *
 * ANT+ sensors send data in multiple packets.  The NPEGeoCacheData
 * combines this data into a single entity.  The data represents the latest of
 * each data type sent from the sensor.
 *
 * See Header Files for Sensor Data Parameter Keys
 */
@interface NPEGeoCacheData : NPESensorData

/**
 * The user-specified GeoCache ID stored on the device.
 */
@property (nonatomic, readonly, nullable) NSString *geoCacheId;

/**
 * The user-specified hint stored on the device.
 */
@property (nonatomic, readonly, nullable) NSString *hint;

/**
 * <b>TRUE</b> if the device has been authenticated, otherwise <b>FALSE</b>.
 */
@property (nonatomic, readonly) BOOL isAuthenticated;

///---------------------------------------------------------------------------------------
/// @name Lat/Lon
///---------------------------------------------------------------------------------------

/**
 * The latitude, in degrees.
 */
@property (nonatomic, readonly) double latitude;

/**
 * The longitude, in degrees.
 */
@property (nonatomic, readonly) double longitude;

///---------------------------------------------------------------------------------------
/// @name Visit data
///---------------------------------------------------------------------------------------

/**
 * The date and time the device was last visited.
 */
@property (nonatomic, readonly, nullable) NSDate *lastVisit;

/**
 * The number of visits since the device was programmed.
 */
@property (nonatomic, readonly) NSInteger numberOfVisits;

@end
NS_ASSUME_NONNULL_END
