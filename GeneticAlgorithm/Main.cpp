/**
	Genetic Algorithm to replicate and automate the 
	Pokemon breeding mechanic within the games.

	Made for my Artificial Intelligence CMP304 Assessment.

	@Author Ruaraidh Canaway.
	
	**Key**
	IV - Individual Value.
	CP - Combat Power - This is the Fitness Value.
	HP - Health Points.
	att - Attack.
	def - Defence.
	spd - Speed.
*/

#include <iostream>
#include "GeneticAlgorithm.h"


int main()
{
	bool cont = false;
	do {
		//GA
		GeneticAlgorithm geneticAlgorithm;
		geneticAlgorithm.init();
		geneticAlgorithm.geneticAlgorithmProcess();
		geneticAlgorithm.cleanUp();

		std::cout << "\n" << "Please Enter y/n to go again" << "\n";
		std::string input;
		std::cin >> input;
		
		char check = input[0];
		
		if (check == 'y') {
			cont = true;
		}
		else {
			cont = false;
		}

	} while (cont == true);

	return 0;
}