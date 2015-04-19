#include "Globals.h"
#include "Application.h"
#include "ModuleLevelOne.h"

ModuleLevelOne::ModuleLevelOne(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	background = NULL;
	stars = NULL;
}

ModuleLevelOne::~ModuleLevelOne()
{}

// Load assets
bool ModuleLevelOne::Start()
{
	LOG("Loading space scene");
	background = App->textures->Load("Resources/Level_Layout.png");

	App->collision->Enable(); // enable before player
	App->player->Enable();
	App->audio->PlayMusic("Resources/03_level1.ogg", 1.0f);

	App->renderer->camera.x = App->renderer->camera.y = 0;

	////////////////////////////////////////////////////////App->collision->AddCollider({0,224,3930, 16}, COLLIDER_WALL);
	///////////////////////////////////////////////////////////App->collision->AddCollider({1376, 16, 112, 80}, COLLIDER_WALL);
	////////////////////////////////////////////////////////App->collision->AddCollider({1376, 144, 112, 80 }, COLLIDER_WALL);

	return true;
}

int map[HEIGHT][WIDTH] = {
	000000000000000,
	011111151611110,
	026265626166620,
	025212121511120,
	026565626666620,
	061515121515550,
	026262626262650,
	025566551212520,
	056265626265620,
	021512521512120,
	056265626565620,
	021265125212120,
	000000000000000};

// UnLoad assets
bool ModuleLevelOne::CleanUp()
{
	LOG("Unloading space scene");

	App->textures->Unload(background);
	App->player->Disable();
	App->collision->Disable();
	
	return true;
}

// Update: draw background
update_status ModuleLevelOne::Update()
{
	// Draw everything --------------------------------------

	int fil, col;

	App->renderer->Blit(background, 0, 0, NULL);
	
	/*for (fil = 0; fil<HEIGHT; fil++)
	{
		for (col = 0; col<WIDTH; col++)
		{
			if (map[fil][col] == 1){ App->renderer->Blit(background, 0, 0, NULL); }
			if (map[fil][col] == 2){ App->renderer->Blit(background, 0, 0, NULL); }
			if (map[fil][col] == 5){ App->renderer->Blit(background, 0, 0, NULL); }
			if (map[fil][col] == 6){ App->renderer->Blit(background, 0, 0, NULL); }
		}
	}*/
	
	
	return UPDATE_CONTINUE;
}