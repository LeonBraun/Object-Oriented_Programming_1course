﻿#include <iostream>
using namespace std;

enum dolzhnost { laborer = 'l', secretary = 's', manager = 'm', accountant = 'a', executive = 'e', researcher = 'r' };

class date
{
    int day, month, year;
    char symbol;
public:
    void SetDate() { cin >> day >> symbol >> month >> symbol >> year; };
    void GetDate() { cout << day << '/' << month << '/' << year; }
};
class rabotnik
{
    int numberRabotnika;
    float zarplata;
    date dayPrinyatiya;
    string strWorker;

public:
    void SetRabotnik()
    {
        static int kolvoSotrudnikov = 1;
        char bukva;

        cout << "\aCотрудник #" << kolvoSotrudnikov++ << endl;
        cout << "Личный номер и зарплата: " && cin >> numberRabotnika >> zarplata;
        cout << "Дата принятия на работу ";
        dayPrinyatiya.SetDate();
        cout << "Введите первую букву должности (laborer, secretary, manager, accountant, executive, researcher): " && cin >> bukva && cout << endl;
        switch (bukva)
        {
        case laborer:
            strWorker = "laborer";
            break;
        case secretary:
            strWorker = "secretary";
            break;
        case manager:
            strWorker = "manager";
            break;
        case accountant:
            strWorker = "accountant";
            break;
        case executive:
            strWorker = "executive";
            break;
        case researcher:
            strWorker = "researcher";
            break;
        default:
            cout << "Ошибка ввода\n\n";
            break;
        }
    };

    void GetRabotnik() { cout << "Сотрудник №" << numberRabotnika << ", занимает должность " << strWorker << " и получает " << zarplata << ", принят на работу "; dayPrinyatiya.GetDate(); cout << endl; }
};
class angle
{
    int gradus;
    float min;
    char napravlenie;

public:
    angle(int g, float m, char n)
    {
        gradus = g;
        min = m;
        napravlenie = n;
    }

    void SetKoord()
    {
        cout << "\nВведите координаты (для обозначения сторон света используйте символы: север - 'N', юг - 'S', запад - 'W', восток - 'E')" << endl;
        cout << "Градусов: " && cin >> gradus;
        cout << "Минут: " && cin >> min;
        do
            cout << "Сторона света: " && cin >> napravlenie;
        while (napravlenie != 'N' && napravlenie != 'S' && napravlenie != 'W' && napravlenie != 'E');
    }
    void GetKoord() { cout << "Точка имеет координаты: " << gradus << char(176) << min << "' " << napravlenie << endl; }
};

int main()
{
    setlocale(LC_ALL, "ru");
    //4, 5, 6
    /*  4) Создайте класс employee, используя задачу 4 лабораторной работы 3. Класс должен включать поле типа int для хранения номера сотрудника и поле типа float для хранения величины его оклада. 
        Методы класса должны позволять пользователю вводить и отображать данные класса. 
        Напишите функцию main(), которая запросит пользователя ввести данные для трех сотрудников и выведет полученную информацию на экран. 
        
        5) Взяв в качестве основы структуру из задачи 5 лабораторной работы 3, создайте класс date. Его данные должны размещаться в трех полях типа int: month, day и year.
        Метод класса SetDate() должен принимать значение для объекта в формате 12/31/02, а метод GetDate() - выводить данные на экран. 

        6) Расширьте содержание класса employee из задачи 4, включив в него класс date и перечисление etype (см. задачу 6 лабораторной работы 3). 
        Объект класса date будет использоваться для хранения даты приема сотрудника на работу. 
        Перечисление будет использовано для хранения статуса сотрудника: лаборант, секретарь, менеджер и т. д. 
        Последние два поля данных должны быть закрытыми в определении класса employee, как и номер и оклад сотрудника.
        Вам будет необходимо разработать методы getemploy() и setemploy(), предназначенные соответственно для ввода и отображения информации о сотруднике. 
        Возможно, при создании методов вам понадобится ветвление switch для работы с перечисляемым типом etype. 
        Напишите функцию main(), которая попросит пользователя ввести данные о трех сотрудниках, а затем выведет эти данные на экран.   */
    rabotnik r1, r2, r3;
    r1.SetRabotnik(); r2.SetRabotnik();  r3.SetRabotnik();
    cout << endl;
    r1.GetRabotnik(); r2.GetRabotnik(); r3.GetRabotnik();
    cout << endl;

    //7
    /*  В морской навигации координаты точки измеряются в градусах и минутах широты и долготы. Например, координаты бухты Панити на о.Таити
        равны 149 градусов 34.8 минут восточной долготы и 17 градусов 31.5 минут южной широты. Это записывается как 149°34.8' W, 17°31.5' S.
        Один градус равен 60 минутам.
        Долгота измеряется величиной от 0 до 180 градусов восточнее или западнее Гринвича.
        Широта принимает значения от 0 до 90 градусов севернее или южнее экватора.
        Создайте класс angle, включающий следующие три поля: типа int для числа градусов, типа float для числа минут и типа char для указания направления (N, S, Е или W).
        Объект этого класса может содержать значение как широты, так и долготы. Создайте метод, позволяющий ввести координату точки, направление, в котором она измеряется,
        и метод, выводящий на экран значение этой координаты, например 179°59.9' Е. Кроме того, напишите конструктор, принимающий три аргумента.
        Напишите функцию main, которая сначала создает переменную с помощью трехаргументного конструктора и выводит ее значение на экран,
        а затем циклически запрашивает пользователя ввести значение координаты и отображает введенное значение на экране. Для вывода символа градусов (°) можно воспользоваться символьной константой '\xF8'.  */
    angle koordObj(144, 31.5, 'N');
    koordObj.GetKoord();
    char prodolzhenie = 'y';
    while (prodolzhenie == 'y')
    {
        koordObj.SetKoord();
        koordObj.GetKoord();
        cout << "Продолжить ввод? (введите символ 'y', если согласны или любой другой, дабы отказаться) " && cin >> prodolzhenie;
    }
}