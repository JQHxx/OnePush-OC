//
//  BDCloudAVAudioDistortionNode.h
//  videoplayer
//
//  Created by blue on 07/11/2017.
//  Copyright © 2017 Baidu. All rights reserved.
//

#import <BDCloudAVUtil/BDCloudAVUtil.h>

@interface BDCloudAVAudioDistortionNode : BDCloudAVAudioNode

- (int)setPreset:(AVAudioUnitDistortionPreset)preset;

// Global, dB, -80 -> 20, -6
- (int)setSoftClipGain:(float)value;

// Global, Percent, 0 -> 100, 50
- (int)setFinalMix:(float)value;

@end

@interface BDCloudAVAudioDistortionNode (Advanced)

// Global, Milliseconds, 0.1 -> 500, 0.1
- (int)setDelay:(float)value;

// Global, Rate, 0.1 -> 50, 1.0
- (int)setDecay:(float)value;

// Global, Percent, 0 -> 100, 50
- (int)setDelayMix:(float)value;

// Global, Percent, 0 -> 100
- (int)setDecimation:(float)value;

// Global, Percent, 0 -> 100, 0
- (int)setRounding:(float)value;

// Global, Percent, 0 -> 100, 50
- (int)setDecimationMix:(float)value;

// Global, Linear Gain, 0 -> 1, 1
- (int)setLinearTerm:(float)value;

// Global, Linear Gain, 0 -> 20, 0
- (int)setSquaredTerm:(float)value;

// Global, Linear Gain, 0 -> 20, 0
- (int)setCubicTerm:(float)value;

// Global, Percent, 0 -> 100, 50
- (int)setPolynomialMix:(float)value;

// Global, Hertz, 0.5 -> 8000, 100
- (int)setRingModFreq1:(float)value;

// Global, Hertz, 0.5 -> 8000, 100
- (int)setRingModFreq2:(float)value;

// Global, Percent, 0 -> 100, 50
- (int)setRingModBalance:(float)value;

// Global, Percent, 0 -> 100, 0
- (int)setRingModMix:(float)value;

@end
