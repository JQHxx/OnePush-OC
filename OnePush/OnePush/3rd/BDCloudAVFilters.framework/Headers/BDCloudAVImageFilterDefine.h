//
//  BDCloudAVImageFilterDefine.h
//  BDCloudAVFilters
//
//  Created by Bai,Lu(CBU) on 2017/3/30.
//  Copyright © 2017年 Baidu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>


// Depend on vendor library GPUImage.
// https://github.com/BradLarson/GPUImage

// Forward declaration.
@protocol GPUImageInput;
@class GPUImageOutput;
@class GPUImageFilter;

// Custom image input could receive and process image.
typedef id<GPUImageInput> BDCloudAVCustomImageInput;

// Custom image filter could receive and process image, and also have dispatch image ability.
typedef GPUImageOutput<GPUImageInput> BDCloudAVCustomImageFilter;
