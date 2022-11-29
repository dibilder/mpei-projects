#include <iostream>

using namespace std;

int main()
{
    const int lengthOfMatrix=5;

    //Переменные
    double matrixA[100][100];
    double matrixB[100][100];
    double massivC[100];
    bool status;
    int i,j;

    //Матрица А
    cout << "Type matrix A 5*5: " << endl;
    for (i=0; i != lengthOfMatrix; i++) {
        cout << "Type line " << i << endl;
        for (j=0; j != lengthOfMatrix ; j++) {
            cin >> matrixA[i][j];
        }
    }

    cout << "Print matrix A 5*5: " << endl;
    for (i=0; i != lengthOfMatrix; i++) {
        for (j=0; j != lengthOfMatrix ; j++) {
            cout << matrixA[i][j] << " ";
        }
        cout << endl;
    }

    //Матрица Б
    cout << "Type matrix B 5*5: " << endl;
    for (i=0; i != lengthOfMatrix; i++) {
        cout << "Type line " << i << endl;
        for (j=0; j != lengthOfMatrix ; j++) {
            cin >> matrixB[i][j];
        }
    }

    cout << "Print matrix B 5*5: " << endl;
    for (i=0; i != lengthOfMatrix; i++) {
        for (j=0; j != lengthOfMatrix ; j++) {
            cout << matrixB[i][j] << " ";
        }
        cout << endl;
    }

    //Сравнение матрица
    //Если случается false, досрочный выход из циклов
    status = true;
    for (i=0; i != lengthOfMatrix; i++) {
        if (status = false)
            break;
        for (j=0; j != lengthOfMatrix ; j++) {
            if (matrixA[i][j] > matrixB[i][j]) {
                status = true;
            } else {
                status = false;
                break;
            }
        }
    }
    cout << "status: " << status << endl;

    //Заполнение и вывод массива C

    if (status) {
        cout << "Array C: " << endl;
        for (i=0; i != lengthOfMatrix; i++) {
            massivC[i] = 0;
            for (j=0; j != lengthOfMatrix ; j++) {
                massivC[i] = massivC[i] + matrixA[i][j] + matrixB[i][j];
            }
            cout << massivC[i] << " " << endl;
        }
    } else {
        cout << "Check failed. Some elements of matrix B are larger than elements of matrix A." << endl;
    }

    return 0;
}
