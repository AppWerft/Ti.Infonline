//
//  HUDView.h
//  Sample
//
//  Created by Michael Ochs on 10/9/12.
//  Copyright (c) 2012 RockAByte GmbH. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface HUDView : UIView

@property (nonatomic, readwrite) NSString* text;

+ (HUDView*)hudView;

- (void)showAboveView:(UIView*)view animated:(BOOL)animated;
- (void)hide:(BOOL)animated;

@end
