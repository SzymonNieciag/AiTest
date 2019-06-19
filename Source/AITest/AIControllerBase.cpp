// Fill out your copyright notice in the Description page of Project Settings.


#include "AIControllerBase.h"
#include <Perception/AISenseConfig_Sight.h>
#include <Perception/AIPerceptionComponent.h>

AAIControllerBase::AAIControllerBase()
{
	TeamProperties.TeamName = "BOT";
}

void AAIControllerBase::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
}

void AAIControllerBase::SetTeamProperties(const FTeamProperties& TeamProp)
{
	TeamProperties = TeamProp; 
	FGenericTeamId NewTeamID = (uint8)TeamProp.MyTeam;

	SetGenericTeamId(NewTeamID);
}

void AAIControllerBase::SetGenericTeamId(const FGenericTeamId& NewTeamID)
{
	AITeamID = NewTeamID;
}

FGenericTeamId AAIControllerBase::GetGenericTeamId() const
{
	return AITeamID;
}

ETeamAttitude::Type AAIControllerBase::GetTeamAttitudeTowards(const AActor & Other) const
{
	if (const APawn* OtherPawn = Cast<APawn>(&Other)) {

		if (const IGenericTeamAgentInterface* TeamAgent = Cast<IGenericTeamAgentInterface>(OtherPawn->GetController()))
		{
			FGenericTeamId OtherTeamID = TeamAgent->GetGenericTeamId();

			if (OtherTeamID == AITeamID)
			{

				//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("team %s"), *OtherPawn->GetName()));
				return ETeamAttitude::Friendly;
			}
			for (ETeamType Team : TeamProperties.EnemyList)
			{

				if (OtherTeamID == (uint8)Team)
				{
					return ETeamAttitude::Hostile;
				}
			}
			for (ETeamType Team : TeamProperties.FriendList)
			{
				if (OtherTeamID == (uint8)Team)
				{
					return ETeamAttitude::Friendly;
				}
			}
			return ETeamAttitude::Neutral;
		}
		return ETeamAttitude::Neutral;
	}
	return ETeamAttitude::Neutral;
}

