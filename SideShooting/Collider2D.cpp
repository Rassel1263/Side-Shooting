#include "DXUT.h"

bool IntersectCollider(const Collider2D& _coli1, const Collider2D& _coli2)
{
	if (_coli1.type == Collider2D::TYPE::AABB && _coli2.type == Collider2D::TYPE::AABB)
	{
		return IntersectAABBAABB(_coli1.obj->pos + _coli1.aabb.min, _coli1.obj->pos + _coli1.aabb.max,
			_coli2.obj->pos + _coli2.aabb.min, _coli2.obj->pos + _coli2.aabb.max);
	}

	else if (_coli1.type == Collider2D::TYPE::CIRCLE && _coli2.type == Collider2D::TYPE::CIRCLE)
	{
		return IntersectCircleCircle(_coli1.obj->pos, _coli1.circle.radius, _coli2.obj->pos, _coli2.circle.radius);
	}

}

D3DXVECTOR2 D3DXVec2Rotation(const D3DXVECTOR2& vec1, const float& rotate)
{
	if (vec1 == D3DXVECTOR2(0.0f, 0.0f))
		return D3DXVECTOR2(0.0f, 0.0f);

	float radian = D3DXToRadian(-rotate);
	float sin = sinf(radian);
	float cos = cosf(radian);
	return D3DXVECTOR2(cos * vec1.x - sin * vec1.y, sin * vec1.x + cos * vec1.y);
}

bool IntersectAABBAABB(const D3DXVECTOR2& min, const D3DXVECTOR2& max, const D3DXVECTOR2& min2, const D3DXVECTOR2& max2)
{
	return (min.x < max2.x) && (max.x > min2.x) && (min.y < max2.y) && (max.y > min2.y);
}

bool IntersectCircleCircle(const D3DXVECTOR2& _p1, const float& _r1, const D3DXVECTOR2& _p2, const float& _r2)
{
	D3DXVECTOR2 p = D3DXVECTOR2(_p2.x - _p1.x, _p2.y - _p1.y);
	return p.x * p.x + p.y * p.y < (_r1 + _r2)* (_r1 + _r2);
}

Collider2D::Collider2D(Object* obj, const std::wstring& tag, const AABB* aabb, const Circle* circle, D3DXCOLOR color)
{
	if (circle)
	{
		type = TYPE::CIRCLE;
		this->circle = *circle;
	}
	else if (aabb)
	{
		type = TYPE::AABB;
		this->aabb = *aabb;
	}

	this->tag = tag;
	this->obj = obj;
	this->color = color;
	obj->bCollision = true;
}
