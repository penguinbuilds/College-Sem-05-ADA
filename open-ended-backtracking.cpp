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

void findLongestPerfectSubstringBacktrack(string s, int k, int start, int end, string& current, string& longest) {
    if (isPerfect(current, k) && current.length() > longest.length()) {
        longest = current;
    }

    if (start >= s.length() || end >= s.length()) {
        return;
    }

    current.push_back(s[end]);
    findLongestPerfectSubstringBacktrack(s, k, start, end + 1, current, longest);
    current.pop_back();
    findLongestPerfectSubstringBacktrack(s, k, start + 1, end + 1, current, longest);
}

string findLongestPerfectSubstring(string s, int k) {
    string longestPerfectSubstring = "";
    string current = "";
    findLongestPerfectSubstringBacktrack(s, k, 0, 0, current, longestPerfectSubstring);
    return longestPerfectSubstring;
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
