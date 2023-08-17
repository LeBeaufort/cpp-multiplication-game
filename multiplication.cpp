#include <iostream>
//pour les nombres aléatoires
#include <ctime>
#include <cstdlib>


void setValues(int& n1, int& n2, int& answer)
{
	n1 = std::rand() % 10 + 1;  //pour pas avoir 0, mais plutot 10
	n2 = std::rand() % 10 + 1;
	answer = n1 * n2;
}

int safeInput()
{
	int userInput(0);
	if (std::cin >> userInput)
	{
		return userInput;
	}
	else
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return -1;
	}
}

int main()
{
	srand(time(0)); //on donne une graine pour la generation, la graine utilisee est le l'heure actuelle

	int number(0); //le numéro de question
	int answer(0); //reponse de la question
	int memberOne(0), memberTwo(0); //variable qui contiendront les deux facteurs
	int userAnswer(0); //pour les entrés de l'utilisateur
	int correctAnswer(0);
	int startTime(time(0));

	std::cout << "Bienvenue dans ce programme de revision des tables de multiplication !" << std::endl << std::endl;


	for (number; number < 10; number++)
	{
		setValues(memberOne, memberTwo, answer);
		std::cout << "Question n" << number + 1 << ":" << std::endl;
		std::cout << "Combien font " << memberOne << "x" << memberTwo << " ?" << std::endl;

		std::cin.clear();
		userAnswer = safeInput(); //todo : pas avoir d"erreur" qui skip tout en oubliant les input quand on entre qqc qui n'est pas un nombre


		if (userAnswer == answer)
		{
			std::cout << "Bonne reponse !" << std::endl;
			correctAnswer++;
		}
		else
		{
			std::cout << "C'est une mauvaise reponse, tu devrai revoir tes tables !" << std::endl;
		}
	}

	std::cout << "Tu as repondu correctement a " << correctAnswer << " questions en " << time(0) - startTime << " secondes" << std::endl;



	return 0;
}