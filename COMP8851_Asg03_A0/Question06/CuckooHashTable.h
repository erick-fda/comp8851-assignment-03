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
	/**
		Struct for a single item in the hash table.
	*/
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
		static const int MAX_REHASHES_BEFORE_EXPANDING;
		
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
			_size{ 0 },
			_rehashCount{ 0 }
		{
			_numHashFunctions = _hashFunctions.NumFunctions();
			Clear();

			std::random_device random;
			_randomGenerator = std::mt19937(random());
			_distribution = std::uniform_int_distribution<int>(0, INT_MAX);
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
		
		/**
			Returns whether the hash table contains the given key.
		*/
		bool Contains(const T& key) const
		{
			return Find(key) > -1;
		}

		/**
			Removes the given item from the hash table if it exists.

			Returns true if the item was removed and false otherwise.
		*/
		bool Remove(const T& key)
		{
			int index = Find(key);

			if (!IsActive(index))
			{
				return false;
			}

			/* Remove the item. */
			_array[index]._isActive = false;
			--_size;
			return true;
		}

		/**
			Inserts the given key into the table by copying it if it does not already exist.
			Returns true if the key was removed and false otherwise.
		*/
		bool Insert(const T& key)
		{
			if (Contains(key))
			{
				return false;
			}

			/* Enlarge the hash table if the max load factor has been exceeded. */
			if (_size >= _array.size() * MAX_LOAD_FACTOR)
			{
				Expand();
			}

			return StandardInsert(key);
		}
		
		/**
			Inserts the given key into the table using move semantics 
			if it does not already exist.
			
			Returns true if the key was removed and false otherwise.
		*/
		bool Insert(T&& key)
		{
			if (Contains(key))
			{
				return false;
			}

			/* Enlarge the hash table if the max load factor has been exceeded. */
			if (_size >= _array.size() * MAX_LOAD_FACTOR)
			{
				Expand();
			}

			return MoveInsert(key);
		}

    private:
		/**
			Inserts the given key into the table by copying it.
		*/
		bool StandardInsert(const T& key)
		{
			const int MAX_DISPLACEMENTS = 100;
			T keyCopy = key;

			while (true)
			{
				int lastIndex = -1;
				int index = 0;

				/* For each attempt... */
				for (int attempt = 0; attempt < MAX_DISPLACEMENTS; ++attempt)
				{
					/* For each hash function... */
					for (int i = 0; i < _numHashFunctions; ++i)
					{
						index = Hash(keyCopy, i);

						/* If the key index is not occupied, place the key there. */
						if (!IsActive(index))
						{
							_array[index] = std::move(HashTuple(std::move(key), true));
							++_size;
							return true;
						}
					}

					/* None of the hash indeces for this key are available. 
						Make like a cuckoo bird and push one out. */
					int i = 0;
					do
					{
						int hashToUse = _distribution(_randomGenerator) % _numHashFunctions;
						index = Hash(keyCopy, hashToUse);
					}
					while (index == lastIndex && i++ < 5);	/* Try at most 5 different hash functions 
																to find a next index different from the previous index. */

					lastIndex = index;
					std::swap(keyCopy, _array[index]._item);
				}

				/* If the alloted number of rehashes has been exceeded, expand the hash table. */
				if (_rehashCount > MAX_REHASHES_BEFORE_EXPANDING)
				{
					Expand();
					_rehashCount = 0;
				}
				/* If the item to be inserted could not be inserted within the alloted
					number of displacements, generate new hash functions. */
				else
				{
					Rehash();
				}
			}
		}

		/**
			Inserts the given key into the table using move semantics.
		*/
		bool MoveInsert(T&& key)
		{
			StandardInsert(std::move(key));
		}

		/**
			Returns whether the tuple at the given index is active.
		*/
		bool IsActive(int index) const
		{
			return _array[index]._isActive;
		}

		/**
			Returns the hash value for a given key.
		*/
		size_t Hash(const T& key, int tableIndex) const
		{
			return _hashFunctions.Hash(key, tableIndex) % _array.size();
		}

		/**
			Searches the hash table for the given key.
			Returns the key's index if it is found and a negative int otherwise.
		*/
		int Find(const T& key) const
		{
			/* Check each hash. */
			for (int i = 0; i < _numHashFunctions; ++i)
			{
				int searchIndex = Hash(key, i);
				
				/* If the tuple is active and contains the right value, return its index. */
				if (IsActive(searchIndex) &&
					_array[searchIndex].item == key)
				{
					return searchIndex;
				}
			}

			return -1;
		}

		/**
			Enlarges the hash table and rehashes its keys.
		*/
		void Expand()
		{
			Rehash(static_cast<int>(_array.size() / MAX_LOAD_FACTOR));
		}

		/**
			Generates new hash functions and rehashes keys 
			without increasing the table size.
		*/
		void Rehash()
		{
			_hashFunctions.GenerateFunctions();
			Rehash(_array.size());
		}

		/**
			Enlarges the hash table and rehashes keys.
			
			The new size of the table will be the lowest prime number 
			greater than or equal to the suggested size.
		*/
		void Rehash(int suggestedSize)
		{
			vector<HashTuple> oldArray = _array;
			_array.resize(MathHelpers::NextPrime(suggestedSize));

			/* Remove all items from the array. */
			for (auto& eachTuple : _array)
			{
				eachTuple._isActive = false;
			}

			_size = 0;

			/* Insert only active items from the copy of the old array into the new array. 
				Note that items marked as inactive before Rehash() was called will be lost. */
			for (auto& eachTuple : oldArray)
			{
				if (eachTuple._isActive)
				{
					Insert(std::move(eachTuple._item));
				}
			}
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
const int CuckooHashTable<T, HashFamily>::MAX_REHASHES_BEFORE_EXPANDING = 5;
