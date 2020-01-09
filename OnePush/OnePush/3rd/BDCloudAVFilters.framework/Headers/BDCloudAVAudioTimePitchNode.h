//
//  BDCloudAVAudioTimePitchNode.h
//  videoplayer
//
//  Created by blue on 25/10/2017.
//  Copyright © 2017 Baidu. All rights reserved.
//

#import <BDCloudAVUtil/BDCloudAVUtil.h>

@interface BDCloudAVAudioTimePitchNode : BDCloudAVAudioNode

/**
 Pitch shift in cents

 @param pitch Cents, -2400 -> 2400, 1.0
 @return set result
 */
- (int)setPitch:(float)pitch;

/**
 Rate control.

 @param rate 1/32 -> 32.0, 1.0
 @return set result
 */
- (int)setRate:(float)rate;

@end
