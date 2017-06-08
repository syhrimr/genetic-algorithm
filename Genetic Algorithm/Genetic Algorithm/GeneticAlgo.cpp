#include "GeneticAlgo.h"

void GeneticAlgo::calculatingFitness() {
	totalFitness = 0;

	for (int i = 0; i < 6; i++) {
		int objectiveFunction = abs((chromeSpec[i].getCPU() + chromeSpec[i].getGPU() + chromeSpec[i].getHDD() + chromeSpec[i].getRAM()) - MAX);
		chromeSpec[i].fitness = 1 / (double)(objectiveFunction + 1);
		totalFitness += chromeSpec[i].fitness;
	}

	for (int i = 0; i < 6; i++) {
		temp[i] = chromeSpec[i];
	}
}

void GeneticAlgo::print() {
	system("cls");
	cout << "Generation : " << generation << "\n";

	for (int i = 0; i < 6; i++) {

		cout << chromeSpec[i].gen.cpu << " ";
		cout << chromeSpec[i].gen.gpu << " ";
		cout << chromeSpec[i].gen.ram << " ";
		cout << chromeSpec[i].gen.hdd << " ";
		
		cout << "Fitness : " << chromeSpec[i].fitness << "\n";
		if (chromeSpec[i].fitness > highestFitness) {
			highestFitness = chromeSpec[i].fitness;

			if (highestFitness == 1)
				solutionFounded = true;
		}
	}

	//if (solutionFounded)
		//bestChrome.printAll();
	Sleep(500);
}

void GeneticAlgo::selection() {
	int chosen = 0;
	
	for (int i = 0; i < 6; i++) {
		double r = 0.1 + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (1.0 - 0.1)));

		for (int j = 0; j < 6; j++) {
			if (r > 0.5) {
				r -= chromeSpec[j].fitness / totalFitness;
			} else if (r <= 0.5) {
				totalFitness -= chromeSpec[j].fitness;
				chosen = j;
				break;
			}
		}

		temp[i] = chromeSpec[chosen];
	}
}

void GeneticAlgo::mutation() {
	int totalGen = 6 * 4;
	int sumMutation = totalGen * mutationRate;
	ChromeSpec *spec;

	for (int i = 0; i < sumMutation; i++) {
		spec = &temp[i];
		float r = 0.1 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (1.0 - 0.1)));
		int random = 1 + static_cast<int>(rand()) / (static_cast<int>(RAND_MAX / (MAX)));

		if (r < mutationRate) {
			switch (random % 4) {
			case 1:
				spec->gen.cpu = 1 + (rand() % (int)(MAX));
				break;
			case 2:
				spec->gen.gpu = 1 + (rand() % (int)(MAX));
				break;
			case 3:
				spec->gen.ram = 1 + (rand() % (int)(MAX));
				break;
			case 0:
				spec->gen.hdd = 1 + (rand() % (int)(MAX));
				break;
			}
		}
	}

	for (int i = 0; i < 6; i++)
		chromeSpec[i] = temp[i];
	generation++;
	//if (generation == maxGeneration) 
		//solutionFounded = true;
	print();
}

void GeneticAlgo::crossover() {
	ChromeSpec *newChrome[6];
	int j = 0;

	for (int i = 0; i < 6; i++) {
		float r = 0.1 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (1.0 - 0.1)));
		if (r <= crossoverRate) {
			newChrome[j] = &temp[i];
			j++;
		}
	}

	for (int k = 0; k < j; k++) {
		int a, b;
		int random = 0 + (rand() % (int)(3 - 0 + 1));

		if (k < j - 1) { a = k; b = k + 1; }
		else { a = k; b = 0; }

		temp[a].gen = newChrome[b]->gen;
		temp[a].gen = newChrome[b]->gen;
	}
}

GeneticAlgo::GeneticAlgo() {
	for (int i = 0; i < 6; i++) {
		chromeSpec[i].gen.cpu = 1 + (rand() % (int)(MAX));
		chromeSpec[i].gen.gpu = 1 + (rand() % (int)(MAX));
		chromeSpec[i].gen.ram = 1 + (rand() % (int)(MAX));
		chromeSpec[i].gen.hdd = 1 + (rand() % (int)(MAX));
	}

	srand(static_cast <unsigned> (time(0)));
}

GeneticAlgo::~GeneticAlgo() {

}
