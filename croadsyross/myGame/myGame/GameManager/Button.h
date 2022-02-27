#pragma once
#include "ResourceManager.h"

class Button
{
private:
	Sprite buttonSprite;
	Vector2f buttonSize;
public:
	Button();
	Button(String name);
	~Button();
	Vector2f getSize();
	void setPosition(Vector2f);
	void Click();
	void Release();
	void Draw(RenderWindow* window);
	void Smaller();
	void setScale(float scale);
	void Bigger();
	Vector2f getPosition();
};