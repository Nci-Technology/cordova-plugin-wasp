//
//  WTSimAntData.h
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
#import <NpeGate/npe_hardware_connector_types.h>

@class Wasp;

NS_ASSUME_NONNULL_BEGIN
///---------------------------------------------------------------------------------------
/// SIM Data Notification
///---------------------------------------------------------------------------------------
FOUNDATION_EXPORT NSString * const NPE_NOTIFICATION_SIM_WASP_QUERY_RESP_REQ;
FOUNDATION_EXPORT NSString * const NPE_NOTIFICATION_SIM_WASP_CONFIG_UPDATED;


/**
 Defines the type of simulated Data to send
 */
typedef NS_ENUM(NSInteger, WTSimDataType) {
    WTSimDataTypeANT,
    WTSimDataTypeBLEAdvert
};


@interface WTSimAntData : NSObject

/**
 * Returns the singleton WTSimAntData instance.
 *
 * The WTSimAntData is enforced as a singleton.
 * This method may be used to obtain a reference to that instance.  If the
 * instance does not yet exist when this method is invoked, it will be created.
 *
 * @return The WTSimAntData singleton instance.
 */
+ (WTSimAntData *)sharedConnector;

@property (nonatomic, readonly) BOOL bConnected;
@property (nonatomic, readonly) NSArray *radioTypes;
@property (nonatomic, strong) NSArray *routeIP;
@property (nonatomic, strong) NSArray *routePort;
@property (nonatomic, assign) WTMsgType msgType;
@property (nonatomic, assign) BOOL bPacketSaver;
@property (nonatomic, assign) BOOL bEncrypted;
@property (nonatomic, assign) BOOL bIncludeMac;
@property (nonatomic, assign) BOOL bIncludeChecksum;
@property (nonatomic, assign) BOOL bGenConstantData;
@property (nonatomic, assign) int  batteryLevel;
@property (nonatomic, assign) float batteryPercentage;
@property (nonatomic, assign) BOOL bPowered;
@property (nonatomic, assign) BOOL bCharging;


-(void)sendAntData:(NSData *)data;

/**
 Sends Simulated Data of a specific data type
 
 @param dataType The type of simulated data to send
 @param data The payload of the data
 @since 2.0
 */
- (void)sendSimulatedType:(WTSimDataType)dataType withData:(NSData *)data;


-(void)sendQueryResp:(NSData *)data;

-(NSString * _Nullable)dataForElement:(NSString *)element;
-(void)setConfig:(NSData *)data;
-(void)resetToDefaults;

@end
NS_ASSUME_NONNULL_END
