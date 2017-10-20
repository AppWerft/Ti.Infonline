/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2011-2016 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

/** This code is generated, do not edit by hand. **/

#include "ti.infonline.InfonlineModule.h"

#include "AndroidUtil.h"
#include "EventEmitter.h"
#include "JNIUtil.h"
#include "JSException.h"
#include "Proxy.h"
#include "ProxyFactory.h"
#include "TypeConverter.h"
#include "V8Util.h"




#include "org.appcelerator.kroll.KrollModule.h"

#define TAG "InfonlineModule"

using namespace v8;

namespace ti {
namespace infonline {


Persistent<FunctionTemplate> InfonlineModule::proxyTemplate;
jclass InfonlineModule::javaClass = NULL;

InfonlineModule::InfonlineModule(jobject javaObject) : titanium::Proxy(javaObject)
{
}

void InfonlineModule::bindProxy(Local<Object> exports, Local<Context> context)
{
	Isolate* isolate = context->GetIsolate();

	Local<FunctionTemplate> pt = getProxyTemplate(isolate);
	Local<Function> proxyConstructor = pt->GetFunction(context).ToLocalChecked();
	Local<String> nameSymbol = NEW_SYMBOL(isolate, "Infonline"); // use symbol over string for efficiency
	Local<Object> moduleInstance = proxyConstructor->NewInstance(context).ToLocalChecked();
	exports->Set(nameSymbol, moduleInstance);
}

void InfonlineModule::dispose(Isolate* isolate)
{
	LOGD(TAG, "dispose()");
	if (!proxyTemplate.IsEmpty()) {
		proxyTemplate.Reset();
	}

	titanium::KrollModule::dispose(isolate);
}

Local<FunctionTemplate> InfonlineModule::getProxyTemplate(Isolate* isolate)
{
	if (!proxyTemplate.IsEmpty()) {
		return proxyTemplate.Get(isolate);
	}

	LOGD(TAG, "GetProxyTemplate");

	javaClass = titanium::JNIUtil::findClass("ti/infonline/InfonlineModule");
	EscapableHandleScope scope(isolate);

	// use symbol over string for efficiency
	Local<String> nameSymbol = NEW_SYMBOL(isolate, "Infonline");

	Local<FunctionTemplate> t = titanium::Proxy::inheritProxyTemplate(isolate,
		titanium::KrollModule::getProxyTemplate(isolate)
, javaClass, nameSymbol);

	proxyTemplate.Reset(isolate, t);
	t->Set(titanium::Proxy::inheritSymbol.Get(isolate),
		FunctionTemplate::New(isolate, titanium::Proxy::inherit<InfonlineModule>)->GetFunction());

	titanium::ProxyFactory::registerProxyPair(javaClass, *t);

	// Method bindings --------------------------------------------------------
	titanium::SetProtoMethod(isolate, t, "getVersion", InfonlineModule::getVersion);
	titanium::SetProtoMethod(isolate, t, "optOut", InfonlineModule::optOut);
	titanium::SetProtoMethod(isolate, t, "sendLoggedEvents", InfonlineModule::sendLoggedEvents);
	titanium::SetProtoMethod(isolate, t, "enableDebug", InfonlineModule::enableDebug);
	titanium::SetProtoMethod(isolate, t, "disableDebug", InfonlineModule::disableDebug);
	titanium::SetProtoMethod(isolate, t, "setDeviceIdEnabled", InfonlineModule::setDeviceIdEnabled);
	titanium::SetProtoMethod(isolate, t, "setDbg", InfonlineModule::setDbg);
	titanium::SetProtoMethod(isolate, t, "optIn", InfonlineModule::optIn);
	titanium::SetProtoMethod(isolate, t, "stopSession", InfonlineModule::stopSession);
	titanium::SetProtoMethod(isolate, t, "startSession", InfonlineModule::startSession);
	titanium::SetProtoMethod(isolate, t, "logEvent", InfonlineModule::logEvent);

	Local<ObjectTemplate> prototypeTemplate = t->PrototypeTemplate();
	Local<ObjectTemplate> instanceTemplate = t->InstanceTemplate();

	// Delegate indexed property get and set to the Java proxy.
	instanceTemplate->SetIndexedPropertyHandler(titanium::Proxy::getIndexedProperty,
		titanium::Proxy::setIndexedProperty);

	// Constants --------------------------------------------------------------
	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		LOGE(TAG, "Failed to get environment in InfonlineModule");
		//return;
	}


			DEFINE_STRING_CONSTANT(isolate, prototypeTemplate, "STATE_VIEW_APPEARED", "appeared");

			DEFINE_STRING_CONSTANT(isolate, prototypeTemplate, "EVENT_GAME", "game");

			DEFINE_STRING_CONSTANT(isolate, prototypeTemplate, "STATE_DOWNLOAD_CANCELLED", "cancelled");

			DEFINE_STRING_CONSTANT(isolate, prototypeTemplate, "STATE_DOCUMENT_CLOSE", "close");

			DEFINE_STRING_CONSTANT(isolate, prototypeTemplate, "STATE_LOGIN_SUCCEEDED", "succeeded");

			DEFINE_STRING_CONSTANT(isolate, prototypeTemplate, "STATE_DOWNLOAD_SUCCEDED", "succeeded");

			DEFINE_STRING_CONSTANT(isolate, prototypeTemplate, "EVENT_VIEW", "view");

			DEFINE_STRING_CONSTANT(isolate, prototypeTemplate, "STATE_GAME_NewAchievement", "newachievement");

			DEFINE_STRING_CONSTANT(isolate, prototypeTemplate, "STATE_DATA_CANCELLED", "cancelled");

			DEFINE_STRING_CONSTANT(isolate, prototypeTemplate, "STATE_DATA_SUCCEEDED", "succeeded");

			DEFINE_STRING_CONSTANT(isolate, prototypeTemplate, "EVENT_DOCUMENT", "document");

			DEFINE_STRING_CONSTANT(isolate, prototypeTemplate, "EVENT_LOGIN", "login");

			DEFINE_STRING_CONSTANT(isolate, prototypeTemplate, "STATE_VIEW_REFRESHED", "refreshed");

			DEFINE_STRING_CONSTANT(isolate, prototypeTemplate, "STATE_LOGIN_FAILED", "failed");

			DEFINE_STRING_CONSTANT(isolate, prototypeTemplate, "EVENT_DATA", "data");

			DEFINE_STRING_CONSTANT(isolate, prototypeTemplate, "STATE_IAP_CANCELLED", "cancelled");

			DEFINE_STRING_CONSTANT(isolate, prototypeTemplate, "STATE_GAME_ACTION", "action");

			DEFINE_STRING_CONSTANT(isolate, prototypeTemplate, "STATE_IAP_STARTED", "started");

			DEFINE_STRING_CONSTANT(isolate, prototypeTemplate, "STATE_GAME_LOST", "lost");

			DEFINE_STRING_CONSTANT(isolate, prototypeTemplate, "STATE_DOCUMENT_EDIT", "edit");

			DEFINE_STRING_CONSTANT(isolate, prototypeTemplate, "STATE_GAME_FINISHED", "finished");

			DEFINE_STRING_CONSTANT(isolate, prototypeTemplate, "STATE_ADVERTISEMENT_OPEN", "open");

			DEFINE_STRING_CONSTANT(isolate, prototypeTemplate, "STATE_ADVERTISEMENT_CLOSE", "close");

			DEFINE_STRING_CONSTANT(isolate, prototypeTemplate, "STATE_DATA_FAILED", "failed");

			DEFINE_STRING_CONSTANT(isolate, prototypeTemplate, "STATE_DOCUMENT_OPEN", "open");

			DEFINE_STRING_CONSTANT(isolate, prototypeTemplate, "STATE_LOGIN_LOGOUT", "logout");

			DEFINE_STRING_CONSTANT(isolate, prototypeTemplate, "STATE_IAP_FINISHED", "finished");

			DEFINE_STRING_CONSTANT(isolate, prototypeTemplate, "STATE_DOWNLOAD_FAILED", "failed");

			DEFINE_STRING_CONSTANT(isolate, prototypeTemplate, "EVENT_ADVERTISEMENT", "advertisement");

			DEFINE_STRING_CONSTANT(isolate, prototypeTemplate, "STATE_VIEW_DISAPPEARED", "disappeared");

			DEFINE_STRING_CONSTANT(isolate, prototypeTemplate, "STATE_DATA_REFRESH", "refresh");

			DEFINE_STRING_CONSTANT(isolate, prototypeTemplate, "STATE_GAME_WON", "won");

			DEFINE_STRING_CONSTANT(isolate, prototypeTemplate, "STATE_GAME_NEWHIGHSCORE", "newhighscore");

			DEFINE_STRING_CONSTANT(isolate, prototypeTemplate, "EVENT_DOWNLOAD", "download");

			DEFINE_STRING_CONSTANT(isolate, prototypeTemplate, "EVENT_IAP", "iap");

			DEFINE_STRING_CONSTANT(isolate, prototypeTemplate, "STATE_DOWNLOAD_START", "start");

			DEFINE_STRING_CONSTANT(isolate, prototypeTemplate, "STATE_GAME_STARTED", "started");


	// Dynamic properties -----------------------------------------------------
	instanceTemplate->SetAccessor(NEW_SYMBOL(isolate, "costumerData"),
			titanium::Proxy::getProperty,
			InfonlineModule::setter_costumerData,
			Local<Value>(), DEFAULT,
			static_cast<v8::PropertyAttribute>(v8::DontDelete)
		);

	// Accessors --------------------------------------------------------------

	return scope.Escape(t);
}

// Methods --------------------------------------------------------------------
void InfonlineModule::getVersion(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "getVersion()");
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(InfonlineModule::javaClass, "getVersion", "()Ljava/lang/String;");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'getVersion' with signature '()Ljava/lang/String;'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	// If holder isn't the JavaObject wrapper we expect, look up the prototype chain
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}

	titanium::Proxy* proxy = titanium::Proxy::unwrap(holder);

	jvalue* jArguments = 0;

	jobject javaProxy = proxy->getJavaObject();
	jstring jResult = (jstring)env->CallObjectMethodA(javaProxy, methodID, jArguments);



	if (!JavaObject::useGlobalRefs) {
		env->DeleteLocalRef(javaProxy);
	}



	if (env->ExceptionCheck()) {
		Local<Value> jsException = titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
		return;
	}

	if (jResult == NULL) {
		args.GetReturnValue().Set(Null(isolate));
		return;
	}

	Local<Value> v8Result = titanium::TypeConverter::javaStringToJsString(isolate, env, jResult);

	env->DeleteLocalRef(jResult);


	args.GetReturnValue().Set(v8Result);

}
void InfonlineModule::optOut(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "optOut()");
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(InfonlineModule::javaClass, "optOut", "()V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'optOut' with signature '()V'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	// If holder isn't the JavaObject wrapper we expect, look up the prototype chain
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}

	titanium::Proxy* proxy = titanium::Proxy::unwrap(holder);

	jvalue* jArguments = 0;

	jobject javaProxy = proxy->getJavaObject();
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	if (!JavaObject::useGlobalRefs) {
		env->DeleteLocalRef(javaProxy);
	}



	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




	args.GetReturnValue().Set(v8::Undefined(isolate));

}
void InfonlineModule::sendLoggedEvents(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "sendLoggedEvents()");
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(InfonlineModule::javaClass, "sendLoggedEvents", "()V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'sendLoggedEvents' with signature '()V'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	// If holder isn't the JavaObject wrapper we expect, look up the prototype chain
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}

	titanium::Proxy* proxy = titanium::Proxy::unwrap(holder);

	jvalue* jArguments = 0;

	jobject javaProxy = proxy->getJavaObject();
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	if (!JavaObject::useGlobalRefs) {
		env->DeleteLocalRef(javaProxy);
	}



	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




	args.GetReturnValue().Set(v8::Undefined(isolate));

}
void InfonlineModule::enableDebug(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "enableDebug()");
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(InfonlineModule::javaClass, "enableDebug", "()V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'enableDebug' with signature '()V'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	// If holder isn't the JavaObject wrapper we expect, look up the prototype chain
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}

	titanium::Proxy* proxy = titanium::Proxy::unwrap(holder);

	jvalue* jArguments = 0;

	jobject javaProxy = proxy->getJavaObject();
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	if (!JavaObject::useGlobalRefs) {
		env->DeleteLocalRef(javaProxy);
	}



	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




	args.GetReturnValue().Set(v8::Undefined(isolate));

}
void InfonlineModule::disableDebug(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "disableDebug()");
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(InfonlineModule::javaClass, "disableDebug", "()V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'disableDebug' with signature '()V'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	// If holder isn't the JavaObject wrapper we expect, look up the prototype chain
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}

	titanium::Proxy* proxy = titanium::Proxy::unwrap(holder);

	jvalue* jArguments = 0;

	jobject javaProxy = proxy->getJavaObject();
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	if (!JavaObject::useGlobalRefs) {
		env->DeleteLocalRef(javaProxy);
	}



	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




	args.GetReturnValue().Set(v8::Undefined(isolate));

}
void InfonlineModule::setDeviceIdEnabled(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "setDeviceIdEnabled()");
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(InfonlineModule::javaClass, "setDeviceIdEnabled", "(Ljava/lang/Boolean;)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'setDeviceIdEnabled' with signature '(Ljava/lang/Boolean;)V'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	// If holder isn't the JavaObject wrapper we expect, look up the prototype chain
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}

	titanium::Proxy* proxy = titanium::Proxy::unwrap(holder);

	if (args.Length() < 1) {
		char errorStringBuffer[100];
		sprintf(errorStringBuffer, "setDeviceIdEnabled: Invalid number of arguments. Expected 1 but got %d", args.Length());
		titanium::JSException::Error(isolate, errorStringBuffer);
		return;
	}

	jvalue jArguments[1];




	bool isNew_0;

	if (!args[0]->IsNull()) {
		Local<Value> arg_0 = args[0];
		jArguments[0].l =
			titanium::TypeConverter::jsValueToJavaObject(
				isolate,
				env, arg_0, &isNew_0);
	} else {
		jArguments[0].l = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	if (!JavaObject::useGlobalRefs) {
		env->DeleteLocalRef(javaProxy);
	}



			if (isNew_0) {
				env->DeleteLocalRef(jArguments[0].l);
			}


	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




	args.GetReturnValue().Set(v8::Undefined(isolate));

}
void InfonlineModule::setDbg(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "setDbg()");
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(InfonlineModule::javaClass, "setDbg", "(Ljava/lang/Boolean;)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'setDbg' with signature '(Ljava/lang/Boolean;)V'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	// If holder isn't the JavaObject wrapper we expect, look up the prototype chain
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}

	titanium::Proxy* proxy = titanium::Proxy::unwrap(holder);

	if (args.Length() < 1) {
		char errorStringBuffer[100];
		sprintf(errorStringBuffer, "setDbg: Invalid number of arguments. Expected 1 but got %d", args.Length());
		titanium::JSException::Error(isolate, errorStringBuffer);
		return;
	}

	jvalue jArguments[1];




	bool isNew_0;

	if (!args[0]->IsNull()) {
		Local<Value> arg_0 = args[0];
		jArguments[0].l =
			titanium::TypeConverter::jsValueToJavaObject(
				isolate,
				env, arg_0, &isNew_0);
	} else {
		jArguments[0].l = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	if (!JavaObject::useGlobalRefs) {
		env->DeleteLocalRef(javaProxy);
	}



			if (isNew_0) {
				env->DeleteLocalRef(jArguments[0].l);
			}


	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




	args.GetReturnValue().Set(v8::Undefined(isolate));

}
void InfonlineModule::optIn(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "optIn()");
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(InfonlineModule::javaClass, "optIn", "()V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'optIn' with signature '()V'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	// If holder isn't the JavaObject wrapper we expect, look up the prototype chain
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}

	titanium::Proxy* proxy = titanium::Proxy::unwrap(holder);

	jvalue* jArguments = 0;

	jobject javaProxy = proxy->getJavaObject();
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	if (!JavaObject::useGlobalRefs) {
		env->DeleteLocalRef(javaProxy);
	}



	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




	args.GetReturnValue().Set(v8::Undefined(isolate));

}
void InfonlineModule::stopSession(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "stopSession()");
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(InfonlineModule::javaClass, "stopSession", "()V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'stopSession' with signature '()V'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	// If holder isn't the JavaObject wrapper we expect, look up the prototype chain
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}

	titanium::Proxy* proxy = titanium::Proxy::unwrap(holder);

	jvalue* jArguments = 0;

	jobject javaProxy = proxy->getJavaObject();
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	if (!JavaObject::useGlobalRefs) {
		env->DeleteLocalRef(javaProxy);
	}



	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




	args.GetReturnValue().Set(v8::Undefined(isolate));

}
void InfonlineModule::startSession(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "startSession()");
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(InfonlineModule::javaClass, "startSession", "()V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'startSession' with signature '()V'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	// If holder isn't the JavaObject wrapper we expect, look up the prototype chain
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}

	titanium::Proxy* proxy = titanium::Proxy::unwrap(holder);

	jvalue* jArguments = 0;

	jobject javaProxy = proxy->getJavaObject();
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	if (!JavaObject::useGlobalRefs) {
		env->DeleteLocalRef(javaProxy);
	}



	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




	args.GetReturnValue().Set(v8::Undefined(isolate));

}
void InfonlineModule::logEvent(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "logEvent()");
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(InfonlineModule::javaClass, "logEvent", "(Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'logEvent' with signature '(Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;)V'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	// If holder isn't the JavaObject wrapper we expect, look up the prototype chain
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}

	titanium::Proxy* proxy = titanium::Proxy::unwrap(holder);

	if (args.Length() < 4) {
		char errorStringBuffer[100];
		sprintf(errorStringBuffer, "logEvent: Invalid number of arguments. Expected 4 but got %d", args.Length());
		titanium::JSException::Error(isolate, errorStringBuffer);
		return;
	}

	jvalue jArguments[4];




	bool isNew_0;

	if (!args[0]->IsNull()) {
		Local<Value> arg_0 = args[0];
		jArguments[0].l =
			titanium::TypeConverter::jsValueToJavaObject(
				isolate,
				env, arg_0, &isNew_0);
	} else {
		jArguments[0].l = NULL;
	}

	bool isNew_1;

	if (!args[1]->IsNull()) {
		Local<Value> arg_1 = args[1];
		jArguments[1].l =
			titanium::TypeConverter::jsValueToJavaObject(
				isolate,
				env, arg_1, &isNew_1);
	} else {
		jArguments[1].l = NULL;
	}

	bool isNew_2;

	if (!args[2]->IsNull()) {
		Local<Value> arg_2 = args[2];
		jArguments[2].l =
			titanium::TypeConverter::jsValueToJavaObject(
				isolate,
				env, arg_2, &isNew_2);
	} else {
		jArguments[2].l = NULL;
	}

	bool isNew_3;

	if (!args[3]->IsNull()) {
		Local<Value> arg_3 = args[3];
		jArguments[3].l =
			titanium::TypeConverter::jsValueToJavaObject(
				isolate,
				env, arg_3, &isNew_3);
	} else {
		jArguments[3].l = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	if (!JavaObject::useGlobalRefs) {
		env->DeleteLocalRef(javaProxy);
	}



			if (isNew_0) {
				env->DeleteLocalRef(jArguments[0].l);
			}


			if (isNew_1) {
				env->DeleteLocalRef(jArguments[1].l);
			}


			if (isNew_2) {
				env->DeleteLocalRef(jArguments[2].l);
			}


			if (isNew_3) {
				env->DeleteLocalRef(jArguments[3].l);
			}


	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




	args.GetReturnValue().Set(v8::Undefined(isolate));

}

// Dynamic property accessors -------------------------------------------------


void InfonlineModule::setter_costumerData(Local<Name> property, Local<Value> value, const PropertyCallbackInfo<void>& args)
{
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		LOGE(TAG, "Failed to get environment, costumerData wasn't set");
		return;
	}

	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(InfonlineModule::javaClass, "setCostumerData", "(Ljava/lang/String;)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'setCostumerData' with signature '(Ljava/lang/String;)V'";
			LOGE(TAG, error);
		}
	}

	titanium::Proxy* proxy = titanium::Proxy::unwrap(args.Holder());
	if (!proxy) {
		return;
	}

	jvalue jArguments[1];

	

	if (!value->IsNull()) {
		Local<Value> arg_0 = value;
		jArguments[0].l =
			titanium::TypeConverter::jsValueToJavaString(
				isolate,
				env, arg_0);
	} else {
		jArguments[0].l = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	if (!JavaObject::useGlobalRefs) {
		env->DeleteLocalRef(javaProxy);
	}



				env->DeleteLocalRef(jArguments[0].l);


	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




	Proxy::setProperty(property, value, args);
}



} // infonline
} // ti
