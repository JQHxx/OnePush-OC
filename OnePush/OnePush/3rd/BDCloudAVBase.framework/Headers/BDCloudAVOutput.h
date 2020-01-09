//
//  BDCloudAVOutput.h
//  BDCloudAVToolbox
//
//  Created by Bai,Lu(CBU) on 2017/3/16.
//  Copyright © 2017年 Baidu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BDCloudAVInput.h"
#import "BDCloudAVControl.h"


/**
 Base dispatcher interface, manage target array of id<BDCloudAVInput> or id<BDCloudAVBinaryInput>.
 Interface inherits from BDCloudAVDispatcher could dispatch CMSampleBuffer or binary data buffer to every target in targets array.
 */
@interface BDCloudAVDispatcher : NSObject

/**
 Dispatch data type, could be AVMediaTypeVideo or AVMediaTypeAudio.
 */
@property(nonatomic, assign, readonly) NSString* mediaType;

/**
 Targets array store id<BDCloudAVInput> or id<BDCloudAVBinaryInput> instances.
 */
@property(nonatomic, strong, readonly) NSArray* targets;

/**
 Initialize with data type.

 @param mediaType data type.
 @return dispatch instance.
 */
- (instancetype)initWithMediaType:(NSString*)mediaType;

/**
 Add a target.

 @param target id<BDCloudAVInput> or id<BDCloudAVBinaryInput> instance.
 */
- (void)addTarget:(id)target;

/**
 Remove a target.

 @param target id<BDCloudAVInput> or id<BDCloudAVBinaryInput> instance.
 */
- (void)removeTarget:(id)target;

/**
 Remove all targets.
 */
- (void)removeAllTargets;
@end

/**
 A Dispatcher could dispatch CMSampleBufferRef to every id<BDCloudAVInput> instance in targets array.
 */
@interface BDCloudAVOutput : BDCloudAVDispatcher

/**
 Dispatch a CMSampleBuffer.

 @param frame frame.
 */
- (void)raiseFrame:(CMSampleBufferRef)frame;
@end

/**
 A Dispatcher Could dispatch binary data buffer to every id<BDCloudAVBinaryInput> in targets array.
 */
@interface BDCloudAVBinaryOutput : BDCloudAVDispatcher

/**
 Dispatch binary data buffer.

 @param buffer binary data buffer.
 @param length data length.
 @param meta metadata of the binary data buffer.
 */
- (void)raiseFrame:(uint8_t*)buffer length:(NSUInteger)length metadata:(NSDictionary*)meta;
@end

/**
 A helper interface have audio and video CMSampleBuffer dispatch ability, internal use only.
 */
@interface BDCloudAVDualOutput : NSObject

/**
 Video Output.
 */
@property(nonatomic, strong, readonly) BDCloudAVOutput* videoOutput;

/**
 Audio Output.
 */
@property(nonatomic, strong, readonly) BDCloudAVOutput* audioOutput;
@end

