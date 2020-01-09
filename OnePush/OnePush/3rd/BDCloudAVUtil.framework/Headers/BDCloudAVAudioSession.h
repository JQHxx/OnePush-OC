//
//  BDCloudAVAudioSession.h
//  BDCloudAVUtil
//
//  Created by Bai,Lu(CBU) on 2017/5/25.
//  Copyright © 2017年 Baidu. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Manage audio session.
 */
@interface BDCloudAVAudioSession : NSObject

/**
 Single instance.

 @return instance.
 */
+ (instancetype)sharedSession;

/**
 Whether support bluetooth device.
 */
@property(nonatomic) BOOL optionEnableBlueTooth;

/**
 Whether duck other apps.
 */
@property(nonatomic) BOOL optionDuckOthers;

/**
 Current audio session's sample rate.
 */
@property(nonatomic, readonly) Float64 sampleRate;

/**
 Whether headphone available.
 */
@property(nonatomic, readonly) BOOL headphoneAvailable;

/**
 Active audio session with special category.

 @param category category.
 @return active result.
 */
- (BOOL)active:(NSString*)category;

/**
 Deactive audio session.

 @return deactive result.
 */
- (BOOL)deactive;

@end

// Notified when audio session route changed, such as headphone plunin or unplug.
extern NSString* const BDCloudAVAudioSessionRouteChanged;

// Notified when audio session's sample rate changed.
extern NSString* const BDCloudAVAudioSessionSampleRateChanged;
