#include "Target.h"
#include "TextureManager.h"

const int FPS = 60;
const float mpp = 5.0f; // 5 meter per pixel
const glm::vec2 gravity = glm::vec2(0.0f, 9.8f);

Target::Target()
{
	TextureManager::Instance()->load("../Assets/textures/Bomb.png","Bomb");

	const auto size = TextureManager::Instance()->getTextureSize("Bomb");
	setWidth(size.x);
	setHeight(size.y);
	
	getTransform()->position = glm::vec2(75.0f, 400.0f);
	getRigidBody()->velocity = glm::vec2(0, 0);
	getRigidBody()->isColliding = false;

	setType(TARGET);
}

Target::~Target()
= default;

void Target::draw()
{
	// alias for x and y
	const auto x = getTransform()->position.x;
	const auto y = getTransform()->position.y;

	// draw the target
	TextureManager::Instance()->draw("Bomb", x, y, 0, 255, true);
}

void Target::update()
{
	m_move();
	m_checkBounds();


}

void Target::clean()
{
}

void Target::m_move()
{
	float deltaTime = 1.0f / FPS;
	
	getRigidBody()->acceleration = gravity;
	
	
	if (!isGravityEnabled)
	{
		getRigidBody()->acceleration = glm::vec2(0, 0);
	}
	else
	{
		getRigidBody()->velocity += (getRigidBody()->acceleration) * deltaTime;
	}
	getTransform()->position += getRigidBody()->velocity * deltaTime * mpp;

}

void Target::m_checkBounds()
{
	int floor = 465;
	int wall = 800;

	if (getTransform()->position.y < 0)
	{
		getTransform()->position.y = 0;
	}

	if (getTransform()->position.y + 15 > floor)
	{
		getTransform()->position.y = floor - 15;
	}

	if (getTransform()->position.x < 0)
	{
		getTransform()->position.x = 0;
	}

	if (getTransform()->position.x + 15 > wall)
	{
		getTransform()->position.x = wall - 15;
	}
}


void Target::m_reset()
{
}

void Target::doThrow()
{
	getTransform()->position = throwPosition;
	getRigidBody()->velocity = throwSpeed;
}

bool Target::isColliding(GameObject* pOther) {
	// Works for square sprites only
	float myRadius = getWidth() * 0.5f;
	float otherRadius = pOther->getWidth() * 0.5f;

	return (getDistance(pOther) <= myRadius + otherRadius);
}

float Target::getDistance(GameObject* pOther) {
	glm::vec2 myPos = getTransform()->position;
	glm::vec2 otherPos = pOther->getTransform()->position;

	// Use pythagorean to calculate distance c = sqrt(a^2 + b^2)
	float a = myPos.x - otherPos.x;
	float b = myPos.y - otherPos.y;
	return sqrt(a * a + b * b);
}


