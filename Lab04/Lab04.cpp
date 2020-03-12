#include <iostream>
using namespace std;

struct time { int hours = 0, minutes = 0, seconds = 0; };

long hms_to_secs(int hours, int min, int sec);
long time_to_secs(time t1, time t2);
time secs_to_time(long totalSec);

int main()
{
    setlocale(LC_ALL, "ru");
    //5
    /*  Напишите функцию с именем hms_to_secs(), имеющую три аргумента типа int: часы, минуты и секунды. Функция должна возвращать эквивалент переданного ей временного значения в секундах (типа long). 
        Создайте программу, которая будет циклически запрашивать у пользователя ввод значения часов, минут и секунд и выводить результат работы функции на экран.   */
    char symbol, prodolzhenie = 'y';
    while (prodolzhenie == 'y')
    {
        int hours, min, sec;
        cout << "Введите время в удобном для вас формате(например, 12 34 58)\n" && cin >> hours >> symbol >> min >> symbol >> sec;
        cout << "Всего секунд: " << hms_to_secs(hours, min, sec) << "\nПродолжить вычисления?(введите 'y' если согласны, или любой другой символ, дабы отказаться)\t" && cin >> prodolzhenie;
    }

    //6
    /*  Модифицируйте программу, описанную в упражнении 11 предыдущей лабораторной работы «Структуры», складывающую два структурных значения типа time. 
        Теперь программа должна включать в себя две функции.
        Первая, time_to_secs(), принимает в качестве аргумента значение типа time и возвращает эквивалентное значение в секундах типа long.
        Вторая, secs_to_time(), в качестве аргумента принимает число секунд, имеющее тип long, а возвращает эквивалентное значение типа time.   */
    time setTime1, setTime2;
    cout << "Введите первое значение времени в формате 12:59:59" << endl;
    cin >> setTime1.hours >> symbol >> setTime1.minutes >> symbol >> setTime1.seconds;
    cout << "Введите второе значение времени в формате 12:59:59" << endl;
    cin >> setTime2.hours >> symbol >> setTime2.minutes >> symbol >> setTime2.seconds;
    long totalSec = time_to_secs(setTime1, setTime2);
    cout << "Сумма времени " << secs_to_time(totalSec).hours << secs_to_time(totalSec).minutes << secs_to_time(totalSec).seconds << endl << endl;

    //7
    /*  Взяв в качестве основы функцию power() из упражнения 2, работающую только со значением типа double, создайте перегруженные функции с этим же именем, 
        принимающими в качестве аргумента значения типа char, int, long и float. Напишите программу, вызывающую функцию power() со всеми возможными типами аргументов. */

}

long hms_to_secs(int hours, int min, int sec) { return hours * 3600 + min * 60 + sec; };

long time_to_secs(time t1, time t2)
{
    long int totalSec = t1.hours * 3600 + t1.minutes * 60 + t1.seconds + t2.hours * 3600 + t2.minutes * 60 + t2.seconds;
    return totalSec;
}

time secs_to_time(long totalSec)
{
    time stt;
    stt.hours = totalSec / 3600;
    stt.minutes = (totalSec % 3600) / 60;
    stt.seconds = (totalSec % 3600) % 60;
    return stt;
}