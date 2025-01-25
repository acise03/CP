#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>
#include <ctime>

void generateInput(int maxN, int maxL, int maxElement)
{
    // Seed the random number generator
    std::srand(std::time(0));
    int N = std::rand() % maxN + 1;

    // Generate L
    int L = std::rand() % maxL + 1;

    // Generate N

    // Generate L distinct random positive long longegers
    std::set<long long> uniqueNumbers;
    while (uniqueNumbers.size() < L)
    {
        long long num = std::rand() % maxElement + 1;
        uniqueNumbers.insert(num);
    }

    // Convert set to vector for easier manipulation
    std::vector<long long> sequence(uniqueNumbers.begin(), uniqueNumbers.end());

    // Prlong long the generated input
    std::cout << N << "\n";
    std::cout << L << "\n";
    for (size_t i = 0; i < sequence.size(); ++i)
    {
        std::cout << sequence[i];
        if (i != sequence.size() - 1)
        {
            std::cout << " ";
        }
    }
    std::cout << "\n";
}

int main()
{
    // Define constralong longs
    long long maxN = 10e9;       // Maximum value of N
    long long maxL = 20;         // Maximum number of values in the sequence
    long long maxElement = 10e6; // Maximum value of elements in the sequence

    // Generate a test case
    generateInput(maxN, maxL, maxElement);

    return 0;
}
