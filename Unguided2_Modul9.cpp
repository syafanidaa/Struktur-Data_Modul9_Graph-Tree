#include <iostream>
#include <vector>
#include <string>

using namespace std;

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

void inputTreeData(vector<string> &cities, vector<vector<int>> &adjMatrix) {
    int n;
    cout << "Silakan masukan jumlah simpul: ";
    cin >> n;

    cities.resize(n);
    adjMatrix.resize(n, vector<int>(n, 0));

    cout << "Silakan masukan nama simpul" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Simpul " << i + 1 << ": ";
        cin >> cities[i];
    }

    cout << "Silakan masukan bobot antar simpul" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                cout << cities[i] << " ---> " << cities[j] << ": ";
                cin >> adjMatrix[i][j];
            }
        }
    }
}

int main() {
    vector<string> cities;
    vector<vector<int>> adjMatrix;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Input data tree\n";
        cout << "2. Tampilkan matrix adjacency\n";
        cout << "3. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> choice;

        switch (choice) {
            case 1:
                inputTreeData(cities, adjMatrix);
                break;
            case 2:
                if (cities.empty() || adjMatrix.empty()) {
                    cout << "Data tree belum diinputkan.\n";
                } else {
                    printMatrix(adjMatrix, cities);
                }
                break;
            case 3:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (choice != 3);

    return 0;
}
