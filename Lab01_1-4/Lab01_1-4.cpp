﻿#include <iostream>
#include <iomanip>
#include "CTYPE.H"
using std::cout;
using std::cin;
using std::endl;
using std::setw;

int main()
{
    setlocale(LC_ALL, "ru");

    /* 5)   Библиотечная функция islower() принимает в качестве аргумента один символ(букву) и возвращает ненулевое целое значение в том случае, если буква является строчной,
            и нулевое, если буква является заглавной. Описание функции хранится в файле CTYPE.H.
            Напишите программу, которая принимает букву от пользователя, а затем выводит нулевое или ненулевое значение в зависимости от того, является ли буква строчной или нет. */
    cout << "Введите символ: ";
    char c = getchar();
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

    /* 2)   Напишите программу, выводящую следующую таблицу:
            1990          135
            1991         7290
            1992        11300
            1993        16200   
            В программе использовать только один оператор с cout. */
    cout << 1990 << setw(8) << 135 << endl
        << 1991 << setw(8) << 7290 << endl
        << 1992 << setw(8) << 11300 << endl
        << 1993 << setw(8) << 16200 << endl << endl;

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
    
    /* 6)   На биржевых торгах за 1 фунт стерлингов давали $1.487, за франк — $0.172. за немецкую марку — $0.584, а за японскую йену — $0.00955. 
            Напишите программу, которая запрашивает денежную сумму в долларах, а затем выводит эквивалентные суммы в других валютах.*/

    return 0;
}