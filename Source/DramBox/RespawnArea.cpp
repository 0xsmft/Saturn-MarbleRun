#include "sppch.h"
#include "RespawnArea.h"

#include "Player.h"

RespawnArea::RespawnArea()
{
	AddComponent<BoxColliderComponent>();
	AddComponent<RigidbodyComponent>();
}

RespawnArea::~RespawnArea()
{
}

void RespawnArea::BeginPlay()
{
	Super::BeginPlay();
}

void RespawnArea::OnUpdate( Saturn::Timestep ts )
{
	Super::OnUpdate( ts );
}

void RespawnArea::OnPhysicsUpdate( Saturn::Timestep ts )
{
	Super::OnPhysicsUpdate( ts );
}

void RespawnArea::OnEntityHit( Entity* pOther, bool isTrigger )
{
	if( pOther )
	{
		if( pOther->GetClass() == Player::StaticClass() )
		{
			Player* pPlayer = dynamic_cast< Player* >( pOther );
			if( pPlayer )
			{
				pPlayer->RespawnAtCheckpoint();
			}
		}
	}
}
