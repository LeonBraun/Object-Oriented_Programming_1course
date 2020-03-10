#include <iostream>
using namespace std;

struct employee
{
    int numberEmployee;
    float posobiye;
};

struct date
{
    int day, month, year;
};

enum dolzhnost { laborer = 'l', secretary = 's', manager = 'm', accountant = 'a', executive = 'e', researcher = 'r' };

int main()
{
    setlocale(LC_ALL, "ru");
    //#4
    /*  Создайте структуру с именем employee, содержащую два поля: номер сотрудника типа int и величину его пособия в долларах типа float.
        Запросите с клавиатуры данные о трех сотрудниках, сохраните их в трех структурных переменных типа employee и выведите информацию о каждом из сотрудников на экран.  */
    employee s1, s2, s3;
    cout << "Введите данные о трех сотрудниках: номер сотрудника и величину его пособия (для каждого сотрудника вводить данные через пробел)" << endl;
    cout << "Первый сотрудник: " && cin >> s1.numberEmployee >> s1.posobiye&&
        cout << "Второй сотрудник: " && cin >> s2.numberEmployee >> s2.posobiye&&
        cout << "Третий сотрудник: " && cin >> s3.numberEmployee >> s3.posobiye;

    cout << "\nСотрудник №" << s1.numberEmployee << " получает " << s1.posobiye << '$'
        << "\nСотрудник №" << s2.numberEmployee << " получает " << s2.posobiye << '$'
        << "\nСотрудник №" << s3.numberEmployee << " получает " << s3.posobiye << '$' << endl << endl;

    //#5
    /*  Создайте структуру типа date, содержащую три поля типа int: месяц, день и год. Попросите пользователя ввести день, месяц и год в формате 31/12/2002,
        сохраните введенное значение в структурной переменной, а затем извлеките данные из этой переменной и выведите их на экран в том же формате, в каком они вводились.  */
    date date1;
    char symbol;
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
    char bukva;
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

    //#7
    /*  Добавьте поля типа enum etype (см. упражнение 6) и struct date (см. упражнение 5) в структуру employee из упражнения 4.
        Организуйте программу таким образом, чтобы пользователь вводил 4 пункта данных о каждом из трех сотрудников: его номер, величину зарплаты, его должность и дату принятия на работу. 
        Программа должна хранить введенные значения в трех переменных типа employee и выводить их содержимое на экран.  */

}