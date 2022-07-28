#include "Snake.h"
#include "Egg.h"

Egg::Egg(int x, int y)
{
	m_name = 'E';
	m_x = x;
	m_y = y;
}

Egg::Egg(bool arrive)
{
	if (true)
	{
		m_name = 'E';
		m_x = rand() % m_w + 1;
		m_y = m_h - 1;
	}
}

bool Egg::OnFrame(int x, int y)
{
	if (m_x == x && m_y == y)
	{
		std::cout << m_name;
		return true;
	}
	return false;
}

void Egg::Move()
{
	m_CurrentCycle += 1;
}

Entity* Egg::Reproduction()
{
	if (m_CurrentCycle + 1 >= m_MaxCycle || m_isEaten)
	{
		return new Snake(m_x, m_y);
	}

	return nullptr;
}

bool Egg::Eat(char name)
{
	return false;
}

bool Egg::IsDead()
{
	if (m_CurrentCycle >= m_MaxCycle || m_isEaten)
	{
		return true;
	}
	
	return false;
}