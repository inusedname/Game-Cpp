#include "Pool.h"

Pool::Pool()
{
	for (int i = 0; i < 10; i++)
	{
		normalCars.push_back(new Car("car" + std::to_string(i)));
		fnormalCars.push_back(new Car("fcar" + std::to_string(i)));
	}
	for (int i = 0; i < 4; i++)
	{
		specialCars.push_back(new Car("special" + std::to_string(i)));
		fspecialCars.push_back(new Car("fspecial" + std::to_string(i)));
	}
	leaf = new Leaf();
	tile[0].setTexture(*DATA->getTexture("tile1"));
	tile[1].setTexture(*DATA->getTexture("tile3"));
}

Pool::~Pool()
{
	for (int i = 0; i < 10; i++)
	{
		delete normalCars[i];
		delete fnormalCars[i];
	}
	for (int i = 0; i < 4; i++)
	{
		delete specialCars[i];
		delete fspecialCars[i];
	}
}

Car* Pool::getCar(int pos, bool special, bool flipped)
{
	if (flipped == false)
	{
		if (special)
			return specialCars[pos];
		return normalCars[pos];
	}
	else
	{
		if (special)
			return fspecialCars[pos];
		return fnormalCars[pos];
	}
}

Leaf* Pool::getLeaf()
{
	return leaf;
}

void Pool::setPosTile(Vector2f pos, int index)
{
	tile[index].setPosition(pos);
}

void Pool::DrawTile(RenderWindow* window, int index)
{
	window->draw(tile[index]);
}

