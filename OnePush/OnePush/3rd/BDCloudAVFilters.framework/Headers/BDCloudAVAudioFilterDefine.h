//
//  BDCloudAVAudioFilterDefine.h
//  BDCloudAVFilters
//
//  Created by Bai,Lu(CBU) on 2017/4/7.
//  Copyright © 2017年 Baidu. All rights reserved.
//

#import <CoreAudio/CoreAudioTypes.h>
#import <AudioToolbox/AudioToolbox.h>

@class BDCloudAVAudioBufferList;

/**
 Interface implements this protocol could process audio frame inplace.
 You should only operate audioBuffer.abl field.
 Do not change audio format, data length and channel count.
 */
@protocol BDCloudAVCustomAudioFilter <NSObject>

/**
 Process audio frame inplace.

 @param abl audio frame.
 */
- (void)processAudioBuffer:(BDCloudAVAudioBufferList*)abl;
@end
