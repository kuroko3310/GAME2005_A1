#include "Plane.h"
#include "TextureManager.h"

Plane::Plane()
{
	TextureManager::Instance()->loadSpriteSheet(
		"../Assets/sprites/atlas.txt",
		"../Assets/sprites/Enemy.png", 
		"Enemy");

	setSpriteSheet(TextureManager::Instance()->getSpriteSheet("Enemy"));

	
	// set frame width
	setWidth(75); 

	// set frame height
	setHeight(100); 

	getTransform()->position = glm::vec2(700.0f, 390.0f);
	getRigidBody()->velocity = glm::vec2(0.0f, 0.0f);
	getRigidBody()->acceleration = glm::vec2(0.0f, 0.0f);
	getRigidBody()->isColliding = false;
	setType(PLANE);

	m_buildAnimations();
}

Plane::~Plane()
= default;

void Plane::draw()
{
	// alias for x and y
	const auto x = getTransform()->position.x;
	const auto y = getTransform()->position.y;

	// draw the plane sprite with simple propeller animation
	TextureManager::Instance()->playAnimation(
		"Enemy", getAnimation("Enemy"),
		x, y, 0.80f, 0, 255, true, SDL_FLIP_HORIZONTAL);
}

void Plane::update()
{
}

void Plane::clean()
{
}

void Plane::m_buildAnimations()
{
	Animation planeAnimation = Animation();

	planeAnimation.name = "Enemy";
	planeAnimation.frames.push_back(getSpriteSheet()->getFrame("Enemy0"));
	planeAnimation.frames.push_back(getSpriteSheet()->getFrame("Enemy1"));
	planeAnimation.frames.push_back(getSpriteSheet()->getFrame("Enemy2"));
	planeAnimation.frames.push_back(getSpriteSheet()->getFrame("Enemy3"));
	planeAnimation.frames.push_back(getSpriteSheet()->getFrame("Enemy4"));
	planeAnimation.frames.push_back(getSpriteSheet()->getFrame("Enemy5"));
	planeAnimation.frames.push_back(getSpriteSheet()->getFrame("Enemy6"));
	planeAnimation.frames.push_back(getSpriteSheet()->getFrame("Enemy7"));
	planeAnimation.frames.push_back(getSpriteSheet()->getFrame("Enemy8"));
	planeAnimation.frames.push_back(getSpriteSheet()->getFrame("Enemy9"));
	planeAnimation.frames.push_back(getSpriteSheet()->getFrame("Enemy10"));

	setAnimation(planeAnimation);

}