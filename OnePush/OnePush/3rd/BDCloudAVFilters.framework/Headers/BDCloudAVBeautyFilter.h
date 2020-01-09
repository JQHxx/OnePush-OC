//
//  BDCloudAVBeautyFilter.h
//  BDCloudAVFilters
//
//  Created by Bai,Lu(CBU) on 2017/4/3.
//  Copyright © 2017年 Baidu. All rights reserved.
//

#import "BDCloudAVImageFilterDefine.h"
#import <GPUImage/GPUImageFilter.h>

@interface BDCloudAVBeautyFilter : GPUImageFilter

/** 美颜程度 */
@property (nonatomic, assign) CGFloat beautyLevel;
/** 美白程度 */
@property (nonatomic, assign) CGFloat brightLevel;
/** 色调强度 */
@property (nonatomic, assign) CGFloat toneLevel;

@end
