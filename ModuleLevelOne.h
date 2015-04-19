#pragma once
#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct Collider;

class ModuleLevelOne : public Module
{
public:
	ModuleLevelOne(Application* app, bool start_enabled = true);
	~ModuleLevelOne();

	bool Start();
	int map[HEIGHT][WIDTH];
	update_status Update();
	bool CleanUp();

public:
	
	SDL_Texture* background;
	SDL_Texture* stars;
};