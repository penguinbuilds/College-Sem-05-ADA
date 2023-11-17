#include <bits/stdc++.h>
using namespace std;

int check_perfect(string s, int k) {
    for (int i = 0; i < s.size(); i++) {
        if (count(s.begin(), s.end(), s[i]) != k) {
            return 0;
        }
    }
    return 1;
}

string count_perfect(string s, int k) {
    if (s.size() < k) {
        return "";
    }

    if (check_perfect(s, k) == 0) {
        string left_result = count_perfect(s.substr(0, s.size() - 1), k);
        string right_result = count_perfect(s.substr(1, s.size()), k);

        if (left_result.size() > right_result.size()) {
            return left_result;
        } else {
            return right_result;
        }
    } else {
        return s;
    }
}

int main() {
    string s;
    int k;

    cout << "Enter a string: ";
    cin >> s;

    cout << "Enter the value of 'k': ";
    cin >> k;

    string longest_perfect_substring = count_perfect(s, k);

    if (longest_perfect_substring.empty()) {
        cout << "No perfect substring found." << k << endl;
    } else {
        cout << "The longest perfect substring is: " << longest_perfect_substring << endl;
    }

    return 0;
}
