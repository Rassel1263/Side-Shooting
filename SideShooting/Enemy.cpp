#include "DXUT.h"
#include "Enemy.h"

Enemy::Enemy(D3DXVECTOR2 pos)
{
	spr.LoadAll(L"a");
	spr.color = D3DCOLOR_ARGB(255, 255, 0, 0);

	this->pos = pos;

}

void Enemy::Update(float deltaTime)
{
	pos = nextPos;
}

void Enemy::Render()
{
	ri.pos = pos;
	spr.Render(ri);
}

void Enemy::SetPos(D3DXVECTOR2 pos)
{
	this->nextPos = pos;
}
