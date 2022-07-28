#pragma once
#include "Entity.h"

class Nut : public Entity // ������������ �� Entity (��������)
{
public:
	Nut() { m_name = 'N'; }; // �����������
	bool	OnFrame(int x, int y)	override;
	void	Move()					override;
	Entity* Reproduction()			override { return nullptr; };
	bool	Eat(char name)			override { return false; };
	bool	IsDead()				override;

private: // ������������ (��������� ����������, ������� ���������� ��� ������)
	int			m_CurrentCycle	= 0;
	const int	m_MaxCycle		= 10;
};