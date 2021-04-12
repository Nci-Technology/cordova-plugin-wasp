//
//  SensorSet.h
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
#import <NpeGate/NpeGate.h>

/**
 SensorSet is a Set of NPESensorConnection Objects
 */
@interface SensorSet : NSObject


- (instancetype)initWithName:(NSString *)name NS_DESIGNATED_INITIALIZER;

/**
 The name of the Set
 */
@property (nonatomic, readonly) NSString *name;

/**
 Array of NPESensorConnection's in the Set
 */
@property (nonatomic, readonly) NSArray *sensors;

/**
 Adds a Sensor to the Set
 
 @pram sensor The NPESensorConnection
 */
- (void)addSensorsObject:(NPESensorConnection *)sensor;


/**
 Removes a Sensor to the Set
 
 @pram sensor The NPESensorConnection
 */
- (void)removeSensorsObject:(NPESensorConnection *)sensor;


@end
