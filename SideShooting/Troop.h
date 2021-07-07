#pragma once

enum class Formation
{
	V_Shaped,
	S_Shaped,
	C_Sahped
};

class Troop : public Object
{
public:
	int enemyCount = 0;
	float angle_D = 20;
	float interval = 0;
	float mDistance = 0;
	float createAngle = 0;

	D3DXVECTOR2 offset = { 0, 0 };
	
	std::vector<Enemy*> enemys;

	Formation formation;

	Troop(int enemyCount, float interval, float angle, Formation formation, D3DXVECTOR2 pos);

	virtual void Update(float deltaTime) override;
	virtual void Render() override;
};

