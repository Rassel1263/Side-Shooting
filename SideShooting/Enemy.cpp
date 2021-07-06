#include "DXUT.h"
#include "Enemy.h"

Enemy::Enemy()
{
	spr.LoadAll(L"a");

	spr.color = D3DCOLOR_ARGB(255, 255, 0, 0);

	pos = { 0, -300 };
}

void Enemy::Update(float deltaTime)
{
}

void Enemy::Render()
{
	ri.pos = pos;
	spr.Render(ri);
}
