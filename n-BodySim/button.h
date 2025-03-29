#pragma once
#include <iostream>
#include "raylib.h"

class Button {
public:
	Vector2 pos;
	Vector2 size;
	std::string text;
	bool hasText;

	Button(Vector2 pos, Vector2 size, std::string text, bool hasText);

	bool buttonLogic(bool& isEnabled);

private:
	bool isOnTop = false;
	Color color = { 128,128,128,255 };
	int textSize = 15;
	int textSeparation = 4;
};
