
#ifndef MYSCENE_H
#define MYSCENE_H

#include <vector>

#include <rt2d/scene.h>
#include "myentity.h"
#include "player.h"
#include "background.h"
#include "bullet.h"

/// @file myscene.h

/// @brief The MyScene class is the Scene implementation.
class MyScene : public Scene
{
public:
	/// @brief Constructor
	MyScene();
	/// @brief Destructor
	virtual ~MyScene();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:

	/// @brief PlayerFireBullet spawns a bullet from player and moves it in player's direction
	/// @return void
	void PlayerFireBullet();
	/// @brief Player2FireBullet spawns a bullet from player2 and moves it in player2's direction
	/// @return void
	void Player2FireBullet();

	/// @brief t is a Timer
	Timer t;
	/// @brief groundLevel is the height of the floor
	int groundLevel;
	/// @brief player_offset is the distance (in pixels) from the center of player to the gun's barrel
	float player_offset;
	/// @brief player2_offset is the distance (in pixels) from the center of player2 to the gun's barrel
	float player2_offset;
	
	//Background* background_left;
	//Background* background_right;

	/// @brief background is the background of the world
	Background* background;

	/// @brief player is an Entity that can be controlled with a keyboard
	Player* player;
	/// @brief player2 is an Entity that can be controlled with a keyboard
	Player* player2;

	/// @brief playerBullets is a list of bullets from player
	std::vector<Bullet*> playerBullets;
	/// @brief playerBullets is a list of bullets from player2
	std::vector<Bullet*> player2Bullets;

	
};

#endif /* SCENE00_H */
