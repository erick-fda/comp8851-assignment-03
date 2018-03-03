/*========================================================================================
	StringHashFamily
	
	Class for generating string hash functions for a cuckoo table.
    
    Copyright 2018 Erick Fernandez de Arteaga. All rights reserved.
        https://www.linkedin.com/in/erick-fda
        https://github.com/erick-fda
        https://bitbucket.org/erick-fda
	
========================================================================================*/

#pragma once

/*========================================================================================
	Dependencies
========================================================================================*/
#include <vector>
#include <string>
#include <random>

using std::vector;
using std::string;

/*========================================================================================
	StringHashFamily	
========================================================================================*/
template <int numFunctions>
class StringHashFamily
{
    /*----------------------------------------------------------------------------------------
		Instance Fields
    ----------------------------------------------------------------------------------------*/
    private:
		vector<int> _multipliers;
		std::mt19937 _randomGenerator;
		std::uniform_int_distribution<int> _distribution;

    /*----------------------------------------------------------------------------------------
		Resource Management
    ----------------------------------------------------------------------------------------*/
    public:
        /** Default constructor. */
		explicit StringHashFamily() :
			_multipliers(numFunctions)
		{
			std::random_device random;
			_randomGenerator = std::mt19937(random());
			_distribution = std::uniform_int_distribution<int>(0, INT_MAX);

			GenerateFunctions();
		}

        /** Copy constructor. */
        StringHashFamily(const StringHashFamily& rhs) = delete;

        /** Move constructor. */
        StringHashFamily(StringHashFamily&& rhs) = default;

        /** Destructor. */
        ~StringHashFamily() = default;

        /** Copy assignment. */
        StringHashFamily& operator=(const StringHashFamily& rhs) = delete;

        /** Move assignment. */
        StringHashFamily& operator=(StringHashFamily&& rhs) = delete;

	/*----------------------------------------------------------------------------------------
		Instance Getter Methods
    ----------------------------------------------------------------------------------------*/
    public:
		/**
			Returns how many hash functions this has family contains.
		*/
		int NumFunctions() const
		{
			return numFunctions;
		}
    
	/*----------------------------------------------------------------------------------------
		Instance Setter Methods
	----------------------------------------------------------------------------------------*/
    public:


	/*----------------------------------------------------------------------------------------
		Instance Methods
	----------------------------------------------------------------------------------------*/
    public:
		/**
			Generates new random multipliers to be used in the hash functions.
		*/
		void GenerateFunctions()
		{
			for (auto& eachMultiplier : _multipliers)
			{
				eachMultiplier = _distribution(_randomGenerator);
			}
		}

		/**
			Returns the hash value for a given key.
		*/
		size_t Hash(const string& key, int functionIndex) const
		{
			const int m = _multipliers[functionIndex];
			size_t hash = 0;

			for (auto eachChar : key)
			{
				hash = (m * hash) + eachChar;
			}

			return hash;
		}
};
