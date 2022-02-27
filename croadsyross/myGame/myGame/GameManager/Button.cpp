#include "Button.h"

Button::Button()
{
}

Button::Button(String name)
{
	buttonSprite.setTexture(*DATA->getTexture("button/button_" + name));
	buttonSize = Vector2f(buttonSprite.getLocalBounds().width, buttonSprite.getLocalBounds().height);
	buttonSprite.setOrigin(buttonSize.x / 2, buttonSize.y / 2);
	buttonSprite.setScale(0.6, 0.6);
}

void Button::setPosition(Vector2f pos)
{
	buttonSprite.setPosition(pos);
}
Button::~Button()
{
}

Vector2f Button::getSize()
{
	return buttonSize;
}

void Button::Click()
{
	buttonSprite.move(0, 10);
}
void Button::Release()
{
	buttonSprite.move(0, -10);
}
void Button::Draw(RenderWindow* window)
{
	window->draw(buttonSprite);
}

void Button::Smaller()
{
	buttonSprite.scale(0.8, 0.8);
}
void Button::setScale(float scale)
{
	buttonSprite.setScale(Vector2f(scale, scale));
}
void Button::Bigger()
{
	buttonSprite.scale(1.25, 1.25);
}
Vector2f Button::getPosition()
{
	return buttonSprite.getPosition();
}
