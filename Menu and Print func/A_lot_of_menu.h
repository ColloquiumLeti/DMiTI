#pragma once

#include <iostream>
#include <string>
#include <locale.h>
#include <vector>
#include <conio.h>

using namespace std;

//Вывод основного меню
int print_menu() {
    int symbol = 1;
    int a = 1;
    while (a) {
        char arr[9][256] = { "\t Menu",
            "1) Natural",
            "2) Integer",
            "3) Fraction",
            "4) Polynom",
            "5) Exit"
        };
        for (int i = 0; i < 6; i++) {
            cout << arr[i];
            if (symbol == i)
                cout << "\t<--";
            cout << endl;
        }
        int But = _getch();
        if (But == 224 || But == 0)
            But = _getch();
        if (But == 72)
            if (symbol - 1 < 1)
                symbol = 5;
            else
                symbol--;
        else if (But == 80)
            if (symbol + 1 > 5)
                symbol = 1;
            else
                symbol++;
        else if (But == 13)
            a = 0;
        else if (But == 27)
            return 5;
        else if (But - '0' >= 1 && But - '0' <= 5) {
            symbol = But - '0';
            a = 0;
        }
        system("cls");
    }
    return symbol;
}


//Вывод меню для натуральных
int print_Natural_menu(){
    int symbol = 1;
    int a = 1;
    while (a) {
        char arr[16][256] = { "\t Menu of Natural",
            "1) Comparison of Natural numbers",
            "2) Checking for zero",
            "3) Adding 1 to a natural number",
            "4) Adding natural numbers",
            "5) Subtracting from the first larger natural number the second smaller or equal",
            "6) Multiplying a natural number by a digit",
            "7) Multiplying a natural number by 10^k",
            "8) Multiplication of natural numbers",
            "9) Subtracting from a natural other multiplied by a digit for a non-negative result",
            "10) Calculating the first digit of the division of the larger natural by the smaller, multiplied by 10^k",
            "11) The quotient of dividing a larger natural number by a smaller or equal natural number with the remainder",
            "12) The remainder of dividing a larger natural number by a smaller or equal natural number",
            "13) The greatest common Divisor of natural numbersvisor of natural numbers",
            "14) The smallest common quotient of natural number",
            "15) Exit"
        };
        for (int i = 0; i < 16; i++) {
            cout << arr[i];
            if (symbol == i)
                cout << "\t<--";
            cout << endl;
        }
        int But = _getch();
        if (But == 224 || But == 0)
            But = _getch();
        if (But == 72)
            if (symbol - 1 < 1)
                symbol = 15;
            else
                symbol--;
        else if (But == 80)
            if (symbol + 1 > 15)
                symbol = 1;
            else
                symbol++;
        else if (But == 13)
            a = 0;
        else if (But == 27)
            return 15;
        else if (But - '0' >= 1 && But - '0' <= 15) {
            symbol = But - '0';
            a = 0;
        }
        system("cls");
    }
    return symbol;
}


//Вывод меню для целых
int print_Integer_menu(){
    int symbol = 1;
    int a = 1;
    while (a) {
        char arr[16][256] = { "\t Menu of Integer",
            "1) Absolute value",
            "2) Definition of positivity",
            "3) Multiplying by -1",
            "4) Converting a natural to an integer",
            "5) Converting a non-negative integer to a natural",
            "6) Sum of integers",
            "7) Subtracting of integers",
            "8) Multiplying integers",
            "9) The quotient of the division of integer to integer",
            "10) The remainder of the division of integer to integer",
            "11) Exit"
        };
        for (int i = 0; i < 12; i++) {
            cout << arr[i];
            if (symbol == i)
                cout << "\t<--";
            cout << endl;
        }
        int But = _getch();
        if (But == 224 || But == 0)
            But = _getch();
        if (But == 72)
            if (symbol - 1 < 1)
                symbol = 11;
            else
                symbol--;
        else if (But == 80)
            if (symbol + 1 > 11)
                symbol = 1;
            else
                symbol++;
        else if (But == 13)
            a = 0;
        else if (But == 27)
            return 11;
        else if (But - '0' >= 1 && But - '0' <= 11) {
            symbol = But - '0';
            a = 0;
        }
        system("cls");
    }
    return symbol;
}


//Вывод меню для дробей
int print_Fraction_menu(){
    int symbol = 1;
    int a = 1;
    while (a) {
        char arr[16][256] = { "\t Menu of Fraction",
            "1) Reduction of fractions",
            "2) Integrity check",
            "3) Getting a fraction from an integer",
            "4) Converting a fraction to an integer",
            "5) Adding fractions",
            "6) Subtracting fractions",
            "7) Multiplying fractions",
            "8) Dividing fractions",
            "9) Exit"
        };
        for (int i = 0; i < 10; i++) {
            cout << arr[i];
            if (symbol == i)
                cout << "\t<--";
            cout << endl;
        }
        int But = _getch();
        if (But == 224 || But == 0)
            But = _getch();
        if (But == 72)
            if (symbol - 1 < 1)
                symbol = 9;
            else
                symbol--;
        else if (But == 80)
            if (symbol + 1 > 9)
                symbol = 1;
            else
                symbol++;
        else if (But == 13)
            a = 0;
        else if (But == 27)
            return 9;
        else if (But - '0' >= 1 && But - '0' <= 9) {
            symbol = But - '0';
            a = 0;
        }
        system("cls");
    }
    return symbol;
}



//Вывод меню для многочленов
int print_Polynom_menu(){
    int symbol = 1;
    int a = 1;
    while (a) {
        char arr[16][256] = { "\t Menu of Polynom",
            "1) Adding polynomials",
            "2) Difference of polynomials",
            "3) Multiplying by a factor",
            "4) Multiplying a polynomial by x^k",
            "5) The highest coefficient of the polynomial",
            "6) Degree of the polynomial",
            "7) Derivative of the polynomial",
            "8) Exit"
        };
        for (int i = 0; i < 9; i++) {
            cout << arr[i];
            if (symbol == i)
                cout << "\t<--";
            cout << endl;
        }
        int But = _getch();
        if (But == 224 || But == 0)
            But = _getch();
        if (But == 72)
            if (symbol - 1 < 1)
                symbol = 8;
            else
                symbol--;
        else if (But == 80)
            if (symbol + 1 > 8)
                symbol = 1;
            else
                symbol++;
        else if (But == 13)
            a = 0;
        else if (But == 27)
            return 8;
        else if (But - '0' >= 1 && But - '0' <= 8) {
            symbol = But - '0';
            a = 0;
        }
        system("cls");
    }
    return symbol;   
}

void Print_fraction(fraction F3){
    vector<int> chi = F3.get_ch();
    reverse(chi.begin(), chi.end());
    vector<int> zna = F3.get_zn();
    reverse(zna.begin(), zna.end());
    cout << "\n ";
    for (int i = 0; i < F3.get_ch_len(); i++)
    cout << chi[i];
    cout << "\n";
    F3.get_sign() > 0 ? cout << "-" : cout << " ";
    if (F3.get_ch_len() > F3.get_zn_len())
    for (int i = 0; i < F3.get_ch_len(); i++)
    cout << "_";
    else for (int i = 0; i < F3.get_zn_len(); i++)
    cout << "_";
    cout << "\n ";
    for (int i = 0; i < F3.get_zn_len(); i++)
    cout << zna[i];
    cout << "\n ";
}
