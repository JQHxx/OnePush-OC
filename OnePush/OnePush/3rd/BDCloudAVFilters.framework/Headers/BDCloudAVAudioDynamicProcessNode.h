//
//  BDCloudAVAudioDynamicProcessNode.h
//  videoplayer
//
//  Created by blue on 07/11/2017.
//  Copyright © 2017 Baidu. All rights reserved.
//

#import <BDCloudAVUtil/BDCloudAVUtil.h>

/**
 <#Description#>

 - BDCloudAVAudioDynamicProcessPresetFastAndSmooth: Fast and Smooth
 - BDCloudAVAudioDynamicProcessPresetHard: Hard
 - BDCloudAVAudioDynamicProcessPresetLight: Light
 - BDCloudAVAudioDynamicProcessPresetLightGate: Light Gate
 - BDCloudAVAudioDynamicProcessPresetMediumGate: Medium Gate
 - BDCloudAVAudioDynamicProcessPresetHardGate: Hard Gate
 */
typedef NS_ENUM(NSInteger, BDCloudAVAudioDynamicProcessPreset) {
    BDCloudAVAudioDynamicProcessPresetFastAndSmooth = 0,
    BDCloudAVAudioDynamicProcessPresetHard = 1,
    BDCloudAVAudioDynamicProcessPresetLight = 2,
    BDCloudAVAudioDynamicProcessPresetLightGate = 3,
    BDCloudAVAudioDynamicProcessPresetMediumGate = 4,
    BDCloudAVAudioDynamicProcessPresetHardGate = 5
};

@interface BDCloudAVAudioDynamicProcessNode : BDCloudAVAudioNode

- (int)setPreset:(BDCloudAVAudioDynamicProcessPreset)preset;

// Global, dB, -40->20, -20
- (int)setThreshold:(float)value;

// Global, dB, 0.1->40.0, 5
- (int)setHeadRoom:(float)value;

// Global, rate, 1->50.0, 2
- (int)setExpansionRatio:(float)value;

// Global, dB
- (int)setExpansionThreshold:(float)value;

// Global, secs, 0.0001->0.2, 0.001
- (int)setAttackTime:(float)value;

// Global, secs, 0.01->3, 0.05
- (int)setReleaseTime:(float)value;

// Global, dB, -40->40, 0
- (int)setMasterGain:(float)value;

- (int)getCompressionAmount:(float*)value;

- (int)getInputAmplitude:(float*)value;

- (int)getOutputAmplitude:(float*)value;

@end
