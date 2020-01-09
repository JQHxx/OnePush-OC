//
//  BDCloudAVFileOutput.h
//  BDCloudAVToolbox
//
//  Created by Bai,Lu(CBU) on 2017/3/16.
//  Copyright © 2017年 Baidu. All rights reserved.
//

#import <BDCloudAVBase/BDCloudAVOutput.h>
#import <AVFoundation/AVFoundation.h>
#import "BDCloudAVFileOutputInterface.h"

/**
 File output delegate methods.
 */
@protocol BDCloudAVFileOutputDelegate <BDCloudAVFileOutputReaderDelegate>
@optional

/**
 File reader initialized.

 @param error if error is nil, initialize success.
 */
- (void)readInitialized:(NSError*)error;

@end

/**
 Read video and audio frame from file.
 Inherits from BDCloudAVDualOutput, have video and audio CMSampleBuffer dispatch ability.
 */
@interface BDCloudAVFileOutput : BDCloudAVDualOutput <BDCloudAVFileOutputControlInterface>

/**
 Toggle audio. Default value is YES.
 If you want to disable audio tracks, make sure you call this method before preparetoread.
 */
@property(nonatomic) BOOL audioEnable;

/**
 Toggle video. Default value is YES.
 If you want to disable video tracks, make sure you call this method before preparetoread.
 */
@property(nonatomic) BOOL videoEnable;

/**
 Delegate
 */
@property(nonatomic, weak) id<BDCloudAVFileOutputDelegate> delegate;

/**
 The file URL.
 */
@property(nonatomic, copy, readonly) NSURL* url;

/**
 Indicates whether the file contains video tracks.
 */
@property(nonatomic, readonly) BOOL hasVideoTrack;

/**
 Indicates whether the file contains audio tracks.
 */
@property(nonatomic, readonly) BOOL hasAudioTrack;

/**
 Current read progress.
 */
@property(nonatomic, readonly) float progress;

/**
 The file's video orientation.
 */
@property(nonatomic, readonly) AVCaptureVideoOrientation orientation;

/**
 The file's video transform.
 */
@property(nonatomic, readonly) CGAffineTransform transform;

/**
 Video dimensions.
 */
@property(nonatomic, readonly) CGSize dimensions;

/**
 The file's video fps.
 */
@property(nonatomic, readonly) float fps;

/**
 The file's duration.
 */
@property(nonatomic, readonly) CMTime duration;

/**
 The range to read. Default value is kCMTimeRangeZero, means to read the whole file.
 */
@property(nonatomic) CMTimeRange range;

/**
 Initialize with file url.

 @param url file url.
 @return instance.
 */
- (instancetype)initWithURL:(NSURL*)url;

@end

