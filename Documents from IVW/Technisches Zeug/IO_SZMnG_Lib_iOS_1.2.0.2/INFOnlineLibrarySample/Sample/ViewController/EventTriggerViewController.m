//
//  EventTriggerViewController.m
//  Sample
//
//  Created by Michael Ochs on 10/9/12.
//  Copyright (c) 2012 RockAByte GmbH. All rights reserved.
//

#import "EventTriggerViewController.h"

#import "HUDView.h"

#import <INFOnlineLibrary/INFOnlineLibrary.h>
#import <MapKit/MapKit.h>
#import <QuartzCore/QuartzCore.h>


@interface EventTriggerViewController () <UITextFieldDelegate>

@property (nonatomic, weak, readwrite) HUDView* hudView;
@property (nonatomic, weak, readwrite) NSTimer* backgroundTimer;
@property (nonatomic, assign, readwrite) UIBackgroundTaskIdentifier backgroundTask;
@property (nonatomic, weak, readwrite) IBOutlet UIView* optOutContainer;
@property (nonatomic, weak, readwrite) IBOutlet UISwitch* optOutSwitch;

@property (weak, nonatomic) IBOutlet UITextField *customerDataTextField;
@property (weak, nonatomic) IBOutlet UITextField *commentTextField;
@property (weak, nonatomic) IBOutlet UITextField *categoryTextField;

@end

@implementation EventTriggerViewController

- (id)initWithCoder:(NSCoder *)aDecoder
{
	self = [super initWithCoder:aDecoder];
	if (self) {
		self.backgroundTask = UIBackgroundTaskInvalid;
	}
	return self;
}

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
	self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
	if (self) {
		self.backgroundTask = UIBackgroundTaskInvalid;
	}
	return self;
}

- (void)viewDidLoad
{
	[super viewDidLoad];
	
	self.optOutContainer.layer.borderColor = [[UIColor lightGrayColor] CGColor];
	self.optOutContainer.layer.borderWidth = 1.0f;
	self.optOutContainer.layer.cornerRadius = 8.0f;
	self.optOutContainer.layer.masksToBounds = YES;
	
	BOOL isOptOut = [[NSUserDefaults standardUserDefaults] boolForKey:@"IOLOptOut"];
	self.optOutSwitch.on = isOptOut;
}



#pragma mark - Actions
- (IBAction)logCustomEvent:(id)sender
{
    [[IOLSession defaultSession] setCustomerData:self.customerDataTextField.text];
    [[IOLSession defaultSession] logEventWithType:IOLEventTypeGame state:IOLGameAction category:self.categoryTextField.text comment:self.commentTextField.text];
}


- (IBAction)startBackgroundTask:(id)sender
{
	if (self.backgroundTask == UIBackgroundTaskInvalid) {
		self.backgroundTask = [[UIApplication sharedApplication] beginBackgroundTaskWithExpirationHandler:^{
			self.backgroundTask = UIBackgroundTaskInvalid;
		}];
		self.backgroundTimer = [NSTimer scheduledTimerWithTimeInterval:5.0 target:self selector:@selector(endBackgroundTask:) userInfo:nil repeats:NO];
		
		HUDView* hudView = [HUDView hudView];
		hudView.text = NSLocalizedString(@"<BackgroundTaskText>", nil);
		[hudView showAboveView:self.view animated:YES];
		self.hudView = hudView;
	}
}

- (void)endBackgroundTask:(NSTimer*)aTimer
{
	[[UIApplication sharedApplication] endBackgroundTask:self.backgroundTask];
	self.backgroundTask = UIBackgroundTaskInvalid;
	
	[self.hudView hide:YES];
}

- (IBAction)openMaps:(id)sender
{
	if ([MKMapItem class] && [MKMapItem respondsToSelector:@selector(mapItemForCurrentLocation)]) {
		//we are on iOS6, use the new way to launch maps!
		[[MKMapItem mapItemForCurrentLocation] openInMapsWithLaunchOptions:nil];
	} else {
		NSURL* url = [NSURL URLWithString:[@"maps:q=1 Infinite Loop, Cupertino" stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding]];
		[[UIApplication sharedApplication] openURL:url];
	}
}

- (IBAction)openOther:(id)sender
{
	NSURL* url = [NSURL URLWithString:[@"http://example.com" stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding]];
	[[UIApplication sharedApplication] openURL:url];
}

- (IBAction)crash:(id)sender
{
	[NSException raise:@"IOLProvokedCrashException" format:@"Crashing for no reason..."];
}

- (IBAction)optOutChanged:(id)sender
{
	UISwitch* optOutSwitch = sender;
	BOOL isOptOut = [[NSUserDefaults standardUserDefaults] boolForKey:@"IOLOptOut"];
	if (isOptOut != optOutSwitch.isOn) {
		[[NSUserDefaults standardUserDefaults] setBool:optOutSwitch.isOn forKey:@"IOLOptOut"];
		isOptOut = optOutSwitch.isOn;
		if (isOptOut) {
			[[IOLSession defaultSession] terminateSession];
		} else {
			[[IOLSession defaultSession] startSessionWithOfferIdentifier:@"iamtest"];
		}
	}
}

#pragma mark - UITextFieldDelegate

- (BOOL)textFieldShouldReturn:(UITextField *)textField {
    [textField resignFirstResponder];
    return NO;
}


@end
