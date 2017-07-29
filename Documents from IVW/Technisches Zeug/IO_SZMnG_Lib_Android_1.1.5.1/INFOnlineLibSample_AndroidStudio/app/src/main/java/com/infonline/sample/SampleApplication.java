/*
 * SampleApplication.java
 * 
 * Copyright (c) 2012 RockAByte GmbH. All rights reserved.
 */
package com.infonline.sample;

import android.os.StrictMode;
import android.support.multidex.MultiDexApplication;

import de.infonline.lib.IOLSession;

public class SampleApplication extends MultiDexApplication {
    @Override
    public void onCreate() {
        super.onCreate();

        StrictMode.setThreadPolicy(new StrictMode.ThreadPolicy.Builder()
                .detectAll()
                .penaltyLog()
                .build());
        StrictMode.setVmPolicy(new StrictMode.VmPolicy.Builder()
                .detectAll()
                .penaltyLog()
                .build());

        IOLSession.initIOLSession(this, "iamtest", BuildConfig.DEBUG);
    }
}
