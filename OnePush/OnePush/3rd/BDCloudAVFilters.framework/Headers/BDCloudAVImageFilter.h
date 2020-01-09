//
//  BDCloudAVImageFilter.h
//  BDCloudAVToolbox
//
//  Created by Bai,Lu(CBU) on 2017/3/16.
//  Copyright © 2017年 Baidu. All rights reserved.
//

#import <BDCloudAVBase/BDCloudAVBase.h>
#import "BDCloudAVImageFilterDefine.h"

/**
 Image filter provides the ability to process images in sub filter chain.
 Inherits from BDCloudAVOutput, have image CMSampleBuffer dispatch ability.
 Implements protocol BDCloudAVInput, have receive and process image CMSampleBuffer ability.
 
 Image process graph:
 
                                    |capture/file output|
                                              |
                                              | image
                           ___________________|______________________
                           |                  |                     |
                           |                  |                     |
                           V                  V                     V
                  |initial filter 1|   |initial filter 2|  ... |initial filter N|
                           |                  |                     |
                           |                  V                     |
                           |---------> |terminal filter| <----------|
                                              |
                                              |-------------> |preview target|
                                              |
                                              V
                                         |next step|

 
 */
@interface BDCloudAVImageFilter : BDCloudAVOutput<BDCloudAVInput>

/**
 The header of the sub filter chain.
 */
@property(nonatomic, strong) NSArray<BDCloudAVCustomImageInput>* initialFilters;

/**
 The tail of the sub filter chain.
 */
@property(nonatomic, strong) BDCloudAVCustomImageFilter* terminalFilter;

/**
 Add preview target. Typically is a GPUImageView.

 @param target target.
 */
- (void)addPreviewTarget:(BDCloudAVCustomImageInput)target;

/**
 Remove preview target.

 @param target target.
 */
- (void)removePreviewTarget:(BDCloudAVCustomImageInput)target;

/**
 Set input orientation.
 Orientation will apply on preview target.

 @param orientation orientation.
 */
- (void)setInputOrientation:(AVCaptureVideoOrientation)orientation;

/**
 Reset image filter.
 @discussion Please call this method before link filters pipeline.
 */
- (void)reset;

@end
