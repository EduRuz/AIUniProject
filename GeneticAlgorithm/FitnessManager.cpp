#include "FitnessManager.h"



FitnessManager::FitnessManager()
{
}


FitnessManager::~FitnessManager()
{
}

/**
Performs the fitness test on the passed in vector and returns a new vector with pokemon above the fitness target.
@param vector<Pokemon> to be evaluated.
@param float target level of fitness for returned population.
*/
std::vector<Pokemon> FitnessManager::fitnessTest(std::vector<Pokemon> populationToTest, float fitnessTarget)
{
	
	for (int i = 0; i < populationToTest.size(); i++) {
	
		if (populationToTest.at(i).getCP() > fitnessTarget) {
			fittestPopulation.push_back(populationToTest.at(i));
		}
	}
	
	return fittestPopulation;
}
