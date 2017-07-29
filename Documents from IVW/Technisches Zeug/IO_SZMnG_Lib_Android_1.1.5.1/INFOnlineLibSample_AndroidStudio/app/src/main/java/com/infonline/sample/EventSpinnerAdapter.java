/*
 * EventSpinnerAdapter.java
 * 
 * Copyright (c) 2012 RockAByte GmbH. All rights reserved.
 */
package com.infonline.sample;


import android.content.Context;
import android.widget.ArrayAdapter;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;
import org.json.JSONTokener;

import java.util.Comparator;

import de.infonline.lib.IOLEventType;

class EventSpinnerAdapter extends ArrayAdapter<String>{
	
	public EventSpinnerAdapter(Context context) {
		super(context, android.R.layout.simple_spinner_item);
		
		try {
			JSONObject config = getConfigFromResource(context);
			JSONObject activeEvents = config.getJSONObject("configuration").getJSONObject("activeEvents");
			JSONArray eventNames = activeEvents.names();
			for(int i=0; i<eventNames.length(); i++){
				JSONArray eventStates = activeEvents.getJSONArray(eventNames.getString(i));
				for(int n=0; n<eventStates.length(); n++){
					String eventName = eventNames.getString(i) +"." + eventStates.getString(n);
					if(!isPublicEvent(eventName)){
						eventName += context.getString(R.string.private_event_ext);
					}
					add(eventName);
				}
			}
		} catch (JSONException e) {
		}
		
		sort(new Comparator<String>() {
			@Override
			public int compare(String lhs, String rhs) {
				return lhs.compareTo(rhs);
			}
		});
	}
		
	private static JSONObject getConfigFromResource(Context context){		
		try {
//            int configId = context.getResources().getIdentifier(context.getPackageName() + ":raw/" + "infonline_lib_config", null, null);
            String jsonString = new java.util.Scanner(context.getResources().openRawResource(de.infonline.lib.R.raw.infonline_lib_config)).useDelimiter("\\A").next();
            return (JSONObject) new JSONTokener(jsonString).nextValue();
		} catch (Exception e) {
		}
		return null;
	}

	static boolean isPublicEvent(String eventName){
		for(IOLEventType type : IOLEventType.values()){
			if( (type.getIdentifier()+"."+type.getState()).equalsIgnoreCase(eventName)){
				return true;
			}
		}
		return false;
	}
	
	static IOLEventType getEventTypeFromString(String eventName){
		for(IOLEventType type : IOLEventType.values()){
			if( (type.getIdentifier()+"."+type.getState()).equalsIgnoreCase(eventName)){
				return type;
			}
		}
		return null;
	}
}