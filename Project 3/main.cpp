/*****************************************************

	By: Anthony Huynh
	Date: 11/04/2018
	Description: main file for the fantasy combat game 

*****************************************************/

#include <stdlib.h>
#include <time.h>
#include "Character.hpp"
#include "Vampire.hpp"
#include "Menu.hpp"
#include "inputValidation.hpp"
#include <iostream>
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"


int main()
{
	//to begin seeding for when dice rolls are needed
	srand(time(0));

	//two character pointers
	Character* char1;
	Character* char2;

	//to create and display character menu, as well as get user's choice
	Menu characterMenu;
	int character1Choice;
	int character2Choice;
	characterMenu.addOption("Vampire");
	characterMenu.addOption("Barbarian");
	characterMenu.addOption("Blue Men");
	characterMenu.addOption("Medusa");
	characterMenu.addOption("Harry Potter");

	//to create and display continue menu
	Menu continueMenu; 
	int continueChoice = 1;
	continueMenu.addOption("Play Again");
	continueMenu.addOption("Quit Game");
	while (continueChoice == 1)
	{

		//for user to pick first character
		std::cout << "What would you like the first character to be? " << std::endl;
		characterMenu.displayMenu();
		character1Choice = integerCheck(1, characterMenu.getVectorSize());
		switch (character1Choice)
		{
		case 1:
			char1 = new Vampire();
			break;
		case 2:
			char1 = new Barbarian();
			break;
		case 3:
			char1 = new BlueMen();
			break;
		case 4:
			char1 = new Medusa();
			break;
		case 5:
			char1 = new HarryPotter();
			break;
		default:
			char1 = new Vampire();
			break;
		}

		//for user to pick second character
		std::cout << "What would you like the second character to be? " << std::endl;
		characterMenu.displayMenu();
		character2Choice = integerCheck(1, characterMenu.getVectorSize());
		switch (character2Choice)
		{
		case 1:
			char2 = new Vampire();
			break;
		case 2:
			char2 = new Barbarian();
			break;
		case 3:
			char2 = new BlueMen();
			break;
		case 4:
			char2 = new Medusa();
			break;
		case 5:
			char2 = new HarryPotter();
			break;
		default:
			char2 = new Vampire();
			break;
		}


		//while loop for each round of battle
		//will exit loop if either characters' strength drops below 0
		int damageTaken;
		int defenderHealth = char2->getRemainingStrength();
		while (char1->getRemainingStrength() > 0 && char2->getRemainingStrength() > 0)
		{
			//character 1 attacks while character 2 defends 
			if (char1->getRemainingStrength() > 0)
			{
				std::cout << "1. " << char1->getCharacterType() << " is attacking " << std::endl;
				std::cout << "2. " << char2->getCharacterType() << ", armor of " << char2->getArmor()
					<< ", strength of " << char2->getRemainingStrength() << std::endl;

				char1->attackRoll();
				char2->defenseRoll();
				damageTaken = char2->calcDamageTaken(char1->getAttack());
				char2->updateStrength(damageTaken);

				std::cout << "3. Attack roll was " << char1->getAttack() << std::endl;
				std::cout << "4. Defense roll was " << char2->getDefense() << std::endl;
				std::cout << "5. Damage taken was " << damageTaken << std::endl;
				std::cout << "6. " << char2->getCharacterType() << " has " << char2->getRemainingStrength()
					<< " remaining strength." << std::endl << std::endl;
			}

			//character two attacks while character 1 defends if character 2 still has health
			if (char2->getRemainingStrength() > 0)
			{
				

				std::cout << "1. " << char2->getCharacterType() << " is attacking " << std::endl;
				std::cout << "2. " << char1->getCharacterType() << ", armor of " << char1->getArmor()
					<< ", strength of " << char1->getRemainingStrength() << std::endl;

				char2->attackRoll();
				char1->defenseRoll();
				damageTaken = char1->calcDamageTaken(char2->getAttack());
				char1->updateStrength(damageTaken);

				std::cout << "3. Attack roll was " << char2->getAttack() << std::endl;
				std::cout << "4. Defense roll was " << char1->getDefense() << std::endl;
				std::cout << "5. Damage taken was " << damageTaken << std::endl;
				std::cout << "6. " << char1->getCharacterType() << " has " << char1->getRemainingStrength()
					<< " remaining strength." << std::endl << std::endl;
			}
			

			//displays winner and deletes charactes that were dynamically allocated
			if (char1->getRemainingStrength() <= 0 || char2->getRemainingStrength() <= 0)
			{
				if (char1->getRemainingStrength() <= 0)
				{
					std::cout << char1->getCharacterType() << " has lost to " << char2->getCharacterType() << std::endl;
				}
				else
				{
					std::cout << char2->getCharacterType() << " has lost to " << char1->getCharacterType() << std::endl;
				}
				delete char1;
				delete char2;
				std::this_thread::sleep_for(std::chrono::milliseconds(200));
			}
		}
		continueMenu.displayMenu();
		continueChoice = integerCheck(1, 2);
	}

	
	return 0;
}