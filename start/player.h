/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file player.h
 *
 * @brief description of MyEntity behavior.
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <rt2d/entity.h>

/// @brief The MyEntity class is the Entity implementation.
class Player : public Entity
{
public:
	/// @brief Constructor
	Player();
	/// @brief Destructor
	virtual ~Player();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	void Jump();

	Vector2 velocity;

private:
	Vector2 pos;
	Vector2 acceleration;
	int gravity;
};

#endif /* PLAYER_H */
