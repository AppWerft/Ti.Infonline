/*
 * IOLWebViewActivity.java
 * 
 * Copyright (c) 2012 RockAByte GmbH. All rights reserved.
 */
package com.infonline.sample.web;

import android.graphics.Bitmap;
import android.os.Bundle;
import android.view.KeyEvent;
import android.view.Window;
import android.webkit.WebChromeClient;
import android.webkit.WebView;
import android.webkit.WebViewClient;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.TextView.OnEditorActionListener;

import com.infonline.sample.R;

import de.infonline.app.IOLActivity;


public class IOLWebViewActivity extends IOLActivity {

private static final String TEST_URL = "https://audit.ioam.de/mi.html";
    
    private EditText urlTextField;
    private WebView webView;
    
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        getWindow().requestFeature(Window.FEATURE_PROGRESS);
        
        setContentView(R.layout.activity_hybridwebview);
        
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
 
        this.webView.setWebViewClient(new WebViewClient(){
            @Override
            public void onPageStarted(WebView view, String url, Bitmap favicon) {
                setTitle(R.string.hybrid_webview_titleprefix);
            }

            @Override
            public void onPageFinished(WebView view, String url) {
                setTitle(getString(R.string.hybrid_webview_titleprefix) + view.getTitle());
                
                //Nothing extraordinary to do here, 
                //IOLWebView (in layout activity_hybridwebview.xml) calls the JavaScript method 'setMultiIdentifier' automatically 
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
