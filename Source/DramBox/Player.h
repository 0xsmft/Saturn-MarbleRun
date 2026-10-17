#pragma once

#include "Saturn/Core/Timestep.h"
#include "Saturn/GameFramework/Core/GameScript.h"

#include "Saturn/GameFramework/Character.h"

#include "Player.Gen.h"

using namespace Saturn;

SCLASS( VisibleInEditor )
class Player : public Character
{
	GENERATED_BODY()
public:
	Player();
	virtual ~Player();

	virtual void BeginPlay() override;
	virtual void OnUpdate( Timestep ts ) override;
	virtual void OnPhysicsUpdate( Timestep ts ) override;

public:
	void OnJump();

public:
	void RespawnAtCheckpoint();

protected:
	virtual void SetupInputBindings() override;

};
