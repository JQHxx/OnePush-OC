//
//  BDCloudAVMovieWriter.h
//  BDCloudAVWriter
//
//  Created by Bai,Lu(CBU) on 2017/3/22.
//  Copyright © 2017年 Baidu. All rights reserved.
//

#import <BDCloudAVBase/BDCloudAVBase.h>
#import <BDCloudAVUtil/BDCloudAVUtil.h>

/**
 Movie writer delegate.
 */
@protocol BDCloudAVMovieWriterDelegate <NSObject>
@optional

/**
 Start write with first frame's pts.

 @param startTime first frame's pts.
 */
- (void)writeStarted:(CMTime)startTime;

/**
 Write frame failure with error.

 @param error error.
 */
- (void)writeFrameFailure:(NSError*)error;

/**
 If writer is busying, frame will be dropped.
 */
- (void)writeFrameDropped;

/**
 Finish write with last frame's pts.
 If error is not nil, means finish write action (by call stop) is failure.

 @param endTime last frame's pts.
 @param error error.
 */
- (void)writeFinishedAtTime:(CMTime)endTime error:(NSError*)error;
@end

/**
 Movie output parameters.
 */
@interface BDCloudAVMovieParameter : NSObject

/**
 The file url which movie will save to.
 */
@property(nonatomic, copy) NSURL* url;

/**
 The video encoder settings.
 If videoSettings set to nil, the generated file will not contain video track.
 */
@property(nonatomic, strong) BDCloudAVVideoOutputSettings* videoSettings;

/**
 The audio encoder settings.
 If audioSettings set to nil, the generated file will not contain audio track.
 */
@property(nonatomic, strong) BDCloudAVAudioOutputSettings* audioSettings;
@end

/**
 Movie writer receive audio/video frames, after encoding, write to a moive file.
 Implements protocol BDCloudAVInput, have receive and process audio/video CMSampleBuffer ability.
 Implements protocol BDCloudAVControl, have write action control ability.
 
 Note:
     Movie write have two process mode, realtime mode and offline mode.
     If inputDelegate is set to nil, writer will in realtime mode, otherwise in offline mode.
 
     1) realtime mode: record a moive that frames from camera and microphone.

         [camera]       [microphone]       [image filter]      [audio filter]    [writer]
            |                |                   |                   |              |
            |                |   videoFrame      |                   |              |
            |---------------/|\----------------> |                   |              |
            |                |                   |                   |   videoFrame |
            |                |                   |------------------/|\-----------> |
            |                |                   |                   |              |
            |                |                   |     audioFrame    |              |
            |                |------------------/|\----------------> |              |
            |                |                   |                   |   audioFrame |
            |                |                   |                   |------------> |
            |                |                   |                   |              |
 
     2) offline mode: read frames from a movie file, then save to a new movie file.
 
         [file output]  [image filter]      [audio filter]       [writer]
            |                |                   |                   |
            |                |   readVideoFrame  |                   |
            | <-------------/|\-----------------/|\------------------|
            |                |                   |                   |
            |   videoFrame   |                   |                   |
            | -------------> |                   |    videoFrame     |
            |                |------------------/|\----------------> |
            |                |                   |                   |
            |                |                   |                   |
            |                |                   |                   |
            |                |   readAudioFrame  |                   |
            | <-------------/|\-----------------/|\------------------|
            |                |                   |                   |
            |   audioFrame   |                   |                   |
            | --------------/|\----------------> |     audioFrame    |
            |                |                   |-----------------> |
            |                |                   |                   |
 */
@interface BDCloudAVMovieWriter : NSObject<BDCloudAVInput, BDCloudAVControl>

/**
 The file url that movie will save to.
 */
@property(nonatomic, strong, readonly) NSURL* url;

/**
 Delegate.
 */
@property(nonatomic, weak) id<BDCloudAVMovieWriterDelegate> delegate;

/**
 Input delegate.
 If set, writer process mode will change from realtime mode to offline mode.
 */
@property(nonatomic, weak) id<BDCloudAVInputDelegate> inputDelegate;

/**
 Initialize with movie settings.

 @param parameter settings.
 @return instance.
 */
- (instancetype)initWithMovieParameter:(BDCloudAVMovieParameter*)parameter;

/**
 Set input video frame's orientation transform.

 @param transform orientation.
 */
- (void)setInputTransform:(CGAffineTransform)transform;

/**
 Update movie parameter and reset internal state for another movie writing.

 @param parameter settings.
 */
- (void)updateMovieParameter:(BDCloudAVMovieParameter*)parameter;

@end
