#include <iostream>
#include <vector>

using namespace std;

void details() {
    cout << "Name: Shaaswat K Jha" << endl;
    cout << "Enrollment No: A2305221208" << endl;
}

vector<vector<int>> matrixAddition(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }

    return result;
}

vector<vector<int>> matrixSubtraction(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }

    return result;
}

vector<vector<int>> strassenMultiply(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();

    if (n == 1) {
        vector<vector<int>> result(1, vector<int>(1, 0));
        result[0][0] = A[0][0] * B[0][0];
        return result;
    }

    int halfN = n / 2;

    vector<vector<int>> A11(halfN, vector<int>(halfN));
    vector<vector<int>> A12(halfN, vector<int>(halfN));
    vector<vector<int>> A21(halfN, vector<int>(halfN));
    vector<vector<int>> A22(halfN, vector<int>(halfN));

    vector<vector<int>> B11(halfN, vector<int>(halfN));
    vector<vector<int>> B12(halfN, vector<int>(halfN));
    vector<vector<int>> B21(halfN, vector<int>(halfN));
    vector<vector<int>> B22(halfN, vector<int>(halfN));

    for (int i = 0; i < halfN; i++) {
        for (int j = 0; j < halfN; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + halfN];
            A21[i][j] = A[i + halfN][j];
            A22[i][j] = A[i + halfN][j + halfN];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + halfN];
            B21[i][j] = B[i + halfN][j];
            B22[i][j] = B[i + halfN][j + halfN];
        }
    }

    vector<vector<int>> P1 = strassenMultiply(A11, matrixSubtraction(B12, B22));
    vector<vector<int>> P2 = strassenMultiply(matrixAddition(A11, A12), B22);
    vector<vector<int>> P3 = strassenMultiply(matrixAddition(A21, A22), B11);
    vector<vector<int>> P4 = strassenMultiply(A22, matrixSubtraction(B21, B11));
    vector<vector<int>> P5 = strassenMultiply(matrixAddition(A11, A22), matrixAddition(B11, B22));
    vector<vector<int>> P6 = strassenMultiply(matrixSubtraction(A12, A22), matrixAddition(B21, B22));
    vector<vector<int>> P7 = strassenMultiply(matrixSubtraction(A11, A21), matrixAddition(B11, B12));

    vector<vector<int>> C11 = matrixSubtraction(matrixAddition(matrixAddition(P5, P4), P6), P2);
    vector<vector<int>> C12 = matrixAddition(P1, P2);
    vector<vector<int>> C21 = matrixAddition(P3, P4);
    vector<vector<int>> C22 = matrixSubtraction(matrixSubtraction(matrixAddition(P5, P1), P3), P7);

    vector<vector<int>> result(n, vector<int>(n, 0));
    for (int i = 0; i < halfN; i++) {
        for (int j = 0; j < halfN; j++) {
            result[i][j] = C11[i][j];
            result[i][j + halfN] = C12[i][j];
            result[i + halfN][j] = C21[i][j];
            result[i + halfN][j + halfN] = C22[i][j];
        }
    }

    return result;
}

int main() {
    details();

    int n;
    cout << "Enter the size of the matrices: ";
    cin >> n;

    vector<vector<int>> A(n, vector<int>(n));
    vector<vector<int>> B(n, vector<int>(n));

    cout << "Enter matrix A:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Enter matrix B:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> B[i][j];
        }
    }

    vector<vector<int>> result = strassenMultiply(A, B);

    cout << "Resultant matrix C:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
