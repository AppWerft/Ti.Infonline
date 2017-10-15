/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2011-2016 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

/** This is generated, do not edit by hand. **/

#include <jni.h>

#include "Proxy.h"

namespace ti {
namespace infoline {

class InfolineModule : public titanium::Proxy
{
public:
	explicit InfolineModule(jobject javaObject);

	static void bindProxy(v8::Local<v8::Object>, v8::Local<v8::Context>);
	static v8::Local<v8::FunctionTemplate> getProxyTemplate(v8::Isolate*);
	static void dispose(v8::Isolate*);

	static jclass javaClass;

private:
	static v8::Persistent<v8::FunctionTemplate> proxyTemplate;

	// Methods -----------------------------------------------------------
	static void optOut(const v8::FunctionCallbackInfo<v8::Value>&);
	static void sendLoggedEvents(const v8::FunctionCallbackInfo<v8::Value>&);
	static void optIn(const v8::FunctionCallbackInfo<v8::Value>&);
	static void stopSession(const v8::FunctionCallbackInfo<v8::Value>&);
	static void startSession(const v8::FunctionCallbackInfo<v8::Value>&);
	static void logEvent(const v8::FunctionCallbackInfo<v8::Value>&);

	// Dynamic property accessors ----------------------------------------
	static void setter_dbg(v8::Local<v8::Name> name, v8::Local<v8::Value> value, const v8::PropertyCallbackInfo<void>& info);
	static void setter_costumerData(v8::Local<v8::Name> name, v8::Local<v8::Value> value, const v8::PropertyCallbackInfo<void>& info);
	static void setter_offerIdentifier(v8::Local<v8::Name> name, v8::Local<v8::Value> value, const v8::PropertyCallbackInfo<void>& info);

};

} // infoline
} // ti
