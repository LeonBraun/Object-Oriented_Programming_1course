#include <iostream>
#include "Fraction.h"
using namespace std;

fraction summa(const fraction& a, const fraction& b) { return fraction(a.getchisl() * b.getznam() + b.getchisl() * a.getznam(), a.getznam() * b.getznam()); }
fraction raznicha(const fraction& a, const fraction& b) { return fraction(a.getchisl() * b.getznam() - b.getchisl() * a.getznam(), a.getznam() * b.getznam()); }
fraction proizv(const fraction& a, const fraction& b) { return fraction(a.getchisl() * b.getchisl(), a.getznam() * b.getznam()); }
fraction delenie(const fraction& a, const fraction& b) { return fraction(a.getchisl() * b.getznam(), a.getznam() * b.getchisl()); };

int sok(int a, int b)
{
    if (a == 0 || b == 0) { return 1; }
    if (a < 0) { a = -a; }
    if (b < 0) { b = -b; }
    while (a != b)
    {
        if (a < b) { b -= a; }
        else { a -= b; }
    }
    return a;
}
fraction reduce(const fraction& f)
{
    int chisl = f.getchisl();
    int znam = f.getznam();
    if (znam < 0) {
        chisl = -chisl;
        znam = -znam;
    }
    int gcd = sok(chisl, znam);
    return fraction(chisl / gcd, znam / gcd);
}
fraction input() { return fraction(); }
void show(const fraction& f) { cout << f.getchisl() << "/" << f.getznam(); }

int main()
{
    setlocale(LC_ALL, "ru");
    //12
    /*	Используйте преимущество ООП, заключающееся в том, что однажды созданный класс можно помещать в другие программы.
        Создайте новую программу, которая будет включать класс fraction, созданный в упражнении 11. Программа должна выводить аналог целочисленной таблицы умножения для дробей.
        Пользователь вводит знаменатель, а программа должна подобрать всевозможные целые значения числителя так, чтобы значения получаемых дробей находились между 0 и 1.

        Дроби из получившегося таким образом набора перемножаются друг с другом во всевозможных комбинациях, в результате чего получается таблица следующего вида (для знаменателя, равного 6):
        1/6 1/3 1/2 2/3 5/6
        1/6 1/36 1/18 1/12 1/9 5/36
        1/3 1/18 1/9 1/6 2/9 5/18
        1/2 1/12 1/6 1/4 1/3 5/12
        2/3 1/9 2/9 1/3 4/9 5/9
        5/6 5/36 5/18 5/12 5/9 25/36	*/
    int znamen;
    cout << "Введите знаменатель: " && cin >> znamen;
    for (register int i = 1; i <= znamen; ++i) //табл. умножения
    {
        for (register int j = 1; j <= znamen; ++j)
        {
            show(reduce(proizv(fraction(i, znamen), fraction(j, znamen))));
            cout << " ";
        }
        cout << endl;
    }
    return 0;
}