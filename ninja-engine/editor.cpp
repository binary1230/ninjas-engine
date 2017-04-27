#include "stdafx.h"
#include "editor.h"
#include "object.h"
#include "objectFactory.h"
#include "gameWorld.h"
#include "input.h"
#include "window.h"
#include "gameState.h"
#include "camera.h"

Object * Editor::CreateObject(const char * objDefName, const char * layerName) {
	XMLNode* xDef = OBJECT_FACTORY->FindObjectDefinition(objDefName);
	assert(xDef);

	string className = OBJECT_FACTORY->GetClassNameFromXML(*xDef);
	Object* obj = Object::CreateObject(className);

	ObjectLayer* layer = WORLD->FindLayer(layerName);
	assert(layer);
	obj->SetLayer(layer);

	obj->SetObjectDefName(objDefName);
	obj->FinishLoading();

	WORLD->AddObject(obj, true);

	_last_object_def_name = objDefName;
	_last_layer_name = layerName;

	return obj;
}

void Editor::CreateAndSelectObject(const char* objDefName, const char* layerName) {
	_mode = EDITOR_MOVE;
	_should_create_another_copy_after_move = true;

	Object* obj = CreateObject(objDefName, layerName);

	SelectObject(obj);
	UpdateSelectedObjectPosition();
}

void Editor::CreateAndSelect_UsePreviousLayerAndObject() {
	CreateAndSelectObject(_last_object_def_name.c_str(), _last_layer_name.c_str());
}

// transform mouse input to compensate for scroll speeds on layers
void Editor::MouseToLayerCoords(b2Vec2& layer_coord_out, ObjectLayer* layer) {
	assert(layer);

	b2Vec2 cameraXY;
	WORLD->GetCamera()->GetXY(cameraXY);

	layer_coord_out.x = (INPUT->MouseX() / layer->GetScrollSpeed()) + cameraXY.x;
	layer_coord_out.y = ((WINDOW->Height() - INPUT->MouseY()) / layer->GetScrollSpeed()) + cameraXY.y;
}

void Editor::SnapToGrid(b2Vec2& pos) {
	uint grid_resolution_x = _grid_resolution;
	uint grid_resolution_y = _grid_resolution;

	if (_selection) {
		grid_resolution_x = _selection->GetWidth();
		grid_resolution_y = _selection->GetHeight();

		if (grid_resolution_x < 1)
			grid_resolution_x = _grid_resolution;

		if (grid_resolution_y < 1)
			grid_resolution_y = _grid_resolution;
	}

	pos.x -= int(pos.x) % grid_resolution_x;
	pos.y -= int(pos.y) % grid_resolution_y;
}

void Editor::UpdateSelectedObjectPosition() {
	if (!_selection)
		return;

	b2Vec2 layer_pos;
	MouseToLayerCoords(layer_pos, _selection->GetLayer());

	if (_SnapToGrid) {
		SnapToGrid(layer_pos);
	}

	_selection->SetXY(layer_pos);
}

void Editor::SelectObject(Object* obj) {
	if (_selection) {
		_selection->SetDrawBounds(false);
	}

	_selection = obj;

	if (_selection) {
		_selection->SetDrawBounds(true, al_map_rgb(255, 255, 0));
	}
}

void Editor::Draw() {
	if (_text_time_remaining > 0)
		WINDOW->DrawText(5, 5, _tooltip_text);
}

void Editor::CommonUpdate() {
	_pausedChanged = _wasPaused != GAMESTATE->IsPaused();
	if (_pausedChanged) {
		FlashText(!_wasPaused ? "paused" : "unpaused");
	}

	if (_text_time_remaining > 0)
		_text_time_remaining--;
	
	SetDrawBoundingBoxes_AllObjects(false);

	_obj_under_mouse = GetObjectUnderCursor();

	if (INPUT->RealKeyOnce(ALLEGRO_KEY_G)) {
		_SnapToGrid = !_SnapToGrid;
		FlashText(_SnapToGrid ? "grid snap on" : "grid snap off");
	}

	if (INPUT->RealKeyOnce(ALLEGRO_KEY_R)) {
		ResetVolatileLevelState(LEVEL_ITEMS);
	}

	if (INPUT->RealKeyOnce(ALLEGRO_KEY_P)) {
		ResetVolatileLevelState(LEVEL_PLAYERS);
	}
}

void Editor::FlashText(string text) {
	_text_time_remaining = 200;
	_tooltip_text = text;
}

void Editor::NoModeUpdate() {
	if (!GAMESTATE->IsPaused()) {
		SelectObject(NULL);
		return;
	}

	if (_obj_under_mouse && _obj_under_mouse != _selection)
		_obj_under_mouse->SetDrawBounds(true);

	if (INPUT->MouseButtonOnce(MOUSE_LEFT_BTN)) {
		SelectObject(_obj_under_mouse); // can be NULL
	}

	if (INPUT->RealKeyOnce(ALLEGRO_KEY_C)) {
		if (_last_layer_name.length() > 0 && _last_object_def_name.length() > 0) {
			CreateAndSelect_UsePreviousLayerAndObject();
			FlashText("creating objects");
		}
	}

	if (_selection && INPUT->RealKeyOnce(ALLEGRO_KEY_DELETE)) {
		DeleteCurrentSelection();
	}

	if (_selection && INPUT->RealKeyOnce(ALLEGRO_KEY_M)) {
		_mode = EDITOR_MOVE;
		FlashText("move mode");
	}

	if (INPUT->RealKeyOnce(ALLEGRO_KEY_F5)) {
		WORLD->SaveWorldOverCurrentFile();
		FlashText("saved level!");
	}
}

// reset anything "volatile" that shouldn't get saved, like whether we picked up coins, player initial position, etc
void Editor::ResetVolatileLevelState(VolatileStateLevel level) {
	for (Object*& obj : WORLD->_objects) {
		obj->ResetVolatileState(level);
	}

	FlashText("reset'd volatile state");
}

void Editor::UpdateMove() {
	assert(_mode == EDITOR_MOVE);
	assert(_selection);

	UpdateSelectedObjectPosition();

	if (GAMESTATE->IsPaused() && INPUT->MouseButtonOnce(MOUSE_LEFT_BTN)) {
		_mode = EDITOR_NONE;

		if (_should_create_another_copy_after_move)
			CreateAndSelect_UsePreviousLayerAndObject();
	}

	bool endMode =	INPUT->RealKeyOnce(ALLEGRO_KEY_ESCAPE) || 
					INPUT->MouseButtonOnce(MOUSE_RIGHT_BTN) ||
					(_pausedChanged && !GAMESTATE->IsPaused());

	if (endMode) {
		DeleteCurrentSelection();
		_mode = EDITOR_NONE;
		_should_create_another_copy_after_move = false;
	}
}

Object* Editor::GetObjectUnderCursor() {
	b2Vec2 layer_coords;

	for (Object*& obj : WORLD->_objects) {
		MouseToLayerCoords(layer_coords, obj->GetLayer());

		if (obj->ContainsPoint(layer_coords))
			return obj;
	}

	return NULL;
}

void Editor::SetDrawBoundingBoxes_AllObjects(bool should_draw) {
	for (Object*& obj : WORLD->_objects) {
		if (obj != _selection)
			obj->SetDrawBounds(false);
	}
}

void Editor::Update() {
	CommonUpdate();

	switch (_mode) {
	case EDITOR_MOVE:
		UpdateMove();
		break;
	case EDITOR_NONE:
		NoModeUpdate();
		break;
	default:
		assert(false && "invalid mode selected");
		break;
	}

	_wasPaused = GAMESTATE->IsPaused();
}

void Editor::DeleteCurrentSelection() {
	if (!_selection)
		return;

	_selection->SetIsDead(true);
	SelectObject(NULL);

	WORLD->RemoveDeadObjectsIfNeeded();
}

Editor::Editor() {
	_selection = NULL;
	_grid_resolution = 30;
	_SnapToGrid = false;
	WORLD->SetAllowExiting(false);
	_mode = EDITOR_NONE;
	_wasPaused = GAMESTATE->IsPaused();
	_pausedChanged = false;
	_obj_under_mouse = NULL;

	_should_create_another_copy_after_move = false;

	_text_time_remaining = 0;
	_tooltip_text = "";
}

Editor::~Editor() {}