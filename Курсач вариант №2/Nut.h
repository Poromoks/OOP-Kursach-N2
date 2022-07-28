#pragma once
#include "Entity.h"

class Nut : public Entity // наследование от Entity (сущности)
{
public:
	Nut() { m_name = 'N'; }; // конструктор
	bool	OnFrame(int x, int y)	override;
	void	Move()					override;
	Entity* Reproduction()			override { return nullptr; };
	bool	Eat(char name)			override { return false; };
	bool	IsDead()				override;

private: // инкапсуляция (приватные переменные, которые недоступны вне класса)
	int			m_CurrentCycle	= 0;
	const int	m_MaxCycle		= 10;
};