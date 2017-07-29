//
//  EventTriggerViewController.h
//  Sample
//
//  Created by Michael Ochs on 10/9/12.
//  Copyright (c) 2012 RockAByte GmbH. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface EventTriggerViewController : UIViewController

- (IBAction)startBackgroundTask:(id)sender;
- (IBAction)openMaps:(id)sender;
- (IBAction)openOther:(id)sender;
- (IBAction)crash:(id)sender;
- (IBAction)optOutChanged:(id)sender;

@end
