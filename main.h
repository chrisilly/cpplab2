using namespace std;

class Program
{


    public:

    int* GetPrimes(int upperBound, int lowerBound);
    int* GetPrimes(int upperBound);
    void PrintNumbers(int *numbers);

    void Replace(char *source, char *find, char *replace);
    void Replace(string &source, string find, string replace);
    bool Contains(char *source, char *substring);
};