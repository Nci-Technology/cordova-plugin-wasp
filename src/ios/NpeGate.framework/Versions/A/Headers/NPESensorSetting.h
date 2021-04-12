//
//  NPESensorSetting.h
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


///---------------------------------------------------------------------------------------
/// Sensor Connection Settings
///---------------------------------------------------------------------------------------

/** Settings Key for Sensors Device Name */
FOUNDATION_EXPORT NSString * const NPESensorSettingsKeyDeviceName;
/** Settings Key for Wheel Circumference.  Default is 2070mm.
 Can be changed by in [NPEConnectorSettings sharedSettings] */
FOUNDATION_EXPORT NSString * const NPESensorSettingsKeyWheelCircumference;
/** Settings Key for Setting Rho Calibration */
FOUNDATION_EXPORT NSString * const NPESensorSettingsKeyCalibrationRho;


/**
 NPESensorSetting Object describes Sensor Specific Settings
 
 @since 2.1.0
 */
@interface NPESensorSetting : NSObject

/**
 String Value for the Settings Key
 
 @since 2.1.0
 */
@property (nonatomic, readonly) NSString *key;

/**
 Describes the value type for the Setting
 
 @since 2.1.0
 */
@property (nonatomic, readonly) NSString *valueType;

/**
 Placeholder value for display of the Setting
 
 @since 2.1.0
 */
@property (nonatomic, readonly) NSString *placeholder;

/**
 The NPEUnitType for the Settings Value
 
 @since 2.1.0
 */
@property (nonatomic, readonly) NSString *units;

/**
 The Value for the Setting
 
 @since 2.1.0
 */
@property (nonatomic, strong) id value;

@end
