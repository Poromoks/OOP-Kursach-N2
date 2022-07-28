#include <ctime>
#include <list>
#include "Nut.h"
#include "Chipmunk.h"
#include "Snake.h"
#include "Egg.h"

using namespace std;

int main()
{
	srand(time(0));

	list <Entity*> entities;

	for (int i = 0; i < 5; i++)
		entities.push_back(new Nut);

	for (int i = 0; i < 5; i++)
		entities.push_back(new Chipmunk);

	for (int i = 0; i < 1; i++)
		entities.push_back(new Snake);

	int seasonCounter = 0;

	while (true)
	{
		int time = clock();

		int snakeCounter = 0;

		list <Entity*> childs;

		for (auto it = entities.begin(); it != entities.end();) // полиморфизм и итератор
		{
			if ((*it)->IsDead())
				it = entities.erase(it);
			else
				it++;
		}

		for (const auto& entity : entities) // полиморфизм (одинаковый интерфейс, разная реализация)
		{
			if (entity->GetName() == 'S' || entity->GetName() == 'E') // массивы указателей на объекты (на самом деле это список)
				snakeCounter++;

			Entity* child = entity->Reproduction();
			if (child != nullptr)
				childs.push_back(child);

			entity->Move();

			for (const auto& eaten : entities) // полиморфизм
			{
				if ((entity != eaten) && (entity->GetPosition() == eaten->GetPosition()))
					if (entity->Eat(eaten->GetName()))
						eaten->SetEaten();
			}
		}

		if (snakeCounter < 2)
			entities.push_back(new Egg(true));

		seasonCounter++;

		if (seasonCounter == 20)
		{
			for (int i = 0; i < 5; i++)
				entities.push_back(new Nut);
			seasonCounter = 0;
		}

		for (int y = 0; y != 29; y++)
		{
			for (int x = 0; x != 119; x++)
			{
				bool isNotEmpty = false;
				for (const auto& entity : entities) // полиморфизм
				{
					isNotEmpty |= entity->OnFrame(x, y);
					if (isNotEmpty)
						break;
				}
				if (!isNotEmpty)
					cout << " ";
			}
			cout << endl;
		}

		int l = 0;

		while (l < 1)
		{
			int tick = clock();
			l = (tick - time) / CLOCKS_PER_SEC;
		}

		for (const auto& child : childs) // полиморфизм
			entities.push_back(child);

		system("cls");
	}

	return 0;
}