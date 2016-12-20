
#include <fstream>
#include <sstream>

#include "myscene.h"

MyScene::MyScene() : Scene()
{
	// start timer
	t.start();

	// set start value of these variables
	groundLevel = 632;
	player_offset = 55.0f;
	player2_offset = 55.0f;

	// ###############################################
	// CREATE BACKGROUND
	// ###############################################
	background = new Background();

	background->scale = Point(2.75, 3);
	background->position = Point2(688, 384);

	this->addChild(background);

	/*
	// create background_left and background_right
	background_left = new Background();
	background_right = new Background();
	
	// set position of background_left and background_right
	background_left->position = Point2(320,250);
	background_right->position = Point2(975, 250);

	// addChild() background_left and background_right
	this->addChild(background_left);
	this->addChild(background_right);
	*/

	// ###############################################
	// CREATE PLAYER 1
	// ###############################################

	// create an Entity called player and set a sprite
	player = new Player();
	player->addSprite("assets/player_test.tga", 0.5,0.5, 0, 0);

	// set player scale and position
	player->scale = Point(2.5f, 2.5f);
	player->position = Point2(SWIDTH / 2, 400);

	// addChild() player
	this->addChild(player);

	// ###############################################
	// CREATE PLAYER 2								   
	// ###############################################

	// create an Entity called player2 and set it's sprite
	player2 = new Player();
	player2->addSprite("assets/player2.tga", 0.5, 0.5, 0, 0);

	// set player2 scale and position
	player2->scale = Point(2.5f, 2.5f);
	player2->position = Point2((SWIDTH / 2) - 200, 400);

	// addChild() player2
	this->addChild(player2);
}


MyScene::~MyScene()
{
	// deconstruct and delete background
	

	// deconstruct player's
	this->removeChild(player);
	this->removeChild(player2);

	// delete player's
	delete player;
	delete player2;

	// deconstruct and delete bullet[i] for player's
	for (unsigned int i = 0; i < playerBullets.size(); i++) {
		this->removeChild(playerBullets[i]);
		delete playerBullets[i];
	}

	for (unsigned int i = 0; i < player2Bullets.size(); i++) {
		this->removeChild(player2Bullets[i]);
		delete player2Bullets[i];
	}
	// clear() bullet* vectors for player's
	playerBullets.clear();
	player2Bullets.clear();
}

void MyScene::update(float deltaTime)
{
	// apply simple gravity to player and player2
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
	// PLAYER 1 //
	// ###############################################################

	// UP Arrow key let's the player JUMP
	if (input()->getKey(GLFW_KEY_UP)) {
		if (player->position.y == groundLevel) {
			player->velocity = Vector2(0, -400);
		}
	}

	// LEFT Arrow key moves player to the LEFT
	if (input()->getKey(GLFW_KEY_LEFT)) {
		player->position -= Point2(250, 0) * deltaTime;
		if (player->scale.x > 0) {
			player->scale = Point(player->scale.x * -1, player->scale.y);
		}
	}

	// RIGHT Arrow key moves player to the RIGHT
	if (input()->getKey(GLFW_KEY_RIGHT)) {
		player->position += Point2(250, 0) * deltaTime;
		if (player->scale.x < 0) {
			player->scale = Point(2.5f, 2.5f);
		}
	}

	// RCTRL key shoots bullet from player
	if (input()->getKeyDown(GLFW_KEY_RIGHT_CONTROL)) {
		PlayerFireBullet();
	}

	// ###############################################################
	// PLAYER 2 //
	// ###############################################################

	// W key let's the player JUMP
	if (input()->getKey(GLFW_KEY_W)) {
		if (player2->position.y == groundLevel) {
			player2->velocity = Vector2(0, -400);
		}
	}

	// A key moves player to the LEFT
	if (input()->getKey(GLFW_KEY_A)) {
		player2->position -= Point2(250, 0) * deltaTime;
		if (player2->scale.x > 0) {
			player2->scale = Point(player2->scale.x * -1, player2->scale.y);
		}
	}

	// D key moves player to the RIGHT
	if (input()->getKey(GLFW_KEY_D)) {
		player2->position += Point2(250, 0) * deltaTime;
		if (player2->scale.x < 0) {
			player2->scale = Point(2.5f, 2.5f);
		}
	}

	// LALT key shoots bullet from player2
	if (input()->getKeyDown(GLFW_KEY_LEFT_ALT)) {
		Player2FireBullet();
	}


	// Escape key stops the Scene
	if (input()->getKeyUp(GLFW_KEY_ESCAPE)) {
		this->stop();
	}
}

void MyScene::PlayerFireBullet()
{
	// ########################################
	// SHOOT PLAYER BULLET
	// ########################################

	// create bullet
	Bullet* bullet = new Bullet();

	// if player is turned to the right: 
	// move bullet to the right
	if (player->scale.x > 0) {
		bullet->position = Point2(player->position.x + player_offset, player->position.y);
		bullet->velocity = Vector2(3, 0);
		bullet->scale = Point(bullet->scale.x * 1, bullet->scale.y * 1);
	}

	// if player is turned to the left: 
	// move bullet to the left
	else {
		bullet->position = Point2(player->position.x - player_offset, player->position.y);
		bullet->velocity = Vector2(-3, 0);
		bullet->scale = Point(bullet->scale.x * -1, bullet->scale.y * -1);
	}

	// addChild() bullet 
	this->addChild(bullet);

	// push the bullet in the back of player2Bullets
	playerBullets.push_back(bullet);
}



void MyScene::Player2FireBullet()
{
	// ########################################
	// SHOOT PLAYER2 BULLET
	// ########################################

	// create bullet
	Bullet* bullet = new Bullet();
	
	// if player2 is turned to the right: 
	// move bullet to the right
	if (player2->scale.x > 0) {
		bullet->position = Point2(player2->position.x + player2_offset, player2->position.y);
		bullet->velocity = Vector2(3, 0);
		bullet->scale = Point(bullet->scale.x * 1, bullet->scale.y * 1);
	}

	// if player2 is turned to the left: 
	// move bullet to the left
	else {
		bullet->position = Point2(player2->position.x - player2_offset, player2->position.y);
		bullet->velocity = Vector2(-3, 0);
		bullet->scale = Point(bullet->scale.x * -1, bullet->scale.y * -1);
	}

	// addChild() bullet 
	this->addChild(bullet);

	// push the bullet in the back of player2Bullets
	player2Bullets.push_back(bullet);
}
