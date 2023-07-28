//
//  NPECustomData.h
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


///---------------------------------------------------------------------------------------
/// Sensor Data Parameter Keys
///
/// See also: NPECommonData
///---------------------------------------------------------------------------------------


/**
 * Represents the data available from the ANT+ Custom sensor.
 *
 * ANT+ sensors send data in multiple packets.  The NPECustomData
 * combines this data into a single entity.  The data represents the latest of
 * each data type sent from the sensor.
 */
@interface NPECustomData : NPESensorData

@property (nonatomic, readonly) NSArray *dataArray;

@end
