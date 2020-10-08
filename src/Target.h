#pragma once
#ifndef __TARGET__
#define __TARGET__

#include "DisplayObject.h"

class Target final : public DisplayObject {
public:
	Target();
	~Target();

	// Inherited via GameObject
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;

	
	glm::vec2 throwSpeed = { 0,0 };
	glm::vec2 throwPosition = {75.0f,400.0f};

	void doThrow();
	bool isColliding(GameObject*);
	float getDistance(GameObject*);

	bool isGravityEnabled = false;

	

private:
	void m_move();
	void m_checkBounds();
	void m_reset();
};


#endif /* defined (__TARGET__) */