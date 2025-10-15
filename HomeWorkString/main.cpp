#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool isValidString(string s) {

    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = s[i] + 32; // 'A' ~> 'a' lowercase
    }

    int freq[26] = {0};

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        for (int j = 0; j < 26; j++) {
            if (c == 'a' + j) {
                freq[j]++;
                break;
            }
        }
    }

    int counts[26];
    int n = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0)
            counts[n++] = freq[i];
    }

    bool allEqual = true;
    for (int i = 1; i < n; i++) {
        if (counts[i] != counts[0]) {
            allEqual = false;
            break;
        }
    }
    if (allEqual) return true;

    int minFreq = 1e9, maxFreq = 0;
    int countMin = 0, countMax = 0;

    for (int i = 0; i < n; i++) {
        if (counts[i] < minFreq) minFreq = counts[i];
        if (counts[i] > maxFreq) maxFreq = counts[i];
    }

    for (int i = 0; i < n; i++) {
        if (counts[i] == minFreq) countMin++;
        if (counts[i] == maxFreq) countMax++;
    }


    if (minFreq == 1 && countMin == 1 && countMax + countMin == n)
        return true;

    if ((maxFreq - minFreq == 1) && countMax == 1 && countMax + countMin == n)
        return true;

    return false;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    if (isValidString(s))
        cout << "Valid String " << endl;
    else
        cout << "Invalid String " << endl;

    return 0;
}
