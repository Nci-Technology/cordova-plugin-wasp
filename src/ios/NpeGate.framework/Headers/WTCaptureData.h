//
//  WTCaptureData.h
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

typedef NS_ENUM(NSInteger, WTCaptureCommand) {
    start,
    pause_rec,
    stop,
    reset
};

typedef NS_ENUM(NSInteger, WTTimeStampCommand) {
    startTS,
    stopTS,
    lapTS
};


FOUNDATION_EXPORT NSString * const kSessionStartStamp;
FOUNDATION_EXPORT NSString * const kSessionLapStamp;
FOUNDATION_EXPORT NSString * const kSessionIntervalStamp;
FOUNDATION_EXPORT NSString * const kSessionRecoveryStamp;
FOUNDATION_EXPORT NSString * const kSessionEndStamp;
FOUNDATION_EXPORT NSString * const kSessionCooldownStamp;


/**
 * The WTCaptureData is an opbject used to store session data from a specific parameter
 * for an ANT+ sensor.
 *
 * The Cature Data object has two arrays, one for storing the data being captured, and the
 * other is for saving the timestamp associated with each sample.
 *
 * Methods are provided to add data, reset the storage, start/stop capture and add a lap
 * timestamp to the data
 *
 * This object is provided to allow very low overhead for storing sensor specific data without
 * burdoning the application with saving the data at a higher level in the application.
 */

@interface WTCaptureData : NSObject

/**
 * Method for setting the units in the WTCapture class
 */
-(instancetype)initWithUnits:(NSString *)units;

/**
 * Method for setting the units in the WTCapture class using a dictionary
 */
-(instancetype)initWithDictionary:(NSDictionary<NSString*,id>*)dict;

/**
 * Scaling parameter to modify the data as is is added to the capture array
 */
@property (nonatomic, assign) float scaleFactor;

/**
 * Set the invert factor to do a 1/x on the parameter before scaling.
 */
@property (nonatomic, assign) BOOL invertFactor;

/**
 * Scaled Units
 * If the scaleFactor is modified from 1.0 then the scaledUnits value is used for the associated data. 
 */
@property (nonatomic, strong) NSString *scaledUnits;

/**
 * Units
 * If the scaleFactor is modified from 1.0 then the scaledUnits value is used for the associated data, otherwise the default units are returned.
 */
@property (nonatomic, readonly) NSString *units;

/**
 * Array for storing the captured data.
 */
@property (nonatomic, readonly) NSMutableArray *data;

/**
 * Array for storing the captured data timestamp.
 */
@property (nonatomic, readonly) NSMutableArray *timeStamp;

/**
 * Dictionary for storing different timestamps throughout the workout session.
 */
@property (nonatomic, readonly) NSDictionary *sessionTimeStamps;

/**
 * Array for storing the timestamp of the lap intervals.
 */
@property (nonatomic, readonly) NSMutableArray *intervals;

@property (nonatomic, readonly) NSString *localUnits;

/**
 * Flag indicating if the Capture object is currently capturing data
 */
@property (nonatomic, readonly) BOOL bCapturing;

/**
 * Text string indicating the data being captured by the module
 */
@property (nonatomic, strong) NSString *title;

/**
 *  NSNumber used to indicate invalid value to prevent recording invalid data
 */
@property (nonatomic, strong) NSNumber *invalidValue;

/**
 *  NSNumber returning the minumum value in the caputured data set
 *  If a sensor is invalid when the capture data is sampled nils are stored
 *  in the capture array.  This parameter ignores the invalid data.
 */
@property (nonatomic, readonly) NSNumber *minValue;

/**
 *  NSNumber returning the maximum value in the caputured data set
 *  If a sensor is invalid when the capture data is sampled nils are stored
 *  in the capture array.  This parameter ignores the invalid data.
 */
@property (nonatomic, readonly) NSNumber *maxValue;

/**
 *  NSNumber returning the average value in the caputured data set
 *  If a sensor is invalid when the capture data is sampled nils are stored
 *  in the capture array.  This parameter ignores the invalid data.
 */
@property (nonatomic, readonly) NSNumber *avgValue;

/**
 * method used internally to add data to the capture module
 */
-(void)addData:(NSNumber*)data;

/**
 * Calling the reset method erases any stored data in the module.
 */
-(BOOL)reset;

/**
 * If the capture module is active, the lab command will add a timestamp
 * to the intevals list.  This is useful for tracking laps in a workout.
 */
-(BOOL)lap;

/**
 * Method for starting the capture of data by the capture module.
 */
-(void)start;

/**
 * Method for stopping the capture of data by the capture module.
 */
-(void)stop;

/**
 * Method for setting the timestamps of different session events
 */
-(void)setSessionTimestampFor:(WTTimeStampCommand)cmd;

@end
