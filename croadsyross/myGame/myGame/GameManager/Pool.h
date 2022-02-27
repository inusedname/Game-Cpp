#pragma once
#include "Singleton.h"
#include "../Objects/Car.h"
#include "../Objects/Leaf.h"

#define POOL Pool::GetInstance()

class Pool : public CSingleton<Pool>
{
private:
	std::vector <Car*> normalCars;
	std::vector <Car*> specialCars;
	std::vector <Car*> fnormalCars;
	std::vector <Car*> fspecialCars;
	Leaf* leaf;
	Sprite tile[2];
	
public:
	Pool();
	~Pool();
	Car* getCar(int, bool, bool);
	Leaf* getLeaf();
	void setPosTile(Vector2f, int index);
	void DrawTile(RenderWindow* window, int index);
};