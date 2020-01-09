//
//  BDCloudAVAACEncoder.h
//  BDCloudAVEncoder
//
//  Created by Bai,Lu(CBU) on 2017/3/16.
//  Copyright © 2017年 Baidu. All rights reserved.
//

#import <BDCloudAVBase/BDCloudAVBase.h>

/**
 AAC encoder.
 Inherits from BDCloudAVOutput, have audio CMSampleBuffer dispatch ability.
 Implements protocol BDCloudAVInput, have receive and process audio CMSampleBuffer ability.
 */
@interface BDCloudAVAACEncoder : BDCloudAVOutput<BDCloudAVInput>

@property(nonatomic) UInt32 sampleRate;

/**
 Audio output bitrate. The default value is 96000.
 */
@property(nonatomic) UInt32 bitrate;

@property(nonatomic) UInt32 framesPerPacket;

/**
 Teardown encoder.
 */
- (void)teardown;

@end
