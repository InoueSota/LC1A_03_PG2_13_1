#include "Player.h"
#include <Novice.h>

void Player::Init(){
	transform_.x = 1280 / 2;
	transform_.y = 600;
	transform_.radius = 30;
	mSpeed = 8;
}
void Player::Update(char keys[], char preKeys[]) {

	if (keys[DIK_W]) {
		transform_.y -= mSpeed;
	}
	if (keys[DIK_S]) {
		transform_.y += mSpeed;
	}
	if (keys[DIK_A]) {
		transform_.x -= mSpeed;
	}
	if (keys[DIK_D]) {
		transform_.x += mSpeed;
	}

	//’e‚Ì”­ŽË
	for (int i = 0; i < 50; i++) {

		//ˆÚ“®ˆ—
		if (bullet[i].isShot_ == true)
		{
			bullet[i].Update();
		}

		//”­ŽËˆ—
		if (bullet[i].isShot_ == false && (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE]))
		{
			bullet[i].transform_.x = transform_.x;
			bullet[i].transform_.y = transform_.y;
			bullet[i].isShot_ = true;
			break;
		}
	}
}
void Player::Draw() {

	//’e•`‰æ
	for (int i = 0; i < 50; i++)
	{
		bullet[i].Draw();
	}

	Novice::DrawEllipse(transform_.x, transform_.y, transform_.radius, transform_.radius, 0.0f, GREEN, kFillModeSolid);
}