//
//  NPESensorImage.h
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
 Defines the Size of the Sensor Images.  These will provide back a correctly scaled image for the display type on iOS.
 */
typedef NS_ENUM(NSInteger, SensorImageSize) {
    /** Image of size 22px */
    SensorImageSmallSize,
    /** Image for the iOS Toolbar (aprox 22px) */
    SensorImageToolBarSize = SensorImageSmallSize,
    /**Image of size 24px */
    SensorImageNormalSize,
    /** Image for the iOS Tabbar (aprox 25px) */
    SensorImageTabbarSize,
    /** Image of size 48px */
    SensorImageMediumSize,
    /** Image of size 64px */
    SensorImageLargeSize
};


#if TARGET_OS_IPHONE
#import <UIKit/UIKit.h>
@compatibility_alias GKImage UIImage;
#elif TARGET_OS_MAC
#import <AppKit/AppKit.h>
@compatibility_alias GKImage NSImage;
#endif


