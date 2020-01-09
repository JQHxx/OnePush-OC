//
//  BDCloudAVInput.h
//  BDCloudAVToolbox
//
//  Created by Bai,Lu(CBU) on 2017/3/15.
//  Copyright © 2017年 Baidu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreMedia/CoreMedia.h>
#import <AVFoundation/AVFoundation.h>
#import <VideoToolbox/VideoToolbox.h>
#import <AudioToolbox/AudioToolbox.h>
#import <AudioUnit/AudioUnit.h>

/**
 Interface implements this protocol could receive and process CMSampleBuffer.
 An id<BDCloudAVInput> instance is usually located in the middle or end of the process chain.
 
 eg:
    BDCloudAVOutput ---> BDCloudAVOutput<BDCloudAVInput> ---> id<BDCloudAVInput>
 
 */
@protocol BDCloudAVInput <NSObject>

/**
 Receive and process a specific type of CMSampleBuffer.
 If the processing is asynchronous, call CFRetain(frame) first, and CFRelease(frame) after process completed.

 @param frame CMSampleBuffer
 @param type CMSampleBuffer type, could be AVMediaTypeVideo or AVMediaTypeAudio.
 */
- (void)frame:(CMSampleBufferRef)frame type:(NSString*)type;
@end

/**
 Typically, processing has push mode and pull mode.
 If the processing is pull mode, an id<BDCloudAVInput> instance need to require CMSampleBuffer manually by call readVideoFrame and readAudioFrame.
 
 A. push mode: audio/video data from AVCaptureSession to an id<BDCloudAVInput> continuous.
 
     AVCaptureSession ---> Video/Audio Filter ---> Writer
 
 B. pull mode: Writer ready for process audio/video data from an Reader.
 
                    2                      3
            Reader ---> Video/Audio Filter --->  Writer
            ^                                      |
            |                                      |
            |______________________________________|
                 1.readVideoFrame/readAudioFrame
 */
@protocol BDCloudAVInputDelegate <NSObject>

/**
 Require a video CMSampleBuffer.

 @return Require result.
 */
- (BOOL)readVideoFrame;

/**
 Require a audio CMSampleBuffer.

 @return Require result.
 */
- (BOOL)readAudioFrame;
@end

/**
 Similar to BDCloudAVInput, it deals with encoded binary data buffer.
 */
@protocol BDCloudAVBinaryInput <NSObject>

/**
 Receive and process a specific type of encoded binary data buffer.

 @param buffer the encoded binary data.
 @param length data length.
 @param type data type, could be AVMediaTypeVideo or AVMediaTypeAudio.
 @param meta meta data.
 */
- (void)binaryFrame:(uint8_t*)buffer length:(NSUInteger)length type:(NSString*)type metadata:(NSDictionary*)meta;
@end
