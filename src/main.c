#include <stdbool.h>
#include "raylib.h"
#include <stdlib.h>
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include "types.h"

#define MOUSE_SCALE_MARK_SIZE   12


void draw_gui(void)
{
        DrawLine(500, 0, 500, GetScreenHeight(), Fade(LIGHTGRAY, 0.6f));
        DrawRectangle(500,
		      0,
		      GetScreenWidth() - 500,
		      GetScreenHeight(),
		      Fade(LIGHTGRAY, 0.3f));
}


void draw_rec(Rec_t rec)
{
	rec.pos.x = 100;
	rec.pos.y = 100;
	rec.pos.width = 200;
	rec.pos.height = 80;
	rec.color = DARKBLUE;
	
	DrawRectangle(rec.pos.x - rec.pos.width/2,
		      rec.pos.y - rec.pos.height/2,
		      rec.pos.width, rec.pos.height,
		      rec.color);
}

bool rec_button(void)
{
	bool button_click;
	button_click = GuiButton((Rectangle){600,155,62,20}, "create rec");
	return button_click;
}


void chagnge_rec_width(Rec_t rec, Mouse_t mouse)
{
	
	if (CheckCollisionPointRec(mouse.pos, rec.pos) &&
            CheckCollisionPointRec(mouse.pos,
				   (Rectangle){ rec.pos.x + rec.pos.width - MOUSE_SCALE_MARK_SIZE,
						   rec.pos.y + rec.pos.height - MOUSE_SCALE_MARK_SIZE,
						   MOUSE_SCALE_MARK_SIZE,
						   MOUSE_SCALE_MARK_SIZE })){

		mouse.scale = true;
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			mouse.mode = true;
	}
	else
		mouse.scale = false;
	
	if (mouse.scale){
		mouse.scale = true;

		rec.pos.width = mouse.pos.x - rec.pos.x;
		rec.pos.height = mouse.pos.y - rec.pos.y;

		if (rec.pos.width < MOUSE_SCALE_MARK_SIZE)
			rec.pos.width = MOUSE_SCALE_MARK_SIZE;
		if (rec.pos.height < MOUSE_SCALE_MARK_SIZE)
			rec.pos.height = MOUSE_SCALE_MARK_SIZE;
		if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
			mouse.mode = false;
	}
	
}

int main(void)
{
	
	const int screenWidth = 800;
	const int screenHeight = 450;
	
	InitWindow(screenWidth, screenHeight, "simple gui");
		
	Rec_t rec;
	Mouse_t mouse;
	bool btn_press = false;
	bool btn_has_been_press;
	SetTargetFPS(60);

	while (!WindowShouldClose()) {
		mouse.pos = GetMousePosition();
		
		BeginDrawing();
		ClearBackground(RAYWHITE);
		
		draw_gui();
		btn_press = rec_button();
		if (btn_press)
			btn_has_been_press = true;
		if(btn_has_been_press)
			draw_rec(rec);
		
		if (mouse.scale){
			DrawRectangleLinesEx(rec.pos, 1, RED);
			
		}
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
