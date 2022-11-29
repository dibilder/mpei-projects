#include <iostream>

using namespace std;

int main()
{
    //Входные данные
    int columnOfMatrix,lineOfMatrix;
    double matrix[100][100];

    //Выходные данные
    double SrAr;

    //Промежуточные данные
    double SummOfColumnValue;
    int i,j;

    SummOfColumnValue = 0;

    cout << "Type number of matrix column: " <<  endl;
    cin >> columnOfMatrix;
    cout << "Type number of matrix line: " <<  endl;
    cin >> lineOfMatrix;

    for (i=0; i != columnOfMatrix; i++) {
        for (j=0; j != lineOfMatrix ; j++) {
            cout << "Type element " << i << " in column " << j << ":" << endl;
            cin >> matrix [i][j];

            SummOfColumnValue += matrix[i][j];

            if (matrix[i][j] >= 0)
                matrix[i][j] = 1;
            else
                matrix[i][j] = 0;

            cout << "Result after conversion:  " << matrix[i][j] << endl;
        }
        SrAr = SummOfColumnValue/lineOfMatrix;
        cout << "Average of column = " << SrAr << endl;
    }
    return 0;
}
