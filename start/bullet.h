#ifndef BULLET_H
#define BULLET_H

#include <rt2d/entity.h>

/// @file bullet.h

/// @brief The Bullet class contains the implementation of a bullet
class Bullet : public Entity
{
public:
	/// @brief Constructor
	Bullet();
	/// @brief Deconstructor
	virtual ~Bullet();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	/// @brief velocity is the speed the bullet gets when it is spawned
	Vector2 velocity;


private:

};

#endif