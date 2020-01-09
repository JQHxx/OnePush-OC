//
//  ViewController.m
//  OnePush
//
//  Created by OFweek01 on 2020/1/9.
//  Copyright © 2020 OFweek01. All rights reserved.
//

#import "ViewController.h"
#import "OFOnePushView.h"

@interface ViewController ()

@property (nonatomic, strong) OFOnePushView *bgView;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    
    self.bgView = [[OFOnePushView alloc]initWithProtrait];
    [self.bgView startStream:@"rtmp://3891.livepush.myqcloud.com/live/3891_user_9564b556_7194?bizid=3891&txSecret=50d979e28b29ab23c9923f7832e6a328&txTime=5E16E305"];
    [self.view addSubview:self.bgView];
    // Do any additional setup after loading the view.
}


@end
