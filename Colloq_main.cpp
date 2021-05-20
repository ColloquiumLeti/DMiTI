
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
                    cout << "Please enter a natural number" << endl;
                    string str_For_Natural_1;
                    getline(cin, str_For_Natural_1);
                    Natural N1(str_For_Natural_1);
                    symbol_N = print_Natural_menu();
                    switch (symbol_N) {
                        case 1:{
                            cout << "Please enter another natural number" << endl;
                            string str_For_Natural_2;
                            getline(cin, str_For_Natural_2);
                            Natural N2(str_For_Natural_2);
                            cout << "Comparison result: 2 - if the first is greater than the second, 0 - if equal, 1-otherwise \n" << N1.COM_NN_D(N2) << endl;
                            _getch();
                            break;
                        }
                        case 2:{
                            cout << "Zero check: if the number is not zero ,then 'yes'(1) otherwise 'no'(0)" << N1.NZER_N_B() << endl;
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
                            cout << "Please enter another natural number" << endl;
                            string str_For_Natural_2;
                            getline(cin, str_For_Natural_2);
                            Natural N2(str_For_Natural_2);
                            Natural N3 = N2.ADD_NN_N(N1);
                            cout << "The sum is equal to" << " ";
                            for(int schetchik = 0; schetchik < N3.Length(); schetchik++){
                            cout << N3.Digits_of_number()[schetchik];
                            }
                            _getch();
                            break;
                        }
                        case 5:{
                            cout << "Please enter another natural number less than the first one" << endl;
                            string str_For_Natural_2;
                            getline(cin, str_For_Natural_2);
                            Natural N2(str_For_Natural_2);
                            Natural N3 = N1.SUB_NN_N(N2);
                            cout << "The Subtracting is equal to" << " ";
                            for(int schetchik = 0; schetchik < N3.Length(); schetchik++){
                            cout << N3.Digits_of_number()[schetchik];
                            }
                            _getch();
                            break;
                        }
                        case 6:{
                            cout << "Please enter the number by which the natural number is multiplied" << endl;
                            int number;
                            cin >> number;
                            N1 = N1.MUL_ND_N(number);
                            cout << "Multiplication by a number is equal to" << " ";
                            for(int schetchik = 0; schetchik < N1.Length(); schetchik++){
                            cout << N1.Digits_of_number()[schetchik];
                            }
                            _getch();
                            break;
                        }
                        case 7:{
                            cout << "Please enter the degree of k" << endl;
                            int number;
                            cin >> number;
                            N1 = N1.MUL_Nk_N(number);
                            cout << "Multiplication by 10^k is equal to" << " ";
                            for(int schetchik = 0; schetchik < N1.Length(); schetchik++){
                            cout << N1.Digits_of_number()[schetchik];
                            }
                            _getch();
                            break;
                        }
                        case 8:{
                            cout << "Please enter another natural number" << endl;
                            string str_For_Natural_2;
                            getline(cin, str_For_Natural_2);
                            Natural N2(str_For_Natural_2);
                            Natural N3 = N2.MUL_NN_N(N1);
                            cout << "The Multiplication is equal to" << " ";
                            for(int schetchik = 0; schetchik < N3.Length(); schetchik++){
                            cout << N3.Digits_of_number()[schetchik];
                            }
                            _getch();
                            break;
                        }
                        case 9:{
                            cout << "Please enter another natural number and the number by which it is multiplied" << endl;
                            string str_For_Natural_2;
                            getline(cin, str_For_Natural_2);
                            Natural N2(str_For_Natural_2);
                            int number;
                            cin >> number;
                            Natural N3 = N2.SUB_NDN_N(N1, number);
                            cout << "The Subtracting is equal to" << " ";
                            for(int schetchik = 0; schetchik < N3.Length(); schetchik++){
                            cout << N3.Digits_of_number()[schetchik];
                            }
                            _getch();
                            break;
                        }
                        case 10:{
                            cout << "Please enter another natural number greater than the first one" << endl;
                            string str_For_Natural_2;
                            getline(cin, str_For_Natural_2);
                            Natural N2(str_For_Natural_2);
                            Natural N3 = N2.DIV_NN_Dk(N1);
                            cout << "The result is equal to" << " ";
                            for(int schetchik = 0; schetchik < N3.Length(); schetchik++){
                            cout << N3.Digits_of_number()[schetchik];
                            }
                            _getch();
                            break;
                        }
                        case 11:{
                            cout << "Please enter another natural number greater than the first one" << endl;
                            string str_For_Natural_2;
                            getline(cin, str_For_Natural_2);
                            Natural N2(str_For_Natural_2);
                            Natural N3 = N2.DIV_NN_N(N1);
                            cout << "The result is equal to" << " ";
                            for(int schetchik = 0; schetchik < N3.Length(); schetchik++){
                            cout << N3.Digits_of_number()[schetchik];
                            }
                            _getch();
                            break;
                        }
                        case 12:{
                            cout << "Please enter another natural number greater than the first one" << endl;
                            string str_For_Natural_2;
                            getline(cin, str_For_Natural_2);
                            Natural N2(str_For_Natural_2);
                            Natural N3 = N2.MOD_NN_N(N1);
                            cout << "The remainder is equal to" << " ";
                            for(int schetchik = 0; schetchik < N3.Length(); schetchik++){
                            cout << N3.Digits_of_number()[schetchik];
                            }
                            _getch();
                            break;
                        }
                        case 13:{
                            cout << "Please enter another natural number" << endl;
                            string str_For_Natural_2;
                            getline(cin, str_For_Natural_2);
                            Natural N2(str_For_Natural_2);
                            Natural N3 = N2.GCF_NN_N(N1);
                            cout << "The greatest common Divisor is equal to" << " ";
                            for(int schetchik = 0; schetchik < N3.Length(); schetchik++){
                            cout << N3.Digits_of_number()[schetchik];
                            }
                            _getch();
                            break;
                        }
                        case 14:{
                            cout << "Please enter another natural number" << endl;
                            string str_For_Natural_2;
                            getline(cin, str_For_Natural_2);
                            Natural N2(str_For_Natural_2);
                            Natural N3 = N2.LCM_NN_N(N1);
                            cout << "The smallest common quotient is equal to" << " ";
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
                    cout << "Please enter an integer (first a sign, then a number)" << endl;
                    int sing1;
                    cin >> sing1;
                    string str_For_Integer_1;
                    getline(cin, str_For_Integer_1);
                    Integer I1(sing1, str_For_Integer_1);
                    symbol_Z = print_Integer_menu();
                    switch (symbol_Z) {
                        case 1:{
                            Natural N1 = I1.ABS_Z_N();
                            cout << "The absolute value is equal to ";
                            for(int schetchik = 0; schetchik < N1.Length(); schetchik++){
                            cout << N1.Digits_of_number()[schetchik];
                            }
                            _getch();
                            break;
                        }
                        case 2:{
                            cout << "(2-positive, 0-zero, 1-negative)   " << I1.POZ_Z_D() << endl;
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
                            cout << "Please enter one natural number" << endl;
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
                            cout << "Please enter a single integer" << endl;
                            int sing2;
                            cin >> sing2;
                            string str_For_Integer_2;
                            getline(cin, str_For_Integer_2);
                            Integer I2(sing2, str_For_Integer_2);
                            Integer I3 = I1.ADD_ZZ_Z(I2);
                            cout << "The sum is equal to" <<" "; 
                            cout << I3.Sign() << " ";
                            for(int schetchik = 0; schetchik < I3.Length(); schetchik++){
                            cout << I3.Digits_of_number()[schetchik];
                            }
                            _getch();
                            break;
                        }
                        case 7:{
                            cout << "Please enter a single integer" << endl;
                            int sing2;
                            cin >> sing2;
                            string str_For_Integer_2;
                            getline(cin, str_For_Integer_2);
                            Integer I2(sing2, str_For_Integer_2);
                            Integer I3 = I1.SUB_ZZ_Z(I2);
                            cout << "the subtraction is equal to" <<" "; 
                            cout << I3.Sign() << " ";
                            for(int schetchik = 0; schetchik < I3.Length(); schetchik++){
                            cout << I3.Digits_of_number()[schetchik];
                            }
                            _getch();
                            break;
                        }
                        case 8:{
                            cout << "Please enter a single integer" << endl;
                            int sing2;
                            cin >> sing2;
                            string str_For_Integer_2;
                            getline(cin, str_For_Integer_2);
                            Integer I2(sing2, str_For_Integer_2);
                            Integer I3 = I1.MUL_ZZ_Z(I2);
                            cout << "multiplication is equal" <<" "; 
                            cout << I3.Sign() << " ";
                            for(int schetchik = 0; schetchik < I3.Length(); schetchik++){
                            cout << I3.Digits_of_number()[schetchik];
                            }
                            _getch();
                            break;
                        }
                        case 9:{
                            cout << "Please enter a single integer" << endl;
                            int sing2;
                            cin >> sing2;
                            string str_For_Integer_2;
                            getline(cin, str_For_Integer_2);
                            Integer I2(sing2, str_For_Integer_2);
                            Integer I3 = I1.DIV_ZZ_Z(I2);
                            cout << "The quotient is equal to" <<" "; 
                            cout << I3.Sign() << " ";
                            for(int schetchik = 0; schetchik < I3.Length(); schetchik++){
                            cout << I3.Digits_of_number()[schetchik];
                            }
                            _getch();
                            break;
                        }
                        case 10:{
                            cout << "Please enter a single integer" << endl;
                            int sing2;
                            cin >> sing2;
                            string str_For_Integer_2;
                            getline(cin, str_For_Integer_2);
                            Integer I2(sing2, str_For_Integer_2);
                            Integer I3 = I1.MOD_ZZ_Z(I2);
                            cout << "The remainder is equal to" <<" "; 
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
                    cout << "Enter a Rational number" << endl;
                    cout << "now enter the numerator and denominator";
                    cout << "enter the number of the element's numerator " << " : "; int ch_n; cin >> ch_n;
                    vector<int> ch_digit(ch_n);
                    cout << "the value of the element's numerator " << " : ";
                    for (int j = 0; j < ch_n; j++)
                    {
                        std::cin >> ch_digit[j];
                    }
                    cout << "enter the element's numerator sign " << " : "; bool sign; cin >> sign;
                    cout << "enter the number of the element's denominator " << " : "; int zn_n; cin >> zn_n;
                    vector<int> zn_digit(zn_n);
                    cout << "the value of the element denominator "  << " : ";
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
                            cout << "If 1 is an integer, if 0 is not" << F1.INT_Q_B() << endl;
                            _getch();
                            break;
                        }
                        case 3:{
                            cout << "Please enter a single integer" << endl;
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
                            cout << "Enter a Rational number" << endl;
                            cout << "now enter the numerator and denominator";
                            cout << "enter the number of the element's numerator " << " : "; int ch_n; cin >> ch_n;
                            vector<int> ch_digit(ch_n);
                            cout << "the value of the element's numerator " << " : ";
                            for (int j = 0; j < ch_n; j++)
                            {
                                std::cin >> ch_digit[j];
                            }
                            cout << "enter the element's numerator sign " << " : "; bool sign; cin >> sign;
                            cout << "enter the number of the element's denominator " << " : "; int zn_n; cin >> zn_n;
                            vector<int> zn_digit(zn_n);
                            cout << "the value of the element denominator "  << " : ";
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
                            cout << "Enter a Rational number" << endl;
                            cout << "now enter the numerator and denominator";
                            cout << "enter the number of the element's numerator " << " : "; int ch_n; cin >> ch_n;
                            vector<int> ch_digit(ch_n);
                            cout << "the value of the element's numerator " << " : ";
                            for (int j = 0; j < ch_n; j++)
                            {
                                std::cin >> ch_digit[j];
                            }
                            cout << "enter the element's numerator sign " << " : "; bool sign; cin >> sign;
                            cout << "enter the number of the element's denominator " << " : "; int zn_n; cin >> zn_n;
                            vector<int> zn_digit(zn_n);
                            cout << "the value of the element denominator "  << " : ";
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
                            cout << "Enter a Rational number" << endl;
                            cout << "now enter the numerator and denominator";
                            cout << "enter the number of the element's numerator " << " : "; int ch_n; cin >> ch_n;
                            vector<int> ch_digit(ch_n);
                            cout << "the value of the element's numerator " << " : ";
                            for (int j = 0; j < ch_n; j++)
                            {
                                std::cin >> ch_digit[j];
                            }
                            cout << "enter the element's numerator sign " << " : "; bool sign; cin >> sign;
                            cout << "enter the number of the element's denominator " << " : "; int zn_n; cin >> zn_n;
                            vector<int> zn_digit(zn_n);
                            cout << "the value of the element denominator "  << " : ";
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
                            cout << "Enter a Rational number" << endl;
                            cout << "now enter the numerator and denominator";
                            cout << "enter the number of the element's numerator " << " : "; int ch_n; cin >> ch_n;
                            vector<int> ch_digit(ch_n);
                            cout << "the value of the element's numerator " << " : ";
                            for (int j = 0; j < ch_n; j++)
                            {
                                std::cin >> ch_digit[j];
                            }
                            cout << "enter the element's numerator sign " << " : "; bool sign; cin >> sign;
                            cout << "enter the number of the element's denominator " << " : "; int zn_n; cin >> zn_n;
                            vector<int> zn_digit(zn_n);
                            cout << "the value of the element denominator "  << " : ";
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
                    cout << "Please enter the polynomial" << endl;
                    Polynom* P1 = new Polynom();
                    symbol_P = print_Polynom_menu();
                    switch (symbol_P) {
                        case 1:{
                            cout << "Please enter another polynomial" << endl;
                            Polynom* P2 = new Polynom();
                            Polynom* P3 = P1->ADD_PP_P(P2);
                            cout << endl;
                            new_butiful_vivod(P3);
                            _getch();
                            break;
                        }
                        case 2:{
                            cout << "Please enter another polynomial" << endl;
                            Polynom* P2 = new Polynom();
                            Polynom* P3 = P1->SUB_PP_P(P2);
                            cout << endl;
                            new_butiful_vivod(P3);
                            _getch();
                            break;
                        }
                        case 3:{
                            cout << "Enter a Rational number" << endl;
                            cout << "now enter the numerator and denominator";
                            cout << "enter the number of the element's numerator " << " : "; int ch_n; cin >> ch_n;
                            vector<int> ch_digit(ch_n);
                            cout << "the value of the element's numerator " << " : ";
                            for (int j = 0; j < ch_n; j++)
                            {
                                std::cin >> ch_digit[j];
                            }
                            cout << "enter the element's numerator sign " << " : "; bool sign; cin >> sign;
                            cout << "enter the number of the element's denominator " << " : "; int zn_n; cin >> zn_n;
                            vector<int> zn_digit(zn_n);
                            cout << "the value of the element denominator "  << " : ";
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
