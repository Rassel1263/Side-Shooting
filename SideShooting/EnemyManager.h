#pragma once

class EnemyManager
{
public:
	enum class EnemyType
	{
		Small,
		Medium,
		Big
	};


	float spawnTime = 3.0f;
	float spawnTimer = 0.0f;

	void SpawnEnemy(float deltaTime);
};

