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

	enum class Formation
	{
		V_Shaped,
		S_Shaped,
		C_Sahped
	};

	float spawnTime = 3.0f;
	float spawnTimer = 0.0f;

	void SpawnEnemy(float deltaTime);
};

