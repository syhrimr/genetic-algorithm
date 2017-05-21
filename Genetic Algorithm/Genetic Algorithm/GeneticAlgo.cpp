#include "GeneticAlgo.h"
#include <iostream>
#include <cmath>

GeneticAlgo::GeneticAlgo()
{
}


GeneticAlgo::~GeneticAlgo()
{
}

int GeneticAlgo::objFunct(int i, int MAX) {
	return std::abs((chrome[i]->cpu + chrome[i]->gpu + chrome[i]->ram + chrome[i]->hdd) - MAX);
}

float GeneticAlgo::fitness(int i, int MAX) {
	return 1 / (float)(objFunct(i, MAX) + 1);
}
