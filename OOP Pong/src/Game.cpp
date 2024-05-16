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

}

void Game::initProps() {
	PG::GraphicsKit* graphicsKit = PG::GraphicsKit::CreateInstance();
	graphicsKit->CreateWindowIMP();
}

void Game::shutDownSystems() {
	
	m_isShutDown = true;
}

void Game::gameLoop() {
	m_isRunning = true;
	while (m_isRunning) {
		
	}
}

void Game::run() {
	this->initSystems();
	this->initProps();
	this->gameLoop();
	this->shutDownSystems();
}
