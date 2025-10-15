#include <iostream>
using namespace std;


bool isValidMatrix(int mat[10][10], int n) {

    for (int i = 0; i < n; i++) {
        bool rowCheck[10] = {false};
        for (int j = 0; j < n; j++) {
            int val = mat[i][j];
            if (val < 1 || val > n || rowCheck[val - 1])
                return false;
            rowCheck[val - 1] = true;
        }
    }


    for (int j = 0; j < n; j++) {
        bool colCheck[10] = {false};
        for (int i = 0; i < n; i++) {
            int val = mat[i][j];
            if (val < 1 || val > n || colCheck[val - 1])
                return false;
            colCheck[val - 1] = true;
        }
    }

    return true;
}

int main() {
    int n;
    cout << "Enter size n of the matrix: ";
    cin >> n;

    int mat[10][10];

    cout << "Enter the matrix elements:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    if (isValidMatrix(mat, n))
        cout << "Matrix is valid " << endl;
    else
        cout << "Matrix is invalid " << endl;

    return 0;
}
