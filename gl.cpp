#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int i, j, k, n;
    float A[20][21], c, x[20], sum = 0.0;

    cout << "\nEnter the order of matrix (max 20): ";
    cin >> n;

    cout << "\nEnter the elements of augmented matrix row-wise:\n";
    for (i = 0; i < n; i++) {
        for (j = 0; j < n + 1; j++) {
            cout << "A[" << i + 1 << "][" << j + 1 << "] : ";
            cin >> A[i][j];
        }
    }

    // Forward Elimination
    for (j = 0; j < n - 1; j++) {
        if (A[j][j] == 0) {
            cout << "Mathematical Error: Division by zero!\n";
            return -1;
        }
        for (i = j + 1; i < n; i++) {
            c = A[i][j] / A[j][j];
            for (k = 0; k < n + 1; k++) {
                A[i][k] = A[i][k] - c * A[j][k];
            }
        }
    }

    // Back Substitution
    for (i = n - 1; i >= 0; i--) {
        sum = 0;
        for (j = i + 1; j < n; j++) {
            sum += A[i][j] * x[j];
        }
        if (A[i][i] == 0) {
            cout << "Mathematical Error: Division by zero!\n";
            return -1;
        }
        x[i] = (A[i][n] - sum) / A[i][i];
    }

    cout << "\nThe solution is:\n";
    cout << fixed << setprecision(4);
    for (i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }

    return 0;
}