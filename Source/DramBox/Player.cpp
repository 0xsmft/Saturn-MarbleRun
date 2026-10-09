#include "sppch.h"
#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::BeginPlay()
{
	Super::BeginPlay();
}

void Player::OnUpdate( Timestep ts )
{
	Super::OnUpdate( ts );
}

void Player::OnPhysicsUpdate( Timestep ts )
{
	Super::OnPhysicsUpdate( ts );
}

void Player::SetupInputBindings()
{
}
