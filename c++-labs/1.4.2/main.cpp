#include <iostream>
using namespace std;

int main()
{
    //������� ������
    int n;
    double x[100];

    //�������� ������
     double SrAr;
     int PositiveCount;

    //������������� ������
    int CountForSrAr;
    double SummForSrAr;


    cout << "Type array length (n):" << endl;
    cin >> n;

    if (n > 100) {
        cout << "Very large value (>100)" << endl;
    } else {
        SummForSrAr=0;
        CountForSrAr=0;
        PositiveCount=0;

        for (int i=0; i != n; i++) {
           cout << "Type " << i << " element of array X:" << endl;
           cin >> x[i];
           if (x[i] != 0) {
                SummForSrAr += x[i];
                CountForSrAr++;
           }
           if (x[i] >= 0) {
                PositiveCount++;
           }
        }
    }

    SrAr = SummForSrAr/CountForSrAr;
    cout << "Average of <> 0 value: " << SrAr << endl;
    cout << "Number of positive values:  " << PositiveCount << endl;

    return 0;
}
