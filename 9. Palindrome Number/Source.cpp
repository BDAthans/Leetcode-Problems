#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

bool isPalindrome(int);
bool fastIsPalindrome(int);
int generateRandInt();
int countDigits(int);

int main() {
    // Seed random number
    srand(time(NULL));

    // Run 3 times for testing
    for (int i = 0; i < 3; i++) {
        // Generate random number
        ///int randNum = generateRandInt();
        //cout << "Random Number: " << randNum;
        int randNum = 121;

        // Check if random number is a palindrome
        bool test = isPalindrome(randNum);
        cout << ", isPalindrome: " << test;

        // Check fastest method for palindrome
        bool test2 = fastIsPalindrome(randNum);
        cout << ", fastIsPalindrome: " << test2 << endl;
    }
    system("PAUSE");
    return 1;
}

bool isPalindrome(int x) {
    // Check if integer is negative
    if (x < 0) {
        return false;
    }

    // Setup vector for storing digits
    vector<int> digits;

    // Get remaining digits
    while (x != 0) {
        // Get next digit from right
        digits.push_back(x % 10);
        x = x / 10;
    }

    // Check digits vector first and last moving inward
    int checkDigits = 0;
    while (checkDigits < (digits.size() / 2)) {
        if (digits[checkDigits] != digits[digits.size() - (checkDigits + 1)]) {
            return false;
        }
        checkDigits++;
    }
    return true;
}

bool fastIsPalindrome(int x) {
    // Convert int x to string
    string s = to_string(x);

    // Initialize two pointers, i at beginning and j at end
    int i = 0, j = s.size() - 1;

    // Loop until pointers intersect
    while (i < j) {
        // Comparison between characters at i and j
        if (s[i] != s[j]) return false; // return false if i and J do not match
        i++;
        j--;
    }
    // Return true if characters match
    return true;
}

int generateRandInt() {
    // Set minimum and maximum values for testing
    int min = -10000;
    int max = 10000;

    // Generate random number
    int randomNumber = min + rand() % (max - min + 1);
    return randomNumber;
}

