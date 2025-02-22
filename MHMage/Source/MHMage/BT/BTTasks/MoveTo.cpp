// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveTo.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UMoveTo::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) 
{
	AAIController* AIController = OwnerComp.GetAIOwner();
	if (!AIController) return EBTNodeResult::Failed;

	return PerformMove(OwnerComp, NodeMemory);
}

EBTNodeResult::Type UMoveTo::PerformMove(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) 
{
	UBlackboardComponent* Blackboard = OwnerComp.GetBlackboardComponent();
	if (!Blackboard) return EBTNodeResult::Failed;

	FAIMoveRequest MoveRequest;
	const FName GoalLocationKey = FName(TEXT("GoalLocation"));
	
	MoveRequest.SetGoalLocation(Blackboard->GetValueAsVector(GoalLocationKey));
	return EBTNodeResult::Failed;
}

