#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <rt2d/entity.h>

/// @file background.h

/// @brief The Background class is an empty Entity with a Sprite
class Background : public Entity
{
public:
	/// @brief Constructor
	Background();
	/// @brief Deconstructor
	virtual ~Background();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:

};

#endif