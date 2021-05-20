#pragma
#include <iostream>
#include <string>
#include <locale.h>
#include "Natural.h"
#include "Fraction.h"
#include "Integer.h"
#include <vector>
#include <conio.h>
using namespace std;

/*
Важное уточнение - в программе реализованы не только некоторые функуии, но и их проверки.
Так же реализованы дополнительные ф-ции что используются в качестве примера рабыот тех или иных механик классов.
Хорошего программирования (^_^)
*/

class Polynom
{
private:
    int m; // (макс степень)(количество-1)
    fraction* C = new fraction[m + 1]; // массив коэф-тов (будет массивом rac чисел)
public:
    //just конструктор с передачей
    Polynom(int new_m, fraction* new_C)
    {
        m = new_m;
        C = new_C;
    }
    // конструктор с вводом значений внутри ф-ции
    Polynom()
    {
        cout << "введите степень ";
        int new_m; cin >> new_m; // передаём степень
        m = new_m;
        new_m++;// new_m становится количеством 
        C = new fraction[new_m]; //фактически пересоздаём(расширяем) массив
        for (int i = 0; i < new_m; i++)
        {
            // cout потом удалить 
            cout << "введите количество числителя элемента " << i << " : "; int ch_n; cin >> ch_n;
            vector<int> ch_digit(ch_n);
            cout << "значение числителя элемента " << i << " : ";
            for (int j = 0; j < ch_n; j++)
            {
                std::cin >> ch_digit[j];
            }
            cout << "введите знак числителя элемента " << i << " : "; bool sign; cin >> sign;
            cout << "введите количество знаменателя элемента " << i << " : "; int zn_n; cin >> zn_n;
            vector<int> zn_digit(zn_n);
            cout << "значение знаменателя элемента " << i << " : ";
            for (int j = 0; j < zn_n; j++)
            {
                std::cin >> zn_digit[j];
            }
            C[i] = fraction(ch_n, ch_digit, sign, zn_n, zn_digit);
        }
    }
    //ВСПОМОГАТЕЛЬНЫЕ Ф-ЦИИ :

    // выводит элемент без индекса
    fraction* get_C_ni_index()
    {
        return C;
    }
    // выводит элемент (дробь) - по индексу от 0
    fraction get_C(int i) // выводит элемент (дробь) - по индексу от 0
    {
        return C[i];
    }

    // ОСНОВНЫЕ Ф-ЦИИ:


    //P - 1 сложение многочленов
    Polynom* ADD_PP_P(Polynom* k)
    {
        Polynom* X = new Polynom(m, C);
        int i = 0;
        int j = 0;
        int for_X = 0;
        int cobolt = this->m;
        if (this->m > k->m)
        {
            X = this;
            i = m - k->m;
            cobolt = this->m;
            for_X = this->m - k->m;
        }

        if (this->m < k->m)
        {
            X = k;
            i = 0;
            j = k->m - this->m;
            cobolt = this->m;
            for_X = k->m - this->m;
        }
        for (i; i < cobolt + 1; i++)
        {
            vector <int> give_me_help = k->C[j].get_zn(); std::reverse(give_me_help.begin(), give_me_help.end()); // универсальные конструкции замены 
            k->C[j].change_zn(give_me_help);
            vector <int> and_you_too = k->C[j].get_ch(); std::reverse(and_you_too.begin(), and_you_too.end());
            k->C[j].change_ch(and_you_too);
            vector <int> norch = this->C[i].get_ch(); std::reverse(norch.begin(), norch.end());
            X->C[for_X].change_ch(norch);
            vector <int> norzn = this->C[i].get_zn(); std::reverse(norzn.begin(), norzn.end());
            X->C[for_X].change_zn(norzn);

            X->C[for_X] = X->C[for_X].ADD_QQ_Q(k->C[j]);

            vector <int> new_chisl = X->C[for_X].get_ch(); std::reverse(new_chisl.begin(), new_chisl.end());
            X->C[for_X].change_ch(new_chisl);
            vector <int> new_znam = X->C[for_X].get_zn(); std::reverse(new_znam.begin(), new_znam.end());
            X->C[for_X].change_zn(new_znam);
            j++;
            for_X++;
        }

        return X;
    }
    //p-2 разность многочленов
    Polynom* SUB_PP_P(Polynom* k)
    {
        Polynom* X = new Polynom(m, C);
        int i = 0;
        int j = 0;
        int for_X = 0;
        int cobolt = this->m;
        if (this->m > k->m)
        {
            X = this;
            i = m - k->m;
            cobolt = this->m;
            for_X = this->m - k->m;
        }

        if (this->m < k->m)
        {
            X = k;
            i = 0;
            j = k->m - this->m;
            cobolt = this->m;
            for_X = k->m - this->m;
        }
        for (i; i < cobolt + 1; i++)
        {
            vector <int> give_me_help = k->C[j].get_zn(); std::reverse(give_me_help.begin(), give_me_help.end()); // универсальные конструкции замены 
            k->C[j].change_zn(give_me_help);
            vector <int> and_you_too = k->C[j].get_ch(); std::reverse(and_you_too.begin(), and_you_too.end());
            k->C[j].change_ch(and_you_too);
            vector <int> norch = this->C[i].get_ch(); std::reverse(norch.begin(), norch.end());
            X->C[for_X].change_ch(norch);
            vector <int> norzn = this->C[i].get_zn(); std::reverse(norzn.begin(), norzn.end());
            X->C[for_X].change_zn(norzn);

            X->C[for_X] = X->C[for_X].SUB_QQ_Q(k->C[j]);

            vector <int> new_chisl = X->C[for_X].get_ch(); std::reverse(new_chisl.begin(), new_chisl.end());
            X->C[for_X].change_ch(new_chisl);
            vector <int> new_znam = X->C[for_X].get_zn(); std::reverse(new_znam.begin(), new_znam.end());
            X->C[for_X].change_zn(new_znam);
            j++;
            for_X++;
        }
        return X;
    }

    // 3 умножение на коэффициент
    Polynom* MUL_PQ_P(fraction k)
    {
        vector <int> give_me_help = k.get_zn(); std::reverse(give_me_help.begin(), give_me_help.end());
        k.change_zn(give_me_help);
        vector <int> and_you_too = k.get_ch(); std::reverse(and_you_too.begin(), and_you_too.end());
        k.change_ch(and_you_too);
        Polynom* X = new Polynom(m, C);
        for (int i = 0; i < m + 1; i++)
        {
            vector <int> norch = this->C[i].get_ch(); std::reverse(norch.begin(), norch.end());
            X->C[i].change_ch(norch);
            vector <int> norzn = this->C[i].get_zn(); std::reverse(norzn.begin(), norzn.end());
            X->C[i].change_zn(norzn);
            X->C[i] = X->C[i].MUL_QQ_Q(k);
            vector <int> new_chisl = X->C[i].get_ch(); std::reverse(new_chisl.begin(), new_chisl.end());
            vector <int> new_znam = X->C[i].get_zn(); std::reverse(new_znam.begin(), new_znam.end());
            X->C[i].change_ch(new_chisl);
            X->C[i].change_zn(new_znam);
        }
        return X;
    }
    // 4 - умножение на x^k (увеличивает степень и добовляет "0" элементы) 
    Polynom* MUL_Pxk_P()
    {
        int kk;
        cin >> kk; // на сколько добавляем степень
        fraction* C1 = new fraction[m + 1 + kk]; //создаём увеличенный массив
        for (int i = 0; i < (m + 1 + kk); ++i)
        {
            if (i < m + 1)	C1[i] = C[i];  // проходимся по новому массиву - где элементы уже были - остовляем, если элемент новый, то он будет 0;
            else
            {
                vector <int> ch{ 0 };
                vector <int> zn{ 1 };
                int new_sign = 0;
                C1[i].change_ch(ch); C1[i].change_sign(0); C1[i].change_ch_len(1); // создаём 0 члены
                C1[i].change_zn(zn); C1[i].change_zn_len(1);
            }
        }
        Polynom* A = new Polynom(m + kk, C1);
        return A;
    }

    // 5 Старший коэффициент
    fraction LED_P_Q()
    {
        return get_C(0);
    }
    // 6 Степень 
    int DEG_P_N()
    {
        return (m);
    }
    // 12 Производная 
    Polynom* DER_P_P()
    {
        Integer new_integer(m);
        fraction* new_C = C; // массив коэфициентов
        for (int i = 0; i < m; i++)
        {
            Integer I = C[i].FracToInt(C[i].get_ch(), C[i].get_ch_len(), C[i].get_sign());
            I = I.MUL_ZZ_Z(new_integer); // умножает на степень (сейчас просто на число)
            new_C[i].change_ch(new_C[i].IntToFrac(I)); // заполняется элементами;
        }
        Polynom* new_Polynom = new Polynom(m-1, new_C);
        return new_Polynom;
    }

};
//ф-ция красивого вывода
void new_butiful_vivod(Polynom* X)
{
    for (int i = 0; i < X->DEG_P_N() + 1; i++)
    {
        if (X->get_C(i).get_sign() == 1) { cout << "-"; }
        for (int j = 0; j < X->get_C(i).get_ch_len(); j++)
        {
            cout << X->get_C(i).get_ch()[j];
        }
        cout << "/";
        for (int j = 0; j < X->get_C(i).get_zn_len(); j++)
        {
            cout << X->get_C(i).get_zn()[j];
        }
        cout << " ";
    }
};

/*
* 
* P1 - Сизов Артём / Елизавета Гладкова
* P2 - Сизов Артём / Елизавета Гладкова
* P3 - Сизов Артём 
* P4 - Сизов Артём / Юлия Данилова / Елизавета Гладкова
* P5 - Юлия Данилова /Елизавета Гладкова
* P6 - Юлия Данилова / Елизавета Гладкова
* 
* P12 - Сизов Артём / Елизавета Гладкова / Юлия Данилова
* 
*/
