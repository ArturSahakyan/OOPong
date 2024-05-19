#include "Game.h"

#include "Engine/Graphics/Platform/Windows/WinGraphicsKit.h"
#include "Engine/Graphics/GraphicsKit.h"

Game::Game()
	: m_isRunning(false), m_isShutDown(true)
{
}

Game::~Game() {
	// Catch All Shutdown
	if (m_isShutDown)
		return;

	// Wasn't ShutDown, So ShutDown Properly
	this->shutDownSystems();
}

void Game::initSystems() {
	if (!m_isShutDown)
		return;

	// Initialize Systems
	m_window = PG::RenderWindow();
}

void Game::initProps() {
	PG::WindowProps wd; // Window Descriptor
	wd.title = "Pong Game";
	wd.width = 1080;
	wd.height = 720;

	m_window.open(wd);
}

void Game::shutDownSystems() {
	
	m_isShutDown = true;
}

void Game::gameLoop() {
	m_isRunning = true;
	while (m_isRunning) {
		m_window.clear();



		m_window.update();
	}
}

void Game::run() {
	this->initSystems();
	this->initProps();
	this->gameLoop();
	this->shutDownSystems();
}
