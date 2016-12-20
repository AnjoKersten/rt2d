#ifndef BULLET_H
#define BULLET_H

#include <rt2d/entity.h>

class Bullet : public Entity
{
public:
	Bullet();
	virtual ~Bullet();

	virtual void update(float deltaTime);

	Vector2 velocity;


private:

};

#endif