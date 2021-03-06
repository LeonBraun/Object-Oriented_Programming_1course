﻿#include <iostream>
using namespace std;

// Некоторые номера в этой и последующих лаб.раб. будут пропущены, т.к. уже решены в описании задачи, дабы избежать тупого копирования!!!

int main()
{
    setlocale(LC_ALL, "ru");
    //#4
    /*  Предположим, вы хотите создать таблицу умножения на заданное число.
        Напишите программу, которая позволяет пользователю ввести это число,
        а затем генерирует таблицу размером 20 строк на 10 столбцов. Первые
        строки результата работы программы должны выглядеть примерно следующим образом:

        Введите число: 7
        7142128354249566370
        77849198105112119126133140
        147154161168175182189196203210  */
    unsigned long int a = 0;
    while (a == 0)
        cout << "Введите число: " && cin >> a;

    int k = 0;
    for (register int i = 0; i < 20; i++)
    {
        for (register int j = 0; j < 10; j++)
        {
            cout << a * ++k << ' '; // Нужно ли в цикле for использовать класс памяти register?
        }
        cout << endl;
    }
    cout << endl;

    //#5
    /*  При помощи цикла for изобразите на экране пирамиду из символов 'X'. Верхняя часть пирамиды должна выглядеть следующим образом:
        х
        ххх
        ххххх
        ххххххх
        ххххххххх
        Вся пирамида должна быть высотой не 5 линий, как изображено здесь, а 20 линий. Одним из способов ее построения может служить использование двух вложенных циклов,
        из которых внутренний будет заниматься печатанием символов 'X' и пробелов, а другой осуществлять переход на одну строку вниз.   */
    k = 1;
    for (register int i = 0; i < 20; i++)
    {
        for (register int j = 0; j < k; j++)
        {
            cout << 'x';
        }
        k += 2;
        cout << endl;
    }
    cout << endl;

    //#6
    /*  Измените программу factor таким образом, чтобы она циклически запрашивала ввод пользователем числа и вычисляла его факториал, пока пользователь не введет 0. В этом случае программа должна завершиться.
        При необходимости вы можете использовать соответствующие операторы программы factor в цикле do или while.

        unsigned int numb;
        unsigned long fact=1;

        cout << "Enter a number: ";
        cin >> numb;

        for(int j=numb; j>0; j--)
        fact *= j;
        cout << "Factorial is " << fact << endl;    */
    while (a != 0)
    {
        cout << "Вычислить факториал: " && cin >> a;
        for (register int i = a - 1; i > 0; i--) { a *= i; };
        cout << "Факториал числа: " << a << endl;
    }
    cout << endl;

    //#7
    /*  Напишите программу, рассчитывающую сумму денег, которые вы получите при вложении начальной суммы с фиксированной процентной ставкой дохода через определенное количество лет.
        Пользователь должен вводить с клавиатуры начальный вклад, число лет и процентную ставку. Примером результата работы программы может быть следующий:

        Введите начальный вклад: 3000
        Введите число лет: 10
        Введите процентную ставку: 5.5
        Через 10 лет вы получите 5124.43 доллара.
        В конце первого года вы получите 3 000 + (3 000*0.055) = 3165 долларов.
        В конце следующего года вы получите 3 165 + (3 165*0.055) = 3339.08 долларов.

        Подобные вычисления удобно производить с помощью цикла for.   */
    double vklad;
    float year, stavka;
    cout << "Введите начальный вклад($): " && cin >> vklad && cout << "Введите число лет: " && cin >> year && cout << "Введите процентную ставку: " && cin >> stavka;
    stavka /= 100;

    for (register int i = 1; i <= year; i++)
    {
        if (i == 2)
            cout << "В конце следующего года вы получите " << vklad << " + (" << vklad << '*' << stavka << ")" << " = " << vklad + (vklad * stavka) << '$' << endl;
        vklad += stavka * vklad;
        if (i == 1)
            cout << "В конце первого года вы получите " << vklad << " + (" << vklad << '*' << stavka << ")" << " = " << vklad << '$' << endl;
    }

    cout << "Через " << year;
    if (year == 2 || year == 3 || year == 4)
        cout << " года вы получите: ";
    else if (year == 1)
        cout << " год вы получите: ";
    else
        cout << " лет вы получите: ";
    cout << vklad << endl << endl; 

    //#8, #11 
    /*	11) Создайте калькулятор, выполняющий действия над денежными суммами, выраженными в фунтах, шиллингах и пенсах (см. упражнения 10 и 12 предыдущего набора заданий).
        Калькулятор должен складывать и вычитать вводимые значения, а также производить умножение денежной суммы на вещественное число
        (операция умножения двух денежных сумм не имеет смысла, поскольку квадратных денежных единиц не существует. Деление одной денежной суммы на другую мы тоже не будем рассматривать).
        Организация взаимодействия с калькулятором описана в упражнении 4 этого набора упражнений.	
    
    8)  Напишите программу, которая циклически будет запрашивать ввод пользователем двух денежных сумм, выраженных в фунтах, шиллингах и пенсах (см. упражнения 10 и 12 предыдущего набора упражнений).
        Программа должна складывать введенные суммы и выводить на экран результат, также выраженный в фунтах, шиллингах и пенсах.
        После каждой итерации программа должна спрашивать пользователя, желает ли он продолжать работу программы. При этом рекомендуется использовать цикл do.
        Естественной формой взаимодействия программы с пользователем была бы следующая:

        Введите первую сумму: £5.10.6
        Введите вторую сумму: £3.2.6
        Всего:   £8.13.0
        Продолжить (у/n)?

        Для того чтобы сложить две суммы, вам необходимо учесть заем одного шиллинга в том случае, если число пенсов окажется больше 11, и одного фунта, если число шиллингов окажется больше 19.   */
    char tochka;
    int pounds1, shiling1, pens1;
    cout << "Введите сумму: " && cin >> pounds1 >> tochka >> shiling1 >> tochka >> pens1;

    char operachiya = ' ';
    while (operachiya != '+' && operachiya != '-' && operachiya != '*')
        cout << "Выберите действие: '+' - сложение, '-' - разность, '*' - умножение на вещественное число" << endl && cin >> operachiya;

    switch (operachiya)
    {
    case '+':
    {
        char prodolzhenie = 'y';
        while (prodolzhenie == 'y')
        {
            int pounds2, shiling2, pens2;
            cout << "Введите вторую сумму: " && cin >> pounds2 >> tochka >> shiling2 >> tochka >> pens2;
            pens1 += pens2;
            shiling1 += shiling2;
            pounds1 += pounds2;

            if (pens1 >= 12)
            {
                shiling1 += pens1 / 12;
                pens1 %= 12;
            }
            if (shiling1 >= 20)
            {
                pounds1 += shiling1 / 20;
                shiling1 %= 20;
            }
            cout << "Сумма: " << pounds1 << '.' << shiling1 << '.' << pens1 << endl;
            cout << "Продолжить сложение(y/n)?" << endl && cin >> prodolzhenie; // <-- #8
        }
        break;
    }

    case '-':
    {
        int pounds2, shiling2, pens2;
        cout << "Введите вторую сумму: " && cin >> pounds2 >> tochka >> shiling2 >> tochka >> pens2;

        int sum1 = pounds1 * 20 * 12 + shiling1 * 12 + pens1;
        int sum2 = pounds2 * 20 * 12 + shiling2 * 12 + pens2;
        int itog = abs(sum1 - sum2);
        pounds1 = itog / 240;
        shiling1 = (itog % 240) / 12;
        pens1 = itog - pounds1 * 20 * 12 - shiling1 * 12;

        cout << "Разность составляет: " << pounds1 << "." << shiling1 << "." << pens1 << endl << endl;
        break;
    }

    case '*':
    {
        float mnozhitel;
        cout << "Умножить на: " && cin >> mnozhitel;

        int sum = pounds1 * 20 * 12 + shiling1 * 12 + pens1;
        sum *= mnozhitel;
        pounds1 = sum / 240;
        shiling1 = (sum % 240) / 12;
        pens1 = sum - pounds1 * 20 * 12 - shiling1 * 12;

        cout << "Произведение равно: " << pounds1 << "." << shiling1 << "." << pens1 << endl << endl;
    }
    default:
        break;
    }

    //#9
    /*  Представьте, что вы собираетесь пригласить к себе шестерых гостей, но за вашим столом могут разместиться всего лишь 4 человека.
        Сколькими способами можно разместить четырех из шести гостей за обеленным столом? Каждый из шести гостей может разместиться на первом стуле. Каждый из оставшихся пяти гостей может занять второй стул.
        На третьем стуле может разместиться один их четырех гостей, и на четвертом — один из трех оставшихся гостей. Двоим из гостей не достанется ни одного места.
        Таким образом, число возможных рассадок гостей за столом равно 6*5*4*3 = 360.
        Напишите программу, которая будет производить аналогичные вычисления для любого числа гостей и любого числа мест за столом (при этом предполагается, что число гостей не меньше числа мест).
        Программа не должна быть сложной, и вычисление можно организовать с помощью простого цикла for. */
    int stul = 1, gost = 0;
    while (gost <= stul)
        cout << "\nКоличество стульев: " && cin >> stul && cout << "Количество гостей(больше, чем стульев): " && cin >> gost;
    int variants = 1;
    for (stul; stul > 0; stul--)
        variants *= gost--;
    cout << "Число возможных рассадок гостей за столом равно " << variants << endl;

    //#10
    /*  Модифицируйте программу, описанную в упражнении 7, так, чтобы вместо вычисления текущей суммы на вашем счете она вычисляла, сколько лет потребуется для того,
        чтобы при заданной процентной ставке и величине начального вклада сумма на вашем счете достигла запрашиваемого вами значения.
        Для хранения найденного числа лет используйте переменную целого типа (можно отбросить дробную часть значения, полученного в результате расчета).
        Самостоятельно выберите тип цикла, подходящий для решения задачи.   */
    float ozhSum;
    cout << "\nВведите начальный вклад: " && cin >> vklad && cout << "Ожидаемая сумма на счету: " && cin >> ozhSum && cout << "Введите процентную ставку: " && cin >> stavka;
    year = 0;
    while (vklad <= ozhSum)
    {
        vklad += stavka * vklad;
        year++;
    }
    cout << "Спустя " << year;
    if (year == 2 || year == 3 || year == 4)
        cout << " года вы получите: ";
    else if (year == 1)
        cout << " год вы получите: ";
    else
        cout << " лет вы получите: ";
    cout << vklad << endl << endl;

    //#12
    /*  Создайте калькулятор, выполняющий четыре арифметических действия над дробями (см. упражнение 9 предыдущего набора и упражнение 4 этого набора).
        Формулы, демонстрирующие выполнение арифметических операций над дробями, приведены ниже.

        Сложение: a/b + c/d = (a*d + b*c)/(b*d)    Вычитание: a/b - c/d = (a*d - b*c)/(b*d)    Умножение: a/b*c/d = (a*c)/(b*d)    Деление: a/b/c/d = (a*d)/(b*c)

        Пользователь должен сначала ввести первый операнд, затем знак операции и второй операнд.    
        После вычисления результата программа должна отобразить его на экране и запросить пользователя о его желании произвести еще одну операцию.  */
    char prodolzhenie = 'y';
    do
    {
        int a, b, c, d;
        char dummychar, operachiya;

        cout << "Введите первый операнд, операцию и второй операнд: ";
        cin >> a >> dummychar >> b >> operachiya >> c >> dummychar >> d;

        switch (operachiya)
        {
        case '+':
        {
            cout << "Сумма: " << (a * d + b * c) << '/' << (b * d) << endl;
            cout << "Выполнить еще одну операцию (y/n)?" << endl && cin >> prodolzhenie;
            break;
        }

        case '-':
        {
            cout << "Разность: " << (a * d - b * c) << '/' << (b * d) << endl;
            cout << "Выполнить еще одну операцию(y/n)?" << endl && cin >> prodolzhenie;
            break;
        }

        case '/':
        {
            cout << "Частное: " << (a * c) << '/' << (b * d) << endl;
            cout << "Выполнить еще одну операцию(y/n)?" << endl && cin >> prodolzhenie;
            break;
        }

        case '*':
        {
            cout << "Произведение: " << (a * c) << '/' << (b * d) << endl;
            cout << "Выполнить еще одну операцию(y/n)?" << endl && cin >> prodolzhenie;
            break;
        }

        default:
            cout << "Некорректный ввод" << endl;
            break;
        }
    } while (prodolzhenie == 'y');
}  