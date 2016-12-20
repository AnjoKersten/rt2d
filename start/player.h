
#ifndef PLAYER_H
#define PLAYER_H

#include <rt2d/entity.h>

/// @file player.h

/// @brief The Player class contains the implementation of a player
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

	/// @brief velocity is a Vector2
	Vector2 velocity;

private:

	/// @brief gravity is a force that is applied to the player
	int gravity;

};

#endif /* PLAYER_H */
