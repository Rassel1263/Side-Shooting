#include "DXUT.h"
#include "EnemyManager.h"

void EnemyManager::SpawnEnemy(float deltaTime)
{
	spawnTimer += deltaTime;

	if (spawnTimer >= spawnTime)
	{
		Enemy* enemy;
		nowScene->obm.AddObject(enemy = new Enemy(NULL, { 1000, 0 }, { 0, 0 }, EnemyType::Small));

		for (int i = 1; i <= 3; ++i)
		{
			Enemy* fastEnemy = enemy;
			nowScene->obm.AddObject(enemy = new Enemy(fastEnemy, { 1000 + (float)i * 50, 0 }, { -100, 50 }, EnemyType::Small));
		}

		spawnTimer = -999.0f;
	}
}
