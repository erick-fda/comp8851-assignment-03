/**
 *  Inserts the given item into the binary heap 
 *  by making a copy rather than moving data.
*/
void insert(const Comparable& item)
{
    /* Double the array's size if it is full. */
    if (currentSize == array.size() - 1)
    {
        array.resize(array.size() * 2);
    }

    int hole == ++currentSize;
    array[0] = item;    /* NOTE: Making a copy rather than moving data. */

    /* Percolate up. */
    for ( ; item < array[hole/2]; hole /= 2)
    {
        array[hole] = std::move(array[hole/2]);
    }

    array[hole] = array[0]  /* NOTE: array[0] retains a copy. */
}