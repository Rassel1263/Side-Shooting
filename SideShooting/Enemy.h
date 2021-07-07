#pragma once
class Enemy : public Object
{
public:
	Sprite spr;
	RenderInfo ri;
	D3DXVECTOR2 nextPos = { 0,0 };

	float dirAngle = 0.0f;
	
	Enemy(D3DXVECTOR2 pos);

	virtual void Update(float deltaTime) override;
	virtual void Render() override;
	
	void SetPos(D3DXVECTOR2 pos);
};

