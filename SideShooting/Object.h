#pragma once

class Collider2D;
class Object
{
public:
	int layer = 0;
	bool destroy = false;
	bool bCollision = false;

	std::vector<Collider2D> bodies;
	D3DXVECTOR2 pos = { 0, 0 };

	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void OnCollision2D(Collider2D& obj);

};

class ObjectManager
{
	std::vector<Object*> objects;
	std::vector<Object*> addObjects;
public:
	virtual ~ObjectManager();

	void AddObject(Object* obj);
	void Update(float deltaTime);
	void Collision();
	void Render();
};
