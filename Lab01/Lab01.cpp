﻿#include <iostream>
#include <iomanip>
#include "CTYPE.H"
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");

    //#5
    /*  Библиотечная функция islower() принимает в качестве аргумента один символ(букву) и возвращает ненулевое целое значение в том случае, если буква является строчной,
        и нулевое, если буква является заглавной. Описание функции хранится в файле CTYPE.H.
        Напишите программу, которая принимает букву от пользователя, а затем выводит нулевое или ненулевое значение в зависимости от того, является ли буква строчной или нет. */
    cout << "Введите символ: ";
    char c = cin.get();
    if (c > 96 && c < 123)
        cout << "Это строчная буква";
    else if (c > 64 && c < 91)
        cout << "Это заглавная буква";
    else
        cout << "Это символ";
    cout << endl << endl;

    /* 1)   Считая, что кубический фут равен 7,481 галлона, написать программу, запрашивающую у пользователя число галлонов и выводящую на экран эквивалентный объем в кубических футах. */
    float gallons;
    cout << "Введите число галлонов: " && cin >> gallons;
    cout << "Эквивалентный объем в кубических футах: " << gallons / 7.481 << endl << endl;

    //#2, #8
    /* 2)   Напишите программу, выводящую следующую таблицу:
            1990          135
            1991         7290
            1992        11300
            1993        16200
            В программе использовать только один оператор с cout.

       8)   Модифицируйте так, чтобы символы, разделяющие пары значений из столбцов, были не пробелами, а точками, например: Москва.....8425785 */
    cout << setfill('.') << 1990 << setw(8) << 135 << endl
        << 1991 << setw(8) << 7290 << endl
        << 1992 << setw(8) << 11300 << endl
        << 1993 << setw(8) << 16200 << endl << endl;

    //#3
    /* 3)   Напишите программу, генерирующую следующий вывод:
            10
            20
            19
            Используйте представление числа 10 в виде целой константы. Для вывода числа 20 воспользуйтесь одной из арифметических операций с присваиванием, а для вывода числа 19 — операцией декремента. */
    const int value1 = 10;
    int value2 = 10;
    value2 += value1;
    cout << value1 << endl;
    cout << value2 << endl;
    cout << --value2 << endl << endl;

    /* 4)   Напишите программу, выводящую па экран ваше любимое стихотворение. Для разбиения на строчки используйте подходящую управляющую последовательность. */
    cout << "Как дымный столп светлеет в вышине!\nКак тень внизу скользит, неуловима!..\n\"Вот наша жизнь, — промолвила ты мне,\n—Не светлый дым, блестящий при луне,\nА эта тень, бегущая от дыма...\"\n" << endl;

    //#6
    /* 6)   На биржевых торгах за 1 фунт стерлингов давали $1.487, за франк — $0.172. за немецкую марку — $0.584, а за японскую йену — $0.00955.
            Напишите программу, которая запрашивает денежную сумму в долларах, а затем выводит эквивалентные суммы в других валютах.*/
    double dollar;
    cout << "Сумма в долларах: " && cin >> dollar;
    cout << "Фунтов стерлингов: " << dollar / 1.487 << endl << "Франков: " << dollar / 0.172 << endl << "Немецких марок: " << dollar / 0.584 << endl << "Японских йен: " << dollar / 0.00955 << endl << endl;

    //#7
    /*      Температуру, измеренную в градусах по Цельсию, можно перевести в градусы по Фаренгейту путем умножения на 9/5 и сложения с числом 32.
            Напишите программу, запрашивающую температуру в градусах по Цельсию и отображающую ее эквивалент по Фаренгейту. */
    float celsius;
    cout << "Градусов по Цельсию: " && cin >> celsius;
    cout << "Градусов по Фаренгейту: " << celsius * 1.75 + 32 << endl << endl;

    //#9
    /*  Две дроби а/b и c/d можно сложить следующим образом:
        a/b + c/d = (a*d + b*c)/(b*d)
        Например, 1/4 + 2/3 = (1*3 + 4*2)/4*3 = 11/12
        Напишите программу, запрашивающую у пользователя значения двух дробей, а затем выводящую результат, также записанный в форме дроби.
        Взаимодействие программы с пользователем может выглядеть, например, следующим образом:
        Введите первую дробь: 1/2
        Введите вторую дробь: 2/5
        Сумма равна 9/10
        Вы можете использовать тот факт, что операция извлечения >> может считывать более одного значения за раз:
        cin >> а >> dummychar >> b; */
    int a1, b1, a2, b2;
    char dummychar;
    cout << "Введите первую дробь: " && cin >> a1 >> dummychar >> b1;
    cout << "Введите вторую дробь: " && cin >> a2 >> dummychar >> b2;
    cout << "Сумма дробей: " << a1 * b2 + b1 * a2 << dummychar << b1 * b2 << endl << endl;

    //#10
    /*  Устаревшая денежная система Великобритании состояла из фунтов, шиллингов и пенсов. 1 фунт был равен 20 шиллингам, а 1 шиллинг — 12 пенсам.
        Для записи использовалась система, состоящая из знака £ и трех десятичных значений, разделенных точками.
        Например, запись £5.2.8 обозначала 5 фунтов, 2 шиллинга и 8 пенсов (пенс — множественное число от пенни).
        Современная денежная система, принятая в 50-е годы XX века, состоит только из фунтов и пенсов, причем один фунт равен 100 пенсам.
        Такой фунт называют десятичным. Таким образом, в новой денежной системе указанная сумма будет обозначаться как £5.13 (если быть точнее,£5.1333333).
        Напишите программу, которая будет преобразовывать сумму, записанную в старом формате (фунты, шиллинги, пенсы), в новый формат (фунты, пенсы).
        Форматом взаимодействия программы с пользователем может являться следующий:

        Введите количество фунтов: 7
        Введите количество шиллингов: 17
        Введите количество пенсов: 9
        Десятичных фунтов:  £7.89   */
    double f, sh, pen;
    cout << "Введите количество фунтов: " && cin >> f && cout << "Введите количество шиллингов: " && cin >> sh && cout << "Введите количество пенсов: " && cin >> pen;
    cout << "Десятичных фунтов: " << ((f * 20 * 12 + sh * 12 + 9) / 2.4) / 100 << endl << endl;

    //#12
    /*  Напишите программу, выполняющую действия, обратные тем, которые описаны в упражнении 10, то есть запрашивающую у пользователя сумму, указанную в десятичных фунтах,
    и переводящую ее в старую систему фунтов, шиллингов и пенсов. Пример взаимодействия программы с пользователем может выглядеть так:

    Введите число десятичных фунтов: 3.51
    Эквивалентная сумма в старой форме записи: £3.10.2

    Обратите внимание на то, что если вам придется присваивать вещественное значение (например, 12,34) переменной целого типа, то его дробная часть (0,34) будет потеряна, а целая переменная получит значение 12. */
    float allSum;	// сумма в десятичных фунтах
    cout << "ОБРАТНОЕ ДЕЙСТВИЕ\n" << "Введите число десятичных фунтов: " && cin >> allSum;
    int pounds = static_cast<int>(allSum); // целое количество фунтов, после отбрасывания дробной части
    float drobnayaChast = (allSum - pounds) * 100; // десятичная дробная часть, СРАЗУ переводимая в пенсы(*100)
    int shilingBezDrobnoyChast = ((pounds * 100 + drobnayaChast) * 2.4 / 12); // целое число шилингов
    float pens = (((pounds * 100 + drobnayaChast) * 2.4 / 12) - shilingBezDrobnoyChast) * 10; // остаток от разницы: шилинги (с дробной частью) - int шилинги, умножаем на * 10 = кол. пенс
    cout << "Эквивалентная сумма в старой форме записи: " << pounds << "." << shilingBezDrobnoyChast % 20 << "." << pens << endl << endl;

    //#11
    /*  По умолчанию форматирование вывода производится по правому краю поля. Можно изменить форматирование текста на левостороннее путем использования манипулятора setiosflags(ios::left)
        (не беспокойтесь о смысле новой формы записи, встретившейся в манипуляторе). Используйте этот манипулятор вместе с setw() для того, чтобы произвести следующий вывод:

    Фамилия     Имя	      Адрес 	    Город
    Петров      Василий   Кленовая 16	Санкт-Петербург
    Иванов      Сергей    Осиновая 3	Находка
    Сидоров     Иван	  Березовая 21	Калининград */
    cout << setiosflags(ios::left) << setfill(' ') <<
        setw(8) << "Фамилия" << setw(8) << "Имя" << setw(13) << "Адрес" << setw(8) << "Город" << endl <<
        setw(8) << "Петров" << setw(8) << "Василий" << setw(13) << "Кленовая 16" << setw(8) << "Санкт-Петербург" << setw(8) << endl << setw(8) <<
        setw(8) << "Иванов" << setw(8) << "Сергей" << setw(13) << "Осиновая 3" << setw(8) << "Находка" << setw(8) << endl <<
        setw(8) << "Сидоров" << setw(8) << "Иван" << setw(13) << "Березовая 21" << setw(8) << "Калининград" << endl << endl;

    return 0;
}