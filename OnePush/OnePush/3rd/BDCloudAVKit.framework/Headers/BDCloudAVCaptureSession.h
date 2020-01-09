//
//  BDCloudAVCaptureSession.h
//  BDCloudAVKit
//
//  Created by Bai,Lu(CBU) on 2017/6/23.
//  Copyright © 2017年 Baidu. All rights reserved.
//

#import "BDCloudAVEffectSession.h"
#import <BDCloudAVSource/BDCloudAVSource.h>

/**
 Capture session delegate.
 */
@protocol BDCloudAVCaptureSessionDelegate <NSObject>
@optional

/**
 Camera preview started.
 */
- (void)previewStarted;

/**
 Capture started.
 */
- (void)captureStarted;

/**
 Capture stopped.
 */
- (void)captureStopped;

/**
 Camera preview stopped.
 */
- (void)previewStopped;
@end

typedef NS_ENUM(NSInteger, BDCloudAVCapturePreviewScalingMode) {
    BDCloudAVCapturePreviewScalingModeNone,
    BDCloudAVCapturePreviewScalingModeAspectFit,
    BDCloudAVCapturePreviewScalingModeAspectFill,
    BDCloudAVCapturePreviewScalingModeFill
};

/**
 Base class for record session and live streaming session.
 Implements protocol BDCloudAVSessionDeviceControlInterface, could control device.
 
 Process video data from camera by image filter, audio data from microphone by audio filter.
 Display processed video data on preview view.
 */
@interface BDCloudAVCaptureSession : BDCloudAVEffectSession<BDCloudAVSessionDeviceControlInterface>

/**
 Preview view.
 */
@property(nonatomic, strong, readonly) UIView* view;

/**
 预览页面缩放模式。默认为kGPUImageFillModePreserveAspectRatio
 */
@property(nonatomic) BDCloudAVCapturePreviewScalingMode scalingMode;

/**
 Delegate.
 */
@property(nonatomic, weak) id delegate;

/**
 Total paused time interval in seconds.
 */
@property(atomic, readonly) NSTimeInterval totalPausedTimeInterval;

/**
 Initialize with capture settings.

 @param config capture settings.
 @return instance.
 */
- (instancetype)initWithCaptureConfig:(BDCloudAVCaptureSettings*)config;

/**
 Start preview.
 */
- (void)startPreview;

/**
 Stop preview.
 */
- (void)stopPreview;

/**
 Add paused time interval.
 
 @discuss:
 If pause and resume are called when recording video, we must keep the pts continuous.
 The audio/video frame's pts after resume call should subtract the total paused time.
 
 When stop is called, the total pause time interval will be automatically clear to zero.
 
 @Important: Call this method before call resume.
 @param interval pause time in seconds.
 */
- (void)addPauseTimeInterval:(NSTimeInterval)interval;

@end
