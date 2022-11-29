#include <iostream>
#include <cmath>

#define PI 3.14159265

using namespace std;

int main()
{
    //Входные данные
    double sideA,sideB;
    double matrix[100][100];

    //Выходные данные
    int counter;

    //Промежуточные данные
    int columnOfMatrix,lineOfMatrix;
    double Srectangle,Sring;
    int i,j;

    cout << "Vvedite storonu A pramougolnika: " << endl;
    cin >> sideA;

    cout << "Vvedite storonu B pramougolnika: " << endl;
    cin >> sideB;

    Srectangle=sideA*sideB;
    columnOfMatrix=2;
    lineOfMatrix=10;

    cout << "Kol-vo stolbcov matrici: " << columnOfMatrix << endl;
    cout << "Kol-vo strok matrici:  " << lineOfMatrix << endl;
    cout << "Stolbec 1 - vnutrenniy diametr kolca, stolbec 2 - vneshniy" << endl;

    for (i=0; i != lineOfMatrix ; i++) {
        for (j=0; j != columnOfMatrix  ; j++) {
            if (j == columnOfMatrix) {
                do {
                    cout << "Vevdite znachenie v stroke " << i << "stolbce " <<  j << ":" << endl;
                    cin >> matrix[i][j];
                    if (matrix[i][j] <  matrix[i][j-1]) {
                        cout << "Vneshniy diametr kolca ne moget bit menshe vnutrennego!" << endl;
                    }
                } while (matrix[i][j] > matrix[i][j-1]);
            } else {
                cout << "Vvedite znachenie v stroke " << i << " stolbce " <<  j << ":" << endl;
                cin >> matrix[i][j];
            }
        }
    }

    cout <<  "Massiv: " << endl;
    for (i=0; i != lineOfMatrix ; i++) {
        for (j=0; j != columnOfMatrix  ; j++)
            cout << matrix[i][j] << " ";
        cout << "" << endl;
    }

    //Можно было сделать все в одном цикле, но я не захотел. Слишком захламленно получается.

    counter=0;
    for (i=0; i != lineOfMatrix ; i++) {
        Sring = PI * (pow((matrix[i][1]/2),2) - pow((matrix[i][0]/2),2));
        if (Sring > Srectangle) {
            cout << "S kolca bolshe. Vneshniy ego diametr = " << matrix[i][1] << endl;
            counter++;
        }
    }

    cout << "Kol-vo kolec, chya ploshyad bolshe: " << counter << endl;

    return 0;
}
