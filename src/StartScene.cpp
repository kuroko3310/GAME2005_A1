#include "StartScene.h"
#include <algorithm>
#include "Game.h"
#include "glm/gtx/string_cast.hpp"
#include "EventManager.h"

StartScene::StartScene()
{
	StartScene::start();
}

StartScene::~StartScene()
= default;

void StartScene::draw()
{
	drawDisplayList();
}

void StartScene::update()
{
	updateDisplayList();
}

void StartScene::clean()
{
	removeAllChildren();
}

void StartScene::handleEvents()
{
	EventManager::Instance().update();

	// Keyboard Events
	if(EventManager::Instance().isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->quit();
	}

	if(EventManager::Instance().isKeyDown(SDL_SCANCODE_1))
	{
		TheGame::Instance()->changeSceneState(PLAY_SCENE);
	}
}

void StartScene::start()
{
	// Color Constants
	const SDL_Color blue = { 0, 0, 255, 255 };
	const SDL_Color red = { 255, 0, 0, 255 };
	const SDL_Color black = { 0, 0, 0, 255 };

	m_pStartLabel = new Label("START SCENE", "Starjedi", 50, black, glm::vec2(400.0f, 40.0f));
	m_pStartLabel->setParent(this);
	addChild(m_pStartLabel);

	m_pInstructionsLabel = new Label("Press 1 to Play", "Consolas", 20, blue, glm::vec2(400.0f, 450.0f));
	m_pInstructionsLabel->setParent(this);
	addChild(m_pInstructionsLabel);


	m_pStudentName = new Label("Jen Marc Capistrano", "Consolas", 30, red, glm::vec2(400.0f, 120.0f));
	m_pStudentName->setParent(this);
	addChild(m_pStudentName);

	m_pStudentName = new Label("101218004", "Consolas", 20, red, glm::vec2(400.0f, 160.0f));
	m_pStudentName->setParent(this);
	addChild(m_pStudentName);

	m_pStudentName = new Label("Meghan Paris", "Consolas", 30, red, glm::vec2(400.0f, 200.0f));
	m_pStudentName->setParent(this);
	addChild(m_pStudentName);

	m_pStudentName = new Label("i dont know", "Consolas", 20, red, glm::vec2(400.0f, 240.0f));
	m_pStudentName->setParent(this);
	addChild(m_pStudentName);


	// Start Button
	m_pStartButton = new Button();
	m_pStartButton->getTransform()->position = glm::vec2(400.0f, 400.0f); 

	m_pStartButton->addEventListener(CLICK, [&]()-> void
	{
		m_pStartButton->setActive(false);
		TheGame::Instance()->changeSceneState(PLAY_SCENE);
	});
	
	m_pStartButton->addEventListener(MOUSE_OVER, [&]()->void
	{
		m_pStartButton->setAlpha(128);
	});

	m_pStartButton->addEventListener(MOUSE_OUT, [&]()->void
	{
		m_pStartButton->setAlpha(255);
	});
	addChild(m_pStartButton);

	
}

