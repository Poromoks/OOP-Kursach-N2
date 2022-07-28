#pragma once
#include "Entity.h"

class Egg : public Entity // наследование от Entity (сущности)
{
public:
	Egg(int x, int y); // конструктор
	Egg(bool arrive); // перегруженный конструктор, который используется при создании нового яйца на карте
	bool	OnFrame(int x, int y)	override;
	void	Move()					override;
	Entity* Reproduction()			override;
	bool	Eat(char name)			override;
	bool	IsDead()				override;

private: // инкапсуляция (приватные переменные, которые недоступны вне класса)
	int			m_CurrentCycle	= 0;
	const int	m_MaxCycle		= 2;
};