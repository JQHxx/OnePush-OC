//
//  BDCloudAVChromaKeyBlendFilter.h
//  BDCloudAVFilters
//
//  Created by Liu,Yawen(CBU) on 2018/2/2.
//  Copyright © 2018年 Baidu. All rights reserved.
//

#import <GPUImage/GPUImageTwoInputFilter.h>

@interface BDCloudAVChromaKeyBlendFilter : GPUImageTwoInputFilter
{
    GLint colorToReplaceUniform, thresholdSensitivityUniform, smoothingUniform;
}

/**
 The threshold sensitivity controls how similar pixels need to be colored to be replaced
 
 The default value is 0.3
 */
@property (readwrite, nonatomic) CGFloat thresholdSensitivity;

/**
 The degree of smoothing controls how gradually similar colors are replaced in the image
 
 The default value is 0.1
 */
@property (readwrite, nonatomic) CGFloat smoothing;

/**
 The new background image.
 */
@property (nonatomic, strong) UIImage *backgroundImage;

/**
 The color to be replaced is specified using individual red, green, and blue components (normalized to 1.0).
 
 The default is green: (0.0, 1.0, 0.0).
 
 @param redComponent Red component of color to be replaced
 @param greenComponent Green component of color to be replaced
 @param blueComponent Blue component of color to be replaced
 */
- (void)setColorToReplaceRed:(GLfloat)redComponent green:(GLfloat)greenComponent blue:(GLfloat)blueComponent;

@end
