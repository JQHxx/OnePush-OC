//
//  BDCloudAVAudioIONode.h
//  videoplayer
//
//  Created by blue on 25/10/2017.
//  Copyright © 2017 Baidu. All rights reserved.
//

#import "BDCloudAVAudioNode.h"

@interface BDCloudAVAudioIONode : BDCloudAVAudioNode
@end

@interface BDCloudAVAudioIONode (Single)
- (int)start;
- (int)stop;
@end

@interface BDCloudAVAudioInputNode : BDCloudAVAudioIONode
@end

@interface BDCloudAVAudioOutputNode : BDCloudAVAudioIONode
@end
