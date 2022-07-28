#pragma once
#include "Entity.h"

class Egg : public Entity // ������������ �� Entity (��������)
{
public:
	Egg(int x, int y); // �����������
	Egg(bool arrive); // ������������� �����������, ������� ������������ ��� �������� ������ ���� �� �����
	bool	OnFrame(int x, int y)	override;
	void	Move()					override;
	Entity* Reproduction()			override;
	bool	Eat(char name)			override;
	bool	IsDead()				override;

private: // ������������ (��������� ����������, ������� ���������� ��� ������)
	int			m_CurrentCycle	= 0;
	const int	m_MaxCycle		= 2;
};