//
//  BDCloudAVAudioBusFrame.h
//  BDCloudAVUtil
//
//  Created by Bai,Lu(CBU) on 18/10/2017.
//  Copyright © 2017 Baidu. All rights reserved.
//

#import "BDCloudAVAudioBufferList.h"

@interface BDCloudAVAudioBusFrame : NSObject

@property(nonatomic) UInt32 flags;
@property(nonatomic) UInt32 bus;
@property(nonatomic) AudioTimeStamp time;
@property(nonatomic, strong) BDCloudAVAudioBufferList* data;

@end
