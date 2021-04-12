//
//  NPEManufacturer.h
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
 Manufacturer Information
 */
@interface NPEManufacturer : NSObject

/**
 The Company Identification

 @since 3.0
 */
@property (nonatomic, readonly) UInt16 companyID;

/**
 Company name

 @since 3.0
 */
@property (nonatomic, readonly, nullable) NSString *name;


- (instancetype _Nonnull)init NS_UNAVAILABLE;

/**
 Creates a Manufaturer Object from the CSAFE Manufacturer ID

 @param companyid CSAFE Manufacturer ID
 @return NPEManufacturer Instance
 @since 3.0
 */
+ (NPEManufacturer * _Nonnull)createWithCsafeManufacturerIdentification:(UInt16)companyid;

/**
 Creates a Manufaturer Object from the ANT Company Identification Number

 @param companyid ANT Manufacturer ID
 @return NPEManufacturer Instance
 @since 3.0
 */
+ (NPEManufacturer * _Nonnull)createWithAntManufacturerIdentification:(UInt16)companyid;

/**
 Creates a Manufaturer Object from the BLE Company Identifier Number

 @param companyid BLE Company Assigned Number
 @return NPEManufacturer Instance
 @since 3.0
 */
+ (NPEManufacturer * _Nonnull)createWithBleCompanyIdentifier:(UInt16)companyid;


///---------------------------------------------------------------------------------------
/// @name Bluetooth Manufacturers
///---------------------------------------------------------------------------------------

/**
 Apple Inc. Manufacturer Object for Bluetooth

 @return NPEManufacturer Instance for Apple, Inc.
 @since 3.0
 */
+ (NPEManufacturer * _Nonnull)bluetoothApple;

/**
 Keiser Corporation Manufacturer Object for Bluetooth
 
 @return NPEManufacturer Instance for Keiser.
 @since 3.0
 */
+ (NPEManufacturer * _Nonnull)bluetoothKeiser;

/**
 Nike Corporation Manufacturer Object for Bluetooth
 
 @return NPEManufacturer Instance for Nike.
 @since 3.x
 */
+ (NPEManufacturer * _Nonnull)bluetoothNike;

/**
 Suunto Oy Manufacturer Object for Bluetooth

 @return NPEManufacturer Instance for Suunto.
 @since 3.0
 */
+ (NPEManufacturer * _Nonnull)bluetoothSuunto;

/**
 Polar Electro OY (Polar) Manufacturer Object for Bluetooth

 @return NPEManufacturer Instance for Polar.
 @since 3.0
 */
+ (NPEManufacturer * _Nonnull)bluetoothPolar;


///---------------------------------------------------------------------------------------
/// @name ANT Manufacturers
///---------------------------------------------------------------------------------------

/**
 Dynastream Manufacturer Object for ANT

 @return NPEManufacturer Instance for Dynastream
 @since 3.0
 */
+ (NPEManufacturer * _Nonnull)antDynastream;

/**
 Garmin Manufacturer Object for ANT

 @return NPEManufacturer Instance for Garmin
 @since 3.0
 */
+ (NPEManufacturer * _Nonnull)antGarmin;

/**
 Gopher Sport Manufacturer Object for ANT

 @return NPEManufacturer Instance for Gopher Sport
 @since 3.0
 */
+ (NPEManufacturer * _Nonnull)antGopherSport;

/**
 North Pole Engineering Manufacturer Object for ANT

 @return NPEManufacturer Instance for NPE.
 @since 3.0
 */
+ (NPEManufacturer * _Nonnull)antNorthPoleEngineering;

/**
 Saris Manufacturer Object for ANT

 @return NPEManufacturer Instance for Saris.
 @since 3.0
 */
+ (NPEManufacturer * _Nonnull)antSaris;

/**
 Scosche Manufacturer Object for ANT

 @return NPEManufacturer Instance for Scosche.
 @since 3.0
 */
+ (NPEManufacturer * _Nonnull)antScosche;

/**
 Suunto Oy Manufacturer Object for ANT

 @return NPEManufacturer Instance for Suunto.
 @since 3.0
 */
+ (NPEManufacturer * _Nonnull)antSuunto;

/**
 TiGRA Sport Manufacturer Object for ANT

 @return NPEManufacturer Instance for TiGRA Sport.
 @since 3.0
 */
+ (NPEManufacturer * _Nonnull)antTigraSport;

/**
 Quarq Manufacturer Object for ANT

 @return NPEManufacturer Instance for Quarq.
 @since 3.0
 */
+ (NPEManufacturer * _Nonnull)antQuarq;

@end
