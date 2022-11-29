/*
�����: ������� �������.
������: �����-61-20.
������� ����� 18:
������� N ����� ������� (�������� ��������).
��� ������� ������ ������ ���������� ������ ����� ������, ���� � ��� ������ ������.
��������� ��������� ��������� (�� �������� ��� ��������� ����������������) �������� ������ ���� ���,
����� ��������� ����� � ���������� ���� ������������. ��������� ���������� ������.
*/

#include <iostream>
#include <vector>

using namespace std;

struct product {
    string type;
    string name;
    int quantitiOfProduct;
    double price;
    double weight;
    double pricePerKG;
};


struct container {
    double containerCapacity; //������� ������������� ����������
    int typeNumber;
    vector<product> productsInContainer; //����� ����� ������ ����� ���������, ������� ������ � ���������. ���������� ����� �������� �� ��, ������� ���������� � ���������
};

//���������� �����
container currentContainer; //��������� ��������� � �������� �� ���������
vector<product> products; //������ ���������
vector<string> types; //������, �������� ���� �������

void sortByPricePerKG() {
    //��������� ������ ������� �� �������� ���� �� 1��.
    for (int i = 0; i != products.size(); i++) {
        bool flag = true;
        for (int j = 0; j != products.size() - (i + 1); j++) {
            if (products[j].pricePerKG < products[j+1].pricePerKG ) {
                flag = false;
                swap (products[j],products[j+1]);
            }
       }
        if (flag)
            break;
    }
}

void sortContainerByPrice() {
    //��������� ������ ������� � ���������� �� �������� ����.
    for (int i = 0; i != currentContainer.productsInContainer.size(); i++) {
        bool flag = true;
        for (int j = 0; j != currentContainer.productsInContainer.size() - (i + 1); j++) {
            if (currentContainer.productsInContainer[j].price < currentContainer.productsInContainer[j+1].price ) {
                flag = false;
                swap (currentContainer.productsInContainer[j],currentContainer.productsInContainer[j+1]);
            }
        }
        if (flag)
            break;
    }
}

void sortContainerByWeight() {
    //��������� ������ ������� � ���������� �� �������� ����.
    for (int i = 0; i != currentContainer.productsInContainer.size(); i++) {
        bool flag = true;
        for (int j = 0; j != currentContainer.productsInContainer.size() - (i + 1); j++) {
            if (currentContainer.productsInContainer[j].weight < currentContainer.productsInContainer[j+1].weight) {
                flag = false;
                swap (currentContainer.productsInContainer[j],currentContainer.productsInContainer[j+1]);
            }
        }
        if (flag)
            break;
    }
}

void sortContainerByQuantiti() {
    //��������� ������ ������� � ���������� �� �������� ����������.
    for (int i = 0; i != currentContainer.productsInContainer.size(); i++) {
        bool flag = true;
        for (int j = 0; j != currentContainer.productsInContainer.size() - (i + 1); j++) {
            if (currentContainer.productsInContainer[j].quantitiOfProduct < currentContainer.productsInContainer[j+1].quantitiOfProduct) {
                flag = false;
                swap (currentContainer.productsInContainer[j],currentContainer.productsInContainer[j+1]);
            }
        }
        if (flag)
            break;
    }
}

void printProductsInContainer() {
    //������� ���������� ����������
    cout << "���������� ����������: " << endl;
    for (int i = 0; i != currentContainer.productsInContainer.size(); i++) {
            cout << currentContainer.productsInContainer[i].quantitiOfProduct << " ��. ������ " << currentContainer.productsInContainer[i].name << " ����� "  << currentContainer.productsInContainer[i].weight << " ��. � ����� " << currentContainer.productsInContainer[i].price << endl;
    }
}


//�������� ����� - ����� �������� ����� � �� ��� ����
//CanBeZero ��������� �������������� �������� ������� ��������
//canBeZero = 0 - ��������� �������� ������ 0
//canBeZero = 1 - ��������� �������� ������, ���� ������ 0
//canBeZero = 2 - ��������� �������� ������ 1
double getValue(string text, int canBeZero)
{
    while (true) // ���� ������������ �� ��� ���, ���� ������������ �� ������ ���������� ��������
    {
        cout << text;
        double a;
        cin >> a;

        if (cin.fail()) // ���� ���������� ���������� ��������� ���������,
        {
            cin.clear(); // �� ���������� cin � '�������' ����� ������
            cin.ignore(32767,'\n'); // � ������� �������� ����������� ����� �� �������� ������
        }
        else {// ���� �� ������, �� ���������� a
            //��������� ��������� �����
            switch (canBeZero) {
            case 0:
                //�� ����� ���� �����
                if (a > 0) {
                    return a;
                }
                break;
            case 1:
                //����� ���� �����
                if (a >= 0) {
                    return a;
                }
                break;
            case 2:
                //�� ����� ���� ������ 1
                if (a >= 1) {
                    return a;
                }
                break;
            default:
                //��� �������
                break;
            }
        }
    }
}

//��������� ������ ����� ������
void inputTypes() {
    int typesQuantity; //���������� ����� ������

    //������, �������� ���� �������
    typesQuantity = getValue("������� ���������� ����� ������: ", 2);

    string insertType; //���������� ��� ���������� ������� �����
    for (int i = 0; i != typesQuantity; i++) {
        cout << i << "-� ��� ������: " << endl;
        cin >> insertType;
        types.push_back(insertType);
    }

}

//������� ��������� ���� � ���������� ����� �������
int chooseType() {
    cout << "��������� ���� ������: " << endl;
    for (int j = 0; j != types.size(); j++)
        cout << j <<". " << types[j] << endl;

    while (true) // ���� ������������ �� ��� ���, ���� ������������ �� ������ ���������� ��������
    {
        int typeNumber = getValue("������� ����� ����: ", 1);

        if ((typeNumber >= 0) && (typeNumber < types.size())) // ���� ���������� ����� ��������� � ��������� ��������� �����,
        {
            return typeNumber;
        }
        else { //����� �������� �� ������
            cout << "�� ����� �������� ����� ����, ���������� ��� ���. ";
        }

    }
}
//��������� ������ �������, ������ ���������� �� ������� ������
void inputProducts(){
    product tempProduct; //���������� ���������� ������� ���������
    int productsQuantity; //���������� �������

    productsQuantity = getValue("������� ���������� �������: ", 2);

    for (int i = 0; i != productsQuantity; i++) {
        //��������� ��������� �������, ����� ������� �������� ��� � ������ Products
        cout << endl << "��������� ������ � ������ " << i << ". " << endl;

        tempProduct.type = types[chooseType()];

        cout << "������� �������� ������: ";
        cin >> tempProduct.name;

        tempProduct.quantitiOfProduct = getValue("������� ���������� (��) ����� ������: ", 1);

        tempProduct.price = getValue("������� ���� (�) �� 1 ��. ������: ", 0);

        tempProduct.weight = getValue("������� ��� (��) 1 ��. ������: ", 0);

        tempProduct.pricePerKG = tempProduct.price / tempProduct.weight;
        cout << "������������ ���� �� 1 ��. ������: " << tempProduct.pricePerKG << endl;

        products.push_back(tempProduct);
    }
    cout << endl;
}

void fillingTheContainer() {
    int amountOfProductInContainer; //���������� ���������, ����������� � ���������

    currentContainer.containerCapacity = getValue("������� ���������������� (��) ����������, ���� ����� ������������ ������: ", 0);

    cout << "� ��������� ����� ��������� ������ ������ ������ ����. ";
    currentContainer.typeNumber = chooseType();

    cout << endl;

    //��������� ���������
    for (int i = 0; i != products.size(); i++) {
        //���� � ���������� ��� ���� �����
        if (currentContainer.containerCapacity > 0) {
            //�������, ������� ������ ����� ������ � ���������
            amountOfProductInContainer = int(currentContainer.containerCapacity / products[i].weight);
            //���� ��� ������ ������������� ����������, � ���������� ����������� ������� ������ 0, � ���������� ��������� ������ ������������ ����������
            if ((products[i].type == types[currentContainer.typeNumber])&& (amountOfProductInContainer > 0) && (products[i].quantitiOfProduct >= amountOfProductInContainer)) {
                currentContainer.containerCapacity -= amountOfProductInContainer*products[i].weight; //�������� �� ����������� ���������� ��� ������ * ���������� ������
                currentContainer.productsInContainer.push_back(products[i]); //�������� ����� � ��������� (������ �������� Product)
                currentContainer.productsInContainer.back().quantitiOfProduct = amountOfProductInContainer; //���������� ��������� ������ �� ��, ������� ������
                //������� ������� ������
                //���������� ����� ������, ��� ��� �����������
                cout << "� ��������� ������ " << amountOfProductInContainer << " ��. ������ " << currentContainer.productsInContainer.back().name << " ��������� ����� "  << amountOfProductInContainer*currentContainer.productsInContainer.back().weight << " ��." << endl;

            //���� ��� ������ ������������� ����������, � ���������� ����������� ������� ������ 0, � ���������� ��������� ������ ������������ ����������
            } else if ((products[i].type == types[currentContainer.typeNumber])&& (amountOfProductInContainer > 0) && (products[i].quantitiOfProduct < amountOfProductInContainer)) {
                currentContainer.containerCapacity -= products[i].quantitiOfProduct*products[i].weight;//�������� �� ����������� ���������� ��� ������ * ���������� ������
                currentContainer.productsInContainer.push_back(products[i]); //�������� � ���������
                //������� ������� ������
                //���������� ����� ������, ��� ��� �����������
                cout << "� ��������� ������ " << currentContainer.productsInContainer.back().quantitiOfProduct << " ��. ������ " << currentContainer.productsInContainer.back().name << " ��������� ����� "  << currentContainer.productsInContainer.back().quantitiOfProduct*currentContainer.productsInContainer.back().weight << " ��." << endl;
            }
            //���������� ����� ������, ��� ��� �����������
            cout << "� ���������� �������� �������� " << currentContainer.containerCapacity << " ��." << endl;
        }
    }
    cout << endl;
}

void ChooseContainerSort(){
    //������ � ���������� ����������. ������ ��� ����.
    vector <string> sortTypes = {"�� ���� ������� ������.", "�� ���� �� ������� ������.", "�� ���������� ������ � ����������."};

    cout << "������ � ����������� ���������� ����� �������������. ���� ���������� �� ���������, ������� ����� ������ �����. " << endl;
    //������� ��� ��������
    cout << "��������� ���� ����������: " << endl;
    for (int j = 0; j != sortTypes.size(); j++)
        cout << j <<". " << sortTypes[j] << endl;

    while (true) // ���� ������������ �� ��� ���, ���� ������������ �� ������ ���������� ��������
    {
        //���������� ������� � ��������� �� ������ ����������� ������
        int sortNumber = getValue("�������� ����� �������� ����������: ", 1);

        if ((sortNumber >= 0) && (sortNumber < sortTypes.size())) // ���� ���������� ����� ��������� � ��������� ��������� �����,
        {
            switch (sortNumber) {
                case 0:
                    sortContainerByWeight();
                    cout << "���������� �� ���� ���������. " << endl;
                    break;
                case 1:
                    sortContainerByPrice();
                    cout << "���������� �� ���� ���������. " << endl;
                    break;
                case 2:
                    sortContainerByQuantiti();
                    cout << "���������� �� ���������� ���������. " << endl;
                    break;
                default:
                    cout << "������ ����������� ����� ����������. ������ �� �������. " << endl;
                    break;
            }
            break;
        } else { //����� �������� �� ������
                cout << "�� ����� �������� ����� ����, ���������� ��� ���. ";
        }
    }
    cout << endl;
}

void helloMessage() {
    cout << "�������� ��������� ������� ����������� ����������. " << endl;
    cout << "�����: ������� �������. " << endl;
    cout << "������: �����-61-20. " << endl;
    cout << "�������: ����������� ���������. " << endl;
    cout << "����: 2021 ���." << endl;
    cout << endl;
}

int main()
{
    //�� ��� �������
    setlocale(LC_ALL, "Russian");

    //����� ���������
    helloMessage();

    //������ ����
    inputTypes();

    //��������� ������ ���������
    inputProducts();

    //��������� ������ �� ���� �� ��
    sortByPricePerKG();

    //��������� ���������
    fillingTheContainer();

    //��������� ������ � ����������
    ChooseContainerSort();

    //������� ���������
    printProductsInContainer();

    return 0;
}
