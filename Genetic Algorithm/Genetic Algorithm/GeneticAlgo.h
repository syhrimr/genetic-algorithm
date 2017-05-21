#pragma once
#include <vector>

class Chrome {
public:
	int cpu;
	int gpu;
	int ram;
	int hdd;

	Chrome(int cpu, int gpu, int ram, int hdd) {
		this->cpu = cpu;
		this->gpu = gpu;
		this->ram = ram;
		this->hdd = hdd;
	}
};

class GeneticAlgo {
public:
	std::vector<Chrome*> chrome;

	GeneticAlgo();
	~GeneticAlgo();
	int objFunct(int i, int MAX);
	float fitness(int i, int MAX);
};

