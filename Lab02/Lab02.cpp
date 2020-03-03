﻿#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");

    //#1
    /*  Предположим, вы хотите создать таблицу умножения на заданное число.
        Напишите программу, которая позволяет пользователю ввести это число,
        а затем генерирует таблицу размером 20 строк на 10 столбцов. Первые
        строки результата работы программы должны выглядеть примерно следующим образом:
        Введите число: 7 
        7142128354249566370 
        77849198105112119126133140 
        147154161168175182189196203210  */
    unsigned long int a;
    cout << "Введите число: " && cin >> a;
    int k = 0;
    for (register int i = 0; i < 20; i++) 
    {
        for (register int j = 0; j < 10; j++) 
        {
            cout << a * ++k << ' ';
        }
        cout << endl;
    }

    //#2
    /*  Напишите программу, предлагающую пользователю осуществить перевод температуры из шкалы Цельсия в шкалу Фаренгейта или наоборот, а затем осуществите преобразование. 
        Используйте в программе переменные вещественного типа. Взаимодействие программы с пользователем может выглядеть следующим образом:
        Начните 1 для перевода шкалы Цельсия в шкалу Фаренгейта. 
        2 для перевода шкалы Фаренгейта в шкалу Цельсия: 1 
        Введите температуру по Фаренгейту: 70 
        Значение по Цельсию: 21.111111  */

}