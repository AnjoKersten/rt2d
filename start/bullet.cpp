#include "bullet.h" 
 
Bullet::Bullet() : Entity()
{
	this->addSprite("assets/bullet.tga");
	this->scale = Point(0.4f, 0.4f);

	velocity = Vector2();
}
 
Bullet::~Bullet(){

}

void Bullet::update(float deltaTime) 
{
	this->position += velocity;
}