#include "GeneticAlgo.h"
#include <iostream>
#include <chrono>
#include <random>
using namespace std;

const int MAX = 10;
const int NUM_OF_CHROME = 6;

int randomize(int max) {
	default_random_engine dre(chrono::steady_clock::now().time_since_epoch().count());
	uniform_int_distribution<int> uid{ 1, MAX };
	return uid(dre);
}

int main() {
	GeneticAlgo *gA = new GeneticAlgo();

	// Generating random var params
	for (int i = 0; i <= NUM_OF_CHROME; i++) {
		int a = randomize(MAX);
		int b = randomize(MAX);
		int c = randomize(MAX);
		int d = randomize(MAX);

		// Initiate chrome
		gA->chrome.push_back(new Chrome(a, b, c, d));

		// Debugging
		cout << gA->chrome[i]->cpu << " "
			<< gA->chrome[i]->gpu << " "
			<< gA->chrome[i]->ram << " "
			<< gA->chrome[i]->hdd << " = "
			<< gA->objFunct(i, MAX) << " / "
			<< gA->fitness(i, MAX) << endl;
	}

	return 0;
}
