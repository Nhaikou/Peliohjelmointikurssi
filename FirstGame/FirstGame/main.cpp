// Include OpenGL ES Engine utils
#include <es_util.h>
#include "GameApp.h"
#include "SplashScreenState.h"
#include "GameState.h"

float count = 0.0f;

using namespace yam2d;
namespace
{
	GameApp* game; 
	SplashScreenState* splash;
}


// Initialize the game
bool init(ESContext *esContext)
{
	game = new GameApp();
	splash = new SplashScreenState(game);
	game->setState(splash);
	return true;
}


// Deinitialize the game
void deinit(ESContext *esContext)
{
	delete game;
}


// Draw game
void draw(ESContext *esContext)
{
	game->render(esContext);
	//splash->render(esContext);
}


// update game
void update(ESContext* ctx, float deltaTime)
{
	game->update(ctx, deltaTime);
	if (false)
	{
		esQuitApp(ctx);
	}

	/*count += deltaTime;

	if (count > 1.0f)
		count = 0.0f;*/
}

//extern "C" void app_dummy();

int main(int argc, char *argv[])
{


	ESContext esContext;
	esInitContext(&esContext);
	esCreateWindow(&esContext, "FirstGame", 1280, 720, ES_WINDOW_DEFAULT);


	esRegisterInitFunc(&esContext, init);
	esRegisterDrawFunc(&esContext, draw);
	esRegisterUpdateFunc(&esContext, update);
	esRegisterDeinitFunc(&esContext, deinit);

	esMainLoop(&esContext);
	return 0;
}
