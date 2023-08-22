#ifndef fileFunction_H_INCLUDED
#define fileFunction_H_INCLUDED
#include <string>

double getBestScore();
bool writeScore(double score, std::string name);
std::string getName();
void resetFile();

#endif // !fileFunction_H_INCLUDED