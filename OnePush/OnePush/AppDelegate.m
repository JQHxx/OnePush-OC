//
//  AppDelegate.m
//  OnePush
//
//  Created by OFweek01 on 2020/1/9.
//  Copyright © 2020 OFweek01. All rights reserved.
//

#import "AppDelegate.h"
#import "ViewController.h"
/*
#import <BDCloudAVBase/BDCloudAVBase.h>
// #import <BDCloudAVFilters/BDCloudAVFilters.h>
#import <BDCloudAVSource/BDCloudAVSource.h>
#import <BDCloudAVUtil/BDCloudAVUtil.h>
// #import <BDCloudAVPlayer/BDCloudAVPlayer.h>
#import <BDCloudAVWriter/BDCloudAVWriter.h>
 */

#import <BDCloudAVLicense/BDCloudAVLicense.h>


@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    self.window = [[UIWindow alloc]initWithFrame:[UIScreen mainScreen].bounds];
    self.window.backgroundColor = [UIColor whiteColor];
    self.window.rootViewController = [ViewController new];
    [self.window makeKeyAndVisible];
    
//    BDCloudAVAuthCredential *credential = [[BDCloudAVAuthCredential alloc] init];
//    credential.userId = @"<userId>";
//    credential.accessKey = @"<accessKey>";
//    credential.secretKey = @"<secretKey>";
//
//    // AK/SK方式鉴权
//    // 鉴权成功，error为nil
//    // 鉴权失败，返回相应的error信息
//    [BDCloudAVAuthentication authenticateWithCredential:credential completionHandler:^(NSError *error) {
//        if (error) {
//            NSLog(@"authenticate error, %@",error);
//        }
//    }];
    return YES;
}


@end
