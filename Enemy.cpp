#include "Enemy.h"



bool Enemy::isAlive;

EnemyA::EnemyA() {
	posX_ = 900;
	posY_ = 300;
	speedX_ = 8;
	speedY_ = 0;
	radius_ = 20;
}
void EnemyA::Update() {

	posX_ += speedX_;
	posY_ += speedY_;

	if (posX_ - radius_ <= 0 || posX_ + radius_ >= 1280) {
		speedX_ *= -1;
	}
	if (posY_ - radius_ <= 0 || posY_ + radius_ >= 720) {
		speedY_ *= -1;
	}

}
void EnemyA::Draw() {
	Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, RED, kFillModeSolid);
}



EnemyB::EnemyB() {
	posX_ = 600;
	posY_ = 500;
	speedX_ = 8;
	speedY_ = 0;
	radius_ = 20;
}
void EnemyB::Update() {

	posX_ += speedX_;
	posY_ += speedY_;

	if (posX_ - radius_ <= 0 || posX_ + radius_ >= 1280) {
		speedX_ *= -1;
	}
	if (posY_ - radius_ <= 0 || posY_ + radius_ >= 720) {
		speedY_ *= -1;
	}

}
void EnemyB::Draw() {
	Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, RED, kFillModeSolid);
}
