#pragma once
#include <cstdlib>
#include <iostream>

class Entity
{
public:
	Entity() // конструктор
	{
		m_x = rand() % m_w + 1;
		m_y = rand() % m_h + 1;
	}

	struct vector2
	{
		vector2(int x, int y) : x(x), y(y) {}; // список инициализации
		int x = 0;
		int y = 0;

		friend bool operator== (const vector2& v1, const vector2& v2) // перегрузка оператора
		{
			return v1.x == v2.x && v1.y == v2.y;
		};
	};

	virtual bool	OnFrame(int x, int y)	= 0; // виртуальные функции
	virtual void	Move()					= 0;
	virtual Entity* Reproduction()			= 0;
	virtual bool	Eat(char name)			= 0;
	virtual bool	IsDead()				= 0;

	void SetEaten()
	{
		m_isEaten = true;
	};

	vector2 GetPosition()
	{
		return vector2(m_x, m_y);
	};

	char GetName()
	{
		return m_name;
	}

protected: // инкапсул€ци€ (приватные переменные, которые недоступны вне класса)
	int			m_x;
	int			m_y;
	const int	m_w			= 10;
	const int	m_h			= 10;
	char		m_name		= ' ';
	bool		m_isEaten	= false;
};