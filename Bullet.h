#pragma once
#include "Transform.h"

class Bullet
{
public:
	Bullet() {
		Init();
	}

	Transform transform_;
	int speed_;
	bool isShot_;

	void Init();
	void Update();
	void Draw();

};

