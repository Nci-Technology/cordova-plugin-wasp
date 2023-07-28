//
//  NPECmdQueueMSg.h
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
#import <NpeGate/WaspRadio.h>

@class Wasp;
@class NPESensorConnection;
@class NPECmdQueueMsg;
@class WaspRadio;
@class NPESensorCommandSettings;

/**
 Defines the Queue State
 */
typedef NS_ENUM(NSInteger, WTQueueState) {
    WTQueueStateMsgUnassiged,
    WTQueueStateMsgNoControlChannel,
    /** WASP has been assigned to take care of this Command */
    WTQueueStateMsgWaspAssigned,
    /** NO Channel is Available at this time to Assign Command To */
    WTQueueStateMsgChannelNotAvailable,
    /** Set When a Channel has been Assigned to a Command */
    WTQueueStateMsgChannelAssigned,
    /** Set When the Command has been Put into the WASP Queue */
    WTQueueStateMsgSentToQueue,
    /** Set When the SDK Sends the Message to the WASP Hardware */
    WTQueueStateMsgQueueInProcess,
    /** Set When the WASP Hardware acknowledges Receipt of command */
    WTQueueStateMsgWaspAcknowledged,
    /** Set when the WASP Sends out the Command to the Sensor */
    WTQueueStateMsgWaspSentCommand,
    /** Set once Command has been Sent to Sensor and is waiting for a response */
    WTQueueStateMsgWaitingResponse,
    /** Set when we have received the correct response for Command */
    WTQueueStateMsgRcvResponse
};

typedef NS_ENUM(NSInteger, NPECmdQueueMsgType) {
    NPECmdQueueMsgTypeStandard      = 0,
    NPECmdQueueMsgTypeAtomic        = 1,
    NPECmdQueueMsgTypeExclusive     = 2,    //One Message Radio
    NPECmdQueueMsgTypeBlocking      = 3,    //One Message Per WASP
};


FOUNDATION_EXPORT const NSInteger NPECmdQueueMsgHighPriorityChannel;


/** 
 Typedef for Successful commands.
 
 @param msg Command Queue Message
 @param retries The number of Retris the command had to do
 @param roundTripTime Time in milisecons
 */
typedef void(^NPECmdQueueMsgSuccess)(NPECmdQueueMsg *msg, NSInteger retries, int roundTripTime);

/** 
 Typedef for Failed commands.

 @param msg Command Queue Message
 @param error The Error Message
 @param retries The number of Retris the command had to do
 @param roundTripTime Time in milisecons
 */
typedef void(^NPECmdQueueMsgFailBlock)(NPECmdQueueMsg *msg, NSError *error, NSInteger retries, int roundTripTime);

@interface NPECmdQueueMsg : NSObject

- (instancetype)initWithAntSensorConnection:(NPESensorConnection *)connection commandType:(NPECmdQueueMsgType)commandType settings:(NPESensorCommandSettings *)settings commandName:(NSString *)name commandData:(NSData *)msgData;

- (instancetype)initWithSensorConnection:(NPESensorConnection *)connection commandType:(NPECmdQueueMsgType)commandType radioRequirement:(RadioFirmwareMode)radioType commandName:(NSString *)name commandData:(NSData *)msgData;

/**
 Unique Identifier for the Message
 
 @since 2.0.6
 */
@property (nonatomic, readonly) NSUUID *uuid;

/**
 Creation time of the message
 */
@property (nonatomic, readonly) NSDate *creationDate;

/**
 Timestamp for last action on the Command
 */
@property (nonatomic, readonly) NSDate *lastActionTime;

/**
 Name of the Sensor Command
 */
@property (nonatomic, readonly) NSString *sensorCommand;

/**
 Current Queue State of the Command
 */
@property (nonatomic, readonly) WTQueueState queueState;

/**
 Radio Channel the Command is Queued on.
 */
@property (nonatomic, readonly) NSNumber *channel;

/**
 Command Message Data 
 */
@property (nonatomic, readonly) NSData *msgData;

/**
 WASP object that the Command is being sent to.
 */
@property (nonatomic, readonly) Wasp *wasp;

/**
 WASP Radio that the Command is being sent from.
 */
@property (nonatomic, readonly) WaspRadio *radio;

/**
 Sensor Connection Object for the Command.
 */
@property (nonatomic, readonly) NPESensorConnection *connection;

/**
 The Message Type of the command.
 */
@property (nonatomic, readonly) NPECmdQueueMsgType messageType;

///---------------------------------------------------------------------------------------
/// @name Options
///---------------------------------------------------------------------------------------

/**
 The Number of times the Command has been retried
 */
@property (nonatomic, readonly) NSInteger retries;

/**
 The number of times the command should retry sending before it is considered a failure.
 
 @note The default is <i>NPESensorCommandSettingsDefaultRetries</i>
 @since 2.0.5
 */
@property (nonatomic, assign) NSInteger maximumRetries;

///---------------------------------------------------------------------------------------
/// @name Command Blocks
///---------------------------------------------------------------------------------------

/**
 Fires hen the Command has been Successfully sent to the Sensor Device
 */
@property (nonatomic, copy) NPECmdQueueMsgSuccess onCommandSuccess;

/**
 This is fired when a message fails.  Will return the message and the failure reason
 */
@property (nonatomic, copy) NPECmdQueueMsgFailBlock onFailedMessage;

@end
