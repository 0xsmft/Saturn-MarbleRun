#include "sppch.h"
#include "Checkpoint.h"

Checkpoint::Checkpoint()
{
}

Checkpoint::~Checkpoint()
{
}

void Checkpoint::BeginPlay()
{
	Super::BeginPlay();
}

void Checkpoint::OnUpdate( Saturn::Timestep ts )
{
	Super::OnUpdate( ts );
}

void Checkpoint::OnPhysicsUpdate( Saturn::Timestep ts )
{
	Super::OnPhysicsUpdate( ts );
}

void Checkpoint::OnEntityHit( Entity* pOther, bool isTrigger )
{
}

