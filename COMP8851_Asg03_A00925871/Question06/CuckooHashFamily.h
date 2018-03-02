/*========================================================================================
	CuckooHashFamily
	
	Interface for a class that generates cuckoo hash functions for a specific data type.
    
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
	CuckooHashFamily	
========================================================================================*/
template <typename T>
class CuckooHashFamily
{
    /*----------------------------------------------------------------------------------------
		Instance Fields
    ----------------------------------------------------------------------------------------*/
    private:


    /*----------------------------------------------------------------------------------------
		Resource Management
    ----------------------------------------------------------------------------------------*/
    public:
        /** Default constructor. */
        explicit CuckooHashFamily() = default;

        /** Copy constructor. */
		CuckooHashFamily(const CuckooHashFamily& rhs) = delete;

        /** Move constructor. */
		CuckooHashFamily(CuckooHashFamily&& rhs) = delete;

        /** Destructor. */
        ~CuckooHashFamily() = default;

        /** Copy assignment. */
        CuckooHashFamily& operator=(const CuckooHashFamily& rhs) = delete;

        /** Move assignment. */
        CuckooHashFamily& operator=(CuckooHashFamily&& rhs) = delete;

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
		size_t Hash(const T& key, int functionIndex) const = 0;
		int NumFunctions() = 0;
		void GenerateFunctions() = 0;

    private:

};
