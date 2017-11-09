# infonline Titanium Module
![](http://www.ivw.eu/profiles/ivw_website/themes/ivw_theme/logo.png)
## Description

Axway Titanium Module for INFOnline. InfOnline is the solution for [IVW-tracking](http://www.ivw.eu/digital/digital). The developmenbt was sponsored by [4D Media GmbH](https://4dmedia.de/) in Düsseldorf.

## About IVW


The German Audit Bureau of Circulation (IVW) has neutrally and objectively recorded and audited the distribution of advertising media since 1949. With the establishment of the IVW, media providers (publishers), advertisers and advertising agencies created an effective controlling system which is under their joint supervision.

Almost all relevant advertising media categories are covered under the umbrella of the IVW: newspapers, magazines and other periodically appearing press products, broadcast media (radio and TV), cinema advertising and digital media.

The underlying idea is simple and obvious. In order to function, the advertising market requires performance data regarding the advertising media that are offered on the market. However, if these data were collected by each provider of an advertising medium for its own advertising media with its own individual methods, on the one hand, no comparability with the data of other providers would be guaranteed, and on the other hand, there would also be no independent assurance of data quality. The advertising market players transferred these tasks to a common parent institution: the IVW.

The results of the IVW's work provide reliable data for the market, for professional advertisers and performance-based competition between the media. As an independent, non-commercial, and neutral auditing organization, the IVW provides the media and advertising industry, and interested public, with basic data for the marketing of media as advertising.

Behind the system of circulation certification, digital measurement applications and the corresponding audit procedures are complex rules and regulations which are negotiated and decided by the delegates of advertisers, agencies and media providers at the IVW "round table". The bodies are committed to the consensus principle and to the IVW´s duty to ensure transparency, i.e. a common denominator is reached in the IVW between the opposing interests of the provider and the customer. The resulting definitions and conventions form market standards and the data provided by the IVW have become the accepted currency for quantitative advertising media performance.  The consensus principle ensures the general acceptance of these currencies, and in this sense, the IVW is a classic Joint Industry Committee (JIC).

## Accessing the infonline Module

To access this module from JavaScript, you would do the following:

    var InfOnline = require("ti.infonline");

The infonline variable is a reference to the Module object.

## Reference

### Constants
#### Event Types:
Event categories with the following naming convention:

```
InfOnline.EVENT_VIEW
InfOnline.EVENT_IAP
InfOnline.EVENT_DATA
InfOnline.EVENT_GAME
InfOnline.EVENT_AUDIO
InfOnline.EVENT_VIDEO
InfOnline.EVENT_AD
InfOnline.EVENT_PUSH
InfOnline.EVENT_LOGIN
InfOnline.EVENT_DEVICE_ORIENTATION
InfOnline.EVENT_DOWNLOAD
InfOnline.EVENT_UPLOAD
InfOnline.EVENT_DOCUMENT
InfOnline.EVENT_HARDWARE_BUTTON
InfOnline.EVENT_GESTURE
```
#### Event States
Event Type specific states with the following naming convention

```
InfOnline.STATE_VIEW_APPEARED
InfOnline.STATE_VIEW_REFRESHED
InfOnline.STATE_VIEW_DISAPPEARED

InfOnline.STATE_DATA_CANCELLED
InfOnline.STATE_DATA_REFRESH
InfOnline.STATE_DATA_SUCCEEDED
InfOnline.STATE_DATA_FAILED

InfOnline.STATE_DOCUMENT_OPEN
InfOnline.STATE_DOCUMENT_CLOSE
InfOnline.STATE_DOCUMENT_EDIT

InfOnline.STATE_DOWNLOAD_CANCELLED
InfOnline.STATE_DOWNLOAD_START
InfOnline.STATE_DOWNLOAD_SUCCEEDED
InfOnline.STATE_DOWNLOAD_FAILED

InfOnline.STATE_GAME_ACTION
InfOnline.STATE_GAME_STARTED
InfOnline.STATE_GAME_FINISHED
InfOnline.STATE_GAME_WON
InfOnline.STATE_GAME_LOST
InfOnline.STATE_GAME_NEW_HIGHSCORE
InfOnline.STATE_GAME_NEW_ACHIEVEMENT

InfOnline.STATE_GESTURE_SHAKE

InfOnline.STATE_HARDWARE_BUTTON_PUSHED

InfOnline.STATE_IAP_STARTED
InfOnline.STATE_IAP_FINISHED
InfOnline.STATE_IAP_CANCELLED

InfOnline.STATE_LOGIN_SUCCEEDED
InfOnline.STATE_LOGIN_FAILED
InfOnline.STATE_LOGIN_LOGOUT

InfOnline.STATE_AUDIO_PLAY
InfOnline.STATE_AUDIO_PAUSE
InfOnline.STATE_AUDIO_STOP
InfOnline.STATE_AUDIO_NEXT
InfOnline.STATE_AUDIO_PREVIOUS
InfOnline.STATE_AUDIO_REPLAY
InfOnline.STATE_AUDIO_SEEK_BACK
InfOnline.STATE_AUDIO_SEEK_FORWARD

InfOnline.STATE_VIDEO_PLAY
InfOnline.STATE_VIDEO_PAUSE
InfOnline.STATE_VIDEO_STOP
InfOnline.STATE_VIDEO_NEXT
InfOnline.STATE_VIDEO_PREVIOUS
InfOnline.STATE_VIDEO_REPLAY
InfOnline.STATE_VIDEO_SEEK_BACK
InfOnline.STATE_VIDEO_SEEK_FORWARD

InfOnline.STATE_PUSH_RECEIVED

InfOnline.STATE_UPLOAD_START
InfOnline.STATE_UPLOAD_FAILED
InfOnline.STATE_UPLOAD_CANCELLED
InfOnline.STATE_UPLOAD_SUCCEEDED


InfOnline.STATE_AD_OPEN
InfOnline.STATE_AD_CLOSE

InfOnline.STATE_ORIENTATION_CHANGED
```
## offerId
The module  needs an offerId, you will get this id from IVW.
Please put the string into your tiapp.xml:

```xml
<property name="IVW_OFFERID_ANDROID" type="string">YOUR_ID</property>
<property name="IVW_OFFERID_IOS" type="string">YOUR_ID</property>
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

### Android only functions:
#### infonline.enableDebug()
#### infonline.disableDebug()
#### infonline.getVersion()
#### setDeviceIdEnabled()  
Needs runtime permission "PHONE_STATE"



### Properties


#### infonline.customerData
Customer data according INFOnline SDK documentation


## Usage

	var iol = require("ti.infonline");
	iol.startSession();
	iol.logEvent(iol.EVENT_VIEW,iol.STATE_VIEW_APPEARED,"My code","My comment");

## Special handling on Android

Every activity must call these both methods:
```
var win = Ti.UI.createWindow({………}); // for tabgroup too"

win.addEvent.activity.onStart=function() {iol.onStart();}
win.addEvent.activity.onStop=function() {iol.onStop();}
```
Maybe it is a good idea to build a generic window.

## Potential pitfalls on Android
Ab August 2014 muss gemäß den Bestimmungen der [Google Play Developer Program Policies](http://play.google.com/about/developer-content-policy.html) der AdvertisingIdentifier in Bezug auf AudienceMeasurement zum Einsatz kommen

Um den AdvertisingIdentifier zu erfassen, muss die Google Play Services Bibliothek in das Projekt eingebunden werden, jedoch nur die Google Mobile Ads API. 

HINWEIS Die Integration der Google Play Services Library muss auch für Apps erfolgen, welche nicht im Google Play Store veröffentlicht werden!

This module is compiled with playservice bersion 11.0.2. If you use in your app additional google modules too (like analytics, firebase oder maps) then you will run in a versions conflict: all parts of google play service must have the same version number. You find the version number inside timodule.xml:

```
<application>
   <meta-data
 	    android:name="com.google.android.gms.version"
 	    android:value="1102000"/>
</application>
```
In some cases you find a reference like:

```xml
<application>
     <meta-data
     	android:name="com.google.android.gms.version"
     	android:value="@integer/google_play_services_version"/>
</application>
```
In this case you fimnd the version inside this file `android/platform/android/res/values/version.xml`

this entry:

```xml
<?xml version="1.0" encoding="utf-8"?>
<resources>
    <integer name="google_play_services_version">10298000</integer>
</resources>
````
### Generating jars
In case of problem above you need to regenerate all jars. The jars you can extract from `ANDROID_SDK/extras/google/m2repository/com/google/android/gms/`. In most cases the ANDROID_SDK is in your homne at `Library/Android/sdk` or in `/opt/android-sdk`. With thos script you can extract:

```sh
#!/bin/sh

if [ $# -lt 1 ]; then
  echo "Usage: $0 <version>  1>&2"
  exit 1
fi

VERSION=$1
GOOGLE=/opt/android-sdk/extras/google/m2repository/com/google
AAR2JAR=/usr/local/bin/aar2jar.sh

# jars for ads:
$AAR2JAR $GOOGLE/android/gms/play-services-ads/$VERSION/play-services-ads-$VERSION.aar lib/
$AAR2JAR $GOOGLE/android/gms/play-services-ads-light/$VERSION/play-services-ads-light-$VERSION.aar lib/
$AAR2JAR $GOOGLE/android/gms/play-services-base/$VERSION/play-services-base-$VERSION.aar lib/
$AAR2JAR $GOOGLE/android/gms/play-services-basement/$VERSION/play-services-basement-$VERSION.aar lib/
$AAR2JAR $GOOGLE/android/gms/play-services-gass/$VERSION/play-services-gass-$VERSION.aar lib/
$AAR2JAR $GOOGLE/android/gms/play-services-clearcut/$VERSION/play-services-clearcut-$VERSION.aar lib/
$AAR2JAR $GOOGLE/android/gms/play-services-safetynet/$VERSION/play-services-safetynet-$VERSION.aar lib/

# jars for map:
$AAR2JAR $GOOGLE/android/gms/play-services-safetynet/$VERSION/play-services-maps-$VERSION.aar lib/

# jars for analytics
$AAR2JAR $GOOGLE/android/gms/play-services-analytics/$VERSION/play-services-analytics-$VERSION.aar lib/
$AAR2JAR $GOOGLE/android/gms/play-services-tagmanagere-v4-impl/$VERSION/play-services-tagmanagere-v4-impl-$VERSION.aar lib/

```
All dependencies you can found in *.pom file inside aar.

The content of `aar2jar.sh` you can find in net or here:

```sh
#!/bin/sh
 
if [ $# -lt 1 ]; then
  echo "Usage: $0 <aar_file> [<output_path>]" 1>&2
  exit 1
fi
 
unzip $1 -d /tmp/aar2jar > /dev/null
if [ -z "$2" ]; then
  dir=.
else
  dir=$2
fi
mv /tmp/aar2jar/classes.jar $dir/`basename $1 .aar`.jar
rm -rf /tmp/aar2jar
```
You can copy this file above to a folder in your path, maybe into `/usr/local/bin`

Hint:
Is is a good idea to give the jars a name with versions number.
## Authors

* (C) 2017 by Stefan Gross (st.gross@gmx.net) (iOS)
* (C) 2017 by Rainer Schleevoigt (rs@hamburger-appwerft.de) (Android)


## License

MIT License
