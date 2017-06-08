#include "GeneticAlgo.h"
#include <iostream>
#include <chrono>
#include <random>
#include <Windows.h>
using namespace std;

int main() {
	GeneticAlgo gA;
	//gA.initChrome();

	while (!gA.solutionFounded) {
		gA.calculatingFitness();
		gA.selection();
		gA.crossover();
		gA.mutation();
	}

	return 0;
}
