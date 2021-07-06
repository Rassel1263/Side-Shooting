#pragma once

template <typename T>
class SingleTon
{
protected:
	SingleTon() {};
	SingleTon(const T&) = delete;
	SingleTon operator=(const T&) = delete;

public:
	static T& GetInstance()
	{
		static T instance;
		return instance;
	}
};