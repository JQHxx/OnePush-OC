//
//  BDCloudAVAuthentication.h
//  BDCloudAVLicense
//
//  Created by Liu,Yawen(CBU) on 2018/3/7.
//  Copyright © 2018年 Baidu. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Functions key.
 */
typedef NSString *BDCloudAVAuthFunction;

/**
 User's credential.
 Can choose two different authentication ways by AK/SK or STS.
 Must set the value for `sessionToken` when choose the STS way, if `sessionToken` is nil, will use AK/SK to authenticate.
 */
@interface BDCloudAVAuthCredential : NSObject

/**
 required
 */
@property (nonatomic, copy) NSString *userId;
@property (nonatomic, copy) NSString *accessKey;
@property (nonatomic, copy) NSString *secretKey;

/**
 optional, set `sessionToken` for STS authenticate.
 */
@property (nonatomic, copy) NSString *sessionToken;

@end

@interface BDCloudAVAuthentication : NSObject

/**
 Start authenticate.

 @param credential credential, must set value for userId, accessKey and secretKey.
 @param completionHandler completion call back.
 */
+ (void)authenticateWithCredential:(BDCloudAVAuthCredential *)credential completionHandler:(void(^)(NSError *error))completionHandler;

@end
