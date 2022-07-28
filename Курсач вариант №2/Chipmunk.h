#pragma once
#include "Entity.h"

class Chipmunk : public Entity // наследование от Entity (сущности)
{
public:
	Chipmunk() { m_name = 'C'; }; // конструктор
	Chipmunk(int x, int y); // перегруженный конструктор, который используется, когда бурундук размножается
	bool	OnFrame(int x, int y)	override;
	void	Move()					override;
	Entity* Reproduction()			override;
	bool	Eat(char name)			override;
	bool	IsDead()				override;

private: // инкапсуляция (приватные переменные, которые недоступны вне класса)
	float		m_Hunger				= 0.5;
	const float	m_ReproductionChance	= 25;
};