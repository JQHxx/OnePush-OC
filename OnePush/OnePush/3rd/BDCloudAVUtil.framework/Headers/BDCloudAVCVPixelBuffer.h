//
//  BDCloudAVCVPixelBuffer.h
//  BDCloudAVUtil
//
//  Created by Bai,Lu(CBU) on 18/10/2017.
//  Copyright © 2017 Baidu. All rights reserved.
//

#import <CoreMedia/CoreMedia.h>

@interface BDCloudAVCVPixelBuffer : NSObject

+ (instancetype)fromCVPxielBuffer:(CVPixelBufferRef)pixelBuffer;

@property(nonatomic, readonly) CVPixelBufferRef buffer;
@property(nonatomic, readonly) size_t width;
@property(nonatomic, readonly) size_t height;
@property(nonatomic, readonly) size_t planes;

- (NSString*)stringAttachment:(NSString*)key;
- (NSNumber*)numberAttachment:(NSString*)key;

- (BOOL)lock:(BOOL)readonly;
- (BOOL)unlock;

@end
