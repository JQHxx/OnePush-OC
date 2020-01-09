//
//  BDCloudAVFormatDescription.h
//  BDCloudAVUtil
//
//  Created by Bai,Lu(CBU) on 18/10/2017.
//  Copyright © 2017 Baidu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreMedia/CoreMedia.h>

typedef NS_ENUM(NSUInteger, BDCloudAVMediaType) {
    BDCloudAVMediaTypeUnknown = 0,
    BDCloudAVMediaTypeAudio = 1,
    BDCloudAVMediaTypeVideo = 2,
    BDCloudAVMediaTypeSubtitle = 4,
};

@class BDCloudAVCVPixelBuffer;

@interface BDCloudAVFormatDescription : NSObject

+ (instancetype)fromCMFormatDescription:(CMFormatDescriptionRef)format;
+ (instancetype)fromASBD:(const AudioStreamBasicDescription*)asbd;
+ (instancetype)fromPixelBuffer:(BDCloudAVCVPixelBuffer*)buffer;

@property(nonatomic, readonly) CMFormatDescriptionRef format;
@property(nonatomic, readonly) BDCloudAVMediaType type;

@property(nonatomic, readonly) const AudioStreamBasicDescription* asbd;
@property(nonatomic, readonly, strong) NSDictionary* extensionAtoms;
@end
