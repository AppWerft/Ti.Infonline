//
//  IOLWatchKitHelper.h
//  INFOnlineLibrary
//
//  Created by Philip Laskowski on 06.07.15.
//  Copyright (c) 2015 RockAByte GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "IOLEvent.h"

@interface IOLWatchKitHelper : NSObject

/*!
 This queues an event you want to log in the current event queue. Logged events will be sent automatically from the session at given	times during the session life time or if you call sendLoggedEvents
 
 There are several convenience methods to log events, that do not require you to instantiate an IOLEvent yourself. For further information look at IOLSession(IOLEvent)
 
 @param		event	The event you want to log.
 @see		startSessionWithOfferIdentifier:
 @see		sendLoggedEvents
 */
+ (void)logEvent:(IOLEvent *)event;

/*!
 Initializes and loggs an event object with its type and state. This is ne mimimal information you need to specify.
 
 @param	type	The event type you want to initialize. Note that the type and the state have to match.
 @param	state	The event state you want to specialize. There are constants defined for every state that is available. e.g. the states for the IOLEventTypeView have the suffix IOLView...
 @see	[IOLEvent initWithType:state:]
 */
+ (void)logEventWithType:(enum IOLEventType)type state:(IOLEventState)state;

/*!
 Initializes and loggs an event object with its type, state, category, comment and paid value.
 
 @param	type		The event type you want to initialize. Note that the type and the state have to match.
 @param	state		The event state you want to specify. There are constants defined for every state that is available. e.g. the states for the IOLEventTypeView have the suffix IOLView...
 @param	category	The category you want to set for this event or nil if you don't want to set a category. Category values are provided by INFOnline specifically for your app.
 @param	comment		The comment you want to specify for this event or nil if you don't want to add a comment. The comment is a value that is specified by yourself to identify different event contexts.
 @see	[IOLEvent initWithType:state:category:comment:]
 */
+ (void)logEventWithType:(enum IOLEventType)type state:(IOLEventState)state category:(NSString *)category comment:(NSString *)comment;

@end
