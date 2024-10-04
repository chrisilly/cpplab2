#include <iostream>
#include "main.h"
#include <cstring>

using namespace std;

const int quantity = 120;
const char *divider = "----------------------------------";
char *source = new char[19] {"crist that's crazy"};
char *goodFind = new char[4] {"cr"};
char *badFind = "cow";
char *replace = new char[4] {"kw"};
// int numbers[quantity];

int main(int argc, const char* argv[])
{
    Program baymax;

    int *primes = baymax.GetPrimes(quantity);

    baymax.PrintNumbers(primes);

    cout << divider << endl;

    // cout << "baymax.Contains(source, goodFind): 1 = ";
    // cout << baymax.Contains(source, goodFind) << endl;
    // cout << "baymax.Contains(source, badFind): 0 = ";
    // cout << baymax.Contains(source, badFind) << endl;

    // cout << divider << endl;

    cout << "String: " << source << endl;
    cout << "Find " << goodFind << " and replace with " << replace << "." << endl;
    baymax.Replace(source, goodFind, replace);
    cout << "New string: " << source << endl;
    
    cout << divider << endl;
}

/// @brief 
/// @param upperBound Inclusive upper bound; the last number to check
/// @return All prime values between 0 and the given upperBound
int* Program::GetPrimes(int upperBound)
{
    int size = upperBound + 1;
    int *numbers = new int[size];
    bool *marked = new bool[size];
    int primesCount = 0;

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
            primesCount++;

            for (int j = numbers[i]; numbers[i] * j <= upperBound; j++)
            {
                marked[i * j] = true;
                cout << i * j << ", ";
            }
            cout << endl;
        }
    }

    // gather all primes in one array
    int *primes = new int[primesCount];
    int j = 0;
    for (int i = 0; i < size; i++)
    {
        
        if(!marked[i])
        {
            primes[j] = numbers[i];
            // primesCount--;
            j++;
        }
    }

    delete[] numbers;
    delete[] marked;
    
    return primes;
}

void Program::PrintNumbers(int *numbers)
{
    // int arraySize = sizeof(numbers)/sizeof(numbers[0]);

    cout << "Numbers: ";
    for (int i = 0; i < 30; i++)
    {
        cout << numbers[i] << ", ";
    }
    cout << endl;
}

void Program::Replace(char *source, char *find, char *replace)
{
    int replaceLength = strlen(replace);
    int sourceLength = strlen(source);
    int findLength = strlen(find);

    int matchingLetters = 0;

    for (int i = 0; i < (sourceLength - findLength + 1); i++)
    {
        for (int j = 0; j < findLength; j++)
        {
            // As soon as the word substring doesn't match up with the targeted series of letters in the source string, stop, then start comparing the beginning of the substring from the next letter of the source string.
            if(source[i + j] != find[j])
            {
                matchingLetters = 0;
                break;
            }
            
            matchingLetters++;

            // Have we found the *whole* `find` within the `source` string?
            if(matchingLetters == findLength)
            {
                if(findLength != replaceLength)
                {
                    cout << "ERROR: The replace word has to be equally long as the find word." << endl;
                    break;
                }

                source += i-1;

                // Replace `find` with `replace`
                for (int k = 0; k < findLength; k++)
                {
                    source++;
                    *source = replace[k];
                    // source[i + k] = find[k];
                }

                source -= i+1+findLength; // not sure if this is necessary. It does not change the result at least... I just want the pointer to point to the first element again (?)

                // Skip ahead to after the replaced word, and continue checking if there are more instances of the substring in the source string.
                i += (findLength - 1);
                break;
            }
        }
    }

    // if(Contains(source, find))
    // {
    //     cout << "Match found." << endl;

    //     // Replace
    // }
    
}

/// @brief 
/// @param source The c-string in which to find a substring
/// @param substring The c-string to find within the other string
/// @return 
bool Program::Contains(char *source, char *substring)
{
    int sourceLength = strlen(source);
    int substringLength = strlen(substring);

    int matchingLetters = 0;

    for (int i = 0; i < (sourceLength - substringLength + 1); i++)
    {
        for (int j = 0; j < substringLength; j++)
        {
            // As soon as the word substring doesn't match up with the targeted series of letters in the source string, stop, then start comparing the beginning of the substring from the next letter of the source string.
            if(source[i + j] != substring[j])
            {
                matchingLetters = 0;
                break;
            }
            
            matchingLetters++;
            if(matchingLetters == substringLength)
                return true;
        }
    }

    return false;
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