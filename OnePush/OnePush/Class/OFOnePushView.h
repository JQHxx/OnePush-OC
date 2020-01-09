//
//  OFOnePushView.h
//  OnePush
//
//  Created by OFweek01 on 2020/1/9.
//  Copyright © 2020 OFweek01. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <BDCloudAVKit/BDCloudAVKit.h>

typedef enum : NSUInteger {
    OnePushRTMPReady, // 未连接
    OnePushRTMPConect, // 已连接
    OnePushRTMPError, // 连接失败
} OnePushRTMPStatus;

@protocol OFOnePushViewDelegate <NSObject>

- (void)onePushViewStartButtonClicked;

- (void)onePushViewExitLive;

@end

@class SpreadButton;

@interface OFOnePushView : UIView

- (instancetype)initWithProtrait;

- (instancetype)initWithLandscape;

- (void)startStream:(NSString *)streamUrl;

- (void)endStream;

@property (weak, nonatomic) id<OFOnePushViewDelegate> delegate;

@property (nonatomic, strong) BDCloudAVLiveSession *session;

/**
 直播开始按钮, 根据按钮的文字区分不同的状态
 */
@property (strong, nonatomic) SpreadButton *streamStartButton;

/**
 当前流的连接状态
 */
@property (assign, nonatomic) OnePushRTMPStatus rtmpStatus;

@end

