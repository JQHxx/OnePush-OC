//
//  BDCloudAVAlbumSaver.h
//  BDCloudAVUtil
//
//  Created by Bai,Lu(CBU) on 2017/6/26.
//  Copyright © 2017年 Baidu. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 A helper class to save image or video to album.
 */
@interface BDCloudAVAlbumSaver : NSObject

/**
 Save image to album.

 @param image image.
 */
+ (void)saveImage:(UIImage*)image;

/**
 Save image located at the special file url to album.

 @param url file url.
 */
+ (void)saveImageAtFileURL:(NSURL*)url;

/**
 Save video located at the special file url to album.

 @param url file url.
 */
+ (void)saveVideoAtFileURL:(NSURL*)url;

@end
