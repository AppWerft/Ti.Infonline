//
//  IOLEvent+Deprecated.h
//  INFOnlineLibrary
//
//  Created by Michael Ochs on 1/29/13.
//  Copyright (c) 2013 RockAByte GmbH. All rights reserved.
//

#import "IOLEvent.h"


/*!
 @enum IOLAd
 
 IOLAd is used to specify wether an event is triggered within an advertisement based content or not.
 */
typedef NS_ENUM(NSInteger, IOLAd) {
	IOLAdUnknown = -1, ///< The event may or may not be triggered within an advertisement content
	IOLAdNo = 0, ///< The event is not triggered within an advertisement content
	IOLAdYes = 1 ///< The event is triggered within an advertisement content
} DEPRECATED_ATTRIBUTE;

/*!
 @enum IOLPaid
 
 IOLPaid is used to specify wether an event is triggered within a paid based content or not.
 */
typedef NS_ENUM(NSInteger, IOLPaid) {
	IOLPaidUnknown = -1, ///< The event may or may not be triggered within a paid content
	IOLPaidNo = 0, ///< The event is not triggered within a paid content
	IOLPaidYes = 1 ///< The event is triggered within a paid content
} DEPRECATED_ATTRIBUTE;


@interface IOLEvent (Deprecated)

/*!
 This is the ad value you specified in the init of the event.
 @return		The ad value you specified or IOLAdUnknown otherwise.
 @see			IOLAd
 @deprecated	Deprecated in 1.1.0 - advertisement information is not supported anymore
 */
@property (nonatomic, assign, readonly) IOLAd ad DEPRECATED_ATTRIBUTE;

/*!
 This is the paid value you specified in the init of the event.
 @return		The paid value you specified or IOLPaidUnknown otherwise.
 @see			IOLPaid
 @deprecated	Deprecated in 1.1.0 - paid information is not supported anymore
 */
@property (nonatomic, assign, readonly) IOLPaid paid DEPRECATED_ATTRIBUTE;


/*!
 Initializes an event object with its type, state, category, comment and paid value.
 @param	type		The event type you want to initialize. Note that the type and the state have to match.
 @param	state		The event state you want to specify. There are constants defined for every state that is available. e.g. the states for the IOLEventTypeView have the suffix IOLView...
 @param	category	The category you want to set for this event or nil if you don't want to set a category. Category values are provided by INFOnline specifically for your app.
 @param	comment		The comment you want to specify for this event or nil if you don't want to add a comment. The comment is a value that is specified by yourself to identify different event contexts.
 @param	paid		The paid value you want to specify for this event. If parts of your app can just be accessed if the user pays for it and other parts are free of charge, you should specify these value, otherwise pass IOLPaidUnknown.
 @deprecated		Deprecated in 1.1.0 - use initWithType:state:category:comment: instead.
 */
- (id)initWithType:(enum IOLEventType)type state:(IOLEventState)state category:(NSString*)category comment:(NSString*)comment paid:(IOLPaid)paid DEPRECATED_ATTRIBUTE;

/*!
 Initializes an event object with its type, state, category, comment, paid and ad value.
 @param	type		The event type you want to initialize. Note that the type and the state have to match.
 @param	state		The event state you want to specify. There are constants defined for every state that is available. e.g. the states for the IOLEventTypeView have the suffix IOLView...
 @param	category	The category you want to set for this event or nil if you don't want to set a category. Category values are provided by INFOnline specifically for your app.
 @param	comment		The comment you want to specify for this event or nil if you don't want to add a comment. The comment is a value that is specified by yourself to identify different event contexts.
 @param	paid		The paid value you want to specify for this event. If parts of your app can just be accessed if the user pays for it and other parts are free of charge, you should specify these value, otherwise pass IOLPaidUnknown.
 @param	ad			The ad value you want to specify for this event. If parts of your app show ads and other don't, you should specify these value, otherwise pass IOLAdUnknown.
 @deprecated		Deprecated in 1.1.0 - use initWithType:state:category:comment: instead.
 */
- (id)initWithType:(enum IOLEventType)type state:(IOLEventState)state category:(NSString*)category comment:(NSString*)comment paid:(IOLPaid)paid ad:(IOLAd)ad DEPRECATED_ATTRIBUTE;

@end

@interface IOLSession (IOLEvent_Deprecated)

/*!
 Initializes and loggs an event object with its type, state, category, comment and paid value.
 
 @param	type		The event type you want to initialize. Note that the type and the state have to match.
 @param	state		The event state you want to specify. There are constants defined for every state that is available. e.g. the states for the IOLEventTypeView have the suffix IOLView...
 @param	category	The category you want to set for this event or nil if you don't want to set a category. Category values are provided by INFOnline specifically for your app.
 @param	comment		The comment you want to specify for this event or nil if you don't want to add a comment. The comment is a value that is specified by yourself to identify different event contexts.
 @param	paid		The paid value you want to specify for this event. If parts of your app can just be accessed if the user pays for it and other parts are free of charge, you should specify these value, otherwise pass IOLPaidUnknown.
 @see	[IOLEvent initWithType:state:category:comment:paid:]
 @deprecated		Deprecated in 1.1.0 - use logEventWithType:state:category:comment: instead.
 */
- (void)logEventWithType:(enum IOLEventType)type state:(IOLEventState)state category:(NSString*)category comment:(NSString*)comment paid:(IOLPaid)paid DEPRECATED_ATTRIBUTE;

/*!
 Initializes and loggs an event object with its type, state, category, comment, paid and ad value.
 
 @param	type		The event type you want to initialize. Note that the type and the state have to match.
 @param	state		The event state you want to specify. There are constants defined for every state that is available. e.g. the states for the IOLEventTypeView have the suffix IOLView...
 @param	category	The category you want to set for this event or nil if you don't want to set a category. Category values are provided by INFOnline specifically for your app.
 @param	comment		The comment you want to specify for this event or nil if you don't want to add a comment. The comment is a value that is specified by yourself to identify different event contexts.
 @param	paid		The paid value you want to specify for this event. If parts of your app can just be accessed if the user pays for it and other parts are free of charge, you should specify these value, otherwise pass IOLPaidUnknown.
 @param	ad			The ad value you want to specify for this event. If parts of your app show ads and other don't, you should specify these value, otherwise pass IOLAdUnknown.
 @see	[IOLEvent initWithType:state:category:comment:paid:ad:]
 @deprecated		Deprecated in 1.1.0 - use logEventWithType:state:category:comment: instead.
 */
- (void)logEventWithType:(enum IOLEventType)type state:(IOLEventState)state category:(NSString*)category comment:(NSString*)comment paid:(IOLPaid)paid ad:(IOLAd)ad DEPRECATED_ATTRIBUTE;

@end