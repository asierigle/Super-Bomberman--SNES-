#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModulePlayer::ModulePlayer(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	graphics = NULL;
	current_animation = NULL;

	position.x = 150;
	position.y = 120;

	// idle animation (just the ship)
	idle.frames.PushBack({66, 1, 32, 14});

	// move upwards
	up.frames.PushBack({100, 1, 32, 14});
	up.frames.PushBack({132, 0, 32, 14});
	up.loop = false;
	up.speed = 0.1f;
	
	// Move down
	down.frames.PushBack({33, 1, 32, 14});
	down.frames.PushBack({0, 1, 32, 14});
	down.loop = false;
	down.speed = 0.1f;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");

	graphics = App->textures->Load("rtype/ship.png");

	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(graphics);

	return true;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	int speed = 1;

	if(App->input->keyboard[SDL_SCANCODE_A] == 1)
	{
		position.x -= speed;
	}

	if(App->input->keyboard[SDL_SCANCODE_D] == 1)
	{
		position.x += speed;
	}

	if(App->input->keyboard[SDL_SCANCODE_S] == 1)
	{
		position.y += speed;
		if(current_animation != &down)
		{
			down.Reset();
			current_animation = &down;
		}
	}

	if(App->input->keyboard[SDL_SCANCODE_W] == 1)
	{
		position.y -= speed;
		if(current_animation != &up)
		{
			up.Reset();
			current_animation = &up;
		}
	}

	if(App->input->keyboard_down[SDL_SCANCODE_SPACE] == 1)
	{
		App->particles->AddParticle(App->particles->laser, position.x + 28, position.y);
	}

	if(App->input->keyboard[SDL_SCANCODE_S] == 0 && App->input->keyboard[SDL_SCANCODE_W] == 0)
		current_animation = &idle;

	// Draw everything --------------------------------------

	App->renderer->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()));

	return UPDATE_CONTINUE;
}