#include "DXUT.h"
#include "Troop.h"

Troop::Troop(int enemyCount, float interval, float angle, Formation formation, D3DXVECTOR2 pos)
{
	this->enemyCount = enemyCount;
	this->formation = formation;
	this->interval = interval;
	this->createAngle = angle;
	angle_D = createAngle;

	enemys.resize(enemyCount);

	for (int i = 0; i < enemyCount; ++i)
		nowScene->obm.AddObject(enemys[i] = new Enemy(pos));
}

void Troop::Update(float deltaTime)
{
	D3DXVECTOR2 movePos = offset * 300 * deltaTime;
	pos += movePos;
	mDistance += D3DXVec2Length(&movePos);

	if (mDistance > 100)
	{
		//if (angle_D <= createAngle + 360)
			angle_D += 2;
	}

	offset = D3DXVECTOR2(cosf(D3DXToRadian(angle_D)), sinf(D3DXToRadian(angle_D)));

	enemys[0]->SetPos(pos);
	for (int i = 1; i < enemyCount; ++i)
		enemys[i]->SetPos(enemys[i - 1]->pos);
}

void Troop::Render()
{
}
