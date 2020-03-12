#include <iostream>
using namespace std;

int glob_kolvo_vizovov = 1;
struct time { int hours = 0, minutes = 0, seconds = 0; };
struct sterling { int pounds = 0, shillings = 0, pence = 0; };

long hms_to_secs(int hours, int min, int sec);
long time_to_secs(time t1, time t2);
time secs_to_time(long totalSec);
double power(double n, int p = 2); //по умолчанию любое число возводим во вторую степень
char power(char n, int p);
int power(int n, int p);
long power(long n, int p);
float power(float n, int p);
void swap(int& a, int& b);
void swap(time t1, time t2);
sterling vvodSummSterlng(sterling s);
sterling slozheniyeSummSterling(sterling s1, sterling s2);
void vivodSterlingSumm(sterling s);

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
        cout << "Всего секунд: " << hms_to_secs(hours, min, sec) << "\nПродолжить вычисления?(введите 'y' если согласны, или любой другой символ, дабы отказаться)\n" && cin >> prodolzhenie;
    }

    //6
    /*  Модифицируйте программу, описанную в упражнении 11 предыдущей лабораторной работы «Структуры», складывающую два структурных значения типа time. 
        Теперь программа должна включать в себя две функции.
        Первая, time_to_secs(), принимает в качестве аргумента значение типа time и возвращает эквивалентное значение в секундах типа long.
        Вторая, secs_to_time(), в качестве аргумента принимает число секунд, имеющее тип long, а возвращает эквивалентное значение типа time.   */
    time setTime1, setTime2;
    cout << "\nВведите первое значение времени в формате 12:59:59" << endl;
    cin >> setTime1.hours >> symbol >> setTime1.minutes >> symbol >> setTime1.seconds;
    cout << "Введите второе значение времени в формате 12:59:59" << endl;
    cin >> setTime2.hours >> symbol >> setTime2.minutes >> symbol >> setTime2.seconds;
    long totalSec = time_to_secs(setTime1, setTime2);
    cout << "Сумма времени " << secs_to_time(totalSec).hours << ':' << secs_to_time(totalSec).minutes << ':' << secs_to_time(totalSec).seconds << endl << endl;

    //7
    /*  Взяв в качестве основы функцию power() из упражнения 2, работающую только со значением типа double, создайте перегруженные функции с этим же именем, 
        принимающими в качестве аргумента значения типа char, int, long и float. Напишите программу, вызывающую функцию power() со всеми возможными типами аргументов. 

        Возведение числа n в степень р — это умножение числа n на себя р раз. Напишите функцию с именем power(), которая в качестве аргументов принимает значение типа double для n
        и значение типа int для р и возвращает значение типа double. Для аргумента, соответствующего степени числа, задайте значение по умолчанию, равное 2, 
        чтобы при отсутствии показателя степени при вызове функции число n возводилось в квадрат.
        Напишите функцию main(), которая запрашивает у пользователя ввод аргументов для функции power(), и отобразите на экране результаты ее работы. */
    cout << "Какой тип данных планируете возводить в степень? Введите первую букву названия типа (int, long, float, double, char).\n" && cin >> symbol;
    cout << "Введите значение: ";
    switch (symbol)
    {
        int i, stepen; long l; float f; double d; char c;
    case 'i':
        cin >> i;
        cout << "Возвести в степень " && cin >> stepen;
        cout << "Ответ: " << power(i, stepen) << endl << endl;
        break;
    case 'l':
        cin >> l;
        cout << "Возвести в степень " && cin >> stepen;
        cout << "Ответ: " << power(l, stepen) << endl << endl;
        break;
    case 'f':
        cin >> f;
        cout << "Возвести в степень " && cin >> stepen;
        cout << "Ответ: " << power(f, stepen) << endl << endl;
        break;
    case 'd':
        cin >> d;
        cout << "Возвести в степень " && cin >> stepen;
        cout << "Ответ: " << power(d, stepen) << endl << endl;
        break;
    case 'c':
        cin >> c;
        cout << "Возвести в степень " && cin >> stepen;
        cout << "Ответ: " << power(c, stepen) << endl << endl;
        break;
    default:
        cout << "Ошибка ввода" << endl << endl;
        break;
    }

    //8
    /*  Напишите функцию с именем swap(), обменивающую значениями два своих аргумента типа int (обратите внимание, что изменяться должны значения переменных из вызывающей программы, а не локальных переменных функции).
        Выберите способ передачи аргументов. Напишите вызывающую программу main(), использующую данную функцию. */
    int a, b;
    cout << "Введите числа, которые необходимо поменять местами:" << endl;
    cout << "a = " && cin >> a;
    cout << "b = " && cin >> b;
    swap(a, b);
    cout << "После замены:\ta = " << a << "\tb = " << b << endl << endl;

    //9
    /*  Переработайте программу из упражнения 8 так, чтобы функция swap() принимала в качестве аргументов значения типа time (см. упражнение 6).  */
    cout << "Введите первое значение времени в формате 12:59:59" << endl;
    cin >> setTime1.hours >> symbol >> setTime1.minutes >> symbol >> setTime1.seconds;
    cout << "Введите второе значение времени в формате 12:59:59" << endl;
    cin >> setTime2.hours >> symbol >> setTime2.minutes >> symbol >> setTime2.seconds;
    swap(setTime1, setTime2);
    cout << "Первое значение времени после функции swap " << setTime1.hours << ':' << setTime1.minutes << ':' << setTime1.seconds << endl;
    cout << "Второе значение времени после функции swap " << setTime2.hours << ':' << setTime2.minutes << ':' << setTime2.seconds << endl << endl;

    //10
    /*  Напишите функцию, которая при каждом вызове будет выводить на экран количество раз, которое она вызывалась ранее. Напишите программу, которая будет вызывать данную функцию не менее 10 раз.
        Попробуйте реализовать данную функцию двумя различными способами: с использованием глобальной переменной и статической локальной переменной для хранения числа вызовов функции.
        Какой из способов предпочтительней? Почему для решения задачи нельзя использовать обычную локальную переменную? */
    for (register int i = 0; i < 20; i++) { printRAZ(); };

    //11
    /*  Напишите программу, использующую структуру sterling, которая описана в упражнении 10 лабораторной работы 3 «Структуры».
        Программа должна получать от пользователя значения двух денежных сумм, выраженных в фунтах, шиллингах и пенсах, складывать эти значения и выводить результат на экран в том же формате.
        Необходимо разработать три функции. Первая из них должна получать от пользователя число фунтов, шиллингов и пенсов и возвращать соответствующее значение типа sterling.
        Вторая функция должна принимать в качестве аргументов два значения типа sterling, складывать их и возвращать значение, также имеющее тип sterling.
        Третья функция должна принимать аргумент типа sterling и выводить его значение на экран.    */
    sterling sum1;
    sum1 = vvodSummSterlng(sum1);
    sterling sum2;
    sum2 = vvodSummSterlng(sum2);
    sterling sumSterl = slozheniyeSummSterling(sum1, sum2);
    vivodSterlingSumm(sumSterl);


}

double power(double n, int p)
{
    double result = 1; //начать с 1
    for (int j = 0; j < p; j++) //умножить на n
        result *= n; //p раз
    return result;
}
char power(char n, int p)
{
    char result = 1; 
    for (int j = 0; j < p; j++) 
        result *= n; 
    return result;
}
int power(int n, int p)
{
    int result = 1;
    for (int j = 0; j < p; j++) 
        result *= n;
    return result;
}
long power(long n, int p)
{
    long result = 1; 
    for (int j = 0; j < p; j++) 
        result *= n; 
    return result;
}
float power(float n, int p)
{
    float result = 1; 
    for (int j = 0; j < p; j++) 
        result *= n; 
    return result;
}

void swap(int& a, int& b)
{
    int x = a;
    a = b;
    b = x;
}
void swap(time t1, time t2)
{
    int ht1 = t1.hours;
    int mt1 = t1.minutes;
    int st1 = t1.seconds;
    t1.hours = t2.hours;
    t1.minutes = t2.minutes;
    t1.seconds = t2.seconds;
    t2.hours = ht1;
    t2.minutes = mt1;
    t2.seconds = st1;
}

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

void printRAZ()
{
    if (glob_kolvo_vizovov < 10)
        cout << "Функция printRAZ была вызвана: " << glob_kolvo_vizovov++ << "раз(а)" << endl;
    else
    {
        static int kolvo_vizovov = glob_kolvo_vizovov;
        cout << "Функция printRAZ была вызвана: " << glob_kolvo_vizovov++ << "раз(а)" << endl;
    }
}

sterling vvodSummSterlng(sterling s)
{
    char symbol;
    cout << "Введите сумму в старом формате (фунты.шилинги.пенсы): ";
    cin >> s.pounds >> symbol >> s.shillings >> symbol >> s.pence;
    return s;
}
sterling slozheniyeSummSterling(sterling s1, sterling s2)
{
    unsigned long int summaPens = s1.pounds * 20 * 12 + s1.shillings * 12 + s1.pence + s2.pounds * 20 * 12 + s2.shillings * 12 + s2.pence;
    s1.pounds = summaPens / 240;
    s1.shillings = (summaPens % 240) / 12;
    s1.pence = (summaPens % 240) % 12;
    return s1;
}
void vivodSterlingSumm(sterling s) { cout << "Сумма стерлингов: " << s.pounds << '.' << s.shillings << '.' << s.pence << endl << endl; };

long hms_to_secs(int hours, int min, int sec) { return hours * 3600 + min * 60 + sec; };