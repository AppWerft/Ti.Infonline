//
//  IOLApplication.h
//  INFOnlineLibrary
//
//  Created by Michael Ochs on 7/19/12.
//  Copyright (c) 2012 RockAByte GmbH. All rights reserved.
//

#import <UIKit/UIKit.h>

extern NSString * const kIOLNotificationNoConfigurationFound;

/*!
 IOLApplication is used for automatic event gathering. You should use this as the base class of you app, if you want to use automatic event gathering.
 
 If you don't use your own subclass of UIApplication, you most likely didn't change anything on the launch source code of your application. To use IOLApplication as your application's base class simply go into your `main.m` file and replace the third argument of `UIApplicationMain()` with `@"IOLApplication"`.
 
 After the change, on non-arc systems your `main.m` should look like this:
	int main(int argc, char *argv[]) {
		NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];
		int retVal = UIApplicationMain(argc, argv, @"IOLApplication", nil);
		[pool release];
		return retVal;
	}
 
 If you are already running in an arc enabled environment, your `main.m` should look like this:
	int main(int argc, char *argv[])
	{
		@autoreleasepool {
			return UIApplicationMain(argc, argv, @"IOLApplication", NSStringFromClass([AppDelegate class]));
		}
	}
 
 @note		The change in the 4th argument relates from changes in the iOS template files provided by Xcode. The important part you have to make sure is the third argument.
 
 @warning	If you are using your own application class, most likely this class inherits from `UIApplication` and the change mentioned above is already done and points to your class. In this case you don't have to change anything on your main.m file. Simply change the parent class of your application class to `IOLApplication`.
 */
@interface IOLApplication : UIApplication

@end
