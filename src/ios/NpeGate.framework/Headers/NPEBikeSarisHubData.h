//
//  NPEBikeSarisHubData.h
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
//  Joe Tretter
//  221 North First St. Ste. 310
//  Minneapolis, Minnesota 55401
//
//  Information contained in this software has been created or obtained by North Pole Engineering,
//  Inc. from sources believed to be reliable.  However, North Pole Engineering, Inc. does not
//  guarantee the accuracy or completeness of the information published herein nor shall
//  North Pole Engineering, Inc. be liable for any errors, omissions, or damages arising
//  from the use of this software.
//

#import <NpeGate/NpeGate.h>


@class NPEBikeSarisHubDeviceData;

///---------------------------------------------------------------------------------------
/// Sensor Data Parameter Keys
///
/// Supports Common Data Parameter Keys:
///     NPESensorDataParameterKeyRawData
///
/// See also: NPECommonData
///---------------------------------------------------------------------------------------


/**
 Saris Hub Packet Message Types
 
 @since 3.0.7
 */
typedef NS_ENUM(uint8_t, NPESarisPacketType) {
    /** Power Message */
    NPESarisPacketTypePowerMsg          = 0,
    /** Redundant Power Message */
    NPESarisPacketTypeRedundantPowerMsg = 1,
    /** PC Mode */
    NPESarisPacketTypePcMode            = 2,
    /** Information Message */
    NPESarisPacketTypeInformation       = 3
};


/**
 Represents Data for a Saris HUB Sensor
 
 @since 3.0.7
 */
@interface NPEBikeSarisHubData : NPESensorData


@end
