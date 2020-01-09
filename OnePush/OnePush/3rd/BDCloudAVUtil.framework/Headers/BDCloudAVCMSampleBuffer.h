//
//  BDCloudAVCMSampleBuffer.h
//  BDCloudAVUtil
//
//  Created by Bai,Lu(CBU) on 18/10/2017.
//  Copyright © 2017 Baidu. All rights reserved.
//

#import <CoreMedia/CoreMedia.h>

@class BDCloudAVCVPixelBuffer;
@class BDCloudAVAudioBufferList;
@class BDCloudAVFormatDescription;


@interface BDCloudAVCMSampleBuffer : NSObject

+ (instancetype)fromCMSampleBuffer:(CMSampleBufferRef)buffer;

+ (instancetype)fromPixelBuffer:(BDCloudAVCVPixelBuffer*)pixelBuffer
                            pts:(CMTime)pts
                       duration:(CMTime)duration;

+ (instancetype)fromAudioBufferList:(BDCloudAVAudioBufferList*)abl
                                pts:(CMTime)pts;

+ (instancetype)fromEncodedAudioBuffer:(uint8_t*)buffer
                                length:(uint32_t)length
                               samples:(uint32_t)samples
                                  asbd:(const AudioStreamBasicDescription*)asbd
                                  aspd:(const AudioStreamPacketDescription*)aspd
                                   pts:(CMTime)pts;

@property(nonatomic, readonly) CMSampleBufferRef buffer;

@property(nonatomic, readonly, strong) BDCloudAVFormatDescription* format;
@property(nonatomic, readonly, strong) BDCloudAVAudioBufferList* abl;
@property(nonatomic, readonly, strong) BDCloudAVCVPixelBuffer* pixelBuffer;

@property(nonatomic, readonly) CMTime pts;
@property(nonatomic, readonly) CMTime duration;

@property(nonatomic, readonly) CMTime dts;
@property(nonatomic, readonly, strong) NSArray* attachments;
@property(nonatomic, readonly) char* data;
@property(nonatomic, readonly) size_t length;

@property(nonatomic, readonly) uint32_t samples;
@end
