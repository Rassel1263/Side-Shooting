#include "DXUT.h"
#include "GameScene.h"

void GameScene::Init()
{
	ShaderManager::GetInstance().CreateEffect("Simple", L"SimpleShader.fx", 0);

	enemyManager = new EnemyManager();

	obm.AddObject(new ObjectTest());
}

void GameScene::Update(float deltaTime)
{
	enemyManager->SpawnEnemy(deltaTime);

	Scene::Update(deltaTime);
}

void GameScene::Render()
{
	Scene::Render();
}
