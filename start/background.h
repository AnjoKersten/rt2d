#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <rt2d/entity.h>

class Background : public Entity
{
public:
	Background();
	virtual ~Background();

	virtual void update(float deltaTime);

private:

};

#endif