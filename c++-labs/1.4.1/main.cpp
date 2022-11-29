#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    //Входные данные
    int n;
    double x[100],y[100];

    //Выходные данные
     double t[100];

    cout << "Type array length (n):" << endl;
    cin >> n;

    if (n > 100) {
        cout << "Very large value (>100)" << endl;
    } else {
        for (int i=0; i != n; i++) {
           cout << "Type " << i << " element of array X:" << endl;
           cin >> x[i];
           cout << "Type " << i << " element of array y:" << endl;
           cin >> y[i];
           if (i == 0)
                t[i]=1;
           else
                t[i]=sqrt(pow(x[i] - y[i],2))/t[i-1];
           cout << "Element " << i << " element of array t =" << t[i] << endl;
        }
    }

    return 0;
}
