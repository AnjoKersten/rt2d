
#ifndef MYSCENE_H
#define MYSCENE_H

#include <vector>

#include <rt2d/scene.h>
#include "myentity.h"
#include "player.h"
#include "background.h"
#include "bullet.h"

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

	void PlayerFireBullet();
	void Player2FireBullet();

	/// @brief t is a Timer
	Timer t;
	
	int groundLevel;

	float player_offset;
	float player2_offset;
	
	//Background* background_left;
	//Background* background_right;

	Background* background;

	Player* player;
	Player* player2;

	std::vector<Bullet*> playerBullets;
	std::vector<Bullet*> player2Bullets;

	
};

#endif /* SCENE00_H */
