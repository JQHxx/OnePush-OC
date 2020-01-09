//
//  BDCloudAVColorAdjustFilter.h
//  BDCloudAVFilters
//
//  Created by Andy Young on 19/04/2017.
//  Copyright © 2017 Baidu. All rights reserved.
//

#ifndef BDCloudAVColorAdjustFilter_h
#define BDCloudAVColorAdjustFilter_h

#import "BDCloudAVImageFilterDefine.h"
#import <GPUImage/GPUImageFilterGroup.h>

@interface BDCloudAVColorAdjustFilter : GPUImageFilterGroup

/** 对比度，from 0.0 to 4.0, with 1.0 as the normal level */
@property (nonatomic, assign) CGFloat contrastLevel;
/** 亮度，from -1.0 to 1.0, with 0.0 as the normal level */
@property (nonatomic, assign) CGFloat brightLevel;
/** 曝光度，from -10.0 to 10.0, with 0.0 as the normal level */
@property (nonatomic, assign) CGFloat exposureLevel;
/** 色温，from -180.0 to 180.0, with 0.0 as the normal level */
@property (nonatomic, assign) CGFloat hueLevel;
/** 饱和度，from 0.0 to 2.0, with 1.0 as the normal level */
@property (nonatomic, assign) CGFloat saturationLevel;
/** 锐度，from -4.0 to 4.0, with 0.0 as the normal level */
@property (nonatomic, assign) CGFloat sharpenLevel;

@end


#endif /* BDCloudAVColorAdjustFilter_h */
