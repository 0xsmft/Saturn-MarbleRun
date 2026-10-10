#pragma once

#include "Saturn/Core/Timestep.h"
#include "Saturn/GameFramework/Core/GameScript.h"

#include "Saturn/Scene/Entity.h"

#include "Checkpoint.Gen.h"

using namespace Saturn;

SCLASS( VisibleInEditor )
class Checkpoint : public Entity
{
	GENERATED_BODY()
public:
	Checkpoint();
	virtual ~Checkpoint();

public:
	virtual void BeginPlay() override;
	virtual void OnUpdate( Saturn::Timestep ts ) override;
	virtual	void OnPhysicsUpdate( Saturn::Timestep ts ) override;
	virtual void OnEntityHit( Entity* pOther, bool isTrigger ) override;

};
