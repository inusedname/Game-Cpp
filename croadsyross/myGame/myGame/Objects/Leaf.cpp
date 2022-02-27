#include "Leaf.h"

Leaf::Leaf()
{
	leafSprite.setTexture(*DATA->getTexture("leaf"));
	leafSize = Vector2f(leafSprite.getLocalBounds().width, leafSprite.getLocalBounds().height);
	leafSprite.setOrigin(leafSize.x / 2, leafSize.y / 2);
}

Leaf::~Leaf()
{
}

Vector2f Leaf::getLeafSize()
{
	return leafSize;
}

Vector2f Leaf::getLeafPosition()
{
	return leafSprite.getPosition();
}

void Leaf::setLeafPosition(Vector2f x)
{
	leafSprite.setPosition(x);
}

void Leaf::Draw(RenderWindow* window)
{
	window->draw(leafSprite);
}
