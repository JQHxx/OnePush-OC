//
//  BDCloudAVUIElementFilter.h
//  BDCloudAVFilters
//
//  Created by Fu,Sheng on 2018/12/5.
//  Copyright © 2018年 Baidu. All rights reserved.
//

#import <GPUImage/GPUImageFilter.h>

typedef enum : NSUInteger {
    BlendTypeNormal,// default
    BlendTypeSourceOver,
    BlendTypeColorBurn,
    BlendTypeColorDodge,
    BlendTypeDarken,
    BlendTypeDifference,
    BlendTypeDissolve,
    BlendTypeExclusion,
    BlendTypeHardLight,
    BlendTypeSoftLight,
    BlendTypeLighten,
    BlendTypeAdd,
    BlendTypeSubtract,
    BlendTypeDivide,
    BlendTypeMultiply,
    BlendTypeOverlay,
    BlendTypeScreen,
    BlendTypeAlpha,
    BlendTypeColor,
    BlendTypeHue,
    BlendTypeSaturation,
    BlendTypeLuminosity,
    BlendTypeLinearBurn,
} BlendType;

@interface BDCloudAVUIElementFilter : GPUImageFilter

/**
 instance a blend filter

 @param type blend type
 @return a blend filter
 */
- (instancetype)initWith:(BlendType)type;

/**
 ContentView will be mixed when add

 @param contentView mix view
 */
- (void)addContentView:(UIView *)contentView;

/**
 ContentView can not mixed when remove
 attation : edit contentView must be after of this func
 
 @param contentView mix view
 */
- (void)removeContentView:(UIView *)contentView;


- (UIView *)queryAllContentView;


@end


// use in BlendType: BlendTypeDissolve,BlendTypeAlpha
@interface BDCloudAVUIElementFilter (Mix)
/**
 Mix from 0.0 to 1.0

 @param mix mix prarm. Default is 0.5
 */
- (void)setMix:(CGFloat)mix;
@end

