#include "Chipmunk.h"

Chipmunk::Chipmunk(int x, int y)
{
	m_name = 'C';
	m_x = x;
	m_y = y;
}

bool Chipmunk::OnFrame(int x, int y)
{
	if (m_x == x && m_y == y)
	{
		std::cout << m_name;
		return true;
	}
	return false;
}

void Chipmunk::Move()
{
	int dx = (rand() % 2 ? 1 : -1);
	int dy = (rand() % 2 ? 1 : -1);

	if (m_x + dx < m_w && m_x + dx > 0)
		m_x += dx;

	if (m_y + dy < m_h && m_y + dy > 0)
		m_y += dy;

	m_Hunger -= 0.2;
}

Entity* Chipmunk::Reproduction()
{
	if (rand() % 100 + 1 >= m_ReproductionChance)
	{
		m_Hunger -= 0.4;
		return new Chipmunk(m_x, m_y);
	}

	return nullptr;
}

bool Chipmunk::Eat(char name)
{
	if (name == 'N')
	{
		m_Hunger += 0.2;
		return true;
	}

	return false;
}

bool Chipmunk::IsDead()
{
	return m_Hunger <= 0 || m_isEaten;
}