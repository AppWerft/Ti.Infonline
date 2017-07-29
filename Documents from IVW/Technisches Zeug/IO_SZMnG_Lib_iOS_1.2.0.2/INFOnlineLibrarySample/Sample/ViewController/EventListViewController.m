//
//  EventListViewController.m
//  Sample
//
//  Created by Michael Ochs on 10/1/12.
//  Copyright (c) 2012 RockAByte GmbH. All rights reserved.
//

#import "EventListViewController.h"

#import <INFOnlineLibrary/INFOnlineLibrary.h>


@interface EventListViewController ()

@property (nonatomic, strong, readwrite) NSDictionary* events;

@end

@implementation EventListViewController

- (id)initWithStyle:(UITableViewStyle)style
{
    self = [super initWithStyle:style];
    if (self) {
		[self buildEventDictionary];
		self.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:NSLocalizedString(@"<Send>", nil) style:UIBarButtonItemStyleBordered target:self action:@selector(forceSend:)];
    }
    return self;
}

- (id)initWithCoder:(NSCoder *)aDecoder
{
	self = [super initWithCoder:aDecoder];
	if (self) {
		[self buildEventDictionary];
		self.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:NSLocalizedString(@"<Send>", nil) style:UIBarButtonItemStyleBordered target:self action:@selector(forceSend:)];
	}
	return self;
}



#pragma mark - Data

- (void)buildEventDictionary {
	// we get all the events the config file supports, to give you the option to try all of these events.
	NSURL* configURL = [[NSBundle bundleWithURL:[[NSBundle mainBundle] URLForResource:@"INFOnlineLibrary" withExtension:@"bundle"]] URLForResource:@"INFOnlineLibrary" withExtension:@"config"];
	NSData* configData = [NSData dataWithContentsOfURL:configURL];
	NSDictionary* config = [NSJSONSerialization JSONObjectWithData:configData options:0 error:NULL];
	
	// Because some internal constraints, there is a media event in the config file, that will be gone in the final release. Because of that, we already hide it here.
	NSMutableDictionary* events = [NSMutableDictionary dictionaryWithDictionary:[config valueForKeyPath:@"configuration.activeEvents"]];
	[events removeObjectForKey:@"media"];
	self.events = events;
}

- (NSArray*)sortedSectionKeys {
	return [self.events.allKeys sortedArrayUsingSelector:@selector(caseInsensitiveCompare:)];
}

- (enum IOLEventType)eventTypeForEvent:(NSString*)section {
	static NSArray* automaticEventSection = nil;
	static dispatch_once_t onceToken;
	dispatch_once(&onceToken, ^{
		automaticEventSection = @[ @"advertisement", @"audio", @"data", @"deviceOrientation", @"document", @"download", @"game", @"gesture", @"hardwareButton", @"iap", @"login", @"push", @"upload", @"video", @"view" ];
	});
	// we validate the event with the list of public events. The index of the array corresponds with the value of the enum.
	// if the event is not in this list, it is an automatic event that shouldn't be triggered manually!
	return [automaticEventSection indexOfObject:section];
}



#pragma mark - Library

- (IBAction)forceSend:(id)sender {
	[[IOLSession defaultSession] sendLoggedEvents];
}



#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
	return self.events.allKeys.count;
}

- (NSString*)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section {
	id<NSCoding> sectionKey = self.sortedSectionKeys[section];
	return (NSString*)sectionKey;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
	id<NSCoding> sectionKey = self.sortedSectionKeys[section];
	return ((NSArray*)self.events[sectionKey]).count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    id<NSCoding> sectionKey = self.sortedSectionKeys[indexPath.section];
	BOOL isAutomaticEvent = ([self eventTypeForEvent:(NSString*)sectionKey] == NSNotFound);
	
#if STILL_SUPPORTS_IOS5
	UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:(isAutomaticEvent ? @"AutomaticEvent" : @"Event")];
	if (!cell) {
		cell = [[UITableViewCell alloc] initWithStyle:(isAutomaticEvent ? UITableViewCellStyleSubtitle : UITableViewCellStyleDefault) reuseIdentifier:(isAutomaticEvent ? @"AutomaticEvent" : @"Event")];
		if (isAutomaticEvent) {
			cell.textLabel.font = [UIFont italicSystemFontOfSize:cell.textLabel.font.pointSize];
			cell.textLabel.textColor = [UIColor lightGrayColor];
		}
	}
#else
	UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:(isAutomaticEvent ? @"AutomaticEvent" : @"Event") forIndexPath:indexPath];
#endif
    
    NSString* event = self.events[sectionKey][indexPath.row];
	cell.textLabel.text = event;
	if (isAutomaticEvent) {
		cell.detailTextLabel.text = NSLocalizedString(@"<AutomaticEvent>", nil);
	}
    
    return cell;
}



#pragma mark - Table view delegate

- (NSIndexPath*)tableView:(UITableView *)tableView willSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
	id<NSCoding> sectionKey = self.sortedSectionKeys[indexPath.section];
	BOOL isAutomaticEvent = ([self eventTypeForEvent:(NSString*)sectionKey] == NSNotFound);
	return (isAutomaticEvent ? nil : indexPath);
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
	id<NSCoding> sectionKey = self.sortedSectionKeys[indexPath.section];
	
	enum IOLEventType type = [self eventTypeForEvent:(NSString*)sectionKey];
	if (type != NSNotFound) {
		IOLEventState state = self.events[sectionKey][indexPath.row];
		/**
		 * we just log some random data.
		 * In your application you should add some useful stuff here.
		 * If you don't need paid and ad, use logEventWithType:state:category:comment: or logEventWithType:state: if you also don't have a category or a comment.
		 */
		[[IOLSession defaultSession] logEventWithType:type state:state category:@"TestCategory" comment:@"TestComment"];
	}
	
	[tableView deselectRowAtIndexPath:indexPath animated:YES];
}

@end
