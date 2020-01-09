//
//  BDCloudAVTools.h
//  videoplayer
//
//  Created by Bai,Lu(CBU) on 20/10/2017.
//  Copyright © 2017 blue. All rights reserved.
//

#import <AVFoundation/AVFoundation.h>

@interface BDCloudAVTools : NSObject

+ (AVAudioFormat*)defaultAudioRecordFormat;
+ (AVAudioFormat*)defaultAudioProcessFormat;
+ (BOOL)isNonInterleaved:(const AudioStreamBasicDescription*)asbd;
+ (UInt32)audioBufferCount:(const AudioStreamBasicDescription*)asbd;
+ (UInt32)audioBufferSize:(UInt32)buffers;
+ (UInt32)channelsPerBuffer:(const AudioStreamBasicDescription*)asbd;

@end
