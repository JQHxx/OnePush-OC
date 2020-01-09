//
//  BDCloudAVAudioBufferListCache.h
//  BDCloudAVUtil
//
//  Created by Bai,Lu(CBU) on 2017/5/25.
//  Copyright © 2017年 Baidu. All rights reserved.
//

#import <AVFoundation/AVFoundation.h>

@class BDCloudAVAudioBufferList;

/**
 A helper class that could cache AudioBufferList.
 */
@interface BDCloudAVAudioBufferListCache : NSObject

+ (instancetype)cacheWithCapacity:(UInt32)capacity channels:(UInt32)channels;

/**
 The cache size in bytes.
 */
@property(nonatomic, readonly) UInt32 capacity;

/**
 The channel count.
 */
@property(nonatomic, readonly) UInt32 channels;

/**
 The frame count filled.
 */
@property(nonatomic, readonly) UInt32 fill;

/**
 Produce an AudioBufferList.
 If no enough space, produce will fail.

 @param data BDCloudAVAudioBufferList.
 @return produce result.
 */
- (BOOL)produceAudioFrame:(BDCloudAVAudioBufferList*)data;

/**
 Consume an AudioBufferList.
 If no enough data, consume will fail.

 @param data [in/out] BDCloudAVAudioBufferList.
 @return consume result.
 */
- (BOOL)consumeAudioFrame:(BDCloudAVAudioBufferList*)data;

/**
 Clear the cached audio data.
 */
- (void)clear;

@end
