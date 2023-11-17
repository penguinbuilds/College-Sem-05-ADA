#include <iostream>
#include <vector>
using namespace std;

void details() {
    cout << endl;
    cout << "Name: Shaaswat K Jha" << endl;
    cout << "Enrollment No: A2305221208" << endl;
}

void printChessboard(const vector<vector<char>>& chessboard) {
    for (const vector<char>& row : chessboard) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int row, int col, const vector<vector<char>>& chessboard, int N) {
    for (int c = 0; c < col; ++c) {
        if (chessboard[row][c] == 'Q') {
            return false;
        }
    }

    for (int r = row, c = col; r >= 0 && c >= 0; --r, --c) {
        if (chessboard[r][c] == 'Q') {
            return false;
        }
    }

    for (int r = row, c = col; r < N && c >= 0; ++r, --c) {
        if (chessboard[r][c] == 'Q') {
            return false;
        }
    }

    return true;
}

bool findFirstSolution(int col, int N, vector<vector<char>>& chessboard, vector<int>& solution) {
    if (col == N) {
        solution = vector<int>(N, -1);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (chessboard[i][j] == 'Q') {
                    solution[i] = j;
                    break;
                }
            }
        }
        return true;
    }

    for (int row = 0; row < N; ++row) {
        if (isSafe(row, col, chessboard, N)) {
            chessboard[row][col] = 'Q';
            if (findFirstSolution(col + 1, N, chessboard, solution)) {
                return true;
            }
            chessboard[row][col] = '.';
        }
    }

    return false;
}

int main() {
    details();
    
    int N;
    cout << "Enter the size of the chessboard (N): ";
    cin >> N;

    vector<vector<char>> chessboard(N, vector<char>(N, '.'));
    vector<int> solution;

    if (findFirstSolution(0, N, chessboard, solution)) {
        cout << "First solution found:" << endl;
        printChessboard(chessboard);
        cout << "Solution vector (queen positions in each row): ";
        for (int i = 0; i < N; ++i) {
            cout << solution[i] << " ";
        }
        cout << endl;
    } else {
        cout << "No solution found." << endl;
    }

    cout << endl;

    return 0;
}
