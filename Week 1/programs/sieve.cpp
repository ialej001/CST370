/* Title: Sieve.cpp
 * Abstract: Finds all prime numbers from 2 to the user selected number
 * ID: 8889
 * Name: Ivan Alejandre
 * Date: 1/13/2020
 * */

#include <iostream>

using namespace std;

int main() {
    int countTo, j;
    int * numbers;
    int * primes;
    cout << "Input an integer greater than 1: ";
    cin >> countTo;

    // populate numbers array to inputted number
    numbers = new int [countTo];
    primes = new int [countTo];

    for (int i = 2; i <= countTo; i++)
    {
        numbers[i] = i;
        primes[i] = 0;
    }

    // eliminate nonprimes
    for (int i = 2; i * i <= countTo; i++)
    {
        if (numbers[i] != 0)
        {
            j = numbers[i] * numbers[i];
            while (j <= countTo)
            {
                numbers[j] = 0;
                j += numbers[i];
            }
        }
    }

    // copy to primes array
    j = 0;
    for (int i = 2; i <= countTo; i++)
    {
        if (numbers[i] != 0)
        {
            primes[j] = numbers[i];
            j++;
        }
    }

    // output
    cout << "All prime numbers up to " << countTo << ": " << endl;
    for (int i = 0; i <= countTo; i++)
    {
        if (primes[i] == 0) {
            return 0;
        }
        if (primes[i] != 0) {
            cout << primes[i];
            if (primes[i + 1] != 0) // no comma after last number
                cout << ", ";
        }
    }

    return 0;
}