//
//  IBDSessionEventListener.h
//  BDCloudBidirectRtmp
//
//  Created by Andy Young on 05/06/2017.
//  Copyright © 2017 Baidu. All rights reserved.
//

#ifndef IBDSessionEventListener_h
#define IBDSessionEventListener_h
#include <BDCloudRtmpSocket/BDCloudRtmpSocket.h>

/**
 * 呼叫失败原因
 */
typedef NS_ENUM(NSInteger, ConversationFailureReason) {
    /**
     * 对方拒绝
     */
    CONVERSATION_DENIED = 0,

    /**
     * 呼叫超时
     */
    CONVERSATION_TIMEOUT = 1,

    /**
     * 对方离线
     */
    CONVERSATION_OFFLINE = 2
};

@protocol IBDSessionEventListener <NSObject>

/**
 * 直播通道已经建立
 * 注意：该事件针对大主播和高级观众（即小主播）
 */
- (void) onSessionConnected;

/**
 * 直播或连麦过程中出错
 *
 * @param error_code 错误码
 */
- (void) onError: (RtmpSocketErrorCode) error_code;
    
/**
 * 高级观众（即小主播）申请连麦
 * 注意：该事件只对大主播有效
 *
 * @param url 小主播的url
 * @param user_id 小主播的UserId
 */
- (void) onConversationRequest:(const NSString*)url  userId:(const NSString*) user_id;
    
/**
 * 成功连麦
 * 注意：该事件只对高级观众（即小主播）、大主播有效
 *
 * @param user_id 连麦对方用户ID
 */
- (void) onConversationStarted: (const NSString*) user_id;

/**
 * 连麦失败
 * 注意：该事件只对高级观众（即小主播）、大主播有效
 *
 * @param user_id     连麦对方用户ID
 * @param fail_reason 失败原因代码
 */
- (void) onConversationFailed: (const NSString*) user_id withReason: (ConversationFailureReason) fail_reason;

/**
 * 已结束连麦
 * 注意：该事件只对高级观众（即小主播）、大主播有效
 *
 * @param user_id 连麦对方用户ID
 */
- (void) onConversationEnded: (const NSString*) user_id;

@end

#endif /* IBDSessionEventListener_h */
