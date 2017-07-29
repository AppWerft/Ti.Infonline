//
//  BrowserViewController.m
//  Sample
//
//  Created by Michael Ochs on 10/23/12.
//  Copyright (c) 2012 RockAByte GmbH. All rights reserved.
//

#import "BrowserViewController.h"

@interface BrowserViewController ()

@end

@implementation BrowserViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    // Test website for hybrid app measurement
    NSURL* testURL = [NSURL URLWithString:@"https://audit.ioam.de/mi.html"];
    
    if ([IOLWebView isWKWebViewAvailable]) {
        self.webView = [[IOL_WKWebView alloc] initWithFrame:self.view.frame];
    } else {
        self.webView = [[IOL_UIWebView alloc] initWithFrame:self.view.frame];
    }
    
    [self.view addSubview:self.webView];
    
    [self.webView loadRequest:[NSURLRequest requestWithURL:testURL]];
    
    self.urlSearchBar.text = [testURL absoluteString];
}

- (void)searchBarSearchButtonClicked:(UISearchBar *)searchBar
{
    NSString* urlString = searchBar.text;
    if (![urlString hasPrefix:@"http"]) {
        urlString = [@"http://" stringByAppendingString:urlString];
    }
    NSURL* url = [NSURL URLWithString:urlString];
    if (url) {
        [self.webView loadRequest:[NSURLRequest requestWithURL:url]];
        [searchBar resignFirstResponder];
        searchBar.text = urlString;
    }
}

@end
