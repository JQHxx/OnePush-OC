//
//  BDCloudAVEffectSession.h
//  BDCloudAVKit
//
//  Created by Bai,Lu(CBU) on 2017/4/24.
//  Copyright © 2017年 Baidu. All rights reserved.
//

#import "BDCloudAVSessionInterface.h"
#import "BDCloudAVImageFilterSetting.h"

/**
 Base class for video/audio process sessions.
 Implements protocol BDCloudAVSessionImageFilterInterface, could change image filter's sub filter chain.
 Implements protocol BDCloudAVSessionAudioFilterInterface, could operate audio filter's behavior.
 Implements protocol BDCloudAVControl, could manage session state.
 */
@interface BDCloudAVEffectSession : NSObject<BDCloudAVSessionImageFilterInterface, BDCloudAVSessionAudioFilterInterface, BDCloudAVControl>

/**
 Image filter.
 */
@property(nonatomic, strong, readonly) BDCloudAVImageFilter* imageFilter;

/**
 Image filter setting.
 */
@property (nonatomic, strong) BDCloudAVImageFilterSetting* imageFilterSetting;

/**
 Audio input mix source.
 */
@property(nonatomic, strong, readonly) BDCloudAVAudioInputMixSource* inputSource;


/**
 Audio music mix source.
 */
@property(nonatomic, strong) BDCloudAVAudioMusicMixSource* musicSource;


/**
 Audio reverb node.
 */
@property(nonatomic, strong) BDCloudAVAudioReverbNode* reverb;

/**
 Audio filter.
 */
@property(nonatomic, strong, readonly) BDCloudAVAudioFilter* audioFilter;

/**
 Video speed, the default value is 1.0, 0.3 -> 3.0.
 */
@property(nonatomic) float speed;

@end
