#include <iostream>
//pour les nombres aléatoires
#include <ctime>
#include <random>


void setValues(int& n1, int& n2, int& answer, std::mt19937& rng)
{
	std::uniform_int_distribution<std::mt19937::result_type> dist(0, 10); //une distribution de nb aléatoires

	n1 = dist(rng) + 1;  //pour pas avoir 0, mais plutot 10
	n2 = dist(rng) + 1;
	answer = n1 * n2;
}

unsigned int safeInput()
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
		return NULL;
	}
}


int main()
{
	std::random_device rdmDevice; //un objet qui sert à obtenir l'entropie aléatoire du système
	std::mt19937 rng(rdmDevice()); //le générateur de nb aléatoire → initialisé avec rdmDevice qui sert de graine
	

	int number(0); //le numéro de question
	int answer(0); //reponse de la question
	int memberOne(0), memberTwo(0); //variable qui contiendront les deux facteurs
	int userAnswer(0); //pour les entrés de l'utilisateur
	int correctAnswer(0);
	double startTime(time(0));

	std::cout << "Bienvenue dans ce programme de revision des tables de multiplication !" << std::endl << std::endl;


	for (number; number < 10; number++)
	{
		setValues(memberOne, memberTwo, answer, rng);
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


	/*
	score : (correcte % temps) x 10
	*/

	double score(0);
	double timeU(0);

	timeU = time(0) - startTime;
	score = (correctAnswer / timeU) * 100;
	std::cout << "Tu as eu " << score << " points !" << std::endl;

	//std::cout << "Tu as repondu correctement a " << correctAnswer << " questions en " << timeU << " secondes" << std::endl;

	return 0;
}