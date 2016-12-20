#include "background.h" 
 
Background::Background() : Entity(){

	//this->addSprite("assets/background1.tga");

	this->addSprite("assets/background_test.tga", 0.5, 0.5, 0, 0);
 
}
 
Background::~Background(){

}

void Background::update(float deltaTime)
{
	
}