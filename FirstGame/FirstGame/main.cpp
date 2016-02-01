// Include OpenGL ES Engine utils
#include <es_util.h>
#include "GameApp.h"
#include "SplashScreenState.h"
#include "GameState.h"

float count = 0.0f;

using namespace yam2d;
namespace
{
	GameApp* m_app; 
}


// Initialize the game
bool init(ESContext *esContext)
{
	m_app = new GameApp();
	m_app->setState(new SplashScreenState(m_app));
	return true;
}


// Deinitialize the game
void deinit(ESContext *esContext)
{
	delete m_app;
}


// Draw game
void draw(ESContext *esContext)
{
	m_app->render(esContext);
	//splash->render(esContext);
}


// update game
void update(ESContext* ctx, float deltaTime)
{
	count += deltaTime;

	if (count > 1.0f)
		count = 0.0f;

	m_app->update(ctx, deltaTime);
	//if (false)
	//{
	//	esQuitApp(ctx);
	//}
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
