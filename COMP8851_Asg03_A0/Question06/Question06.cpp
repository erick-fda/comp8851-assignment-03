/*========================================================================================
	Question 06
	
	Demonstrates a basic cuckoo hash table implementation with int hashing.
    
    Copyright 2018 Erick Fernandez de Arteaga. All rights reserved.
        https://www.linkedin.com/in/erick-fda
        https://github.com/erick-fda
        https://bitbucket.org/erick-fda
	
========================================================================================*/

/*========================================================================================
	Dependencies
========================================================================================*/
#include <iostream>
#include <string>
#include "StringHashFamily.h"
#include "CuckooHashTable.h"

using std::cout;
using std::cin;
using std::string;

/*========================================================================================
	Constants
========================================================================================*/
const string HORIZONTAL_RULE = "--------------------------------------------------------";

/*========================================================================================
	Functions
========================================================================================*/


/*========================================================================================
	Main Function
========================================================================================*/
int main()
{
	cout << HORIZONTAL_RULE << "\n\t" << "Question 06\n" << HORIZONTAL_RULE << "\n\n";

	StringHashFamily<2> fam = StringHashFamily<2>();
	CuckooHashTable<string, StringHashFamily<2>> table = CuckooHashTable<string, StringHashFamily<2>>();

	cout << "Press any key to quit...\n";
	cin.ignore();
	return 0;
}
