//
//  OFOnePushView.m
//  OnePush
//
//  Created by OFweek01 on 2020/1/9.
//  Copyright © 2020 OFweek01. All rights reserved.
//

#import "OFOnePushView.h"
#import "SpreadButton.h"
#import <Masonry.h>
#import <BDCloudAVFilters/BDCloudAVFilters.h>
#import "LFGPUImageBeautyFilter.h"

@interface OFOnePushView()<BDCloudAVLiveSessionDelegate>

@property (nonatomic, strong) BDCloudAVCaptureSettings *avCapturesettings;

/**
切换摄像头
*/
@property (nonatomic, strong) UIButton *switchCameraButton;

/**
闪光灯
*/
@property (nonatomic, strong) UIButton *torchButton;

/**
 推流地址
 */
@property (strong, nonatomic) NSString *pushURL;

/**
 是否竖屏
 */
@property (assign, nonatomic) BOOL isProtrait;

/**
 当前的控制器
 */
@property (nonatomic, weak) UIViewController *curViewController;

@property (strong, nonatomic) UIImageView *shadowup;
@property (strong, nonatomic) UIView *redPoint;

@end

@implementation OFOnePushView

- (instancetype)initWithProtrait {
    self = [super initWithFrame:CGRectMake(0, 0, UIScreen.mainScreen.bounds.size.width, UIScreen.mainScreen.bounds.size.height)];
    if (self) {
        self.backgroundColor = [UIColor whiteColor];
        [self initUI:YES];
        [self setupUI];
        [self requestAccessForVideo];
        [self requestAccessForAudio];
        self.rtmpStatus = OnePushRTMPReady;
        
    }
    return self;
}

- (instancetype)initWithLandscape {
    self = [super initWithFrame:CGRectMake(0, 0, UIScreen.mainScreen.bounds.size.height, UIScreen.mainScreen.bounds.size.width)];
    if (self) {
        self.backgroundColor = [UIColor whiteColor];
        [self initUI:NO];
        [self setupUI];
        [self requestAccessForVideo];
        [self requestAccessForAudio];
        self.rtmpStatus = OnePushRTMPReady;
    }
    return self;
}

- (void)startStream:(NSString *)streamUrl {
    _pushURL = streamUrl;
    NSURL *pushURL = [NSURL URLWithString:_pushURL];
    BDCloudAVVideoOutputSettings *avVideoOutputSettings = [BDCloudAVVideoOutputSettings defaultSettings];
    
    CMVideoDimensions dimension;
    if (_isProtrait) {
        dimension.width = 480;
        dimension.height = 858;
        avVideoOutputSettings.bitRate = 750 * 1000;
    } else {
        dimension.width = 720;
        dimension.height = 1280;
        avVideoOutputSettings.bitRate = 1000 * 1000;
    }
    avVideoOutputSettings.dimension = dimension;

    BDCloudAVAudioOutputSettings *avAudioOutputSettings = [BDCloudAVAudioOutputSettings defaultSettings];
    avAudioOutputSettings.quality = AVAudioQualityHigh;
    self.session = [self.session initWithURL:pushURL captureConfig:self.avCapturesettings videoSettings:avVideoOutputSettings audioSettings:avAudioOutputSettings];
    //self.session.scalingMode = BDCloudAVCapturePreviewScalingModeAspectFill;
    LFGPUImageBeautyFilter *filter = [[LFGPUImageBeautyFilter alloc]init];
    [filter setBrightLevel:0.5];
    [filter setBeautyLevel:0.7];
    [self.session addFilter:filter];
    [self.session startPreview];
    [self.session start];
}

- (void)endStream {
    self.rtmpStatus = OnePushRTMPReady;
    [self.session stop];
    self.session = nil;
}

#pragma mark - Private methods
- (void)initUI:(BOOL)isProtrait {
    _isProtrait = isProtrait;
    
    self.session.view.frame = self.frame;
    [self addSubview:self.session.view];
    [self.session startPreview];
    
    [self addSubview:self.shadowup];
    CGFloat statuBarHeight = UIApplication.sharedApplication.statusBarFrame.size.height;
    CGFloat bgHeight = statuBarHeight + 44.0;
    if (!isProtrait) {
        bgHeight = 64.0;
        statuBarHeight = 20.0;
    }
    [self.shadowup mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.top.right.equalTo(self);
//        make.height.mas_equalTo(60);
        //2019.1.15适配X
        make.height.mas_equalTo(bgHeight);
    }];
    
    SpreadButton *backBtn = [SpreadButton buttonWithType:UIButtonTypeCustom];
    backBtn.minimumHitTestWidth = 100;
    backBtn.minimumHitTestHight = 60;
    [backBtn setImage:[UIImage imageNamed:@"turnback"] forState:UIControlStateNormal];
    [backBtn addTarget: self action:@selector(backAction) forControlEvents:UIControlEventTouchUpInside];
    [_shadowup addSubview:backBtn];
    [backBtn mas_makeConstraints:^(MASConstraintMaker *make) {
//        make.centerY.equalTo(_shadowup);
        //2019.1.15适配X
        make.top.equalTo(_shadowup).offset(statuBarHeight+12);
        make.left.equalTo(_shadowup).offset(16);
        make.width.mas_equalTo(12);
        make.height.mas_equalTo(20);
    }];
}

- (void) setupUI {
    
    CGFloat statuBarHeight = UIApplication.sharedApplication.statusBarFrame.size.height;
    [self.shadowup addSubview:self.streamStartButton];
    [_streamStartButton addSubview:self.redPoint];
    
    [_streamStartButton mas_makeConstraints:^(MASConstraintMaker *make) {
        //2019.1.15适配X
        make.top.equalTo(self.shadowup).offset(statuBarHeight+4.5);
        make.centerX.equalTo(self.shadowup);
        make.width.mas_equalTo(109);
        make.height.mas_equalTo(35);
    }];
    
    [_redPoint mas_makeConstraints:^(MASConstraintMaker *make) {
        make.centerY.equalTo(_streamStartButton);
        make.left.equalTo(_streamStartButton).offset(7);
        make.width.height.mas_equalTo(6);
    }];
    
    // 闪光灯
    [self.shadowup addSubview:self.torchButton];
    
    //右边距
    NSLayoutConstraint *leftCons = [NSLayoutConstraint
                  constraintWithItem:_torchButton
                  attribute:NSLayoutAttributeRight
                  relatedBy:NSLayoutRelationEqual
                  toItem:_shadowup
                  attribute:NSLayoutAttributeRight
                  multiplier:1.0f
                  constant:-8];
    [self.shadowup addConstraint:leftCons];
    
    //顶部边距
    NSLayoutConstraint *topCons = [NSLayoutConstraint
                  constraintWithItem:_torchButton
                  attribute:NSLayoutAttributeCenterY
                  relatedBy:NSLayoutRelationEqual
                  toItem:_streamStartButton
                  attribute:NSLayoutAttributeCenterY
                  multiplier:1.0f
                  constant:0];
    [self.shadowup addConstraint:topCons];
    
    // 切换摄像头
    [self.shadowup addSubview:self.switchCameraButton];
    //右边距
    NSLayoutConstraint *switchBtnRightCons = [NSLayoutConstraint
                  constraintWithItem:_switchCameraButton
                  attribute:NSLayoutAttributeRight
                  relatedBy:NSLayoutRelationEqual
                  toItem:_torchButton
                  attribute:NSLayoutAttributeLeft
                  multiplier:1.0f
                  constant:-15];
    [self addConstraint:switchBtnRightCons];
    
    //顶部边距
    NSLayoutConstraint *switchBtnTopCons = [NSLayoutConstraint
                  constraintWithItem:_switchCameraButton
                  attribute:NSLayoutAttributeCenterY
                  relatedBy:NSLayoutRelationEqual
                  toItem:_streamStartButton
                  attribute:NSLayoutAttributeCenterY
                  multiplier:1.0f
                  constant:0];
    [self addConstraint:switchBtnTopCons];
    
}

- (UIViewController*)getViewController:(UIView *)sender {
    for (UIView* next = [sender superview]; next; next = next.superview) {
        UIResponder* nextResponder = [next nextResponder];
        if ([nextResponder isKindOfClass:[UIViewController class]]) {
            return (UIViewController*)nextResponder;
        }
    }
    return nil;
}

#pragma mark - 请求摄像头权限
- (void)requestAccessForVideo {
    AVAuthorizationStatus status = [AVCaptureDevice authorizationStatusForMediaType:AVMediaTypeVideo];
    switch (status) {
        case AVAuthorizationStatusNotDetermined: {
            // 许可对话没有出现，发起授权许可
            [AVCaptureDevice requestAccessForMediaType:AVMediaTypeVideo completionHandler:^(BOOL granted) {
                if (granted) {
                    dispatch_async(dispatch_get_main_queue(), ^{
                    });
                }
            }];
            break;
        }
        case AVAuthorizationStatusAuthorized: {
            // 已经开启授权，可继续
            dispatch_async(dispatch_get_main_queue(), ^{
            });
            break;
        }
        case AVAuthorizationStatusDenied:
        case AVAuthorizationStatusRestricted: {
            break;
        }
        default:
            break;
    }
}

#pragma mark - 请求麦克风权限
- (void)requestAccessForAudio {
    AVAuthorizationStatus status = [AVCaptureDevice authorizationStatusForMediaType:AVMediaTypeAudio];
    if(!self.curViewController) {
         self.curViewController = [self getViewController:self];
     }
    switch (status) {
        case AVAuthorizationStatusNotDetermined: {
            [AVCaptureDevice requestAccessForMediaType:AVMediaTypeAudio completionHandler:^(BOOL granted) {
            }];
            break;
        }
        case AVAuthorizationStatusAuthorized: {
            break;
        }
        case AVAuthorizationStatusDenied:
        case AVAuthorizationStatusRestricted: {
            NSString *str = @"请在系统\"设置\"--\"OFweek\"--\"麦克风\"启用权限";
            UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"需要\"麦克风\"使用权限" message:str preferredStyle:UIAlertControllerStyleAlert];
            __weak typeof(alert) weakAlert = alert;
            
            [weakAlert addAction:[UIAlertAction actionWithTitle:@"知道了" style:UIAlertActionStyleDefault handler:^(UIAlertAction *action) {
            }]];
            [self.curViewController presentViewController:weakAlert animated:YES completion:nil];
            break;
        }
            break;
        default:
            break;
    }
}

#pragma mark - BDCloudAVLiveSessionDelegate
- (void)liveSessionConnected {
    self.rtmpStatus = OnePushRTMPConect;
}

- (void)liveSessionError:(RtmpSocketErrorCode)code {
    self.rtmpStatus = OnePushRTMPError;
}

#pragma mark - Event response
// 闪光灯
- (void)onFlash {
    if(!self.curViewController) {
        self.curViewController = [self getViewController:self];
    }
    if (_avCapturesettings.cameraPosition == AVCaptureDevicePositionBack) {
        _torchButton.selected = !_torchButton.selected;
        [self.session setTorchMode:_torchButton.selected];
    } else {
        UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"提示" message:@"当前为前置摄像头，无法开启闪光灯" preferredStyle:UIAlertControllerStyleAlert];
        __weak typeof(alert) weakAlert = alert;
        [weakAlert addAction:[UIAlertAction actionWithTitle:@"知道了" style:UIAlertActionStyleDefault handler:^(UIAlertAction *action) {
        }]];
        [self.curViewController presentViewController:weakAlert animated:YES completion:nil];
        return;
    }
}

// 切换摄像头
- (void)onCameraToggle { // see kit or block
    _torchButton.selected = NO;
    [self.session setTorchMode:NO];
    _switchCameraButton.selected = !_switchCameraButton.selected;
    [self.session setCameraPosition:_switchCameraButton.selected ? AVCaptureDevicePositionBack : AVCaptureDevicePositionFront];
}

- (void)backAction {
    if (_delegate && [_delegate respondsToSelector:@selector(onePushViewExitLive)]) {
        [_delegate onePushViewExitLive];
    }
}

#pragma mark -- 开始直播/停止直播 按钮点击
- (void)streamStartButtonClicked:(id)sender {
    
    //[self.kit.streamerBase startStream:[NSURL URLWithString:_pushURL]];
    if(!self.curViewController) {
          self.curViewController = [self getViewController:self];
      }
      
      UIAlertController *alert = nil;
      
      AVAuthorizationStatus status = [AVCaptureDevice authorizationStatusForMediaType:AVMediaTypeVideo];
      if(status == AVAuthorizationStatusDenied || status == AVAuthorizationStatusRestricted) {
          alert = [UIAlertController alertControllerWithTitle:@"需要\"相机\"使用权限" message:@"请在系统\"设置\"--\"OFweek\"--\"相机\"启用权限" preferredStyle:UIAlertControllerStyleAlert];
          __weak typeof(alert) weakAlert = alert;
          
          [weakAlert addAction:[UIAlertAction actionWithTitle:@"知道了" style:UIAlertActionStyleDefault handler:^(UIAlertAction *action) {
          }]];
          
          [self.curViewController presentViewController:weakAlert animated:NO completion:nil];
          return;
      }
      
      status = [AVCaptureDevice authorizationStatusForMediaType:AVMediaTypeAudio];
      if(status == AVAuthorizationStatusDenied || status == AVAuthorizationStatusRestricted) {
          alert = [UIAlertController alertControllerWithTitle:@"需要\"麦克风\"使用权限" message:@"请在系统\"设置\"--\"OFweek\"--\"麦克风\"启用权限" preferredStyle:UIAlertControllerStyleAlert];
          __weak typeof(alert) weakAlert = alert;
          [weakAlert addAction:[UIAlertAction actionWithTitle:@"知道了" style:UIAlertActionStyleDefault handler:^(UIAlertAction *action) {
          }]];
          
          [self.curViewController presentViewController:weakAlert animated:NO completion:nil];
          return;
      }
    if (self.delegate && [self.delegate respondsToSelector:@selector(onePushViewStartButtonClicked)]) {
        [self.delegate onePushViewStartButtonClicked];
    }
     
}

#pragma mark - Setter & Getter
- (BDCloudAVLiveSession *)session {
    if (!_session) {
        NSURL *pushURL = [NSURL URLWithString:@"rtmp://fms.ofweek.com/live/test"];
        BDCloudAVVideoOutputSettings *avVideoOutputSettings = [BDCloudAVVideoOutputSettings defaultSettings];
        BDCloudAVAudioOutputSettings *avAudioOutputSettings = [BDCloudAVAudioOutputSettings defaultSettings];
        avAudioOutputSettings.quality = AVAudioQualityHigh;
        _session = [[BDCloudAVLiveSession alloc] initWithURL:pushURL captureConfig:self.avCapturesettings videoSettings:avVideoOutputSettings audioSettings:avAudioOutputSettings];
        _session.delegate = self;
        // _session.scalingMode = BDCloudAVCapturePreviewScalingModeAspectFill;
        LFGPUImageBeautyFilter *filter = [[LFGPUImageBeautyFilter alloc]init];
        [filter setBrightLevel:0.8];
        [filter setBeautyLevel:0.7];
        [_session addFilter:filter];
    }
    return _session;
}

- (BDCloudAVCaptureSettings *)avCapturesettings {
    if (!_avCapturesettings) {
        _avCapturesettings = [BDCloudAVCaptureSettings defaultSettings];
        // 前置摄像头
        _avCapturesettings.cameraPosition = AVCaptureDevicePositionFront;
    }
    return _avCapturesettings;
}

- (UIButton *)torchButton {
    if (!_torchButton) {
        _torchButton = [[UIButton alloc] init];
        _torchButton.translatesAutoresizingMaskIntoConstraints =  NO;
        [_torchButton setImage:[UIImage imageNamed:@"light"] forState:UIControlStateNormal];
        [_torchButton addTarget:self action:@selector(onFlash) forControlEvents:UIControlEventTouchUpInside];
    }
    return _torchButton;
}

- (UIButton *)switchCameraButton {
    if (!_switchCameraButton) {
        //翻转摄像头
        _switchCameraButton = [[UIButton alloc] init];
        _switchCameraButton.translatesAutoresizingMaskIntoConstraints =  NO;
        [_switchCameraButton setImage:[UIImage imageNamed:@"turn"] forState:UIControlStateNormal];
        [_switchCameraButton addTarget:self action:@selector(onCameraToggle) forControlEvents:UIControlEventTouchUpInside];
    }
    return _switchCameraButton;
}

- (SpreadButton *)streamStartButton {
    if (!_streamStartButton) {
        _streamStartButton = [SpreadButton buttonWithType:UIButtonTypeSystem];
        _streamStartButton.backgroundColor = [UIColor colorWithRed:0 green:0 blue:0 alpha:0.45];
        _streamStartButton.layer.cornerRadius = 6;
        _streamStartButton.clipsToBounds = YES;
        _streamStartButton.minimumHitTestWidth = 150;
        _streamStartButton.minimumHitTestHight = 80;
        _streamStartButton.translatesAutoresizingMaskIntoConstraints = NO;
        [_streamStartButton setTitle:@"开启直播" forState:UIControlStateNormal];
        [_streamStartButton setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
        [_streamStartButton addTarget:self action:@selector(streamStartButtonClicked:) forControlEvents:UIControlEventTouchUpInside];
    }
    return _streamStartButton;
}

- (UIImageView *)shadowup {
    if (!_shadowup) {
        _shadowup = [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"shadowup"]];
        _shadowup.userInteractionEnabled = YES;
        _shadowup.translatesAutoresizingMaskIntoConstraints = NO;
    }
    return _shadowup;
}

- (UIView *)redPoint {
    if (!_redPoint) {
        _redPoint = [[UIView alloc] init];
        _redPoint.backgroundColor = [UIColor redColor];
        // [UIColor vi_colorWithHex:0xe65e50];
        _redPoint.layer.cornerRadius = 3;
        _redPoint.hidden = YES;
    }
    return _redPoint;
}

// 连接状态
- (void)setRtmpStatus:(OnePushRTMPStatus)rtmpStatus {
    
    dispatch_async(dispatch_get_main_queue(), ^{
        switch (rtmpStatus) {
             case OnePushRTMPReady:
                 _streamStartButton.userInteractionEnabled = YES;
                 [_streamStartButton setTitle:@"开启直播" forState:UIControlStateNormal];
                 _redPoint.hidden = YES;
                 break;
             case OnePushRTMPConect:
                 _streamStartButton.userInteractionEnabled = YES;
                  [_streamStartButton setTitle:@"停止直播" forState:UIControlStateNormal];
                  _redPoint.hidden = NO;
                 
                 break;
             case OnePushRTMPError:
                 _streamStartButton.userInteractionEnabled = YES;
                  [_streamStartButton setTitle:@"开启直播" forState:UIControlStateNormal];
                  _redPoint.hidden = YES;
                 break;
                 
         }
    });
 
}

@end
