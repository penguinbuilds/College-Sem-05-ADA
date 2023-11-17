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

string perfectSubstringGreedy(string s, int k) {
    for(int i = 0; i < s.size(); i++) {
        for(int j = s.size(); j > i; j--) {
            if(check_perfect(s.substr(i, j - i), k)) {
                return s.substr(i, j - i);
            }
        }
    }
    return ""; // Add this line to handle the case where no perfect substring is found
}

int main() {
    details();

    string s;
    int k;

    cout << "Enter a string: ";
    cin >> s;

    cout << "Enter the value of 'k': ";
    cin >> k;

    string longest_perfect_substring = perfectSubstringGreedy(s, k);

    if (longest_perfect_substring.empty()) {
        cout << "No perfect substring found." << endl;
    } else {
        cout << "The longest perfect substring is: " << longest_perfect_substring << endl;
    }

    cout << endl;

    return 0;
}
