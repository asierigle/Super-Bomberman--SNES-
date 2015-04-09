#pragma once
#include "Module.h"
#include "Globals.h"

class ModuleInput : public Module
{
public:
	
	ModuleInput(Application* app, bool start_enabled = true);
	~ModuleInput();

	bool Init();
	update_status PreUpdate();
	bool CleanUp();

	const Uint8* keyboard;
	Uint8* keyboard_down;
	int mouse_x;
	int mouse_y;
};