//Tester file for CodewordGenerator class

#include <string>
#include <regex>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include "CodewordGenerator.hpp"


int main()
{
	std::string a = "[A-Z]+BB[Y-Z]+";
	//first one should be ABBY
	std::string b = "[C-M]+[A-Y]+[G-O]*B";
	//should be NMJ
	CodewordGenerator mygen;
	std::string answer;
	std::string answer2;
	answer = mygen.generateShortestWord(a);
	std::cout<<answer<<std::endl;
	answer2= mygen.generateLengthWord(b, 3);
	std::cout<<answer2<<std::endl;

return 0;

}
