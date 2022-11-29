#include <iostream>
#include <cmath>
using namespace std;

double formula (double value) {
    return sqrt(exp(value))-pow(value,2);
}

int main()
{
    //Входные данные
    int n;
    double a[100];

    //Выходные данные
    int indexOfMax;

    //Промежуточные данные
    double maxValue;
    int i;


    cout << "Type array length (n):" << endl;
    cin >> n;

    for (i=0; i != n; i++) {
        cout << "Type " << i << " element of array:" << endl;
        cin >> a[i];
        cout << "According to the formula: " << formula(a[i]) << endl;
        }

    maxValue = a[1];
    indexOfMax=1;
    for (i=0; i != n; i++){
        if (formula(a[i]) > formula(maxValue) ) {
            maxValue = a[i];
            indexOfMax = i;
        }
    }
    cout << "The highest value is numbered " << indexOfMax << endl;

    return 0;
}
