#include "Collision.h"

Collision::Collision()
{
}

Collision::~Collision()
{
}

bool Collision::simpleCollisionCheck(Rect<float> a, Rect<float> b)
{
	return a.intersects(b);
}