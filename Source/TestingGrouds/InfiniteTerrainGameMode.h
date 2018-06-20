// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TestingGroudsGameMode.h"
#include "InfiniteTerrainGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TESTINGGROUDS_API AInfiniteTerrainGameMode : public ATestingGroudsGameMode
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable, Category = "Bounds Pool")
		void PopulateBoundsVolumePool();
	

private:
	void AddToPool(class ANavMeshBoundsVolume *VolumeToAdd);

	
	
	
};
