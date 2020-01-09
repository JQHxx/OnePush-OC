//
//  BDCloudAVImageFilterSetting.h
//  BDCloudAVFilters
//
//  Created by Liu,Yawen(CBU) on 2018/1/16.
//  Copyright © 2018年 Baidu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <BDCloudAVFilters/BDCloudAVFilters.h>

typedef NS_ENUM(NSUInteger, BDCloudAVFilterType) {
    BDCloudAVFilterTypeSpeed,
    BDCloudAVFilterTypeBeauty,
    BDCloudAVFilterTypeColorAdjust,
    BDCloudAVFilterTypeStyle,
    BDCloudAVFilterTypeChromaBlend,
    BDCloudAVFilterTypeUIElement,
    BDCloudAVFilterTypeBeautyAndUIElement
};

typedef NS_ENUM(NSUInteger, BDCloudAVStyleFilterType) {
    BDCloudAVStyleFilterTypeNone,
    BDCloudAVStyleFilterTypeAmaro,
    BDCloudAVStyleFilterTypeBrannan,
    BDCloudAVStyleFilterTypeEarlybird,
    BDCloudAVStyleFilterTypeHefe,
    BDCloudAVStyleFilterTypeNashville,
    BDCloudAVStyleFilterTypeRise,
    BDCloudAVStyleFilterTypeSierra,
    BDCloudAVStyleFilterTypeToaster,
    BDCloudAVStyleFilterTypeValencia,
    BDCloudAVStyleFilterTypeXproII
};

@interface BDCloudAVImageFilterSetting : NSObject

/**
 Extra custom filters.
 */
@property (nonatomic, strong, readonly) NSMutableArray <BDCloudAVCustomImageFilter *> *extraFilters;

/**
 Speed filter.
 */
@property (nonatomic, strong, readonly) BDCloudAVSpeedFilter *speedFilter;

/**
 Beauty filter.
 */
@property (nonatomic, strong, readonly) BDCloudAVARFaceBeautyFilter *beautyFilter;

/**
 Color adjust filter.
 */
@property (nonatomic, strong, readonly) BDCloudAVColorAdjustFilter *colorFilter;

/**
 Style filter.
 */
@property (nonatomic, strong, readonly) BDCloudAVCustomImageFilter *styleFilter;

/**
 Chroma key blend filter.
 */
@property (nonatomic, strong, readonly) BDCloudAVChromaKeyBlendFilter *blendFilter;

/**
 Add UI Element filter
 */
@property (nonatomic,strong,readonly) BDCloudAVUIElementFilter *uiElementFilter;

/**
 Add Beauty and UI Element Group filter
 */
@property (nonatomic, strong, readonly) BDCloudAVFaceBeautyGroupFilter *beautyGroupFilter;

/**
 Initialize with image filter.

 @param filter image filter.
 @return instance.
 */
- (instancetype)initWithImageFilter:(BDCloudAVImageFilter *)filter;

/**
 Initialize with image filter setting and image filter.

 @param setting image filter setting.
 @param filter image filter.
 @return instance.
 */
- (instancetype)initWithImageFilterSetting:(BDCloudAVImageFilterSetting *)setting imageFilter:(BDCloudAVImageFilter *)filter;

/**
 Add extra filter.

 @param filter filter.
 */
- (void)addFilter:(BDCloudAVCustomImageFilter *)filter;

/**
 Remove extra filter.

 @param filter filter.
 */
- (void)removeFilter:(BDCloudAVCustomImageFilter *)filter;

/**
 Add builtin filter.
 SubType can be set to BDCloudAVStyleFilterTypeNone when filter type is not BDCloudAVFilterTypeStyle.

 @param type image filter type.
 @param subType style filter type.
 */
- (void)addFilterWithType:(BDCloudAVFilterType)type styleType:(BDCloudAVStyleFilterType)subType;

/**
 Remove builtin filter.

 @param type image filter type.
 */
- (void)removeFilterWithType:(BDCloudAVFilterType)type;

/**
 Set speed filter's speed.

 @param level speed level.
 */
- (void)setSpeedLevel:(float)level;

/**
 Set speed filter's paused enabled. Default value is NO.
 If you want to pause the video frame, make sure you call this method before a speed filter already exist.

 @param pauseEnabled pause Enabled.
 */
- (void)setPauseEnabled:(BOOL)pauseEnabled;

/**
 Set beauty Group filter's beauty level.
 
 @param level beauty level.
 */
- (void)setBeautyGroupLevel:(CGFloat)level;

/**
 Set beauty Group filter's skin level.
 
 @param level bright level.
 */
- (void)setSkinGroupLevel:(CGFloat)level;

/**
 Set beauty Group filter's eye level.
 
 @param level eye level.
 */
- (void)setEyeGroupLevel:(CGFloat)level;

/**
 Set beauty Group filter's face level.
 
 @param level face level.
 */
- (void)setFaceGroupLevel:(CGFloat)level;

/**
 Set beauty Group color filter's id.
 
 @param filterId face filter id.
 */
- (void)setColorGroupFilterLevel:(NSString *)filterId value:(CGFloat)prefer;

/**
 Set beauty filter's beauty level.

 @param level beauty level.
 */
- (void)setBeautyLevel:(CGFloat)level;

/**
 Set beauty filter's skin level.

 @param level bright level.
 */
- (void)setSkinLevel:(CGFloat)level;

/**
 Set beauty filter's eye level.
 
 @param level eye level.
 */
- (void)setEyeLevel:(CGFloat)level;

/**
 Set beauty filter's face level.
 
 @param level face level.
 */
- (void)setFaceLevel:(CGFloat)level;

/**
 Set beauty color filter's id.
 
 @param filterId face filter id.
 */
- (void)setColorFilterLevel:(NSString *)filterId value:(CGFloat)prefer;

/**
 Set beauty filter's tone level.

 @param level tone level.
 */
- (void)setBeautyTone:(CGFloat)level;

- (void)setSticker:(NSString *)stickerPath type:(NSString *)type;
/**
 Set color filter's contrast level.

 @param level contrast level.
 */
- (void)setColorContrast:(CGFloat)level;

/**
 Set color filter's bright level.
 
 @param level bright level.
 */
- (void)setColorBright:(CGFloat)level;

/**
 Set color filter's exposure level.
 
 @param level exposure level.
 */
- (void)setColorExposure:(CGFloat)level;

/**
 Set color filter's hue level.

 @param level hue level.
 */
- (void)setColorHue:(CGFloat)level;

/**
 Set color filter's saturation level.

 @param level saturation level.
 */
- (void)setColorSaturation:(CGFloat)level;

/**
 Set color filter's sharpen level.

 @param level sharpen level.
 */
- (void)setColorSharpen:(CGFloat)level;

/**
 Set blend filter's new background image.

 @param image image.
 */
- (void)setNewBackgroundImage:(UIImage *)image;

/**
 Set blend filter's threshold sensitivity, the default value is 0.3.
 The threshold sensitivity controls how similar pixels need to be colored to be replaced.
 If you want to set this value, make sure you call this method before a blend filter already exist.

 @param thresholdSensitivity thresholdSensitivity
 */
- (void)setChromaBlendThresholdSensitivity:(CGFloat)thresholdSensitivity;

/**
 Set blend filter's smoothing, the default value is 0.1.
 The degree of smoothing controls how gradually similar colors are replaced in the image.
 If you want to set this value, make sure you call this method before a blend filter already exist.

 @param smoothing smoothing
 */
- (void)setChromaBlendSmoothing:(CGFloat)smoothing;

/**
 Set blend filter's color to be replaced, the default is green: (0.0, 1.0, 0.0).
 If you want to set the color, make sure you call this method before a blend filter already exist.

 @param redComponent Red component of color to be replaced.
 @param greenComponent Green component of color to be replaced.
 @param blueComponent Blue component of color to be replaced.
 */
- (void)setColorToReplaceRed:(GLfloat)redComponent green:(GLfloat)greenComponent blue:(GLfloat)blueComponent;

@end
