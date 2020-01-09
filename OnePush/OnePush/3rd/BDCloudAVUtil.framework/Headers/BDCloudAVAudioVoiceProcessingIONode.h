//
//  BDCloudAVAudioVoiceProcessingIONode.h
//  videoplayer
//
//  Created by blue on 25/10/2017.
//  Copyright © 2017 Baidu. All rights reserved.
//

#import "BDCloudAVAudioIONode.h"

@interface BDCloudAVAudioVoiceProcessingInputNode : BDCloudAVAudioInputNode
- (int)setAECEnable:(BOOL)enable;
- (int)setAGCEnable:(BOOL)enable;
@end

@interface BDCloudAVAudioVoiceProcessingOutputNode : BDCloudAVAudioOutputNode
- (int)setMute:(BOOL)mute;
@end
