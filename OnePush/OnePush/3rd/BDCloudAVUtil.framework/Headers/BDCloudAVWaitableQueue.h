//
//  BDCloudAVWaitableQueue.h
//  BDCloudAVUtil
//
//  Created by Bai,Lu(CBU) on 15/12/2017.
//  Copyright © 2017 Baidu. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 A waitable serial queue.
 */
@interface BDCloudAVWaitableQueue : NSObject

/**
 Initialize with serial queue name.

 @param name queue name.
 @return instance.
 */
- (instancetype)initWithName:(NSString*)name;

/**
 Wait queue with special time.

 @param time time to wait.
 @return wait result.
 */
- (BOOL)wait:(dispatch_time_t)time;

/**
 Dispatch a job to the serial queue.

 @param job job.
 */
- (void)dispatch:(dispatch_block_t)job;
@end
