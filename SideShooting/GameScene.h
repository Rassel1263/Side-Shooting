#pragma once

class GameScene : public Scene
{
public:
	Enemy* enemy = NULL;

	virtual void Init() override;
	virtual void Update(float deltaTime) override;
	virtual void Render() override;
};

