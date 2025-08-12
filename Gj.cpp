#include <iostream>
using namespace std;

int main() {
    int i, j, k, n;
    float A[20][20], c, x[10];

    cout << "\nEnter the size of matrix: ";
    cin >> n;

    cout << "\nEnter the elements of augmented matrix row-wise:\n";
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n + 1; j++) {
            cout << " A[" << i << "][" << j << "]: ";
            cin >> A[i][j];
        }
    }

    for (j = 1; j <= n; j++) {
        for (i = 1; i <= n; i++) {
            if (i != j) {
                if (A[j][j] == 0) {
                    cout << "Math error: Division by zero at pivot A[" << j << "][" << j << "]\n";
                    return -1;
                }
                c = A[i][j] / A[j][j];
                for (k = 1; k <= n + 1; k++) {
                    A[i][k] = A[i][k] - c * A[j][k];
                }
            }
        }
    }

    cout << "\nThe solution is:\n";
    for (i = 1; i <= n; i++) {
        if (A[i][i] == 0) {
            cout << "Cannot divide by zero at A[" << i << "][" << i << "]\n";
            return -1;
        }
        x[i] = A[i][n + 1] / A[i][i];
        cout << " x" << i << " = " << x[i] << endl;
    }

    return 0;
}