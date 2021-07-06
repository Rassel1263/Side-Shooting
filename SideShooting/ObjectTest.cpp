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

	if (Input::GetInstance().KeyDown(VK_SPACE))
		nowScene->obm.AddObject(new Bullet(pos, 180));

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
