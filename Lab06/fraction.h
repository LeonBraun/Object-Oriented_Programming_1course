#include <iostream>
using namespace std;

class fraction
{
    int chislitel, znamenatel;
    char deistvie;
public:
    fraction()
    {
        chislitel = 0;
        znamenatel = 1;
        deistvie = ' ';
    }
    void setDrob()
    {
        char symbol;
        cin >> chislitel >> symbol >> znamenatel;
    }
    void SetDrob_and_Deistviye(fraction& d1, fraction& d2)
    {
        char symbol;
        cout << "Введите первый операнд(дробь), операцию и второй операнд(дробь): " && cin >> d1.chislitel >> symbol >> d1.znamenatel >> deistvie >> d2.chislitel >> symbol >> d2.znamenatel;
    }
    void sokrashDrobi(int& chis, int& znam) //Сокращение дроби
    {
        long polozhChis, polozhZnam, vremValue, gcd;
        polozhChis = labs(chis); // Берем модули числителя и знаменателя 
        polozhZnam = labs(znam); // Нужен cmath
        if (polozhZnam == 0)
        { // Проверка знаменателя
            cout << "Недопустимый знаменатель";
            exit(1);
        }
        else if (polozhChis == 0)
        {
            chis = 0;
            znam = 1;
            return;
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
        chis = chis / gcd;
        znam = znam / gcd;
    }
    void sokrashDrobi(fraction& drob)
    {
        {
            long polozhChis, polozhZnam, vremValue, gcd;
            polozhChis = labs(drob.chislitel); // Берем модули числителя и знаменателя 
            polozhZnam = labs(drob.znamenatel); // Нужен cmath
            if (polozhZnam == 0)
            { // Проверка знаменателя
                cout << "Недопустимый знаменатель";
                exit(1);
            }
            else if (polozhChis == 0)
            {
                drob.chislitel = 0;
                drob.znamenatel = 1;
                return;
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
            drob.chislitel = drob.chislitel / gcd;
            drob.znamenatel = drob.znamenatel / gcd;
        }
    }
    void Calculator(fraction drob1, fraction drob2)
    {
        switch (deistvie)
        {
        case'+':
            chislitel = drob1.chislitel * drob2.znamenatel + drob1.znamenatel * drob2.chislitel;
            znamenatel = drob1.znamenatel * drob2.znamenatel;
            break;
        case'-':
            chislitel = drob1.chislitel * drob2.znamenatel - drob1.znamenatel * drob2.chislitel;
            znamenatel = drob1.znamenatel * drob2.znamenatel;
            break;
        case'/':
            chislitel = drob1.chislitel * drob2.chislitel;
            znamenatel = drob1.znamenatel * drob2.znamenatel;
            break;
        case'*':
            chislitel = drob1.chislitel * drob2.chislitel;
            znamenatel = drob1.znamenatel * drob2.znamenatel;
            break;

        default:
            cout << "Ошибка ввода!!!" << endl;
            break;
        }
        sokrashDrobi(chislitel, znamenatel);
        cout << "Ответ: " << chislitel << '/' << znamenatel << endl;
    }
    void srredSumm(fraction& drob1, fraction drob2)
    {
        drob1.chislitel = drob1.chislitel * drob2.znamenatel + drob1.znamenatel * drob2.chislitel;
        drob1.znamenatel = drob1.znamenatel * drob2.znamenatel;
    }

    void GetDrob() { cout << chislitel << '/' << znamenatel << endl; }
    void umnozhNaCheloe(fraction& drob, int kolvoDrobs) { drob.znamenatel = drob.znamenatel * kolvoDrobs; }
};