#include "DXUT.h"
#include "Bullet.h"

Bullet::Bullet(D3DXVECTOR2 pos, float angle, float speed)
{
	spr.LoadAll(L"a");
	spr.color = D3DCOLOR_ARGB(255, 125, 125, 0);
	ri.scale = { 0.3 ,0.3 };

	this->pos = pos;
	this->angle = D3DXToRadian(angle);
	this->speed = speed;
}

void Bullet::Update(float deltaTime)
{
	pos += D3DXVECTOR2(cosf(angle), sinf(angle)) * deltaTime * speed;
}

void Bullet::Render()
{
	ri.pos = pos;
	spr.Render(ri);
}
