#include "Player.h"
#include "TextureManager.h"

Player::Player(): m_currentAnimationState(PLAYER_IDLE_RIGHT)
{
	TextureManager::Instance()->loadSpriteSheet(
		"../Assets/sprites/atlas.txt",
		"../Assets/sprites/sprites.png", 
		"sprite");



	setSpriteSheet(TextureManager::Instance()->getSpriteSheet("sprite"));
	
	// set frame width
	setWidth(56); 

	// set frame height
	setHeight(100); 

	getTransform()->position = glm::vec2(75.0f, 390.0f);
	getRigidBody()->velocity = glm::vec2(0.0f, 0.0f);
	getRigidBody()->acceleration = glm::vec2(0.0f, 0.0f);
	getRigidBody()->isColliding = false;
	setType(PLAYER);

	m_buildAnimations();
}

Player::~Player()
= default;

void Player::draw()
{
	// alias for x and y
	const auto x = getTransform()->position.x;
	const auto y = getTransform()->position.y;

	// draw the player according to animation state
	switch(m_currentAnimationState)
	{
	case PLAYER_IDLE_RIGHT:
		TextureManager::Instance()->playAnimation("sprite", getAnimation("idle"),
			x, y, 0.80f, 0, 255, true);
		break;
	case PLAYER_IDLE_LEFT:
		TextureManager::Instance()->playAnimation("sprite", getAnimation("idle"),
			x, y, 0.80f, 0, 255, true, SDL_FLIP_HORIZONTAL);
		break;
	case PLAYER_RUN_RIGHT:
		TextureManager::Instance()->playAnimation("spritesheet", getAnimation("run"),
			x, y, 0.25f, 0, 255, true);
		break;
	case PLAYER_RUN_LEFT:
		TextureManager::Instance()->playAnimation("spritesheet", getAnimation("run"),
			x, y, 0.25f, 0, 255, true, SDL_FLIP_HORIZONTAL);
		break;
	default:
		break;
	}
	
}

void Player::update()
{
}

void Player::clean()
{
}

void Player::setAnimationState(const PlayerAnimationState new_state)
{
	m_currentAnimationState = new_state;
}

void Player::m_buildAnimations()
{
	Animation idleAnimation = Animation();

	idleAnimation.name = "idle";
	idleAnimation.frames.push_back(getSpriteSheet()->getFrame("sprites-0"));
	idleAnimation.frames.push_back(getSpriteSheet()->getFrame("sprites-1"));
	idleAnimation.frames.push_back(getSpriteSheet()->getFrame("sprites-2"));
	idleAnimation.frames.push_back(getSpriteSheet()->getFrame("sprites-3"));
	idleAnimation.frames.push_back(getSpriteSheet()->getFrame("sprites-4"));
	idleAnimation.frames.push_back(getSpriteSheet()->getFrame("sprites-5"));
	idleAnimation.frames.push_back(getSpriteSheet()->getFrame("sprites-6"));
	idleAnimation.frames.push_back(getSpriteSheet()->getFrame("sprites-7"));
	idleAnimation.frames.push_back(getSpriteSheet()->getFrame("sprites-8"));
	idleAnimation.frames.push_back(getSpriteSheet()->getFrame("sprites-9"));
	idleAnimation.frames.push_back(getSpriteSheet()->getFrame("sprites-10"));
	setAnimation(idleAnimation);



	Animation runAnimation = Animation();

	runAnimation.name = "run";
	runAnimation.frames.push_back(getSpriteSheet()->getFrame("megaman-run-0"));
	runAnimation.frames.push_back(getSpriteSheet()->getFrame("megaman-run-1"));
	runAnimation.frames.push_back(getSpriteSheet()->getFrame("megaman-run-2"));
	runAnimation.frames.push_back(getSpriteSheet()->getFrame("megaman-run-3"));

	setAnimation(runAnimation);
}
