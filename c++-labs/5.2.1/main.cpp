#include <iostream>

using namespace std;

 struct student {
        string group;
        string firstName;
        string middleName;
        string secondName;
        short int year;
        char gender;
        short int physics, math, info;
        double scholarship;
    };

int main()
{
    //Входные данные
    int n;
    student a[30];

    //Выходные данные
    int counter = 0;

    //Промежуточные данные
    int i;
    string currentGroup = "C5-97";

    cout << "Type number of students: " << endl;
    cin >> n;

    for (i=0; i != n; i++) {
        cout << "Student " << i << ". " << endl;

        cout << "Type group: " << endl;
        cin >> a[i].group;

        cout << "Type first name: " << endl;
        cin >> a[i].firstName;

        cout << "Type middle name: " << endl;
        cin >> a[i].middleName;

        cout << "Type second name: " << endl;
        cin >> a[i].secondName;

        cout << "Type year of birth: " << endl;
        cin >> a[i].year;

        cout << "Type gender: " << endl;
        cin >> a[i].gender;

        cout << "Type physics mark: " << endl;
        cin >> a[i].physics;

        cout << "Type math mark: " << endl;
        cin >> a[i].math;

        cout << "Type computer science mark: " << endl;
        cin >> a[i].info;

        cout << "Type scholarship: " << endl;
        cin >> a[i].scholarship;
    }

    cout << "Students in group C5-97 and all five marks: " << endl;

    for (i=0; i != n; i++){
        if ((a[i].group == currentGroup) && (((a[i].physics + a[i].math + a[i].info) / 3) == 5)) {
            counter++;
            cout << "Name: " << a[i].firstName << " " << a[i].middleName << " " << a[i].secondName << endl;
            cout << "Scholarship: " << a[i].scholarship << endl;
            cout << endl;
        }
    }

    cout << "The number of such students: " << counter << endl;

    return 0;
}
