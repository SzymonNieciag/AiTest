// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterBase.h"
#include <GenericTeamAgentInterface.h>



ACharacterBase::ACharacterBase()
{

}

void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}
// Called every frame
void ACharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
