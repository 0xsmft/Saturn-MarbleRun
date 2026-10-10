#include "sppch.h"
#include "TransitionTrigger.h"

TransitionTrigger::TransitionTrigger()
{
}

TransitionTrigger::~TransitionTrigger()
{
}

void TransitionTrigger::BeginPlay()
{
	Super::BeginPlay();
}

void TransitionTrigger::OnUpdate( Saturn::Timestep ts )
{
	Super::OnUpdate( ts );
}

void TransitionTrigger::OnPhysicsUpdate( Saturn::Timestep ts )
{
	Super::OnPhysicsUpdate( ts );
}

void TransitionTrigger::OnEntityHit( Entity* pOther, bool isTrigger )
{
}

