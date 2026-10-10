#pragma once

#include "Saturn/Core/Timestep.h"
#include "Saturn/GameFramework/Core/GameScript.h"

#include "Saturn/Scene/Entity.h"

#include "TransitionTrigger.Gen.h"

using namespace Saturn;

SCLASS( VisibleInEditor )
class TransitionTrigger : public Entity
{
	GENERATED_BODY()
public:
	TransitionTrigger();
	virtual ~TransitionTrigger();

public:
	virtual void BeginPlay() override;
	virtual void OnUpdate( Saturn::Timestep ts ) override;
	virtual void OnPhysicsUpdate( Saturn::Timestep ts ) override;
	virtual void OnEntityHit( Entity* pOther, bool isTrigger ) override;

};
