#include "stdafx.h"
#include "eventManager.h"
#include "luaManager.h"

DECLARE_SINGLETON(EventManager)

EventManager::EventManager() {}
EventManager::~EventManager() {}

bool EventManager::Init() {
	return true;
}

void EventManager::Shutdown() {
}

void EventManager::OnLoad() {
	LUA->RunVoidFunctionNoArgs("Level_OnLoad", false);
}

void EventManager::OnUnLoad() {
	LUA->RunVoidFunctionNoArgs("Level_OnUnLoad", false);
}

void EventManager::OnTextboxDone() {
	LUA->RunVoidFunctionNoArgs("Textbox_Done", false);
}

void EventManager::OnInputEndedPlayback() {
	LUA->RunVoidFunctionNoArgs("Input_DonePlaying", false);
}

void EventManager::OnPickupItem(const char* name) {
	LUA->RunVoidFunction1Args("OnPickupItem", name, false);
}

void EventManager::OnEvent(const char* eventName) {
	std::string sEventCall = "Event_";
	sEventCall += eventName;

	LUA->RunVoidFunctionNoArgs(sEventCall.c_str(), false);
}
