#include <fstream>
#include <string>
#include <iostream>

double getBestScore()
{
	std::ifstream file("scores.txt");
	double bestScore(0);

	if (file) //on vérifie qu'on peut lire le fichier
	{

		double fileScore(0);
		std::string fileScoreString;
		std::getline(file, fileScoreString);
		fileScore = std::stoi(fileScoreString);

		return fileScore;
	}

	else //si c'est pas le cas, return NULL
	{
		return NULL;
	}
}

std::string getName()
{
	std::ifstream file("scores.txt");
	std::string line("");
	int counter(0);
	if (file)
	{
		while (std::getline(file, line))
		{
			if (counter == 1)
			{
				return line;
			}
			
			counter++;
		}
		
	}
	else
	{
		return NULL;
	}
	

}

std::string getDate()
{
	std::ifstream file("scores.txt");
	std::string line("");
	
	int counter(0);

	if (file)
	{
		while (std::getline(file, line))
		{
			if (counter == 2)
			{
				return line;
			}

			counter++;
		}
	}
}

bool writeScore(double score, std::string name, std::string date)
{
	std::ofstream file("scores.txt");

	if (file)
	{
		file << score << std::endl;;
		file << name << std::endl;
		file << date;
		return true;
	}

	else
	{
		return false;
	}

}

void resetFile()
{
	double defaultScore(0);
	std::string defaultName("username");

	std::ofstream file("scores.txt");
	if (file)
	{
		file << defaultScore << std::endl;
		file << defaultName;
	}
	else
	{
		std::cout << "Erreur !" << std::endl;
	}
}