//
//  BDCloudAVAudioNode.h
//  videoplayer
//
//  Created by Bai,Lu(CBU) on 23/10/2017.
//  Copyright © 2017 Baidu. All rights reserved.
//

#import <AVFoundation/AVFoundation.h>

@interface BDCloudAVAudioNode : NSObject
@end

typedef NS_ENUM(UInt32, BDCloudAVAudioNodeCallbackType) {
    BDCloudAVAudioNodeCallbackInput,
    BDCloudAVAudioNodeCallbackRender,
    BDCloudAVAudioNodeCallbackNotify,
};

@class BDCloudAVAudioBusFrame;

@protocol BDCloudAVAudioNodeCallback <NSObject>
- (int)audioNode:(BDCloudAVAudioNode*)node
           frame:(BDCloudAVAudioBusFrame*)frame
            type:(BDCloudAVAudioNodeCallbackType)type;
@end
