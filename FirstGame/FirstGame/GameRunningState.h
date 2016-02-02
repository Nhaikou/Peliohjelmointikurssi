#pragma once
#include "GameState.h"
#include "MainMenuState.h"

class GameRunningState : public GameState
{
public:
	GameRunningState(GameApp* app);
	virtual~GameRunningState();

	virtual bool update(ESContext* ctx, float deltaTime);
	virtual void render(ESContext* ctx);

private:
	float m_totalTime = 0;
	float m_count = 0;
	Ref<Map> m_map;
	GameApp* m_app;
	Ref<Texture> m_texture = 0;
	Ref<Text> m_text = 0;
	Ref<Texture> m_fontTexture = 0;
	Ref<Sprite> m_sprite = 0;
	Ref<SpriteBatchGroup> m_batch = 0;
	Ref<SpriteSheet> m_font = 0;
};

