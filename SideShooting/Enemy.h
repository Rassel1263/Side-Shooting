#pragma once
class Enemy : public Object
{
public:
	Sprite spr;
	RenderInfo ri;

	Enemy();

	virtual void Update(float deltaTime) override;
	virtual void Render() override;
};

