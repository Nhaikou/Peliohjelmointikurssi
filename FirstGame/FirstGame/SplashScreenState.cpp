#include "SplashScreenState.h"
#include "SpriteBatch.h"
#include "SpriteSheet.h"
#include "Texture.h"
namespace
{
	SpriteBatchGroup * batch = 0;
	Texture* openGLTexture = 0;
	Sprite* sprite = 0;
}

SplashScreenState::SplashScreenState()
{
	batch = new SpriteBatchGroup();

	openGLTexture = new Texture("meepo2_splash.png");

	sprite = new Sprite(0);

}


SplashScreenState::~SplashScreenState()
{

}

bool SplashScreenState::update(ESContext* ctx, float deltaTime)
{
	float count = 0.0f;
	batch->clear();
	batch->addSprite(openGLTexture, sprite, vec2(0, 0), count, vec2(1024, 576));

	return true;
}

void SplashScreenState::render(ESContext* esContext)
{
	// Set OpenGL clear color
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);

	// Clear the color buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Set the viewport to be full window area.
	glViewport(0, 0, esContext->width, esContext->height);

	// Set projection to identity
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Calculate half screen size
	float left = -0.5f*esContext->width;
	float right = 0.5f*esContext->width;
	float bottom = -0.5f*esContext->height;
	float top = 0.5f*esContext->height;

	// Set OpenGL orthogonal projection for screen size <esContext->width,esContext->height>
	glOrthof(float(int(left)), float(int(right)), float(int(bottom)), float(int(top)), -1.0, 1.0f);

	// Enable back face culling
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	// Enable depth test
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	// Enable alpha blending (transparency)
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// Set model view matrix to identity
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Draw batched objects to screen.
	batch->render();
}
