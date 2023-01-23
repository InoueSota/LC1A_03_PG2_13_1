#include "Bullet.h"
#include <Novice.h>



void Bullet::Init() {
	transform_.radius = 15;
	speed_ = 15;
	isShot_ = false;
}

void Bullet::Update() {

	//発射状態の場合
	if (isShot_ == true)
	{
		transform_.y -= speed_;

		//画面外に出た場合isShotフラグをオフにする
		if (transform_.y < 0 || 720 < transform_.y || transform_.x < 0 || 1280 < transform_.x)
		{
			isShot_ = false;
		}
	}

}

void Bullet::Draw() {

	if (isShot_ == true)
	{
		Novice::DrawEllipse(transform_.x, transform_.y, transform_.radius, transform_.radius, 0.0f, WHITE, kFillModeSolid);
	}

}
