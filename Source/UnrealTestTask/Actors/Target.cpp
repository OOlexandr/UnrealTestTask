#include "Target.h"
#include <typeinfo>
#include "Math/Vector.h"
#include "MyGameStateBase.h"

// Sets default values
ATarget::ATarget()
{
	PrimaryActorTick.bCanEverTick = true;

	Sphere = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SphereMesh"));
	Sphere->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	Sphere->SetNotifyRigidBodyCollision(true);

	Sphere->BodyInstance.SetCollisionProfileName("BlockAllDynamic");
	Sphere->OnComponentHit.AddDynamic(this, &ATarget::OnCompHit);

	RootComponent = Sphere;
}

// Called when the game starts or when spawned
void ATarget::BeginPlay()
{
	Super::BeginPlay();

	SphereRadius = GetWorld()->GetGameState<AMyGameStateBase>()->SphereRadius;
	Sphere->SetRelativeScale3D(FVector(SphereRadius / 50.0f));
}

// Called every frame
void ATarget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// On hit updates score and destroyes the target
void ATarget::OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if ((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL))
	{
		AMyGameStateBase* GameState = GetWorld()->GetGameState<AMyGameStateBase>();
		GameState->SpheresDestroyedNumber++;
		if (FVector::Dist(FVector(0, 0, 100), GetActorLocation()) < GameState->KillRadius)
		{
			GameState->SpheresDestroyedInKillZone++;
		}
		Destroy();
	}
}

// Spawns at actor location actor with destructible mesh, aka "destruction animation"
void ATarget::Destroyed()
{
	if (!GetWorld()->GetGameState<AMyGameStateBase>()->OnReset)
	{
		AActor* Debris = GetWorld()->SpawnActor<AActor>(DestroyedTarget, GetActorLocation(), GetActorRotation());
		Debris->SetActorScale3D(FVector(SphereRadius / 50.0f));
	}
}