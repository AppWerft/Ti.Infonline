/**
 * infonline
 *
 * Created by Stefan Gross
 * Copyright (c) 2017 Stefan Gross. All rights reserved.
 */

#import "TiInfonlineModule.h"
#import "TiBase.h"
#import "TiHost.h"
#import "TiUtils.h"


static NSString* offerId = @"iamtest";
static NSString* customerData = @"";

static bool sessionStarted = NO;

@implementation TiInfonlineModule

#pragma mark Internal

// This is generated for your module, please do not change it
- (id)moduleGUID
{
	return @"a98f00c4-5edc-4f73-aa1b-27232e9fcdf7";
}

// This is generated for your module, please do not change it
- (NSString *)moduleId
{
	return @"ti.infonline";
}

#pragma mark Lifecycle

- (void)startup
{
	// This method is called when the module is first loaded
	// You *must* call the superclass
	[super startup];
	NSLog(@"[DEBUG] %@ loaded",self);
}

#pragma constants

// Map Event Types to JS accessible constants
MAKE_SYSTEM_UINT(EVENT_VIEW,IOLEventTypeView);
MAKE_SYSTEM_UINT(EVENT_IAP,IOLEventTypeIAP);
MAKE_SYSTEM_UINT(EVENT_DATA,IOLEventTypeData);
MAKE_SYSTEM_UINT(EVENT_GAME,IOLEventTypeGame);
MAKE_SYSTEM_UINT(EVENT_AUDIO,IOLEventTypeAudio);
MAKE_SYSTEM_UINT(EVENT_VIDEO,IOLEventTypeVideo);
MAKE_SYSTEM_UINT(EVENT_AD,IOLEventTypeAdvertisement);
MAKE_SYSTEM_UINT(EVENT_PUSH,IOLEventTypePush);
MAKE_SYSTEM_UINT(EVENT_LOGIN,IOLEventTypeLogin);
MAKE_SYSTEM_UINT(EVENT_DEVICE_ORIENTATION,IOLEventTypeDeviceOrientation);
MAKE_SYSTEM_UINT(EVENT_DOWNLOAD,IOLEventTypeDownload);
MAKE_SYSTEM_UINT(EVENT_UPLOAD,IOLEventTypeUpload);
MAKE_SYSTEM_UINT(EVENT_DOCUMENT,IOLEventTypeDocument);
MAKE_SYSTEM_UINT(EVENT_HARDWARE_BUTTON,IOLEventTypeHardwareButton);
MAKE_SYSTEM_UINT(EVENT_GESTURE,IOLEventTypeGesture);



MAKE_SYSTEM_STR(STATE_VIEW_APPEARED, IOLViewAppeared)
MAKE_SYSTEM_STR(STATE_VIEW_REFRESHED, IOLViewRefreshed)
MAKE_SYSTEM_STR(STATE_VIEW_DISAPPEARED, IOLViewDisappeared)

MAKE_SYSTEM_STR(STATE_DATA_CANCELLED, IOLDataCancelled)
MAKE_SYSTEM_STR(STATE_DATA_REFRESH, IOLDataRefresh)
MAKE_SYSTEM_STR(STATE_DATA_SUCCEEDED, IOLDataSucceeded)
MAKE_SYSTEM_STR(STATE_DATA_FAILED, IOLDataFailed)

MAKE_SYSTEM_STR(STATE_DOCUMENT_OPEN, IOLDocumentOpen)
MAKE_SYSTEM_STR(STATE_DOCUMENT_CLOSE, IOLDocumentClose)
MAKE_SYSTEM_STR(STATE_DOCUMENT_EDIT, IOLDocumentEdit)

MAKE_SYSTEM_STR(STATE_DOWNLOAD_CANCELLED, IOLDownloadCancelled)
MAKE_SYSTEM_STR(STATE_DOWNLOAD_START, IOLDownloadStart)
MAKE_SYSTEM_STR(STATE_DOWNLOAD_SUCCEEDED, IOLDownloadSucceeded)
MAKE_SYSTEM_STR(STATE_DOWNLOAD_FAILED, IOLDownloadFailed)

MAKE_SYSTEM_STR(STATE_GAME_ACTION, IOLGameAction)
MAKE_SYSTEM_STR(STATE_GAME_STARTED, IOLGameStarted)
MAKE_SYSTEM_STR(STATE_GAME_FINISHED, IOLGameFinished)
MAKE_SYSTEM_STR(STATE_GAME_WON, IOLGameWon)
MAKE_SYSTEM_STR(STATE_GAME_LOST, IOLGameLost)
MAKE_SYSTEM_STR(STATE_GAME_NEW_HIGHSCORE, IOLGameNewHighscore)
MAKE_SYSTEM_STR(STATE_GAME_NEW_ACHIEVEMENT, IOLGameNewAchievement)

MAKE_SYSTEM_STR(STATE_GESTURE_SHAKE, IOLGestureShake)

MAKE_SYSTEM_STR(STATE_HARDWARE_BUTTON_PUSHED, IOLHardwareButtonPushed)

MAKE_SYSTEM_STR(STATE_IAP_STARTED, IOLIAPStarted)
MAKE_SYSTEM_STR(STATE_IAP_FINISHED, IOLIAPFinished)
MAKE_SYSTEM_STR(STATE_IAP_CANCELLED, IOLIAPCancelled)

MAKE_SYSTEM_STR(STATE_LOGIN_SUCCEEDED, IOLLoginSucceeded)
MAKE_SYSTEM_STR(STATE_LOGIN_FAILED, IOLLoginFailed)
MAKE_SYSTEM_STR(STATE_LOGIN_LOGOUT, IOLLoginLogout)

MAKE_SYSTEM_STR(STATE_AUDIO_PLAY, IOLAudioPlay)
MAKE_SYSTEM_STR(STATE_AUDIO_PAUSE, IOLAudioPause)
MAKE_SYSTEM_STR(STATE_AUDIO_STOP, IOLAudioStop)
MAKE_SYSTEM_STR(STATE_AUDIO_NEXT, IOLAudioNext)
MAKE_SYSTEM_STR(STATE_AUDIO_PREVIOUS, IOLAudioPrevious)
MAKE_SYSTEM_STR(STATE_AUDIO_REPLAY, IOLAudioReplay)
MAKE_SYSTEM_STR(STATE_AUDIO_SEEK_BACK, IOLAudioSeekBack)
MAKE_SYSTEM_STR(STATE_AUDIO_SEEK_FORWARD, IOLAudioSeekForward)

MAKE_SYSTEM_STR(STATE_VIDEO_PLAY, IOLVideoPlay)
MAKE_SYSTEM_STR(STATE_VIDEO_PAUSE, IOLVideoPause)
MAKE_SYSTEM_STR(STATE_VIDEO_STOP, IOLVideoStop)
MAKE_SYSTEM_STR(STATE_VIDEO_NEXT, IOLVideoNext)
MAKE_SYSTEM_STR(STATE_VIDEO_PREVIOUS, IOLVideoPrevious)
MAKE_SYSTEM_STR(STATE_VIDEO_REPLAY, IOLVideoReplay)
MAKE_SYSTEM_STR(STATE_VIDEO_SEEK_BACK, IOLVideoSeekBack)
MAKE_SYSTEM_STR(STATE_VIDEO_SEEK_FORWARD, IOLVideoSeekForward)

MAKE_SYSTEM_STR(STATE_PUSH_RECEIVED, IOLPushReceived)

MAKE_SYSTEM_STR(STATE_UPLOAD_START, IOLUploadStart)
MAKE_SYSTEM_STR(STATE_UPLOAD_FAILED, IOLUploadFailed)
MAKE_SYSTEM_STR(STATE_UPLOAD_CANCELLED, IOLUploadCancelled)
MAKE_SYSTEM_STR(STATE_UPLOAD_SUCCEEDED, IOLUploadSucceeded)


MAKE_SYSTEM_STR(STATE_AD_OPEN, IOLAdvertisementOpen)
MAKE_SYSTEM_STR(STATE_AD_CLOSE, IOLAdvertisementClose)

MAKE_SYSTEM_STR(STATE_ORIENTATION_CHANGED, IOLDeviceOrientationChanged)


#pragma Public APIs


- (void)startSession:(id)args {
    
    [[IOLSession defaultSession] setDebugLogLevel:IOLDebugLevelVerbose];
    
    BOOL isOptOut = [[NSUserDefaults standardUserDefaults] boolForKey:@"IOLOptOut"];
    if (!isOptOut) {
        // start only if not opted out
        [[IOLSession defaultSession] startSessionWithOfferIdentifier:offerId];
        sessionStarted = YES;
    }
}

- (void)stopSession:(id)args {
    if(sessionStarted) {
        [[IOLSession defaultSession] terminateSession];
    }
}

- (void)sendLoggedEvents:(id)args {
    if(sessionStarted) {
        [[IOLSession defaultSession] sendLoggedEvents];
    }
}

- (void)optOut:(id)args {
    [self stopSession:@""];
    [[NSUserDefaults standardUserDefaults] setBool:YES forKey:@"IOLOptOut"];
    
}

- (void)optIn:(id)args {
    [[NSUserDefaults standardUserDefaults] setBool:NO forKey:@"IOLOptOut"];
    [self startSession:@""];
    
}

- (void) logEvent:(id)args {
    enum Args {
        kArgEvent = 0,
        kArgState,
        kArgCategory,
        kArgComment,
        kArgCount
    };

    ENSURE_ARG_COUNT(args, kArgCount)
    NSUInteger event = [TiUtils intValue:[args objectAtIndex:kArgEvent] ];
    NSString* state = [TiUtils stringValue:[args objectAtIndex:kArgState] ];
    NSString* category = [TiUtils stringValue:[args objectAtIndex:kArgCategory] ];
    NSString* comment = [TiUtils stringValue:[args objectAtIndex:kArgComment] ];

    [[IOLSession defaultSession]
       logEventWithType:event
       state:state
       category:category
       comment:comment];
}

- (id)customerData
{
    return customerData;
}

- (void)setCustomerData:(id)value
{
    ENSURE_STRING(value);
    customerData = value;
    [[IOLSession defaultSession] setCustomerData:customerData];
}


- (id)offerIdentifier
{
	// Call with "ifwModule.offerIdentifier" or "ifwModule.getOfferIdentifier()"
	return offerId;
}

- (void)setOfferIdentifier:(id)value
{
    ENSURE_STRING(value);
    offerId = value;
}


- (void) logTestEvent:(id)args {
    [[IOLSession defaultSession] setCustomerData:@"valueFromArg"];
    [[IOLSession defaultSession]
     logEventWithType:IOLEventTypeGame
     state:IOLGameAction
     category:@"category?"
     comment:@"optionalComment"];
}


@end
