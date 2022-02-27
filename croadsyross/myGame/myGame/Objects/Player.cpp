#include "Player.h"

Player::Player()
{
	playerSprite.setTexture(*DATA->getTexture("player"));
	playerSize.x = playerSprite.getLocalBounds().width;
	playerSize.y = playerSprite.getLocalBounds().height;
	playerSprite.setOrigin(playerSize.x / 2, 6 * playerSize.y / 5);
	playerSprite.setPosition(Vector2f(576, 640));

	playerHitbox.height = playerSize.y;
	playerHitbox.width = playerSize.x;
	playerHitbox.left = playerSprite.getPosition().x - (playerSize.x / 2);
	playerHitbox.top = playerSprite.getPosition().y - (6 * playerSize.y / 5);
	
	playerHitboxShow.setOutlineColor(Color::Red);
	playerHitboxShow.setOutlineThickness(2);
	playerHitboxShow.setFillColor(Color::Transparent);
	playerHitboxShow.setSize(playerSize);
	playerHitboxShow.setOrigin(playerSprite.getOrigin());
}

Player::~Player()
{
}

void Player::move(LR x)
{
	if (x == TOTHELEFT && playerSprite.getPosition().x > 64)
		playerSprite.move(Vector2f(-128, 0));
	if (x == TOTHERIGHT && playerSprite.getPosition().x < 1280 - 64)
		playerSprite.move(Vector2f(128, 0));
	playerHitbox.left = playerSprite.getPosition().x - (playerSize.x / 2);
	playerHitbox.top = playerSprite.getPosition().y - (6 * playerSize.y / 5);
}

void Player::DrawPlayer(RenderWindow* window)
{
	window->draw(playerSprite);
	window->draw(playerHitboxShow);
}

Rect<float> Player::getPlayerHitbox()
{
	return playerHitbox;
}
