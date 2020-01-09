//
//  BDCloudAVBeautyFilter.h
//  BDCloudAVFilters
//
//  Created by Andy Young(CBU) on 2017/8/29.
//  Copyright © 2017年 Baidu. All rights reserved.
//

#import "BDCloudAVImageFilterDefine.h"
#import <GPUImage/GPUImageFilterGroup.h>

@interface BDCloudAVNaturalBeautyFilter : GPUImageFilterGroup

/** 美颜程度 */
@property (nonatomic, assign) CGFloat beautyLevel;
/** 美白程度 */
@property (nonatomic, assign) CGFloat brightLevel;
/** 色调强度 */
@property (nonatomic, assign) CGFloat toneLevel;

@end
