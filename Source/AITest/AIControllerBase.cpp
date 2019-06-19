// Fill out your copyright notice in the Description page of Project Settings.


#include "AIControllerBase.h"
#include <Perception/AIPerceptionComponent.h>

AAIControllerBase::AAIControllerBase()
{
	TeamProperties.TeamName = "BOT";
}

void AAIControllerBase::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
}

void AAIControllerBase::SetTeamProperties(const FTeamProperties TeamProp)
{
	TeamProperties = TeamProp;
	
}

FTeamProperties AAIControllerBase::GetTeamProperties() const
{
	return TeamProperties;
}

ETeamAttitude::Type AAIControllerBase::GetTeamAttitudeTowards(const AActor & Other) const
{
	if (const APawn* OtherPawn = Cast<APawn>(&Other)) {

		if (const AAIControllerBase* BaseController = Cast<AAIControllerBase>(OtherPawn->GetController()))
		{
			FTeamProperties OtherTeamProperties = BaseController->GetTeamProperties();


			if (OtherTeamProperties.AITeamID == TeamProperties.AITeamID)
			{
				return ETeamAttitude::Friendly;
			}
			for (int32 Team : TeamProperties.EnemyListID)
			{
				if (Team == OtherTeamProperties.AITeamID)
				{
					return ETeamAttitude::Hostile;
				}
			}
			for (int32 Team : TeamProperties.FriendListID)
			{
				if (Team == OtherTeamProperties.AITeamID)
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

