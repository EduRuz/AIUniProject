#include "GeneticAlgorithm.h"


GeneticAlgorithm::GeneticAlgorithm()
{
}


GeneticAlgorithm::~GeneticAlgorithm()
{

}

/**
Initializes the initial population for the genetic algorithm and works out initial average fintness
*/
void GeneticAlgorithm::init()
{

	Pokemon dragonite;

	for (int i = 0; i < populationSize; i++) {

		population.push_back(dragonite);
		population.back().initPokemon(0, 31);

		std::cout << "Dragonite " << (i + 1) << " Stats: " << "\n";
		std::cout << "Combat Power : " << population.back().getCP() << "\n";
		std::cout << "IVs Hp:" << population.back().getHPIV() << " Att:" << population.back().getAttIV() << " Def:" <<
			population.back().getDefIV() << " Spd:" << population.back().getSpdIV() << "\n" << "\n";
	}

	//Calculate initial avg Fitness
	for (int i = 0; i < population.size(); i++) {
		initialAvgFitness += population.at(i).getCP();
	}
	initialAvgFitness = initialAvgFitness / population.size();
	avgFitness.push_back(initialAvgFitness);

}

/**
Main method for the Algorithm, breeds together two parents to attempt to make better offspring then tests 
those offspring and continues breeding until the improvment over the generations is below a threshold.
*/
void GeneticAlgorithm::geneticAlgorithmProcess()
{

	//Genetic Algorithm loop 
	while (stop == false) {
			
		targetAmount += 10;

		for (int i = 0; i < population.size(); i++) {

			if (population.at(i).getCP() > parent1.getCP()) {
				parent1 = population.at(i);
			}

			if (population.at(i).getCP() < parent1.getCP() && population.at(i).getCP() > parent2.getCP()) {
				parent2 = population.at(i);
			}
		}
			
		newPopulation.clear();

		//Breeding Loop
		do {
			child = breeder.crossOverOperator(parent1, parent2);
			newPopulation.push_back(child);
			amountOfChildren++;

		} while (amountOfChildren < targetAmount);

		generation++;

		std::cout << "Generation " << generation << " of children" << "\n";
		//std::cout << "Press enter to continue to the next generation" << "\n" << "\n";
		//getchar();

		//Test fitness of children and keep the fittest ones
		newPopulation = fitnessCheck.fitnessTest(newPopulation, initialAvgFitness);

		newAvgFitness = 0;

		//Merge new population into current population and calculate average fitness
		for (int i = 0; i < newPopulation.size(); i++) {
			population.push_back(newPopulation.at(i));	
			newAvgFitness += newPopulation.at(i).getCP();
		}

		newAvgFitness = newAvgFitness / newPopulation.size();
		avgFitness.push_back(newAvgFitness);

		if (generation > 4) {
			avgFitnessOver2Gen = ((avgFitness.at(avgFitness.size() - 1) + avgFitness.at(avgFitness.size() - 2)) - (avgFitness.at(avgFitness.size() - 3) + avgFitness.at(avgFitness.size() - 4)));

			if (avgFitnessOver2Gen < avgFitnessThreshold) {

				stop = true;
				Pokemon tempBest;

				for (int i = 0; i < population.size(); i++) {

					if (population.at(i).getCP() > tempBest.getCP()) {
						tempBest = population.at(i);
					}
				}

				std::cout << "The Algorithm has ended and the strongest dragonite has been created. " << "\n";
				std::cout << "It took " << amountOfChildren << " children to find it" << "\n";
				std::cout << "Combat Power is : " << tempBest.getCP() << " CP" << "\n";
				std::cout << "IVs: Hp:" << tempBest.getHPIV() << " Att:" << tempBest.getAttIV() << " Def:" <<
					tempBest.getDefIV() << " Spd:" << tempBest.getSpdIV() << "\n";
			}
		}
	}
	
}

/**
Cleans up variables, clears data structures and reset variables for genetic algorithm to go again.
*/
void GeneticAlgorithm::cleanUp()
{
	population.clear();
	newPopulation.clear();
	avgFitness.clear();

	initialAvgFitness = 0.f;
	newAvgFitness = 0.f;
	avgFitnessOver2Gen = 0.f;

	stop = false;

	populationSize = 20;
	amountOfChildren = 0;
	generation = 0;
	targetAmount = 0;
}


