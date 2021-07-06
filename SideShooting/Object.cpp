#include "DXUT.h"

void Object::Update(float deltaTime)
{
}

void Object::Render()
{
		for (auto	& body : bodies)
		{
			D3DXMATRIX matrix;
			D3DXMatrixTranslation(&matrix, pos.x, -pos.y, 0.0f);
	
			if (bCollision)
			{
				if (body.type == Collider2D::TYPE::AABB)
				{
					Game::GetInstance().DrawLine(body.aabb.min, D3DXVECTOR2(body.aabb.max.x, body.aabb.min.y), matrix, body.color);
					Game::GetInstance().DrawLine(D3DXVECTOR2(body.aabb.max.x, body.aabb.min.y), body.aabb.max, matrix, body.color);
					Game::GetInstance().DrawLine(body.aabb.max, D3DXVECTOR2(body.aabb.min.x, body.aabb.max.y), matrix, body.color);
					Game::GetInstance().DrawLine(D3DXVECTOR2(body.aabb.min.x, body.aabb.max.y), body.aabb.min, matrix, body.color);
				}
				else if (body.type == Collider2D::TYPE::CIRCLE)
				{
					D3DXVECTOR2 position[36];
					for (int i = 0; i < 36; ++i)
						position[i] = D3DXVec2Rotation(D3DXVECTOR2(0.0f, body.circle.radius), i * 10.0f);
					for (int i = 0; i < 36; ++i)
						Game::GetInstance().DrawLine(position[i], position[(i + 1) % 36], matrix, body.color);
				}
			}
		}
}

void Object::OnCollision2D(Collider2D& obj)
{
}

ObjectManager::~ObjectManager()
{
	for (auto& object : objects)
		SAFE_DELETE(object);

	for (auto& addObject : addObjects)
		SAFE_DELETE(addObject);
}

void ObjectManager::AddObject(Object* obj)
{
	addObjects.push_back(obj);
}

void ObjectManager::Update(float deltaTime)
{
	objects.insert(objects.end(), addObjects.begin(), addObjects.end());
	addObjects.clear();

	std::sort(objects.begin(), objects.end(), [](Object* lo, Object* ro) { return lo->layer < ro->layer; });

	for (auto object = objects.begin(); object != objects.end();)
	{
		(*object)->Update(deltaTime);
		if ((*object)->destroy)
		{
			SAFE_DELETE(*object);
			object = objects.erase(object);
		}
		else
			++object;
	}
}


void ObjectManager::Collision()
{
	for (auto it = objects.begin(); it != objects.end(); ++it)
	{
		for (auto it2 = it + 1; it2 != objects.end(); ++it2)
		{
			if (!(*it)->bCollision || !(*it2)->bCollision) continue;

			for (auto body1 : (*it)->bodies)
			{
				for (auto body2 : (*it2)->bodies)
				{
					if (IntersectCollider(body1, body2))
					{
						(*it)->OnCollision2D(body2);
						(*it2)->OnCollision2D(body1);
					}
				}
			}
		}
	}
}

void ObjectManager::Render()
{
	for (auto& object : objects)
		object->Render();
}