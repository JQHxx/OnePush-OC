//
//  BDCloudAVAudioParametricEQNode.h
//  videoplayer
//
//  Created by blue on 07/11/2017.
//  Copyright © 2017 Baidu. All rights reserved.
//

#import <BDCloudAVUtil/BDCloudAVUtil.h>

@interface BDCloudAVAudioParametricEQNode : BDCloudAVAudioNode

// Global, Hz, 20->(SampleRate/2), 2000
- (int)setCenterFreq:(float)value;

// Global, Hz, 0.1->20, 1.0
- (int)setQ:(float)value;

// Global, dB, -20->20, 0
- (int)setGain:(float)value;
@end
