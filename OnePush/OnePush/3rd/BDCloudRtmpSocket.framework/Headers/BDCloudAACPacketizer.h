//
//  BDCloudAACPacketizer.h
//  BDCloudAVRTMPStack
//
//  Created by Bai,Lu(CBU) on 2017/6/9.
//  Copyright © 2017年 Baidu. All rights reserved.
//

#import <BDCloudAVBase/BDCloudAVBase.h>

/**
 Packetize encoded audio CMSampleBuffer to rtmp packet.
 Inherits from BDCloudAVBinaryOutput, have binary data buffer dispatch ability.
 Implements protocol BDCloudAVInput, have receive and process audio CMSampleBuffer ability.
 */
@interface BDCloudAACPacketizer : BDCloudAVBinaryOutput<BDCloudAVInput>
@end
