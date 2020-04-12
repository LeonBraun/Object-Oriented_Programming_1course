#include <iostream>
#include <cstdlib>
#include <math.h>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

const int ARRSIZE = 100;
const float Pi = 3.14159;

class time
{
    int hours, mins, secs;
public:
    time() : hours(0), mins(0), secs(0) {} // конструктор, инициализирующий все элементы 0 по умолчанию
    time(int h, int m, int s) : hours(h), mins(m), secs(s) {} // конструтор, позволяющий присвоить значения элементам, переданными в него данными

    void GetTime() { cout << hours << ":" << mins << ":" << secs << endl; }

    time& operator + (const time& t2)
    {
        int s = secs + t2.secs;
        int m = mins + t2.mins;
        int h = hours + t2.hours;
        if (s > 59) { s -= 60; m++; }
        if (m > 59) { m -= 60; h++; }
        return *this;
    }
    time& operator ++() // префикс, добавить ко времени 1 секунду
    {
        if (++secs > 59)
        {
            secs = 0;
            mins++;
        }
        if (mins > 59)
        {
            mins = 0;
            hours++;
        }
        return *this;
    }
    time& operator --()
    {
        if (--secs < 0)
        {
            secs += 60;
            mins--;
        }
        if (mins < 0)
        {
            mins += 60;
            hours--;
        }
        return *this;
    }
    time& operator++(int) //постфикс
    {
        ++(*this);
        return *this;
    }
    time& operator--(int)
    {
        --(*this);
        return *this;
    }
    time& operator *(const float a)
    {
        this->secs *= a;
        this->mins *= a;
        this->hours *= a;
        if (this->secs > 59)
        {
            this->secs %= 60;
            this->mins += this->secs / 60;
        }
        if (this->mins > 59)
        {
            this->mins %= 60;
            this->hours += this->mins / 60;
        }
        return *this;
    }
    time& operator -(const time& t)
    {
        this->secs -= t.secs;
        this->mins -= t.mins;
        this->hours -= t.hours;
        if (this->secs < 0) { this->secs += 60; this->mins--; }
        if (this->mins < 0) { this->mins += 60; this->hours--; }
        if (this->hours < 0) this->hours = 0;
        return *this;
    }
};
class fraction
{
    int chislitel, znamenatel;
    char deistvie;
public:
    fraction()
    {
        chislitel = 1;
        znamenatel = 1;
        deistvie = ' ';
    }
    fraction(int chis, int znam) {}

    char SetDrob(fraction& d1, fraction& d2)
    {
        char symbol;
        cout << "\nВведите первый операнд(дробь), операцию и второй операнд(дробь): " && cin >> d1.chislitel >> symbol >> d1.znamenatel >> deistvie >> d2.chislitel >> symbol >> d2.znamenatel;
        if (d1 == fraction(0, 1) || d1 == fraction(1, 1) || d1 == fraction(0, 0)) { cout << "Ошибка ввода" << endl; exit(0); }
        if (d2 == fraction(0, 1) || d2 == fraction(1, 1) || d2 == fraction(0, 0)) { cout << "Ошибка ввода" << endl; exit(0); }
        return deistvie;
    }
    fraction sokrashDrobi(fraction d) //Сокращение дроби
    {
        long polozhChis, polozhZnam, vremValue, gcd;
        polozhChis = labs(d.chislitel); // Берем модули числителя и знаменателя 
        polozhZnam = labs(d.znamenatel); // Нужен cmath
        if (polozhZnam == 0)
        { // Проверка знаменателя
            cout << "Недопустимый знаменатель";
            exit(1);
        }
        else if (polozhChis == 0)
        {
            d.chislitel = 0;
            d.znamenatel = 1;
            return d;
        }
        // Нахождение наибольшего общего делителя
        while (polozhChis != 0)
        {
            if (polozhChis < polozhZnam)
            { // Если числитель больше знаменателя, меняем их местами.
                vremValue = polozhChis;
                polozhChis = polozhZnam;
                polozhZnam = vremValue;
            }
            polozhChis = polozhChis - polozhZnam;
        }
        gcd = polozhZnam;// Делим числитель и знаменатель на НОД.
        d.chislitel = d.chislitel / gcd;
        d.znamenatel = d.znamenatel / gcd;
        return d;
    }
    void GetDrob()
    {
        fraction a = sokrashDrobi(*this);
        cout << a.chislitel << '/' << a.znamenatel << endl;
    }
    fraction& operator +(const fraction& drob2)
    {
        this->chislitel = this->chislitel * drob2.znamenatel + this->znamenatel * drob2.chislitel;
        this->znamenatel = this->znamenatel * drob2.znamenatel;
        return *this;
    }
    fraction& operator -(const fraction& drob2)
    {
        this->chislitel = this->chislitel * drob2.znamenatel - this->znamenatel * drob2.chislitel;
        this->znamenatel = this->znamenatel * drob2.znamenatel;
        return *this;
    }
    fraction& operator *(const fraction& drob2)
    {
        this->chislitel = this->chislitel * drob2.chislitel;
        this->znamenatel = this->znamenatel * drob2.znamenatel;
        return *this;
    }
    fraction& operator /(const fraction& drob2)
    {
        this->chislitel = this->chislitel * drob2.chislitel;
        this->znamenatel = this->znamenatel * drob2.znamenatel;
        return *this;
    }
    bool operator ==(const fraction& d)
    {
        return this->chislitel == d.chislitel && this->znamenatel == d.znamenatel;
    }
    bool operator !=(const fraction& d)
    {
        return this->chislitel != d.chislitel && this->znamenatel != d.znamenatel;
    }
};
class safearay
{
private:
    int arr[ARRSIZE];
    int verh, niz;
public:
    safearay() {}
    safearay(int niz, int verh) { this->verh = verh; this->niz = niz; }
    int& operator [](int n)
    {
        if (n < niz || n > verh) { cout << "\nИндекс вне границ"; exit(1); }
        return arr[n];
    }
};
class Polar
{
    float rad, ugl;
public:
    Polar(float radius, float angle) : rad(radius), ugl(angle) {}
    Polar operator+(Polar p)
    {
        float x = rad * cos(ugl) + p.rad * cos(p.ugl);
        float y = rad * sin(ugl) + p.rad * sin(p.ugl);
        float tan = y / x;
        return Polar(sqrt(x * x + y * y), tan < 0 ? Pi + atan(tan) : atan(tan));
    }
    void GetR() { cout << "Радиус: " << rad << ", угол: " << ugl << endl; }
};
class bMoney
{
    long double denstr = 0;
public:
    bMoney() {};
    explicit bMoney(long double sum) : denstr(sum) {}
    long double mstold(string summa) // конвертируем строку в double (stold)
    {
        string res = "";
        for (register int i = 0; i < summa.length(); i++)
        {
            if (isdigit(summa[i]) | summa[i] == ',')
                res += summa[i];
        }
        return stold(res);
    }
    string ldtoms(long double sum)
    {
        if (sum > 9999999999999990.00) return "";
        ostringstream strs;
        strs << fixed << sum;
        string ustr = strs.str();
        string newstr = "$";

        int i;	int j;
        for (i = 0; i < ustr.length() && (ustr[i] == '0' || ustr[i] == '.'); i++); // считает "лишние" нули перед запятой И точку, если она идет СРАЗУ после нулей (например, $000456.23 -> i = 3 или 0,95 -> i = 2) 

        if (i > 1 && ustr[i - 1] == '.') i -= 2;

        if (i == ustr.length()) return "$0,00"; // Если количество "лишних" нулей вместе с точкой = длине строки, то вывод суммы "$0,00"

        for (j = ustr.length() - 1; j >= 0 && ustr[j] != '.'; j--); // кол-во знаков в числе БЕЗ запятой

        j += 2;

        for (; i <= j; i++)
        {
            if (i != 0 && i < j - 2 && (j - i + 1) % 3 == 0) //деление на три разряда
                newstr += '.';

            if (ustr[i] == '.')
                newstr += ',';
            else
                newstr += ustr[i];
        }
        return newstr;
    }
    long double Setmoney(string mon) { denstr = mstold(mon); return denstr; }
    void madd(bMoney s1, bMoney s2) { denstr = s1.denstr + s2.denstr; }
    void Getmoney() { cout << "Итог: " << ldtoms(denstr); }

    bMoney operator+(bMoney a) { return bMoney(denstr + a.denstr); }
    bMoney operator-(bMoney a) { return bMoney(denstr - a.denstr); }
    bMoney operator*(long double a) { return bMoney(denstr * a); }
    bMoney operator/(long double a) { return bMoney(denstr / a); }
    long double operator/(bMoney a) { return long double(denstr / a.denstr); }

    /*operator sterling()
    {
        return sterling(denstr / 50);
    }*/
};
class sterling
{
    long int funts;
    int shilings, pens;
public:
    sterling() { funts = 0; shilings = 0; pens = 0; }
    sterling(double x) { funts = static_cast<long int>(x);  shilings = (x - funts) * 100; pens = 0; }
    sterling(long int funts, int shilings, int pens) { this->funts = funts; this->shilings = shilings; this->pens = pens; }

    void SetSterling()
    {
        do
        {
            char symbol;
            cout << "Введите сумму фунтов, шиллингов и пенсов в формате 9.19.11\n" && cin >> funts >> symbol >> shilings >> symbol >> pens;
        } while (shilings >= 20 || pens >= 12);
    }
    void GetSterling() { cout << funts << '.' << shilings << '.' << pens << endl; }

    sterling operator+(const sterling& s2)
    {
        sterling vrem;
        vrem.pens = pens + s2.pens;
        if (vrem.pens >= 12) { vrem.shilings += vrem.pens / 12; vrem.pens %= 12; }
        vrem.shilings += shilings + s2.shilings;
        if (vrem.shilings >= 20) { vrem.funts += vrem.shilings / 20; vrem.shilings %= 20; }
        vrem.funts += funts + s2.funts;
        return vrem;
    }
    sterling operator-(const sterling& s2)
    {
        sterling vrem;
        vrem.pens = pens - s2.pens;
        if (vrem.pens < 0) { vrem.pens += 12; vrem.shilings--; }
        vrem.shilings = shilings - s2.shilings;
        if (vrem.shilings < 0) { vrem.shilings += 20; vrem.funts--; }
        vrem.funts = funts - s2.funts;
        return vrem;
    }
    sterling operator*(const double& mnozhitel)
    {
        sterling vrem;
        vrem.pens = pens * mnozhitel;
        vrem.shilings += shilings * mnozhitel;
        vrem.funts += funts * mnozhitel;
        if (vrem.pens > 12) { vrem.shilings += vrem.pens / 12; vrem.pens %= 12; }
        if (vrem.shilings >= 20) { vrem.funts += vrem.shilings / 20; vrem.shilings %= 20; }
        return vrem;
    }
    sterling operator/(const double& chastnoe)
    {
        sterling vrem;
        long int h;
        h = pens + shilings * 12 + funts * 240;
        h /= chastnoe;
        vrem.funts = h / 240;
        vrem.shilings = (h % 240) / 12;
        vrem.pens = (h % 240) % 12;
        return vrem;
    }
    long double operator/(const sterling& s2)
    {
        long double vrem1 = 0, vrem2 = 0;
        vrem1 += pens + shilings * 12 + funts * 240;
        vrem2 += s2.pens + s2.shilings * 12 + s2.funts * 240;
        return (vrem1 / vrem2);
    }
    operator bMoney()
    {
        long double cents;
        cents = funts * 5000 + shilings * 2496 + pens * 208;
        return bMoney(cents / 100);
    }
};


int main()
{
    setlocale(LC_ALL, "rus");
    //5
    /*  Пополните класс time, рассмотренный в упражнении 3, перегруженными операциями увеличения (++) и уменьшения (--), которые работают в обеих, префиксной и постфиксной, формах записи и возвращают значение.
        Дополните функцию main(), чтобы протестировать эти операции. */
    time t1(10, 59, 59);
    t1++;   t1.GetTime();   t1--;   t1.GetTime();
    ++t1;   t1.GetTime();   --t1;   t1.GetTime();
    cout << endl;

    //6
    /*  Добавьте в класс time из упражнения 5 возможность вычитать значения времени, используя перегруженную операцию -, и умножать эти значения, используя тип float и перегруженную операцию *.     */
    float a = 1.5;
    time t2(10, 20, 10);
    t2.GetTime();    t2* a;     t2.GetTime();
    t2 = t2 - t1; t2.GetTime();

    //7
    /*  Модифицируйте класс fraction в четырехфункциональном дробном калькуляторе из упражнения 11 лабораторной работы №5 так, чтобы он использовал перегруженные операции сложения, вычитания, умножения и деления.
        (Вспомните правила арифметики с дробями в упражнении 12 лабораторной работы №2 «Циклы и ветвления».) Также перегрузите операции сравнения == и != и используйте их для выхода из цикла,
        когда пользователь вводит 0/1, 0 и 1 значения двух частей дроби. Вы можете модифицировать и функцию lowterms() так, чтобы она возвращала значение ее аргумента, уменьшенное до несократимой дроби.
        Это будет полезным в арифметических функциях, которые могут быть выполнены сразу после получения ответа.    */
    char prodolzhenie = 'y';
    do
    {
        fraction d1, d2, operationNADdrob;
        char deistv = operationNADdrob.SetDrob(d1, d2);

        switch (deistv)
        {
        case'+': operationNADdrob = d1 + d2; break;
        case'-': operationNADdrob = d1 - d2; break;
        case'*': operationNADdrob = d1 * d2; break;
        case'/': operationNADdrob = d1 / d2; break;
        default: cout << "Ошибка"; break;
        }
        operationNADdrob.GetDrob();

        cout << "Выполнить еще одну операцию? (введите 'y' если согласны, или любой другой символ, дабы отказаться) " && cin >> prodolzhenie && cout << endl;
    } while (prodolzhenie == 'y');
    cout << endl;

    //8
    /*  Модифицируйте класс bМоnеу из упражнения 12 лабораторной работы №6, включив арифметические операции, выполненные с помощью перегруженных операций:

        bМоnеу = bМоnеу + bМоnеу
        bМоnеу = bМоnеу - bМоnеу
        bМоnеу = bМоnеу * long double (цена за единицу времени, затраченного на изделие)
        long double = bМоnеу / bМоnеу (общая цена, деленная на цену за изделие)
        bМоnеу = bМоnеу / long double (общая цена, деленная на количество изделий)

        Заметим, что операция / перегружена дважды. Компилятор может различить оба варианта, так как их аргументы разные.
        Помним, что легче выполнять арифметические операции с объектами класса bМоnеу, выполняя те же операции с его long double данными.

        Убедитесь, что программа main() запросит ввод пользователем двух денежных строк и числа с плавающей точкой. Затем она выполнит все пять операций и выведет результаты.
        Это должно происходить в цикле, так, чтобы пользователь мог ввести еще числа, если это понадобится.

        Некоторые операции с деньгами не имеют смысла: bМоnеу*bМоnеу не представляет ничего реального, так как нет такой вещи, как денежный квадрат;
        вы не можете прибавить bМоnеу к long double (что же будет, если рубли сложить с изделиями?).
        Чтобы сделать это невозможным, скомпилируйте такие неправильные операции, не включая операции преобразования для bМоnеу в long double или long double в bМоnеу.

        Если вы это сделаете и запишете затем выражение типа:
        bmon2 = bmonl + widgets; //это не имеет смысла

        то компилятор будет автоматически преобразовывать widgets в ЬМопеу и выполнять сложение. Без них компилятор будет отмечать такие преобразования как ошибки, что позволит легче найти концептуальные ошибки.
        Также сделайте конструкторы преобразований явными.  */
    bMoney m1, m2;
    string s1, s2;
    long double ld;
    prodolzhenie = 'y';
    do
    {
        cout << "Введите первую денежную строку: " && cin >> s1;
        cout << "Введите вторую денежную строку: " && cin >> s2;
        cout << "Введите число с плавающей запятой: " && cin >> ld;
        m1.Setmoney(s1); m2.Setmoney(s2);
        cout << "s1 + s2 = "; (m1 + m2).Getmoney();
        cout << "\ns1 - s2 = "; (m1 - m2).Getmoney();
        cout << "\ns1 * long double = "; (m1 * ld).Getmoney();
        cout << "\ns1 / s2 = " << m1 / m2;
        cout << "\ns1 / long double = "; (m1 / ld).Getmoney();
        cout << "\nПродолжить? (введите 'y' если согласны, или любой другой символ, дабы отказаться) " && cin >> prodolzhenie;
    } while (prodolzhenie == 'y');
    cout << endl;

    //9
    /*  Дополните класс safearray так, чтобы пользователь мог определять и верхнюю, и нижнюю границы массива (например, индексы, начинающиеся с 100 и заканчивающиеся 200).
        Имеем перегруженную операцию доступа к членам массива, проверяющую индексы каждый раз, когда к массиву нужен доступ, для проверки того, что мы не вышли за пределы массива.

        Вам понадобится конструктор с двумя аргументами, который определяет верхнюю и нижнюю границы. Так как мы еще не изучили, как выделять память динамически,
        то данные класса все еще будут размещаться в массиве, состоящем из 100 элементов, но вообще вы можете преобразовывать индексы массива safearray в индексы реального массива целых чисел произвольным образом.
        Например, если пользователь определил диапазон от 100 до 175, то вы можете преобразовать его в диапазон от агг[0] до агг[75]. */
    safearay sa1(10, 15);

    for (int j = 10; j < 15; j++)
        sa1[j] = j * 10;

    for (int j = 10; j < 15; j++)
    {
        int temp = sa1[j];
        cout << "Элемент " << j << " это " << temp << endl;
    }

    //10
    /*  Создайте класс Polar, который предназначен для хранения полярных координат (радиуса и угла).
        Перегрузите операцию + для выполнения сложения для объектов класса Polar.
        Сложение двух объектов выполняется путем сложения координат X объектов, а затем координат Y. Результат будет координатами новой точки.
        Таким образом, вам нужно будет преобразовать полярные координаты к прямоугольным, сложить их, а затем обратно преобразовать прямоугольные координаты результата к полярным. */
    Polar r1(25, Pi), r2(7, Pi / 2);
    r1.GetR();  r2.GetR(); (r1 + r2).GetR();
    cout << endl;

    //11
    /*  Помните структуру sterling? Преобразуйте ее в класс, имеющий переменные для фунтов (типа long), шиллингов (типа int) и пенсов (типа int).
        (Устаревшая денежная система Великобритании состояла из фунтов, шиллингов и пенсов. 1 фунт был равен 20 шиллингам, а 1 шиллинг — 12 пенсам.
        Например, запись £5.2.8 обозначала 5 фунтов, 2 шиллинга и 8 пенсов (пенс — множественное число от пенни).
        Современная денежная система, состоит только из фунтов и пенсов, причем один фунт равен 100 пенсам.
        Такой фунт называют десятичным. Таким образом, в новой денежной системе указанная сумма будет обозначаться как £5.13)

        Создайте в классе следующие функции:
        конструктор без аргументов;
        конструктор с одним аргументом типа double (для преобразования от десятичных фунтов);
        конструктор с тремя аргументами: фунтами, шиллингами и пенсами;
        метод getSterLing() для получения от пользователя значений количества фунтов, шиллингов и пенсов в формате £9.19.11;
        метод putSterling() для вывода значений количества фунтов, шиллингов и пенсов в формате £9.19.11;
        метод для сложения (sterling + sterling), используя перегруженную операцию +;
        метод вычитания (sterling - sterling), используя перегруженную операцию -;
        метод умножения (sterling * double), используя перегруженную операцию *;
        метод деления (sterling / sterling), используя перегруженную операцию /;
        метод деления (sterling / double), используя перегруженную операцию /;
        операцию double (для преобразования к типу double)

        Выполнять вычисления вы можете, например, складывая отдельно данные объекта: сложить сначала пенсы, затем шиллинги и т. д.
        Однако легче использовать операцию преобразования для преобразования объекта класса sterling к типу double, выполнить вычисления с типами double, а затем преобразовать обратно к типу sterling.    */
    sterling sum1, sum2;
    double x;
    sum1.SetSterling(); sum2.SetSterling();
    cout << "Введите double: " && cin >> x;

    cout << "Сумма: "; (sum1 + sum2).GetSterling();
    cout << "Разница: "; (sum1 - sum2).GetSterling();
    cout << "Произведение: "; (sum1 * x).GetSterling();
    cout << "Частное суммы и double: "; (sum1 / x).GetSterling();
    cout << "Частное двух сумм: " << sum1 / sum2 << endl << endl;

    //12
    /*  Напишите программу, объединяющую в себе классы bМоnеу из упражнения 8 и sterling из упражнения 11.
        Напишите операцию преобразования для преобразования между классами bМоnеу и sterling, предполагая, что один фунт (£1.0.0) равен пятидесяти долларам ($50.00).
        Это приблизительный курс обмена для XIX века, когда Британская империя еще использовала меру фунты-шиллинги-пенсы.
        Напишите программу main(), которая позволит пользователю вводить суммы в каждой из валют и преобразовывать их в другую валюту с выводом результата.
        Минимизируйте количество изменений в существующих классах bМоnеу и sterling.    */
    prodolzhenie = 'y';
    do
    {
        string denstr = "";
        bMoney m;
        sterling s;
        char symbol;

        cout << "Какую валюту собираетесь ввести? ('m' - money, 's' - sterling): " && cin >> symbol;
        switch (symbol)
        {
        case 'm':
            cout << "Введите денежную строку: " && cin >> denstr;
            m.Setmoney(denstr);
            //m.operator sterling().GetSterling();
            break;
        case's':
            s.SetSterling();
            s.operator bMoney().Getmoney();
            break;
        default:
            cout << "Ошибка ввода" << endl;
            break;
        }

        cout << "\nВыполнить еще одну операцию? (введите 'y' если согласны, или любой другой символ, дабы отказаться) " && cin >> prodolzhenie && cout << endl;
    } while (prodolzhenie = 'y');
}