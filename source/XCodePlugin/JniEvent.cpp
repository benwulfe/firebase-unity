//
//  JniEvent.cpp
//  XCodePlugin
//
//  Created by benwu on 9/11/15.
//
//

#include "JniEvent.h"
#include "Plugin.pch"

void JniEvent::Process() {
}

ValueChangedEvent::ValueChangedEvent(JniDataSnapshot* snapshot) {
    m_snapshot = snapshot;
}
void ValueChangedEvent::Process() {
    g_valueChanged(m_snapshot->GetCookie(), m_snapshot);
}

ChildAddedEvent::ChildAddedEvent(JniDataSnapshot* snapshot) {
    m_snapshot = snapshot;
}
void ChildAddedEvent::Process() {
    g_childAdded(m_snapshot->GetCookie(), m_snapshot);
}

ChildRemovedEvent::ChildRemovedEvent(JniDataSnapshot* snapshot) {
    m_snapshot = snapshot;
}
void ChildRemovedEvent::Process() {
    g_childRemoved(m_snapshot->GetCookie(), m_snapshot);
}

ChildChangedEvent::ChildChangedEvent(JniDataSnapshot* snapshot) {
    m_snapshot = snapshot;
}
void ChildChangedEvent::Process() {
    g_childChanged(m_snapshot->GetCookie(), m_snapshot);
}

ChildMovedEvent::ChildMovedEvent(JniDataSnapshot* snapshot) {
    m_snapshot = snapshot;
}
void ChildMovedEvent::Process() {
    g_childMoved(m_snapshot->GetCookie(), m_snapshot);
}

AuthSuccessEvent::AuthSuccessEvent(uint64_t cookie, const char* token, const char*uid, uint64_t expiration) {
    m_cookie = cookie;
    m_token = token;
    m_uid = uid;
    m_expiration = expiration;
}
void AuthSuccessEvent::Process() {
    g_authSuccess(m_cookie, m_token, m_uid, m_expiration);
}

AuthFailureEvent::AuthFailureEvent(uint64_t cookie, int code, const char* message, const char* detail) {
    m_cookie = cookie;
    m_code = code;
    m_message = message;
    m_detail = detail;
}
void AuthFailureEvent::Process() {
    g_authCancel(m_cookie, m_code, m_message, m_detail);
}

ErrorEvent::ErrorEvent(void* cookie, int code, const char* message, const char* detail) {
    m_cookie = cookie;
    m_code = code;
    m_message = message;
    m_detail = detail;
}
void ErrorEvent::Process() {
    g_Error(m_cookie, m_code, m_message, m_detail);
}

