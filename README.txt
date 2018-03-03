==========================================================================================
    COMP 8851 Assignment 03
    
    Copyright 2018 Erick Fernandez de Arteaga. All rights reserved.
        https://www.linkedin.com/in/erick-fda
        https://github.com/erick-fda
        https://bitbucket.org/erick-fda
    
==========================================================================================

------------------------------------------------------------------------------------------
    TABLE OF CONTENTS
    
    ## Question Responses
    
------------------------------------------------------------------------------------------

==========================================================================================
    ## Question Responses
==========================================================================================
1.)---------------------------------------------------------------------------------------
    My response to this question can be found at
        ./COMP8851_Asg03_A00925871/Question01/CopyInsert.cpp

2.)---------------------------------------------------------------------------------------
    The running time of heapsort for presorted input is O(NlogN). This is 
    because creating the binary heap has O(N) running time; and a deleteMin or deleteMax 
    operation on the heap takes O(logN) time, and must be performed N times.

    The important thing to note is that heapsort's running time is NOT affected one way 
    or the other by having presorted input.

3.)---------------------------------------------------------------------------------------
    As per the textbook, rehasing to make the table roughly twice as large is an O(N) 
    operation, but because it needs to be preceded (and, in a sense, triggered) by 
    roughly N/2 insertions, it is equivalent in the long term to adding a constant 
    running time cost to each insertion.

    We should follow similar logic for deciding when to rehash and make the table smaller. 
    If the table is to be made about half as large, then we should rehash when the table 
    is about half empty (that is, when there are roughly half as many elements as the 
    size of the table and the load factor is roughly 0.5).
    
    This means that at the time a rehash to a smaller table occurs, there will have been 
    roughly N/2 deletions since the last rehash. This means that the the cost of 
    rehashing to a smaller table in the long term will be similar to adding a constant 
    cost to each deletion.

4.)---------------------------------------------------------------------------------------
    My response to this question can be found at
        ./COMP8851_Asg03_A00925871/Question04/

5.)---------------------------------------------------------------------------------------
    My response to this question can be found at
        ./COMP8851_Asg03_A00925871/Question05/

6.)---------------------------------------------------------------------------------------
    My source code for this question can be found at
        ./COMP8851_Asg03_A00925871/Question06/

    The executable at 
        
        ./COMP8851_Asg03_A00925871/Debug/Question06.exe

    can be run without arguments. This program runs a test of the CuckooHashTable class, 
    demonstrating the functionality of its methods.

7.)---------------------------------------------------------------------------------------
    Place the N players in a "roster" array of size N.

    Make a two-dimensional array for the tournament schedule with N-1 rows and N columns. 
    Each row represents a day of the tournament and each cell in the row represents the 
    opponent to be faced by the player with that cell's index on that day.

    For each iteration of the algorithm (i.e., each day in the tournament), fill out a 
    day in the tournament schedule. Make each player with index i < N/2 in the roster 
    play against the player with index N-(1+i) on this day.

    Then remove the last item in the roster array, move all items with indeces > 0 to the 
    right by one, and reinsert the previously last element at index 1. Pass the new roster 
    array to the next iteration of the recursive algorithm.
    
    Once a depth of N-1 is reached, return, folding up through the recursive calls to the 
    original. The two-dimensional schedule array will now be filled with the schedule 
    data for the entire tournament.

    My source code for this question can be found at
        ./COMP8851_Asg03_A00925871/Question07/Question07.cpp

    The executable at 
        
        ./COMP8851_Asg03_A00925871/Debug/Question07.exe

    can be run by providing a single command-line argument for k. So if 3 is given as the 
    argument, for example, a tournament schedule for 8 (2^k) players will be generated. 
    
    Note that since the program prints the two-dimensional schedule array, the output may 
    become oddly formatted on a small window if the given k is large. Enlarge the window 
    or decrease the text size if necessary.

8.)---------------------------------------------------------------------------------------
    My response to this question can be found at
        ./COMP8851_Asg03_A00925871/Question08/
    