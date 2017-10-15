//
//  IOLSession.h
//  INFOnlineReports
//
//  Copyright 2010 RockAByte. All rights reserved.
//

#import <Foundation/Foundation.h>

@class IOLEvent;

/*!
 @enum		IOLDebugLevel
 @abstract	Values for controlling the level of debug outputs during runtime.
 @discussion	This enumerated type is used to declare the level of debug outputs to the IOLSession object you use to log events
 @constant	IOLDebugLevelOff		Log nothing
 @constant	IOLDebugLevelError		Log only errors
 @constant	IOLDebugLevelWarning	Log errors and warnings
 @constant	IOLDebugLevelInfo		Log errors, warnings and infos
 @constant	IOLDebugLevelTrace		Log errors, warnings, infos, events, requests and responses. Requests and responses will be logged as file in the Documents folder of your app. You can enable iTunes File Sharing in the info.plist file of your app to easily retrieve these files from iTunes
 */
extern NS_ENUM(NSUInteger, IOLDebugLevel) {
	IOLDebugLevelOff = 0,
	IOLDebugLevelError = 1,
	IOLDebugLevelWarning = 2,
	IOLDebugLevelInfo = 3,
	IOLDebugLevelTrace = 4,
	
	IOLDebugLevelVerbose = IOLDebugLevelTrace
};

/*!
 IOLSession is the main entry point of the library. It handles event logging, connections with the server, starting and stopping of event gathering and debug logs.
 */
@interface IOLSession : NSObject


/*! @name Basic information */

/*!
 Gives you the default session you should use for logging.
 
 On the first call the default session instance is allocated and initialized. You have to call startSessionWithOfferIdentifier: before you can start logging.
 
 @warning	If you don't want the lib to be instantiated at all, you **must not** call this method.
 @return	The default session to use for logging
 @see		startSessionWithOfferIdentifier:
 */
+ (IOLSession*)defaultSession;

/*!
 @return	The current version of the library
 */

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Woverriding-method-mismatch"

+ (NSString*)version;

#pragma clang diagnostic pop

/*!
 The offer identifier that is used in this session
 
 @note		You have to set the offer identifier via startSessionWithOfferIdentifier:
 @return	The current session's offer identifier
 @see		startSessionWithOfferIdentifier:
 */
@property (nonatomic, copy, readonly) NSString* offerIdentifier;

/*!
 The hybrid identifier is optional and is used for hybrid apps that have web content that should be tracked.
 
 @note		You have to set the hybrid identifier via startSessionWithOfferIdentifier:hybridIdentifier:
 @return	The current session's hybrid identifier
 @see		startSessionWithOfferIdentifier:hybridIdentifier:
 @since		1.1
 */
@property (nonatomic, copy, readonly) NSString* hybridIdentifier;

/*!
 Customer data is optional and is used for hybrid apps that have web content that should be tracked.
 
 This identifier is defined by the developer and is sent as is, without any calculations or validations on it.
 
 @return	The current session's customerData value
 @since		1.1
 */
@property (nonatomic, copy, readwrite) NSString* customerData;

/*!
 The debug level for the current session.
 
 In the release build of your app you might want to set this value to IOLDebugLevelOff to stop the app from logging into the device console.
 
 @return	the debugLogLevel that is currently used
 */
@property (nonatomic, assign, readwrite) NSUInteger debugLogLevel;


/*! @name Session lifetime */

/*!
 This call starts the session with the given offer identifier. After this call, you can start logging events with logEvent: or one of the logEventWithType:... methods.
 
 On calling this method, events that could not be sent in the last session will be sent immediately.
 If you don't want the lib to track events, for example if the user opt out from tracking in you app, you must not call this method.
 
 @param		offerIdentifier		The offer identifier you want to start the session with
 @see		terminateSession
 */
- (void)startSessionWithOfferIdentifier:(NSString*)offerIdentifier;

/*!
 This call starts the session with the given offer identifier and a hybrid identifier that is needed for web based tracking.
 After this call, you can start logging events with logEvent: or one of the logEventWithType:... methods.
 
 On calling this method, events that could not be sent in the last session will be sent immediately.
 If you don't want the lib to track events, for example if the user opt out from tracking in you app, you must not call this method.
 
 @param		offerIdentifier		The offer identifier you want to start the session with
 @param		hybridIdentifier	The hybrid identifier for web content tracking
 @see		terminateSession
 @since		1.1
 */
- (void)startSessionWithOfferIdentifier:(NSString*)offerIdentifier hybridIdentifier:(NSString*)hybridIdentifier;

/*!
 This terminates the current logging session. You should call this method, if you want to cancel logging after a call
 to startSessionWithOfferIdentifier: for example when the user opts-out in your app.
 
 @note		This drops all events that are currently in the event queue. These events will never be sent.
 @see		startSessionWithOfferIdentifier:
 @see		sendLoggedEvents
 */
- (void)terminateSession;


/*! @name Event logging */

/*!
 This queues an event you want to log in the current event queue. Logged events will be sent automatically from the session at given	times during the session life time or if you call sendLoggedEvents
 
 There are several convenience methods to log events, that do not require you to instantiate an IOLEvent yourself. For further information look at IOLSession(IOLEvent)
 
 @param		event	The event you want to log.
 @see		startSessionWithOfferIdentifier:
 @see		sendLoggedEvents
 */
- (void)logEvent:(IOLEvent*)event;

/*!
 This forces the queued events to be sent immediately. You might want to call this method before calling terminateSession as this would drop all events that haven't been sent.
 
 @note		The session sends queued events automatically on different events. Under normal conditions you should not need to call this message.
 */
- (void)sendLoggedEvents;


@end
