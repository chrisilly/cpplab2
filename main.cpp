#include <iostream>
#include "main.h"

using namespace std;

const int quantity = 13;
// int numbers[quantity];

int main(int argc, const char* argv[])
{
    Program baymax;

    // int *primes = baymax.GetPrimes(quantity, 2);
    // int primesCount = sizeof(primes) / sizeof(int);

    // std::cout << "Amount of primes found: " << primesCount << endl;

    // Print primes
    // for(int i = 0; i < sizeof(primes) / sizeof(int); i++)
    //     std::cout << primes[i] << " ";
    // std::cout << endl;

    // delete [] primes;

    int *primes = baymax.GetPrimes(quantity);

    baymax.PrintNumbers(primes);
}

#pragma region AttemptOne
/// @brief Extracts the prime numbers within a given range.
/// @param upperBound Inclusive upper bound of the range from which to extract primes.
/// @param lowerBound Inclusive lower bound of the range from which to extract primes. Defaults to zero.
/// @return Array of primes within given range
int* Program::GetPrimes(int upperBound, int lowerBound)
{
    // We only use positive numbers for this.
    if(upperBound <= 2)
        throw(new exception("Bad range."));
    if(lowerBound < 2)
        lowerBound = 2;

    // Check that the lowerBound is, in fact a __lower__ bound.
    // Swap the values in this case
    // if(lowerBound > upperBound)
    // {
    //     int swapper = lowerBound;
    //     lowerBound = upperBound;
    //     upperBound = swapper;
    // }

    int size = upperBound - lowerBound + 1;

    int *numbers = new int[size];
    bool *marked = new bool[size];

    for (int i = 0; i < size; i++)
    {
        numbers[i] = lowerBound + i;
        marked[i] = false;
    }

    // Get rid of even numbers and 
    // for (int i = 0; i < size; i++)
    //     if(numbers[i] < 2 || numbers[i] % 2 == 0) 
    //         marked[i] = true;
    
    // Mark multiples (non-primes)
    for (int i = 0; i < size; i++)
    {
        // Don't bother marking multiples of non-primes
        if(!marked[i])
        {
            // Mark multiples
            cout << "Found prime: " << numbers[i] << endl 
            << "Marked numbers: ";
            for (int j = numbers[i]; numbers[i] * j <= upperBound; j++)
            {
                marked[(numbers[i] * j)] = true;
                std::cout << (numbers[i] * j) << ", ";
            }
            cout << endl;
        }

        // cout << marked[i] << endl;
    }

    int primesCount = 0;
    for (int i = 0; i < size; i++)
    {
        if(marked[i] == false)
        {
            primesCount++;
            std::cout << "Primes: " << numbers[i] << ", ";
        }
    }

    std::cout << endl << "Prime count: " << primesCount << endl;

    int *primes = new int[primesCount];
    int j;
    for (int i = 0; primesCount <= 0; i++)
    {
        if(marked[i] == false)
        {
            j = primesCount % (primesCount + i);
            primes[(primesCount % (primesCount + i))] = numbers[i];
            primesCount--;
        }
    }

    // delete [] marked;
    // delete [] numbers;
    
    return primes;
}
#pragma endregion

/// @brief 
/// @param upperBound Inclusive upper bound; the last number to check
/// @return All prime values between 0 and the given upperBound
int* Program::GetPrimes(int upperBound)
{
    int size = upperBound + 1;
    int *numbers = new int[size];
    bool *marked = new bool[size];

    // Initialize numbers
    for (int i = 0; i < size; i++)
    {
        numbers[i] = i;
        marked[i] = false;
    }

    // Mark all non-primes
    for (int i = 0; i < size; i++)
    {
        if(numbers[i] < 2)
        {
            marked[i] = true;
        }

        if(!marked[i])
        {
            cout << "Found Prime: " << numbers[i] << endl;
            cout << "Marking multiples: ";

            for (int j = numbers[i]; numbers[i] * j <= upperBound; j++)
            {
                marked[i * j] = true;
                cout << i * j << ", ";
            }
            cout << endl;
        }
    }
    
    return numbers;
}

void Program::PrintNumbers(int *numbers)
{
    // int arraySize = sizeof(numbers)/sizeof(numbers[0]);
    // int numbersSize = sizeof(numbers);

    cout << "Numbers: ";
    for (int i = 0; i < 14; i++)
    {
        cout << numbers[i] << ", ";
    }
    cout << endl;
}