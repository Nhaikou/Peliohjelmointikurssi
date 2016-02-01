#include "SplashScreenState.h"

SplashScreenState::SplashScreenState(GameApp* app) : GameState(app), m_app(app)
{
	esLogMessage(__FUNCTION__);
	int cc = 0;
	esLogMessage("Init... %d", cc++);
	// Create new sprite batch group. This must be deleted at deinit.
	m_batch = new SpriteBatchGroup();

	esLogMessage("Init... %d", cc++);
	// Load OpenGL logo to be used as texture for sprite.
	m_texture = new Texture("meepo.png");

	esLogMessage("Init... %d", cc++);
	// Create new sprite, with default parameters.
	m_sprite = new Sprite(0);

	esLogMessage("Init... %d", cc++);
	// Load font texture. Made with font creation tool like bitmap font builder.
	m_fontTexture = new Texture("Fixedsys_24_Bold.png");

	esLogMessage("Init... %d", cc++);
	// Create font clip areas (sprite sheet), from dat file and texture. Dat-file is made with bitmap font builder.
	m_font = SpriteSheet::autoFindFontFromTexture(m_fontTexture, "Fixedsys_24_Bold.dat");

	esLogMessage("Init... %d", cc++);
	// Create new text-object
	m_text = new Text(0, m_font);

}


SplashScreenState::~SplashScreenState()
{
	
}

bool SplashScreenState::update(ESContext* ctx, float deltaTime)
{
	m_totalTime += deltaTime;
	m_count += deltaTime;

	// Set text.
	m_text->setText("Ain't NOTHING gonna stop US now!!");

	// Clear sprite before add new dynamic sprites.
	m_batch->clear();

	if (m_totalTime <= 3.0f)
	{
		// Add sprite. Rotate it according to total time. We need also scale font a bit (100 times, so the sprite is 100x100 pixels).
		m_batch->addSprite(m_texture, m_sprite, vec2(0, 0), 0, vec2(300 * m_count, 300 * m_count));
		// Add text to position
		m_batch->addText(m_fontTexture, m_text, vec2(-ctx->width / 50, ctx->height / 2.5), 0);
	}
	else
	{
		//MainMenuState* m_menu = new MainMenuState(getApp());
		getApp()->setState(new MainMenuState(getApp()));
		return true;
	}
	return true;
}

void SplashScreenState::render(ESContext* ctx)
{
	// Set OpenGL clear color
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// Clear the color buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Set the viewport to be full window area.
	glViewport(0, 0, ctx->width, ctx->height);

	// Set projection to identity
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Calculate half screen size
	float left = -0.5f*ctx->width;
	float right = 0.5f*ctx->width;
	float bottom = -0.5f*ctx->height;
	float top = 0.5f*ctx->height;

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
	m_batch->render();
}
