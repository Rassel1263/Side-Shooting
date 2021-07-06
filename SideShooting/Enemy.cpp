#include "DXUT.h"
#include "Enemy.h"

Enemy::Enemy(Object* target, D3DXVECTOR2 pos, D3DXVECTOR2 offset, EnemyManager::EnemyType type)
{
	this->target = target;
	this->offset = offset;
	this->dirAngle = -D3DXToRadian(30.0f);

	spr.LoadAll(L"a");
	spr.color = D3DCOLOR_ARGB(255, 255, 0, 0);

	this->pos = pos;
}

void Enemy::Update(float deltaTime)
{
	if (target == NULL)
	{
		pos -= D3DXVECTOR2(cosf(dirAngle), sinf(dirAngle)) * 300 * deltaTime;

		//if (GetAsyncKeyState('A'))
		//	pos.x -= 300 * deltaTime;

		//if (GetAsyncKeyState('W'))
		//	pos.y -= 300 * deltaTime;

		//if (GetAsyncKeyState('S'))
		//	pos.y += 300 * deltaTime;

		//if (GetAsyncKeyState('D'))
		//	pos.x += 300 * deltaTime;

	}
	else
	{
		D3DXVECTOR2 dir = target->pos - pos;
		float angle = atan2(dir.y, dir.x);
		
		pos -= D3DXVECTOR2(-cosf(angle), -sinf(angle)) * 300 * deltaTime;
	}

}

void Enemy::Render()
{
	ri.pos = pos;
	spr.Render(ri);
}
