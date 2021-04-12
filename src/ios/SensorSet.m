//
//  SensorSet.m
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

#import "SensorSet.h"

@interface SensorSet () {
    NSMutableArray *_sensors;
}
@property (nonatomic, strong) NSString *name;

@end

@implementation SensorSet

- (instancetype)initWithName:(NSString *)name {
    self = [super init];
    
    if (self != nil) {
        _name = [name copy];
        _sensors = [[NSMutableArray alloc] init];
    }
    
    return self;
}

- (instancetype)init {
    return [self initWithName:@"Unknown"];
}

- (void)addSensorsObject:(NPESensorConnection *)sensor {
    
    if (sensor != nil) {
        [_sensors addObject:sensor];
    }
}

- (void)removeSensorsObject:(NPESensorConnection *)sensor {
    
    if ([_sensors containsObject:sensor]) {
        [_sensors removeObject:sensor];
    }
}

@end
