#include "sppch.h"
#include "GameState.h"

GameState::GameState()
{
}

GameState::~GameState()
{
}

void GameState::BeginPlay()
{
	Super::BeginPlay();
}

void GameState::OnUpdate( Saturn::Timestep ts )
{
	Super::OnUpdate( ts );
}

void GameState::OnPhysicsUpdate( Saturn::Timestep ts )
{
	Super::OnPhysicsUpdate( ts );
}

