#include "DXUT.h"
#include "GameScene.h"

void GameScene::Init()
{
	ShaderManager::GetInstance().CreateEffect("Simple", L"SimpleShader.fx", 0);

	obm.AddObject(new ObjectTest());
}

void GameScene::Update(float deltaTime)
{
	Scene::Update(deltaTime);
}

void GameScene::Render()
{
	Scene::Render();
}
