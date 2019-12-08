#include "CodewordGenerator.hpp"
#include <regex>
#include <stack>
#include <queue>
#include <vector>

/*Default Constructor for CodewordGenerator 

@post: Private member vector<string> v is populated
with uppercase letters A-Z

*/ 
CodewordGenerator::CodewordGenerator()
{
	v.push_back("A");
	v.push_back("B");
	v.push_back("C");
	v.push_back("D");
	v.push_back("E");
	v.push_back("F");
	v.push_back("G");
	v.push_back("H");
	v.push_back("I");
	v.push_back("J");
	v.push_back("K");
	v.push_back("L");
	v.push_back("M");
	v.push_back("N");
	v.push_back("O");
	v.push_back("P");
	v.push_back("Q");
	v.push_back("R");
	v.push_back("S");
	v.push_back("T");
	v.push_back("U");
	v.push_back("V");
	v.push_back("W");
	v.push_back("X");
	v.push_back("Y");
	v.push_back("Z");

}

/*
Letters in our vector are iteratively pushed onto a queue
and after they are all pushed, are popped one by one, and each letter of the
vector is appended to it. This process repeats until the pattern is satisfied.

This effectively performs a Breadth First Search of the expression pattern
thats passed as a parameter and returns the shortest string that satisfies
the expression pattern.

@parameters: string which contains a proper regular expression pattern
*/
std::string CodewordGenerator::generateShortestWord(std::string pattern)
{
	std::regex re(pattern);
	std::queue<std::string> myq;

	std::string curr_str;
	std::string z = ""; 
	myq.push(z); 						//push empty string on queue
	while (!myq.empty())
	{
		curr_str = myq.front(); 			//temporary string gets the first element

		if(std::regex_match(curr_str, re)) 
		{
			return curr_str; 			//if we find the match, return it
		}
		else
		{
			for (int i = 0; i<v.size(); i++) 	//otherwise iteratively populate queue
			{
				curr_str = curr_str + v[i]; 	//append
				myq.push(curr_str); 		//push back onto queue
				curr_str= myq.front(); 		//reset string to be previous value, otherwise 
								//during next pass we append the wrong letter

			}
		}
		myq.pop();					//finally, pop the element, so we can repeat.

	}
}

/*
Letters in our vector are iteratively pushed onto a stack. After they are all pushed, 
are popped one by one, and each letter of the vector is appended to it. 
This process repeats until the pattern is found of the given length parameter.

This effectively performs a Depth First Search of the expression pattern
thats passed as a parameter and returns the string with length "length" that satisfies
the expression pattern.

Here, the algorithms are similar but the bahavior is drastically different
when we switch between using a stack vs using a queue. 

@parameters: string which contains a proper regular expression pattern and a integer length
*/
std::string CodewordGenerator::generateLengthWord(std::string pattern, int length)
{  	
	std::regex de(pattern);

	std::stack<std::string> mys;
	std::string curr_str2;
	std::string y = "";
	mys.push(y);
	while (!mys.empty())
	{
		curr_str2 = mys.top();
		mys.pop();

		if (curr_str2.length()<length)									
		{
			for (int i = 0; i<v.size(); i++)		
			{
				std::string append;
				append = curr_str2 + v[i]; 								
				mys.push(append);										
				append= mys.top();										

			}
		}
		else 												
		{													
			if (std::regex_match(curr_str2, de)==false)		//this branch is new--once we have a sequence of the length
			{							//we want, if it doesn't match, we don't care about it--pop it.
				mys.pop();
			}
			else if (std::regex_match(curr_str2, de)==true)		//else, we are at the length we want, and we return the
			{							//string
				return curr_str2;
			}
		}
	}
}
