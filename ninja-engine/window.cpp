#include "stdafx.h"
#include "window.h"

#include "assetManager.h"
#include "game.h"
#include "globals.h"
#include "sprite.h"
#include "gameOptions.h"

DECLARE_SINGLETON(Window)

int screen_size_x = DEFAULT_SCREEN_SIZE_X;
int screen_size_y = DEFAULT_SCREEN_SIZE_Y;

void Window::Screenshot(char* filename) {
	/*std::string file;
	static int screenshot_num = 0;

	if (filename) {
		file = filename;
	} else {
		// Make one up.
		file.Format("ninjas-screenshot%i.png", screenshot_num++);
	}

	TRACE(" -- saving screenshot '%s'\n", file);

	al_save_bitmap(file, al_get_target_bitmap());*/
}
	
void Window::DrawFade() {
	if (fading_state == FADED_NONE)
		return;

	DrawRect(0,0,width,height, al_map_rgb(0,0,0),true,fade_alpha);
}

void Window::Draw() {
	DrawFade();
}

void Window::Update() {
	UpdateFade();
}

void Window::UpdateFade() {

	if (fading_state == FADED_NONE || fading_state == FADED_OUT)
		return;

	if (fading_state == FADING_IN) {
		fade_alpha -= fade_rate;
		if (fade_alpha <= 0)
			fading_state = FADED_NONE;
	} else if (fading_state == FADING_OUT) {
		fade_alpha += fade_rate;
		if (fade_alpha >= 255)
			fading_state = FADED_OUT;
	}
}

void Window::SetFadedIn() {
	fade_alpha = 0;
	fading_state = FADED_NONE;
}

void Window::SetFadedOut() {
	fade_alpha = 255;
	fading_state = FADED_OUT;
}

void Window::FadeOut(uint rate = 1 /*=1*/) {
	if (fading_state != FADING_OUT) {
		fade_rate = rate;
		fade_alpha = 0;
	} else {
		fade_rate = std::min(fade_rate, rate);
	}

	fading_state = FADING_OUT;
}

void Window::FadeIn(uint rate = 1 /*=1*/) {
	if (fading_state != FADING_IN) {
		fade_rate = rate;
		fade_alpha = 255;
	} else {
		fade_rate = std::min(fade_rate, rate);
	}

	fading_state = FADING_IN;
}

void Window::DrawRect(_Rect &r, ALLEGRO_COLOR col, bool filled, int alpha) {
	DrawRect(	(int)r.getx1(), (int)r.gety1(), 
				(int)r.getx2(), (int)r.gety2(), 
				col, filled, alpha);
}

// Draws a level-sized gradient
// The idea is that the gradient is the height of the LEVEL not the SCREEN
// So we have to figure out given the level height, screen height, and current
// position of the camera, what two colors we need to draw on a quad in order
// to make it look like there is one continuous gradient going up the level

// Usually the screen height is smaller than the level height
void Window::DrawBackgroundGradient(ALLEGRO_COLOR bottom_col, ALLEGRO_COLOR top_col, 
	int bottom_y, int top_y, int level_height) 
{	
	// get the color differences for computing the new colors
	float col_diff_r = top_col.r - bottom_col.r;
	float col_diff_g = top_col.g - bottom_col.g;
	float col_diff_b = top_col.b - bottom_col.b;

	// sanity check.
	if (top_y > level_height)
		top_y = level_height;
	else if (top_y < 0)
		top_y = 0;

	// sanity check.
	if (bottom_y > level_height)
		bottom_y = level_height;
	else if (bottom_y < 0)
		bottom_y = 0;

	float top_col_percent = float(top_y) / float(level_height);
	float bottom_col_percent = float(bottom_y) / float(level_height);

	// compute the final top color
	ALLEGRO_COLOR final_top_col = al_map_rgb_f(
									bottom_col.r + col_diff_r * top_col_percent,
									bottom_col.g + col_diff_g * top_col_percent,
									bottom_col.b + col_diff_b * top_col_percent
								);

	// compute the final bottom color
	ALLEGRO_COLOR final_bottom_col = al_map_rgb_f(
									bottom_col.r + col_diff_r * bottom_col_percent,
									bottom_col.g + col_diff_g * bottom_col_percent,
									bottom_col.b + col_diff_b * bottom_col_percent
								);

	// draw the quad with the two new colors
	DrawQuad(	0, 0, width, height,
						final_bottom_col, final_bottom_col, final_top_col, final_top_col,
						true, 255);
}

// Colors start at the bottom left and go counter-clockwise
// Color order: (bottom left, bottom right, top right, top left)
// TODO: prob convert alpha param to float
void Window::DrawQuad(	int x1, int y1, int x2, int y2, 
							ALLEGRO_COLOR col1, ALLEGRO_COLOR col2, ALLEGRO_COLOR col3, ALLEGRO_COLOR col4,
							bool filled, int alpha ) 
{
	glLoadIdentity();
	glDisable(GL_TEXTURE_2D);

	if (filled)
		glBegin(GL_QUADS); 
	else
		glBegin(GL_LINE_LOOP);

	float alpha_f = float(alpha / 255.0f);

	glColor4f(col1.r, col1.g, col1.b, alpha_f);
	glVertex2f(x1, y2);
	glColor4f(col2.r, col2.g, col2.b, alpha_f);
	glVertex2f(x2, y2);
	glColor4f(col3.r, col3.g, col3.b, alpha_f);
	glVertex2f(x2, y1);
	glColor4f(col4.r, col4.g, col4.b, alpha_f);
	glVertex2f(x1, y1);

	glEnd();

	glEnable(GL_TEXTURE_2D);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
}

void Window::DrawRect(	int x1, int y1, 
							int x2, int y2, 
							ALLEGRO_COLOR col, bool filled, int alpha)
{
	DrawQuad(x1, y1, x2, y2, col, col, col, col, filled, alpha);
}

// HACK HACK HACK - get this from somewhere!!
#define FONT_HEIGHT 14

// text object delimiters (see objectTxtOverlay.cpp)
#define OBJECT_TXT_LINE_DELIM "|"			// Which char goes to the next line

void Window::DrawText(int x, int y, std::string text) {
	vector<std::string> lines;
	StringSplit(text, OBJECT_TXT_LINE_DELIM, lines);
	int i, max = lines.size();

	int _x = x;
	int _y = y;
	ALLEGRO_COLOR col = al_map_rgba_f(1.0f,1.0f,1.0f,1.0f);

	glLoadIdentity();
	for (i = 0; i < max; i++) {

		// IMPORTANT NOTE: Only call this function AFTER drawing all the other opengl stuff.
		// otherwise you may see weird artifacts like messed up alpha blending on objects drawn after this
		al_draw_text(main_font, col, _x, _y, ALLEGRO_ALIGN_LEFT, lines[i].c_str());

		_y += FONT_HEIGHT;
	}
}

// public function
// NOTE: two things can tell the sprite to flip itself, either
// calling this function with flip_x/y true, or having the sprite
// set its flip_x/y flag to true.  We may have to flip it twice (e.g.
// NOT flip it at all) 
//
// Holy sweetness. Remember that '^' is XOR, and XOR rocks.
void Window::DrawSprite(Sprite* sprite, float x, float y, 
							bool flip_x, bool flip_y, 
							float rotate_angle,
							GLuint alpha, bool bDrawBoundingBoxOnly) 
{
	//if (alpha == 0)
	//	return;

	// texture coords
	// we mess with them if flipping
	float tx1 = 0.0f, ty1 = 0.0f;
	float tx2 = 0.0f, ty2 = 1.0f;
	float tx3 = 1.0f, ty3 = 1.0f;
	float tx4 = 1.0f, ty4 = 0.0f;

	float rx = x + sprite->x_offset;

	// clip if needed
	if (rx + sprite->width < 0 || rx > SCREEN_W)
		return;

	// flip x if needed
	if (sprite->flip_x ^ flip_x) {
		tx1 = tx2 = 1.0f;
		tx3 = tx4 = 0.0f;
	}

	float ry = y + sprite->y_offset;

	// clip if needed
	if (ry + sprite->height < 0 || ry > SCREEN_H)
		return;

	// flip y if needed
	if (sprite->flip_y ^ flip_y) {
		ty1 = ty4 = 1.0f;
		ty2 = ty3 = 0.0f;
	}

	// -----------------------------------------------

	if (!bDrawBoundingBoxOnly)
	{
		glBindTexture(GL_TEXTURE_2D, sprite->texture);
		glColor4ub(255,255,255,alpha);
	}
	else
	{
		glDisable(GL_TEXTURE_2D);
		glColor4ub(255,0,255,255);
	}

	glLoadIdentity();

	glTranslatef(rx, ry, 0.0f);

	glTranslatef(sprite->width/2.0f, sprite->height/2.0f, 0.0f);
	glRotatef(rotate_angle, 0.0f, 0.0f, 1.0f);
	glTranslatef(-sprite->width/2.0f, -sprite->height/2.0f, 0.0f);

	glScalef(sprite->width, sprite->height, 1.0f);

	if (!bDrawBoundingBoxOnly)
		glBegin(GL_QUADS); 
	else
		glBegin(GL_LINE_LOOP);

    glTexCoord2f(tx1, ty1);
		glVertex2f(0,1);

    glTexCoord2f(tx2, ty2);
		glVertex2f(0,0);

    glTexCoord2f(tx3, ty3);
		glVertex2f(1,0);

    glTexCoord2f(tx4, ty4);
		glVertex2f(1,1);

	glEnd();

	if (bDrawBoundingBoxOnly)
		glEnable(GL_TEXTURE_2D);
}

void Window::SetClearColor(float r, float g, float b) {
	glClearColor(r, g, b, 1.0f);
}

bool Window::Init( uint _width, uint _height, bool _fullscreen) 
{
	EASY_BLOCK("Create Window");

	fade_rate = 0;
	fade_alpha = 255;
	fading_state = FADED_NONE;

	width = _width;
	height = _height;

	al_set_new_display_flags(ALLEGRO_OPENGL);

	al_init_font_addon();
	al_init_ttf_addon();

	al_init_image_addon();
	
	display = al_create_display(width, height);
	if (!display) {
		TRACE("failed to create display!");
		return false;
	}
	
	SetTitle(VERSION_STRING);

	// TODO: Font stuff should go in asset manager
	string fontfile = ASSETMANAGER->GetPathOf("Vera.ttf");
	main_font = al_load_ttf_font(fontfile.c_str(), 12, 0);
	if (!main_font) {
		TRACE("failed to create main font (does the file exist?)");
		return false;
	}

	initialized = InitGL();

	// Draw the window once so it's black whilst everything else loads
	BeginDrawing();
	Clear();
	DrawText(10, 10, "Pirates VS Ninjas Loading ...");
	Flip();
	EndDrawing();

	return true;
}

void Window::SetTitle(const char* szTitle)
{
	al_set_window_title(WINDOW->GetDisplay(), szTitle);
}

bool Window::InitGL() {
	// apparently, all of this stuff never did _anything_

	/*glShadeModel(GL_FLAT);

	glViewport(0, 0, SCREEN_W, SCREEN_H);
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();
	
	glOrtho(0, SCREEN_W, 0, SCREEN_H, -10, 10);
	
	// flip the Y axis
	glScalef(1.0f, -1.0f, 1.0f);

	// move the origin to bottom left
	glTranslatef(0, -SCREEN_H, 0);
	glMatrixMode(GL_MODELVIEW);*/

	return true;
}

void Window::Clear() {
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
}

void Window::BeginDrawing() {
	glDisable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// not used for opengl, for stuff like text only.  not currently using.
	// al_set_blender(ALLEGRO_ADD, ALLEGRO_ALPHA, ALLEGRO_INVERSE_ALPHA); // default
	// al_set_blender(ALLEGRO_ADD, ALLEGRO_ONE, ALLEGRO_INVERSE_ALPHA);   // non-premultiplied alpha?
}

void Window::EndDrawing() {
	glDisable(GL_BLEND);
}

// draws the backbuffer to the screen and erases the backbuffer
void Window::Flip() {
	al_wait_for_vsync(); // i guess right thing to do? 2017
	al_flip_display();
}

void Window::Shutdown() {
	if (!initialized)
		return;

	al_destroy_display(display);

	initialized = false;
}

Window::Window() : initialized(false) {
}

Window::~Window() {}
