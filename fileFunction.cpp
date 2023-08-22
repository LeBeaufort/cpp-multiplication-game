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
		file >> fileScore;

		if (!file) // si l'extraction ne s'est pas bien passée
		{
			return NULL;
		}
		else // si elle s'est bien passée on return
		{
			return fileScore;
		}
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
	if (file)
	{
		while (std::getline(file, line))
		{
			continue;
		}
		return line;
	}
	else
	{
		return NULL;
	}
	

}

bool writeScore(double score, std::string name)
{
	std::ofstream file("scores.txt");

	if (file)
	{
		file << score << std::endl;;
		file << name;
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