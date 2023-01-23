#include <Novice.h>
#include "Player.h"
#include "Enemy.h"
#include "Collision.h"



const char kWindowTitle[] = "LC1A_03_";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Player* player = new Player();
	Enemy* enemyA = new EnemyA();
	Enemy* enemyB = new EnemyB();

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		if (keys[DIK_R] && !Enemy::isAlive) {
			Enemy::isAlive = true;
		}

		player->Update(keys, preKeys);

		if (Enemy::isAlive) {

			enemyA->Update();
			enemyB->Update();

			for (int i = 0; i < 50; i++) {
				if (Collision(player->bullet[i].transform_.x, player->bullet[i].transform_.y, player->bullet[i].transform_.radius, enemyA->GetPosX(), enemyA->GetPosY(), enemyA->GetRadius())) {
					Enemy::isAlive = false;
				}
				if (Collision(player->bullet[i].transform_.x, player->bullet[i].transform_.y, player->bullet[i].transform_.radius, enemyB->GetPosX(), enemyB->GetPosY(), enemyB->GetRadius())) {
					Enemy::isAlive = false;
				}
			}
		}




		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		//操作方法等描画
		Novice::ScreenPrintf(0, 0, "enemyA isAlive = %d", enemyA->isAlive);
		Novice::ScreenPrintf(0, 20, "enemyB isAlive = %d", enemyB->isAlive);
		Novice::ScreenPrintf(0, 40, "WASD : player Move");
		Novice::ScreenPrintf(0, 60, "shot : SPACE");
		Novice::ScreenPrintf(0, 80, "enemy respawn : R");

		player->Draw();
		if (Enemy::isAlive) {
			enemyA->Draw();
			enemyB->Draw();
		}


		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	delete enemyA;
	delete enemyB;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
