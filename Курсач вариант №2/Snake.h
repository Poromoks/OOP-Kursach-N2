#pragma once
#include "Entity.h"

class Snake : public Entity // наследование от Entity (сущности)
{
public:
	Snake() { m_name = 'S'; }; // конструктор
	Snake(int x, int y); // перегруженный конструктор, который используется, когда змея вылупляется
	bool	OnFrame(int x, int y)	override;
	void	Move()					override;
	Entity* Reproduction()			override;
	bool	Eat(char name)			override;
	bool	IsDead()				override;

private: // инкапсуляция (приватные переменные, которые недоступны вне класса)
	float		m_Hunger			= 3;
	const float	m_HungerRage		= 1.5;
	const int	m_MinAmount			= 2;
	const int	m_SnakeRelax		= 3;
	int			m_CurrentSnakeRelax = 3;
};