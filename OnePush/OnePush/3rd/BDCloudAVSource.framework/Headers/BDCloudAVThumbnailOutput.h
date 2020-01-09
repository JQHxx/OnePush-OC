//
//  BDCloudAVThumbnailOutput.h
//  BDCloudAVSource
//
//  Created by Bai,Lu(CBU) on 2017/4/26.
//  Copyright © 2017年 Baidu. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreMedia/CoreMedia.h>

/**
 Thumbnail output delegate methods
 */
@protocol BDCloudAVThumbnailOutputDelegate <NSObject>
@optional

/**
 Thumbnail start.
 */
- (void)thumbnailStart;

/**
 A thumbnail generated.

 @param index thumbnail index.
 @param image thumbnail image.
 @param time original thumbnail time.
 @param actualTime actual thumbnail time.
 */
- (void)thumbnailGeneratedAtIndex:(NSUInteger)index image:(UIImage*)image time:(CMTime)time actualTime:(CMTime)actualTime;

/**
 Thumbnail cancelled.

 @param index thumbnail index.
 @param time original thumbnail time.
 */
- (void)thumbnailCancelledAtIndex:(NSUInteger)index time:(CMTime)time;

/**
 Thumbnail failure.

 @param index thumbnail index.
 @param time original thumbnail time.
 @param error error.
 */
- (void)thumbnailFailureAtIndex:(NSUInteger)index time:(CMTime)time error:(NSError*)error;

/**
 Thumbnail end.
 */
- (void)thumbnailEnd;
@end

/**
 Generates thumbnails for a given time array.
 */
@interface BDCloudAVThumbnailOutput : NSObject

/**
 Delegate.
 */
@property(nonatomic, weak) id<BDCloudAVThumbnailOutputDelegate> delegate;

/**
 The file's duration.
 */
@property(nonatomic, readonly) CMTime duration;

/**
 The output thumbnail's max size.
 */
@property(nonatomic) CGSize maxSize;

/**
 Lerance before original thumbnail time.
 */
@property(nonatomic) CMTime timeLeranceBefore;

/**
 Lerance after original thumbnail time.
 */
@property(nonatomic) CMTime timeLeranceAfter;

/**
 Initialize with file.

 @param file file.
 @return instance.
 */
- (instancetype)initWithFile:(NSString*)file;

/**
 Asynchronous general thumbnails with a given time array.

 @param times thumbnail times.
 */
- (void)generateThumbnail:(NSArray<NSValue*>*)times;

/**
 Synchronous general thumbnail with a given time.

 @param time origin thumbnail time.
 @param actualTime actual thumbnail time.
 @param error error.
 @return thumbnail, may be nil if error occur.
 */
- (UIImage*)generateThumbnailAtTime:(CMTime)time actualTIme:(CMTime*)actualTime error:(NSError**)error;

/**
 Cancel asynchronous thumbnail general.
 */
- (void)cancelGeneration;

@end
