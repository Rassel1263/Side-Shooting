#pragma once
class Bullet : public Object
{
public:
	Sprite spr;
	RenderInfo ri;

	Object* target = NULL;

	float angle = 0;

	Bullet(D3DXVECTOR2 pos, float angle);

	virtual void Update(float deltaTime) override;
	virtual void Render() override;
};

