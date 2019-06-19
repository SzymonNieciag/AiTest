// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AIControllerBase.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class ETeamType :uint8
{
	Red = 0 UMETA(DisplayName = "RedTeam"),
	Blue = 1 UMETA(DisplayName = "BlueTeam"),
	Green = 2 UMETA(DisplayName = "GreenTeam"),
	Yellow = 3 UMETA(DisplayName = "YellowTeam"),
};

USTRUCT(BlueprintType)
struct FTeamProperties
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
		FName TeamName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
		ETeamType MyTeam;
	UPROPERTY(EditAnywhere, Category = "AI")
		TArray<ETeamType> FriendList;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
		TArray<ETeamType> EnemyList;
};

UCLASS()
class AITEST_API AAIControllerBase : public AAIController
{
	GENERATED_BODY()

public:

	AAIControllerBase();
	virtual void OnPossess(APawn* InPawn)override;

private:

	FGenericTeamId AITeamID;
	
	UPROPERTY(EditAnywhere,Category = "AI")
		TArray<ETeamType> FriendList;

	UPROPERTY(EditAnywhere, Category = "AI")
		FTeamProperties TeamProperties;

public:
	UFUNCTION(BlueprintCallable, Category = "AI")
		virtual void SetTeamProperties(const FTeamProperties& TeamProp);
	UFUNCTION()
		virtual void SetGenericTeamId(const FGenericTeamId& NewTeamID)override;

	/** Retrieve team identifier in form of FGenericTeamId */
	UFUNCTION(BlueprintCallable, Category = "AI")
		virtual FGenericTeamId GetGenericTeamId()const override;

	ETeamAttitude::Type GetTeamAttitudeTowards(const AActor & Other) const override;
};
