//
//  BDCloudAVVideoOutputSettings.h
//  BDCloudAVKit
//
//  Created by Bai,Lu(CBU) on 2017/4/20.
//  Copyright © 2017年 Baidu. All rights reserved.
//

#import <CoreMedia/CoreMedia.h>

/**
 Video output settings used by encoder or writer.
 */
@interface BDCloudAVVideoOutputSettings : NSObject

/**
 Video Encoder ID. The default value is AVVideoCodecH264, if device support HEVC encode, you can set to AVVideoCodecHEVC.
 */
@property(nonatomic) NSString* codecID;

/**
 Video output dimensions. The default value is 360 * 640
 */
@property(nonatomic) CMVideoDimensions dimension;

/**
 Video output bitrate. The default value is 500Kbps.
 */
@property(nonatomic) UInt32 bitRate;

/**
 Video output gop length in seconds. The default value is 2 seconds.
 */
@property(nonatomic) UInt32 maxKeyFrameInterval;

/**
 Video output fps. The default value is 30 fps.
 */
@property(nonatomic) UInt32 frameRate;

/**
 Video output scaling mode. The default value is AVVideoScalingModeResizeAspect.
 */
@property(nonatomic) NSString* scalingMode;

/**
 Video encoder's profile. The default value is AVVideoProfileLevelH264HighAutoLevel.
 */
@property(nonatomic) NSString* profile;

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
