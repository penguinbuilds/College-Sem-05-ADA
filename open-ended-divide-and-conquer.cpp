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

int check_perfect(string s, int k) {
    for (int i = 0; i < s.size(); i++) {
        if (count(s.begin(), s.end(), s[i]) != k) {
            return 0;
        }
    }
    return 1;
}

string divide_and_conquer(string s, int k) {
    int n = s.size();
    if (n < k) {
        return "";
    }

    if (check_perfect(s, k) == 0) {
        string left_result = divide_and_conquer(s.substr(0, n - 1), k);
        string right_result = divide_and_conquer(s.substr(1, n - 1), k);

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
    details();

    string s;
    int k;

    cout << "Enter a string: ";
    cin >> s;

    cout << "Enter the value of 'k': ";
    cin >> k;

    string longest_perfect_substring = divide_and_conquer(s, k);

    if (longest_perfect_substring.empty()) {
        cout << "No perfect substring found." << endl;
    } else {
        cout << "The longest perfect substring is: " << longest_perfect_substring << endl;
    }

    cout << endl;

    return 0;
}
