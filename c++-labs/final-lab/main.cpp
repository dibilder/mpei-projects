/*
Автор: Семачев Алексей.
Группа: ИЭозс-61-20.
Задание номер 18:
Имеется N типов товаров (названия известны).
Для каждого товара задано количество единиц этого товара, цена и вес единиц товара.
Требуется загрузить контейнер (не превышая его известной грузоподъемности) товарами одного типа так,
чтобы стоимость груза в контейнере была максимальной. Выполнить сортировку списка.
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
    double containerCapacity; //Текущая загруженность контейнера
    int typeNumber;
    vector<product> productsInContainer; //Здесь будут лежать копии продуктов, которые попали в контейнер. Количество будет изменено на то, сколько уместилось в контейнер
};

//Глобальные штуки
container currentContainer; //Структура контейнер с вектором из продуктов
vector<product> products; //Вектор продуктов
vector<string> types; //Вектор, хранящий типы товаров

void sortByPricePerKG() {
    //Сортируем массив товаров по убыванию цены за 1кг.
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
    //Сортируем массив товаров в контейнере по убыванию цены.
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
    //Сортируем массив товаров в контейнере по убыванию веса.
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
    //Сортируем массив товаров в контейнере по убыванию количества.
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
    //Выводим содержимое контейнера
    cout << "Содержимое контейнера: " << endl;
    for (int i = 0; i != currentContainer.productsInContainer.size(); i++) {
            cout << currentContainer.productsInContainer[i].quantitiOfProduct << " шт. товара " << currentContainer.productsInContainer[i].name << " весом "  << currentContainer.productsInContainer[i].weight << " кг. и ценой " << currentContainer.productsInContainer[i].price << endl;
    }
}


//Проверка ввода - нужно получить число и ни что иное
//CanBeZero позволяет контролировать диапазон числого значения
//canBeZero = 0 - принимаем значения больше 0
//canBeZero = 1 - принимаем значения больше, либо равные 0
//canBeZero = 2 - принимаем значения больше 1
double getValue(string text, int canBeZero)
{
    while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
    {
        cout << text;
        double a;
        cin >> a;

        if (cin.fail()) // если предыдущее извлечение оказалось неудачным,
        {
            cin.clear(); // то возвращаем cin в 'обычный' режим работы
            cin.ignore(32767,'\n'); // и удаляем значения предыдущего ввода из входного буфера
        }
        else {// если всё хорошо, то возвращаем a
            //Проверяем введенное число
            switch (canBeZero) {
            case 0:
                //Не может быть нулем
                if (a > 0) {
                    return a;
                }
                break;
            case 1:
                //Может быть нулем
                if (a >= 0) {
                    return a;
                }
                break;
            case 2:
                //Не может быть меньше 1
                if (a >= 1) {
                    return a;
                }
                break;
            default:
                //Все пропало
                break;
            }
        }
    }
}

//Заполняем вектор типов товара
void inputTypes() {
    int typesQuantity; //Количество типов товара

    //Вектор, хранящий типы товаров
    typesQuantity = getValue("Введите количество типов товара: ", 2);

    string insertType; //Переменная для заполнения вектора типов
    for (int i = 0; i != typesQuantity; i++) {
        cout << i << "-й тип товара: " << endl;
        cin >> insertType;
        types.push_back(insertType);
    }

}

//Выводим доступные типы и производим выбор нужного
int chooseType() {
    cout << "Доступные типы товара: " << endl;
    for (int j = 0; j != types.size(); j++)
        cout << j <<". " << types[j] << endl;

    while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
    {
        int typeNumber = getValue("Введите номер типа: ", 1);

        if ((typeNumber >= 0) && (typeNumber < types.size())) // если полученный номер находится в диапазоне доступных типов,
        {
            return typeNumber;
        }
        else { //Иначе сообщаем об ошибке
            cout << "Вы ввели неверный номер типа, попробуйте еще раз. ";
        }

    }
}
//Заполняем массив товаров, вводим информацию по каждому товару
void inputProducts(){
    product tempProduct; //Переменная заполнения вектора продуктов
    int productsQuantity; //Количество товаров

    productsQuantity = getValue("Введите количество товаров: ", 2);

    for (int i = 0; i != productsQuantity; i++) {
        //Заполняем временный продукт, потом целиком передаем его в вектор Products
        cout << endl << "Заполните данные о товаре " << i << ". " << endl;

        tempProduct.type = types[chooseType()];

        cout << "Укажите название товара: ";
        cin >> tempProduct.name;

        tempProduct.quantitiOfProduct = getValue("Укажите количество (шт) этого товара: ", 1);

        tempProduct.price = getValue("Укажите цену (р) за 1 ед. товара: ", 0);

        tempProduct.weight = getValue("Укажите вес (кг) 1 ед. товара: ", 0);

        tempProduct.pricePerKG = tempProduct.price / tempProduct.weight;
        cout << "Рассчитанная цена за 1 кг. товара: " << tempProduct.pricePerKG << endl;

        products.push_back(tempProduct);
    }
    cout << endl;
}

void fillingTheContainer() {
    int amountOfProductInContainer; //Количество продуктов, вмещяющихся в контейнер

    currentContainer.containerCapacity = getValue("Введите грузоподъемность (кг) контейнера, куда будут складываться товары: ", 0);

    cout << "В контейнер можно загрузить товары только одного типа. ";
    currentContainer.typeNumber = chooseType();

    cout << endl;

    //Заполняем контейнер
    for (int i = 0; i != products.size(); i++) {
        //Если в контейнере еще есть место
        if (currentContainer.containerCapacity > 0) {
            //Считаем, сколько влезет этого товара в контейнер
            amountOfProductInContainer = int(currentContainer.containerCapacity / products[i].weight);
            //Если тип товара соответствует выбранному, и количество вмещающихся товаров больше 0, и количество продуктов больше вмещающегося количества
            if ((products[i].type == types[currentContainer.typeNumber])&& (amountOfProductInContainer > 0) && (products[i].quantitiOfProduct >= amountOfProductInContainer)) {
                currentContainer.containerCapacity -= amountOfProductInContainer*products[i].weight; //Вычитаем из вместимости контейнера вес товара * количество товара
                currentContainer.productsInContainer.push_back(products[i]); //Передаем товар в контейнер (вектор структур Product)
                currentContainer.productsInContainer.back().quantitiOfProduct = amountOfProductInContainer; //Количество продуктов меняем на то, которое влезло
                //Выводим сколько влезло
                //Информацию можно убрать, она для наглядности
                cout << "В контейнер влезло " << amountOfProductInContainer << " шт. товара " << currentContainer.productsInContainer.back().name << " суммарным весом "  << amountOfProductInContainer*currentContainer.productsInContainer.back().weight << " кг." << endl;

            //Если тип товара соответствует выбранному, и количество вмещяющихся товаров больше 0, и количество продуктов меньше вмещяющегося количества
            } else if ((products[i].type == types[currentContainer.typeNumber])&& (amountOfProductInContainer > 0) && (products[i].quantitiOfProduct < amountOfProductInContainer)) {
                currentContainer.containerCapacity -= products[i].quantitiOfProduct*products[i].weight;//Вычитаем из вместимости контейнера вес товара * количество товара
                currentContainer.productsInContainer.push_back(products[i]); //Передаем в контейнер
                //Выводим сколько влезло
                //Информацию можно убрать, она для наглядности
                cout << "В контейнер влезло " << currentContainer.productsInContainer.back().quantitiOfProduct << " шт. товара " << currentContainer.productsInContainer.back().name << " суммарным весом "  << currentContainer.productsInContainer.back().quantitiOfProduct*currentContainer.productsInContainer.back().weight << " кг." << endl;
            }
            //Информацию можно убрать, она для наглядности
            cout << "В контейнере осталось свободно " << currentContainer.containerCapacity << " кг." << endl;
        }
    }
    cout << endl;
}

void ChooseContainerSort(){
    //Вектор с вариантами сортировки. Потому что могу.
    vector <string> sortTypes = {"По весу единицы товара.", "По цене за единицу товара.", "По количеству товара в контейнере."};

    cout << "Товары в заполненном контейнере можно отсортировать. Если сортировка не требуется, введите любое другое число. " << endl;
    //Выводим эти варианты
    cout << "Доступные типы сортировки: " << endl;
    for (int j = 0; j != sortTypes.size(); j++)
        cout << j <<". " << sortTypes[j] << endl;

    while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
    {
        //Спрашиваем вариант и сортируем на основе полученного номера
        int sortNumber = getValue("Выберите номер варианта сортировки: ", 1);

        if ((sortNumber >= 0) && (sortNumber < sortTypes.size())) // если полученный номер находится в диапазоне доступных типов,
        {
            switch (sortNumber) {
                case 0:
                    sortContainerByWeight();
                    cout << "Сортировка по весу выполнена. " << endl;
                    break;
                case 1:
                    sortContainerByPrice();
                    cout << "Сортировка по цене выполнена. " << endl;
                    break;
                case 2:
                    sortContainerByQuantiti();
                    cout << "Сортировка по количеству выполнена. " << endl;
                    break;
                default:
                    cout << "Введен неизвестный номер сортировки. Ничего не сделано. " << endl;
                    break;
            }
            break;
        } else { //Иначе сообщаем об ошибке
                cout << "Вы ввели неверный номер типа, попробуйте еще раз. ";
        }
    }
    cout << endl;
}

void helloMessage() {
    cout << "Запущена программа расчета вместимости контейнера. " << endl;
    cout << "Автор: Семачев Алексей. " << endl;
    cout << "Группа: ИЭозс-61-20. " << endl;
    cout << "Предмет: Программная инженерия. " << endl;
    cout << "Дата: 2021 год." << endl;
    cout << endl;
}

int main()
{
    //Ну тут понятно
    setlocale(LC_ALL, "Russian");

    //Шапка программы
    helloMessage();

    //Вводим типы
    inputTypes();

    //Заполняем вектор продуктов
    inputProducts();

    //Сортируем вектор по цене за кг
    sortByPricePerKG();

    //Заполняем контейнер
    fillingTheContainer();

    //Сортируем товары в контейнере
    ChooseContainerSort();

    //Выводим контейнер
    printProductsInContainer();

    return 0;
}
