//
//  NPESensors.h
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

#import <NpeGate/NPESensorLocationProtocol.h>
#import <NpeGate/NPEEventSensorData.h>
#import <NpeGate/NPEEventSensorSignal.h>
#import <NpeGate/NPESensorSetting.h>
#import <NpeGate/NPESensorImage.h>
#import <NpeGate/NPESensorConnection.h>
#import <NpeGate/NPESensorConnectionDelegate.h>
#import <NpeGate/NPESensorCommandQueue.h>
#import <NpeGate/NPESensorCommandSettings.h>
#import <NpeGate/NPEBikeCadenceConnection.h>
#import <NpeGate/NPESensorData.h>
#import <NpeGate/NPEBeaconConnection.h>
#import <NpeGate/NPEBeaconData.h>
#import <NpeGate/NPEBikeData.h>
#import <NpeGate/NPEBikeCadenceData.h>
#import <NpeGate/NPEBikePowerConnection.h>
#import <NpeGate/NPEBikePowerCrankTorqueData.h>
#import <NpeGate/NPEBikePowerCTFData.h>
#import <NpeGate/NPEBikePowerData.h>
#import <NpeGate/NPEBikePowerPowerOnlyData.h>
#import <NpeGate/NPEBikePowerWheelTorqueData.h>
#import <NpeGate/NPEkickrConnection.h>
#import <NpeGate/NPEKickrResponseData.h>
#import <NpeGate/NPEBikeSpeedCadenceConnection.h>
#import <NpeGate/NPEBikeSpeedCadenceData.h>
#import <NpeGate/NPEBikeSpeedConnection.h>
#import <NpeGate/NPEBikeSpeedData.h>
#import <NpeGate/NPEBloodPressureConnection.h>
#import <NpeGate/NPEBloodPressureData.h>
#import <NpeGate/NPECommonData.h>
#import <NpeGate/NPECommonDataError.h>
#import <NpeGate/NPECommonDataPairedDevice.h>
#import <NpeGate/NPEAccelConnection.h>
#import <NpeGate/NPEAccelData.h>
#import <NpeGate/NPEEnvironmentalConnection.h>
#import <NpeGate/NPEEnvironmentalData.h>
#import <NpeGate/NPEFitnessEquipmentConnection.h>
#import <NpeGate/NPEFitnessEquipmentData.h>
#import <NpeGate/NPEFootpodConnection.h>
#import <NpeGate/NPEFootpodData.h>
#import <NpeGate/NPEActivityConnection.h>
#import <NpeGate/NPEActivityData.h>
#import <NpeGate/NPEPedometerConnection.h>
#import <NpeGate/NPEPedometerData.h>
#import <NpeGate/NPEMoxConnection.h>
#import <NpeGate/NPEMoxData.h>
#import <NpeGate/NPECustomConnection.h>
#import <NpeGate/NPECustomData.h>
#import <NpeGate/NPEAeroConnection.h>
#import <NpeGate/NPEAeroData.h>
#import <NpeGate/NPEGeoCacheConnection.h>
#import <NpeGate/NPEGeoCacheData.h>
#import <NpeGate/NPEHeartrateConnection.h>
#import <NpeGate/NPEHeartrateData.h>
#import <NpeGate/NPEPairingPodConnection.h>
#import <NpeGate/NPEPairingPodData.h>
#import <NpeGate/NPEFrConnection.h>
#import <NpeGate/NPEFrData.h>
#import <NpeGate/NPEWeightScaleConnection.h>
#import <NpeGate/NPEWeightScaleData.h>
#import <NpeGate/NPEInfiltrometerConnection.h>
#import <NpeGate/NPEInfiltrometerSensorData.h>
#import <NpeGate/NPEBikeSuspensionConnection.h>
#import <NpeGate/NPEBikeSuspensionData.h>
#import <NpeGate/NPEBikeSuspensionDeviceData.h>
#import <NpeGate/NPEBikeSarisHubConnection.h>
#import <NpeGate/NPEBikeSarisHubData.h>
#import <NpeGate/NPEBikeSarisPowerBeamConnection.h>
#import <NpeGate/NPEBikeSarisPowerBeamData.h>
#import <NpeGate/NPERunningDynamicsConnection.h>
#import <NpeGate/NPERunningDynamicsData.h>
#import <NpeGate/NPEOTAFirmwareConnection.h>
#import <NpeGate/NPENikeConnection.h>
#import <NpeGate/NPENikeData.h>
#import <NpeGate/NPEUnknownConnection.h>
#import <NpeGate/NPEUnknownData.h>
#import <NpeGate/NPESensorFilter.h>
