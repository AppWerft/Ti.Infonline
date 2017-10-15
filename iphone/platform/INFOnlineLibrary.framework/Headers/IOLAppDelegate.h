//
//  IOLAppDelegate.h
//  INFOnlineLibrary
//
//  Created by Philip Laskowski on 06.07.15.
//  Copyright (c) 2015 RockAByte GmbH. All rights reserved.
//

#import <UIKit/UIKit.h>

@class IOLSession;

@protocol IOLAppDelegate

@required

- (void)startSession;

@optional

- (IOLSession *)currentSession;

@end

@interface IOLAppDelegate : UIResponder <UIApplicationDelegate, IOLAppDelegate>

@property (strong, nonatomic) UIWindow *window;

@end
