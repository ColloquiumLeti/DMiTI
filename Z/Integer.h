#pragma
#include <iostream>
#include <string>
#include <locale.h>
#include "natural.h"

using namespace std;

class Integer {
private:
	int* digits_of_number;
	int length;
	int sign;

public:
	int* Digits_of_number() { return digits_of_number; }
	int Length() { return length; }
	int Sign() { return sign; }

	//Конструкторы
	Integer(int sign, string number) { //Инициализация объекта типа Integer
		int counter = 0;
		bool true_input = 1;
		setlocale(LC_ALL, "Russian");
		for (counter = 0; counter < number.length(); counter++) { //Проверка на корректный ввод
			if (!isdigit(number[counter]) && number[counter] != '.') true_input = false;
		}
		if (true_input == true) {
			for (counter = 0; counter < number.length(); counter++) {
				if (number[counter] == '.') break;
			}
			if (counter != 0) number.erase(counter); //Если число - десятичная дробь, то от числа берется только целая часть
			for (counter = 0; counter < number.length(); counter++) {
				if (number[counter] != '0') break;
			}
			if (counter == number.length()) { //Заполнение массива цифр для нуля
				length = 1;
				digits_of_number = new int[1];
				digits_of_number[0] = 0;
				sign = 0;
			}
			else {
				if (counter != 0) number.erase(0, counter); //Если привводе у числа есть незначащие нули, они обрезаются
				//Заполнение массива цифр для целого числа (нулевой элемент массива - первая цифра числа)
				length = number.length();
				digits_of_number = new int[length];
				for (counter = 0; counter < length; counter++) {
					digits_of_number[counter] = number[counter] - '0';
				}
			}
		}
		else { //Если введенная строка содержит символы кроме цифр и точки, то числу присваивается 0. Некорректный ввод
			cout << "Invalid input" << endl; //Вывод сообщения о некорректном вводе
			length = 1;
			digits_of_number = new int[1];
			digits_of_number[0] = 0;
			sign = 0;
		}
	}

	//Конструктор Integer для готового массива чисел и длины числа
	Integer(int digits[], int size_of_array, int new_sign) {
		digits_of_number = new int[size_of_array];
		for (int i = 0; i < size_of_array; i++) digits_of_number[i] = digits[i];
		length = size_of_array;
		sign = new_sign;;
	}

	//N-1 абсолютная величина 
	Natural ABS_Z_N() {
		return Natural(Digits_of_number(), Length());
	}

	//N-2 определение положительности 
	int POZ_Z_D() {
		if (digits_of_number[0] == 0) return 0;
		else {
			if (Sign() == 0) return 2;
			else {
				return 1;
			}
		}
	}

	//N-3 умножение на -1
	Integer MUL_ZM_Z() {
		int sign;
		if (Sign() == 0) {
			sign = 1;
		}
		else {
			sign = 0;
		}
		return Integer(Digits_of_number(), Length(), sign);
	}

	// Z-4 Преобразование натурального в целое
	Integer TRANS_N_Z(Natural number1) {
		return Integer(number1.Digits_of_number(), number1.Length(), 0);
	}

	// Z-5 Преобразование целого неотрицательного в натуральное
	Natural TRANS_Z_N() {
		if (Sign() == 0) {
			return Natural(Digits_of_number(), Length());
		}
		else {
			return Natural("0");
		}
	}

	// Z - 6 - сумма целых
	Integer ADD_ZZ_Z(Integer Y) {
		//формируем результирующую переменнную
		int sign_res = 0;
		int lenght_res;
		lenght_res = length; // по умолчанию так, но если нет то нет
		if (length < Y.length) { lenght_res = Y.length; }
		int* Arr_res = new int[lenght_res];
		Natural N_x = ABS_Z_N(); //вспомогательная переменная (модуль) - чтобы не путаться в функциях
		Natural N_y = Y.ABS_Z_N();
		Natural res_N(Arr_res, lenght_res);
		if (this->sign == Y.sign) {
			sign_res = sign;
			Natural res_N = N_x.ADD_NN_N(N_y);
			lenght_res = res_N.Length();
			Arr_res = res_N.Digits_of_number();
		}
		else {
			// COM_NN_D (N-1) Сравнение натуральных чисел: 2 - если первое больше второго, 0 - если равны, 1 - второе больше первого 
			N_x.COM_NN_D(N_y);
			switch (N_x.COM_NN_D(N_y)) {
			case 1: // Y > X
				sign_res = Y.sign;
				res_N = N_y.SUB_NN_N(N_x);
				lenght_res = res_N.Length();
				Arr_res = res_N.Digits_of_number();
				break;
			case 0: // X = Y
			case 2:  // X > Y
				sign_res = sign;
				res_N = N_x.SUB_NN_N(N_y);
				lenght_res = res_N.Length();
				Arr_res = res_N.Digits_of_number();
				break;
			}
		}
		return Integer(Arr_res, lenght_res, sign_res);
	}

	// Z-7 - разность целых
	Integer SUB_ZZ_Z(Integer Y) {
		//формируем результирующую переменнную
		int sign_res = 0;
		int lenght_res;
		lenght_res = length; // по умолчанию так, но если нет - то нет
		if (length < Y.length) { lenght_res = Y.length; }
		int* Arr_res = new int[lenght_res];
		Natural N_x = ABS_Z_N(); //вспомогательная переменная (модуль) - чтобы не путаться в функциях
		Natural N_y = Y.ABS_Z_N();
		Natural res_N(Arr_res, lenght_res);
		if (this->sign != Y.sign) { // что иронично - разница между - и + только в этом условии ))
			sign_res = sign;
			Natural res_N = N_x.ADD_NN_N(N_y);
			lenght_res = res_N.Length();
			Arr_res = res_N.Digits_of_number();
		}
		else { // COM_NN_D (N-1) Сравнение натуральных чисел: 2 - если первое больше второго, 0 - если равны, 1 - второе больше первого 
			N_x.COM_NN_D(N_y);
			switch (N_x.COM_NN_D(N_y)) {
			case 1: // Y > X
				if (Y.sign == 0) { Y.sign = 1; }
				else { Y.sign = 0; }
				sign_res = Y.sign;
				res_N = N_y.SUB_NN_N(N_x);
				lenght_res = res_N.Length();
				Arr_res = res_N.Digits_of_number();
				break;
			case 0: // X = Y
			case 2:  // X > Y
				sign_res = sign;
				res_N = N_x.SUB_NN_N(N_y);
				lenght_res = res_N.Length();
				Arr_res = res_N.Digits_of_number();
				break;
			}
		}
		return Integer(Arr_res, lenght_res, sign_res);
	}

	// Z-8 Умножение целых чисел
	Integer MUL_ZZ_Z(Integer number) {
		Natural num2 = number.ABS_Z_N();
		int s = Sign();
		if (s == number.Sign())
			s = 0;
		else
			s = 1;
		num2 = Natural(Digits_of_number(), Length()).MUL_NN_N(num2);
		int* arr = num2.Digits_of_number();
		int length = num2.Length();
		return Integer(arr, length, s);
	}

	// Z-9 Частное от деления целого на целое (делитель отличен от нуля)
	Integer DIV_ZZ_Z(Integer number) {
		Natural num2 = number.ABS_Z_N();
		int s = Sign();
		if (s == number.Sign())
			s = 0;
		else
			s = 1;
		num2 = Natural(Digits_of_number(), Length()).DIV_NN_N(num2);
		int* arr = num2.Digits_of_number();
		int length = num2.Length();
		return Integer(arr, length, s);
	}

	// Z-10 Остаток от деления целого на целое(делитель отличен от нуля)
	Integer MOD_ZZ_Z(Integer number) {
		Integer N_1(Digits_of_number(), Length(), Sign());
		Integer N_2 = number;
		switch (N_1.ABS_Z_N().COM_NN_D(N_2.ABS_Z_N())) {
		case 0: {
			return N_2.SUB_ZZ_Z(N_1);
			break;
		}
		case 1: {
			N_2 = N_2.SUB_ZZ_Z(N_2.DIV_ZZ_Z(N_1).MUL_ZZ_Z(N_1));
			return N_2;
			break;
		}
		case 2: {
			N_1 = N_1.SUB_ZZ_Z(DIV_ZZ_Z(N_2).MUL_ZZ_Z(N_2));
			return N_1;
			break;
		}
		}
	}
};
