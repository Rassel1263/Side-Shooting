#pragma once

struct PlayerInfo
{
	int Level = 1;
	int bulletAmount = 1;

	float Exp = 0;
	float hp = 5;
	float speed = 100;
	float damage = 10;
	float shotSpd = 0.1f;
	float shotAngle = 30;
};

class ObjectTest : public Object
{
public:
	enum class ShotType
	{
		Direct,
		Radiation
	} shotType = ShotType::Direct;

	Sprite spr;
	RenderInfo ri;
	PlayerInfo pInfo;

	SimpleShader* simpleShader = NULL;

	float timer = 0;
	float shotTimer = 0.0f;

	ObjectTest();

	virtual void Update(float deltaTime) override;
	virtual void Render() override;

	void Shot(float deltaTime);
};

