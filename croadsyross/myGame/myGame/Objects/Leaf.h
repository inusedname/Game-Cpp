#pragma once
#include "../GameManager/ResourceManager.h"

class Leaf
{
private:
	Sprite leafSprite;
	Vector2f leafSize;
public:
	Leaf();
	~Leaf();
	Vector2f getLeafSize();
	Vector2f getLeafPosition();
	void setLeafPosition(Vector2f);
	void Draw(RenderWindow*);
};