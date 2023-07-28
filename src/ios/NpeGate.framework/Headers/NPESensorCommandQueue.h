//
//  NPESensorCommandQueue.h
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
#import <NpeGate/NPECmdQueueMsg.h>

@class NPESensorCommandQueue;

/**
 Defines the Sensor Command Queue Status
 
 @since 2.1.0
 */
typedef NS_ENUM(NSInteger, NPESensorCommandQueueStatus) {
    /** Command Message was added to Queue */
    NPESensorCommandQueueStatusEnQueued         = 0,
    /** Command Message was removed from Queue */
    NPESensorCommandQueueStatusDeQueued         = 1,
    /** Processed a Successful Message */
    NPESensorCommandQueueStatusProcessSuccess   = 2,
    /** Processed a Failed Message */
    NPESensorCommandQueueStatusProcessFail      = 3,

};

NS_ASSUME_NONNULL_BEGIN

/** An Observer Block for the Queue Observer */
typedef void (^NPESensorCommandQueueCommandStateObserverBlock)(NPESensorCommandQueue *queue, NPECmdQueueMsg *message, WTQueueState state);
/** An Observer Block for the Queue Status Observer */
typedef void (^NPESensorCommandQueueStatusObserverBlock)(NPESensorCommandQueue *queue, NPECmdQueueMsg *message, NPESensorCommandQueueStatus status, NSError  * _Nullable error);


/**
 The Command Queue Interface for the NPESensorConnection
 
 @since 2.1.0
 */
@interface NPESensorCommandQueue : NSObject

/**
 Readonly Property of the Command Queue
 
 @since 2.1.0
 */
@property (nonatomic, readonly, nullable) NSArray<NPECmdQueueMsg *> *queue;

/**
 Reference to the Current Working Command
 
 @since 2.1.0
 @note Will be nil if no command is current being processed
 */
@property (nonatomic, readonly, nullable) NPECmdQueueMsg *currentWorkingCommand;

///---------------------------------------------------------------------------------------
/// @name Queue Commands
///---------------------------------------------------------------------------------------

/**
 Flushes all Commands from the Queue
 
 @since 2.1.0
 */
- (void)flush;

///---------------------------------------------------------------------------------------
/// @name Statistics
///---------------------------------------------------------------------------------------

/**
 Average Round Trip Time of Commands.
 
 The round trip time is calculated from the time the application sends the command until the framework determins success or failure of the command.  The value is an average over the last five commands.
 
 @since 2.1.0
 */
@property (nonatomic, readonly) NSTimeInterval averageCommandRoundTripTime;

/**
 Count of the total commands that have been Sent to sensors.
 
 @since 2.1.0
 */
@property (nonatomic, readonly) NSInteger requestCount;

/**
 Count of the Total commands that have been Successfully sent to Sensors.
 
 @since 2.1.0
 */
@property (nonatomic, readonly) NSInteger successCount;

/**
 Count of the Total commands that have failed to send to the Sensor.
 
 This number reflects commands that we have sent to the sensor but didn't get back the expected results in a timely manor.
 
 @since 2.1.0
 */
@property (nonatomic, readonly) NSInteger failCount;

/**
 Count of the Total retries that the command peformed.
 
 The count reflects how many retires were performed, regardless of if the command failed, or was successful.
 
 @since 2.1.0
 */
@property (nonatomic, readonly) NSInteger retryCount;

/**
 Reset the Command Queue Statistics
 
 @since 2.1.0
 */
- (void)resetStatistics;

///---------------------------------------------------------------------------------------
/// @name Queue Observers
///---------------------------------------------------------------------------------------

/**
 A weakified Queue Status Observer
 
 This will fire each time a Command is put on or taken off the Queue
 
 @param observer The Observer who is observing the Status of the Queue
 @param handler The Block to perform on status change
 @since 2.1.0
 */
- (void)addQueueStatusObserver:(id)observer block:(NPESensorCommandQueueStatusObserverBlock)handler;

/**
 Removes th Queue Status Observer
 
 @param observer The Observer to remove from the Status changes
 */
- (void)removeQueueStatusObserver:(id)observer;

/**
 A weakified Queue Command State Observer.
 
 This will fire each time the it receives a state change for a NPECmdQueueMsg in its queue.
 
 @param observer The Observer who is observing the state of the Commands in the Queue.
 @param handler The Block to perform on receipt of the queue state changes.
 @since 2.1.0
 */
- (void)addQueueCommandStateObserver:(id)observer block:(NPESensorCommandQueueCommandStateObserverBlock)handler;

/**
 Removes the Queue Command State Observer
 
 Once you are done observing the Queue you can unsubscribe from the notifications
 
 @param observer The observer to remove from the Command State Change Observers
 @since 2.1.0
 */
- (void)removeQueueCommandStateObserver:(id)observer;

@end
NS_ASSUME_NONNULL_END
