#pragma once
#include <string>
#include <random>
#include <iostream>

class Pokemon
{
public:
	Pokemon();
	~Pokemon();

	void initPokemon(float hp, float att, float def, float spd);
	void initPokemon(int upper, int lower);

	void calculateCombatPower();

	//CP
	float getCP() { return combatPower; }
	void setCP(float cp) { combatPower = cp; }
	
	//HP
	float getHPIV() { return healthIV; }
	void setHPIV(float hp);
	//Att
	float getAttIV() { return attackIV; }
	void setAttIV(float att);
	//Def
	float getDefIV() { return defenceIV; }
	void setDefIV(float def);
	//Spd
	float getSpdIV() { return speedIV; }
	void setSpdIV(float spd);

	bool getMutated() { return mutated; }
	void setMutated(bool flag) { mutated = flag; }

	bool getCrossover() { return crossOver; }
	void setCrossover(bool flag) { crossOver = flag; }

private:

	float hpWeight = 1.6f;
	float attWeight = 1.8f;
	float defWeight = 1.4f;
	float spdWeight = 2.0f;

	void setChromosomes();

	int upperRange;
	int lowerRange;

	bool mutated = false;
	bool crossOver = false;

protected:

	int chromosomes[4];

	float combatPower = 0.0f;
	float healthIV, attackIV, defenceIV, speedIV;


};


