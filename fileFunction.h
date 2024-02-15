#ifndef fileFunction_H_INCLUDED
#define fileFunction_H_INCLUDED
#include <string>

double getBestScore();
bool writeScore(double score, std::string name, std::string date);
std::string getName();
void resetFile();
std::string getDate();

#endif // !fileFunction_H_INCLUDED