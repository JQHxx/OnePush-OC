//
//  BDCloudAVVideoEncoder.h
//  BDCloudAVEncoder
//
//  Created by Bai,Lu(CBU) on 2017/5/30.
//  Copyright © 2017年 Baidu. All rights reserved.
//

#import <BDCloudAVBase/BDCloudAVBase.h>
#import <BDCloudAVUtil/BDCloudAVUtil.h>

#import <CoreMedia/CoreMedia.h>

/**
 Video encoder.
 Inherits from BDCloudAVOutput, have image CMSampleBuffer dispatch ability.
 Implements protocol BDCloudAVInput, have receive and process image CMSampleBuffer ability.
 */
@interface BDCloudAVVideoEncoder : BDCloudAVOutput<BDCloudAVInput>

/**
 Initialize with video output settings.
 
 @param settings settings.
 @return instance.
 */
- (instancetype)initWithSettings:(BDCloudAVVideoOutputSettings*)settings;

/**
 Video encoder type. Readonly. Can be kCMVideoCodecType_H264 or kCMVideoCodecType_HEVC
 */
@property(nonatomic, readonly) CMVideoCodecType codec;

/**
 Video output bitrate. Readonly.
 */
@property(nonatomic, readonly) UInt32 bitRate;

/**
 Video output fps. Readonly.
 */
@property(nonatomic, readonly) UInt32 frameRate;

/**
 Setup encoder.

 @return setup result.
 */
- (BOOL)setup;

/**
 Teardown encoder.

 @return teardown result.
 */
- (BOOL)teardown;

/**
 Change current video output bitrate.

 @param bitrate bitrate.
 */
- (void)updatedBitRate:(UInt32)bitrate;
                                       
@end
