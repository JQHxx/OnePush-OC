//
//  BidirectRtmpSocket.h
//  BDCloudRtmpSocket
//
//  Created by Andy Young on 06/06/2017.
//  Copyright © 2017 Baidu. All rights reserved.
//

#ifndef BidirectRtmpSocket_h
#define BidirectRtmpSocket_h

#import "IBidirectRtmpEventListener.h"

@interface BidirectRtmpSocket : NSObject

@property (nonatomic, weak) id<IBidirectRtmpEventListener> eventListener;
@property (nonatomic, assign) BOOL isConnected;

- (id) init;

- (void) connect:(NSString*) url;
- (void) disconnect;

- (void) sendRtmpPacket: (const uint8_t*) buf
             withLength: (int) len
                withPts: (long) pts
          withFrameType: (int) type;

- (void) sendMetaData: (int) width
           withHeight: (int) height
              withFps: (double) videoFps
     withVideoBitrate: (double) videoBitrate
     withAudioBitrate: (double) audioBitrate
       withSampleRate: (int) samplerate;

- (void) sendCallSignal: (NSString*) targetUrl
       withTargetUserId: (NSString*) targetUserId
        withLocalUserId: (NSString*) localUserId;

- (void) sendResponseToCall: (NSString*) callerUrl
           withCallerUserId: (NSString*) callerUserId
            withLocalUserId: (NSString*) localUserId
           withResponseCode: (RtmpResponseCode) responseCode;

- (void) sendInviteSignal: (NSString*) targetUrl
         withTargetUserId: (NSString*) targetUserId
          withLocalUserId: (NSString*) localUserId;

- (void) sendResponseToInvite: (NSString*) callerUrl
             withCallerUserId: (NSString*) callerUserId
              withLocalUserId: (NSString*) localUserId
             withResponseCode: (RtmpResponseCode) responseCode;

- (void) sendAckSignal: (NSString*) targetUrl
      withTargetUserId: (NSString*) targetUserId
       withLocalUserId: (NSString*) localUserId;

- (void) sendCancelSignal: (NSString*) targetUrl
         withTargetUserId: (NSString*) targetUserId
          withLocalUserId: (NSString*) localUserId;

- (void) sendKickSignal: (NSString*) targetUrl
       withTargetUserId: (NSString*) targetUserId
        withLocalUserId: (NSString*) localUserId;

- (void) sendByeSignal: (NSString*) targetUrl
      withTargetUserId: (NSString*) targetUserId
       withLocalUserId: (NSString*) localUserId;

- (void) sendPingSignal: (NSString*) targetUrl
       withTargetUserId: (NSString*) targetUserId
        withLocalUserId: (NSString*) localUserId
            withExtInfo: (NSString*) extInfo;

- (void) sendInfoSignal: (NSString*) targetUrl
       withTargetUserId: (NSString*) targetUserId
        withLocalUserId: (NSString*) localUserId
            withExtInfo: (NSString*) extInfo;

- (void) sendRtmpCommand: (NSString*) cmdName
              withParams: (NSArray<NSString*>*) params
         withParamsCount: (int) count;

- (double) getSendFPS;

- (double) getCurrentBandWidthKBps;

@end

#endif /* BidirectRtmpSocket_h */
