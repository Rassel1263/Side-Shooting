#include "DXUT.h"
#include "Bullet.h"

Bullet::Bullet(D3DXVECTOR2 pos, float angle)
{
	spr.LoadAll(L"a");
	spr.color = D3DCOLOR_ARGB(255, 125, 125, 0);
	ri.scale = { 0.3 ,0.3 };

	this->pos = pos;
	this->angle = D3DXToRadian(angle);

	target = static_cast<GameScene*>(nowScene)->enemy;
}

void Bullet::Update(float deltaTime)
{
	D3DXVECTOR2 dir = target->pos - pos;
	angle = atan2(dir.y, dir.x);

	pos += D3DXVECTOR2(cosf(angle), sinf(angle)) * deltaTime * 300;
}

void Bullet::Render()
{
	ri.pos = pos;
	spr.Render(ri);
}
