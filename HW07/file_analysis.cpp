
#include <iostream>
#include <fstream>
#include <cctype> // for character testing functions

using namespace std;

// funct to analyze contents of the file, update char counters.
int ReadFile(const char* filename, int& totalUpper, int& totalLower, int& totalDigits,
             int& totalPunct, int& totalSpace, int& totalLines, int& totalPeriods, int& totalQuestion) {
    ifstream inFile(filename);

    if (!inFile) {
        cout << "Error: Unable to open file: " << filename << endl;
        return -1; // indicate error to open file
    }
    // declare char
    char ch;
    int totalChars = 0;

    totalUpper = totalLower = totalDigits = totalPunct = totalSpace = totalLines = totalPeriods = totalQuestion = 0;
    // check if in file
    while (inFile.get(ch)) {
        totalChars++;

        if (isupper(ch)) {
            totalUpper++;
        } else if (islower(ch)) {
            totalLower++;
        } else if (isdigit(ch)) {
            totalDigits++;
        } else if (ispunct(ch)) {
            totalPunct++;
        } else if (isspace(ch)) {
            totalSpace++;
        }

        if (ch == '\n') {
            totalLines++;
        } else if (ch == '.') {
            totalPeriods++;
        } else if (ch == '?') {
            totalQuestion++;
        }
    }

    inFile.close();
    return totalChars;
}

int main() {
    const char* filename = "dracula.txt";
    int totalUpper, totalLower, totalDigits, totalPunct, totalSpace, totalLines, totalPeriods, totalQuestion;

    int totalChars = ReadFile(filename, totalUpper, totalLower, totalDigits, totalPunct, totalSpace, totalLines, totalPeriods, totalQuestion);

    if (totalChars != -1) {
        cout << "Uppercase letters: " << totalUpper << endl;
        cout << "Lowercase letters: " << totalLower << endl;
        cout << "Digits: " << totalDigits << endl;
        cout << "Punctuation characters: " << totalPunct << endl;
        cout << "Whitespace characters: " << totalSpace << endl;
        cout << "Lines: " << totalLines << endl;
        cout << "Total Periods: " << totalPeriods << endl;
        cout << "Total Question marks: " << totalQuestion << endl;
        cout << "Total characters read: " << totalChars << endl;
    }

    return 0;
}
