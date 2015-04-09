#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"

// Reference at https://youtu.be/6OlenbCC4WI?t=382

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	graphics = NULL;
	fx = 0;
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;
	graphics = App->textures->Load("rtype/intro.png");
	App->audio->PlayMusic("rtype/intro.ogg", 0.0f);
	fx = App->audio->LoadFx("rtype/starting.wav");

	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	App->textures->Unload(graphics);

	return true;
}

// Update: draw background
update_status ModuleSceneIntro::Update()
{
	// Draw everything --------------------------------------	
	App->renderer->Blit(graphics, 0, 0, NULL);

	if(App->input->keyboard_down[SDL_SCANCODE_SPACE] == 1)
	{
		App->fade->FadeToBlack(this, App->scene_space, 3.0f);
		App->audio->PlayFx(fx);
	}

	return UPDATE_CONTINUE;
}