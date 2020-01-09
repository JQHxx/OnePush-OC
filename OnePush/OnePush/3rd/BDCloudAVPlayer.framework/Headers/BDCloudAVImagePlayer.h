//
//  BDCloudAVImagePlayer.h
//  BDCloudAVPlayer
//
//  Created by Bai,Lu(CBU) on 2017/4/21.
//  Copyright © 2017年 Baidu. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <GPUImage/GPUImageContext.h>
#import <BDCloudAVBase/BDCloudAVBase.h>

/**
 Image fill mode.
 
 - BDCloudAVImagePlayerFillModeStretch: Stretch to fill the full view, which may distort the image outside of its normal aspect ratio.
 - BDCloudAVImagePlayerFillModePreserveAspectRatio: Maintains the aspect ratio of the source image, adding bars of the specified background color.
 - BDCloudAVImagePlayerFillModePreserveAspectRatioAndFill: Maintains the aspect ratio of the source image, zooming in on its center to fill the view.
 */
typedef NS_ENUM(NSUInteger, BDCloudAVImagePlayerFillMode) {
    BDCloudAVImagePlayerFillModeStretch,
    BDCloudAVImagePlayerFillModePreserveAspectRatio,
    BDCloudAVImagePlayerFillModePreserveAspectRatioAndFill
};

/**
 Image player.
 Implements protocol GPUImageInput, have receive and process GPUImageFrameBuffer ability.
 Implements protocol BDCloudAVControl, have play action control ability.
 
 */
@interface BDCloudAVImagePlayer : NSObject<GPUImageInput, BDCloudAVControl>

/**
 Render view.
 */
@property(nonatomic, strong, readonly) UIView* view;

/**
 Image fill mode. The default value is BDCloudAVImagePlayerFillModePreserveAspectRatioAndFill.
 */
@property(nonatomic) BDCloudAVImagePlayerFillMode fillMode;

/**
 Initialize with input delegate.
 
 @param delegate input delegate.
 @return instance.
 */
- (instancetype)initWithDelegate:(id<BDCloudAVInputDelegate>)delegate;
@end
