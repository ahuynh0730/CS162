/************************************

	By: Anthony Huynh
	Date: 11/18/2018
	Description: main file for fantasy combat tournament

************************************/

#include "Queue.hpp"
#include "Menu.hpp"
#include <iostream>
#include "inputValidation.hpp"
#include "Vampire.hpp"
#include "Character.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"

int main()
{
	Menu characterMenu;
	characterMenu.addOption("Vampire");
	characterMenu.addOption("Barbarian");
	characterMenu.addOption("Blue Men");
	characterMenu.addOption("Medusa");
	characterMenu.addOption("Harry Potter");

	Menu displayFinalFighterList;
	displayFinalFighterList.addOption("Yes");
	displayFinalFighterList.addOption("No");

	Menu playOption;
	playOption.addOption("Play (Again)");
	playOption.addOption("Exit");


	Queue team1;
	Queue team2;
	Queue losersPile;

	int amountFighters1;
	int amountFighters2;
	int characterChoice;
	int team1Points = 0;
	int team2Points = 0;
	int numberLosers = 0;
	std::string nameOfCharacter;

	playOption.displayMenu();
	int userPlayChoice = integerCheck(1, 2);
	while (userPlayChoice != 2)
	{
		

		//getting fighters and their names for team 1
		std::cout << "How many fighters on Team 1? ";
		amountFighters1 = integerCheck(1, 15);
		for (int i = 0; i < amountFighters1; i++)
		{
			std::cout << "What kind of fighter is fighter " << i + 1 << "?" << std::endl;
			characterMenu.displayMenu();
			characterChoice = integerCheck(1, 5);
			std::cout << "What is fighter " << i + 1 << "'s name? ";
			std::getline(std::cin, nameOfCharacter);
			std::cout << std::endl;
			switch (characterChoice)
			{
			case 1:
				team1.addToBack(new Vampire(nameOfCharacter));
				break;
			case 2:
				team1.addToBack(new Barbarian(nameOfCharacter));
				break;
			case 3:
				team1.addToBack(new BlueMen(nameOfCharacter));
				break;
			case 4:
				team1.addToBack(new Medusa(nameOfCharacter));
				break;
			case 5:
				team1.addToBack(new HarryPotter(nameOfCharacter));
				break;
			default:
				break;
			}

		}


		//getting fighters and their names for team 2
		std::cout << "How many fighters on Team 2? ";
		amountFighters2 = integerCheck(1, 15);
		for (int i = 0; i < amountFighters2; i++)
		{
			std::cout << "What kind of fighter is fighter " << i + 1 << "?" << std::endl;
			characterMenu.displayMenu();
			characterChoice = integerCheck(1, 5);
			std::cout << "What is fighter " << i + 1 << "'s name? ";
			std::getline(std::cin, nameOfCharacter);
			std::cout << std::endl;
			switch (characterChoice)
			{
			case 1:
				team2.addToBack(new Vampire(nameOfCharacter));
				break;
			case 2:
				team2.addToBack(new Barbarian(nameOfCharacter));
				break;
			case 3:
				team2.addToBack(new BlueMen(nameOfCharacter));
				break;
			case 4:
				team2.addToBack(new Medusa(nameOfCharacter));
				break;
			case 5:
				team2.addToBack(new HarryPotter(nameOfCharacter));
				break;
			default:
				break;
			}
		}


		//while loop that will keep a new battle going if either team still has fighters
		while (amountFighters1 != 0 && amountFighters2 != 0)
		{
			Character* char1 = team1.getFrontCharacter();
			Character* char2 = team2.getFrontCharacter();


			//while loop for each round of battle
			//will exit loop if either characters' strength drops below 0

			int damageTaken;
			int defenderHealth = char2->getRemainingStrength();
			while (char1->getRemainingStrength() > 0 && char2->getRemainingStrength() > 0)
			{
				//character 1 attacks while character 2 defends 
				if (char1->getRemainingStrength() > 0)
				{
					std::cout << "1. " << char1->getCharacterName() << " is attacking " << std::endl;
					std::cout << "2. " << char2->getCharacterName() << ", armor of " << char2->getArmor()
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


					std::cout << "1. " << char2->getCharacterName() << " is attacking " << std::endl;
					std::cout << "2. " << char1->getCharacterName() << ", armor of " << char1->getArmor()
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
					//if char from team 1 lost
					if (char1->getRemainingStrength() <= 0)
					{
						std::cout << char1->getCharacterName() << " has lost to " << char2->getCharacterName() << std::endl;
						std::cout << std::endl;
						losersPile.addToFront(&team1);
						team2.moveFrontToBack();
						numberLosers++;
						amountFighters1--;
						team1Points -= 1;
						team2Points += 2;
					}

					//if char from team 2 lost
					else
					{
						std::cout << char2->getCharacterName() << " has lost to " << char1->getCharacterName() << std::endl;
						std::cout << std::endl;
						losersPile.addToFront(&team2);
						team1.moveFrontToBack();
						numberLosers++;
						amountFighters2--;
						team1Points += 2;
						team2Points -= 1;
					}


					std::this_thread::sleep_for(std::chrono::milliseconds(200));
				}

			}
		}
		//displaying final score and winner
		std::cout << "Final score: " << team1Points << " to " << team2Points << "!" << std::endl;
		if (team1Points > team2Points)
		{
			std::cout << "Team 1 is the winner!" << std::endl;
		}
		else if (team1Points < team2Points)
		{
			std::cout << "Team 2 is the winner!" << std::endl;
		}
		else if (team1Points == team2Points)
		{
			std::cout << "This game is a tie!" << std::endl;
		}


		//asking if user wants to see who is left on both teams and the losing bracker
		std::cout << "Would you like to see remaining fighters and who lost?" << std::endl;
		displayFinalFighterList.displayMenu();
		int userDisplayChoice = integerCheck(1, 2);
		switch (userDisplayChoice)
		{
		case 1:
			std::cout << "Team 1:" << std::endl;
			team1.displayCharacterNames(amountFighters1);
			std::cout << std::endl;

			std::cout << "Team 2:" << std::endl;
			team2.displayCharacterNames(amountFighters2);
			std::cout << std::endl;

			std::cout << "Loser's pile:" << std::endl;
			losersPile.displayCharacterNames(numberLosers);
			std::cout << std::endl;
			
			break;
		case 2:
			break;
		default:
			break;
		}
		
		playOption.displayMenu();
		userPlayChoice = integerCheck(1, 2);

		//to restart before game is played again
		if (!team1.isEmpty())
		{
			team1.~Queue();
		}
		if (!team2.isEmpty())
		{
			team2.~Queue();
		}
		if (!losersPile.isEmpty())
		{
			losersPile.~Queue();
			numberLosers = 0;
		}
		team1Points = 0;
		team2Points = 0;
	
	}

	return 0;
}