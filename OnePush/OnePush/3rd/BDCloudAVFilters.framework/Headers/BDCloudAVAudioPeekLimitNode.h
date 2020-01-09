//
//  BDCloudAVAudioPeekLimitNode.h
//  videoplayer
//
//  Created by blue on 07/11/2017.
//  Copyright © 2017 Baidu. All rights reserved.
//

#import <BDCloudAVUtil/BDCloudAVUtil.h>

@interface BDCloudAVAudioPeekLimitNode : BDCloudAVAudioNode

// Global, Secs, 0.001->0.03, 0.012
- (int)setAttackTime:(float)time;

// Global, Secs, 0.001->0.06, 0.024
- (int)setDecayTime:(float)time;

// Global, dB, -40->40, 0
- (int)setPreGain:(float)gain;

@end
