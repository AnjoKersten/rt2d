
#include "player.h"

Player::Player() : Entity()
{

	velocity = Vector2();
	gravity = 1000;
	
}

Player::~Player()
{
	
}

void Player::update(float deltaTime)
{
	// Add Gravity to Player
	position += velocity * deltaTime;
	velocity.y += gravity * deltaTime;
}