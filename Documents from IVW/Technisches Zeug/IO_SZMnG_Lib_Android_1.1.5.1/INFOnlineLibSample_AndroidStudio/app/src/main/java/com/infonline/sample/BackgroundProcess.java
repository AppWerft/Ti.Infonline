/*
 * BackgroundProcess.java
 * 
 * Copyright (c) 2012 RockAByte GmbH. All rights reserved.
 */
package com.infonline.sample;


import de.infonline.lib.IOLEventType;
import de.infonline.lib.IOLSession;

class BackgroundProcess  {
	
	interface BackgroundProcessListener{
		public void backgroundProcessStateChange();
	}
	
	private static final BackgroundProcess staticInstance = new BackgroundProcess();
	
	private volatile BackgroundProcessListener listener = null;		
	private Thread thread = null;
	private volatile boolean stop = false;
	
	private BackgroundProcess(){
	}
	
	static final BackgroundProcess getInstance(){
		return staticInstance;
	}
	
	public void setListener(BackgroundProcessListener listener){
		this.listener = listener;
	}
	
	final boolean isRunning(){
		return this.thread != null;
	}
	
	final boolean isStopping(){
		return this.stop;
	}

	final void start(){
		if(this.thread == null){
			this.thread = new Thread(new Runnable() {				
				@Override
				public void run() {
					if(listener != null){
						listener.backgroundProcessStateChange();
					}
					IOLSession.logEvent(IOLEventType.BackgroundTaskStart);
					
					while(!stop){
						if(listener != null){
							listener.backgroundProcessStateChange();							
						}

						try {
							Thread.sleep(4000);
							IOLSession.logEvent(IOLEventType.DataRefresh);
						} catch (InterruptedException e) {}
					}
					
					thread = null;
					stop = false;
					if(listener != null){
						listener.backgroundProcessStateChange();
					}					
					IOLSession.logEvent(IOLEventType.BackgroundTaskEnd);
				}
			});
			thread.start();
		}
	}
	
	final void stop(){
		this.stop = true;		
	}
}
