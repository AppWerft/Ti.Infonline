//
//  IOL_WKWebview.h
//  INFOnlineLibrary
//
//  Created by Philip Laskowski on 02.07.15.
//  Copyright (c) 2015 RockAByte GmbH. All rights reserved.
//

#import <WebKit/WebKit.h>

#import "IOLWebViewCommon.h"

@class IOLSession;

@interface IOL_WKWebView : WKWebView <IOLWebViewCommon>

/*!
 This is the UIWebView's delegate.
 
 @warning You **must not** check an `IOLWebView`'s delegate for pointer equality or nil! Instead check for isEqual: if you have to compare the delegate with another object.
 */

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Woverriding-method-mismatch"

@property (nonatomic, weak) id<WKNavigationDelegate> delegate;

#pragma clang diagnostic pop

@property (nonatomic, weak) id<WKNavigationDelegate> navigationDelegate;

/*!
 The multi identifier string is sent to your webserver as argument of the iom.setMultiIdentifier(string) JavaScript method
 of the INFOnline tracking framework.
 
 Normally you don't need to access this value, however if you are using frameworks like phonegap and you are not able to
 use the IOLWebView, you can use this string and call the iom.setMultiIdentifier() method on -webViewDidFinishLoad: manually.
 
 @return		The escaped multi identifier string based on the informations from the defaultSession or nil if the session has not been initialized yet.
 
 @note			You should not cache or store this value. Pass it as is to the JavaScript function! No manipulation like escaping is required.
 @since			1.1
 @deprecated	1.1.4 use multiIdentifierStringWithSession: instead
 */
+ (NSString *)multiIdentifierString DEPRECATED_ATTRIBUTE;

/*!
 The multi identifier string is sent to your webserver as argument of the iom.setMultiIdentifier(string) JavaScript method
 of the INFOnline tracking framework.
 
 Normally you don't need to access this value, however if you are using frameworks like phonegap and you are not able to
 use the IOLWebView, you can use this string and call the iom.setMultiIdentifier() method on -webViewDidFinishLoad: manually.
 
 @param		session	The session the mutliIdentifierString should use for data gathering.
 @return	The escaped multi identifier string or nil if the session has not been initialized yet.
 
 @note		You should not cache or store this value. Pass it as is to the JavaScript function! No manipulation like escaping is required.
 @since		1.1.4
 */
+ (NSString *)multiIdentifierStringWithSession:(IOLSession*)session;

/*!
 The session this IOLWebView uses for logging. If you use multiple sessions, you need to set this value.
 
 @note		If this value is nil, the default session will be used.
 @since		1.1.4
 */
@property (nonatomic, retain, readwrite) IOLSession* session;

- (instancetype)initWithCoder:(NSCoder *)aDecoder;

@end