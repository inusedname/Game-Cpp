#pragma once
#include "../GameManager/ResourceManager.h"

enum LR {
	TOTHELEFT,
	TOTHERIGHT,
};
class Player
{
private:
	Sprite playerSprite;
	RectangleShape rectTMP;
	Rect<float> playerHitbox;
	RectangleShape playerHitboxShow;
	Vector2f playerSize;
public:
	Player();
	~Player();
	void move(LR);
	void DrawPlayer(RenderWindow*);
	Rect<float> getPlayerHitbox();
};