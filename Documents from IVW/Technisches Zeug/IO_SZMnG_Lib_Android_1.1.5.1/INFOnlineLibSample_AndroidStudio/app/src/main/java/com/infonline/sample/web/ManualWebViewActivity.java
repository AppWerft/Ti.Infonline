/*
 * IOLWebViewActivity.java
 * 
 * Copyright (c) 2012 RockAByte GmbH. All rights reserved.
 */
package com.infonline.sample.web;

import android.app.Activity;
import android.graphics.Bitmap;
import android.os.Bundle;
import android.view.KeyEvent;
import android.view.Window;
import android.webkit.WebChromeClient;
import android.webkit.WebSettings;
import android.webkit.WebView;
import android.webkit.WebViewClient;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.TextView.OnEditorActionListener;

import com.infonline.sample.R;

import de.infonline.lib.IOLSession;

public class ManualWebViewActivity extends Activity {
	
private static final String TEST_URL = "https://audit.ioam.de/mi.html";
    
    private EditText urlTextField;
    private WebView webView;
    
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        getWindow().requestFeature(Window.FEATURE_PROGRESS);
        
        setContentView(R.layout.activity_manualwebview);
        
        this.urlTextField = (EditText) findViewById(R.id.webview_url_text);
        this.urlTextField.setText(TEST_URL);
        this.urlTextField.setOnEditorActionListener(new OnEditorActionListener(){
            @Override
            public boolean onEditorAction(TextView v, int actionId, KeyEvent event) {
                String url = v.getText().toString();
                if(!url.startsWith("http")){
                    url = "http://"+url;
                }
                webView.loadUrl(url);
                return true;
            }
        });
        
        this.webView = (WebView) findViewById(R.id.webview);
        
        //Make sure JavaScript and Dom-Storage are enabled (IOLWebView does this automatically)
        this.webView.getSettings().setJavaScriptEnabled(true);
        this.webView.getSettings().setDomStorageEnabled(true);
        
        //This Activity uses a standard android.webkit.WebView (see layout activity_manualwebview)
        //So we need to call the JavaScript method 'setMultiIdentifier' manually
        //'setMultiIdentifier' has to be called at least once after the website has been loaded completely
        //In this example we use a custom WebViewClient implementation to call 'setMultiIdentifier' in the onPageFinished method
        this.webView.setWebViewClient(new WebViewClient(){
            @Override
            public void onPageStarted(WebView view, String url, Bitmap favicon) {
                setTitle(R.string.manual_webview_titleprefix);
            }

            @Override
            public void onPageFinished(final WebView view, String url) {
                setTitle(getString(R.string.manual_webview_titleprefix) + view.getTitle());
                
                //page has loaded completely, so call 'setMultiIdentifier'          
                IOLSession.requestMultiIdentifier(new IOLSession.MultiIdentifierCallback() {					
					@Override
					public void onMultiIdentifier(String returnValue) {						
		                String multiIdentifier = returnValue;
		                String multiIdentifierJSCall = "javascript:iom.setMultiIdentifier(\"" + multiIdentifier + "\")";
		                view.loadUrl(multiIdentifierJSCall);   
					}
				});    
            }
        });     
        
        this.webView.setWebChromeClient(new WebChromeClient() {
            @Override
            public void onProgressChanged(WebView view, int progress) {
                setProgress(progress * 100);
            }
        });
        
        this.webView.loadUrl(TEST_URL);   
    }
    
    @Override
    public boolean onKeyDown(int keyCode, KeyEvent event) {
        if ((keyCode == KeyEvent.KEYCODE_BACK) && this.webView.canGoBack()) {
            this.webView.goBack();
            return true;
        }
        return super.onKeyDown(keyCode, event);
    }
}
