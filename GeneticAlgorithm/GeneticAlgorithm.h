#pragma once
#include "BreedingManager.h"
#include "FitnessManager.h"
#include "Pokemon.h"
#include <vector>
#include <stdio.h>

class GeneticAlgorithm
{
public:
	GeneticAlgorithm();
	~GeneticAlgorithm();

	void init();
	void geneticAlgorithmProcess();
	void cleanUp();

	int getGenerations() { return generation; }

private:
	//Populations
	std::vector<Pokemon> population;
	std::vector<Pokemon> newPopulation;

	//FitnessTesting
	std::vector<float> avgFitness;
	float initialAvgFitness = 0.f;
	float newAvgFitness = 0.f;
	float avgFitnessOver2Gen = 0.f;
	float avgFitnessThreshold = .5f;

	//Dragonites
	Pokemon parent1;
	Pokemon parent2;
	Pokemon child;

	int populationSize = 20;
	int amountOfChildren = 0;
	int generation = 0;
	int targetAmount = 0;//Target amount of children for a generation

	bool stop = false;

	BreedingManager breeder;
	FitnessManager fitnessCheck;

};

