//
//  NPELogEvents.h
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
 Log levels for the NPELogEvents
 
 @since 2.0.6
 */
typedef NS_OPTIONS(NSInteger, NPELogEventMask) {
    /** No Logging will be performed (DEFAULT).  Startup Messages are still sent */
    NPELogEventMaskNone                 = 0,
    /** NpeLog Events for General Logging informaiton */
    NPELogEventMaskDefault              = 1 << 0,
    /** NpeLog Events for Reachability Changes */
    NPELogEventMaskReachability         = 1 << 1,
    /** NpeLog Events for General WASP Information */
    NPELogEventMaskWaspInformation      = 1 << 2,
    /** NpeLog Events for Wasp Radio & Channel Informaiton */
    NPELogEventMaskWaspRadio            = 1 << 3,
    
    /** NpeLog Events for Sending Commands & Command Queue Information */
    NPELogEventMaskCommandQueue         = 1 << 4,
    /** NpeLog Events for USB */
    NPELogEventMaskUsb                  = 1 << 5,

    /** Turns on All of the Logging Events */
    NPELogEventMaskAll = ( NPELogEventMaskDefault |
                          NPELogEventMaskReachability |
                          NPELogEventMaskWaspInformation |
                          NPELogEventMaskWaspRadio |
                          NPELogEventMaskCommandQueue |
                          NPELogEventMaskUsb )
    
};

/**
 Shared Event Logger for NpeGate Framework
  
 @since 2.0.6
 */
@interface NPELogEvents : NSObject

/**
 Shared Logger singleton for the NpeGate Framework
 
 @since 2.0.6
 */
+ (NPELogEvents *) sharedLogger;

/**
 If you have the XCode Plugin XCodeColors you can see the Logs in color
 */
@property (nonatomic, assign) BOOL xcodecolors;

///---------------------------------------------------------------------------------------
/// @name Properties
///---------------------------------------------------------------------------------------
/**
 Property which determines which log information you will see in the console
 
 @since 2.0.6
 */
@property (nonatomic, assign) NPELogEventMask loggingMask;



@end
