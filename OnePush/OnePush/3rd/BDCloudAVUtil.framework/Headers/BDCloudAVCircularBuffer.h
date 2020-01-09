//
//  BDCloudAVCircularBuffer.h
//  BDCloudAVUtil
//
//  Created by Bai,Lu(CBU) on 2017/5/25.
//  Copyright © 2017年 Baidu. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 A circular buffer to store data.
 */
@interface BDCloudAVCircularBuffer : NSObject

/**
 Create buffer with special capacity.

 @param capacity capacity.
 @return create result.
 */
- (BOOL)create:(UInt32)capacity;

/**
 Clear the filled data.
 */
- (void)clear;

/**
 Produce data with special data buffer and length.
 If not enough space, produce will fail.

 @param src data buffer.
 @param len length.
 @return produce result.
 */
- (BOOL)produceBytes:(const void*)src len:(UInt32)len;


/**
 Consume data with special data buffer and length.
 If not enough data, consume will fail.
 Note: this method return the internal buffer pointer without memcpy.

 @param buffer [in/out] Data buffer.
 @param len [in] Data length want to consume.
 @return consume result.
 */
- (BOOL)consumeBytes:(void**)buffer len:(UInt32)len;

@end
