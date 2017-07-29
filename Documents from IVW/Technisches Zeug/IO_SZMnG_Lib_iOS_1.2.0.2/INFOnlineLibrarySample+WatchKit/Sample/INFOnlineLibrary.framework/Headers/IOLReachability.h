//
//  IOLReachability.h
//  INFOnlineReports
//
//  Copyright 2010 RockAByte. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <SystemConfiguration/SystemConfiguration.h>
#import <netinet/in.h>

typedef enum IOLReachabilityNetworkStatus {
	IOLReachabilityNetworkStatusUnknown = -1,
	IOLReachabilityNetworkStatusNotReachable = 0,
	IOLReachabilityNetworkStatusWWAN = 1,
	IOLReachabilityNetworkStatusWiFi = 2
} IOLReachabilityNetworkStatus;

extern NSString* const IOLReachabilityChangedNotification;

extern NSString* const IOLReachabilityChangedOldStatusKey;


@interface IOLReachability : NSObject {
}

+ (IOLReachability*)defaultReachability;

+ (IOLReachability*)reachabilityWithHostName:(NSString*)hostName;
+ (IOLReachability*)reachabilityWithAddress:(const struct sockaddr_in*)hostAddress;
+ (IOLReachability*)reachabilityForInternetConnection;
+ (IOLReachability*)reachabilityForLocalWiFi;

- (id)initWithHostName:(NSString*)hostName;
- (id)initWithAddress:(const struct sockaddr_in*)hostAddress;
- (id)initForInternetConnection;
- (id)initForLocalWifi;

@property (nonatomic, readonly) IOLReachabilityNetworkStatus status;

- (BOOL)beginGeneratingReachabilityNotifications;
- (void)stopGeneratingReachabilityNotifications;

- (BOOL)connectionRequired;

@end
