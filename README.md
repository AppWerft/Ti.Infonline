# infonline Titanium Module
![](http://www.ivw.eu/profiles/ivw_website/themes/ivw_theme/logo.png)
## Description

Axway Titanium Module for INFOnline. Infoline is the solution for [IVW-tracking](http://www.ivw.eu/digital/digital). 

## About IVW


The German Audit Bureau of Circulation (IVW) has neutrally and objectively recorded and audited the distribution of advertising media since 1949. With the establishment of the IVW, media providers (publishers), advertisers and advertising agencies created an effective controlling system which is under their joint supervision.

Almost all relevant advertising media categories are covered under the umbrella of the IVW: newspapers, magazines and other periodically appearing press products, broadcast media (radio and TV), cinema advertising and digital media.

The underlying idea is simple and obvious. In order to function, the advertising market requires performance data regarding the advertising media that are offered on the market. However, if these data were collected by each provider of an advertising medium for its own advertising media with its own individual methods, on the one hand, no comparability with the data of other providers would be guaranteed, and on the other hand, there would also be no independent assurance of data quality. The advertising market players transferred these tasks to a common parent institution: the IVW.

The results of the IVW's work provide reliable data for the market, for professional advertisers and performance-based competition between the media. As an independent, non-commercial, and neutral auditing organization, the IVW provides the media and advertising industry, and interested public, with basic data for the marketing of media as advertising.

Behind the system of circulation certification, digital measurement applications and the corresponding audit procedures are complex rules and regulations which are negotiated and decided by the delegates of advertisers, agencies and media providers at the IVW "round table". The bodies are committed to the consensus principle and to the IVW´s duty to ensure transparency, i.e. a common denominator is reached in the IVW between the opposing interests of the provider and the customer. The resulting definitions and conventions form market standards and the data provided by the IVW have become the accepted currency for quantitative advertising media performance.  The consensus principle ensures the general acceptance of these currencies, and in this sense, the IVW is a classic Joint Industry Committee (JIC).

## Accessing the infonline Module

To access this module from JavaScript, you would do the following:

    var Infonline = require("ti.infonline");

The infonline variable is a reference to the Module object.

## Reference

### Constants
#### Event Types:
Event categories with the following naming convention:

```
Infoline.EVENT_VIEW
Infoline.EVENT_IAP
Infoline.EVENT_DATA
Infoline.EVENT_GAME
Infoline.EVENT_AUDIO
Infoline.EVENT_VIDEO
Infoline.EVENT_AD
Infoline.EVENT_PUSH
Infoline.EVENT_LOGIN
Infoline.EVENT_DEVICE_ORIENTATION
Infoline.EVENT_DOWNLOAD
Infoline.EVENT_UPLOAD
Infoline.EVENT_DOCUMENT
Infoline.EVENT_HARDWARE_BUTTON
Infoline.EVENT_GESTURE
```
#### Event States
Event Type specific states with the following naming convention

```
Infoline.STATE_VIEW_APPEARED
Infoline.STATE_VIEW_REFRESHED
Infoline.STATE_VIEW_DISAPPEARED

Infoline.STATE_DATA_CANCELLED
Infoline.STATE_DATA_REFRESH
Infoline.STATE_DATA_SUCCEEDED
Infoline.STATE_DATA_FAILED

Infoline.STATE_DOCUMENT_OPEN
Infoline.STATE_DOCUMENT_CLOSE
Infoline.STATE_DOCUMENT_EDIT

Infoline.STATE_DOWNLOAD_CANCELLED
Infoline.STATE_DOWNLOAD_START
Infoline.STATE_DOWNLOAD_SUCCEEDED
Infoline.STATE_DOWNLOAD_FAILED

Infoline.STATE_GAME_ACTION
Infoline.STATE_GAME_STARTED
Infoline.STATE_GAME_FINISHED
Infoline.STATE_GAME_WON
Infoline.STATE_GAME_LOST
Infoline.STATE_GAME_NEW_HIGHSCORE
Infoline.STATE_GAME_NEW_ACHIEVEMENT

Infoline.STATE_GESTURE_SHAKE

Infoline.STATE_HARDWARE_BUTTON_PUSHED

Infoline.STATE_IAP_STARTED
Infoline.STATE_IAP_FINISHED
Infoline.STATE_IAP_CANCELLED

Infoline.STATE_LOGIN_SUCCEEDED
Infoline.STATE_LOGIN_FAILED
Infoline.STATE_LOGIN_LOGOUT

Infoline.STATE_AUDIO_PLAY
Infoline.STATE_AUDIO_PAUSE
Infoline.STATE_AUDIO_STOP
Infoline.STATE_AUDIO_NEXT
Infoline.STATE_AUDIO_PREVIOUS
Infoline.STATE_AUDIO_REPLAY
Infoline.STATE_AUDIO_SEEK_BACK
Infoline.STATE_AUDIO_SEEK_FORWARD

Infoline.STATE_VIDEO_PLAY
Infoline.STATE_VIDEO_PAUSE
Infoline.STATE_VIDEO_STOP
Infoline.STATE_VIDEO_NEXT
Infoline.STATE_VIDEO_PREVIOUS
Infoline.STATE_VIDEO_REPLAY
Infoline.STATE_VIDEO_SEEK_BACK
Infoline.STATE_VIDEO_SEEK_FORWARD

Infoline.STATE_PUSH_RECEIVED

Infoline.STATE_UPLOAD_START
Infoline.STATE_UPLOAD_FAILED
Infoline.STATE_UPLOAD_CANCELLED
Infoline.STATE_UPLOAD_SUCCEEDED


Infoline.STATE_AD_OPEN
Infoline.STATE_AD_CLOSE

Infoline.STATE_ORIENTATION_CHANGED
```

## Functions
#### infonline.startSession()
Start a session. You have to set the offer identifier before calling this function!

#### infonline.stopSession()
Stops a previously initiated session.

#### infonline.logEvent(EventType,EventState,Code,Comment)
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
