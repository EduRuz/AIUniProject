#pragma once

#include "Pokemon.h"

class BreedingManager
{
public:
	BreedingManager();
	~BreedingManager();

	Pokemon crossOverOperator(Pokemon pkmn1, Pokemon pkmn2);
	Pokemon mutationOperator(Pokemon pkmn);

private:




protected:


};

