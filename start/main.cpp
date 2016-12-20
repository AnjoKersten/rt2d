/**
 * Copyright 2016 Anjo Kersten <anjokersten@gmail.com>
 *
 * @brief Description of Friendly Fire.
 *
 * @file main.cpp
 *
 * @mainpage Friendly Fire
 *
 * @section intro Introduction
 *
 * Detailed description of Friendly Fire.
 */
#include <rt2d/core.h>

#include "myscene.h"

/// @brief main entry point
int main( void )
{
	// Core instance
	Core core;

	// Scene01
	MyScene* myscene = new MyScene(); // create Scene on the heap
	while(myscene->isRunning()) { // check status of Scene every frame
		core.run(myscene); // update and render the current scene
		core.showFrameRate(5); // show framerate in output every n seconds
	}
	//core.cleanup(); // cleanup ResourceManager (Textures + Meshes, but not Shaders)
	delete myscene; // delete Scene and everything in it from the heap to make space for next Scene

	// No need to explicitly clean up the core.
	// As a local var, core will go out of scope and destroy Renderer->ResourceManager.
	// ResourceManager destructor also deletes Shaders.

	return 0;
}
