#include "sppch.h"
#include "Checkpoint.h"

#include "Saturn/Scene/Scene.h"

#include "GameState.h"
#include "Player.h"

Checkpoint::Checkpoint()
{
}

Checkpoint::~Checkpoint()
{
}

void Checkpoint::BeginPlay()
{
	Super::BeginPlay();

	const auto gameStateList = GetScene()->GetAllEntitiesWithClass<GameState>();
	SAT_CORE_ASSERT( !gameStateList.empty() );

	m_GameState = gameStateList[ 0 ];
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
	if( pOther->GetClass() == Player::StaticClass() )
	{
		if( auto gameState = m_GameState.Access() )
		{
			gameState->SetSpawningLocation( GetLocalPosition() );
		}
	}
}
