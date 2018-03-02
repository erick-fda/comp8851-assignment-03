/*========================================================================================
	CuckooHashTable
	
	A basic cuckoo hash table implementation.
    
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
#include <random>
#include "MathHelpers.h"
#include "CuckooHashFamily.h"

using std::vector;

/*========================================================================================
	CuckooHashTable	
========================================================================================*/
template <typename T, typename HashFamily>
class CuckooHashTable
{
	struct HashTuple
	{
		T _item;
		bool _isActive;

		/* Default constructor. */
		HashTuple(const T& item = T(), bool isActive = false) :
			_item{ item }, _isActive{ isActive }
		{}

		/** Pseudo-move constructor. */
		HashTuple(T&& item, bool isActive = false) :
			_item{ std::move(item) }, _isActive{ isActive }
		{}
	};

    /*----------------------------------------------------------------------------------------
		Instance Fields
    ----------------------------------------------------------------------------------------*/
    private:
		static const int DEFAULT_SIZE;
		static const float MAX_LOAD_FACTOR;
		static const int MAX_REHASHES;
		
		vector<HashTuple> _array;
		HashFamily _hashFunctions;
		int _size;
		int _numHashFunctions;
		int _rehashCount;

		std::mt19937 _randomGenerator;
		std::uniform_int_distribution<int> _distribution;

    /*----------------------------------------------------------------------------------------
		Resource Management
    ----------------------------------------------------------------------------------------*/
    public:
        /** Default constructor. */
		explicit CuckooHashTable() :
			CuckooHashTable(DEFAULT_SIZE)
		{}

		explicit CuckooHashTable(int size) :
			_array{ vector<HashTuple>(MathHelpers::NextPrime(size)) }, 
			_hashFunctions{ HashFamily() }, 
			_rehashCount{ 0 }
		{
			_size = _array.size();
			_numHashFunctions = _hashFunctions.NumFunctions();
			Clear();
		}

        /** Copy constructor. */
        CuckooHashTable(const CuckooHashTable& rhs) = delete;

        /** Move constructor. */
        CuckooHashTable(CuckooHashTable&& rhs) = default;

        /** Destructor. */
        ~CuckooHashTable() = default;

        /** Copy assignment. */
        CuckooHashTable& operator=(const CuckooHashTable& rhs) = delete;

        /** Move assignment. */
        CuckooHashTable& operator=(CuckooHashTable&& rhs) = delete;

	/*----------------------------------------------------------------------------------------
		Instance Getter Methods
    ----------------------------------------------------------------------------------------*/
    public:
        
    
	/*----------------------------------------------------------------------------------------
		Instance Setter Methods
	----------------------------------------------------------------------------------------*/
    public:


	/*----------------------------------------------------------------------------------------
		Instance Methods
	----------------------------------------------------------------------------------------*/
    public:
		/**
			Removes all elements from the hash table.
		*/
		void Clear()
		{
			_size = 0;
			for (auto& eachItem : _array)
			{
				eachItem._isActive = false;
			}
		}
		
		bool Contains(const T& key) const
		{
			return false;
		}

		bool Remove(const T& key)
		{
			return false;
		}

		bool Insert(const T& key)
		{
			return false;
		}

		bool Insert(T&& key)
		{
			return false;
		}

    private:
		bool StandardInsert(const T& key)
		{
			return false;
		}

		bool MoveInsert(T&& key)
		{
			return false;
		}

		bool IsActive(int index) const
		{
			return false;
		}

		size_t Hash(const T& key, int tableIndex) const
		{
			return 0;
		}

		int Find(const T& key) const
		{

		}

		void Expand()
		{

		}

		void Rehash()
		{

		}

		void Rehash(int newSize)
		{

		}
};

/*----------------------------------------------------------------------------------------
	Static Fields
----------------------------------------------------------------------------------------*/
template <typename T, typename HashFamily>
const int CuckooHashTable<T, HashFamily>::DEFAULT_SIZE = 101; 

template <typename T, typename HashFamily>
const float CuckooHashTable<T, HashFamily>::MAX_LOAD_FACTOR = 0.4f;

template <typename T, typename HashFamily>
const int CuckooHashTable<T, HashFamily>::MAX_REHASHES = 5;
