# infonline Titanium Module
![](http://www.ivw.eu/profiles/ivw_website/themes/ivw_theme/logo.png)
## Description

Axway Titanium Module for INFOnline. Infoline is the solution for [IVW-tracking](http://www.ivw.eu/digital/digital). The developmenbt was sponsored by [4D Media GmbH](https://4dmedia.de/) in Düsseldorf.

## About IVW


The German Audit Bureau of Circulation (IVW) has neutrally and objectively recorded and audited the distribution of advertising media since 1949. With the establishment of the IVW, media providers (publishers), advertisers and advertising agencies created an effective controlling system which is under their joint supervision.

Almost all relevant advertising media categories are covered under the umbrella of the IVW: newspapers, magazines and other periodically appearing press products, broadcast media (radio and TV), cinema advertising and digital media.

The underlying idea is simple and obvious. In order to function, the advertising market requires performance data regarding the advertising media that are offered on the market. However, if these data were collected by each provider of an advertising medium for its own advertising media with its own individual methods, on the one hand, no comparability with the data of other providers would be guaranteed, and on the other hand, there would also be no independent assurance of data quality. The advertising market players transferred these tasks to a common parent institution: the IVW.

The results of the IVW's work provide reliable data for the market, for professional advertisers and performance-based competition between the media. As an independent, non-commercial, and neutral auditing organization, the IVW provides the media and advertising industry, and interested public, with basic data for the marketing of media as advertising.

Behind the system of circulation certification, digital measurement applications and the corresponding audit procedures are complex rules and regulations which are negotiated and decided by the delegates of advertisers, agencies and media providers at the IVW "round table". The bodies are committed to the consensus principle and to the IVW´s duty to ensure transparency, i.e. a common denominator is reached in the IVW between the opposing interests of the provider and the customer. The resulting definitions and conventions form market standards and the data provided by the IVW have become the accepted currency for quantitative advertising media performance.  The consensus principle ensures the general acceptance of these currencies, and in this sense, the IVW is a classic Joint Industry Committee (JIC).

## Accessing the infonline Module

To access this module from JavaScript, you would do the following:

    var iol = require("ti.infonline");

The infonline variable is a reference to the Module object.

## Reference

### Constants
#### Event Types:
Event categories with the following naming convention:

```
let iol = require('ti.infoline');
iol.EVENT_VIEW
iol.EVENT_IAP
iol.Event_DATA
iol.Event_GAME
iol.Event_AUDIO
iol.Event_VIDEO
iol.Event_AD
iol.Event_PUSH
iol.Event_LOGIN
iol.Event_DEVICE_ORIENTATION
iol.Event_DOWNLOAD
iol.Event_UPLOAD
iol.Event_DOCUMENT
iol.Event_HARDWARE_BUTTON
iol.Event_GESTURE
```
#### Event States
Event Type specific states with the following naming convention

```
iol.STATE_VIEW_APPEARED
iol.STATE_VIEW_REFRESHED
iol.STATE_VIEW_DISAPPEARED

iol.STATE_DATA_CANCELLED
iol.STATE_DATA_REFRESH
iol.STATE_DATA_SUCCEEDED
iol.STATE_DATA_FAILED

iol.STATE_DOCUMENT_OPEN
iol.STATE_DOCUMENT_CLOSE
iol.STATE_DOCUMENT_EDIT

iol.STATE_DOWNLOAD_CANCELLED
iol.STATE_DOWNLOAD_START
iol.STATE_DOWNLOAD_SUCCEEDED
iol.STATE_DOWNLOAD_FAILED

iol.STATE_GAME_ACTION
iol.STATE_GAME_STARTED
iol.STATE_GAME_FINISHED
iol.STATE_GAME_WON
iol.STATE_GAME_LOST
iol.STATE_GAME_NEW_HIGHSCORE
iol.STATE_GAME_NEW_ACHIEVEMENT

iol.STATE_GESTURE_SHAKE

iol.STATE_HARDWARE_BUTTON_PUSHED

iol.STATE_IAP_STARTED
iol.STATE_IAP_FINISHED
iol.STATE_IAP_CANCELLED

iol.STATE_LOGIN_SUCCEEDED
iol.STATE_LOGIN_FAILED
iol.STATE_LOGIN_LOGOUT

iol.STATE_AUDIO_PLAY
iol.STATE_AUDIO_PAUSE
iol.STATE_AUDIO_STOP
iol.STATE_AUDIO_NEXT
iol.STATE_AUDIO_PREVIOUS
iol.STATE_AUDIO_REPLAY
iol.STATE_AUDIO_SEEK_BACK
iol.STATE_AUDIO_SEEK_FORWARD

iol.STATE_VIDEO_PLAY
iol.STATE_VIDEO_PAUSE
iol.STATE_VIDEO_STOP
iol.STATE_VIDEO_NEXT
iol.STATE_VIDEO_PREVIOUS
iol.STATE_VIDEO_REPLAY
iol.STATE_VIDEO_SEEK_BACK
iol.STATE_VIDEO_SEEK_FORWARD

iol.STATE_PUSH_RECEIVED

iol.STATE_UPLOAD_START
iol.STATE_UPLOAD_FAILED
iol.STATE_UPLOAD_CANCELLED
iol.STATE_UPLOAD_SUCCEEDED


iol.STATE_AD_OPEN
iol.STATE_AD_CLOSE

iol.STATE_ORIENTATION_CHANGED
```

## Functions
#### iol.startSession()
Start a session. You have to set the offer identifier before calling this function!

#### iol.stopSession()
Stops a previously initiated session.

#### iol.logEvent(EventType,EventState,Code,Comment)
Log a single event. Events will be queued until configured threshold is reached.

| Parameter  | Meaning |
| ------------- | ------------- |
| EventType  | see EventType constants for supported values  |
| EventState  | a state matching the EventType. See EvenState constants for supported values  |
| Code  | code as assigned in/by INFOnline portal. Unassigned codes will lead to errors/warnings in the backend |
| Comment  | a comment you (maybe) can define  |


#### infonline.sendLoggedEvents()
Forced send of all queued events

#### infonline.optOut()
The user must have the option to opt out. If you don't want to handle the value in your own code,
just call the optOut() function and the logEvent / startSession functions will respect that

#### infonline.optIn()
Re enable event logging after having called optOut()

### Android only functions:
#### iol.enableDebug()
#### iol.disableDebug()
#### iol.getVersion()
#### iol.setDeviceIdEnabled()  
Needs runtime permission "PHONE_STATE"



### Properties
#### infonline.offerIdentifier
The INFOnline provided offer identifier.
NOTE: You have to set it, before calling startSession()!

#### infonline.customerData
Customer data according INFOnline SDK documentation


## Usage

	var iol = require("ti.infonline");
	iol.setOfferIdentifier("appXXX");
	iol.startSession();
	iol.logEvent(iol.EVENT_VIEW,iol.STATE_VIEW_APPEARED,"My code","My comment");


## Authors

* (C) 2017 by Stefan Gross (st.gross@gmx.net) (iOS)
* (C) 2017 by Rainer Schleevoigt (rs@hamburger-appwerft.de) (Android)


## License

MIT License
