#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    //Входные данные
    double x;
    int n;
    //Промежуточные данные
    double temp;

    //Выходные данные
    double result;

    result = 0;
    temp = 1.0/3.0;
    cout << "Type x:" << endl;
    cin >> x;
    cout << "Type n:" << endl;
    cin >> n;

    if (n <= 0) {
        cout << "Wrong input" << endl;
    } else {
        for (int k=0; k != n; k++) {
            result += (pow(log(fabs(x + k)),2) * cos((pow(k,2) +   x)/n));
        }
        result = result * (temp*sqrt(exp(x)));
        cout << "Result:" <<  result << endl;
    }

    return 0;
}
