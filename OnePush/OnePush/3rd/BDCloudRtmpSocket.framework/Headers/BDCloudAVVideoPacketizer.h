//
//  BDCloudAVVideoPacketizer.h
//  BDCloudRtmpSocket
//
//  Created by blue on 11/08/2017.
//  Copyright © 2017 Baidu. All rights reserved.
//

#import <BDCloudAVBase/BDCloudAVBase.h>
#import <BDCloudAVUtil/BDCloudAVUtil.h>

/**
 Packetize encoded video CMSampleBuffer to rtmp packet.
 Inherits from BDCloudAVBinaryOutput, have binary data buffer dispatch ability.
 Implements protocol BDCloudAVInput, have receive and process image CMSampleBuffer ability.
 */
@interface BDCloudAVVideoPacketizer : BDCloudAVBinaryOutput<BDCloudAVInput>

/**
 Initialize with video output settings.
 
 @param settings settings.
 @return instance.
 */
+ (instancetype)packetizerWithSettings:(BDCloudAVVideoOutputSettings*)settings;

/**
 Composition time offset. Two frames delay is recommended.
 */
@property(nonatomic, assign) int32_t ctsOffset;

/**
 Realtime encode bitrate for statistics.
 */
@property(nonatomic, readonly) double realtimeBitRate;

@end
