//
//  BDCloudAVAudioHighPassNode.h
//  videoplayer
//
//  Created by blue on 07/11/2017.
//  Copyright © 2017 Baidu. All rights reserved.
//

#import <BDCloudAVUtil/BDCloudAVUtil.h>

@interface BDCloudAVAudioHighPassNode : BDCloudAVAudioNode

// Global, Hz, 10->(SampleRate/2), 6900
- (int)setCutoffFrequency:(float)value;

// Global, dB, -20->40, 0
- (int)setResonance:(float)value;

@end
