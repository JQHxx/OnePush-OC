//
//  BDCloudAVConcatFileOutput.h
//  BDCloudAVSource
//
//  Created by blue on 13/12/2017.
//  Copyright © 2017 Baidu. All rights reserved.
//

#import <BDCloudAVBase/BDCloudAVBase.h>
#import "BDCloudAVFileOutputInterface.h"

@class BDCloudAVFileOutput;

/**
 Concat multi file into one file.
 Inherits from BDCloudAVDualOutput, have video and audio CMSampleBuffer dispatch ability.
 */
@interface BDCloudAVConcatFileOutput : BDCloudAVDualOutput <BDCloudAVFileOutputControlInterface>

/**
 Delegate.
 */
@property(nonatomic, weak) id<BDCloudAVFileOutputReaderDelegate> delegate;

/**
 File output array.
 */
@property(nonatomic, strong, readonly) NSArray<BDCloudAVFileOutput*>* fileOutputs;

/**
 The duration of the generated file.
 */
@property(nonatomic, readonly) CMTime duration;

/**
 Initialize with file url array.

 @param files file url array.
 @return instance.
 */
- (instancetype)initWithFiles:(NSArray<NSURL*>*)files;

/**
 Toggle video. Default value is YES.
 If you want to disable video tracks, make sure you call this method before prepareToRead.
 */
@property(nonatomic) BOOL videoEnable;

/**
 Toggle audio. Default value is YES.
 If you want to disable audio tracks, make sure you call this method before prepareToRead.
 */
@property(nonatomic) BOOL audioEnable;

@end
