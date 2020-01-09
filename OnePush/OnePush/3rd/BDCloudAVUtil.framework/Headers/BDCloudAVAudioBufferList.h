//
//  BDCloudAVAudioBufferList.h
//  BDCloudAVUtil
//
//  Created by Bai,Lu(CBU) on 2017/5/15.
//  Copyright © 2017年 Baidu. All rights reserved.
//

#import <AVFoundation/AVFoundation.h>

@class BDCloudAVFormatDescription;

@interface BDCloudAVAudioBufferList : NSObject

+ (instancetype)fromCMSampleBuffer:(CMSampleBufferRef)buffer;
+ (instancetype)fromASBD:(const AudioStreamBasicDescription*)asbd;
+ (instancetype)fromASBD:(const AudioStreamBasicDescription*)asbd data:(AudioBufferList*)data samples:(UInt32)samples;

@property(nonatomic, readonly) const AudioStreamBasicDescription* asbd;
@property(nonatomic, readonly) AudioBufferList* abl;
@property(nonatomic, readonly) UInt32 samples;

- (void)clearAudioBuffers:(UInt32)samples;
- (void)createAudioBuffers:(UInt32)samples;
- (void)makeSilent;

@end
