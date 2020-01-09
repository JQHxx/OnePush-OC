//
//  BDCloudAVProcessSession.h
//  BDCloudAVKit
//
//  Created by Bai,Lu(CBU) on 2017/4/24.
//  Copyright © 2017年 Baidu. All rights reserved.
//

#import "BDCloudAVEffectSession.h"

/**
 Process session delegate.
 */
@protocol BDCloudAVProcessSessionDelegate <NSObject>
@optional

/**
 Process started.
 */
- (void)processStarted;

/**
 Process progress report.

 @param progress progress.
 @param current current processed position.
 @param duration total duration.
 */
- (void)processProgress:(float)progress current:(CMTime)current duration:(CMTime)duration;

/**
 Process stopped.
 If the error is not nil, means process failure.

 @param error error.
 */
- (void)processStopped:(NSError*)error;
@end

/**
 Read frames from a video file, after processed by image/audio filter, then save to another video file.
 */
@interface BDCloudAVProcessSession : BDCloudAVEffectSession<BDCloudAVSessionOutputSettingInterface>

/**
 Delegate.
 */
@property(nonatomic, weak) id<BDCloudAVProcessSessionDelegate> delegate;

/**
 source video file url.
 */
@property(nonatomic, strong, readonly) NSURL* srcURL;

/**
 destination video file url.
 */
@property(nonatomic, strong, readonly) NSURL* destURL;

/**
 The source video's duration.
 */
@property(nonatomic, readonly) CMTime duration;

/**
 Current process progress.
 */
@property(nonatomic, readonly) float progress;

/**
 Whether the video reverse playback.
 */
@property(nonatomic) BOOL reversed;

/**
 Initialize with source and destination video file url.

 @param src souce video file url.
 @param dest destination video file url.
 @return instance.
 */
- (instancetype)initWithSource:(NSURL*)src destination:(NSURL*)dest;

/**
 Initialize with source & destination video file url, video/audio output settings.

 @param src souce video file url.
 @param dest destination video file url.
 @param videoSettings video output settings.
 @param audioSettings audio output settings.
 @return instance.
 */
- (instancetype)initWithSource:(NSURL*)src
                   destination:(NSURL*)dest
                 videoSettings:(BDCloudAVVideoOutputSettings*)videoSettings
                 audioSettings:(BDCloudAVAudioOutputSettings*)audioSettings;

/**
 Set process time range.

 @param range time range.
 */
- (void)setRange:(CMTimeRange)range;

@end
