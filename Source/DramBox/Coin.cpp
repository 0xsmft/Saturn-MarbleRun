#include "sppch.h"
#include "Coin.h"

Coin::Coin()
{
}

Coin::~Coin()
{
}

void Coin::BeginPlay()
{
	Super::BeginPlay();
}

void Coin::OnUpdate( Saturn::Timestep ts )
{
	Super::OnUpdate( ts );
}

void Coin::OnPhysicsUpdate( Saturn::Timestep ts )
{
	Super::OnPhysicsUpdate( ts );
}

void Coin::OnEntityHit( Entity* pOther, bool isTrigger )
{
}
