/* Title: palindrome.cpp
 * Abstract: Determines if an inputted word is a palindrome
 * ID: 8889
 * Name: Ivan Alejandre
 * Date: 1/13/2020
 * */


#include <iostream>
#include <string>

using namespace std;

int main() {
    // define variables needed
	
	// special note: the string class treats strings as an array and thus have
	// the length method, are created with a pointer to the first element, and
	// are continuous in memory. Because the string type is extremely similar
	// to the C standard char array, we'll use string in this case and avoid
	// using an explicit dynamic array
    string inputString;
    int size, i , j;

    // get the word in question
    cout << "Input string: ";
    cin >> inputString;

    size = inputString.length();
    i = 0;
    j = size - 1;

    // starting at 0 and the end of the word, compare each character. if
    // different, not a palindrome. When incrementing indexes, check if
    // indexes overcome each other (even character words)
    do {
        if (inputString[i] != inputString[j]) {
            cout << "not a palindrome!";
            return 0;
        } else
        {
            i++;
            j--;
            if (i < j) // for even numbered words
                break;
        }
    } while (i != j);

    // when do..while ends, it determined it is a palindrome, output to user.
    cout << "it's a palindrome!";

    return 0;
}
