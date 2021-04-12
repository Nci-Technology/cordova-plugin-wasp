//
//  GatewayManager.h
//  ShowSensorsObjc
//
//  NPEGATE SAMPLE Copyright © 2012-2016 by North Pole Engineering, Inc.  All rights reserved.
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

#import <Foundation/Foundation.h>
#import "SensorSet.h"
#import <NpeGate/NpeGate.h>


/** Notification when the SensorSets or Sensors array have new sensors added to them */
FOUNDATION_EXPORT NSString * const kNewSensorFound;


/**
 Manages the NpeGate Connection.
 Monitors for New Sesnros and Creates SensorSets of common sensors
 Maintains a Master Array of all sensors
 */
@interface GatewayManager : NSObject

+ (instancetype)sharedManager;

/**
 Hardware Connector
 */
@property (nonatomic, readonly) NPEHardwareConnector *gatewayConection;

/**
 An Array of Wasp Objects on the network
 */
@property (nonatomic, readonly) NSArray<Wasp *> *allWasps;

/**
 An Array of SensorSets, which contains a set of sensors for the NPESensorType_t's
 */
@property (nonatomic, readonly) NSArray<SensorSet *> *sensorSets;

/**
 A raw array of NPESensorConnections
 */
@property (nonatomic, readonly) NSArray<NPESensorConnection *> *sensors;

/**
 Enable / Disable post notification
 */
@property (nonatomic, assign) BOOL enablePosts;

@end
