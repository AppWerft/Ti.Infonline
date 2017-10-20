package ti.infonline;


import de.infonline.lib.*;

public class Utils {
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
