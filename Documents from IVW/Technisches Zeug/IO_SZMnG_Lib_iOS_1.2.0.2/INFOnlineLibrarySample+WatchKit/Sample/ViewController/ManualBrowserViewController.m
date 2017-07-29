//
//  ManualBrowserViewController.m
//  Sample
//
//  Created by Michael Ochs on 2/12/13.
//  Copyright (c) 2013 RockAByte GmbH. All rights reserved.
//

#import "ManualBrowserViewController.h"

@interface ManualBrowserViewController ()

@end

@implementation ManualBrowserViewController

- (void)viewDidLoad {
    
    [super viewDidLoad];
    
    [self.webView setDelegate:self];
}

- (void)webViewDidFinishLoad:(UIWebView *)webView {
    NSString* uuidJSCall = [NSString stringWithFormat:@"iom.setMultiIdentifier(\"%@\")", [IOLWebView multiIdentifierStringWithSession:[IOLSession defaultSession]]];
    [webView stringByEvaluatingJavaScriptFromString:uuidJSCall];
}

- (void)webView:(WKWebView *)webView didFinishNavigation:(WKNavigation *)navigation {
    NSString* uuidJSCall = [NSString stringWithFormat:@"iom.setMultiIdentifier(\"%@\")", [IOL_WKWebView multiIdentifierStringWithSession:[IOLSession defaultSession]]];
    [webView evaluateJavaScript:uuidJSCall completionHandler:nil];
}

@end
