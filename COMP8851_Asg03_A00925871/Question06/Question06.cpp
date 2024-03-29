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

	cout << "Beginning CuckooHashTable test...\n\n";

	cout << "Creating CuckooHashTable...\n\n";

	CuckooHashTable<string, StringHashFamily<2>> table = CuckooHashTable<string, StringHashFamily<2>>();

	/* Test Insert(). */
	cout << "Inserting strings \"snap\", \"crackle\", and \"pop\"...\n";
	if (table.Insert("snap"))
	{
		cout << "\"snap\" inserted.\n";
	}
	else
	{
		cout << "ERROR: Could not insert \"snap\".\n";
		return 1;
	}

	if (table.Insert("crackle"))
	{
		cout << "\"crackle\" inserted.\n";
	}
	else
	{
		cout << "ERROR: Could not insert \"crackle\".\n";
		return 1;
	}

	if (table.Insert("pop"))
	{
		cout << "\"pop\" inserted.\n\n";
	}
	else
	{
		cout << "ERROR: Could not insert \"pop\".\n";
		return 1;
	}

	/* Test Insert() with duplicate. */
	cout << "Attempting to insert duplicate \"pop\" element...\n";
	if (!table.Insert("pop"))
	{
		cout << "Did not insert duplicate element.\n\n";
	}
	else
	{
		cout << "ERROR: Inserted duplicate \"pop\" element.\n";
		return 1;
	}

	/* Test Find() and Contains(). */
	cout << "Verifying prescence of key \"crackle\" in hash table...\n";
	if (table.Contains("crackle"))
	{
		cout << "Table contains \"crackle\".\n\n";
	}
	else
	{
		cout << "ERROR: Table did not contain element \"crackle\" after it was inserted.\n";
		return 1;
	}

	/* Test Remove(). */
	cout << "Removing strings \"snap\", \"crackle\", and \"pop\"...\n";
	if (table.Remove("snap"))
	{
		cout << "\"snap\" removed.\n";
	}
	else
	{
		cout << "ERROR: Could not remove \"snap\".\n";
		return 1;
	}

	if (table.Remove("crackle"))
	{
		cout << "\"crackle\" removed.\n";
	}
	else
	{
		cout << "ERROR: Could not remove \"crackle\".\n";
		return 1;
	}

	if (table.Remove("pop"))
	{
		cout << "\"pop\" removed.\n\n";
	}
	else
	{
		cout << "ERROR: Could not remove \"pop\".\n";
		return 1;
	}

	/* Test Remove() on non-existent element. */
	cout << "Attempting to remove string \"snap\" when it is no longer in the table...\n";
	if (!table.Remove("snap"))
	{
		cout << "\"snap\" was correctly not found and not removed.\n\n";
	}
	else
	{
		cout << "ERROR: Non-existent element \"snap\" was (somehow) removed.\n";
		return 1;
	}

	cout << "SUCCESS: CuckooHashTable test completed successfully.\n\n";

	cout << "Press Enter to quit...\n";
	cin.ignore();
	return 0;
}
