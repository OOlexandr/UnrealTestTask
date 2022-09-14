// This class describes spheres that will be spawned and destroyed
//

#pragma once

#include "Components/SphereComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DestructibleComponent.h"
#include "Target.generated.h"


UCLASS()
class UNREALTESTTASK_API ATarget : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATarget();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Destroyed();

	void Shatter();

private:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Sphere;

	//Will store destroyed target blueprint actor
	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> DestroyedTarget;

	//Will store projectile blueprint to ensure that target only gets destroyed on collision with projectiles
	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> Projectile;

	float SphereRadius;

	UFUNCTION()
	void OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
