//
//  BDCloudAVSessionInterface.h
//  BDCloudAVKit
//
//  Created by Bai,Lu(CBU) on 2017/4/24.
//  Copyright © 2017年 Baidu. All rights reserved.
//

#import <AVFoundation/AVFoundation.h>
#import <BDCloudAVUtil/BDCloudAVUtil.h>
#import <BDCloudAVFilters/BDCloudAVFilters.h>
#import <BDCloudAVWriter/BDCloudAVWriter.h>
#import "BDCloudAVImageFilterSetting.h"

/**
 Interface implements this protocol could control device.
 The methods listed below are define and comment in BDCloudAVSource/BDCloudAVCaptureOutput.h
 */
@protocol BDCloudAVSessionDeviceControlInterface <NSObject>
- (void)setVideoEnable:(BOOL)enable;
- (void)setAudioEnable:(BOOL)enable;
- (void)setCameraPosition:(AVCaptureDevicePosition)position;
- (void)setTorchMode:(AVCaptureTorchMode)mode;
- (void)setAutoFoucsMode;
- (void)setLockedFoucsWithLens:(float)lensPosition;
- (void)setContinuousAutoFoucsModeInterestPoint:(CGPoint)point;
- (void)setAutoExposureMode;
- (void)setLockedExposureModeWithBias:(float)bias;
- (void)setContinuousExposureModeInterestPoint:(CGPoint)point;
- (void)setAutoWhiteBalance;
- (void)setContinuousAutoWhiteBalance;
- (void)setLockedWhiteBalanceWithGains:(AVCaptureWhiteBalanceGains)gains;
- (void)setVideoFrameRate:(int32_t)frameRate;

- (void)setSmoothZoom:(BOOL)smooth;
- (void)setZoomFactor:(float)factor rate:(float)rate;

@end

/**
 Interface implements this protocol could reset movie writer with new output settings.
 The method listed below is define and comment in BDCloudAVWriter/BDCloudAVMovieWriter.h
 */
@protocol BDCloudAVSessionOutputSettingInterface <NSObject>
- (void)updateOutputParameter:(BDCloudAVMovieParameter*)parameter;
@end

/**
 Interface implements this protocol could change image filter's sub filter chain.
 The related properties are define and comment in BDCloudAVFilters/BDCloudAVImageFilter.h and BDCloudAVImageFilterSetting.h
 */
@protocol BDCloudAVSessionImageFilterInterface <NSObject>
- (void)setInitialFilters:(NSArray<BDCloudAVCustomImageInput>*)initialFilters
           terminalFilter:(BDCloudAVCustomImageFilter*)terminalFilter;
- (void)addFilter:(BDCloudAVCustomImageFilter *)filter;
- (void)removeFilter:(BDCloudAVCustomImageFilter *)filter;
- (void)addFilterWithType:(BDCloudAVFilterType)type styleType:(BDCloudAVStyleFilterType)subType;
- (void)removeFilterWithType:(BDCloudAVFilterType)type;
- (void)setBeautyGroupLevel:(CGFloat)level;
- (void)setSkinGroupLevel:(CGFloat)level;
- (void)setBeautyGroupTone:(CGFloat)level;
- (void)setEyeGroupLevel:(CGFloat)level;
- (void)setFaceGroupLevel:(CGFloat)level;
- (void)setBeautyLevel:(CGFloat)level;
- (void)setSkinLevel:(CGFloat)level;
- (void)setBeautyTone:(CGFloat)level;
- (void)setEyeLevel:(CGFloat)level;
- (void)setFaceLevel:(CGFloat)level;
- (void)setStickerName:(NSString *)name type:(NSString *)type;
- (void)setColorContrast:(CGFloat)level;
- (void)setColorBright:(CGFloat)level;
- (void)setColorExposure:(CGFloat)level;
- (void)setColorHue:(CGFloat)level;
- (void)setColorSaturation:(CGFloat)level;
- (void)setColorSharpen:(CGFloat)level;
- (void)setNewBackgroundImage:(UIImage *)image;
- (void)setChromaBlendThresholdSensitivity:(CGFloat)thresholdSensitivity;
- (void)setChromaBlendSmoothing:(CGFloat)smoothing;
- (void)setColorToReplaceRed:(GLfloat)redComponent green:(GLfloat)greenComponent blue:(GLfloat)blueComponent;
@end

/**
 Interface implements this protocol could operate audio filter's behavior.
 The methods listed below are define and comment in BDCloudAVFilters/BDCloudAVAudioFilter.h
 */
@protocol BDCloudAVSessionAudioFilterInterface <NSObject>
- (void)addSubAudioFilter:(id<BDCloudAVCustomAudioFilter>)filter;
- (void)removeSubFilter:(id<BDCloudAVCustomAudioFilter>)filter;
- (void)setMusic:(NSString*)file;
- (void)setMusicRange:(CMTimeRange)range;
- (void)setMasterVolume:(float)value;
- (void)setMusicVolume:(float)value;
- (void)setMixOutputVolume:(float)value;
- (void)setMusicEnable:(BOOL)enable;
- (void)setReverbDryWetLevel:(NSUInteger)level;
- (void)setReverbGain:(NSInteger)gain;
- (void)setReverbMinDelayTime:(NSTimeInterval)time;
- (void)setReverbMaxDelayTime:(NSTimeInterval)time;
- (void)setReverbDecayTimeAt0Hz:(float)time;
- (void)setReverbDecayTimeAtNyquist:(float)time;
- (void)setReverbRandomizeReflections:(NSInteger)value;
@end
