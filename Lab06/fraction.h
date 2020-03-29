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
        cout << "������� ������ �������(�����), �������� � ������ �������(�����): " && cin >> d1.chislitel >> symbol >> d1.znamenatel >> deistvie >> d2.chislitel >> symbol >> d2.znamenatel;
    }
    void sokrashDrobi(int& chis, int& znam) //���������� �����
    {
        long polozhChis, polozhZnam, vremValue, gcd;
        polozhChis = labs(chis); // ����� ������ ��������� � ����������� 
        polozhZnam = labs(znam); // ����� cmath
        if (polozhZnam == 0)
        { // �������� �����������
            cout << "������������ �����������";
            exit(1);
        }
        else if (polozhChis == 0)
        {
            chis = 0;
            znam = 1;
            return;
        }
        // ���������� ����������� ������ ��������
        while (polozhChis != 0)
        {
            if (polozhChis < polozhZnam)
            { // ���� ��������� ������ �����������, ������ �� �������.
                vremValue = polozhChis;
                polozhChis = polozhZnam;
                polozhZnam = vremValue;
            }
            polozhChis = polozhChis - polozhZnam;
        }
        gcd = polozhZnam;// ����� ��������� � ����������� �� ���.
        chis = chis / gcd;
        znam = znam / gcd;
    }
    void sokrashDrobi(fraction& drob)
    {
        {
            long polozhChis, polozhZnam, vremValue, gcd;
            polozhChis = labs(drob.chislitel); // ����� ������ ��������� � ����������� 
            polozhZnam = labs(drob.znamenatel); // ����� cmath
            if (polozhZnam == 0)
            { // �������� �����������
                cout << "������������ �����������";
                exit(1);
            }
            else if (polozhChis == 0)
            {
                drob.chislitel = 0;
                drob.znamenatel = 1;
                return;
            }
            // ���������� ����������� ������ ��������
            while (polozhChis != 0)
            {
                if (polozhChis < polozhZnam)
                { // ���� ��������� ������ �����������, ������ �� �������.
                    vremValue = polozhChis;
                    polozhChis = polozhZnam;
                    polozhZnam = vremValue;
                }
                polozhChis = polozhChis - polozhZnam;
            }
            gcd = polozhZnam;// ����� ��������� � ����������� �� ���.
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
            cout << "������ �����!!!" << endl;
            break;
        }
        sokrashDrobi(chislitel, znamenatel);
        cout << "�����: " << chislitel << '/' << znamenatel << endl;
    }
    void srredSumm(fraction& drob1, fraction drob2)
    {
        drob1.chislitel = drob1.chislitel * drob2.znamenatel + drob1.znamenatel * drob2.chislitel;
        drob1.znamenatel = drob1.znamenatel * drob2.znamenatel;
    }

    void GetDrob() { cout << chislitel << '/' << znamenatel << endl; }
    void umnozhNaCheloe(fraction& drob, int kolvoDrobs) { drob.znamenatel = drob.znamenatel * kolvoDrobs; }
};