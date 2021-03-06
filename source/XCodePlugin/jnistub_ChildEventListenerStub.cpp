//
//  jnistub_ChildEventListenerStub.cpp
//  XCodePlugin
//
//  Created by benwu on 8/24/15.
//
//

#include <stdio.h>
#include <pthread.h>
#include "jnistub_ChildEventListenerStub.h"
#include "JniDataSnapshot.h"
#include "plugin.pch"
#include "JniHelper.h"
#include "JniEventProcessor.h"
#include "JniEvent.h"
#include "JniFirebaseError.h"

/*
* Class:     jnistub_ChildEventListenerStub
* Method:    onChildAdded
* Signature: (Lcom/firebase/client/DataSnapshot;Ljava/lang/String;)V
*/
JNIEXPORT void JNICALL Java_jnistub_ChildEventListenerStub_onChildAdded
(JNIEnv *, jobject, jlong cookie, jobject snapshot, jstring) {
    JniEventProcessor::GetInstance()->EnqueueEvent(new ChildAddedEvent(
                                                      new JniDataSnapshot(snapshot, (void*)cookie, JniDataSnapshot::ChildAdded)));
}

/*
 * Class:     jnistub_ChildEventListenerStub
 * Method:    onChildChanged
 * Signature: (Lcom/firebase/client/DataSnapshot;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_jnistub_ChildEventListenerStub_onChildChanged
(JNIEnv *, jobject, jlong cookie, jobject snapshot, jstring) {
    JniEventProcessor::GetInstance()->EnqueueEvent( new ChildChangedEvent(
                                                      new JniDataSnapshot(snapshot, (void*)cookie, JniDataSnapshot::ChildChanged)));
}

/*
 * Class:     jnistub_ChildEventListenerStub
 * Method:    onChildRemoved
 * Signature: (Lcom/firebase/client/DataSnapshot;)V
 */
JNIEXPORT void JNICALL Java_jnistub_ChildEventListenerStub_onChildRemoved
(JNIEnv *, jobject, jlong cookie, jobject snapshot) {
    JniEventProcessor::GetInstance()->EnqueueEvent(  new ChildRemovedEvent(
                                                      new JniDataSnapshot(snapshot, (void*)cookie, JniDataSnapshot::ChildRemoved)));
}

/*
 * Class:     jnistub_ChildEventListenerStub
 * Method:    onChildMoved
 * Signature: (Lcom/firebase/client/DataSnapshot;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_jnistub_ChildEventListenerStub_onChildMoved
(JNIEnv *, jobject, jlong cookie, jobject snapshot, jstring) {
    JniEventProcessor::GetInstance()->EnqueueEvent(  new ChildMovedEvent(
                                                      new JniDataSnapshot(snapshot, (void*)cookie, JniDataSnapshot::ChildMoved)));

}

/*
 * Class:     jnistub_ChildEventListenerStub
 * Method:    onCancelled
 * Signature: (JLcom/firebase/client/FirebaseError;)V
 */
JNIEXPORT void JNICALL Java_jnistub_ChildEventListenerStub_onCancelled
(JNIEnv *, jobject, jlong cookie, jobject firebaseError) {
    JniFirebaseError error = JniFirebaseError(firebaseError);
    JniEventProcessor::GetInstance()->EnqueueEvent(
                                                   new ErrorEvent((void*)cookie, error.GetCode(),
                                                                        error.GetErrorMessage(), error.GetDetails()));
}
