// Fill out your copyright notice in the Description page of Project Settings.

#include "InfiniteTerrainGameMode.h"
#include"AI/Navigation/NavMeshBoundsVolume.h"
#include"EngineUtils.h"
#include"ActorPool.h"


void AInfiniteTerrainGameMode::PopulateBoundsVolumePool() {
	auto VolumeIterator = TActorIterator<ANavMeshBoundsVolume>(GetWorld());
	while (VolumeIterator) {
		AddToPool(*VolumeIterator);
		
		++VolumeIterator;
	}
}

AInfiniteTerrainGameMode::AInfiniteTerrainGameMode() {
	NavMeshBoundsVolumePool = CreateDefaultSubobject<UActorPool>(FName("Nav Mesh Bounds Volume Pool"));
}
void AInfiniteTerrainGameMode::AddToPool(ANavMeshBoundsVolume *VolumeToAdd) {
	NavMeshBoundsVolumePool->Add(VolumeToAdd);
}
