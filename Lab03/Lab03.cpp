#include <iostream>
using namespace std;

enum dolzhnost { laborer = 'l', secretary = 's', manager = 'm', accountant = 'a', executive = 'e', researcher = 'r' };

struct date
{
    int day, month, year;
};

struct employee
{
    int numberEmployee;
    float zarplata;
    date date_IN_STRUCT_employee;
    dolzhnost dolzhnost_IN_STRUCT_employee;
};

int main()
{
    setlocale(LC_ALL, "ru");
    //#4, #7
    /*  4) Создайте структуру с именем employee, содержащую два поля: номер сотрудника типа int и величину его пособия в долларах типа float.
            Запросите с клавиатуры данные о трех сотрудниках, сохраните их в трех структурных переменных типа employee и выведите информацию о каждом из сотрудников на экран.

        7) Добавьте поля типа enum etype (см. упражнение 6) и struct date (см. упражнение 5) в структуру employee из упражнения 4.
            Организуйте программу таким образом, чтобы пользователь вводил 4 пункта данных о каждом из трех сотрудников: его номер, величину зарплаты, его должность и дату принятия на работу. 
            Программа должна хранить введенные значения в трех переменных типа employee и выводить их содержимое на экран.  */
    employee s1, s2, s3;
    char bukva, symbol;
    cout << "Введите данные о трех сотрудниках: его номер, величину зарплаты, его должность и дату принятия на работу" << endl;
    
    cout << "\aПервый сотрудник" << endl;
    cout << "Номер и зарплата : " && cin >> s1.numberEmployee >> s1.zarplata;
    cout << "Введите первую букву должности (laborer, secretary, manager, accountant, executive, researcher): " && cin >> bukva;
    cout << "Дата принятия на работу: " && cin >> s1.date_IN_STRUCT_employee.day >> symbol >> s1.date_IN_STRUCT_employee.month >> symbol >> s1.date_IN_STRUCT_employee.year;

    cout << "\aВторой сотрудник" << endl;
    cout << "Номер и зарплата : " && cin >> s2.numberEmployee >> s2.zarplata;
    cout << "Введите первую букву должности (laborer, secretary, manager, accountant, executive, researcher): " && cin >> bukva;
    cout << "Дата принятия на работу: " && cin >> s2.date_IN_STRUCT_employee.day >> symbol >> s2.date_IN_STRUCT_employee.month >> symbol >> s2.date_IN_STRUCT_employee.year;

    cout << "\aТретий сотрудник" << endl;
    cout << "Номер и зарплата : " && cin >> s3.numberEmployee >> s3.zarplata;
    cout << "Введите первую букву должности (laborer, secretary, manager, accountant, executive, researcher): " && cin >> bukva;
    cout << "Дата принятия на работу: " && cin >> s3.date_IN_STRUCT_employee.day >> symbol >> s3.date_IN_STRUCT_employee.month >> symbol >> s3.date_IN_STRUCT_employee.year;


    //cout << "\nСотрудник №" << s1.numberEmployee << " получает " << s1.zarplata << '$';
        

    //#5
    /*  Создайте структуру типа date, содержащую три поля типа int: месяц, день и год. Попросите пользователя ввести день, месяц и год в формате 31/12/2002,
        сохраните введенное значение в структурной переменной, а затем извлеките данные из этой переменной и выведите их на экран в том же формате, в каком они вводились.  */
    date date1;
    cout << "Введите дату в формате '31/12/2002'" << endl;
    cin >> date1.day >> symbol >> date1.month >> symbol >> date1.year;
    cout << date1.day << symbol << date1.month << symbol << date1.year << endl;

    //#6
    /*  Как мы говорили, стандартные средства ввода/вывода C++ вместо значений перечисляемых типов данных выводят их внутреннее представление в виде целых чисел. 
        Для того чтобы преодолеть это ограничение, вы можете использовать конструкцию switch, с помощью которой устанавливается соответствие между значением переменной перечисляемого типа и ее внутренним представлением. 
        
        Пусть, например, в программе определен перечисляемый тип данных etype, отражающий должность сотрудника:
        enum etype { laborer, secretary, manager, accountant, executive, researcher };
        
        Напишите программу, которая сначала по первой букве должности, введенной пользователем, определяет соответствующее значение переменной, помещает это значение в переменную типа etype,
        а затем выводит полностью название должности, первую букву которой ввел пользователь. Взаимодействие программы с пользователем может выглядеть следующим образом:

        Введите первую букву должности (laborer, secretary, manager, accountant, executive, researcher): a
        Полное название должности: accountant

        Возможно, вам понадобится два ветвления switch: одно — для ввода значения, другое — для вывода. */
    dolzhnost worker;
    cout << "\nВведите первую букву должности (laborer, secretary, manager, accountant, executive, researcher): " && cin >> bukva;
    switch (bukva)
    {
    case laborer:
    {
        worker = dolzhnost::laborer;
        cout << "Полное название должности: laborer" << endl;
        break;
    }
    case secretary:
    {
        worker = dolzhnost::secretary;
        cout << "Полное название должности: secretary" << endl;
        break;
    }
    case manager:
    {
        worker = dolzhnost::manager;
        cout << "Полное название должности: manager" << endl;
        break;
    }
    case accountant:
    {
        worker = dolzhnost::accountant;
        cout << "Полное название должности: accountant" << endl;
        break;
    }
    case executive:
    {
        worker = dolzhnost::executive;
        cout << "Полное название должности: executive" << endl;
        break;
    }
    case researcher:
    {
        worker = dolzhnost::researcher;
        cout << "Полное название должности: researcher" << endl;
        break;
    }
    default:
        cout << "Ошибка ввода" << endl;
        break;
    }
}