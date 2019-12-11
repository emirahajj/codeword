/*
Author: Emira Hajj

In this program, we take create a CodewordGenerator
class which countains two public methods:

generateShortestWord which takes in a string parameter and returns the shortest
string that matches the pattern in Breadth First Search order utilizing a queue.

generateLengthWord which takes in a string parameter and an integer parameter
and returns a string of that length that matches the pattern in Depth First Search order utilizing a stack.

Limitations:

the only characters in the "alphabet" are upper case letters
{A, B, C, ... , Z} so the only characters that should appear in 
the regular expression should be A-Z.

Since our alphabet has 26 letters, our queue and stack grow quickly
each time we pop, append letters and push. Because of this, the lengths of 
the codewords should be relatively short when testing with Depth First Search to avoid strain on memory.
*/

#ifndef CODEWORDGENERATOR_H_
#define CODEWORDGENERATOR_H_

#include <string>
#include <iostream>
#include <regex>

class CodewordGenerator
{
public:
	/*Default Constructor for CodewordGenerator 
	@post: Private member vector<string> v is populated with uppercase letters A-Z
	*/ 
	CodewordGenerator();
	/*
	generateShortestWord method:
	@parameter: string which contains a proper regular expression pattern
	@return: shortest string that matches regex pattern in Breadth First Search order
	*/
	std::string generateShortestWord(std::string pattern);
	/*
	generateLengthWord method:
	@parameters: 
	string which contains a proper regular expression pattern
	integer which represents the length of the pattern to return
	@return: string of length length that matches regex pattern
	*/
	std::string generateLengthWord(std::string pattern, int length);


private:
	/*
	A vector that stores strings to represent our alphabet. 
	*/
	std::vector<std::string> v;

};
#endif
