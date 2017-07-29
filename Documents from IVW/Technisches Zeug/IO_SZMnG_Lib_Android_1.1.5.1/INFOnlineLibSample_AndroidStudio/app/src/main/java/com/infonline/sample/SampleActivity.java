/*
 * SampleActivity.java
 * 
 * Copyright (c) 2012 RockAByte GmbH. All rights reserved.
 */
package com.infonline.sample;


import android.Manifest;
import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.database.Cursor;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.net.Uri;
import android.net.wifi.WifiManager;
import android.os.AsyncTask;
import android.os.Bundle;
import android.provider.MediaStore;
import android.support.annotation.NonNull;
import android.support.annotation.Nullable;
import android.support.v4.app.ActivityCompat;
import android.support.v4.content.ContextCompat;
import android.util.Log;
import android.view.KeyEvent;
import android.view.Menu;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemSelectedListener;
import android.widget.Button;
import android.widget.CompoundButton;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.ProgressBar;
import android.widget.Spinner;
import android.widget.ToggleButton;

import com.infonline.sample.BackgroundProcess.BackgroundProcessListener;
import com.infonline.sample.web.IOLWebViewActivity;
import com.infonline.sample.web.ManualWebViewActivity;

import de.infonline.app.IOLActivity;
import de.infonline.lib.IOLEventType;
import de.infonline.lib.IOLSession;

public class SampleActivity extends IOLActivity implements BackgroundProcessListener{

	private static final int REQUEST_PERMISSION_RESULT = 0;

	private static final int SELECT_IMAGE_RESULT = 0x28267;
	private Button backgroundProcessButton;

	private int lastOrientation = -1;

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);

		final WifiManager wifiManager = (WifiManager)getSystemService(Context.WIFI_SERVICE);
		final Button wlanButton = (Button) findViewById(R.id.buttonWlan);
		wlanButton.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) {
				if(wifiManager.isWifiEnabled()){
					wlanButton.setText(R.string.enable_wlan);
				}else{
					wlanButton.setText(R.string.disable_wlan);
				}
				wifiManager.setWifiEnabled(!wifiManager.isWifiEnabled());
			}
		});
		if(wifiManager.isWifiEnabled()){
			wlanButton.setText(R.string.disable_wlan);
		}else{
			wlanButton.setText(R.string.enable_wlan);
		}


		Button galleryButton = (Button) findViewById(R.id.buttonOpenGallery);
		galleryButton.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) {
				Intent intent = new Intent();
				intent.setType("image/*");
				intent.setAction(Intent.ACTION_GET_CONTENT);
				startActivityForResult(Intent.createChooser(intent, "Select Picture"),SELECT_IMAGE_RESULT);

				IOLSession.logEvent(IOLEventType.OpenAppOther, "gallery", null);
			}
		});

		Button crashButton = (Button) findViewById(R.id.buttonCrash);
		crashButton.setOnClickListener(new OnClickListener() {
			@SuppressWarnings("null")
			@Override
			public void onClick(View v) {
				//NullPointerException
				String s = null;
				s.toString();
			}
		});

		final Spinner eventSpinner = (Spinner) findViewById(R.id.spinnerEvents);
		EventSpinnerAdapter spinnerAdapter = new EventSpinnerAdapter(this);
		spinnerAdapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
		eventSpinner.setAdapter(spinnerAdapter);

		final Button buttonLogSpinnerEvent = (Button) findViewById(R.id.buttonLogSpinnerEvent);
		final EditText categoryEditText = (EditText) findViewById(R.id.category_edittext);
		final EditText commentEditText = (EditText) findViewById(R.id.comment_edittext);
		final EditText customerDataEditText = (EditText) findViewById(R.id.customerdata_edittext);
		buttonLogSpinnerEvent.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) {
				IOLEventType type = EventSpinnerAdapter.getEventTypeFromString((String)eventSpinner.getSelectedItem());
				if(type != null){
					IOLSession.setCustomerData(customerDataEditText.getText().toString());
					IOLSession.logEvent(type, categoryEditText.getText().toString(), commentEditText.getText().toString());
				}
			}
		});
		eventSpinner.setOnItemSelectedListener(new OnItemSelectedListener() {
			@Override
			public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
				if(((String)eventSpinner.getSelectedItem()).endsWith(getString(R.string.private_event_ext))){
					buttonLogSpinnerEvent.setEnabled(false);
				}else{
					buttonLogSpinnerEvent.setEnabled(true);
				}
			}
			@Override
			public void onNothingSelected(AdapterView<?> arg0) {}
		});



		this.backgroundProcessButton = (Button) findViewById(R.id.buttonBackground);
		backgroundProcessButton.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) {
				if(BackgroundProcess.getInstance().isRunning()){
					BackgroundProcess.getInstance().stop();
				}else{
					BackgroundProcess.getInstance().start();
				}
				updateBackgroundProcessButton();
			}
		});
		updateBackgroundProcessButton();


		Button sendButton = (Button) findViewById(R.id.buttonSendLoggedEvents);
		sendButton.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) {
				IOLSession.sendLoggedEvents();
			}
		});

		Button startSessionButton = (Button) findViewById(R.id.buttonStartSession);
		startSessionButton.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) {
				IOLSession.startSession();
			}
		});

		Button terminateSessionButton = (Button) findViewById(R.id.buttonTerminateSession);
		terminateSessionButton.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) {
				IOLSession.terminateSession();
			}
		});

		Button openHybridWebView = (Button) findViewById(R.id.buttonOpenHybridWebView);
		openHybridWebView.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) {
				Intent intent = new Intent(SampleActivity.this, IOLWebViewActivity.class);
				startActivity(intent);
			}
		});

		Button openManualWebView = (Button) findViewById(R.id.buttonOpenManualWebView);
		openManualWebView.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) {
				Intent intent = new Intent(SampleActivity.this, ManualWebViewActivity.class);
				startActivity(intent);
			}
		});

		ToggleButton toggleDeviceIDs = (ToggleButton) findViewById(R.id.toggleButtonDeviceIDs);
		toggleDeviceIDs.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
			@Override
			public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
				IOLSession.setDeviceIDsEnabled(isChecked);
			}
		});

		Button requestRuntimePermissionReadPhoneState = (Button) findViewById(R.id.buttonRequestPermission);
		requestRuntimePermissionReadPhoneState.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) {
				if (ContextCompat.checkSelfPermission(SampleActivity.this, Manifest.permission.READ_PHONE_STATE) != PackageManager.PERMISSION_GRANTED) {
					ActivityCompat.requestPermissions(SampleActivity.this, new String[]{Manifest.permission.READ_PHONE_STATE}, REQUEST_PERMISSION_RESULT);
				} else {
					Log.d("SampleActivity", "Permission already granted.");
				}
			}
		});


		ViewGroup focusLayout = (ViewGroup) findViewById(R.id.focuslayout);
		focusLayout.requestFocus();
	}

	@Override
	public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {
		if (requestCode == REQUEST_PERMISSION_RESULT) {
			if (grantResults.length > 0 && grantResults[0] == PackageManager.PERMISSION_GRANTED) {
				Log.d("SampleActivity", "Permission Granted");
			}
		}
	}

	private final void updateBackgroundProcessButton(){
		ProgressBar progressBar = (ProgressBar) findViewById(R.id.backgroundProgressBar);
		if(BackgroundProcess.getInstance().isRunning()){
			if(BackgroundProcess.getInstance().isStopping()){
				backgroundProcessButton.setText(R.string.quittin_background_process);
				backgroundProcessButton.setEnabled(false);
			}else{
				backgroundProcessButton.setText(R.string.end_background_process);
				backgroundProcessButton.setEnabled(true);
			}
			progressBar.setVisibility(View.VISIBLE);
		}else{
			backgroundProcessButton.setText(R.string.start_background_process);
			backgroundProcessButton.setEnabled(true);
			progressBar.setVisibility(View.INVISIBLE);
		}
	}

	@Override
	protected void onActivityResult(int requestCode, int resultCode, Intent data) {
		super.onActivityResult(requestCode, resultCode, data);

		if(requestCode == SELECT_IMAGE_RESULT){
			if(resultCode == RESULT_OK){
				IOLSession.logEvent(IOLEventType.DocumentOpen, "galleryimage", null);
				new LoadBitmap().execute(data.getData());
			}
		}
	};


	@Override
	protected void onStart() {
		super.onStart();
		BackgroundProcess.getInstance().setListener(this);
		IOLSession.logEvent(IOLEventType.ViewAppeared, "mainscreen", null);

		//Log orientation changes
		int orientation = getResources().getConfiguration().orientation;
		if(orientation != this.lastOrientation){
			IOLSession.logEvent(IOLEventType.DeviceOrientationChanged);
			this.lastOrientation = orientation;
		}
	}

	@Override
	protected void onStop() {
		IOLSession.logEvent(IOLEventType.ViewDisappeared, "mainscreen", null);
		BackgroundProcess.getInstance().setListener(null);
		super.onStop();
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		getMenuInflater().inflate(R.menu.activity_main, menu);
		return true;
	}

	@Override
	public boolean dispatchKeyEvent (KeyEvent event){
		if(event.getAction() == KeyEvent.ACTION_UP && event.getKeyCode() == KeyEvent.KEYCODE_BACK){
			IOLSession.logEvent(IOLEventType.HardwareButtonPushed, "", "");
		}
		return super.dispatchKeyEvent(event);
	}

	class LoadBitmap extends AsyncTask<Uri, Void, Bitmap>{

		@Override
		protected void onPreExecute(){
			IOLSession.logEvent(IOLEventType.BackgroundTaskStart, "loadimage", null);
		}

		@Override
		protected Bitmap doInBackground(Uri... params) {

			String bitmapPath = null;
			Bitmap bitmap = null;

			//Get image path
			{
				String[] filePathColumn = {MediaStore.Images.Media.DATA};

				Cursor cursor = getContentResolver().query(params[0], filePathColumn, null, null, null);
				cursor.moveToFirst();

				int columnIndex = cursor.getColumnIndex(filePathColumn[0]);
				bitmapPath = cursor.getString(columnIndex);
				cursor.close();
			}

			//Load Bitmap
			if(bitmapPath != null){
				BitmapFactory.Options bounds = new BitmapFactory.Options();
				bounds.inJustDecodeBounds = true;
				BitmapFactory.decodeFile(bitmapPath,bounds);

				if(bounds.outWidth != -1){
					int width = bounds.outWidth;
					int height = bounds.outHeight;

					if(width > 800 || height > 800){
						bounds.inJustDecodeBounds = false;
						bounds.inSampleSize = (int) Math.pow(2, ((int)(Math.max(width, height)/800)));
						bitmap = BitmapFactory.decodeFile(bitmapPath, bounds);
					}else{
						bitmap = BitmapFactory.decodeFile(bitmapPath);
					}
				}
			}
			return bitmap;
		}

		@Override
		protected void onPostExecute(Bitmap bitmap) {
			IOLSession.logEvent(IOLEventType.BackgroundTaskEnd, "loadimage", null);
			if(bitmap != null){
				ImageView imageView = (ImageView) findViewById(R.id.imageView1);
				imageView.setImageBitmap(bitmap);
			}
		}
	}

	@Override
	public void backgroundProcessStateChange() {
		runOnUiThread(new Runnable() {
			@Override
			public void run() {
				updateBackgroundProcessButton();
			}
		});
	}
}
