#include "DXUT.h"
#include "ObjectTest.h"

ObjectTest::ObjectTest()
{
	spr.LoadAll(L"Assets/Sprites/aa.png");

	Collider2D::Circle circle;
	circle.radius = 100;
	bodies.push_back(Collider2D(this, L"aa", 0, &circle));

	layer = 100;

	simpleShader = new SimpleShader;
	
}

void ObjectTest::Update(float deltaTime)
{
	timer += deltaTime;

	if (timer >= 2.0f)
		timer -= 3.0f;

 	Shot(deltaTime);

	if (Input::GetInstance().KeyDown('R'))
		(shotType == ShotType::Direct) ? shotType = ShotType::Radiation : shotType = ShotType::Direct;

	if (GetAsyncKeyState(VK_LEFT))
		pos.x -= 300 * deltaTime;

	if (GetAsyncKeyState(VK_UP))
		pos.y -= 300 * deltaTime;

	if (GetAsyncKeyState(VK_DOWN))
		pos.y += 300 * deltaTime;

	if (GetAsyncKeyState(VK_RIGHT))
		pos.x += 300 * deltaTime;

}

void ObjectTest::Render()
{
	ri.pos = pos;
	simpleShader->Render(simpleShader, spr.GetNowScene(), spr, ri, D3DXVECTOR4(0.5f, 0.5f, 0.5f, 0.8), timer);
	//spr.Render(ri);

	Object::Render();
}

void ObjectTest::Shot(float deltaTime)
{
	shotTimer += deltaTime;

	if (shotTimer >= pInfo.shotSpd)
	{
		if (Input::GetInstance().KeyDown(VK_SPACE))
		{
			switch (shotType)
			{
			case ShotType::Direct:
				pInfo.shotSpd = 0.1f;
				pInfo.bulletAmount = 1;
				break;

			case ShotType::Radiation:
				pInfo.shotSpd = 0.3f;
				pInfo.bulletAmount = 3;
				break;
			}

			for (int i = 0; i < pInfo.bulletAmount; ++i)
				nowScene->obm.AddObject(new Bullet(pos, (i - pInfo.bulletAmount / 2) * pInfo.shotAngle, 300));

			shotTimer = 0.0f;
		}
	}
}
