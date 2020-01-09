//
//  BDRtmpSessionBasic.h
//  BDCloudBDRtmpSession
//
//  Created by Andy Young on 08/06/2017.
//  Copyright © 2017 Baidu. All rights reserved.
//

#ifndef BDRtmpSessionBasic_h
#define BDRtmpSessionBasic_h

#import <BDCloudAVBase/BDCloudAVBase.h>

#import "IBDRtmpSessionEventListener.h"

typedef NS_ENUM(NSInteger, UserRole) {
    // 创建直播间的大主播
    Host = 0,
    // 可能参与连麦的高级观众
    Guest = 1,
    // 普通观众
    Audience = 2
};

@interface BDRtmpSessionBasic : NSObject<BDCloudAVBinaryInput>

@property(nonatomic, weak) id<IBDSessionEventListener> eventListener;
@property(nonatomic, strong, readonly) BidirectRtmpSocket* rtmpSocket;
@property(nonatomic, copy) NSString* streamUrl;
@property(nonatomic, copy) NSString* userId;

- (id) initWithRole: (UserRole) role;

- (void) createStream;
- (void) destroyStream;

- (void) startConversation: (NSString*) targetUrl withUserId: (NSString*) targetUserId;
- (void) stopConversation: (NSString*) targetUrl withUserId: (NSString*) targetUserId;

@end

#endif /* BDRtmpSessionBasic_h */
