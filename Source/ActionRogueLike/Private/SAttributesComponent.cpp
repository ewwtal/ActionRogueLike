// Fill out your copyright notice in the Description page of Project Settings.


#include "SAttributesComponent.h"

// Sets default values for this component's properties
USAttributesComponent::USAttributesComponent()
{
	Health = 100.0f;
}

bool USAttributesComponent::IsAlive() const
{
	return Health > 0.0f;
}

bool USAttributesComponent::ApplyHealthChange(float Delta)
{
	Health += Delta;

	OnHealthChanged.Broadcast(nullptr, this, Health, Delta);

	return true;
}
