#include "raylib.h"

int main(void)
{
	const int screenWidth = 800;
	const int screenHeight = 450;
	
	InitWindow(screenWidth, screenHeight, "simple rectangle");

	Rectangle rec = {100, 100, 200, 80};
	Color rec_color = RAYWHITE;
	Vector2 mouse_pos = {0};
	
	SetTargetFPS(60);

	while (!WindowShouldClose()) {
		mouse_pos = GetMousePosition();
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			rec.x = mouse_pos.x;
			rec.y = mouse_pos.y;
			rec_color = DARKBLUE;
		}
		
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawRectangle(rec.x - rec.width/2, rec.y - rec.height/2, rec.width, rec.height, rec_color);
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
