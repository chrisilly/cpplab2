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
string trickySource = "Hejjj";
string trickyFind = "ej";
string trickyReplace = "eje";
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

    char *sourceCstring = source;
    char *findCstring = goodFind;
    char *replaceCstring = replace;

    cout << "String: " << sourceCstring << endl;
    cout << "Find " << findCstring << " and replace with " << replaceCstring << "." << endl;
    baymax.Replace(sourceCstring, findCstring, replaceCstring);
    cout << "New string: " << sourceCstring << endl;
    
    cout << divider << endl;

    string sourceString = trickySource;
    string findString = trickyFind;
    string replaceString = trickyReplace;

    cout << "String: " << sourceString << endl;
    cout << "Find " << findString << " and replace with " << replaceString << "." << endl;
    baymax.Replace(sourceString, findString, replaceString);
    cout << "New string: " << sourceString << endl;
    
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
}

void Program::Replace(string &source, string find, string replace)
{
    int matchingLetters = 0;

    for (int i = 0; i < (source.length() - find.length() + 1); i++)
    {
        for (int j = 0; j < find.length(); j++)
        {
            // The find word doesn't start on index i, reset skip to next
            if (source[i + j] != find[j])
            {
                matchingLetters = 0;
                break;
            }

            matchingLetters++;
            
            // If we've found the find word in its entirety in the source string...
            if(matchingLetters == find.length())
            {
                
                // Replace the `find` word with the `replace` word
                source.replace(i, find.length(), replace);
                
                // Skip index ahead to the end of the `replace` word. 
                // (i.e. Don't keep looking for a `find` inside of the newly replaced section.)
                i += (replace.length() - 1);
                break;
            }
        }
        
    }
    
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