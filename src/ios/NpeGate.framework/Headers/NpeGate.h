//
//  NpeGate.h
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
/*
 
 REQUIRED OS Versions:
 iOS7 is required for this framework

 
 REQUIRED iOS SDK Frameworks
 ---------------------------
 
 The WASP Sensor Kit Framework requires that you include the following frameworks to work correctly.
 
 - SystemConfiguration.framework
 - Security.framework
 - CoreBluetooth.framework
 - libz.dylib
 */

#import <Foundation/Foundation.h>

#import <NpeGate/NPEAttributes.h>
#import <NpeGate/NPELogEvents.h>
#import <NpeGate/NPEANT.h>
#import <NpeGate/NPEBLE.h>
#import <NpeGate/NPESensors.h>
#import <NpeGate/NPEUnitTypeIdentifiers.h>
#import <NpeGate/npe_hardware_connector_types.h>
#import <NpeGate/NPEDevicePacketProtocol.h>
#import <NpeGate/NPEEvent.h>
#import <NpeGate/Wasp.h>
#import <NpeGate/WaspBattery.h>
#import <NpeGate/WaspNetQuality.h>
#import <NpeGate/WaspRouteSocket.h>
#import <NpeGate/WaspRadio.h>
#import <NpeGate/WaspRadioCapabilities.h>
#import <NpeGate/WaspRadioChannel.h>
#import <NpeGate/NPEWaspPoeDistressBeacon.h>
#import <NpeGate/NPEFirmwareBundle.h>
#import <NpeGate/NPECmdQueueMsg.h>
#import <NpeGate/NPEConnectorSettings.h>
#import <NpeGate/NPEHardwareConnector.h>
#import <NpeGate/NPEHardwareConnectorDelegate.h>
#import <NpeGate/PageData.h>
#import <NpeGate/AccessPoint.h>
#import <NpeGate/WTCaptureData.h>
#import <NpeGate/WTSimAntData.h>
#import <NpeGate/NPEReachability.h>
#import <NpeGate/NPEManufacturer.h>

