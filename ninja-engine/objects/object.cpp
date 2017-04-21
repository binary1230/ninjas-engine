#include "stdafx.h"
#include "object.h"

#include "gameState.h"
#include "window.h"
#include "globals.h"
#include "animation.h"
#include "animations.h"
#include "gameWorld.h"
#include "gameOptions.h"
#include "gameSound.h"
#include "objectLayer.h"
#include "sprite.h"
#include "physics.h"
#include "..\objectFactory.h"

bool Object::debug_draw_bounding_boxes = 0;
map<std::string, Object*> Object::objectProtoTable;

void Object::SetObjectDefName(const char* _name) {
	objectDefName = _name;
}

std::string Object::GetObjectDefName() {
	return objectDefName;
}

// Used as criteria for STL find()
bool ObjectIsDead(Object* obj) {
	assert(obj != NULL);
	return obj->IsDead();
}

// Objects can call this if they use
// simple animations.
void Object::UpdateSimpleAnimations() {
	if (!currentAnimation)
		return;

	currentAnimation->Update();
	currentSprite = currentAnimation->GetCurrentSprite();
}

// Base update stuff used by all objects
void Object::BaseUpdate() {
	UpdateDisplayTime();
	UpdateFade();

	if (m_pkPhysicsBody)
	{
		UpdatePositionFromPhysicsLocation();

		if (!properties.do_our_own_rotation)
		{
			use_rotation = true;
			rotate_angle = RAD_TO_DEG(-m_pkPhysicsBody->GetAngle());
		}
	}

	if (use_rotation)
	{
		if (properties.do_our_own_rotation)
		{
			// ignore physics for rotation, use our own
			rotate_angle += rotate_velocity;
		}
	}
}

// Decrement the display time, when it reaches 0, we 
// destroy this object. If it's -1, then it lives forever
void Object::UpdateDisplayTime() {
	if (display_time == -1)
		return;

	if (display_time > 0)
		display_time--;

	if (display_time == 0)
		is_dead = true;
}

void Object::InitPhysics()
{
	if (m_pkPhysicsBody)
		return; // already init'd

	if (!PHYSICS)
	{
		TRACE("ERROR: Physics subsystem not yet initialized! Can't init object physics!");
		assert(PHYSICS);
		return;
	}

	if (!properties.uses_physics_engine)
		return;

	// WHO'S READY FOR THE HACKS?!?!?!?
	// TODO: DONT HARDCORE, I WILL KILL YOU
	float fDensity = 0.1f;
	if (properties.is_player)
		fDensity = 0.1f;

	if (properties.is_static)
		m_pkPhysicsBody = PHYSICS->CreateStaticPhysicsBox(pos.x, pos.y, GetWidth(), GetHeight(), properties.is_sensor);
	else
		m_pkPhysicsBody = PHYSICS->CreateDynamicPhysicsBox(pos.x, pos.y, GetWidth(), GetHeight(), properties.ignores_physics_rotation, fDensity, properties.use_angled_corners_collision_box);

	m_pkPhysicsBody->SetUserData(this);
}

void Object::UpdateFade() {
	if (!is_fading)
		return;

	if (!fade_out_time_remaining) {
		is_fading = false;
	} else {
		--fade_out_time_remaining;
	}
	
	alpha = uint(	( (float)fade_out_time_remaining / (float)fade_out_time_total)
								* 255.0f);
}

void Object::FadeOut(int time) {
	fade_out_time_total = fade_out_time_remaining = time;
	alpha = 255;
	is_fading = true;
}

void Object::Clear() {
	m_animationMapping.clear();
	m_bDrawBoundingBox = false;
	tmp_debug_flag = 0;
	ClearProperties(properties);
	is_dead = false;
	fade_out_time_total = fade_out_time_remaining = 0;
	is_fading = false;
	alpha = 255;
	display_time = -1;
	controller_num = 0;
	rotate_angle = rotate_velocity = 0.0f;
	use_rotation = false;
	b_box_offset_x = b_box_offset_y = 0;
	b_box_width = b_box_height = 0;
	m_pkLayer = NULL;
	pos.x = pos.y = 0.0f;
	m_kCurrentCollision.down = 0;
	m_kCurrentCollision.up = 0;
	m_kCurrentCollision.left = 0;
	m_kCurrentCollision.right = 0;
	currentAnimation = NULL;
	animations.clear();
	currentSprite = NULL;	
	flip_x = flip_y = false;
	objectDefName = "";
	alpha = 255;
	b_box_offset_x = b_box_offset_y = 0;
	m_bDrawBoundingBox = false;
	m_pkPhysicsBody = NULL;
	debug_flag = false;

	unique_id = Object::debug_object_id++;
}

bool Object::BaseInit() {
	return true;
}

void Object::Draw() {
	assert(WORLD != NULL);

	if (tmp_debug_flag)
		TRACE("DEBUG FLAG!!\n");

	int flip_offset_x = -b_box_offset_x;
	int flip_offset_y = 0;

	if (b_box_offset_x)
	{
		if (flip_x)
			flip_offset_x = - currentAnimation->GetWidth() + b_box_offset_x + GetWidth();

		flip_offset_y = b_box_height; // not sure if this is right
	}

	DrawAtOffset(flip_offset_x, flip_offset_y);
}


//! Ultimately we need the actual, on-screen coordinates of where
//! to draw the sprite.  To get to those from the object's "world" coordinates
//! as computed by the physics engine, we need to take into account the 
//! position of the camera, and we need to flip the Y axis.  These
//! things are handled by the WORLD->TransformXXX() methods.
//
//! This function populates x,y (reference params) with the 
//! correctly transformed coordinates.
void Object::Transform(int &x, int &y, const int &offset_x, const int &offset_y) {
	x = (int)pos.x + offset_x;
	y = (int)pos.y + offset_y;

	// take into account the camera now.
	if (!properties.is_overlay)
		WORLD->TransformWorldToView(x, y);
	
	// compute absolute x,y coordinates on the screen
	y = y + GetHeight();
	WORLD->TransformViewToScreen(x, y);
}

// Same as Transform(), just for rectangles only.
void Object::TransformRect(_Rect &r) {

	int x1, x2, y1, y2, w, h;
	
	// r.Fix();
	
	x1 = (int)r.getx1();	
	y1 = (int)r.gety1();	
	x2 = (int)r.getx2();
	y2 = (int)r.gety2();
	w = x2 - x1;
	h = y2 - y1;

	// take into account the camera now.
	if (!properties.is_overlay) {
		WORLD->TransformWorldToView(x1, y1);
		WORLD->TransformWorldToView(x2, y2);
	}
	
	// compute absolute x,y coordinates on the screen
	WORLD->TransformViewToScreen(x1, y1);
	WORLD->TransformViewToScreen(x2, y2);

	r.set(x1,y1,x2,y2);
}

//! This function does the real dirty work of drawing.
void Object::DrawAtOffset(int offset_x, int offset_y, Sprite* sprite_to_draw) 
{	
	int x, y;
	Transform(x, y, offset_x, offset_y);
				
	// draw for real
	if (!sprite_to_draw)
		sprite_to_draw = currentSprite;

	if (sprite_to_draw)
		WINDOW->DrawSprite(sprite_to_draw, x, y, flip_x, flip_y, use_rotation, rotate_angle, alpha);

	#if DEBUG_DRAW_SPRITE
	if (sprite_to_draw && (b_box_offset_x || b_box_offset_y))
	{
		const bool bOnlyDrawBoundingBox = true;
		WINDOW->DrawSprite(sprite_to_draw, x, y, flip_x, flip_y, use_rotation, rotate_angle, alpha, bOnlyDrawBoundingBox);
	}
	#endif

	if (m_bDrawBoundingBox) 
	{
		_Rect bbox_t;

		// get current bounding box
		bbox_t.set(	pos.x, pos.y, pos.x + GetWidth(), pos.y + GetHeight());

		// draw current bounding rectangle, pink
		TransformRect(bbox_t);
		WINDOW->DrawRect(bbox_t, al_map_rgb(255,0,255));
	}
}

int Object::GetWidth() const
{
	if (b_box_width > 0) {
		return b_box_width;
	}

	if (animations.size() <= 0 || !animations[0]) {
		return 0;
	}

	return animations[0]->GetWidth();
}

int Object::GetHeight() const
{
	if (b_box_height > 0) {
		return b_box_height;
	}

	if (animations.size() <= 0 || !animations[0]) {
		return 0;
	}
	return animations[0]->GetHeight();
}

void Object::ResetForNextFrame()
{
	m_kCurrentCollision.up = m_kCurrentCollision.down = m_kCurrentCollision.left = m_kCurrentCollision.right = 0;

	if (m_pkPhysicsBody)
	{
		const b2Vec2& kPos = m_pkPhysicsBody->GetPosition();
		pos.x = kPos.x;
		pos.y = kPos.y;
	}
}

void Object::BaseShutdown() {
	assert(m_pkLayer);
	m_pkLayer->RemoveObject(this);

	int i, max = animations.size();
	for (i = 0; i < max; i++) {
		if (animations[i])
			animations[i]->Shutdown();
		SAFE_DELETE(animations[i]);
	}
	animations.clear();
	
	currentAnimation = NULL;
	currentSprite = NULL;
	m_pkLayer = NULL;
	is_dead = true;
	display_time = -1;

	if (PHYSICS && m_pkPhysicsBody)
		PHYSICS->RemoveFromWorld(m_pkPhysicsBody);
}

unsigned long Object::debug_object_id = 0;

void Object::OnCollide(Object* obj, const b2WorldManifold* pkbWorldManifold)
{
	// default is no action, this is overidden in higher classes
}

void Object::PlayAnimation( uint uiIndex )
{
	assert(uiIndex >=0 && uiIndex < animations.size() && "Animation index out of range.");

	if (uiIndex < 0 || uiIndex >= animations.size())
	{
		TRACE("ERROR: Animation #%i is out of range! Can't switch to it.\n", uiIndex);
		return;
	}

	if (!animations[uiIndex])
	{
		TRACE("ERROR: Animation #%i contains nothing! Can't switch to it.\n", uiIndex);
		return;
	}

	if (currentAnimation == animations[uiIndex])
		return;

	currentAnimation = animations[uiIndex];
	currentAnimation->ResetAnimation();
}

void Object::ApplyImpulse( float x, float y )
{
	ApplyImpulse(b2Vec2(x, y));
}

void Object::ApplyImpulse(const b2Vec2& v)
{
	if (m_pkPhysicsBody)
		m_pkPhysicsBody->ApplyLinearImpulseToCenter(v, true);
}

void Object::UpdatePositionFromPhysicsLocation()
{
	pos.x = METERS_TO_PIXELS(m_pkPhysicsBody->GetPosition().x) - float(GetWidth()) / 2;
	pos.y = METERS_TO_PIXELS(m_pkPhysicsBody->GetPosition().y) - float(GetHeight()) / 2;
}

bool Object::FinishLoading()
{
	XMLNode* xDef = OBJECT_FACTORY->FindObjectDefinition(GetObjectDefName());
	assert(xDef);
	return LoadFromObjectDef(*xDef);
}

bool Object::LoadFromObjectDef(XMLNode& xDef) {
	SetObjectDefName(xDef.getAttribute("name"));

	if (!Init())
		return false;

	if (!LoadObjectProperties(xDef))
		return false;

	if (!LoadObjectSounds(xDef))
		return false;

	if (!LoadObjectAnimations(xDef))
		return false;

	#if USE_OLD_LOADING_SYSTEM == 0
	InitPhysics();
	#endif

	return true;
}

bool Object::LoadObjectSounds(XMLNode &xDef) {
	if (xDef.nChildNode("sounds")) {
		XMLNode xSounds = xDef.getChildNode("sounds");
		if (!SOUND->LoadSounds(xSounds))
			return false;
	}

	return true;
}

bool Object::LoadObjectProperties(XMLNode &xDef) {
	XMLNode xProps = xDef.getChildNode("properties");

	// TODO: these are overriding things set in Init()

	properties.feels_gravity = xProps.nChildNode("affectedByGravity") != 0;
	properties.feels_user_input = xProps.nChildNode("affectedByInput1") != 0;
	properties.feels_friction = xProps.nChildNode("affectedByFriction") != 0;

	properties.uses_physics_engine = xProps.nChildNode("solidObject") != 0;
	properties.is_static = xProps.nChildNode("solidObject") != 0;

	properties.do_our_own_rotation = xProps.nChildNode("noPhysicsRotate") != 0;
	properties.is_sensor = xProps.nChildNode("sensorOnly") != 0;

	properties.spawns_enemies = xProps.nChildNode("spawnsEnemies") != 0;

	if (xProps.nChildNode("isOverlay")) {
		properties.is_overlay = 1;
	}

	if (xProps.nChildNode("boundingBox") != 0)
	{
		XMLNode xBoundingBox = xProps.getChildNode("boundingBox");

		if (!xBoundingBox.nChildNode("offset_x"))
		{
			return false;
		}

		if (!xBoundingBox.getChildNode("offset_x").getInt(b_box_offset_x) ||
			!xBoundingBox.getChildNode("offset_y").getInt(b_box_offset_y) ||
			!xBoundingBox.getChildNode("width").getInt(b_box_width) ||
			!xBoundingBox.getChildNode("height").getInt(b_box_height))
		{
			TRACE("Invalid bounding box info.\n");
			return false;
		}
	}

	return true;
}

bool Object::LoadXMLInstanceProperties(XMLNode & xObj)
{
	return true;
}

// A helper function to load animations
bool Object::LoadObjectAnimations(XMLNode &xDef) {
	uint i;
	int num_xml_animations, num_animation_slots_needed = -1, iterator;

	Animation* anim = NULL;
	std::string anim_name;
	XMLNode xAnim, xAnims;

	xAnims = xDef.getChildNode("animations");
	num_xml_animations = xAnims.nChildNode("animation");

	if (m_animationMapping.size())
		num_animation_slots_needed = m_animationMapping.size();

	animations.resize(max(num_xml_animations, num_animation_slots_needed));

	// zero out all the animations to NULL
	for (i = 0; i < animations.size(); ++i)
		animations[i] = NULL;

	// read everything from XML
	for (i = iterator = 0; i<(uint)num_xml_animations; ++i)
	{
		xAnim = xAnims.getChildNode("animation", &iterator);
		anim_name = xAnim.getAttribute("name");

		// Load the animation	
		anim = Animation::Load(xAnim, this);

		if (!anim)
			return false;

		// if we have animation names (e.g. "walking") then use them to figure
		// out which index we store this animation at
		// if not, just put it in the next available index
		uint index;
		if (m_animationMapping.size())
			index = m_animationMapping[anim_name];
		else
			index = i;

		assert(index >= 0 && index < animations.size());
		animations[index] = anim;
	}
	
	std::string default_name;
	int default_index;

	if (m_animationMapping.size()) {
		default_name = xAnims.getAttribute("default");
		default_index = m_animationMapping[default_name];
		currentAnimation = animations[default_index];
	} else {
		if (animations.size() > 0) {
			currentAnimation = animations[0];
		}
	}

	if (currentAnimation) {
		currentSprite = currentAnimation->GetCurrentSprite();
	}

	return true;
}

Object::Object() {
	Clear();
}
Object::~Object() {}

Object* Object::AddPrototype(string type, Object * obj)
{
	TRACE("adding object prototype for '%s' ", type.c_str());
	objectProtoTable[type] = obj;
	return obj; // handy
}

Object* Object::CreateObject(std::string type)
{
	std::map<string, Object*>::iterator it;
	it = objectProtoTable.find(type);
	if (it == objectProtoTable.end()) {
		TRACE("CreateObject(): Object type named '%s' not found", type.c_str());
		return NULL;
	}

	Object* obj = it->second;
		
	return obj->Clone();
}

BOOST_CLASS_EXPORT_GUID(Object, "Object")