#include <stdbool.h>
#include "raylib.h"
#include <stdlib.h>
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include "types.h"

#define MOUSE_SCALE_MARK_SIZE   12
#define MAX_BOX                 200

void draw_gui(int *rec_count)
{
        DrawLine(500, 0, 500, GetScreenHeight(), Fade(LIGHTGRAY, 0.6f));
        DrawRectangle(500,
		      0,
		      GetScreenWidth() - 500,
		      GetScreenHeight(),
		      Fade(LIGHTGRAY, 0.3f));
	if(GuiButton((Rectangle){600,155,62,20}, "create rec"))
		(*rec_count)++;
	//if(GuiButton((Rectangle){600,180,62,20}, "darkblue"))
}


void draw_rec(Rec_t *rec)
{
	DrawRectangleRec(rec->pos,rec->color);
}


bool check_collision(Rec_t rec, Mouse_t mouse)
{
	bool collision;
	collision = CheckCollisionPointRec(mouse.pos, rec.pos);
	return collision;
}

void highlight_box(Rec_t rec)
{
	DrawRectangleLinesEx(rec.pos, 3, RED);
	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
		DrawRectangleLinesEx(rec.pos, 3, BLUE);
}

int main(void)
{
	
	const int screenWidth = 800;
	const int screenHeight = 450;
	
	InitWindow(screenWidth, screenHeight, "simple gui");
		
	Mouse_t mouse;
	Rec_t *recs = (Rec_t *)malloc(MAX_BOX*sizeof(Rec_t));
	int rec_count = 0;
	
	SetTargetFPS(60);
	
	 while (!WindowShouldClose()) { 
		mouse.pos = GetMousePosition();
		
		DrawText(TextFormat("rec count: %d", rec_count), 120, 10, 20, GREEN);
		
		if (rec_count > -1){
			recs[rec_count].pos = (Rectangle) {100,100,200,80};
			if (rec_count == 0)
				recs[rec_count].color = DARKBLUE;
			else
				recs[rec_count].color = DARKBROWN;
		}

		for (int i = 0; i < rec_count; i++){
			check_collision(recs[i], mouse);
		}
		
		BeginDrawing();
		ClearBackground(RAYWHITE);
		
		draw_gui(&rec_count);
		for (int i = 0; i < rec_count; i++){
			draw_rec(&recs[i]);
			if (check_collision(recs[i], mouse)) 
				highlight_box(recs[i]);
			
		}
		
		EndDrawing();
	}
	 free(recs);
	 CloseWindow();
	 return 0;
}
