//
//  BDCloudAVExtraTextureFilter.h
//  BDCloudAVFilters
//
//  Created by Andy Young on 20/04/2017.
//  Copyright © 2017 Baidu. All rights reserved.
//

#ifndef BDCloudAVExtraTextureFilter_h
#define BDCloudAVExtraTextureFilter_h
#import <GPUImage/GPUImageFilter.h>

@interface BDCloudAVExtraTextureFilter : GPUImageFilter

/** 滤镜效果程度，from 0.0 to 1.0, with 1.0 as default*/
@property (nonatomic, assign) CGFloat strength;

- (id)initWithTextureNames: (NSArray<NSString*>*) textureNames andFragmentShader: (NSString*) shader;

@end

#endif /* BDCloudAVExtraTextureFilter_h */
