//
//  BDCloudAVCaptureOutput.h
//  BDCloudAVToolbox
//
//  Created by Bai,Lu(CBU) on 2017/3/16.
//  Copyright © 2017年 Baidu. All rights reserved.
//

#import <BDCloudAVBase/BDCloudAVOutput.h>
#import <BDCloudAVUtil/BDCloudAVUtil.h>

struct BDCloudAVAudioData;

/**
 Capture Settings.
 */
@interface BDCloudAVCaptureSettings : NSObject

/**
 Create default capture settings instance.

 @return instance.
 */
+ (instancetype)defaultSettings;

/**
 Whether capture video. Default value is YES.
 */
@property(nonatomic) BOOL captureVideo;

/**
 Whether capture audio. Default value is YES.
 */
@property(nonatomic) BOOL captureAudio;

/**
 The position of camera used to capture video. Default value is AVCaptureDevicePositionFront.
 */
@property(nonatomic) AVCaptureDevicePosition cameraPosition;

/**
 The camera type. Default value is AVCaptureDeviceTypeBuiltInWideAngleCamera in iOS10+.
 */
@property(nonatomic) NSString* cameraType;

/**
 The video dimension. Default value is 1280 * 720.
 */
@property(nonatomic) CMVideoDimensions dimensions;

/**
 Whether mirroring the video. Default value is NO.
 */
@property(nonatomic) BOOL videoMirroring;

/**
 The video frame rate to capture. Default value is 30 FPS.
 */
@property(nonatomic) int32_t videoFrameRate;

/**
 The torch mode. Default value is AVCaptureTorchModeOff.
 */
@property(nonatomic) AVCaptureTorchMode torchMode;

/**
 The video capture connection's orientation. Default value is AVCaptureVideoOrientationPortrait.
 */
@property(nonatomic) AVCaptureVideoOrientation cameraOrientation;

/**
 The camera focus mode. Default value is AVCaptureFocusModeContinuousAutoFocus.
 */
@property(nonatomic) AVCaptureFocusMode foucsMode;

/**
 The interest foucs point when focus mode is continuous auto focus. Default value is CGPoint(0.5, 0.5).
 */
@property(nonatomic) CGPoint focusPointOfInterest;

/**
 The camera exposure mode. Default value is AVCaptureExposureModeContinuousAutoExposure.
 */
@property(nonatomic) AVCaptureExposureMode exposureMode;

/**
 The interest exposure point when exposure mode is continuous auto exposure. Default value is CGPoint(0.5, 0.5).
 */
@property(nonatomic) CGPoint exposurePointOfInterest;

/**
 The camera stabilization mode. Default value is AVCaptureVideoStabilizationModeOff.
 */
@property(nonatomic) AVCaptureVideoStabilizationMode stabilizationMode;

/**
 Whether use smooth zoom.
 */
@property(nonatomic) BOOL smoothZoom;

/**
 Zoom factor. Controls zoom level of image outputs. Default value is 1.0f.
 */
@property(nonatomic) float zoomFactor;

/**
 Whether enable audio echo cancellation. Default value is NO.
 */
@property(nonatomic) BOOL enableAEC;
@end

/**
 Capture output delegate methods.
 */
@protocol BDCloudAVCaptureOutputDelegate <NSObject>
@optional

/**
 No suitable AVCaptureDeviceFormat was found based on user supplied capture settings.
 */
- (void)noSuitableFormatFound;

/**
 Several frames may be black when the camera startup.
 We should ingore several frames.

 @return The frame count to ingore when camera startup.
 */
- (NSUInteger)ingnoreStartupFrameCount;

/**
 Video frame will dropped when notime to process.
 */
- (void)videoFrameDropped;

/**
 Capture session started.
 */
- (void)captureStarted;

/**
 Capture session stopped.
 */
- (void)captureStopped;
@end

/**
 Capture video data from camera, audio data from microphone.
 Inherits from BDCloudAVDualOutput, have video and audio CMSampleBuffer dispatch ability.
 Implements protocol BDCloudAVControl, have capture session control ability.
 */
@interface BDCloudAVCaptureOutput : BDCloudAVDualOutput<BDCloudAVControl>

/**
 Capture session.
 */
@property(nonatomic, strong, readonly) AVCaptureSession* session;

/**
 Camera device current used.
 */
@property(nonatomic, strong, readonly) AVCaptureDevice* camera;

/**
 Microphone device current used.
 */
@property(nonatomic, strong, readonly) BDCloudAVAudioIONode* microphone;

/**
  Current video capture connection's orientation.
 */
@property(nonatomic, readonly) AVCaptureVideoOrientation orientation;

/**
 Delegate.
 */
@property(nonatomic, weak) id<BDCloudAVCaptureOutputDelegate> delegate;

/**
 Total paused time interval in seconds.
 */
@property(atomic, readonly) NSTimeInterval totalPausedTimeInterval;

/**
 Initialize with configuration.

 @param settings settings.
 @return instance.
 */
- (instancetype)initWithConfiguration:(BDCloudAVCaptureSettings*)settings;

/**
 Toggle video capture.

 @param enable enable.
 */
- (void)setVideoEnable:(BOOL)enable;

/**
 Toggle audio capture.

 @param enable enable.
 */
- (void)setAudioEnable:(BOOL)enable;

/**
 Set camera position.

 @param position camera position.
 */
- (void)setCameraPosition:(AVCaptureDevicePosition)position;

/**
 Set camera type.
 For iPhone6s+, could be AVCaptureDeviceTypeBuiltInWideAngleCamera, AVCaptureDeviceTypeBuiltInTelephotoCamera or AVCaptureDeviceTypeBuiltInDualCamera.

 @param type camera type.
 */
- (void)setCamereType:(AVCaptureDeviceType)type;

/**
 Set whether video is mirroring.

 @param videoMirroring mirroring.
 */
- (void)setVideoMirroring:(BOOL)videoMirroring;

/**
 Set video frame rate.

 @param frameRate frame rate.
 */
- (void)setVideoFrameRate:(int32_t)frameRate;

/**
 Set torch mode.

 @param mode mode.
 */
- (void)setTorchMode:(AVCaptureTorchMode)mode;

/**
 Set foucs mode to AVCaptureFocusModeAutoFocus.
 */
- (void)setAutoFoucsMode;

/**
 Set foucs mode to locked foucs with lens. lens must in [0, 1].

 @param lensPosition lens.
 */
- (void)setLockedFoucsWithLens:(float)lensPosition;

/**
 Set foucs mode to AVCaptureFocusModeContinuousAutoFocus with interest point.

 @param point interest point.
 */
- (void)setContinuousAutoFoucsModeInterestPoint:(CGPoint)point;

/**
 Set exposure mode to AVCaptureExposureModeAutoExpose.
 */
- (void)setAutoExposureMode;

/**
 Set exposure mode to AVCaptureExposureModeLocked with bias.
 The bias must between current camera's minExposureTargetBias and minExposureTargetBias.

 @param bias bias.
 */
- (void)setLockedExposureModeWithBias:(float)bias;

/**
 Set exposure mode to AVCaptureExposureModeContinuousAutoExposure with interest point.

 @param point interest point.
 */
- (void)setContinuousExposureModeInterestPoint:(CGPoint)point;

/**
 Set white balance mode to AVCaptureWhiteBalanceModeAutoWhiteBalance.
 */
- (void)setAutoWhiteBalance;

/**
 Set white balance mode to AVCaptureWhiteBalanceModeContinuousAutoWhiteBalance.
 */
- (void)setContinuousAutoWhiteBalance;

/**
 Set white balance mode to AVCaptureWhiteBalanceModeLocked with gains.

 @param gains gains.
 */
- (void)setLockedWhiteBalanceWithGains:(AVCaptureWhiteBalanceGains)gains;

/**
 Toggle smooth zoom.

 @param smooth whether smooth.
 */
- (void)setSmoothZoom:(BOOL)smooth;

/**
 Set zoom factor with zoom rate.

 @param factor zoom factor.
 @param rate zoom rate.
 */
- (void)setZoomFactor:(float)factor rate:(float)rate;

/**
 Toggle audio echo cancellation.
 If you want to toggle audio echo cancellation during capture, you need to turn on audio echo cancellation at initialization.

 @param enable enable.
 */
- (void)setAECEnable:(BOOL)enable;

/**
 Toggle audio gain control.
 If you want to toggle audio gain control during capture, you need to turn on audio echo cancellation at initialization.

 @param enable enable.
 */
- (void)setAGCEnable:(BOOL)enable;

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

