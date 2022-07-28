#include "Nut.h"

bool Nut::OnFrame(int x, int y)
{
	if (m_x == x && m_y == y)
	{
		std::cout << m_name;
		return true;
	}
	return false;
}

void Nut::Move()
{
	m_CurrentCycle += 1;
}

bool Nut::IsDead()
{
	return m_CurrentCycle >= m_MaxCycle || m_isEaten;
}