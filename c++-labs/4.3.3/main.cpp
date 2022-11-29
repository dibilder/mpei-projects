#include <iostream>
#include <cmath>

using namespace std;

//Глобальная переменная
double matrix[100][100];

double SrAr(double TempMatrix[100][100], int column, int line) {
        double SummOfElements = 0;
        for (int i=0; i != line; i++) {
            for (int j=0; j != column ; j++) {
                SummOfElements += TempMatrix[i][j];
            }
        }
        return SummOfElements/(column * line);
}

int FindColumnOfMatrix (double TempMatrix[100][100], int column, int line) {
        int columnNumber = 1, NegativNumbers = 0, counter;
        for (int i=0; i != column; i++) {
            counter = 0;
            for (int j=0; j != line ; j++) {
                if (TempMatrix[j][i] < 0 )
                    counter++;
            }
            if (counter > NegativNumbers) {
                columnNumber = i;
                NegativNumbers = counter;
            }
        }
        return columnNumber;
}

void PrintMatrix(double TempMatrix[100][100], int column,int line) {
        for (int i=0; i != line; i++) {
            for (int j=0; j != column ; j++) {
                cout << TempMatrix[i][j] << " ";
            }
            cout << endl;
        }
}

void ReplaceMatrixColumn(int column, int line, int localTrueColumn) {
        for (int i=(localTrueColumn); i != column; i++) {
            for (int j=0; j != line ; j++) {
                if (matrix[j][i] < 0)
                    matrix[j][i] = abs(matrix[j][i]);
            }
        }
}

int main()
{
    //Входные данные
    int columnOfMatrix,lineOfMatrix;

    //Выходные данные
    double SrArFirst, SrArSecond;

    //Промежуточные данные
    int trueColumn;

    cout << "Type number of array column: " << endl;
    cin >> columnOfMatrix;
    cout << "Type number of array line: " << endl;
    cin >> lineOfMatrix;

    cout << "Type matrix: " << endl;
    for (int i=0; i != lineOfMatrix; i++) {
        cout << "Type line " << i << " with " << columnOfMatrix << " elements: " << endl;
        for (int j=0; j != columnOfMatrix ; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << "Print matrix: " << endl;
    PrintMatrix(matrix, columnOfMatrix, lineOfMatrix);

    SrArFirst = SrAr(matrix, columnOfMatrix, lineOfMatrix);

    trueColumn = FindColumnOfMatrix(matrix, columnOfMatrix, lineOfMatrix);
    cout << "Column with the most negative elements:  " << trueColumn << endl;

    ReplaceMatrixColumn(columnOfMatrix, lineOfMatrix, trueColumn);

    SrArSecond = SrAr(matrix, columnOfMatrix, lineOfMatrix);

    cout << "Matrix after changes: " << endl;
    PrintMatrix(matrix, columnOfMatrix, lineOfMatrix);

    cout << "Old average: " << SrArFirst << endl;
    cout << "New average: " << SrArSecond << endl;

    return 0;
}
