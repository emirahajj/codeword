# Codeword Generator

A C++ program which produces a 'codeword' (permutation of capital letters A-Z) that matches a given regular expression.

-----
In this program, we take create a CodewordGenerator class which contains two public methods:

**generateShortestWord** which takes in a string parameter and returns the shortest string that matches the pattern in Breadth First Search order utilizing a queue.

**generateLengthWord** which takes in a string parameter and an integer parameter
and returns a string of that length that matches the pattern in Depth First Search order utilizing a stack.

Limitations:
The only characters in the "alphabet" are upper case letters {A, B, C, ... , Z} so the only characters that should appear in 
the regular expression are letters A-Z.

Since our alphabet has 26 letters, our queue and stack grow quickly each time we pop, append letters and push. Because of this, the lengths of the codewords should be relatively short when testing with Depth First Search to avoid strain on memory.
*/
