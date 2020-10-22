#include "BreedingManager.h"



BreedingManager::BreedingManager()
{
}


BreedingManager::~BreedingManager()
{
}

/**
Performs a single point crossover with a random point on the two parents to create a single offspring.
@param Pokemon parent 1 for breeding.
@param Pokemon parent 2 for breeding.
*/
Pokemon BreedingManager::crossOverOperator(Pokemon parent1, Pokemon parent2)
{
	Pokemon child;

	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<int> distr(1, 90);

	int randomCrossoverPoint = distr(eng);
	
	//80% chance to Crossover with IV's calculated at random if crossover fails
	if (randomCrossoverPoint >= 1 && randomCrossoverPoint <= 12) {
		//1
		child.initPokemon(parent1.getHPIV(), parent2.getAttIV(), parent2.getDefIV(), parent2.getSpdIV());
		child.setCrossover(true);
	}
	else if (randomCrossoverPoint >= 13 && randomCrossoverPoint <= 24) {
		//2
		child.initPokemon(parent1.getHPIV(), parent1.getAttIV(), parent2.getDefIV(), parent2.getSpdIV());
		child.setCrossover(true);
	}
	else if (randomCrossoverPoint >= 25 && randomCrossoverPoint <= 36) {
		//3
		child.initPokemon(parent1.getHPIV(), parent1.getAttIV(), parent1.getDefIV(), parent2.getSpdIV());
		child.setCrossover(true);
	}
	else if (randomCrossoverPoint >= 37 && randomCrossoverPoint <= 48) {
		//4
		child.initPokemon(parent2.getHPIV(), parent1.getAttIV(), parent1.getDefIV(), parent1.getSpdIV());
		child.setCrossover(true);
	}
	else if (randomCrossoverPoint >= 49 && randomCrossoverPoint <= 60) {
	//5
		child.initPokemon(parent2.getHPIV(), parent2.getAttIV(), parent1.getDefIV(), parent1.getSpdIV());
		child.setCrossover(true);
	}
	else if (randomCrossoverPoint >= 61 && randomCrossoverPoint <= 72) {
	//6
		child.initPokemon(parent2.getHPIV(), parent2.getAttIV(), parent2.getDefIV(), parent1.getSpdIV());
		child.setCrossover(true);
	}
	else {
		child.initPokemon(0, 31);
		child.setCrossover(false);
	}

	child = mutationOperator(child);

	//Parent 1 Stats Output
	std::cout << "Parent 1 :" << parent1.getCP() <<" CP " << "\n";
	std::cout << "IVs Hp:" << parent1.getHPIV() << " Att:" << parent1.getAttIV() << " Def:" <<
		parent1.getDefIV() << " Spd:" << parent1.getSpdIV() << "\n";
	//Parent 2 Stats Output
	std::cout << "Parent 2 :" << parent2.getCP() << " CP " << "\n";
	std::cout << "IVs Hp:" << parent2.getHPIV() << " Att:" << parent2.getAttIV() << " Def:" <<
		parent2.getDefIV() << " Spd:" << parent2.getSpdIV() << "\n";
	//Child Stats Output
	std::cout << "Child    :" << child.getCP() <<" CP" << "\n";

	if (child.getCrossover() == true) {
		std::cout << "Successful Cross Over & ";
	}
	else {
		std::cout << "Unsuccessful Cross Over & ";
	}

	if (child.getMutated() == true) {
		std::cout << "Successful Mutation" << "\n";
	}
	else {
		std::cout << "Unsuccessful Mutation" << "\n";
	}


	std::cout << "IVs Hp:" << child.getHPIV() << " Att:" << child.getAttIV() << " Def:" <<
		child.getDefIV() << " Spd:" << child.getSpdIV() << "\n" << "\n";

	return child;
}

/**
Performs mutation on the passed in Pokemon. 2% chance to mutate with 50/50 that its constructive or destructive.
@param Pokemon to perform mutation on.
*/
Pokemon BreedingManager::mutationOperator(Pokemon pkmn)
{
	//Random number for if mutation happens
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<int> distr(1, 100);

	int rand = distr(eng);

	//2% Chance
	if (rand > 98) {
		//Random number for destructive or constructive mutation
		std::random_device rd2;
		std::mt19937 eng2(rd2());
		std::uniform_int_distribution<int> distr2(1, 8);

		int rand2 = distr2(eng2);

		// 50/50 of constructive or destructive
		switch (rand2) {
		
		case 1:
			pkmn.setHPIV((pkmn.getHPIV() + 1));
			break;
		case 2:
			pkmn.setAttIV((pkmn.getAttIV() + 1));
			break;
		case 3:
			pkmn.setDefIV((pkmn.getDefIV() + 1));
			break;
		case 4:
			pkmn.setSpdIV((pkmn.getSpdIV() + 1));
			break;
		case 5:
			pkmn.setHPIV((pkmn.getHPIV() - 1));
			break;
		case 6:
			pkmn.setAttIV((pkmn.getAttIV() - 1));
			break;
		case 7:
			pkmn.setDefIV((pkmn.getDefIV() - 1));
			break;
		case 8:
			pkmn.setSpdIV((pkmn.getSpdIV() - 1));
			break;
		}
		pkmn.setMutated(true);
		pkmn.calculateCombatPower();
	}

	return pkmn;
}
