//
//  BDCloudAVScaleFilter.h
//  BDCloudAVFilters
//
//  Created by baidu on 2019/6/20.
//  Copyright © 2019 Baidu. All rights reserved.
//

#import <GPUImage/GPUImageFilter.h>

NS_ASSUME_NONNULL_BEGIN

@interface BDCloudAVScaleFilter : GPUImageFilter
@property(readwrite, nonatomic) CGFloat time; //动画时间
@end

NS_ASSUME_NONNULL_END
