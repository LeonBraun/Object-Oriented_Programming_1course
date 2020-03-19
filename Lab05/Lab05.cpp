#include <iostream>
using namespace std;

enum dolzhnost { laborer = 'l', secretary = 's', manager = 'm', accountant = 'a', executive = 'e', researcher = 'r' };
//5
/*  Взяв в качестве основы структуру из задачи 5 лабораторной работы 3, создайте класс date. Его данные должны размещаться в трех полях типа int: month, day и year.
    Метод класса SetDate() должен принимать значение для объекта в формате 12/31/02, а метод GetDate() - выводить данные на экран. */
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
    dolzhnost worker;

public:
    void SetRabotnik()
    {
        static int kolvoSotrudnikov = 1;
        char bukva;

        cout << "\aCотрудник #" << kolvoSotrudnikov++ << endl;
        cout << "Личный номер и зарплата: " && cin >> numberRabotnika >> zarplata;
        cout << "Дата принятия на работу ";
        dayPrinyatiya.SetDate();
        cout << "Введите первую букву должности (laborer, secretary, manager, accountant, executive, researcher): " && cin >> bukva;
        switch (bukva)
        {
        case laborer:
            worker = dolzhnost::laborer;
            break;
        case secretary:
            worker = dolzhnost::secretary;
            break;
        case manager:
            worker = dolzhnost::manager;
            break;
        case accountant:
            worker = dolzhnost::accountant;
            break;
        case executive:
            worker = dolzhnost::executive;
            break;
        case researcher:
            worker = dolzhnost::researcher;
            break;
        default:
            cout << "Ошибка ввода\n\n";
            break;
        }
    };

    void vivodRabotnika() { cout << "Сотрудник №" << numberRabotnika << ", занимает должность " << worker << " и получает " << zarplata << ", принят на работу "; dayPrinyatiya.GetDate(); cout << endl; }
};

int main()
{
    setlocale(LC_ALL, "ru");
    //4, 6
    /*  4) Создайте класс employee, используя задачу 4 лабораторной работы 3. Класс должен включать поле типа int для хранения номера сотрудника и поле типа float для хранения величины его оклада. 
        Методы класса должны позволять пользователю вводить и отображать данные класса. 
        Напишите функцию main(), которая запросит пользователя ввести данные для трех сотрудников и выведет полученную информацию на экран. 
        
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
    r1.vivodRabotnika(); r2.vivodRabotnika(); r3.vivodRabotnika();

}