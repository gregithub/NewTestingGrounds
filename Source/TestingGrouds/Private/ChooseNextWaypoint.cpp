// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWaypoint.h"
#include"BehaviorTree/BlackboardComponent.h"
#include"AIController.h"
#include"PatrollingGuard.h"	//TODO remove coupling


EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//TODO protect against empty patrol routes
	UE_LOG(LogTemp, Warning, TEXT("LOL"));
	//Get the patroled points. 
	auto AIController = OwnerComp.GetAIOwner();
	auto ControlledPawn = AIController->GetPawn();
	//TODO remove coupling
	auto PatrollingGuard = Cast<APatrollingGuard>(ControlledPawn);
	auto PatrollingPoints = PatrollingGuard->PatrolPointsCPP;

	//Set next waypoint
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrollingPoints[Index]);

	//Cycle the index
	auto NextIndex = (Index + 1) % PatrollingPoints.Num();
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);
	//UE_LOG(LogTemp, Warning, TEXT("waypoint index: %i "), Index);
	return EBTNodeResult::Succeeded;

}


