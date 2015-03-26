#pragma once
#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"

class ModulePlayer : public Module
{
public:
	ModulePlayer(Application* app);
	~ModulePlayer();

	bool Start();
	update_status Update();

public:

	SDL_Texture* graphics;
	Animation idle;
	Animation forward;
	Animation backward;
	p2Point<int> position;

};