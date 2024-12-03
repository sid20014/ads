#include <iostream>
#include <vector>
using namespace std;

// Function to build the prefix table
void buildPrefixTable(const string& pattern, vector<int>& prefixTable) {
    int m = pattern.length();
    int j = 0; // Length of the previous longest prefix suffix
    prefixTable[0] = 0; // First element is always 0

    for (int i = 1; i < m; i++) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = prefixTable[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            j++;
        }
        prefixTable[i] = j;
    }
}

// KMP search function
void KMP(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();
    vector<int> prefixTable(m);

    // Build the prefix table
    buildPrefixTable(pattern, prefixTable);

    int j = 0; // Index for pattern
    for (int i = 0; i < n; i++) {
        while (j > 0 && text[i] != pattern[j]) {
            j = prefixTable[j - 1];
        }
        if (text[i] == pattern[j]) {
            j++;
        }
        if (j == m) {
            cout << "Pattern found at index " << i - m + 1 << endl;
            j = prefixTable[j - 1];
        }
    }
}

int main() {
    string text, pattern;
    cout << "Enter the text: ";
    getline(cin, text);
    cout << "Enter the pattern: ";
    getline(cin, pattern);

    KMP(text, pattern);

    return 0;
}

