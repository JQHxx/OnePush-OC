//
//  BDCloudAVFaceBeautyGroupFilter.h
//  BDCloudAVFilters
//
//  Created by baidu on 2019/6/3.
//  Copyright © 2019 Baidu. All rights reserved.
//

#import <GPUImage/GPUImageFilter.h>

NS_ASSUME_NONNULL_BEGIN
@class BDCloudAVARFaceBeautyFilter;
@class BDCloudAVCombinationGroupFilter;
@class BDCloudAVUIElementFilter;

@interface BDCloudAVFaceBeautyGroupFilter : GPUImageFilter
/** 美肤程度 */
@property(nonatomic, assign) CGFloat beautyLevel;
/** 磨皮程度 */
@property(nonatomic, assign) CGFloat skinLevel;
/**大眼程度**/
@property(nonatomic, assign) CGFloat adjustEyeLevel;
/**瘦脸程度**/
@property(nonatomic, assign) CGFloat adjustFaceLevel;
/*颜色滤镜*/
@property(nonatomic, assign) CGFloat adjustNormalLevel;

/**
 人脸贴纸
 @param stickerPath sticker.
 */
- (void)setSticker:(NSString *)stickerPath type:(NSString *)type;

/**
 切换滤镜
 @param filterId 滤镜id
 */
- (void)switchFilter:(NSString *)filterId;

/**
 ContentView will be mixed when add
 
 @param contentView mix view
 */
- (void)addContentView:(UIView *)contentView;

- (UIView *)queryAllContentView;

@end

NS_ASSUME_NONNULL_END
