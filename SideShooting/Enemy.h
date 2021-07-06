#pragma once
class Enemy : public Object
{
public:
	Sprite spr;
	RenderInfo ri;
	Object* target = NULL;

	D3DXVECTOR2 offset = { 0, 0 };
	D3DXVECTOR2 pastPos = { 0, 0 };

	float dirAngle = 0.0f;
	float fallowTimer = 0.1f;

	Enemy(Object* target, D3DXVECTOR2 pos, D3DXVECTOR2 offset, EnemyManager::EnemyType type);

	virtual void Update(float deltaTime) override;
	virtual void Render() override;
};

