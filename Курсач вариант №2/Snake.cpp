#include "Snake.h"
#include "Egg.h"

Snake::Snake(int x, int y)
{
	m_name = 'S';
	m_x = x;
	m_y = y;
}

bool Snake::OnFrame(int x, int y)
{
	if (m_x == x && m_y == y)
	{
		std::cout << m_name;
		return true;
	}
	return false;
}

void Snake::Move()
{
	int dx = (rand() % 2 ? 1 : -1);
	int dy = (rand() % 2 ? 1 : -1);

	if (m_x + dx < m_w && m_x + dx > 0 && m_SnakeRelax < m_CurrentSnakeRelax)
		m_x += dx;

	if (m_y + dy < m_h && m_y + dy > 0 && m_SnakeRelax < m_CurrentSnakeRelax)
		m_y += dy;

	m_Hunger -= 0.2;
	m_CurrentSnakeRelax += 1;
}

Entity* Snake::Reproduction()
{
	if (m_Hunger - 0.2 <= 0 || m_isEaten)
	{
		return new Egg(m_x, m_y);
	}

	return nullptr;
}

bool Snake::Eat(char name)
{
	if (name == 'C' && m_Hunger < m_HungerRage)
	{
		m_Hunger += 0.2;
		m_CurrentSnakeRelax = 0;
		return true;
	}

	return false;
}

bool Snake::IsDead()
{
	if (m_Hunger <= 0 || m_isEaten)
	{
		return true;
	}

	return false;
}