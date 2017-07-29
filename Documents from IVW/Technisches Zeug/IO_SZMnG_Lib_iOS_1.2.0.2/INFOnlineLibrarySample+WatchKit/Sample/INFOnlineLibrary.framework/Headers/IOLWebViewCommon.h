//
//  IOLWebViewInterface.h
//  INFOnlineLibrary
//
//  Created by Philip Laskowski on 03.07.15.
//  Copyright (c) 2015 RockAByte GmbH. All rights reserved.
//

/*
 * This protocol aims at making the exchange of IOL_UIWebView and IOL_WKWebView as easy as possible
 * by defining properties and methods that either UIWebView or WKWebView are missing.
 */

@protocol IOLWebViewCommon <NSObject>

@property (nonatomic, strong) NSURLRequest *request;

@property (readonly) NSURL *URL;

- (id)delegate;
- (void)setDelegate:(id)delegate;

- (void)loadRequest:(NSURLRequest *)request;
- (void)loadRequestFromString:(NSString *)urlNameAsString;
- (BOOL)canGoBack;

- (NSString *)stringByEvaluatingJavaScriptFromString:(NSString *)script;
- (void)evaluateJavaScript:(NSString *)javaScriptString completionHandler:(void (^)(id, NSError *))completionHandler;

@end