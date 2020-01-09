//
//  BDCloudAVRecordSession.h
//  BDCloudAVKit
//
//  Created by Bai,Lu(CBU) on 2017/6/23.
//  Copyright © 2017年 Baidu. All rights reserved.
//

#import "BDCloudAVCaptureSession.h"

/**
 Record session delegate, inherits from BDCloudAVCaptureSessionDelegate.
 */
@protocol BDCloudAVRecordSessionDelegate <BDCloudAVCaptureSessionDelegate>
@optional

/**
 Writer started with first frame‘s pts.

 @param time first frame's pts.
 */
- (void)writeStartedAtTime:(CMTime)time;

/**
 Writer stopped with last frame's pts.
 If error is not nil, means write failure.

 @param time last frame's pts.
 @param error error.
 */
- (void)writeStoppedAtTime:(CMTime)time error:(NSError*)error;
@end

/**
 Record a video and save to file.
 */
@interface BDCloudAVRecordSession : BDCloudAVCaptureSession<BDCloudAVSessionOutputSettingInterface>

/**
 Record duration. The default value is zero, means continuous recording util stop called.
 */
@property(nonatomic) NSTimeInterval duration;

/**
 Initialize with file url.

 @param url file url.
 @return instance.
 */
- (instancetype)initWithURL:(NSURL*)url;

/**
 Initialize with file url, capture settings, video/audio output settings.

 @param url file url.
 @param captureConfig capture settings.
 @param videoSettings video output settings.
 @param audioSettings audio output settings.
 @return instance.
 */
- (instancetype)initWithURL:(NSURL*)url
              captureConfig:(BDCloudAVCaptureSettings*)captureConfig
              videoSettings:(BDCloudAVVideoOutputSettings*)videoSettings
              audioSettings:(BDCloudAVAudioOutputSettings*)audioSettings;

@end
