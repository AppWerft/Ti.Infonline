//
//  IOLEvent.h
//  INFOnlineLibrary
//
//  Created by Michael Ochs on 7/20/12.
//  Copyright (c) 2012 RockAByte GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>


#pragma mark - Enums

/*!
 @enum IOLEventType
 
 IOLEventType is the list of publicly available events that can be triggered within your app.
 */
extern NS_ENUM(NSUInteger, IOLEventType) {
	IOLEventTypeAdvertisement,
	IOLEventTypeAudio,
	IOLEventTypeData,
	IOLEventTypeDeviceOrientation,
	IOLEventTypeDocument,
	IOLEventTypeDownload,
	IOLEventTypeGame,
	IOLEventTypeGesture,
	IOLEventTypeHardwareButton,
	IOLEventTypeIAP,
	IOLEventTypeLogin,
	IOLEventTypePush,
	IOLEventTypeUpload,
	IOLEventTypeVideo,
	IOLEventTypeView,
    IOLEventTypeWatchKitInterface,
    IOLEventTypeNotFound = NSNotFound
};

typedef NSString* const IOLEventState;



#pragma mark - Event States

//EVENT: Advertisement
extern IOLEventState IOLAdvertisementOpen; ///< This can be used in an event of type IOLEventTypeAdvertisement and specifies the 'open' state.
extern IOLEventState IOLAdvertisementClose; ///< This can be used in an event of type IOLEventTypeAdvertisement and specifies the 'close' state.

//EVENT: Audio
extern IOLEventState IOLAudioPlay; ///< This can be used in an event of type IOLEventTypeAudio and specifies the 'play' state.
extern IOLEventState IOLAudioPause; ///< This can be used in an event of type IOLEventTypeAudio and specifies the 'pause' state.
extern IOLEventState IOLAudioStop; ///< This can be used in an event of type IOLEventTypeAudio and specifies the 'stop' state.
extern IOLEventState IOLAudioNext; ///< This can be used in an event of type IOLEventTypeAudio and specifies the 'next' state.
extern IOLEventState IOLAudioPrevious; ///< This can be used in an event of type IOLEventTypeAudio and specifies the 'previous' state.
extern IOLEventState IOLAudioReplay; ///< This can be used in an event of type IOLEventTypeAudio and specifies the 'replay' state.
extern IOLEventState IOLAudioSeekBack; ///< This can be used in an event of type IOLEventTypeAudio and specifies the 'seek back' state.
extern IOLEventState IOLAudioSeekForward; ///< This can be used in an event of type IOLEventTypeAudio and specifies the 'seek forward' state.

//EVENT: Data
extern IOLEventState IOLDataCancelled; ///< This can be used in an event of type IOLEventTypeData and specifies the 'cancelled' state.
extern IOLEventState IOLDataRefresh; ///< This can be used in an event of type IOLEventTypeData and specifies the 'refresh' state.
extern IOLEventState IOLDataSucceeded; ///< This can be used in an event of type IOLEventTypeData and specifies the 'succeeded' state.
extern IOLEventState IOLDataFailed; ///< This can be used in an event of type IOLEventTypeData and specifies the 'failed' state.

//EVENT: DeviceOrientation
extern IOLEventState IOLDeviceOrientationChanged; ///< This can be used in an event of type IOLEventTypeDeviceOrientation and specifies the 'changed' state.

//EVENT: Document
extern IOLEventState IOLDocumentOpen; ///< This can be used in an event of type IOLEventTypeDocument and specifies the 'open' state.
extern IOLEventState IOLDocumentEdit; ///< This can be used in an event of type IOLEventTypeDocument and specifies the 'edit' state.
extern IOLEventState IOLDocumentClose; ///< This can be used in an event of type IOLEventTypeDocument and specifies the 'close' state.

//EVENT: Download
extern IOLEventState IOLDownloadCancelled; ///< This can be used in an event of type IOLEventTypeDownload and specifies the 'cancelled' state.
extern IOLEventState IOLDownloadStart; ///< This can be used in an event of type IOLEventTypeDownload and specifies the 'start' state.
extern IOLEventState IOLDownloadSucceeded; ///< This can be used in an event of type IOLEventTypeDownload and specifies the 'succeeded' state.
extern IOLEventState IOLDownloadFailed; ///< This can be used in an event of type IOLEventTypeDownload and specifies the 'failed' state.

//EVENT: Game
extern IOLEventState IOLGameAction; ///< This can be used in an event of type IOLEventTypeGame and specifies the 'action' state.
extern IOLEventState IOLGameStarted; ///< This can be used in an event of type IOLEventTypeGame and specifies the 'started' state.
extern IOLEventState IOLGameFinished; ///< This can be used in an event of type IOLEventTypeGame and specifies the 'finished' state.
extern IOLEventState IOLGameWon; ///< This can be used in an event of type IOLEventTypeGame and specifies the 'won' state.
extern IOLEventState IOLGameLost; ///< This can be used in an event of type IOLEventTypeGame and specifies the 'lost' state.
extern IOLEventState IOLGameNewHighscore; ///< This can be used in an event of type IOLEventTypeGame and specifies the 'highscore' state.
extern IOLEventState IOLGameNewAchievement; ///< This can be used in an event of type IOLEventTypeGame and specifies the 'achievement' state.

//EVENT: Gesture
extern IOLEventState IOLGestureShake; ///< This can be used in an event of type IOLEventTypeGesture and specifies the 'shake' state.

//EVENT: HardwareButton
extern IOLEventState IOLHardwareButtonPushed; ///< This can be used in an event of type IOLEventTypeHardwareButton and specifies the 'pushed' state.

//EVENT: IAP
extern IOLEventState IOLIAPStarted; ///< This can be used in an event of type IOLEventTypeIAP and specifies the 'started' state.
extern IOLEventState IOLIAPFinished; ///< This can be used in an event of type IOLEventTypeIAP and specifies the 'finished' state.
extern IOLEventState IOLIAPCancelled; ///< This can be used in an event of type IOLEventTypeIAP and specifies the 'cancelled' state.

//EVENT: Login
extern IOLEventState IOLLoginSucceeded; ///< This can be used in an event of type IOLEventTypeLogin and specifies the 'succeeded' state.
extern IOLEventState IOLLoginFailed; ///< This can be used in an event of type IOLEventTypeLogin and specifies the 'failed' state.
extern IOLEventState IOLLoginLogout; ///< This can be used in an event of type IOLEventTypeLogin and specifies the 'logout' state.

//EVENT: Push
extern IOLEventState IOLPushReceived; ///< This can be used in an event of type IOLEventTypePush and specifies the 'received' state.

//EVENT: Upload
extern IOLEventState IOLUploadCancelled; ///< This can be used in an event of type IOLEventTypeUpload and specifies the 'cancelled' state.
extern IOLEventState IOLUploadStart; ///< This can be used in an event of type IOLEventTypeUpload and specifies the 'start' state.
extern IOLEventState IOLUploadSucceeded; ///< This can be used in an event of type IOLEventTypeUpload and specifies the 'succeeded' state.
extern IOLEventState IOLUploadFailed; ///< This can be used in an event of type IOLEventTypeUpload and specifies the 'failed' state.

//EVENT: Video
extern IOLEventState IOLVideoPlay; ///< This can be used in an event of type IOLEventTypeVideo and specifies the 'play' state.
extern IOLEventState IOLVideoPause; ///< This can be used in an event of type IOLEventTypeVideo and specifies the 'pause' state.
extern IOLEventState IOLVideoStop; ///< This can be used in an event of type IOLEventTypeVideo and specifies the 'stop' state.
extern IOLEventState IOLVideoNext; ///< This can be used in an event of type IOLEventTypeVideo and specifies the 'next' state.
extern IOLEventState IOLVideoPrevious; ///< This can be used in an event of type IOLEventTypeVideo and specifies the 'previous' state.
extern IOLEventState IOLVideoReplay; ///< This can be used in an event of type IOLEventTypeVideo and specifies the 'replay' state.
extern IOLEventState IOLVideoSeekBack; ///< This can be used in an event of type IOLEventTypeVideo and specifies the 'seek back' state.
extern IOLEventState IOLVideoSeekForward; ///< This can be used in an event of type IOLEventTypeVideo and specifies the 'seek forward' state.

//EVENT: View
extern IOLEventState IOLViewAppeared; ///< This can be used in an event of type IOLEventTypeView and specifies the 'appeared' state.
extern IOLEventState IOLViewRefreshed; ///< This can be used in an event of type IOLEventTypeView and specifies the 'refreshed' state.
extern IOLEventState IOLViewDisappeared; ///< This can be used in an event of type IOLEventTypeView and specifies the 'disappeared' state.

//EVENT: WatchKit Interface
extern IOLEventState IOLWatchKitInterfaceActivate; ///< This can be used in an event of type IOLWatchKitInterface and specifies the 'willActivate' state.
extern IOLEventState IOLWatchKitInterfaceDeactivated; ///< This can be used in an event of type IOLWatchKitInterface and specifies the 'didDeactivate' state.

#pragma mark - IOLEvent

/*!
 IOLEvent represents one event you can log and send to the IOL servers via an IOLSession object.
 
 @see	IOLSession
 */
@interface IOLEvent : NSObject <NSCoding, NSCopying>

/*!
 This is the type you specified in the init of the event.
 @note	The only way to set this value is thru the init methods of this class
 @see	IOLEventType
 */
@property (nonatomic, assign, readonly) enum IOLEventType type;

/*!
 This is the state you specified in the init of the event.
 @see	IOLEventState
 */
@property (nonatomic, retain, readonly) IOLEventState state;

/*!
 This is the category you specified in the init of the event.
 @return	The catogory you specified or nil otherwise.
 */
@property (nonatomic, copy, readonly) NSString* category;

/*!
 This is the comment you specified in the init of the event.
 @return	The comment you specified or nil otherwise.
 */
@property (nonatomic, copy, readonly) NSString* comment;

/*!
 Initializes an event object with its type and state. This is ne mimimal information you need to specify.
 @param	type	The event type you want to initialize. Note that the type and the state have to match.
 @param	state	The event state you want to specialize. There are constants defined for every state that is available. e.g. the states for the IOLEventTypeView have the suffix IOLView...
 @return			The created event or nil if the event was not found.
 */
- (id)initWithType:(enum IOLEventType)type state:(IOLEventState)state;


/*!
 Initializes an event object with its type, state, category, comment and paid value.
 @param	type		The event type you want to initialize. Note that the type and the state have to match.
 @param	state		The event state you want to specify. There are constants defined for every state that is available. e.g. the states for the IOLEventTypeView have the suffix IOLView...
 @param	category	The category you want to set for this event or nil if you don't want to set a category. Category values are provided by INFOnline specifically for your app.
 @param	comment		The comment you want to specify for this event or nil if you don't want to add a comment. The comment is a value that is specified by yourself to identify different event contexts.
 @return			The created event or nil if the event was not found.
 */
- (id)initWithType:(enum IOLEventType)type state:(IOLEventState)state category:(NSString*)category comment:(NSString*)comment;

- (id)initWithType:(enum IOLEventType)type dictionaryData:(NSDictionary*)dictionaryData;

@end


#pragma mark - IOLSession

#import "IOLSession.h"

@interface IOLSession (IOLEvent)

/*!
 Initializes and loggs an event object with its type and state. This is ne mimimal information you need to specify.
 
 @param	type	The event type you want to initialize. Note that the type and the state have to match.
 @param	state	The event state you want to specialize. There are constants defined for every state that is available. e.g. the states for the IOLEventTypeView have the suffix IOLView...
 @see	[IOLEvent initWithType:state:]
 */
- (void)logEventWithType:(enum IOLEventType)type state:(IOLEventState)state;

/*!
 Initializes and loggs an event object with its type, state, category, comment and paid value.
 
 @param	type		The event type you want to initialize. Note that the type and the state have to match.
 @param	state		The event state you want to specify. There are constants defined for every state that is available. e.g. the states for the IOLEventTypeView have the suffix IOLView...
 @param	category	The category you want to set for this event or nil if you don't want to set a category. Category values are provided by INFOnline specifically for your app.
 @param	comment		The comment you want to specify for this event or nil if you don't want to add a comment. The comment is a value that is specified by yourself to identify different event contexts.
 @see	[IOLEvent initWithType:state:category:comment:]
 */
- (void)logEventWithType:(enum IOLEventType)type state:(IOLEventState)state category:(NSString*)category comment:(NSString*)comment;

@end
