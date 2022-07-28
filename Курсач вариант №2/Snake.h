#pragma once
#include "Entity.h"

class Snake : public Entity // ������������ �� Entity (��������)
{
public:
	Snake() { m_name = 'S'; }; // �����������
	Snake(int x, int y); // ������������� �����������, ������� ������������, ����� ���� �����������
	bool	OnFrame(int x, int y)	override;
	void	Move()					override;
	Entity* Reproduction()			override;
	bool	Eat(char name)			override;
	bool	IsDead()				override;

private: // ������������ (��������� ����������, ������� ���������� ��� ������)
	float		m_Hunger			= 3;
	const float	m_HungerRage		= 1.5;
	const int	m_MinAmount			= 2;
	const int	m_SnakeRelax		= 3;
	int			m_CurrentSnakeRelax = 3;
};