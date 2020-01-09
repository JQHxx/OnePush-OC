//
//  BDCloudAVAudioOutputSettings.h
//  BDCloudAVKit
//
//  Created by Bai,Lu(CBU) on 2017/4/20.
//  Copyright © 2017年 Baidu. All rights reserved.
//

#import <AVFoundation/AVFoundation.h>

/**
 Audio output settings used by encoder or writer.
 */
@interface BDCloudAVAudioOutputSettings : NSObject

/**
 Audio output samplerate. The default and recommended value is 44100Hz.
 */
@property(nonatomic) UInt32 sampleRate;

/**
 Audio output channel count. The default and recommended value is 2.
 */
@property(nonatomic) UInt32 channelsPreFrame;

/**
 Audio output bits coutn pre sample. The default and recommended value is 16.
 */
@property(nonatomic) UInt32 bitsPreSample;

/**
 Audio output bit rate. The default and recommended value is 96000.
 */
@property(nonatomic) UInt32 bitRate;

/**
 AVAudioQualityMedium
 */
@property(nonatomic) AVAudioQuality quality;

/**
 Create default settings.

 @return instance.
 */
+ (instancetype)defaultSettings;

/**
 Convert settings to a dictionary used by writer module.

 @return dictionary.
 */
- (NSDictionary*)toSystemOutputSettings;

@end
