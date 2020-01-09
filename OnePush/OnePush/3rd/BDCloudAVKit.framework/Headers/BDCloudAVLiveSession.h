//
//  BDCloudAVLiveSession.h
//  BDCloudAVKit
//
//  Created by Bai,Lu(CBU) on 2017/4/19.
//  Copyright © 2017年 Baidu. All rights reserved.
//

#import <BDCloudRtmpSocket/IBidirectRtmpEventListener.h>

#import "BDCloudAVCaptureSession.h"



/**
 Live session delegate, inherits from BDCloudAVCaptureSessionDelegate.
 */
@protocol BDCloudAVLiveSessionDelegate <BDCloudAVCaptureSessionDelegate>
@optional

/**
 RTMP session connected.
 */
- (void)liveSessionConnected;

/**
 RTMP session failure with an error.

 @param code error code.
 */
- (void)liveSessionError:(RtmpSocketErrorCode)code;
@end

/**
 Capture image/audio and streaming via RTMP protocol.
 */
@interface BDCloudAVLiveSession : BDCloudAVCaptureSession<BDCloudAVSessionOutputSettingInterface>

/**
 Initialize with RTMP streaming url.

 @param url RTMP streaming url.
 @return instance.
 */
- (instancetype)initWithURL:(NSURL*)url;

/**
 Initialize with RTMP streaming url, capture settings, video/audio output settings.

 @param url RTMP streaming url
 @param captureConfig capture settings
 @param videoSettings video output settings.
 @param audioSettings audio output settings.
 @return instance.
 */
- (instancetype)initWithURL:(NSURL*)url
              captureConfig:(BDCloudAVCaptureSettings*)captureConfig
              videoSettings:(BDCloudAVVideoOutputSettings*)videoSettings
              audioSettings:(BDCloudAVAudioOutputSettings*)audioSettings;

/**
 Realtime upload speed for statistics usage.
 */
@property(nonatomic, readonly) double realtimeUploadSpeed;

/**
 Realtime upload fps for statistics usage.
 */
@property(nonatomic, readonly) double realtimeUploadFPS;

/**
 Realtime encode bitrate for statistics usage.
 */
@property(nonatomic, readonly) double realtimeBitrate;

@end

/**
 QOS category for adaptive bitrate.
 */
@interface BDCloudAVLiveSession (QOS)

/**
 Start adaptive bitrate with sensibility and bitrate range.

 @param sensibility sensitivity in [5, 10], the smaller the more sensitive.
 @param maxBitRate min bitrate.
 @param minBitRate max bitrate.
 */
- (void)startQOS:(NSUInteger)sensibility maxBitRate:(NSUInteger)maxBitRate minBitRate:(NSUInteger)minBitRate;

/**
 Stop adaptive bitrate.
 */
- (void)stopQOS;

@end
