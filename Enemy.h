#pragma once
#include <Novice.h>


class Enemy
{
protected:
	int posX_;
	int posY_;
	int radius_;
	int speedX_;
	int speedY_;
public:
	static bool isAlive;
	Enemy() { isAlive = true; }
	~Enemy() { isAlive = false; }
	virtual void Update() {};
	virtual void Draw() {};

	inline int GetPosX() { return posX_; }
	inline int GetPosY() { return posY_; }
	inline int GetRadius() { return radius_; }
};

class EnemyA : public Enemy
{
public:
	EnemyA();

	void Update()override;
	void Draw()override;

};

class EnemyB : public Enemy
{
public:
	EnemyB();

	void Update()override;
	void Draw()override;
};