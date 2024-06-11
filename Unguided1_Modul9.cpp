#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

// Function to print the adjacency matrix
void printMatrix(vector<vector<int>> &matrix, vector<string> &cities) {
    cout << "\t";
    for (const auto &city : cities) {
        cout << city << "\t";
    }
    cout << endl;

    for (int i = 0; i < matrix.size(); ++i) {
        cout << cities[i] << "\t";
        for (int j = 0; j < matrix[i].size(); ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Silakan masukan jumlah simpul: ";
    cin >> n;

    vector<string> cities(n);
    cout << "Silakan masukan nama simpul" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Simpul " << i + 1 << ": ";
        cin >> cities[i];
    }

    vector<vector<int>> adjMatrix(n, vector<int>(n, 0));

    cout << "Silakan masukan bobot antar simpul" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                cout << cities[i] << " ---> " << cities[j] << ": ";
                cin >> adjMatrix[i][j];
            }
        }
    }

    printMatrix(adjMatrix, cities);

    return 0;
}
