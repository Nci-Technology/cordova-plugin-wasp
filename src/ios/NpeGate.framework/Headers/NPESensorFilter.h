//
//  NPESensorFilter.h
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
#import <NpeGate/npe_hardware_connector_types.h>

/**
 Sesnor Filter Object

 Allows for filtering of sensors
 */
@interface NPESensorFilter : NSObject


/**
 Creates a Filter for All Device Numbers of Sensor Type

 @param type Sensor Type
 @return NPESensorFilter Instance
 @since 3.0
 */
+ (instancetype)initWithDeviceType:(NPESensorType)type;

/**
 Creates a Filter for Devices of Sensor Type and Specific Device Number

 @param type Sensor Type
 @param number Sensor Device Number
 @return NPESensorFilter Instance
 @since 3.0
 */
+ (instancetype)initWithDeviceType:(NPESensorType)type deviceNumber:(NSInteger)number;


/**
 The Sensor Type to filter on

 Using a sensor type of <i>NPESensorTypeNone</i> will allow any type of Sensor to be decoded.

 @since 3.0
 */
@property (nonatomic, readonly) NPESensorType type;

/**
 The Device Number to filter on

 Using a device number of <b>0</b> will allow any Sensor of the <b>type</b> to be decoded.

 @since 3.0
 */
@property (nonatomic, readonly) NSInteger deviceNumber;

@end
