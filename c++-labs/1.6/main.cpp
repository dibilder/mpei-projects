#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    //Входные данные
    int n;
    double a, x1;

    //Выходные данные
    double x,y;

    //Промежуточные данные
    double dx;


    cout << "Type n:" << endl;
    cin >> n;
    cout << "Type a:" << endl;
    cin >> a;
    cout << "Type x1:" << endl;
    cin >> x1;

    dx = a/2;
    x = 0;

    cout << "x1 = :" << x1 << endl;
    cout << "dX = A / 2 = " << dx << endl;

    if (n <= 0)
        cout << "Error." << endl;
    else {
        cout << "N       X          Y" << endl;
        for (int i=0; i != n; i++) {
           x = x1 + (dx * (i));
            if (x < (4*a))
                y = sqrt(16*pow(a,2) - pow((x - 4*a),2));
            else
                y = (8*(exp(log(a) * 3)))/(pow((x - 4*a),2) + 4*pow(a,2));
            cout << i << "       " << x << "       " << y << endl;
        }
    }


    return 0;
}
