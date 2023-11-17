#include <bits/stdc++.h>
using namespace std;

void details() {
    cout << endl;
    cout << "Name\t\t\t" << "Enrollment Number" << endl;
    cout << "Shreyas Om\t\t" << "A2305221156" << endl;
    cout << "Shaaswat K Jha\t\t" << "A2305221208" << endl;
    cout << "Ananya Singh\t\t" << "A2305221332" << endl;
    cout << endl;
    }

bool isPerfect(string s, int k) {
    unordered_map<char, int> charCount;
    for (char c : s) {
        charCount[c]++;
    }
    for (auto it : charCount) {
        if (it.second != k) {
            return false;
        }
    }
    return true;
}

string findLongestPerfectSubstring(string s, int k) {
    if (s.empty() || k <= 0) {
        return "";
    }

    if (isPerfect(s, k)) {
        return s;
    }

    string leftResult = findLongestPerfectSubstring(s.substr(0, s.size() - 1), k);
    string rightResult = findLongestPerfectSubstring(s.substr(1, s.size() - 1), k);

    if (leftResult.size() > rightResult.size()) {
        return leftResult;
    } else {
        return rightResult;
    }
}

int main() {
    details();
    
    string s;
    int k;

    cout << "Enter a string: ";
    cin >> s;

    cout << "Enter the value of 'k': ";
    cin >> k;

    string longestPerfectSubstring = findLongestPerfectSubstring(s, k);

    if (longestPerfectSubstring.empty()) {
        cout << "No perfect substring found with k=" << k << endl;
    } else {
        cout << "The longest perfect substring is: " << longestPerfectSubstring << endl;
    }

    cout << endl;

    return 0;
}
