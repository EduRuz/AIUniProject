#pragma once
#include "Pokemon.h"
#include <vector>

class FitnessManager
{
public:
	FitnessManager();
	~FitnessManager();

	std::vector<Pokemon> fittestPopulation;
	std::vector<Pokemon> fitnessTest(std::vector<Pokemon> populationToTest, float fitnessTarget);
};

