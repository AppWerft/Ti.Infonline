/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2011-2016 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

/** This code is generated, do not edit by hand. **/

#include "ti.infoline.InfolineModule.h"

#include "AndroidUtil.h"
#include "EventEmitter.h"
#include "JNIUtil.h"
#include "JSException.h"
#include "Proxy.h"
#include "ProxyFactory.h"
#include "TypeConverter.h"
#include "V8Util.h"




#include "org.appcelerator.kroll.KrollModule.h"

#define TAG "InfolineModule"

using namespace v8;

namespace ti {
namespace infoline {


Persistent<FunctionTemplate> InfolineModule::proxyTemplate;
jclass InfolineModule::javaClass = NULL;

InfolineModule::InfolineModule(jobject javaObject) : titanium::Proxy(javaObject)
{
}

void InfolineModule::bindProxy(Local<Object> exports, Local<Context> context)
{
	Isolate* isolate = context->GetIsolate();

	Local<FunctionTemplate> pt = getProxyTemplate(isolate);
	Local<Function> proxyConstructor = pt->GetFunction(context).ToLocalChecked();
	Local<String> nameSymbol = NEW_SYMBOL(isolate, "Infoline"); // use symbol over string for efficiency
	Local<Object> moduleInstance = proxyConstructor->NewInstance(context).ToLocalChecked();
	exports->Set(nameSymbol, moduleInstance);
}

void InfolineModule::dispose(Isolate* isolate)
{
	LOGD(TAG, "dispose()");
	if (!proxyTemplate.IsEmpty()) {
		proxyTemplate.Reset();
	}

	titanium::KrollModule::dispose(isolate);
}

Local<FunctionTemplate> InfolineModule::getProxyTemplate(Isolate* isolate)
{
	if (!proxyTemplate.IsEmpty()) {
		return proxyTemplate.Get(isolate);
	}

	LOGD(TAG, "GetProxyTemplate");

	javaClass = titanium::JNIUtil::findClass("ti/infoline/InfolineModule");
	EscapableHandleScope scope(isolate);

	// use symbol over string for efficiency
	Local<String> nameSymbol = NEW_SYMBOL(isolate, "Infoline");

	Local<FunctionTemplate> t = titanium::Proxy::inheritProxyTemplate(isolate,
		titanium::KrollModule::getProxyTemplate(isolate)
, javaClass, nameSymbol);

	proxyTemplate.Reset(isolate, t);
	t->Set(titanium::Proxy::inheritSymbol.Get(isolate),
		FunctionTemplate::New(isolate, titanium::Proxy::inherit<InfolineModule>)->GetFunction());

	titanium::ProxyFactory::registerProxyPair(javaClass, *t);

	// Method bindings --------------------------------------------------------
	titanium::SetProtoMethod(isolate, t, "optOut", InfolineModule::optOut);
	titanium::SetProtoMethod(isolate, t, "sendLoggedEvents", InfolineModule::sendLoggedEvents);
	titanium::SetProtoMethod(isolate, t, "optIn", InfolineModule::optIn);
	titanium::SetProtoMethod(isolate, t, "stopSession", InfolineModule::stopSession);
	titanium::SetProtoMethod(isolate, t, "startSession", InfolineModule::startSession);
	titanium::SetProtoMethod(isolate, t, "logEvent", InfolineModule::logEvent);

	Local<ObjectTemplate> prototypeTemplate = t->PrototypeTemplate();
	Local<ObjectTemplate> instanceTemplate = t->InstanceTemplate();

	// Delegate indexed property get and set to the Java proxy.
	instanceTemplate->SetIndexedPropertyHandler(titanium::Proxy::getIndexedProperty,
		titanium::Proxy::setIndexedProperty);

	// Constants --------------------------------------------------------------
	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		LOGE(TAG, "Failed to get environment in InfolineModule");
		//return;
	}


			DEFINE_STRING_CONSTANT(isolate, prototypeTemplate, "STATE_IAP_CANCELLED", "cancelled");

			DEFINE_STRING_CONSTANT(isolate, prototypeTemplate, "STATE_IAP_STARTED", "started");

			DEFINE_STRING_CONSTANT(isolate, prototypeTemplate, "STATE_VIEW_APPEARED", "appeared");

			DEFINE_STRING_CONSTANT(isolate, prototypeTemplate, "EVENT_GAME", "game");

			DEFINE_STRING_CONSTANT(isolate, prototypeTemplate, "STATE_ADVERTISEMENT_OPEN", "open");

			DEFINE_STRING_CONSTANT(isolate, prototypeTemplate, "STATE_ADVERTISEMENT_CLOSE", "close");

			DEFINE_STRING_CONSTANT(isolate, prototypeTemplate, "STATE_LOGIN_SUCCEEDED", "succeeded");

			DEFINE_STRING_CONSTANT(isolate, prototypeTemplate, "STATE_LOGIN_LOGOUT", "logout");

			DEFINE_STRING_CONSTANT(isolate, prototypeTemplate, "STATE_IAP_FINISHED", "finished");

			DEFINE_STRING_CONSTANT(isolate, prototypeTemplate, "EVENT_ADVERTISEMENT", "advertisement");

			DEFINE_STRING_CONSTANT(isolate, prototypeTemplate, "EVENT_VIEW", "view");

			DEFINE_STRING_CONSTANT(isolate, prototypeTemplate, "STATE_VIEW_DISAPPEARED", "disappeared");

			DEFINE_STRING_CONSTANT(isolate, prototypeTemplate, "EVENT_DOWNLOAD", "download");

			DEFINE_STRING_CONSTANT(isolate, prototypeTemplate, "EVENT_IAP", "iap");

			DEFINE_STRING_CONSTANT(isolate, prototypeTemplate, "EVENT_DOCUMENT", "document");

			DEFINE_STRING_CONSTANT(isolate, prototypeTemplate, "EVENT_LOGIN", "login");

			DEFINE_STRING_CONSTANT(isolate, prototypeTemplate, "STATE_VIEW_REFRESHED", "refreshed");

			DEFINE_STRING_CONSTANT(isolate, prototypeTemplate, "STATE_LOGIN_FAILED", "failed");

			DEFINE_STRING_CONSTANT(isolate, prototypeTemplate, "EVENT_DATA", "data");


	// Dynamic properties -----------------------------------------------------
	instanceTemplate->SetAccessor(NEW_SYMBOL(isolate, "costumerData"),
			titanium::Proxy::getProperty,
			InfolineModule::setter_costumerData,
			Local<Value>(), DEFAULT,
			static_cast<v8::PropertyAttribute>(v8::DontDelete)
		);
	instanceTemplate->SetAccessor(NEW_SYMBOL(isolate, "offerIdentifier"),
			titanium::Proxy::getProperty,
			InfolineModule::setter_offerIdentifier,
			Local<Value>(), DEFAULT,
			static_cast<v8::PropertyAttribute>(v8::DontDelete)
		);

	// Accessors --------------------------------------------------------------

	return scope.Escape(t);
}

// Methods --------------------------------------------------------------------
void InfolineModule::optOut(const FunctionCallbackInfo<Value>& args)
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
		methodID = env->GetMethodID(InfolineModule::javaClass, "optOut", "()V");
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
void InfolineModule::sendLoggedEvents(const FunctionCallbackInfo<Value>& args)
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
		methodID = env->GetMethodID(InfolineModule::javaClass, "sendLoggedEvents", "()V");
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
void InfolineModule::optIn(const FunctionCallbackInfo<Value>& args)
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
		methodID = env->GetMethodID(InfolineModule::javaClass, "optIn", "()V");
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
void InfolineModule::stopSession(const FunctionCallbackInfo<Value>& args)
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
		methodID = env->GetMethodID(InfolineModule::javaClass, "stopSession", "()V");
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
void InfolineModule::startSession(const FunctionCallbackInfo<Value>& args)
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
		methodID = env->GetMethodID(InfolineModule::javaClass, "startSession", "()V");
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
void InfolineModule::logEvent(const FunctionCallbackInfo<Value>& args)
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
		methodID = env->GetMethodID(InfolineModule::javaClass, "logEvent", "(Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;)V");
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


void InfolineModule::setter_costumerData(Local<Name> property, Local<Value> value, const PropertyCallbackInfo<void>& args)
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
		methodID = env->GetMethodID(InfolineModule::javaClass, "setCostumerData", "(Ljava/lang/String;)V");
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



void InfolineModule::setter_offerIdentifier(Local<Name> property, Local<Value> value, const PropertyCallbackInfo<void>& args)
{
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		LOGE(TAG, "Failed to get environment, offerIdentifier wasn't set");
		return;
	}

	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(InfolineModule::javaClass, "setOfferIdentifier", "(Ljava/lang/String;)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'setOfferIdentifier' with signature '(Ljava/lang/String;)V'";
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



} // infoline
} // ti
