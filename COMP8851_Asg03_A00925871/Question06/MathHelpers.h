/*========================================================================================
	MathHelpers

	Helper functions for mathematical operations.
    
    Copyright 2018 Erick Fernandez de Arteaga. All rights reserved.
        https://www.linkedin.com/in/erick-fda
        https://github.com/erick-fda
        https://bitbucket.org/erick-fda
	
========================================================================================*/

#pragma once

/*========================================================================================
	Dependencies
========================================================================================*/


/*========================================================================================
	MathHelpers	
========================================================================================*/
namespace MathHelpers
{
    /*----------------------------------------------------------------------------------------
		Public Functions
    ----------------------------------------------------------------------------------------*/
    /**
		Returns whether the given int is a prime number.
	*/
	bool IsPrime(int num)
	{
		if (num == 2 || 
			num == 3)
		{
			return true;
		}

		if (num % 2 == 0 ||
			num % 3 == 0)
		{
			return false;
		}

		int divisor = 6;
		while ((divisor * divisor) - (2 * divisor) + 1 <= num)
		{
			if (num % (divisor - 1) == 0)
			{
				return false;
			}

			if (num % (divisor + 1) == 0)
			{
				return false;
			}

			divisor += 6;
		}

		return true;
	}

	/**
		Returns the next prime number starting at the given number and searching upwards.
	*/
	int NextPrime(int num)
	{
		while (!IsPrime(num))
		{
			++num;
		}

		return num;
	}

    /*----------------------------------------------------------------------------------------
		Private Functions
    ----------------------------------------------------------------------------------------*/

};
