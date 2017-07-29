//
//  EventListViewController.h
//  Sample
//
//  Created by Michael Ochs on 10/1/12.
//  Copyright (c) 2012 RockAByte GmbH. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface EventListViewController : UITableViewController

@property (nonatomic, strong, readonly) NSDictionary* events;

@end
