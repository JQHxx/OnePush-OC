//
//  BDCloudAVFileOutputInterface.h
//  BDCloudAVSource
//
//  Created by Liu,Yawen(CBU) on 2018/3/5.
//  Copyright © 2018年 Baidu. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol BDCloudAVFileOutputControlInterface <NSObject>

/**
 Prepare to read the file.
 After this method, you can call readVideoFrame or readAudioFrame to read frames.
 
 @return prepare result.
 */
- (BOOL)prepareToRead;

/**
 Read a video frame.
 If an error occur, or reach to eof, this method will return NO.
 
 @return read result.
 */
- (BOOL)readVideoFrame;

/**
 Read a audio frame.
 If an error occur, or reach to eof, this method will return NO.
 
 @return read result.
 */
- (BOOL)readAudioFrame;

/**
 Cancel read.
 */
- (void)cancelReading;

/**
 Reset for reread.
 */
- (void)resetForReading;

@end

@protocol BDCloudAVFileOutputReaderDelegate <NSObject>

@optional

/**
 Progress report.
 
 @param progress read progress.
 @param current read position in seconds.
 @param duration file duration in seconds.
 */
- (void)readProgress:(float)progress current:(CMTime)current duration:(CMTime)duration;

/**
 File reader read cancelled.
 */
- (void)readCancelled;

/**
 File reader read failure with error.
 
 @param error error.
 */
- (void)readFailured:(NSError*)error;

/**
 File reader read completed.
 */
- (void)readCompleted;

@end
