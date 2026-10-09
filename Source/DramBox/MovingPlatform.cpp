#include "sppch.h"
#include "MovingPlatform.h"

MovingPlatform::MovingPlatform()
{
}

MovingPlatform::~MovingPlatform()
{
}

void MovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	m_StartingZCoord = GetLocalPosition().z;
	m_TargetZCoord = m_StartingZCoord + TravelDistance;
}

void MovingPlatform::OnUpdate( Saturn::Timestep ts )
{
	Super::OnUpdate( ts );

	// Determine if we should start to move or not.
	if( !m_Moving && ( m_ArrivalWaitTimeCounter += ts.Seconds() ) >= ArrivalWaitTime )
	{
		// Determine where we are
		m_StartedMoving = true;
		m_ArrivalWaitTimeCounter = 0.0f;
	}

	if( m_StartedMoving || m_Moving )
	{
		m_Moving = true;
		m_StartedMoving = false;

		const auto localPosition = GetLocalPosition();

		// if we are at the end we stop moving and reset timer.
		if( localPosition.z >= m_TargetZCoord )
		{
			m_Moving = m_StartedMoving = false;
			
			// Swap positions
			m_StartingZCoord = std::exchange( m_TargetZCoord, m_StartingZCoord );
		}

		const auto delta = m_TargetZCoord - localPosition.z;
		const auto step = TravelSpeed * ts.Seconds();

//		const float lerpedZ = glm::mix( localPosition.z, m_TargetZCoord, TravelSpeed * ts.Seconds() );
		const float newZ = localPosition.z + glm::sign( delta ) * glm::min( glm::abs( delta ), step );
		SetPosition( { localPosition.x, localPosition.y, newZ } );
	}
}

void MovingPlatform::OnPhysicsUpdate( Saturn::Timestep ts )
{
	Super::OnPhysicsUpdate( ts );
}
