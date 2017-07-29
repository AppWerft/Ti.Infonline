//
//  EventStateRowController.h
//  Sample
//
//  Created by Philip Laskowski on 06.07.15.
//  Copyright (c) 2015 RockAByte GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>

@import WatchKit;

@interface EventStateRowController : NSObject

@property (weak, nonatomic) IBOutlet WKInterfaceLabel* eventStateLabel;
@property (weak, nonatomic) IBOutlet WKInterfaceLabel* eventAutomaticLabel;

@end
