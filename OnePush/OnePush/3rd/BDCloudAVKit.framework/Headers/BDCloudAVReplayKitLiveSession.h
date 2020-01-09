//
//  BDCloudAVReplayKitLiveSession.h
//  BDCloudAVKit
//
//  Created by Bai,Lu(CBU) on 17/11/2017.
//  Copyright © 2017 Baidu. All rights reserved.
//

#import "BDCloudAVEffectSession.h"
#import <ReplayKit/ReplayKit.h>

@protocol BDCloudAVLiveSessionDelegate;

/**
 Session for replay kit live streaming via RTMP protocol.
 */
@interface BDCloudAVReplayKitLiveSession : BDCloudAVEffectSession<BDCloudAVSessionOutputSettingInterface>

/**
 Initialize with RTMP streaming url.
 
 @param url RTMP streaming url.
 @param userId local user's id
 @return instance.
 */
- (instancetype)initWithURL:(NSURL*)url
                     userId:(NSString *)userId;

/**
 Initialize with RTMP streaming url, video/audio output settings.
 
 @param url RTMP streaming url
 @param userId local user's id
 @param videoSettings video output settings.
 @param audioSettings audio output settings.
 @return instance.
 */
- (instancetype)initWithURL:(NSURL*)url
                     userId:(NSString *)userId
              videoSettings:(BDCloudAVVideoOutputSettings*)videoSettings
              audioSettings:(BDCloudAVAudioOutputSettings*)audioSettings;


/**
 Delegate. Reuse live session's delegate.
 */
@property(nonatomic, weak) id<BDCloudAVLiveSessionDelegate> delegate;

/**
 Enqueue sample buffer to audio/image filter for live streaming.
 Call this method in [RPBroadcastSampleHandler processSampleBuffer].

 @param buffer buffer
 @param type buffer type.
 */
- (void)enqueueSampleBuffer:(CMSampleBufferRef)buffer type:(RPSampleBufferType)type;

@end
