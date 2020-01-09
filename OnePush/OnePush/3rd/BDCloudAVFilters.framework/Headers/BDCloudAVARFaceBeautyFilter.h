//
//  BDCloudAVARFaceBeautyFilter.h
//  BDCloudAVFaceSticker
//
//  Created by baidu on 2019/2/25.
//  Copyright © 2019 Baidu. All rights reserved.
//

#import <GPUImage/GPUImageFilter.h>

NS_ASSUME_NONNULL_BEGIN

@interface BDCloudAVARFaceBeautyFilter : GPUImageFilter
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
@end

NS_ASSUME_NONNULL_END
