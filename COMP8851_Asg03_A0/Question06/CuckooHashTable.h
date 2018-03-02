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


    /*----------------------------------------------------------------------------------------
		Resource Management
    ----------------------------------------------------------------------------------------*/
    public:
        /** Default constructor. */
		explicit CuckooHashTable()
		{}

		explicit CuckooHashTable(int size)
		{}

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
		void Clear();
		
		bool Contains(const T& key) const;

		bool Remove(const T& key);

		bool Insert(const T& key);

		bool Insert(T&& key);

    private:

};
