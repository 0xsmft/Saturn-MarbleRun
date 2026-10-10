#pragma once

#include "Saturn/Core/Timestep.h"
#include "Saturn/GameFramework/Core/GameScript.h"

#include "Saturn/Scene/Entity.h"

#include "SpinningObstacle.Gen.h"

using namespace Saturn;

SCLASS( VisibleInEditor )
class SpinningObstacle : public Entity
{
	GENERATED_BODY()
public:
	SpinningObstacle();
	virtual ~SpinningObstacle();


public:
	SPROPERTY()
	float RotationSpeed = 10.0f;

public:
	virtual void BeginPlay() override;
	virtual void OnUpdate( Saturn::Timestep ts ) override;
	virtual void OnPhysicsUpdate( Saturn::Timestep ts ) override;

private:
	float m_LastYRotation = 0.0f;
};
