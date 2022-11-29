#include <iostream>

using namespace std;

 struct children {
        string name;
        string secondName;
        short int age, weight, height;
    };

int main()
{
    //Входные данные
    int n;
    children a[30];

    //Промежуточные данные
    int i;

    cout << "Type number of childrens: " << endl;
    cin >> n;

    for (i=0; i != n; i++) {
        cout << "Children " << i << ". " << endl;

        cout << "Type name: " << endl;
        cin >> a[i].name;

        cout << "Type second name: " << endl;
        cin >> a[i].secondName;

        cout << "Type the childs age: " << endl;
        cin >> a[i].age;

        cout << "Type height: " << endl;
        cin >> a[i].height;

        cout << "Type weight: " << endl;
        cin >> a[i].weight;


    }

    cout << "Children from 10 to 12 years old, whose height is not less than 155, and weight is not more than 45 kg:  " << endl;

    for (i=0; i != n; i++){
        if ((a[i].age >= 10) && (a[i].age <= 12) && (a[i].height >= 155 )) {
            cout << a[i].name << " " << a[i].secondName << endl;
            cout << endl;
        }
    }

    return 0;
}
