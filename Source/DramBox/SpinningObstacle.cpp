#include "sppch.h"
#include "SpinningObstacle.h"

SpinningObstacle::SpinningObstacle()
{
}

SpinningObstacle::~SpinningObstacle()
{
}

void SpinningObstacle::BeginPlay()
{
	Super::BeginPlay();
}

void SpinningObstacle::OnUpdate( Saturn::Timestep ts )
{
	Super::OnUpdate( ts );

	const auto localRotation = GetLocalRotation();

	const auto delta = m_LastYRotation - localRotation.y;
	const auto step = RotationSpeed * ts.Seconds();

	SetRotation( { localRotation.x, localRotation.y + step, localRotation.z } );

	m_LastYRotation = localRotation.y;
}

void SpinningObstacle::OnPhysicsUpdate( Saturn::Timestep ts )
{
	Super::OnPhysicsUpdate( ts );
}
