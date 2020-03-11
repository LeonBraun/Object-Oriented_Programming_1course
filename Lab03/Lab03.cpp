#include <iostream>
using namespace std;

enum dolzhnost { laborer = 'l', secretary = 's', manager = 'm', accountant = 'a', executive = 'e', researcher = 'r' };

struct date { int day, month, year; };
struct time { int hours = 0, minutes = 0, seconds = 0; };
struct sterling { int pounds, shillings, pence; };
struct drobi { int chislitel, znamenatel; };
struct employee
{
    int numberEmployee;
    float zarplata;
    date date_IN_STRUCT_employee;
    dolzhnost dolzhnost_IN_STRUCT_employee;
};


void VvodDannihSotrudnika(employee& rab);
string VivodPolnRabotaName(employee& rab);

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

    cout << "Введите данные о трех сотрудниках: его номер, величину зарплаты, его должность и дату принятия на работу" << endl;
    VvodDannihSotrudnika(s1);
    VvodDannihSotrudnika(s2);
    VvodDannihSotrudnika(s3);

    cout << "\nСотрудник №" << s1.numberEmployee << ", нанятый " << s1.date_IN_STRUCT_employee.day << '/' << s1.date_IN_STRUCT_employee.month << '/' << s1.date_IN_STRUCT_employee.year 
        << ", получает " << s1.zarplata << "$ и занимает должность " << VivodPolnRabotaName(s1);
    cout << "\nСотрудник №" << s2.numberEmployee << ", нанятый " << s2.date_IN_STRUCT_employee.day << '/' << s2.date_IN_STRUCT_employee.month << '/' << s2.date_IN_STRUCT_employee.year
        << ", получает " << s2.zarplata << "$ и занимает должность " << VivodPolnRabotaName(s2);
    cout << "\nСотрудник №" << s3.numberEmployee << ", нанятый " << s3.date_IN_STRUCT_employee.day << '/' << s3.date_IN_STRUCT_employee.month << '/' << s3.date_IN_STRUCT_employee.year
        << ", получает " << s3.zarplata << "$ и занимает должность " << VivodPolnRabotaName(s3) << endl << endl;
        
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
        Полное название должности: accountant */
    dolzhnost worker;
    char bukva;
    cout << "\nВведите первую букву должности (laborer, secretary, manager, accountant, executive, researcher): " && cin >> bukva;
    switch (bukva)
    {
    case laborer:
    {
        worker = dolzhnost::laborer;
        cout << "Полное название должности: laborer\n\n";
        break;
    }
    case secretary:
    {
        worker = dolzhnost::secretary;
        cout << "Полное название должности: secretary\n\n";
        break;
    }
    case manager:
    {
        worker = dolzhnost::manager;
        cout << "Полное название должности: manager\n\n";
        break;
    }
    case accountant:
    {
        worker = dolzhnost::accountant;
        cout << "Полное название должности: accountant\n\n";
        break;
    }
    case executive:
    {
        worker = dolzhnost::executive;
        cout << "Полное название должности: executive\n\n";
        break;
    }
    case researcher:
    {
        worker = dolzhnost::researcher;
        cout << "Полное название должности: researcher\n\n";
        break;
    }
    default:
        cout << "Ошибка ввода\n\n";
        break;
    }

    //#8
    /*  Вернитесь к упражнению 9 комплекта заданий 1. В этом упражнении требуется написать программу, которая хранит значения двух дробей в виде числителя и знаменателя, 
        а затем складывает эти дроби согласно арифметическому правилу. Измените эту программу так, чтобы значения дробей хранились в структуре fraction, состоящей из двух полей типа int,
        предназначенных для хранения числителя и знаменателя. Все значения дробей должны храниться в переменных типа fraction.  */
    drobi drob1, drob2;
    cout << "Введите первую дробь: " && cin >> drob1.chislitel >> symbol >> drob1.znamenatel;
    cout << "Введите вторую дробь: " && cin >> drob2.chislitel >> symbol >> drob2.znamenatel;
    cout << "Сумма дробей: " << drob1.chislitel * drob2.znamenatel + drob1.znamenatel * drob2.chislitel << symbol << drob1.znamenatel * drob2.znamenatel << endl << endl;

    //#9
    /*  Создайте структуру с именем time. Три ее поля, имеющие тип int. будут называться hours, minutes и seconds. 
        Напишите программу, которая просит пользователя ввести время в формате часы, минуты, секунды. 
        Можно запрашивать на ввод как три значения сразу, так и выводить для каждой величины отдельное приглашение. 
        Программа должна хранить время в структурной переменной типа time и выводить количество секунд в введенном времени, определяемое следующим образом:
        long totalsecs = t1.hours*3600 + t1.minutes*60 + t1.seconds */
    time setTime1;
    cout << "Желаете ввести время в полном формате?\n(введите 'y' если согласны, или любой другой символ, дабы отказаться)\n" && cin >> symbol;
    if (symbol == 'y')
    {
        cout << "Введите время в удобном для вас формате(например, 12 43 54)" << endl;
        cin >> setTime1.hours >> symbol >> setTime1.minutes >> symbol >> setTime1.seconds;
    }
    else
    {
        cout << "Обозначить количество часов?\n(введите 'y' если согласны, или любой другой символ, дабы отказаться)\n" && cin >> symbol;
        if (symbol == 'y')
            cout << "Часов: " && cin >> setTime1.hours;
        cout << "Обозначить количество минут?\n(введите 'y' если согласны, или любой другой символ, дабы отказаться)\n" && cin >> symbol;
        if (symbol == 'y')
            cout << "Минут: " && cin >> setTime1.minutes;
        cout << "Обозначить количество секунд?\n(введите 'y' если согласны, или любой другой символ, дабы отказаться)\n" && cin >> symbol;
        if (symbol == 'y')
            cout << "Секунд: " && cin >> setTime1.seconds;
    }
    cout << "Всего секунд: " << setTime1.hours * 3600 + setTime1.minutes * 60 + setTime1.seconds << endl << endl;

    //10
    /*  Создайте структуру с именем sterling, хранящую денежные суммы в старой английской системе, описанной в упражнениях 8 и 11 комплекса заданий 2.
        Поля структуры могут быть названы pounds, shillings и pence и иметь тип int. Программа должна запрашивать у пользователя значение денежной суммы в новых десятичных фунтах
        (значение должно храниться в переменной типа double), затем переводить эту сумму в старую систему, сохранять переведенное значение в переменной типа sterling.
        А затем выводить на экран полученную сумму в фунтах, шиллингах и пенсах.  */
    sterling starSumma;
    double desSumma;
    cout << "Денежная сумма в десятичных фунтах: " && cin >> desSumma;
    starSumma.pounds = static_cast<int>(desSumma);
    float drobnayaChast = (desSumma - starSumma.pounds) * 100; // десятичная дробная часть, СРАЗУ переводимая в пенсы(*100)
    starSumma.shillings = ((starSumma.pounds * 100 + drobnayaChast) * 2.4 / 12); // целое число шилингов
    starSumma.pence = (((starSumma.pounds * 100 + drobnayaChast) * 2.4 / 12) - starSumma.shillings) * 10; // остаток от разницы: шилинги (с дробной частью) - int шилинги, умножаем на * 10 = кол. пенс
    cout << "Эквивалентная сумма в старой форме записи: " << starSumma.pounds << "." << starSumma.shillings % 20 << "." << starSumma.pence << endl << endl;

    //11
    /*  Используя структуру time из упражнения 9, напишите программу, которая получает от пользователя два значения времени в формате 12:59:59, сохраняет их в переменных типа struct time,
        затем переводит оба значения в секунды, складывает их, переводит сумму в исходный формат, сохраняет его в переменной типа time и выводит полученный результат на экран в формате 12:59:59.  */
    time setTime2;
    cout << "Введите первое значение времени в формате 12:59:59" << endl;
    cin >> setTime1.hours >> symbol >> setTime1.minutes >> symbol >> setTime1.seconds;
    cout << "Введите второе значение времени в формате 12:59:59" << endl;
    cin >> setTime2.hours >> symbol >> setTime2.minutes >> symbol >> setTime2.seconds;
    unsigned long int totalSec = setTime1.hours * 3600 + setTime1.minutes * 60 + setTime1.seconds + setTime2.hours * 3600 + setTime2.minutes * 60 + setTime2.seconds;
    setTime1.hours = totalSec / 3600;
    setTime1.minutes = (totalSec % 3600) / 60;
    setTime1.seconds = (totalSec % 3600) % 60;
    cout << "Сумма времени " << setTime1.hours << ':' << setTime1.minutes << ':' << setTime1.seconds << endl << endl;

    //12
    /*  Переработайте программу-калькулятор для дробей, описанную в упражнении 12 комплекта упражнений 2 так,
        чтобы каждая из дробей хранилась как значение переменной типа struct fraction, по аналогии с упражнением 8 этого комплекса упражнений.  */
    char prodolzhenie = 'y';
    do
    {
        drobi drob1, drob2;
        char symbol, operachiya;

        cout << "Введите первый операнд(дробь), операцию и второй операнд(дробь): ";
        cin >> drob1.chislitel >> symbol >> drob1.znamenatel >> operachiya >> drob2.chislitel >> symbol >> drob2.znamenatel;

        switch (operachiya)
        {
        case '+':
        {
            cout << "Сумма: " << (drob1.chislitel * drob2.znamenatel + drob1.znamenatel * drob2.chislitel) << '/' << (drob1.znamenatel * drob2.znamenatel) << endl;
            cout << "Выполнить еще одну операцию (y/n)?" << endl && cin >> prodolzhenie;
            break;
        }

        case '-':
        {
            cout << "Разность: " << (drob1.chislitel * drob2.znamenatel - drob1.znamenatel * drob2.chislitel) << '/' << (drob1.znamenatel * drob2.znamenatel) << endl;
            cout << "Выполнить еще одну операцию(y/n)?" << endl && cin >> prodolzhenie;
            break;
        }

        case '/':
        {
            cout << "Частное: " << (drob1.chislitel * drob2.chislitel) << '/' << (drob1.znamenatel * drob2.znamenatel) << endl;
            cout << "Выполнить еще одну операцию(y/n)?" << endl && cin >> prodolzhenie;
            break;
        }

        case '*':
        {
            cout << "Произведение: " << (drob1.chislitel * drob2.chislitel) << '/' << (drob1.znamenatel * drob2.znamenatel) << endl;
            cout << "Выполнить еще одну операцию(y/n)?" << endl && cin >> prodolzhenie;
            break;
        }

        default:
            cout << "Некорректный ввод" << endl;
            break;
        }
    } while (prodolzhenie == 'y');
}

void VvodDannihSotrudnika(employee& rab)
{
    static int kolvoSotrudnikov = 1;
    char bukva, symbol;
    cout << "\aCотрудник #" << kolvoSotrudnikov++ << endl;
    cout << "Личный номер и зарплата: " && cin >> rab.numberEmployee >> rab.zarplata;
    cout << "Введите первую букву должности (laborer, secretary, manager, accountant, executive, researcher): " && cin >> bukva;
    cout << "Дата принятия на работу: " && cin >> rab.date_IN_STRUCT_employee.day >> symbol >> rab.date_IN_STRUCT_employee.month >> symbol >> rab.date_IN_STRUCT_employee.year;
    switch (bukva)
    {
    case laborer:
        rab.dolzhnost_IN_STRUCT_employee = dolzhnost::laborer;
        break;
    case secretary:
        rab.dolzhnost_IN_STRUCT_employee = dolzhnost::secretary;
        break;
    case manager:
        rab.dolzhnost_IN_STRUCT_employee = dolzhnost::manager;
        break;
    case accountant:
        rab.dolzhnost_IN_STRUCT_employee = dolzhnost::accountant;
        break;
    case executive:
        rab.dolzhnost_IN_STRUCT_employee = dolzhnost::executive;
        break;
    case researcher:
        rab.dolzhnost_IN_STRUCT_employee = dolzhnost::researcher;
        break;
    default:
        cout << "Ошибка ввода!!!" << endl;
        break;
    }
}

string VivodPolnRabotaName(employee& rab)
{
    switch (rab.dolzhnost_IN_STRUCT_employee)
    {
    case laborer:
        return "laborer";
        break;
    case secretary:
        return "secretary";
        break;
    case manager:
        return "manager";
        break;
    case accountant:
        return "accountant";
        break;
    case executive:
        return "executive";
        break;
    case researcher:
        return "researcher";
        break;
    default:
        return "Ошибка ввода!!!";
        break;
    }
}