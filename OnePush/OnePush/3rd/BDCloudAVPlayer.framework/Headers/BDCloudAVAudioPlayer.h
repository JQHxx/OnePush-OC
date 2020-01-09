//
//  BDCloudAVAudioPlayer.h
//  BDCloudAVPlayer
//
//  Created by Bai,Lu(CBU) on 2017/4/18.
//  Copyright © 2017年 Baidu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <BDCloudAVBase/BDCloudAVBase.h>

/**
 Image player.
 Implements protocol BDCloudAVInput, have receive and process audio CMSampleBuffer ability.
 Implements protocol BDCloudAVControl, have play action control ability.
 
 */
@interface BDCloudAVAudioPlayer : NSObject<BDCloudAVInput, BDCloudAVControl>

/**
 Initialize with input delegate.
 
 @param delegate input delegate.
 @return instance.
 */
- (instancetype)initWithDelegate:(id<BDCloudAVInputDelegate>)delegate;
@end
