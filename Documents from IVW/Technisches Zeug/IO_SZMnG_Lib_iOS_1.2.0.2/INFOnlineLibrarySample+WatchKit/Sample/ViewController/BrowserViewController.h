//
//  BrowserViewController.h
//  Sample
//
//  Created by Michael Ochs on 10/23/12.
//  Copyright (c) 2012 RockAByte GmbH. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <INFOnlineLibrary/INFOnlineLibrary.h>

@interface BrowserViewController : UIViewController <UISearchBarDelegate>

@property UIView<IOLWebViewCommon> *webView;

@property (nonatomic, weak, readwrite) IBOutlet UISearchBar* urlSearchBar;

@end
