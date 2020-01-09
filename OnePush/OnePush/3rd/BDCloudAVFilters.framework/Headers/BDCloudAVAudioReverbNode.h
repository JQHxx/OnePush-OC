//
//  BDCloudAVAudioReverbNode.h
//  videoplayer
//
//  Created by blue on 25/10/2017.
//  Copyright © 2017 Baidu. All rights reserved.
//

#import <BDCloudAVUtil/BDCloudAVUtil.h>

@interface BDCloudAVAudioReverbNode : BDCloudAVAudioNode

- (int)setPreset:(AVAudioUnitReverbPreset)preset;

/**
 kReverb2Param_DryWetMix
 
 @param level // Global, CrossFade, 0->100, 100
 */
- (int)setDryWetLevel:(NSUInteger)level;

@end

@interface BDCloudAVAudioReverbNode (Advanced)

/**
 kReverb2Param_Gain
 
 @param gain // Global, Decibels, -20->20, 0
 */
- (int)setReverbGain:(NSInteger)gain;

/**
 kReverb2Param_MinDelayTime
 
 @param time // Global, Secs, 0.0001->1.0, 0.008
 */
- (int)setMinDelayTime:(NSTimeInterval)time;

/**
 kReverb2Param_MaxDelayTime
 
 @param time // Global, Secs, 0.0001->1.0, 0.050
 */
- (int)setMaxDelayTime:(NSTimeInterval)time;

/**
 kReverb2Param_DecayTimeAt0Hz
 
 @param time // Global, Secs, 0.001->20.0, 1.0
 */
- (int)setDecayTimeAt0Hz:(float)time;

/**
 kReverb2Param_DecayTimeAtNyquist
 
 @param time // Global, Secs, 0.001->20.0, 0.5
 */
- (int)setDecayTimeAtNyquist:(float)time;

/**
 kReverb2Param_RandomizeReflections
 
 @param value // Global, Integer, 1->1000
 */
- (int)setRandomizeReflections:(NSInteger)value;

@end
