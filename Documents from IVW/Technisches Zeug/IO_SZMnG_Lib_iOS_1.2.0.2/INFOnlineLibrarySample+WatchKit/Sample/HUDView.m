//
//  HUDView.m
//  Sample
//
//  Created by Michael Ochs on 10/9/12.
//  Copyright (c) 2012 RockAByte GmbH. All rights reserved.
//

#import "HUDView.h"

#import <QuartzCore/QuartzCore.h>


static void* const HUDViewTextChangedContext = (void*)&HUDViewTextChangedContext;
static NSTimeInterval const HUDViewAnimationDuration = 0.3;

static inline CGPoint CenterPointOfCGRect(CGRect rect) {
	return CGPointMake(CGRectGetMidX(rect), CGRectGetMidY(rect));
}

@interface HUDView ()

@property (nonatomic, weak, readwrite) UILabel* textLabel;

@end


@implementation HUDView

+ (HUDView*)hudView
{
	HUDView* hudView = [[self alloc] initWithFrame:CGRectMake(0.0f, 0.0f, 128.0f, 128.0f)];
	return hudView;
}

- (id)initWithFrame:(CGRect)frame
{
	self = [super initWithFrame:frame];
	if (self) {
		self.layer.cornerRadius = 10.0f;
		self.layer.masksToBounds = YES;
		self.backgroundColor = [UIColor colorWithWhite:0.0f alpha:0.5f];
		self.autoresizingMask = UIViewAutoresizingFlexibleTopMargin | UIViewAutoresizingFlexibleLeftMargin | UIViewAutoresizingFlexibleBottomMargin | UIViewAutoresizingFlexibleRightMargin;
		
		UIActivityIndicatorView* activity = [[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleWhiteLarge];
		activity.center = CenterPointOfCGRect(self.bounds);
		[activity startAnimating];
		[self addSubview:activity];
		
		UILabel* label = [[UILabel alloc] initWithFrame:CGRectMake(8.0f, frame.size.height - 8.0f - 24.0f, frame.size.width - 16.0f, 24.0f)];
		label.backgroundColor = [UIColor clearColor];
		label.font = [UIFont boldSystemFontOfSize:[UIFont systemFontSize]];
		label.textAlignment = NSTextAlignmentCenter;
		label.textColor = [UIColor whiteColor];
		[self addSubview:label];
		self.textLabel = label;
		
		[self addObserver:self forKeyPath:@"text" options:NSKeyValueObservingOptionInitial context:HUDViewTextChangedContext];
	}
	return self;
}

- (void)dealloc
{
	[self removeObserver:self forKeyPath:@"text" context:HUDViewTextChangedContext];
}



#pragma mark - View management

- (void)showAboveView:(UIView*)view animated:(BOOL)animated
{
	if (animated) {
		self.alpha = 0.0f;
		self.center = CenterPointOfCGRect(view.bounds);
		[view addSubview:self];
		[UIView animateWithDuration:HUDViewAnimationDuration animations:^{
			self.alpha = 1.0f;
		}];
	}
}

- (void)hide:(BOOL)animated
{
	if (animated) {
		[UIView animateWithDuration:HUDViewAnimationDuration animations:^{
			self.alpha = 0.0f;
		} completion:^(BOOL finished) {
			[self removeFromSuperview];
			self.alpha = 1.0f; // bring the view in its default state
		}];
	} else {
		[self removeFromSuperview];
	}
}



#pragma mark - Text Updates

- (void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary *)change context:(void *)context
{
	if (context == HUDViewTextChangedContext) {
		self.textLabel.text = self.text;
	}
}

@end
