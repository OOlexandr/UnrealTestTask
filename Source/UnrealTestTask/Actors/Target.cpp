// Fill out your copyright notice in the Description page of Project Settings.


#include "Target.h"

// Sets default values
ATarget::ATarget()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MyComp = CreateDefaultSubobject<USphereComponent>(TEXT("HitSphere"));
	MyComp->SetNotifyRigidBodyCollision(true);

	MyComp->BodyInstance.SetCollisionProfileName("BlockAllDynamic");
	MyComp->OnComponentHit.AddDynamic(this, &ATarget::OnCompHit);

	MyComp->InitSphereRadius(50);

	RootComponent = MyComp;

	Sphere = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SphereMesh"));
	Sphere->AttachTo(RootComponent);
	Sphere->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	Sphere->SetNotifyRigidBodyCollision(true);

	Sphere->BodyInstance.SetCollisionProfileName("BlockAllDynamic");
	Sphere->OnComponentHit.AddDynamic(this, &ATarget::OnCompHit);
}

// Called when the game starts or when spawned
void ATarget::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATarget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATarget::OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if ((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL))
	{
		Destroy();
	}
}

void ATarget::Destroyed()
{
	GetWorld()->SpawnActor<AActor>(DestroyedTarget, GetActorLocation(), GetActorRotation());
}