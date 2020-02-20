#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	textureG.loadFromFile("gfx/Beach_Ball.png");
	ballG.setTexture(&textureG);
	ballG.setSize(sf::Vector2f(100, 100));
	ballG.setPosition(100, 100);
	ballG.setInput(input);
	ballG.setVelocity(50, 50);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	ballG.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	ballG.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(ballG);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}