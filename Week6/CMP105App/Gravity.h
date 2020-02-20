#pragma once
#include "Framework/GameObject.h"
#include "Framework/Input.h"
class Gravity : public GameObject
{
	private:

		float scale;
		bool isJumping;
		sf::Vector2f gravity;
		sf::Vector2f stepVelocity;
		sf::Vector2f jumpVector;

	public:

		Gravity();
		void update(float dt);
		void handleInput(float dt);
		//For future work make it so the ball hits the bottom of the screen
};

