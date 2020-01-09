//
//  BDCloudAVBase.h
//  BDCloudAVBase
//
//  Created by Bai,Lu(CBU) on 2017/3/16.
//  Copyright © 2017年 Baidu. All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for BDCloudAVBase.
FOUNDATION_EXPORT double BDCloudAVBaseVersionNumber;

//! Project version string for BDCloudAVBase.
FOUNDATION_EXPORT const unsigned char BDCloudAVBaseVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <BDCloudAVBase/PublicHeader.h>

#import <Availability.h>

#ifdef __cplusplus
#define BDCLOUD_AV_EXTERN extern "C" __attribute__((visibility ("default")))
#else
#define BDCLOUD_AV_EXTERN extern __attribute__((visibility ("default")))
#endif

#import <BDCloudAVBase/BDCloudAVInput.h>
#import <BDCloudAVBase/BDCloudAVControl.h>
#import <BDCloudAVBase/BDCloudAVOutput.h>

