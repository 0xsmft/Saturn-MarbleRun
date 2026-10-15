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

void Player::OnJump()
{
	Jump( 5.0f );
}

void Player::RespawnAtCheckpoint()
{
	if( const auto gameState = m_GameState.Access() )
	{
		SetPosition( gameState->GetCheckpointLocation() );
	}
}

void Player::SetupInputBindings()
{
	m_PlayerInputController->BindAction( "Forward", ActionBindingTriggerState::Pressed, SAT_BIND_EVENT_FN( Character::MoveForward ) );
	m_PlayerInputController->BindAction( "Forward", ActionBindingTriggerState::Released, SAT_BIND_EVENT_FN( Character::MoveForwardEnd ) );

	m_PlayerInputController->BindAction( "Backward", ActionBindingTriggerState::Pressed, SAT_BIND_EVENT_FN( Character::MoveBack ) );
	m_PlayerInputController->BindAction( "Backward", ActionBindingTriggerState::Released, SAT_BIND_EVENT_FN( Character::MoveForwardEnd ) );

	m_PlayerInputController->BindAction( "Left", ActionBindingTriggerState::Pressed, SAT_BIND_EVENT_FN( Character::MoveLeft ) );
	m_PlayerInputController->BindAction( "Left", ActionBindingTriggerState::Released, SAT_BIND_EVENT_FN( Character::MoveLeftEnd ) );

	m_PlayerInputController->BindAction( "Right", ActionBindingTriggerState::Pressed, SAT_BIND_EVENT_FN( Character::MoveRight ) );
	m_PlayerInputController->BindAction( "Right", ActionBindingTriggerState::Released, SAT_BIND_EVENT_FN( Character::MoveLeftEnd ) );

	m_PlayerInputController->BindAction( "ImpulseJump", ActionBindingTriggerState::Released, SAT_BIND_EVENT_FN( Player::OnJump ) );
}
