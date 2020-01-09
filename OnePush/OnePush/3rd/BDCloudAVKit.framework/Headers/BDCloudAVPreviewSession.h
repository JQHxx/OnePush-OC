//
//  BDCloudAVProcessSession.h
//  BDCloudAVKit
//
//  Created by Bai,Lu(CBU) on 2017/4/19.
//  Copyright © 2017年 Baidu. All rights reserved.
//

#import "BDCloudAVEffectSession.h"
#import <BDCloudAVPlayer/BDCloudAVPlayer.h>
#import <BDCloudAVSource/BDCloudAVSource.h>

/**
 Preview session delegate.
 */
@protocol BDCloudAVPreviewSessionDelegate <NSObject>
@optional

/**
 Preview started.
 */
- (void)previewStarted;

/**
 Preview progress report.

 @param progress progress.
 @param current current play position.
 @param duration total duration.
 */
- (void)previewProgress:(float)progress current:(CMTime)current duration:(CMTime)duration;

/**
 Preview stopped.
 */
- (void)previewStopped;

/**
 Preview repeated.
 */
- (void)previewRepeated;
@end

/**
 Preivew image/audio filter process effect in realtime.
 */
@interface BDCloudAVPreviewSession : BDCloudAVEffectSession

/**
 Read video and audio frame from file.
 */
@property(nonatomic, strong, readonly) BDCloudAVFileOutput* fileOutput;

/**
 Whether the preview is repeat. The default value is YES.
 */
@property(nonatomic) BOOL repeat;

/**
 Delegate.
 */
@property(nonatomic, weak) id<BDCloudAVPreviewSessionDelegate> delegate;

/**
 Render view.
 */
@property(nonatomic, strong, readonly) UIView* view;

/**
 The video's duration.
 */
@property(nonatomic, readonly) CMTime duration;

/**
 Whether the preview is paused.
 */
@property(nonatomic, readonly) BOOL paused;

/**
 Preview range. The default value is kCMTimeRangeZero, means the whole video.
 */
@property(nonatomic) CMTimeRange range;

/**
 Whether the video reverse playback.
 */
@property(nonatomic) BOOL reversed;

/**
 Preivew fill mode.
 */
@property(nonatomic) BDCloudAVImagePlayerFillMode fillMode;

/**
 Initialize with file url.

 @param url fil url.
 @return instance.
 */
- (instancetype)initWithURL:(NSURL*)url;
@end
