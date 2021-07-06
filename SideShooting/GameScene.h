#pragma once

class GameScene : public Scene
{
public:
	EnemyManager* enemyManager = NULL;

	virtual void Init() override;
	virtual void Update(float deltaTime) override;
	virtual void Render() override;
};

