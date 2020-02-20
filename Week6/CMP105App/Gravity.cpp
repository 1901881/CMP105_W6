#include "Gravity.h"

Gravity::Gravity()
{
	scale = 200.0f;
	gravity = sf::Vector2f(0, 9.8f) * scale;
	jumpVector = sf::Vector2f(0, -4.0f) * scale;
	isJumping = false;
}

void Gravity::update(float dt)
{
	// Apply gravity force, increasing velocity
	//Move shape by new velocityt
	sf::Vector2f pos = stepVelocity * dt + 0.5f * gravity * dt * dt; //ut + 1/2at^2
	stepVelocity += gravity * dt; // v = u + at  note the += is not =
	setPosition(getPosition() + pos);
	//remember i flipped these lines

	//Check for collision with bottom of window
	if (getPosition().y >= 500) {
		setPosition(getPosition().x, 500);
		stepVelocity = sf::Vector2f(0, 0);
		isJumping = false;
	}
}

void Gravity::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Space)) {
		velocity = sf::Vector2f(0, -1.f) * scale;
		if (!isJumping) {
			stepVelocity = jumpVector;
			isJumping = true;
		}
	}

	
	if (input->isKeyDown(sf::Keyboard::D)) {
		setPosition(input->getMouseX(), input->getMouseY());
		
	}
	

}
