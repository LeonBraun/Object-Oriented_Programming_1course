
#include <iostream>
#include <cstdlib>
#include <math.h>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

const int LEN = 80;
const int LIMIT = 100;

class publication
{
    string nameDisk;
    float price;
public:
    void SetData()
    {
        cout << "Введите название диска: " && cin >> nameDisk;
        cout << "Обозначьте цену: " && cin >> price;
    }
    void GetData() const
    {
        cout << "\nНазвание: " << nameDisk << endl;
        cout << "Цена: " << price << endl;
    }
};
class publication2 : public publication
{
    string dataVihoda;
public:
    void SetData() { publication::SetData(); cout << "Дата выхода(string): " && cin >> dataVihoda; }
    void GetData() const { publication::GetData(); cout << "Дата выхода " << dataVihoda << endl; }
};
class book : public publication2
{
    int pages;
public:
    void SetData()
    {
        publication2::SetData();
        cout << "Введите номер страницы: " && cin >> pages;
    }
    void GetData() const
    {
        publication2::GetData();
        cout << "Страница: " << pages << endl << endl;
    }
};
class type : public publication2
{
    float time;
public:
    void SetData()
    {
        publication2::SetData();
        cout << "Введите время воспроизведения: " && cin >> time;
    }
    void GetData() const
    {
        publication2::GetData();
        cout << "\nИграющее время: " << time;
    }
};
class sales
{
private:
    enum { MONTHS = 3 };
    float salesArr[MONTHS];
public:
    void SetData();
    void GetData() const;
};
void sales::SetData()
{
    cout << "Enter sales for 3 months\n";
    for (int j = 0; j < MONTHS; j++)
    {
        cout << "Month " << j + 1 << ": ";
        cin >> salesArr[j];
    }
}
void sales::GetData() const
{
    for (int j = 0; j < MONTHS; j++)
    {
        cout << "\nSales for month " << j + 1 << ": ";
        cout << salesArr[j];
    }
}
class disk : public publication, public sales
{
    enum cd_dvd { CD = 'c', DVD = 'd' } vid;
public:
    void SetData()
    {
        publication::SetData();
        char symbol;
        cout << "Выберите тип диска(c/d): " && cin >> symbol;
        switch (symbol)
        {
        case CD: {vid = CD; break; }
        case DVD: {vid = DVD; break; }
        default: {cout << "Ошибка ввода" << endl; break; }
        }
        sales::SetData();
    }
    void GetData()
    {
        publication::GetData();
        cout << "Вид: ";
        switch (vid)
        {
        case CD: {cout << "CD"; break; }
        case DVD: {cout << "DVD"; break; }
        default: {cout << "Ошибка"; break; }
        }
        sales::GetData();
    }
};
class employee
{
private:
    char name[LEN];
    unsigned long number;
public:
    void SetData()
    {
        cout << "Введите имя сотрудника: " && cin >> name;
        cout << "Его номер: " && cin >> number;
    }
    void GetData() const
    {
        cout << "Имя: " << name << endl;
        cout << "Номер: " << number << endl;
    }
};
class employee2 : public employee
{
    double oplata;
    enum period { HOURS = 'h', WEEK = 'w', MONTH = 'm' } per;
public:
    void SetData()
    {
        employee::SetData();
        char symbol;
        cout << "Выберите период оплаты (hours = 'h', week = 'w', month = 'm'): " && cin >> symbol;
        switch (symbol)
        {
        case HOURS: {per = HOURS; break; }
        case WEEK: {per = WEEK; break; }
        case MONTH: {per = MONTH; break; }
        default: {cout << "Ошибка ввода" << endl; break; }
        }
        cout << "Оплата($): " && cin >> oplata;
    }
    void GetData()
    {
        employee::GetData();
        cout << "Получает " << oplata;
        switch (per)
        {
        case HOURS: {cout << "$ в час" << endl; break; }
        case WEEK: {cout << "$ в неделю" << endl; break; }
        case MONTH: {cout << "$ в месяц" << endl; break; }
        default: {cout << "Ошибка" << endl; break; }
        }
    }
};
class safearay
{
private:
    int arr[LIMIT];
public:
    int& operator [](int n)
    {
        if (n < 0 || n >= LIMIT)
        {
            cout << "Index out of bounds\n"; exit(1);
        }
        return arr[n];
    }
};
class safearay2 : public safearay
{
    int verh, niz;
public:
    safearay2(int niz, int verh) { this->verh = verh; this->niz = niz; }
    int& operator [](int n) { return safearay::operator[](n >= verh ? LIMIT : n - niz); }
};
class Counter
{
protected:
    unsigned int count;
public:
    Counter() : count(0) {}
    Counter(int c) : count(c) {}
    unsigned int get_count() const { return count; }
    Counter operator ++ () { return Counter(++count); }
};
class CountDn : public Counter
{
public:
    CountDn() : Counter() {}
    CountDn(int c) : Counter(c) {}
    CountDn operator -- () { return CountDn(--count); }
};
class CountPost : public CountDn
{
public:
    CountPost operator++(int) { count++; return *this; }
    CountPost operator--(int) { count--; return *this; }
    void GetP() { cout << count << endl; }
};
class String
{
protected:
    enum { SIZE = 80 };
    char str[SIZE];
public:
    String() { str[0] = '\0'; }
    String(char s[]) { strcpy_s(str, s); }

    void GetStr() const { cout << str << endl; }

    operator char* () { return str; }
};
class Pstring : public String
{
public:
    Pstring(const char s[])
    {
        if (strlen(s) > SIZE - 1)
        {
            int j = 0;
            for (; j < SIZE - 1; j++)
                str[j] = s[j];
            str[j] = '\0';
        }
        else
            strcpy_s(str, s);
    }
};
class Pstring2 : public Pstring
{
public:
    Pstring2(const char s[]) : Pstring(s) {}

    Pstring2 Left(int s)
    {
        Pstring2 newstr = "";
        int i = 0;
        for (; i < s; i++) { newstr[i] = str[i]; }
        newstr[i] = '\0';
        return newstr;
    }
    Pstring2 Right(int s)
    {
        Pstring2 newstr = "";
        int i = strlen(str) - s;
        int k = 0;
        for (; i < strlen(str); i++) {
            newstr[k++] = str[i];
        }
        newstr[k] = '\0';
        return newstr;
    }
    Pstring2 Mid(int kol, int nach)
    {
        Pstring2 newstr = "";
        int i = kol;
        int k = 0;
        for (; i > 0; i--) { newstr[k++] = str[nach++]; }
        newstr[k] = '\0';
        return newstr;
    }
};
class student
{
    char school[LEN];
    char degree[LEN];
public:
    void SetEdu()
    {
        cout << "Введите название школы или университета: " && cin >> school;
        cout << "Введите самую высокую заработанную степень (Highschool, Bachelor's, Master's, PhD)\n" && cin >> degree;
    }
    void GetEdu() const
    {
        cout << "Школа или университет: " << school;
        cout << "Самая высокая ученая степень: " << degree;
    }
};
class manager : public employee, public student
{
    char title[LEN];
    double dues;
public:
    void SetData()
    {
        employee::SetData();
        cout << "Введите название: " && cin >> title;
        cout << "Введите взносы в гольф-клуб: " && cin >> dues;
        student::SetEdu();
    }
    void GetData() const
    {
        employee::GetData();
        cout << "\n   Title: " << title;
        cout << "\n   Golf club dues: " << dues;
        student::GetEdu();
    }
};
class scientist : public employee, public student
{
    int pubs;
public:
    void SetData()
    {
        employee::SetData();
        cout << "Введите количество пабов: " && cin >> pubs;
        student::SetEdu();
    }
    void GetData() const
    {
        employee::GetData();
        cout << "Номер публикации: " << pubs << endl;
        student::GetEdu();
    }
};
class laborer : public employee {};
class executive : public manager
{
    int premia, kolvoAk;
public:
    void SetData()
    {
        manager::SetData();
        cout << "Размер годовой премии: " && cin >> premia;
        cout << "Количество его акций в компании: " && cin >> kolvoAk;
    }
    void GetData()
    {
        manager::GetData();
        cout << "Размер годовой премии: " << premia << endl;
        cout << "Количество его акций в компании: " << kolvoAk << endl;
    }
};
class Pair
{
public:
    int x, y;
    Pair() : x(0), y(0) {}
    Pair(int x, int y) { this->x = x; this->y = y; }
};
class Stack
{
protected:
    enum { MAX = 10 }; // размер стека
    int st[MAX]; // данные, хранящиеся в стеке
    int top; // индекс последнего элемента в стеке
public:
    Stack() { top = -1; }
    void push(int var) { st[++top] = var; } // помещение числа в стек
    int pop() { return st[top--]; } // извлечение числа из стека
};
class Stack2 : public Stack
{
public:
    void push(int var) // помещение числа в стек
    {
        if (top >= MAX - 1) { cout << "\nОшибка: стек полон"; exit(1); } // если стек полон, то ошибка
        Stack::push(var); // вызов функции push класса Stack
    }
    int pop() // извлечение числа из стека
    {
        if (top < 0) { cout << "\nОшибка: стек пуст\n"; exit(1); } // если стек пуст, то ошибка
        return Stack::pop(); // вызов функции pop класса Stack(можно без return)
    }
};
class pairStack : public Stack2
{
public:
    void push(Pair a)
    {
        Stack::push(a.x);
        Stack::push(a.y);
    }
    Pair pop()
    {
        int x = Stack::pop();
        int y = Stack::pop();
        return Pair(x, y);
    }
};
class sterling
{
protected:
    int funts;
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
            cout << "Введите сумму фунтов, шиллингов и пенсов в формате 9.19.11-1/4\n" && cin >> funts >> symbol >> shilings >> symbol >> pens;
        } while (shilings >= 20 || pens >= 12);
    }
    void GetSterling() { cout << funts << '.' << shilings << '.' << pens; }
    int GetFunts() { return funts; }
    int GetShilings() { return shilings; }
    int GetPens() { return pens; }

    sterling operator+(const sterling& ster2)
    {
        sterling vrem(0, 0, 0);
        vrem.pens = pens + ster2.pens;
        if (vrem.pens >= 12) { vrem.shilings += vrem.pens / 12; vrem.pens %= 12; }
        vrem.shilings += shilings + ster2.shilings;
        if (vrem.shilings >= 20) { vrem.funts += vrem.shilings / 20; vrem.shilings %= 20; }
        vrem.funts += funts + ster2.funts;
        return vrem;
    }
    sterling operator-(const sterling& ster2)
    {
        sterling vrem;
        vrem.pens = pens - ster2.pens;
        if (vrem.pens < 0) { vrem.pens += 12; vrem.shilings--; }
        vrem.shilings = shilings - ster2.shilings;
        if (vrem.shilings < 0) { vrem.shilings += 20; vrem.funts--; }
        vrem.funts += funts - ster2.funts;
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
};
class sterfrac :public sterling
{
    int eighths;
public:
    sterfrac() : sterling() {}
    sterfrac(sterling a) { this->funts = a.GetFunts(); this->shilings = a.GetShilings(); this->pens = a.GetPens(); }
    sterfrac(long pound, int shil, int pence) : sterling(funts, shilings, pens) {}
    void SetSterling()
    {
        sterling::SetSterling();
        char symbol;
        int a, b;
        cin >> symbol >> a >> symbol >> b;
        eighths = a * 8 / b;
    }
    void GetSterling()
    {
        sterling::GetSterling();
        int tnum, tden, temp;
        tnum = eighths;
        tden = 8;
        while (tnum != 0) {
            if (tnum < tden) {
                temp = tnum;
                tnum = tden;
                tden = temp;
            }
            tnum -= tden;
        }
        if (eighths == 0)
            cout << "-0";
        else
            cout << '-' << eighths / tden << '/' << 8 / tden << endl;
    }

    sterfrac operator+(const sterfrac& s2)
    {
        sterfrac vrem;
        vrem.eighths = eighths + s2.eighths;
        if (vrem.eighths > 8) { pens++; vrem.eighths %= 8; };
        sterling a = sterling::operator+(sterling(s2));
        sterfrac itog(a);
        itog.eighths = vrem.eighths;
        return itog;
    }
    sterfrac operator-(const sterfrac& s2)
    {
        sterfrac vrem;
        vrem.eighths = eighths - s2.eighths;
        if (vrem.eighths > 8 || vrem.eighths < 0) { pens--; vrem.eighths %= 8; }
        sterling a = sterling::operator-(sterling(s2));
        sterfrac itog(a);
        itog.eighths = abs(vrem.eighths);
        return itog;
    }
    sterfrac operator*(const double& mnozhitel)
    {
        sterfrac vrem;
        vrem.eighths = eighths * mnozhitel;
        sterling a = sterling::operator*(mnozhitel);
        sterfrac itog(a);
        if (vrem.eighths > 8) { itog.pens++; vrem.eighths %= 8; };
        itog.eighths = vrem.eighths;
        return itog;
    }
    sterfrac operator/(const double& chastnoe)
    {
        sterfrac vrem;
        vrem.eighths = eighths / chastnoe;
        sterling a = sterling::operator/(chastnoe);
        sterfrac itog(a);
        if (vrem.eighths > 8) { itog.pens++; vrem.eighths %= 8; };
        itog.eighths = vrem.eighths;
        return itog;
    }
    long double operator/(const sterfrac& s2)
    {
        sterfrac vrem(s2);
        if (((double)eighths / 8) + ((double)s2.eighths / 8) >= 1) vrem.pens++;
        return sterling::operator/(sterling(vrem));
    }
};

int main()
{
    setlocale(LC_ALL, "rus");
    //4
    /*  Предположим, что издатель из упражнений 1 и 3 решил добавить к своей продукции версии книг на компьютерных дисках для тех, кто любит читать книги на своих компьютерах.
        Добавьте класс disk, который, как book и type, является производным класса publication. Класс disk должен включать в себя те же функции, что и в других классах.
        Полем только этого класса будет тип диска: CD или DVD. Для хранения этих данных вы можете ввести тип enum. Пользователь должен выбрать подходящий тип, набрав на клавиатуре с или d.    */
    disk a; a.SetData(); a.GetData();

    //5
    /*  Создайте производный класс employee2 от базового класса employee (приведён выше).
        Добавьте в новый класс поле compensation типа double и поле period типа enum для обозначения периода оплаты работы служащего: почасовая, понедельная или помесячная. */
    employee2 rab; rab.SetData(); rab.GetData();

    //6
    /*  Используя наследование, добавьте к классу, который приведён выше, возможность для пользователя определять верхнюю и нижнюю границы массива в конструкторе. */
    safearay2 sf2(10, 15);
    for (int j = 10; j < 15; j++)
        sf2[j] = j * 10;
    for (int j = 10; j <= 15; j++) { int temp = sf2[j]; cout << "Элемент " << j << " это " << temp << endl; }

    //7
    /* Используя наследование на приведённом ниже классе, добавьте возможность использования постфиксных операций для случаев увеличения и уменьшения. */
    CountPost cp; cp++; cp--; cp.GetP();

    //8
    /*  В некоторых компьютерных языках, таких, как Visual Basic, есть операции, с помощью которых можно выделить часть строки и присвоить ее другой строке.
        Используя наследование, добавьте такую возможность в класс Pstring из упражнения 2.
        В новом производном классе Pstring2 разместите три новых функции: left(), mid() и right(), которые будут принимать:
        Left() – один аргумент, количество символов, которое будет вырезано с левого края
        Right() – один аргумент, количество символов, которое будет вырезано с правого края
        Mid() – два аргумента. Первый – количество символов, которое будет вырезано, второй – с какого символа начинать резать. */
    Pstring2 ps2 = "PrimerStroki";
    ps2.Left(3).GetStr();
    ps2.Right(3).GetStr();
    ps2.Mid(4, 4).GetStr();

    //9
    /*  Вспомним классы publication, book и type из упражнения 1. Предположим, что мы хотим добавить в классы book и type дату выхода книги.
        Создайте новый производный класс publication2, который является производным класса publication и включает в себя поле, хранящее эту дату.
        Затем измените классы book и type так, чтобы они стали производными класса publication2 вместо publication.
        Сделайте необходимые изменения функций классов так, чтобы пользователь мог вводить и выводить дату выхода книги. */
    book bk; bk.SetData(); bk.GetData();
    type tp; tp.SetData(); tp.GetData();

    //10
    /*  Создайте производный от класса manager класс executive. (Мы предполагаем, что управляющий — это главный менеджер.)
        Добавочными данными этого класса будут размер годовой премии и количество его акций в компании. Добавьте подходящие методы для этих данных, позволяющие их вводить и выводить.  */
    manager m1;
    scientist s1, s2;
    laborer l1;
    cout << "\nEnter data for manager 1";
    m1.SetData();
    cout << "\nEnter data for scientist 1";
    s1.SetData();
    cout << "\nEnter data for scientist 2";
    s2.SetData();
    cout << "\nEnter data for laborer 1";
    l1.SetData();
    cout << "\nData on manager 1";
    m1.GetData();
    cout << "\nData on scientist 1";
    s1.GetData();
    cout << "\nData on scientist 2";
    s2.GetData();
    cout << "\nData on laborer 1";
    l1.GetData();
    cout << endl;

    //11
    /*  В различных ситуациях иногда требуется работать с двумя числами, объединенными в блок. Например, каждая из координат экрана имеет горизонтальную составляющую (х) и вертикальную (у).
        Представьте такой блок чисел в качестве структуры pair, которая содержит две переменные типа int. Теперь предположим, что мы хотим иметь возможность хранить переменные типа pair в стеке.
        То есть мы хотим иметь возможность положить переменную тина pair в стек путем вызова метода push() с переменной типа pair в качестве аргумента и вынуть ее из стека путем вызова метода рор(),
        возвращающего переменную типа pair. Начнем с класса Stack2, что првиедён ниже. Создадим производный от него класс pairStack.
        В нем будут содержаться два метода: перегружаемый метод push() и перегружаемый метод рор().
        Метод pairStack::push() должен будет сделать два вызова метода Stack2::push(), чтобы сохранить оба числа из пары, а метод pairStack::pop() должен будет сделать два вызова метода Stack2::pop().    */
    Pair p, p1;
    pairStack pr;

    for (int i = 0; i < 5; i++)
    {
        p.x = i * 5;
        p.y = i * 3;
        pr.push(p);
        cout << "Положено " << p.x << " и " << p.y << endl;
    }
    for (int i = 0; i < 5; i++) { p1 = pr.pop(); cout << "Взято " << p1.x << " и " << p1.y << endl; }

    //12
    /*  Рассмотрим старую Британскую платежную систему фунты-стерлинги-пенсы. Пенсы в дальнейшем делятся на фартинги и полупенсы. Фартинг — это 1/4 пенс.
        Существовали монеты фартинг, полфартиига и пенсы. Любые сочетания монет выражались через восьмые части пенса:
        1/8	пенни	— это	полфартинга;
        1/4	пенни	— это	фартинг;
        3/8	пенни	— это	фартинг с половиной;
        1/2	пенни	— это   полпенни;
        5/8	пенни	— это	полфартинга плюс полпенни;
        3/4	пенни	— это	полпенни плюс фартинг;
        7/8	пенни	— эго	полпенни плюс фартинг с половиной.
        Давайте предположим, что мы хотим добавить в класс sterling возможность пользоваться этими дробными частями пенни.
        Формат ввода/выво¬да может быть похожим на £1.1.1-1/4 или £9.19.11-7/8, где дефисы отделяют дробные части от пенни.

        Создайте новый класс sterfrac, производный от класса sterling. В нем должна быть возможность выполнения четырех основных арифметических операций со стерлинх'ами, включая восьмые части пенни.
        Поле eighths типа int определяет количество восьмых.
        Вам нужно будет перегрузить методы класса sterling, чтобы они могли работать с восьмыми частями. Пользователь должен иметь возможность ввести и вывести дробные части пенни. */
    sterfrac stf1, strf2;
    double x;
    stf1.SetSterling(); strf2.SetSterling();
    cout << "Введите double: " && cin >> x;
    cout << "s1 + s2 = "; (stf1 + strf2).GetSterling();
    cout << "s1 - s2 = "; (stf1 - strf2).GetSterling();
    cout << "s1 / s2 = "; (stf1 / 1.5).GetSterling();
    cout << "s1/s2 = " << (stf1 / strf2) << endl;
    cout << "s1 * double = "; (stf1 * x).GetSterling();
    return 0;
}