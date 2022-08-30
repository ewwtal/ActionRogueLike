// Fill out your copyright notice in the Description page of Project Settings.


#include "SAttributesComponent.h"
#include "Windows/LiveCoding/Private/External/LC_CommandMap.h"

// Sets default values for this component's properties
USAttributesComponent::USAttributesComponent()
{
	HealthMax = 100.0f;
	Health = HealthMax;
}

bool USAttributesComponent::IsAlive() const
{
	return Health > 0.0f;
}

bool USAttributesComponent::IsFullHealth() const
{
	return Health == HealthMax;
}

float USAttributesComponent::GetHealthMax() const
{
	return HealthMax;
}

bool USAttributesComponent::ApplyHealthChange(float Delta)
{
	const float OldHealth = Health;
	
	Health = FMath::Clamp(Health + Delta, 0.0f, HealthMax);

	float ActualDelta = Health - OldHealth;
	OnHealthChanged.Broadcast(nullptr, this, Health, ActualDelta);

	return ActualDelta != 0;
}
