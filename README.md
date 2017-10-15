# infonline Module

## Description

Module for INFOnline 

## Accessing the infonline Module

To access this module from JavaScript, you would do the following:

    var infonline = require("ti.infonline");

The infonline variable is a reference to the Module object.

## Reference

### Constants
#### Event Types:
Event categories with the following naming convention:
- EVENT_VIEW,... (see module source or SDK for available values)

#### Event States
Event Type specific states with the following naming convention
- STATE_VIEW_APPEARED

##Functions
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

###Properties
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


## Author

(C) 2017 by Stefan Gross (st.gross@gmx.net)

## License

MIT License
