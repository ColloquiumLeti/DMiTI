
#include <iostream>
#include <string>
#include <locale.h>
#include <vector>
#include <conio.h>
#include "Integer.h"
#include "Natural.h"
#include "Polynom.h"
#include "Fraction.h"
#include "A_lot_of_menu.h"
using namespace std;


int main(){
    setlocale(LC_ALL, "Russian");
    system("cls");
    int symbol=1;
    while (symbol != 5) {
        system("cls");
        symbol = print_menu();
        switch (symbol) {
            case 1:{
                int symbol_N=1;
                while (symbol_N != 15) {
                    system("cls");
                    cout << "Пожалуйста введите натуральное число" << endl;
                    string str_For_Natural_1;
                    getline(cin, str_For_Natural_1);
                    Natural N1(str_For_Natural_1);
                    symbol_N = print_Natural_menu();
                    switch (symbol_N) {
                        case 1:{
                            cout << "Пожалуйста введите еще одно натуральное число" << endl;
                            string str_For_Natural_2;
                            getline(cin, str_For_Natural_2);
                            Natural N2(str_For_Natural_2);
                            cout << "Результат сравнения: 2 - если первое больше второго, 0 - если равны, 1- иначе \n" << N1.COM_NN_D(N2) << endl;
                            _getch();
                            break;
                        }
                        case 2:{
                            cout << "Проверка на ноль: если число не равно нулю, то 'да'(1) иначе 'нет'(0)" << N1.NZER_N_B() << endl;
                            _getch();
                            break;
                        }
                        case 3:{
                            N1 = N1.ADD_1N_N();
                            for(int schetchik = 0; schetchik < N1.Length(); schetchik++){
                            cout << N1.Digits_of_number()[schetchik];
                            }
                            _getch();
                            break;
                        }
                        case 4:{
                            cout << "Пожалуйста введите еще одно натуральное число" << endl;
                            string str_For_Natural_2;
                            getline(cin, str_For_Natural_2);
                            Natural N2(str_For_Natural_2);
                            Natural N3 = N2.ADD_NN_N(N1);
                            cout << "Сумма равна" << " ";
                            for(int schetchik = 0; schetchik < N3.Length(); schetchik++){
                            cout << N3.Digits_of_number()[schetchik];
                            }
                            _getch();
                            break;
                        }
                        case 5:{
                            cout << "Пожалуйста введите еще одно натуральное число меньше первого" << endl;
                            string str_For_Natural_2;
                            getline(cin, str_For_Natural_2);
                            Natural N2(str_For_Natural_2);
                            Natural N3 = N1.SUB_NN_N(N2);
                            cout << "Разность равна" << " ";
                            for(int schetchik = 0; schetchik < N3.Length(); schetchik++){
                            cout << N3.Digits_of_number()[schetchik];
                            }
                            _getch();
                            break;
                        }
                        case 6:{
                            cout << "Пожалуйста введите число на которое умножают натуральное" << endl;
                            int number;
                            cin >> number;
                            N1 = N1.MUL_ND_N(number);
                            cout << "Умножение на число равно" << " ";
                            for(int schetchik = 0; schetchik < N1.Length(); schetchik++){
                            cout << N1.Digits_of_number()[schetchik];
                            }
                            _getch();
                            break;
                        }
                        case 7:{
                            cout << "Пожалуйста введите степень k" << endl;
                            int number;
                            cin >> number;
                            N1 = N1.MUL_Nk_N(number);
                            cout << "Умножение на 10^k равно" << " ";
                            for(int schetchik = 0; schetchik < N1.Length(); schetchik++){
                            cout << N1.Digits_of_number()[schetchik];
                            }
                            _getch();
                            break;
                        }
                        case 8:{
                            cout << "Пожалуйста введите еще одно натуральное число" << endl;
                            string str_For_Natural_2;
                            getline(cin, str_For_Natural_2);
                            Natural N2(str_For_Natural_2);
                            Natural N3 = N2.MUL_NN_N(N1);
                            cout << "Произведение равно" << " ";
                            for(int schetchik = 0; schetchik < N3.Length(); schetchik++){
                            cout << N3.Digits_of_number()[schetchik];
                            }
                            _getch();
                            break;
                        }
                        case 9:{
                            cout << "Пожалуйста введите еще одно натуральное число и число на которое его домножают" << endl;
                            string str_For_Natural_2;
                            getline(cin, str_For_Natural_2);
                            Natural N2(str_For_Natural_2);
                            int number;
                            cin >> number;
                            Natural N3 = N2.SUB_NDN_N(N1, number);
                            cout << "Разность равна" << " ";
                            for(int schetchik = 0; schetchik < N3.Length(); schetchik++){
                            cout << N3.Digits_of_number()[schetchik];
                            }
                            _getch();
                            break;
                        }
                        case 10:{
                            cout << "Пожалуйста введите еще одно натуральное число больше первого" << endl;
                            string str_For_Natural_2;
                            getline(cin, str_For_Natural_2);
                            Natural N2(str_For_Natural_2);
                            Natural N3 = N2.DIV_NN_Dk(N1);
                            cout << "Результат равен" << " ";
                            for(int schetchik = 0; schetchik < N3.Length(); schetchik++){
                            cout << N3.Digits_of_number()[schetchik];
                            }
                            _getch();
                            break;
                        }
                        case 11:{
                            cout << "Пожалуйста введите еще одно натуральное число больше или равное первому" << endl;
                            string str_For_Natural_2;
                            getline(cin, str_For_Natural_2);
                            Natural N2(str_For_Natural_2);
                            Natural N3 = N2.DIV_NN_N(N1);
                            cout << "Результат равен" << " ";
                            for(int schetchik = 0; schetchik < N3.Length(); schetchik++){
                            cout << N3.Digits_of_number()[schetchik];
                            }
                            _getch();
                            break;
                        }
                        case 12:{
                            cout << "Пожалуйста введите еще одно натуральное число больше или равное первому" << endl;
                            string str_For_Natural_2;
                            getline(cin, str_For_Natural_2);
                            Natural N2(str_For_Natural_2);
                            Natural N3 = N2.MOD_NN_N(N1);
                            cout << "Остаток равен" << " ";
                            for(int schetchik = 0; schetchik < N3.Length(); schetchik++){
                            cout << N3.Digits_of_number()[schetchik];
                            }
                            _getch();
                            break;
                        }
                        case 13:{
                            cout << "Пожалуйста введите еще одно натуральное число" << endl;
                            string str_For_Natural_2;
                            getline(cin, str_For_Natural_2);
                            Natural N2(str_For_Natural_2);
                            Natural N3 = N2.GCF_NN_N(N1);
                            cout << "НОД равен" << " ";
                            for(int schetchik = 0; schetchik < N3.Length(); schetchik++){
                            cout << N3.Digits_of_number()[schetchik];
                            }
                            _getch();
                            break;
                        }
                        case 14:{
                            cout << "Пожалуйста введите еще одно натуральное число" << endl;
                            string str_For_Natural_2;
                            getline(cin, str_For_Natural_2);
                            Natural N2(str_For_Natural_2);
                            Natural N3 = N2.LCM_NN_N(N1);
                            cout << "НОК равен" << " ";
                            for(int schetchik = 0; schetchik < N3.Length(); schetchik++){
                            cout << N3.Digits_of_number()[schetchik];
                            }
                            _getch();
                            break;
                        }
                    }
                }
                break;
            }
            case 2:{
                int symbol_Z=1;
                while (symbol_Z != 11) {
                    system("cls");
                    cout << "Пожалуйста введите целое число (сначала знак потом число)" << endl;
                    int sing1;
                    cin >> sing1;
                    string str_For_Integer_1;
                    getline(cin, str_For_Integer_1);
                    Integer I1(sing1, str_For_Integer_1);
                    symbol_Z = print_Integer_menu();
                    switch (symbol_Z) {
                        case 1:{
                            Natural N1 = I1.ABS_Z_N();
                            cout << "Абсолютное значение равно ";
                            for(int schetchik = 0; schetchik < N1.Length(); schetchik++){
                            cout << N1.Digits_of_number()[schetchik];
                            }
                            _getch();
                            break;
                        }
                        case 2:{
                            cout << "(2 - положительное, 0 — равное нулю, 1 - отрицательное)   " << I1.POZ_Z_D() << endl;
                            _getch();
                            break;
                        }
                        case 3:{
                            Integer I3 = I1.MUL_ZM_Z();
                            cout << I3.Sign() << " ";
                            for(int schetchik = 0; schetchik < I3.Length(); schetchik++){
                            cout << I3.Digits_of_number()[schetchik];
                            }
                            _getch();
                            break;
                        }
                        case 4:{
                            cout << "Пожалуйста введите одно натуральное число" << endl;
                            string str_For_Natural_2;
                            getline(cin, str_For_Natural_2);
                            Natural N2(str_For_Natural_2);
                            Integer I3 = I1.TRANS_N_Z(N2);
                            cout << I3.Sign() << " ";
                            for(int schetchik = 0; schetchik < I3.Length(); schetchik++){
                            cout << I3.Digits_of_number()[schetchik];
                            }
                            _getch();
                            break;
                        }
                        case 5:{
                            Natural N3 = I1.TRANS_Z_N();
                            for(int schetchik = 0; schetchik < N3.Length(); schetchik++){
                            cout << N3.Digits_of_number()[schetchik];
                            }
                            _getch();
                            break;
                        }
                        case 6:{
                            cout << "Пожалуйста введите одно целое число" << endl;
                            int sing2;
                            cin >> sing2;
                            string str_For_Integer_2;
                            getline(cin, str_For_Integer_2);
                            Integer I2(sing2, str_For_Integer_2);
                            Integer I3 = I1.ADD_ZZ_Z(I2);
                            cout << "Сумма равна" <<" "; 
                            cout << I3.Sign() << " ";
                            for(int schetchik = 0; schetchik < I3.Length(); schetchik++){
                            cout << I3.Digits_of_number()[schetchik];
                            }
                            _getch();
                            break;
                        }
                        case 7:{
                            cout << "Пожалуйста введите одно целое число" << endl;
                            int sing2;
                            cin >> sing2;
                            string str_For_Integer_2;
                            getline(cin, str_For_Integer_2);
                            Integer I2(sing2, str_For_Integer_2);
                            Integer I3 = I1.SUB_ZZ_Z(I2);
                            cout << "Разность равна" <<" "; 
                            cout << I3.Sign() << " ";
                            for(int schetchik = 0; schetchik < I3.Length(); schetchik++){
                            cout << I3.Digits_of_number()[schetchik];
                            }
                            _getch();
                            break;
                        }
                        case 8:{
                            cout << "Пожалуйста введите одно целое число" << endl;
                            int sing2;
                            cin >> sing2;
                            string str_For_Integer_2;
                            getline(cin, str_For_Integer_2);
                            Integer I2(sing2, str_For_Integer_2);
                            Integer I3 = I1.MUL_ZZ_Z(I2);
                            cout << "Произведение равно" <<" "; 
                            cout << I3.Sign() << " ";
                            for(int schetchik = 0; schetchik < I3.Length(); schetchik++){
                            cout << I3.Digits_of_number()[schetchik];
                            }
                            _getch();
                            break;
                        }
                        case 9:{
                            cout << "Пожалуйста введите одно целое число" << endl;
                            int sing2;
                            cin >> sing2;
                            string str_For_Integer_2;
                            getline(cin, str_For_Integer_2);
                            Integer I2(sing2, str_For_Integer_2);
                            Integer I3 = I1.DIV_ZZ_Z(I2);
                            cout << "Частное равно" <<" "; 
                            cout << I3.Sign() << " ";
                            for(int schetchik = 0; schetchik < I3.Length(); schetchik++){
                            cout << I3.Digits_of_number()[schetchik];
                            }
                            _getch();
                            break;
                        }
                        case 10:{
                            cout << "Пожалуйста введите одно целое число" << endl;
                            int sing2;
                            cin >> sing2;
                            string str_For_Integer_2;
                            getline(cin, str_For_Integer_2);
                            Integer I2(sing2, str_For_Integer_2);
                            Integer I3 = I1.MOD_ZZ_Z(I2);
                            cout << "Остаток равен" <<" "; 
                            cout << I3.Sign() << " ";
                            for(int schetchik = 0; schetchik < I3.Length(); schetchik++){
                            cout << I3.Digits_of_number()[schetchik];
                            }
                            _getch();
                            break;
                        }
                    }
                }
                break;
            }
            case 3:{
                int symbol_Q=1;
                while (symbol_Q != 9) {
                    system("cls");
                    cout << "Введите Рациональное число" << endl;
                    cout << "сейчас введите числ и знам";
                    cout << "введите количество числителя элемента " << " : "; int ch_n; cin >> ch_n;
                    vector<int> ch_digit(ch_n);
                    cout << "значение числителя элемента " << " : ";
                    for (int j = 0; j < ch_n; j++)
                    {
                        std::cin >> ch_digit[j];
                    }
                    cout << "введите знак числителя элемента " << " : "; bool sign; cin >> sign;
                    cout << "введите количество знаменателя элемента " << " : "; int zn_n; cin >> zn_n;
                    vector<int> zn_digit(zn_n);
                    cout << "значение знаменателя элемента "  << " : ";
                    for (int j = 0; j < zn_n; j++)
                    {
                        std::cin >> zn_digit[j];
                    }
                    fraction F1(ch_n, ch_digit, sign, zn_n, zn_digit);
                    symbol_Q = print_Fraction_menu();
                    switch (symbol_Q) {
                        case 1:{
                            fraction F2 = F1.RED_Q_Q();
                            vector<int> chi = F2.get_ch();
                            reverse(chi.begin(), chi.end());
                            vector<int> zna = F2.get_zn();
                            reverse(zna.begin(), zna.end());
                            cout << "\n ";
                            for (int i = 0; i < F2.get_ch_len(); i++)
                            cout << chi[i];
                            cout << "\n";
                            F2.get_sign() > 0 ? cout << "-" : cout << " ";
                            if (F2.get_ch_len() > F2.get_zn_len())
                            for (int i = 0; i < F2.get_ch_len(); i++)
                            cout << "_";
                            else for (int i = 0; i < F2.get_zn_len(); i++)
                            cout << "_";
                            cout << "\n ";
                            for (int i = 0; i < F2.get_zn_len(); i++)
                            cout << zna[i];
                            cout << "\n ";
                            _getch();
                            break;
                        }
                        case 2:{
                            cout << "Если 1-число целое, если 0-то нет" << F1.INT_Q_B() << endl;
                            _getch();
                            break;
                        }
                        case 3:{
                            cout << "Пожалуйста введите одно целое число" << endl;
                            int sing2;
                            cin >> sing2;
                            string str_For_Integer_2;
                            getline(cin, str_For_Integer_2);
                            Integer I2(sing2, str_For_Integer_2);
                            fraction F2 = F1.TRANS_Z_Q(I2);
                            vector<int> chi = F2.get_ch();
                            reverse(chi.begin(), chi.end());
                            vector<int> zna = F2.get_zn();
                            reverse(zna.begin(), zna.end());
                            cout << "\n ";
                            for (int i = 0; i < F2.get_ch_len(); i++)
                            cout << chi[i];
                            cout << "\n";
                            F2.get_sign() > 0 ? cout << "-" : cout << " ";
                            if (F2.get_ch_len() > F2.get_zn_len())
                            for (int i = 0; i < F2.get_ch_len(); i++)
                            cout << "_";
                            else for (int i = 0; i < F2.get_zn_len(); i++)
                            cout << "_";
                            cout << "\n ";
                            for (int i = 0; i < F2.get_zn_len(); i++)
                            cout << zna[i];
                            cout << "\n ";
                            _getch();
                            break;
                        }
                        case 4:{
                            Integer I1 = F1.TRANS_Q_Z();
                            cout << I1.Sign() << " ";
                            for(int schetchik = 0; schetchik < I1.Length(); schetchik++){
                            cout << I1.Digits_of_number()[schetchik];
                            }
                            _getch();
                            break;
                        }
                        case 5:{
                            cout << "Введите еще одно Рациональное число" << endl;
                            cout << "сейчас введите числ и знам";
                            cout << "введите количество числителя элемента " << " : "; int ch_n; cin >> ch_n;
                            vector<int> ch_digit(ch_n);
                            cout << "значение числителя элемента " << " : ";
                            for (int j = 0; j < ch_n; j++)
                            {
                                std::cin >> ch_digit[j];
                            }
                            cout << "введите знак числителя элемента " << " : "; bool sign; cin >> sign;
                            cout << "введите количество знаменателя элемента " << " : "; int zn_n; cin >> zn_n;
                            vector<int> zn_digit(zn_n);
                            cout << "значение знаменателя элемента "  << " : ";
                            for (int j = 0; j < zn_n; j++)
                            {
                                std::cin >> zn_digit[j];
                            }
                            fraction F2(ch_n, ch_digit, sign, zn_n, zn_digit);
                            fraction F3 = F1.ADD_QQ_Q(F2);
                            Print_fraction(F3);
                            _getch();
                            break;
                        }
                        case 6:{
                            cout << "Введите еще одно Рациональное число" << endl;
                            cout << "сейчас введите числ и знам";
                            cout << "введите количество числителя элемента " << " : "; int ch_n; cin >> ch_n;
                            vector<int> ch_digit(ch_n);
                            cout << "значение числителя элемента " << " : ";
                            for (int j = 0; j < ch_n; j++)
                            {
                                std::cin >> ch_digit[j];
                            }
                            cout << "введите знак числителя элемента " << " : "; bool sign; cin >> sign;
                            cout << "введите количество знаменателя элемента " << " : "; int zn_n; cin >> zn_n;
                            vector<int> zn_digit(zn_n);
                            cout << "значение знаменателя элемента "  << " : ";
                            for (int j = 0; j < zn_n; j++)
                            {
                                std::cin >> zn_digit[j];
                            }
                            fraction F2(ch_n, ch_digit, sign, zn_n, zn_digit);
                            fraction F3 = F1.SUB_QQ_Q(F2);
                            Print_fraction(F3);
                            _getch();
                            break;
                        }
                        case 7:{
                            cout << "Введите еще одно Рациональное число" << endl;
                            cout << "сейчас введите числ и знам";
                            cout << "введите количество числителя элемента " << " : "; int ch_n; cin >> ch_n;
                            vector<int> ch_digit(ch_n);
                            cout << "значение числителя элемента " << " : ";
                            for (int j = 0; j < ch_n; j++)
                            {
                                std::cin >> ch_digit[j];
                            }
                            cout << "введите знак числителя элемента " << " : "; bool sign; cin >> sign;
                            cout << "введите количество знаменателя элемента " << " : "; int zn_n; cin >> zn_n;
                            vector<int> zn_digit(zn_n);
                            cout << "значение знаменателя элемента "  << " : ";
                            for (int j = 0; j < zn_n; j++)
                            {
                                std::cin >> zn_digit[j];
                            }
                            fraction F2(ch_n, ch_digit, sign, zn_n, zn_digit);
                            fraction F3 = F1.MUL_QQ_Q(F2);
                            Print_fraction(F3);
                            _getch();
                            break;
                        }
                        case 8:{
                            cout << "Введите еще одно Рациональное число" << endl;
                            cout << "сейчас введите числ и знам";
                            cout << "введите количество числителя элемента " << " : "; int ch_n; cin >> ch_n;
                            vector<int> ch_digit(ch_n);
                            cout << "значение числителя элемента " << " : ";
                            for (int j = 0; j < ch_n; j++)
                            {
                                std::cin >> ch_digit[j];
                            }
                            cout << "введите знак числителя элемента " << " : "; bool sign; cin >> sign;
                            cout << "введите количество знаменателя элемента " << " : "; int zn_n; cin >> zn_n;
                            vector<int> zn_digit(zn_n);
                            cout << "значение знаменателя элемента "  << " : ";
                            for (int j = 0; j < zn_n; j++)
                            {
                                std::cin >> zn_digit[j];
                            }
                            fraction F2(ch_n, ch_digit, sign, zn_n, zn_digit);
                            fraction F3 = F1.DIV_QQ_Q(F2);
                            Print_fraction(F3);
                            _getch();
                            break;
                        }
                    }
                }
                break;
            }
            case 4:{
                int symbol_P=1;
                while (symbol_P != 8) {
                    system("cls");
                    cout << "Пожалуйста введите многочлен" << endl;
                    Polynom* P1 = new Polynom();
                    symbol_P = print_Polynom_menu();
                    switch (symbol_P) {
                        case 1:{
                            cout << "Пожалуйста введите еще один многочлен" << endl;
                            Polynom* P2 = new Polynom();
                            Polynom* P3 = P1->ADD_PP_P(P2);
                            cout << endl;
                            new_butiful_vivod(P3);
                            _getch();
                            break;
                        }
                        case 2:{
                            cout << "Пожалуйста введите еще один многочлен" << endl;
                            Polynom* P2 = new Polynom();
                            Polynom* P3 = P1->SUB_PP_P(P2);
                            cout << endl;
                            new_butiful_vivod(P3);
                            _getch();
                            break;
                        }
                        case 3:{
                            cout << "Введите Рациональное число" << endl;
                            cout << "сейчас введите числ и знам";
                            cout << "введите количество числителя элемента " << " : "; int ch_n; cin >> ch_n;
                            vector<int> ch_digit(ch_n);
                            cout << "значение числителя элемента " << " : ";
                            for (int j = 0; j < ch_n; j++)
                            {
                                std::cin >> ch_digit[j];
                            }
                            cout << "введите знак числителя элемента " << " : "; bool sign; cin >> sign;
                            cout << "введите количество знаменателя элемента " << " : "; int zn_n; cin >> zn_n;
                            vector<int> zn_digit(zn_n);
                            cout << "значение знаменателя элемента "  << " : ";
                            for (int j = 0; j < zn_n; j++)
                            {
                                std::cin >> zn_digit[j];
                            }
                            fraction F2(ch_n, ch_digit, sign, zn_n, zn_digit);
                            Polynom* P3 = P1->MUL_PQ_P(F2);
                            cout << endl;
                            new_butiful_vivod(P3);
                            _getch();
                            break;
                        }
                        case 4:{
                           Polynom* P3 = P1->MUL_Pxk_P();
                            cout << endl;
                            new_butiful_vivod(P3);
                            _getch();
                            break; 
                        }
                        case 5:{
                            fraction F3 = P1->LED_P_Q();
                            Print_fraction(F3);
                            _getch();
                            break;
                        }
                        case 6:{
                            cout << P1->DEG_P_N() << endl;
                            _getch();
                            break;
                        }
                        case 7:{
                            Polynom* P3 = P1->DER_P_P();
                            cout << endl;
                            new_butiful_vivod(P3);
                            _getch();
                            break; 
                        }
                    }
                }
                break;
            }
        }
    }
    return 0;
}
