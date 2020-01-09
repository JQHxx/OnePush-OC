//
//  BDCloudRtmpSocketKey.h
//  BDCloudRtmpSocket
//
//  Created by Bai,Lu(CBU) on 2017/6/13.
//  Copyright © 2017年 Baidu. All rights reserved.
//

#import <BDCloudAVBase/BDCloudAVBase.h>

// Key of rtmp packet timestamp, value type is int64_t.
BDCLOUD_AV_EXTERN NSString* const BDCloudRtmpPacketTimestampKey;

// Key of rtmp packet type, value type is uint8_t.
BDCLOUD_AV_EXTERN NSString* const BDCloudRtmpPacketTypeKey;

// Key of rtmp packet stream ID, value type is uint8_t.
BDCLOUD_AV_EXTERN NSString* const BDCloudRtmpStreamIDKey;

// Key that indicates rtmp packet whether is a key frame. value type is BOOL, valid in video stream.
BDCLOUD_AV_EXTERN NSString* const BDCloudRtmpIsKeyFrameKey;
