//
//  NPEWeightScaleConnection.h
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
#import <NpeGate/NPESensorConnection.h>

/**
 * Describes user profile data for the weight scale.
 */
typedef struct
{
    /** User profile ID number. */
    uint16_t userProfileId;
    /** User's gender. */
    uint8_t  gender;
    /** User's age. */
    uint8_t  age;
    /** User's height (in cm). */
    uint8_t  height;
    /** <b>TRUE</b> if user is an athlete. */
    BOOL   athlete;
    /** User's activity level */
    uint8_t  activityLevel;
    
} NPEWeightScaleUserProfileStruct;


/**
 * Represents a connection to an ANT+ Weight Scale sensor.
 */
@interface NPEWeightScaleConnection : NPESensorConnection

/**
 * Sends a user profile message to the Weight Scale sensor with the user
 * profile data specified in the ::NPEWeightScaleUserProfileStruct structure.
 *
 * @param pstData A ::NPEWeightScaleUserProfileStruct structure containing the
 * user profile information to be sent to the sensor.
 *
 * @return <b>TRUE</b> if the user profile message was sent successfully,
 * otherwise <b>FALSE</b>.
 */
- (BOOL)setWeightScaleUserProfile:(NPEWeightScaleUserProfileStruct *)pstData;

/**
 *
 * Initiates an ANT-FS session with the weight scale for the purpose of transfering 
 * the files stored on the weight scale relating to weight scale measurements.
 */
- (void)requestWeightScaleFiles;

@end
