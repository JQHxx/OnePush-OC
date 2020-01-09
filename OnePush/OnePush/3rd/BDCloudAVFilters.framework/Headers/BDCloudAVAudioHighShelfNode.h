//
//  BDCloudAVAudioHighShelfNode.h
//  videoplayer
//
//  Created by blue on 07/11/2017.
//  Copyright © 2017 Baidu. All rights reserved.
//

#import <BDCloudAVUtil/BDCloudAVUtil.h>

@interface BDCloudAVAudioHighShelfNode : BDCloudAVAudioNode

// Global, Hz, 10000->(SampleRate/2), 10000
- (int)setCutOffFrequency:(float)value;

// Global, dB, -40->40, 0
- (int)setGain:(float)value;

@end
