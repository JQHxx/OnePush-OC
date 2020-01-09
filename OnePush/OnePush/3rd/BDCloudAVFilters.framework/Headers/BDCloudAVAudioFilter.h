//
//  BDCloudAVAudioFilter.h
//  videoplayer
//
//  Created by blue on 26/10/2017.
//  Copyright © 2017 Baidu. All rights reserved.
//

#import <BDCloudAVBase/BDCloudAVBase.h>

@class BDCloudAVAudioMixSource;
@protocol BDCloudAVAudioNodeCallback;

/**
 Audio filter provide reverb, mixer, resample and user defined custom process ability.
 User defined custom mixSource to add muiltple channel audio.
 Inherits from BDCloudAVOutput, have audio CMSampleBuffer dispatch ability.
 The master mixSource (BDCloudAVAudioInputMixSource) implements protocol BDCloudAVInput, have receive and process audio CMSampleBuffer ability.
 
 Audio process graph:
 
       |capture/file output|                         |background music file|
                |                       |                       |
                | voice                 |                       |
                V                       V                       V
         /--------------\        /--------------\        /--------------\
         |  timePitch   |        |              |        |              |
         |      |       |        |    cache     |        |  filePlayer  |
         |      V       |        |              |        |              |
         |    reverb    |        |              |        |              |
         |  mixSource 0 |        |  mixSource 1 |        |  mixSource N |
         \--------------/        \--------------/        \--------------/
                |                       |                       |
                |                       V                       |
                |---------------> |   mixer   | <---------------|
                                       |
                                       V
                                  | next step |
 */

@interface BDCloudAVAudioFilter : BDCloudAVOutput

/**
 Add master source. master source must be the object of BDCloudAVAudioInputMixSource.
 
 @param source master source.
 @return result.
 */
- (BOOL)addMasterSource:(BDCloudAVAudioMixSource*)source;

/**
 Add source.
 
 @param source source.
 @return result.
 */
- (BOOL)addSource:(BDCloudAVAudioMixSource*)source;

/**
 Install notify callback block.
 All the mix source or mixer can install notify callback, to implement real-time ears back or play bgm.
 
 @param callback callback.
 @return result.
 */
- (int)installNotifyCallback:(id<BDCloudAVAudioNodeCallback>)callback;

/**
 Remove notify callback block.
 
 @return result.
 */
- (int)removeNotifyCallback;

/**
 Set mixer input bus count.
 
 @param count bus count.
 @return result.
 */
- (int)setInputBusCount:(UInt32)count;

/**
 Set mixer input volume.
 
 @param volume volume.
 @param bus bus.
 @return result.
 */
- (int)setInputVolume:(float)volume bus:(UInt32)bus;

/**
 Toggle mixer input bus.
 
 @param enable enable.
 @param bus bus.
 @return result.
 */
- (int)setInputEnable:(BOOL)enable bus:(UInt32)bus;

/**
 Set mixer output volume.
 
 @param volume volume.
 @return result.
 */
- (int)setOutputVolume:(float)volume;

/**
 Set mixer output pan.
 
 @param pan pan.
 @return result.
 */
- (int)setOutputPan:(float)pan;

@end
