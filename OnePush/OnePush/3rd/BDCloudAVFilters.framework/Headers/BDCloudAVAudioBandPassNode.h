//
//  BDCloudAVAudioBandPassNode.h
//  videoplayer
//
//  Created by blue on 07/11/2017.
//  Copyright © 2017 Baidu. All rights reserved.
//

#import <BDCloudAVUtil/BDCloudAVUtil.h>

@interface BDCloudAVAudioBandPassNode : BDCloudAVAudioNode

// Global, Hz, 20->(SampleRate/2), 5000
- (int)setCenterFrequency:(float)value;

// Global, Cents, 100->12000, 600
- (int)setBandwidth:(float)value;

@end
