//
//  BDCloudAVMoviePlayer.h
//  BDCloudAVPlayer
//
//  Created by Bai,Lu(CBU) on 2017/4/18.
//  Copyright © 2017年 Baidu. All rights reserved.
//

#import <BDCloudAVBase/BDCloudAVBase.h>
#import <UIKit/UIKit.h>

@class BDCloudAVImagePlayer;
@class BDCloudAVAudioPlayer;

/**
 A simple movie player for preview image/audio filter apply effect.
 */
@interface BDCloudAVMoviePlayer : NSObject <BDCloudAVControl>

/**
 Whether the player is paused.
 */
@property(nonatomic, readonly) BOOL paused;

/**
 Image player.
 */
@property(nonatomic, strong, readonly) BDCloudAVImagePlayer* imagePlayer;

/**
 Audio player.
 */
@property(nonatomic, strong, readonly) BDCloudAVAudioPlayer* audioPlayer;

/**
 Initialize with input delegate.

 @param delegate input delegate.
 @return instance.
 */
- (instancetype)initWithInputDelegate:(id<BDCloudAVInputDelegate>)delegate;
@end
