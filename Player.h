#pragma once
#include "Transform.h"
#include "Bullet.h"

class Player
{
public:
	Player() {
		Init();
	}

	void Init();
	void Update(char keys[], char preKeys[]);
	void Draw();

	Transform transform_;
	int mSpeed;

	Bullet bullet[50];

};

