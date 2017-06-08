#pragma once
#include <math.h>
#include <cmath>
#include <time.h>
#include <iostream>
#include <stdlib.h>
#include <Windows.h>
using namespace std;

class GeneticAlgo {
	struct Spec {
		int cpu;
		int gpu;
		int ram;
		int hdd;
	};
	
	struct ChromeSpec {
		Spec gen;
		double fitness;
		
		void printAll() {
			for (int i = 0; i < 6; i++) {
				cout << gen.cpu << " ";
				cout << gen.gpu << " ";
				cout << gen.ram << " ";
				cout << gen.hdd << " ";
				cout << "Fitness : " << fitness << "\n";
			}
		}
		int getCPU() { return gen.cpu; }
		int getGPU() { return gen.gpu; }
		int getRAM() { return gen.ram; }
		int getHDD() { return gen.hdd; }
	};
	
public:
	int MAX = 10;
	int generation = 0;
	int maxGeneration = 500;
	double crossoverRate = 0.6;
	double mutationRate = 0.3;
	double totalFitness;
	double highestFitness = 0;
	bool solutionFounded = false;
	
	ChromeSpec bestChrome;
	ChromeSpec chromeSpec[4];
	ChromeSpec temp[4];
	
	GeneticAlgo();
	~GeneticAlgo();

	void print();
	void calculatingFitness();
	void selection();
	void crossover();
	void mutation();
};
