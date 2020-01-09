//
//  IBidirectRtmpEventListener.h
//  BDCloudRtmpSocket
//
//  Created by Andy Young on 05/06/2017.
//  Copyright © 2017 Baidu. All rights reserved.
//

#ifndef IBidirectRtmpEventListener_h
#define IBidirectRtmpEventListener_h

typedef NS_ENUM(NSInteger, RtmpSocketErrorCode) {
    /**
     * 与服务器建立rtmp连接过程出错
     */
    ErrorCodeConnectToServerFailed = -1,
    /**
     * 创建rtmp推流通道出错
     */
    ErrorCodePulishStreamFailed = -2,
    /**
     * endRtmpSession过程中出错
     */
    ErrorCodeDisconnectFromServerFailed = -3,
    /**
     * 推流过程中，遇到未知错误导致推流失败
     */
    ErrorCodeUnknownStreamingError = -6,
    /**
     * 推流过程中，遇到弱网情况导致推流失败
     * 收到此错误后，建议提示用户当前网络不稳定，
     * 如果反复收到此错误码，建议调用endRtmpSession停止推流
     */
    ErrorCodeWeakConnection = -7,
    /**
     * 推流过程中，遇到服务器网络错误导致推流失败
     * 收到此错误后，建议调用endRtmpSession立即停止推流，并在服务恢复后再重新推流
     */
    ErrorCodeServerNetworkError = -8,
    /**
     * 推流过程中，遇到设备断网导致推流失败，
     * 收到此错误后，建议提示用户检查网络连接，然后调用endRtmpSession立即停止推流
     */
    ErrorCodeLocalNetworkError = -9
};

typedef NS_ENUM(NSInteger, RtmpResponseCode) {
    CallResponseCodeOK = 200,
    CallResponseCodeDENIED = 400,
    CallResponseCodeTIMEOUT = 300,
    CallResponseCodeRINGING = 201,
    CallResponseCodeOFFLINE = 401
};

@protocol IBidirectRtmpEventListener <NSObject>


/**
 * 连接服务器成功
 */
- (void) onSessionConnected;

/**
 * 连接出错
 *
 * @param errorCode 参考RtmpSocketErrorCode定义
 */
- (void) onSessionError: (RtmpSocketErrorCode) errorCode;

/**
 * 收到Call、Invite信令
 *
 * @param callerId 呼叫者UserId
 * @param callerUrl 呼叫者StreamUrl
 */
- (void) onCallSignal: (NSString*) callerId withUrl: (NSString*) callerUrl;

/**
 * 收到Cancel信令
 *
 * @param callerId 呼叫者UserId
 * @param callerUrl 呼叫者StreamUrl
 */
- (void) onCancelSignal: (NSString*) callerId withUrl: (NSString*) callerUrl;

/**
 * 收到Call、Invite的回复
 *
 * @param calleeId 被呼叫者UserId
 * @param calleeUrl 被呼叫者StreamUrl
 * @param code 回复码
 */
- (void) onResponseSignal: (NSString*) calleeId withUrl: (NSString*) calleeUrl withResponseCode: (RtmpResponseCode) code;

/**
 * 收到Ack信令
 *
 * @param fromId 对方UserId
 * @param fromUrl 对方StreamUrl
 */
- (void) onAckSignal: (NSString*) fromId withUrl: (NSString*) fromUrl;

/**
 * 收到大主播的Kick信令
 *
 * @param fromId 大主播UserId
 * @param fromUrl 大主播StreamUrl
 */
- (void) onKickSignal: (NSString*) fromId withUrl: (NSString*) fromUrl;

/**
 * 收到Bye信令
 *
 * @param fromId 对方UserId
 * @param fromUrl 对方StreamUrl
 */
- (void) onByeSignal: (NSString*) fromId withUrl: (NSString*) fromUrl;

/**
 * 收到Ping信令
 *
 * @param fromId 对方UserId
 * @param fromUrl 对方StreamUrl
 * @param extInfo 附加信息
 */
- (void) onPingSignal: (NSString*) fromId withUrl: (NSString*) fromUrl withInfo: (NSString*) extInfo;

/**
 * 收到Info信令
 *
 * @param fromId 对方UserId
 * @param fromUrl 对方StreamUrl
 * @param info 附加信息
 */
- (void) onInfoSignal: (NSString*) fromId withUrl: (NSString*) fromUrl withInfo: (NSString*) info;

@end

#endif /* IBidirectRtmpEventListener_h */
