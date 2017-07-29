//
//  IOLEvent+Internal.h
//  INFOnlineLibrary
//
//  Created by Michael Ochs on 7/20/12.
//  Copyright (c) 2012 RockAByte GmbH. All rights reserved.
//


#import "IOLEvent.h"
#import "IOLEvent+Deprecated.h"

#import "IOLReachability.h"


extern NS_ENUM(NSUInteger, IOLInternalEventType) {
	IOLEventTypeAccessory = 0x100,
	IOLEventTypeApplication,
	IOLEventTypeBackgroundTask,
	IOLEventTypeInternetConnection,
	IOLEventTypeOpenApp,
	IOLEventTypeWebView
};


//EVENT: Accessory
extern IOLEventState IOLAccessoryConnected;
extern IOLEventState IOLAccessoryDisconnected;

//EVENT: Application
extern IOLEventState IOLApplicationStart;
extern IOLEventState IOLApplicationEnterBackground;
extern IOLEventState IOLApplicationEnterForeground;
extern IOLEventState IOLApplicationResignActive;
extern IOLEventState IOLApplicationBecomeActive;
extern IOLEventState IOLApplicationTerminate;
extern IOLEventState IOLApplicationCrashed;

//EVENT: BackgroundTask
extern IOLEventState IOLBackgroundTaskStart;
extern IOLEventState IOLBackgroundTaskEnd;

//EVENT: InternetConnection
extern IOLEventState IOLInternetConnectionEstablished;
extern IOLEventState IOLInternetConnectionLost;
extern IOLEventState IOLInternetConnectionSwitchedInterface;

//EVENT: OpenApp
extern IOLEventState IOLOpenAppMaps;
extern IOLEventState IOLOpenAppOther;

//EVENT: WebView
extern IOLEventState IOLWebViewInit;
//extern IOLEventState IOLWebViewStop;


@interface IOLEvent ()

@property (nonatomic, assign, readwrite) enum IOLEventType type;
@property (nonatomic, retain, readwrite) IOLEventState state;
@property (nonatomic, copy, readwrite) NSDictionary* parameter;
@property (nonatomic, copy, readwrite) NSString* category;
@property (nonatomic, copy, readwrite) NSString* comment;
@property (nonatomic, retain, readwrite) NSDate* date;
@property (nonatomic, assign, readwrite) IOLReachabilityNetworkStatus network;


+ (NSString*)identifierWithType:(NSUInteger)type;

+ (enum IOLEventType)typeWithIdentifier:(NSString *)identifier;

+ (NSSet *)eventStatesWithType:(NSUInteger)type;

+ (BOOL)isAutomatic:(NSInteger)eventType;

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

// designated initializer!
- (id)initWithType:(enum IOLEventType)type state:(IOLEventState)state category:(NSString*)category comment:(NSString*)comment parameter:(NSDictionary*)parameter;

- (NSDictionary*)dictionaryRepresentation;



#pragma mark - Deprecation

@property (nonatomic, assign, readwrite) IOLAd ad DEPRECATED_ATTRIBUTE;
@property (nonatomic, assign, readwrite) IOLPaid paid DEPRECATED_ATTRIBUTE;

@end
