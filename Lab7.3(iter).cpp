#include <iostream>
#include <iomanip>
#include <time.h>


using namespace std;

void Create(int** P, const int rowCount, const int colCount) {
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++) {
            cout << "P[" << i << "][" << j << "] = "; 
            cin >> P[i][j];
        } 
    cout << endl;

}

void Print(int** P, const int rowCount, const int colCount) {
    if (rowCount == 0 || colCount == 0) {
        cout << "no matrix" << endl;
        return;
    }
    cout << endl;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            cout << setw(4) << P[i][j];
        }
        cout << endl;
    }
}

void rowDel(int** P, int& rowCount, const int colCount, const int rowNum) {
    for (int i = rowNum - 1; i < rowCount - 1; i++) {
        for (int j = 0; j < colCount; j++) {
            P[i][j] = P[i + 1][j];
        }
    }
    rowCount--;
}

void colDel(int** P, const int rowCount, int& colCount, const int colNum) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = colNum - 1; j < colCount - 1; j++) {
            P[i][j] = P[i][j + 1];
        }
    }
    colCount--;
    
}

void matrixCompress(int** P, int& rowCount, int& colCount) {
    int i = 0;
    while (i < rowCount) {
        int j = 0;
        while (j < colCount) {
            if (P[i][j] == 0 && j == colCount - 1) {
                rowDel(P, rowCount, colCount, i + 1);
                j = colCount;
            }
            else if (P[i][j] == 0) {
                j++;
            }
            else {
                j = colCount;
                i++;
            }

        }

    }

    if (rowCount == 0) {
        return;
    }

    int j = 0;
    while (j < colCount) {
        i = 0;
        while (i < rowCount) {
            if (P[i][j] == 0 && i == rowCount - 1) {
                colDel(P, rowCount, colCount, j + 1);
                i = rowCount;
            }
            else if (P[i][j] == 0) {
                i++;
            }
            else {
                i = rowCount;
                j++;
            }

        }

    }
}

int matrixFirstPlus(int** P, const int rowCount, const int colCount) {
    if (rowCount == 0 || colCount == 0) {
        return -1;
    }
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            if (P[i][j] > 0) {
                return i + 1;
            }
            else if (P[i][j] <= 0 && i == rowCount && j == colCount) {
                return -1;
            }
        }
    }
}



int main()
{
    int rowCount;
    int colCount;

    cout << "rowCount = "; cin >> rowCount;
    cout << "colCount = "; cin >> colCount;

    int** P = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        P[i] = new int[colCount];


    Create(P, rowCount, colCount);
    cout << "Before compression:" << endl;
    Print(P, rowCount, colCount);
    cout << "First row with at least 1 element > 0: " << matrixFirstPlus(P, rowCount, colCount) << endl;

    cout << "After compression:" << endl;
    matrixCompress(P, rowCount, colCount);
    Print(P, rowCount, colCount);
    cout << "First row with at least 1 element > 0: " << matrixFirstPlus(P, rowCount, colCount) << endl;

    system("pause");
    cin.get();
    return 0;
}
