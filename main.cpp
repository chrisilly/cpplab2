#include <iostream>
#include "main.h"

using namespace std;

const int quantity = 100;
int numbers[quantity];

int main(int argc, const char* argv[])
{
    Program baymax;

//    int* primes = baymax.GetPrimes(quantity);
   
    // delete [] numbers;
}

/// @brief Extracts the prime numbers within a given (sorted) range of numbers.
/// @param upperBound Inclusive upper bound of the range from which to extract primes.
/// @param lowerBound Inclusive lower bound of the range from which to extract primes. Defaults to zero.
/// @return Array of primes within given range
int* Program::GetPrimes(int upperBound, int lowerBound = 0)
{
    // We only use positive numbers for this.
    if(lowerBound < 0)
        lowerBound *= -1;
    if(upperBound < 0)
        upperBound *= -1;

    // Check that the lowerBound is, in fact a __lower__ bound.
    // Swap the values in this case
    if(lowerBound > upperBound)
    {
        int swapper = lowerBound;
        lowerBound = upperBound;
        upperBound = swapper;
    }

    int size = upperBound - lowerBound;
    int* numbers = new int[size];
    bool* marked = new bool[size];

    for (int i = lowerBound; i <= upperBound; i++)
    {
        numbers[i] = i;
    }

    // Get rid of even numbers and 
    // for (int i = 0; i < size; i++)
    //     if(numbers[i] < 2 || numbers[i] % 2 == 0) 
    //         marked[i] = true;
    
    // Mark multiples
    for (int i = 0; i < size; i++)
    {
        // Don't bother marking multiples of non-primes
        if(marked[i] || numbers[i] < 2) continue;

        // Mark multiples
        for (int j = 2; numbers[i] * j <= size; j++)
        {
            marked[numbers[i]*j] = true;
        }
    }

    delete [] marked;
    delete [] numbers;
    
    return numbers;
}