#pragma once
#include "ResourceManager.h"
class Collision {

public: 
	Collision();
	~Collision();
	bool simpleCollisionCheck(Rect<float>, Rect<float>);
};