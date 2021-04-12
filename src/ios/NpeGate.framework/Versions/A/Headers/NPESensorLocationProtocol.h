//
//  NPESensorLocationProtocol.h
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
 Provides a location of where the Sensor is located.
 
 @since 2.0
 */
typedef NS_ENUM (NSInteger, NPESensorLocation) {
    /**
     Sensor is located at an unidentified location.
     @since 2.0
     */
    NPESensorLocationOther                  = 0,
    /**
     Sensor is located on the shoe laces
     @since 2.0
     */
    NPESensorLocationLaces                  = 1001,
    /**
     Sensor is located on the Mid Sole
     @note Same as BLE Shoe
     @since 2.0
     */
    NPESensorLocationMidsole                = 1002,
    /**
     Sensor is located on the Ankle
     @since 2.0
     */
    NPESensorLocationAnkle                  = 1003,
    /**
     Sensor is located on the Foot
     @since 2.0
     */
    NPESensorLocationFoot                   = 1004,
    /**
     Sensor is located on the Left Leg
     @since 3.0
     */
    NPESensorLocationLeftLeg                = 1010,
    /**
     Sensor is located on the Right Leg
     @since 3.0
     */
    NPESensorLocationRightLeg               = 1011,
    /**
     Sensor is located on the Left Calf
     @since 3.0
     */
    NPESensorLocationLeftCalf               = 1012,
    /**
     Sensor is located on the Right Calf
     @since 3.0
     */
    NPESensorLocationRightCalf              = 1013,
    /**
     Sensor is located on the Left Shin
     @since 3.0
     */
    NPESensorLocationLeftShin               = 1014,
    /**
     Sensor is located on the Right Shin
     @since 3.0
     */
    NPESensorLocationRightShin              = 1015,
    /**
     Sensor is located on the Left Hamstring
     @since 3.0
     */
    NPESensorLocationLeftHamstring          = 1016,
    /**
     Sensor is located on the Right Hamstring
     @since 3.0
     */
    NPESensorLocationRightHamstring         = 1017,
    /**
     Sensor is located on the Left Quad
     @since 3.0
     */
    NPESensorLocationLeftQuad               = 1018,
    /**
     Sensor is located on the Right Quad
     @since 3.0
     */
    NPESensorLocationRightQuad              = 1019,

    /**
     Sensor is located on the Left Glut
     @since 3.0
     */
    NPESensorLocationLeftGlut               = 1030,
    /**
     Sensor is located on the Right Glut
     @since 3.0
     */
    NPESensorLocationRightGlut              = 1033,

    /**
     Sensor is located on the Hip
     @since 2.0
     */
    NPESensorLocationHip                    = 1100,
    /**
     Sensor is located around the Chest
     @since 2.0
     */
    NPESensorLocationChest                  = 1101,
    /**
     Sensor is located on the Left Chest
     @since 3.0
     */
    NPESensorLocationChestLeft              = 1102,
    /**
     Sensor is located on the Right Chest
     @since 3.0
     */
    NPESensorLocationChestRight             = 1103,

    /**
     Sensor is located on the Waist Mid Back
     @since 3.0
     */
    NPESensorLocationWaistMidBack           = 1110,
    /**
     Sensor is located on the Waist Front
     @since 3.0
     */
    NPESensorLocationWaistFront             = 1111,
    /**
     Sensor is located on the Waist Left
     @since 3.0
     */
    NPESensorLocationWaistLeft              = 1112,
    /**
     Sensor is located on the Waist Right
     @since 3.0
     */
    NPESensorLocationWaistRight             = 1113,

    /**
     Sensor is located on the Torso Back
     @since 3.0
     */
    NPESensorLocationTorsoBack              = 1120,
    /**
     Sensor is located on the Torso Front
     @since 3.0
     */
    NPESensorLocationTorsoFront             = 1121,

    /**
     Sensor is located on the Back
     @since 3.0
     */
    NPESensorLocationBack                   = 1130,
    /**
     Sensor is located on the Lower Left
     @since 3.0
     */
    NPESensorLocationBackLowerLeft          = 1131,
    /**
     Sensor is located on the Lower Right
     @since 3.0
     */
    NPESensorLocationBackLowerRight         = 1132,
    /**
     Sensor is located on the Upper Left
     @since 3.0
     */
    NPESensorLocationBackUpperLeft          = 1133,
    /**
     Sensor is located on the Upper Right
     @since 3.0
     */
    NPESensorLocationBackUpperRight         = 1134,

    /**
     Sensor is located on the Abdomen
     @since 3.0
     */
    NPESensorLocationAbdomen                = 1150,
    /**
     Sensor is located on the Abdomen Left
     @since 3.0
     */
    NPESensorLocationAbdomentLeft           = 1151,
    /**
     Sensor is located on the Abdomen Right
     @since 3.0
     */
    NPESensorLocationAbdomentRight          = 1152,

    /**
     Sensor is located on the Wrist
     @since 2.0
     */
    NPESensorLocationWrist                  = 1200,
    /**
     Sensor is located on the Finger
     @since 2.0
     */
    NPESensorLocationFinger                 = 1201,
    /**
     Sensor is located on the Hand
     @since 2.0
     */
    NPESensorLocationHand                   = 1202,

    /**
     Sensor is located on the Arm
     @since 3.0
     */
    NPESensorLocationArm                    = 1210,
    /**
     Sensor is located on the Arm Left
     @since 3.0
     */
    NPESensorLocationArmLeft                = 1211,
    /**
     Sensor is located on the Arm Left
     @since 3.0
     */
    NPESensorLocationArmRight               = 1212,
    /**
     Sensor is located on the Forearm
     @since 2.0
     */
    NPESensorLocationForeArm                = 1220,
    /**
     Sensor is located on the Forearm Left Anterior
     @since 3.0
     */
    NPESensorLocationForeArmLeftAnterior    = 1221,
    /**
     Sensor is located on the Forearm Right Anterior
     @since 3.0
     */
    NPESensorLocationForeArmRightAnterior   = 1222,
    /**
     Sensor is located on the Forearm Left Posterior
     @since 3.0
     */
    NPESensorLocationForeArmLeftPosterior   = 1223,
    /**
     Sensor is located on the Forearm Right Posterior
     @since 3.0
     */
    NPESensorLocationForeArmRightPosterior  = 1224,
    /**
     Sensor is located on the Bicep Left
     @since 3.0
     */
    NPESensorLocationBicepLeft              = 1225,
    /**
     Sensor is located on the Bicep Right
     @since 3.0
     */
    NPESensorLocationBicepRight             = 1226,
    /**
     Sensor is located on the Tricep Left
     @since 3.0
     */
    NPESensorLocationTricepLeft             = 1228,
    /**
     Sensor is located on the Tricep Right
     @since 3.0
     */
    NPESensorLocationTricepRight            = 1229,
    /**
     Sensor is located on the Shoulder Left
     @since 3.0
     */
    NPESensorLocationShoulderLeft           = 1230,
    /**
     Sensor is located on the Shoulder Right
     @since 3.0
     */
    NPESensorLocationShoulderRight          = 1233,

    /**
     Sensor is located on the Neck
     @since 2.0
     */
    NPESensorLocationNeck                   = 1300,
    /**
     Sensor is located on the Throat
     @since 2.0
     */
    NPESensorLocationThroat                 = 1301,
    /**
     Sensor is located on the Ear Lobe
     @since 2.0
     */
    NPESensorLocationEarLobe                = 1302,

    /**
     Sensor is located on the Front Wheel
     @since 2.0
     */
    NPESensorLocationFrontWheel             = 2000,
    /**
     Sensor is located on the Back Wheel
     @since 2.0
     */
    NPESensorLocationBackWheel              = 2001,
    /**
     Sensor is located on the Left Crank
     @since 2.0
     */
    NPESensorLocationLeftCrank              = 2003,
    /**
     Sensor is located on the Right Crank
     @since 2.0
     */
    NPESensorLocationRightCrank             = 2004,
    /**
     Sensor is located on the Left Pedal
     @since 2.0
     */
    NPESensorLocationLeftPedal              = 2005,
    /**
     Sensor is located on the Right Pedal
     @since 2.0
     */
    NPESensorLocationRightPedal             = 2006,
    /**
     Sensor is located on the Front Hub
     @since 2.0
     */
    NPESensorLocationFrontHub               = 2007,
    /**
     Sensor is located on the Back Hub
     @since 2.0
     */
    NPESensorLocationBackHub                = 2008,
    /**
     Sensor is located on the Rear Dropout
     @since 2.0
     */
    NPESensorLocationRearDropout            = 2009,
    /**
     Sensor is located on the Chainstay
     @since 2.0
     */
    NPESensorLocationChainStay              = 2010,
    /**
     Sensor is located on the Front Fork
     @since 2.0
     */
    NPESensorLocationFrontFork              = 2011,
    
};

/**
 Protocol for Sensors that provide Sensor Location Information
 
 @since 2.0
 @see NPESensorLocation
 */
@protocol NPESensorLocationProtocol <NSObject>

@required
///---------------------------------------------------------------------------------------
/// @name Sensor Location Information
///---------------------------------------------------------------------------------------

/**
 The Location of the Sensor Module.
 
 @note This uses a NPESensorLocation that is translated from the ANT/BLE location information
 @since 2.0
 */
@property (nonatomic, readonly) NPESensorLocation sensorLocation;


/**
 String Value of the Sensors location
 
 @since 2.0
 */
@property (nonatomic, readonly, copy) NSString *locationName;


@end
