//
//  NPEANTDefines.h
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
 ANT Device Types
 
 @since 2.0.6
 */
typedef NS_ENUM(UInt8, NPEAntDeviceType) {
    /** Defines RESERVED type */
    NPEAntDeviceTypeReserved                    = 0x00,
    /** Defines a Sync Device type */
    NPEAntDeviceTypeSync                        = 0x01,
    /** Defines a Custom ANT Device type */
    NPEAntDeviceTypeCustom                      = 0x02,
    /** Defines The ANT+ Suunto Heartrate type */
    NPEAntDeviceTypeSuuntoHeartRate             = 0x04,
    /** Defines The ANT Saris Hub type */
    NPEAntDeviceTypeBikeSarisHub                = 0x08,
    /** Defines The ANT+ Bike Power Device type */
    NPEAntDeviceTypeBikePower                   = 0x0B,
    /** Defines The ANT+ Aerostick Device type */
    NPEAntDeviceTypeAeroStick                   = 0x0C,
    /** Defines The ANT+ Multi-Sport Speed Distance Device type */
    NPEAntDeviceTypeMultiSportSpeedDistance     = 0x0F,
    /** Defines The ANT+ Controls Device type */
    NPEAntDeviceTypeControls                    = 0x10,
    /** Defines The ANT+ Fitness Equipment Device type */
    NPEAntDeviceTypeFitnessEquipment            = 0x11,
    /** Defines The ANT+ Blood Pressure Device type */
    NPEAntDeviceTypeBloodPressure               = 0x12,
    /** Defines The ANT+ GecoCache Device type */
    NPEAntDeviceTypeGeoCache                    = 0x13,
    /** Defines The ANT+ Light Electric Vehicle (LEV) Device type */
    NPEAntDeviceTypeLightElectricVehicle        = 0x14,
    /** Defines The ANT+ Activity Monitor Device type */
    NPEAntDeviceTypeActivityMonitor             = 0x15,
    /** Defines The ANT Fore Runner Watch Device type */
    NPEAntDeviceTypeForeRunnerWatch             = NPEAntDeviceTypeActivityMonitor,
    /** Defines The ANT Saris PowerBeam type */
    NPEAntDeviceTypeBikeSarisPowerBeam          = 0x18,
    /** Defines The ANT+ Environment Device type */
    NPEAntDeviceTypeEnvironment                 = 0x19,
    /** Defines The ANT+ Racquet Device type */
    NPEAntDeviceTypeRacquet                     = 0x1A,
    /** Defines the ANT+ pressure sensor array */
    NPEAntDeviceTypePressureSensorArray         = 0x1C,
    /** Defines the ANT+ Running Dynamics, HR-Running Dynamics Device Type */
    NPEAntDeviceTypeRunningDynamics             = 0x1E,
    /** Defines The ANT+ Muscle Oxygen Device type */
    NPEAntDeviceTypeMuscleOxygen                = 0x1F,
    /** Defines the ANT+ Bike Shifting Device Type */
    NPEAntDeviceTypeBikeShifting                = 0x22,
    /** Defines The ANT+ Bike Lights Device type */
    NPEAntDeviceTypeBikeLight                   = 0x23,
    /** Defines The ANT+ Bike Lights Device Search for Main type */
    NPEAntDeviceTypeBikeLightSearchMain         = 0x24,
    /** Defines The ANT+ Bike Radar Device type */
    NPEAntDeviceTypeBikeRadar                   = 0x28,
    /** Defines the ANT+ Tracker */
    NPEAntDeviceTypeTracker                     = 0x29,
    /** Defines The ANT+ NPE Pairing Pod Device type */
    NPEAntDeviceTypeNpePairingPod               = 0x31,
    /** Defines The ANT+ Pedometer Device type */
    NPEAntDeviceTypePedometer                   = 0x32,
    /** Defines The ANT+ Accel Device type */
    NPEAntDeviceTypeAccel                       = 0x4C,
    /** Defines the ANT+ Bike Dropper Seatpost Device Type */
    NPEAntDeviceTypeBikeDropperSeatpost         = 0x73,
    /** Defines the ANT+ Bike Suspension Device Type */
    NPEAntDeviceTypeBikeSuspension              = 0x74,
    /** Defines The ANT+ Weight Scale type */
    NPEAntDeviceTypeWeightScale                 = 0x77,
    /** Defines The ANT+ Heartrate type */
    NPEAntDeviceTypeHeartRate                   = 0x78,
    /** Defines The ANT+ Bike Speed and Cadence type */
    NPEAntDeviceTypeBikeSpeedCadence            = 0x79,
    /** Defines The ANT+ Bike Cadence Device type */
    NPEAntDeviceTypeBikeCadence                 = 0x7A,
    /** Defines The ANT+ Bike Speed Device type */
    NPEAntDeviceTypeBikeSpeed                   = 0x7B,
    /** Defines the ANT+ Stride Based Speed Distance (Footpod) Device type */
    NPEAntDeviceTypeStrideBasedSpeedDistance    = 0x7C,
    /** Defines the Infiltrometer Device type */
    NPEAntDeviceTypeInfiltrometer               = 0x7D,
};


/**
 Defines the ANT+ Transmission types
 */
typedef NS_ENUM(NSUInteger, NPEAntTransType) {
    /** Device is in pairing Search (0x00) */
    NPEAntTransTypePairingSearch	= 0,
    /** Device uses Common Pages (0x05) */
    NPEAntTransTypeCommonPages		= 5,
    /** KICKR Transmission (0xA5) */
    NPEAntTransTypeKICKR			= 165
};
