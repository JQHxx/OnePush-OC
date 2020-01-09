//
//  BDCloudAVAudioLowShelfNode.h
//  videoplayer
//
//  Created by blue on 07/11/2017.
//  Copyright © 2017 Baidu. All rights reserved.
//

#import <BDCloudAVUtil/BDCloudAVUtil.h>

@interface BDCloudAVAudioLowShelfNode : BDCloudAVAudioNode

// Global, Hz, 10->200, 80
- (int)setCutOffFrequency:(float)value;

// Global, dB, -40->40, 0
- (int)setGain:(float)value;;

@end
