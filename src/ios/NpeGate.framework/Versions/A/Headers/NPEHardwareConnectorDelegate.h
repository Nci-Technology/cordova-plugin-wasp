//
//  NPEHardwareConnectorDelegate.h
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

#import <NpeGate/NPEAttributes.h>
#import <NpeGate/npe_hardware_connector_types.h>


@class NPEHardwareConnector;
@class NPESensorConnection;
@class NPEConnectorSettings;
@class Wasp;

NS_ASSUME_NONNULL_BEGIN
/**
 * The NPEHardwareConnectorDelegate protocol declares the interface that
 * NPEHardwareConnector delegates must implement.
 *
 * The NPEHardwareConnectorDelegate protocol should be adopted in classes
 * where the sensor data is processed.  It is common to adopt this protocol
 * in the same class where the NPEHardwareConnector instance is created, but
 * this is not necessary.  Sensor data updates and connection status events
 * will be delivered to the delegate.
 */
@protocol NPEHardwareConnectorDelegate <NSObject>

@optional

/**
 * Alerts the delegate that a Sensor has been found.
 *
 * The <i>connectionInfo</i> parameter may be used to determine the type
 * and identification of the sensor which was connected.
 *
 * @param hwConnector The NPEHardwareConnector instance.
 *
 * @param connectionInfo A NPESensorConnection instance that may be used to
 * determine the sensor type and manage the connection.
 */
- (void)hardwareConnector:(NPEHardwareConnector *)hwConnector connectedSensor:(NPESensorConnection *)connectionInfo __deprecated_msg("no longer supported 3.0.  Use addSensorStateChangeObserver");

/**
 * Alerts the delegate that a sensor connection has ended.
 *
 * The <i>connectionInfo</i> parameter may be used to determine the type
 * and identification of the sensor which was disconnected.
 *
 * @param hwConnector The NPEHardwareConnector instance.
 *
 * @param connectionInfo A NPESensorConnection instance that may be used to
 * determine the sensor type.
 */
- (void)hardwareConnector:(NPEHardwareConnector *)hwConnector disconnectedSensor:(NPESensorConnection *)connectionInfo __deprecated_msg("no longer supported 3.0.  Use addSensorStateChangeObserver");

/**
 * Requests settings information from the delegate.
 *
 * This method is called each time a new sensor is detected.
 * If the delegate has settings information related to the sensor it should provide it.
 */
- (void)getConnectorSettingsForDeviceData:(NPESensorConnection *)connection __deprecated_msg("no longer supported 3.0.");

/**
 Called when a new Wasp Devices is discovered on the network.
 
 @param hwConnector The NPEHardwareConnector Instance
 @param wasp The Wasp Instance
 @since 2.0
 */
- (void)hardwareConnector:(NPEHardwareConnector *)hwConnector didDiscoverWasp:(Wasp *)wasp __deprecated_msg("no longer supported 3.0");

/**
 Called when a new Wasp Devices is about to be removed from the list of found devices.  This occurs if we have not heard from the specific Wasp after a set time period.
 
 @param hwConnector The NPEHardwareConnector Instance
 @param wasp The Wasp Instance to be removed
 @since 2.0
 */
- (void)hardwareConnector:(NPEHardwareConnector *)hwConnector willRemoveWasp:(Wasp *)wasp __deprecated_msg("no longer supported 3.0");

@end
NS_ASSUME_NONNULL_END
