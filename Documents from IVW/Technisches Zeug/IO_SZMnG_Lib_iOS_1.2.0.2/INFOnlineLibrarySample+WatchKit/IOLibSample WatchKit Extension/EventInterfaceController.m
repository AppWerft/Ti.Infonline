//
//  InterfaceController.m
//  IOLibSample WatchKit Extension
//
//  Created by Philip Laskowski on 02.07.15.
//  Copyright (c) 2015 RockAByte GmbH. All rights reserved.
//

#import "EventInterfaceController.h"

#import <INFOnlineLibrary/INFOnlineLibrary.h>
#import <INFOnlineLibrary/IOLEvent+Internal.h>

@interface EventInterfaceController()

@property (weak, nonatomic) IBOutlet WKInterfaceTable* eventTable;

@property NSMutableSet* automaticEvents;
@property NSMutableArray* eventTypesAndStates;
@property NSMutableDictionary* events;
@property NSMutableDictionary* eventTypeMapping;

@end


@implementation EventInterfaceController

- (void)awakeWithContext:(id)context {
    
    [super awakeWithContext:context];
    
    [self buildEvents];
}

- (void)willActivate {
    // This method is called when watch view controller is about to be visible to user
    [super willActivate];
    
    IOLEvent *event = [[IOLEvent alloc] initWithType:IOLEventTypeView
                                               state:IOLViewAppeared
                                            category:@"TestCategory"
                                             comment:@"TestComment"];
    
    [IOLWatchKitHelper logEvent:event];
}

- (void)didDeactivate {
    // This method is called when watch view controller is no longer visible
    [super didDeactivate];
    
    IOLEvent *event = [[IOLEvent alloc] initWithType:IOLEventTypeView
                                               state:IOLViewDisappeared
                                            category:NSStringFromClass([self class])
                                             comment:nil];
    
    [IOLWatchKitHelper logEvent:event];
}

- (void)buildEvents {
    
    _events = [NSMutableDictionary new];
    _eventTypeMapping = [NSMutableDictionary new];
    _eventTypesAndStates = [NSMutableArray new];
    _automaticEvents = [NSMutableSet new];
    
    [self addEventWithType:IOLEventTypeAdvertisement];
    [self addEventWithType:IOLEventTypeApplication];
    [self addEventWithType:IOLEventTypeAudio];
    [self addEventWithType:IOLEventTypeData];
    [self addEventWithType:IOLEventTypeDeviceOrientation];
    [self addEventWithType:IOLEventTypeDocument];
    [self addEventWithType:IOLEventTypeDownload];
    [self addEventWithType:IOLEventTypeGame];
    [self addEventWithType:IOLEventTypeGesture];
    [self addEventWithType:IOLEventTypeHardwareButton];
    [self addEventWithType:IOLEventTypeIAP];
    [self addEventWithType:IOLEventTypeInternetConnection];
    [self addEventWithType:IOLEventTypeLogin];
    [self addEventWithType:IOLEventTypeOpenApp];
    [self addEventWithType:IOLEventTypePush];
    [self addEventWithType:IOLEventTypeUpload];
    [self addEventWithType:IOLEventTypeVideo];
    [self addEventWithType:IOLEventTypeView];
    [self addEventWithType:IOLEventTypeWebView];
    
    NSArray *sortedEvents = [_eventTypesAndStates sortedArrayUsingComparator:^NSComparisonResult(IOLEvent *event1, IOLEvent *event2) {
        return [event1.category compare:event2.category options:NSCaseInsensitiveSearch];
    }];
    
    [_eventTypesAndStates removeAllObjects];
    
    for (IOLEvent *event in sortedEvents) {
        
        [_eventTypesAndStates addObject:event.category];
        
        NSNumber *eventType = [NSNumber numberWithInteger:event.type];
        
        [_eventTypeMapping setObject:eventType
                              forKey:[NSNumber numberWithInteger:_eventTypeMapping.count]];
        
        NSArray *sortedEventStates = [[_events[event.category] allObjects] sortedArrayUsingSelector:@selector(caseInsensitiveCompare:)];
        
        for (NSString *eventState in sortedEventStates) {
            
            [_eventTypesAndStates addObject:eventState];
            [_eventTypeMapping setObject:eventType
                                  forKey:[NSNumber numberWithInteger:_eventTypeMapping.count]];
        }
    }
    
    [self loadEvents];
}

- (void)addEventWithType:(NSUInteger)type {
    
    NSString *identifier = [IOLEvent identifierWithType:type];
    NSSet *eventStates = [IOLEvent eventStatesWithType:type];
    if (identifier && eventStates) {
        
        [_events setObject:eventStates forKey:identifier];
        [_eventTypesAndStates addObject:[[IOLEvent alloc] initWithType:type
                                                                 state:0
                                                              category:identifier
                                                               comment:nil]];
        
        if ([IOLEvent isAutomatic:type]) {
            [_automaticEvents addObject:identifier];
        }
    }
}

- (void)loadEvents {
    
    NSMutableArray *rowTypes = [NSMutableArray new];
    
    NSString *rowTypeEventType = NSStringFromClass([EventTypeRowController class]);
    NSString *rowTypeEventState = NSStringFromClass([EventStateRowController class]);
    
    for (NSString *eventTypeOrState in _eventTypesAndStates) {
        
        if ([_events objectForKey:eventTypeOrState]) {
            [rowTypes addObject:rowTypeEventType];
        } else {
            [rowTypes addObject:rowTypeEventState];
        }
    }
    
    [_eventTable setRowTypes:rowTypes];
    
    BOOL isAutomaticEvent = NO;
    
    NSInteger rowIndex = -1;
    
    for (NSString *eventTypeOrState in _eventTypesAndStates) {
        
        rowIndex++;
        
        if ([_events objectForKey:eventTypeOrState]) {
            
            isAutomaticEvent = [_automaticEvents containsObject:eventTypeOrState];
            
            EventTypeRowController *eventTypeRow = [_eventTable rowControllerAtIndex:rowIndex];
            
            NSMutableAttributedString *eventState = [[NSMutableAttributedString alloc]
                                                     initWithString:eventTypeOrState
                                                     attributes:@{NSFontAttributeName : [UIFont boldSystemFontOfSize:16.f]}];
            [eventTypeRow.eventTypeLabel setAttributedText:eventState];
            
            if (isAutomaticEvent) {
                eventTypeRow.eventTypeLabel.textColor = [UIColor grayColor];
            }
            
        } else {
            
            EventStateRowController* eventStateRow = [_eventTable rowControllerAtIndex:rowIndex];
            eventStateRow.eventStateLabel.text = eventTypeOrState;
            
            if (isAutomaticEvent) {
                eventStateRow.eventStateLabel.textColor = [UIColor grayColor];
                eventStateRow.eventAutomaticLabel.textColor = [UIColor grayColor];
                
                NSMutableAttributedString *text = [[NSMutableAttributedString alloc]
                                                         initWithString:@"automatic event"
                                                         attributes:@{NSFontAttributeName : [UIFont italicSystemFontOfSize:12.f]}];
                [eventStateRow.eventAutomaticLabel setAttributedText:text];
            } else {
                eventStateRow.eventAutomaticLabel.text = @"";
            }
        }
    }
}

- (void)table:(WKInterfaceTable *)table didSelectRowAtIndex:(NSInteger)rowIndex {
    
    id rowController = [_eventTable rowControllerAtIndex:rowIndex];
    
    if ([rowController isKindOfClass:[EventStateRowController class]]) {
        
        NSString *eventState = [_eventTypesAndStates objectAtIndex:rowIndex];
        NSNumber *eventType = [_eventTypeMapping objectForKey:[NSNumber numberWithInteger:rowIndex]];
        
        IOLEvent *event = [[IOLEvent alloc] initWithType:[eventType integerValue]
                                                   state:eventState
                                                category:@"TestCategory"
                                                 comment:@"TestComment"];

        [IOLWatchKitHelper logEvent:event];
    }
}

@end



