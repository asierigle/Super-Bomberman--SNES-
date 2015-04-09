#include "Globals.h"
#include "Application.h"
#include "ModuleSceneSpace.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleSceneSpace::ModuleSceneSpace(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	background = NULL;
	stars = NULL;
}

ModuleSceneSpace::~ModuleSceneSpace()
{}

// Load assets
bool ModuleSceneSpace::Start()
{
	LOG("Loading space scene");
	
	background = App->textures->Load("rtype/background.png");

	App->player->Enable();
	App->audio->PlayMusic("rtype/stage1.ogg", 1.0f);
	
	return true;
}

// UnLoad assets
bool ModuleSceneSpace::CleanUp()
{
	LOG("Unloading space scene");

	App->textures->Unload(background);
	App->player->Disable();
	
	return true;
}

// Update: draw background
update_status ModuleSceneSpace::Update()
{
	// Move camera forward -----------------------------
	int scroll_speed = 1;

	App->player->position.x += 1;
	App->renderer->camera.x -= 3;
	

	// Draw everything --------------------------------------
	App->renderer->Blit(background, 0, 0, NULL);
	
	return UPDATE_CONTINUE;
}