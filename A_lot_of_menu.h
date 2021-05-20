#pragma once

#include <iostream>
#include <string>
#include <locale.h>
#include <vector>
#include <conio.h>

using namespace std;

//Вывод основного меню
int print_menu() {
    setlocale(LC_ALL, "Russian");
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
            "1) Сравнение Натуральных чисел",
            "2) Проверка на ноль",
            "3) Добавление 1 к натуральному числу",
            "4) Сложение натуральных чисел",
            "5) Вычитание из первого большего натурального числа второго меньшего или равного",
            "6) Умножение натурального числа на цифру",
            "7) Умножение натурального числа на 10^k",
            "8) Умножение натуральных чисел",
            "9) Вычитание из натурального другого, умноженного на цифру, для неотрицательного результата",
            "10) Вычисление первой цифры деления большего натурального на меньшее, домноженное на 10^k",
            "11) Частное от деления большего натурального числа на меньшее или равное натуральное с остатком",
            "12) Остаток от деления большего натурального числа на меньшее или равное натуральное",
            "13) НОД натуральных чисел",
            "14) НОК натуральных чисел",
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
            "1) Абсолютная величина",
            "2) Определение положительности",
            "3) Умножение на -1",
            "4) Преобразование натурального в целое",
            "5) Преобразование целого неотрицательного в натуральное",
            "6) Сумма целых",
            "7) Разность целых",
            "8) Умножение целых чисел",
            "9) Частное от деления целого на целое",
            "10) Остаток от деления целого на целое",
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
            "1) Сокращение дробей",
            "2) Проверка на целостность",
            "3) Получение из целого дробь",
            "4) Преобразование дроби в целое",
            "5) Сложение дробей",
            "6) Вычитание дробей",
            "7) Умножение дробей",
            "8) Деление дробей",
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
            "1) Сложение многочленов",
            "2) Разность многочленов",
            "3) Умножение на коэффициент",
            "4) Умножение многочлена на x^k",
            "5) Старший коэффициент многочлена",
            "6) Степень многочлена",
            "7) Производная многочлена",
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