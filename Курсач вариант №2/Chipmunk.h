#pragma once
#include "Entity.h"

class Chipmunk : public Entity // ������������ �� Entity (��������)
{
public:
	Chipmunk() { m_name = 'C'; }; // �����������
	Chipmunk(int x, int y); // ������������� �����������, ������� ������������, ����� �������� ������������
	bool	OnFrame(int x, int y)	override;
	void	Move()					override;
	Entity* Reproduction()			override;
	bool	Eat(char name)			override;
	bool	IsDead()				override;

private: // ������������ (��������� ����������, ������� ���������� ��� ������)
	float		m_Hunger				= 0.5;
	const float	m_ReproductionChance	= 25;
};