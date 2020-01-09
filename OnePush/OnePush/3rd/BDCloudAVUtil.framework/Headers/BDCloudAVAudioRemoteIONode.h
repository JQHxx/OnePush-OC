//
//  BDCloudAVAudioRemoteIONode.h
//  videoplayer
//
//  Created by blue on 25/10/2017.
//  Copyright © 2017 Baidu. All rights reserved.
//

#import "BDCloudAVAudioIONode.h"

@interface BDCloudAVAudioRemoteInputNode : BDCloudAVAudioInputNode
@end

@interface BDCloudAVAudioRemoteOutputNode : BDCloudAVAudioOutputNode

+ (instancetype)defaultOutput:(id<BDCloudAVAudioNodeCallback>)render;

@end

