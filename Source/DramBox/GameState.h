#pragma once

#include "Saturn/Core/Timestep.h"
#include "Saturn/GameFramework/Core/GameScript.h"

#include "Saturn/Scene/Entity.h"

#include "GameState.Gen.h"

using namespace Saturn;

SCLASS( VisibleInEditor )
class GameState : public Entity
{
	GENERATED_BODY()
public:
	GameState();
	virtual ~GameState();

public:
	virtual void BeginPlay() override;
	virtual void OnUpdate( Saturn::Timestep ts ) override;
	virtual void OnPhysicsUpdate( Saturn::Timestep ts ) override;

public:
	void SetSpawningLocation( const glm::vec3& rLocation ) { m_PlayerSpawnLocation = rLocation; }

private:
	// Checkpoint location in which the player will spawn if they
	// fall off.
	glm::vec3 m_PlayerSpawnLocation{};
};
