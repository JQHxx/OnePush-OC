//
//  BDCloudAVAudioMixSource.h
//  videoplayer
//
//  Created by blue on 26/10/2017.
//  Copyright © 2017 Baidu. All rights reserved.
//

#import <BDCloudAVBase/BDCloudAVBase.h>

@class BDCloudAVAudioNode;
@protocol BDCloudAVAudioNodeCallback;
@protocol BDCloudAVCustomAudioFilter;

/**
 The source of mixer's input bus, contains multiple nodes.
 Add node in order to influence the final audio effects.
 */
@interface BDCloudAVAudioMixSource : NSObject

/**
 Audio nodes.
 */
@property(nonatomic, strong, readonly) NSArray<BDCloudAVAudioNode*>* nodes;

/**
 Add audio node.
 
 @param node node.
 */
- (void)addNode:(BDCloudAVAudioNode*)node;

/**
 Install render notify callback block.
 
 @param callback callback.
 @return result.
 */
- (int)installNotifyCallback:(id<BDCloudAVAudioNodeCallback>)callback;

/**
 Remove render notify callback block.
 
 @return result.
 */
- (int)removeNotifyCallback;
@end

/**
 Audio filter's input mix source, can be the master source.
 */
@interface BDCloudAVAudioInputMixSource : BDCloudAVAudioMixSource<BDCloudAVInput>

/**
 Whether the source is master.
 */
@property(nonatomic) BOOL isMaster;

/**
 Add user defined custom filter.
 
 @param filter filter.
 */
- (void)addCustomFilter:(id<BDCloudAVCustomAudioFilter>)filter;

/**
 Remove user defined custom filter.
 
 @param filter filter.
 */
- (void)removeCustomFilter:(id<BDCloudAVCustomAudioFilter>)filter;

/**
 Set tempo.
 
 @param tempo tempo, 1/32 -> 32.0, 1.0.
 @return result.
 */
- (int)setTempo:(float)tempo;

/**
 Set pitch.
 
 @param pitch pitch Cents, -2400 -> 2400, 1.0.
 @return result.
 */
- (int)setPitch:(float)pitch;

@end

/**
 Music mix source.
 */
@interface BDCloudAVAudioMusicMixSource : BDCloudAVAudioMixSource

/**
 Background music duration.
 */
@property(nonatomic, readonly) CMTime duration;

/**
 Set background music file.
 
 @param file file path.
 @return result.
 */
- (int)setFile:(NSString*)file;

/**
 Set background music file and loop count.
 
 @param file file path.
 @param loop loop count.
 @return result.
 */
- (int)setFile:(NSString*)file loop:(UInt32)loop;

/**
 Set background music play range.
 
 @param range range.
 @return result.
 */
- (int)setRange:(CMTimeRange)range;

/**
 Set background music play tempo.
 
 @param tempo tempo, 1/32 -> 32.0, 1.0.
 @return result.
 */
- (int)setTempo:(float)tempo;

/**
 Set background music play pitch.
 
 @param pitch pitch Cents, -2400 -> 2400, 1.0.
 @return result.
 */
- (int)setPitch:(float)pitch;

/**
 Restart.
 
 @return result.
 */
- (int)restart;

@end
