#pragma once

class ObjectTest : public Object
{
public:
	Sprite spr;
	RenderInfo ri;

	SimpleShader* simpleShader = NULL;

	float timer = 0;
	ObjectTest();

	virtual void Update(float deltaTime) override;
	virtual void Render() override;
};

