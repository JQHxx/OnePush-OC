//
//  BDCloudAVSpeedFilter.h
//  BDCloudAVFilters
//
//  Created by Liu,Yawen(CBU) on 2018/1/16.
//  Copyright © 2018年 Baidu. All rights reserved.
//

#import <GPUImage/GPUImageFilter.h>

@interface BDCloudAVSpeedFilter : GPUImageFilter

@property (nonatomic, assign) float speed;
@property (nonatomic, assign) BOOL pauseEnabled;

@end
