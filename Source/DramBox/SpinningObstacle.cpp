#include "sppch.h"
#include "SpinningObstacle.h"

#include "Saturn/Physics/PhysicsRigidBody.h"

SpinningObstacle::SpinningObstacle()
{
}

SpinningObstacle::~SpinningObstacle()
{
}

void SpinningObstacle::BeginPlay()
{
	Super::BeginPlay();

	if( auto* pRbComp = TryGetComponent<RigidbodyComponent>(); pRbComp )
	{
		m_pRigidBody = pRbComp->Rigidbody;
	}
}

void SpinningObstacle::OnUpdate( Saturn::Timestep ts )
{
	Super::OnUpdate( ts );
}

void SpinningObstacle::OnPhysicsUpdate( Saturn::Timestep ts )
{
	Super::OnPhysicsUpdate( ts );

	const auto localRotation = GetLocalRotation();

	const auto delta = m_LastYRotation - localRotation.y;
	const auto step = RotationSpeed * ts.Seconds();

	m_pRigidBody->Rotate( { localRotation.x, localRotation.y + step, localRotation.z } );
	SetRotation( { localRotation.x, localRotation.y + step, localRotation.z } );

	m_LastYRotation = localRotation.y;
}
