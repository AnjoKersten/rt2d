
#include <fstream>
#include <sstream>

#include "myscene.h"

MyScene::MyScene() : Scene()
{
	// start the timer.
	t.start();

	groundLevel = 600;

	// create a single instance of Player in the middle of the screen.
	// scale the Player's instance 5 times.
	player = new Player();
	player->addSprite("assets/player.tga");
	player->scale = Point(5.0f, 5.0f);
	player->position = Point2(SWIDTH / 2, 400);
	// addChild the instace named player
	this->addChild(player);

	// create a single instance of Player in the middle of the screen.
	// scale the Player's instance 5 times.
	player2 = new Player();
	player2->addSprite("assets/player2.tga");
	player2->scale = Point(5.0f, 5.0f);
	player2->position = Point2((SWIDTH / 2) - 200, 400);
	// addChild the instace named player
	this->addChild(player2);
}


MyScene::~MyScene()
{
	// deconstruct and delete the Players
	this->removeChild(player);
	this->removeChild(player2);
	// delete the player2 from the heap
	delete player;
	delete player2;
}

void MyScene::update(float deltaTime)
{
	// Ground Level
	if (player->position.y > groundLevel)
	{
		player->velocity.y = 0;
		player->position = Point2(player->position.x, groundLevel);
	}
	if (player2->position.y > groundLevel)
	{
		player2->velocity.y = 0;
		player2->position = Point2(player2->position.x, groundLevel);
	}


	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(GLFW_KEY_ESCAPE)) {
		this->stop();
	}

	// PLAYER 1 //
	// ###############################################################
	// Right Arrow key moves player to the RIGHT
	// ###############################################################
	if (input()->getKey(GLFW_KEY_D)) {
		player2->position += Point2(250, 0) * deltaTime;
	}

	// ###############################################################
	// Left Arrow key moves player to the LEFT
	// ###############################################################
	if (input()->getKey(GLFW_KEY_A)) {
		player2->position -= Point2(250, 0) * deltaTime;
	}

	

	// ###############################################################
	// W key let's the player JUMP
	// ###############################################################
	if (input()->getKey(GLFW_KEY_W)) {
		if (player2->position.y == groundLevel) {
			
			player2->velocity = Vector2(0, -400);
		}
	}
	
	// PLAYER 2 //
	// ###############################################################
	// Right Arrow key moves player to the RIGHT
	// ###############################################################
	if (input()->getKey(GLFW_KEY_RIGHT)) {
		player->position += Point2(250,0) * deltaTime;
	}
	
	// ###############################################################
	// Left Arrow key moves player to the LEFT
	// ###############################################################
	if (input()->getKey(GLFW_KEY_LEFT)) {
		player->position -= Point2(250, 0) * deltaTime;
	}

	// ###############################################################
	// Up Arrow key let's the player JUMP
	// ###############################################################
	if (input()->getKey(GLFW_KEY_UP)) {
		if (player->position.y == groundLevel) {

			player->velocity = Vector2(0, -400);
		}
	}

	
	
	









	/*
	// ###############################################################
	// Spacebar scales myentity
	// ###############################################################
	if (input()->getKeyDown( GLFW_KEY_SPACE )) {
		myentity->scale = Point(0.5f, 0.5f);
	}
	if (input()->getKeyUp( GLFW_KEY_SPACE )) {
		myentity->scale = Point(1.0f, 1.0f);
	}

	// ###############################################################
	// Rotate color
	// ###############################################################
	if (t.seconds() > 0.0333f) {
		RGBAColor color = myentity->sprite()->color;
		myentity->sprite()->color = Color::rotate(color, 0.01f);
		t.start();
	}
	*/
}
