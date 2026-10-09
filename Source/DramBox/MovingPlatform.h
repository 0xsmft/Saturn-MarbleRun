#pragma once

#include "Saturn/Core/Timestep.h"
#include "Saturn/GameFramework/Core/GameScript.h"

#include "Saturn/Scene/Entity.h"

#include "MovingPlatform.Gen.h"

using namespace Saturn;

SCLASS( VisibleInEditor )
class MovingPlatform : public Entity
{
	GENERATED_BODY()
public:
	MovingPlatform();
	virtual ~MovingPlatform();

	virtual void BeginPlay() override;
	virtual void OnUpdate( Saturn::Timestep ts ) override;
	virtual void OnPhysicsUpdate( Saturn::Timestep ts ) override;

public:
	// Travel distance in meters.
	SPROPERTY()
	float TravelDistance = 2.5f;

	// Time in seconds.
	SPROPERTY()
	float TravelSpeed = 2.0f;

	// Time in seconds.
	SPROPERTY()
	float ArrivalWaitTime = 5.0f;

private:
	float m_TargetZCoord = 0.0f;
	float m_StartingZCoord = 0.0f;
	float m_Time = 0.0f;
	float m_ArrivalWaitTimeCounter = 0.0f;
	bool m_Moving = false;
	bool m_StartedMoving = false;
};
