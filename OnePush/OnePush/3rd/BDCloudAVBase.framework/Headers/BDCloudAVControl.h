//
//  BDCloudAVControl.h
//  BDCloudAVBase
//
//  Created by Bai,Lu(CBU) on 2017/4/21.
//  Copyright © 2017年 Baidu. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Interface implements this protocol could control the process state.
 */
@protocol BDCloudAVControl <NSObject>
- (void)start;
- (void)pause;
- (void)resume;
- (void)stop;
@end
