//
//  BDCloudAVSurfaceBlurFilter.h
//  BDCloudAVFilters
//
//  Created by Andy Young on 29/08/2017.
//  Copyright © 2017 Baidu. All rights reserved.
//

#ifndef BDCloudAVSurfaceBlurFilter_h
#define BDCloudAVSurfaceBlurFilter_h
#import "BDCloudAVImageFilterDefine.h"
#import <GPUImage/GPUImageTwoPassTextureSamplingFilter.h>

@interface BDCloudAVSurfaceBlurFilter : GPUImageTwoPassTextureSamplingFilter

-(id) init;
-(id) initWithBlurSize: (GLfloat) blurSize
           andThrehold: (GLfloat) threhold;

@property(nonatomic, assign) GLfloat threhold;

@end

#endif /* BDCloudAVSurfaceBlurFilter_h */
