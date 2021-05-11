#include <iostream>
#include <string>
#include <locale.h>
using namespace std;

class Natural {
private:
	int* digits_of_number;
	int length;

public:
	int* Digits_of_number() { return digits_of_number; }
	int Length() { return length; }


	//Конструкторы
	Natural(string number) { //Инициализация объекта типа Natural(только гетеро, не гомо)
		int counter = 0;
		bool true_input = 1;
		setlocale(LC_ALL, "Russian");
		for (counter = 0; counter < number.length(); counter++) { //Проверка на корректный ввод
			if (!isdigit(number[counter]) && number[counter] != '.') true_input = false;
		}
		if (true_input == true)
		{
			for (counter = 0; counter < number.length(); counter++) {
				if (number[counter] == '.') break;
			}
			if (counter != 0) number.erase(counter); //Если число - десятичная дробь, то от числа берется только целая часть
			for (counter = 0; counter < number.length(); counter++) {
				if (number[counter] != '0') break;
			}
			if (counter == number.length())
			{
				//Заполнение массива цифр для нуля
				length = 1;
				digits_of_number = new int[1];
				digits_of_number[0] = 0;
			}
			else
			{
				if (counter != 0) number.erase(0, counter); //Если привводе у числа есть незначащие нули, они обрезаются
				//Заполнение массива цифр для натурального числа (нулевой элемент массива - первая цифра числа)
				length = number.length();
				digits_of_number = new int[length];
				for (counter = 0; counter < length; counter++)
				{
					digits_of_number[counter] = number[counter] - '0';
				}
			}
		}
		else //Если введенная строка содержит символы кроме цифр и точки, то числу присваивается 0. Некорректный ввод
		{
			cout << "Invalid input" << endl; //Вывод сообщения о некорректном вводе
			length = 1;
			digits_of_number = new int[1];
			digits_of_number[0] = 0;
		}
	};

	Natural(int digits[], int size_of_array) { //Конструктор Natural для готового массива чисел и длины числа
		digits_of_number = new int[size_of_array];
		for (int i = 0; i < size_of_array; i++) digits_of_number[i] = digits[i];
		length = size_of_array;
	}

	//Методы для натуральных чисел

	//N-1 Сравнение натуральных чисел: 2 - если первое больше второго, 0 - если равны, 1- иначе
	int COM_NN_D(Natural number) {
		if (length > number.Length()) return 2;
		else {
			if (length < number.Length()) return 1;
			else {
				int* digits = number.Digits_of_number();
				int counter = 0;
				while ((digits_of_number[counter] == digits[counter]) && (counter < length - 1)) counter++;
				if (counter == length - 1 && digits_of_number[counter] == digits[counter]) return 0;
				else {
					if (digits_of_number[counter] > digits[counter]) return 2;
					else return 1;
				}
			}
		}
	}

	//N-2 Проверка на ноль: если число не равно нулю, то "да"(1) иначе "нет"(0)
	bool NZER_N_B() {
		if (digits_of_number[0] == 0) return 0;
		else return 1;
	}

	//N-3 Добавление 1 к натуральному числу
	Natural ADD_1N_N() {
		int Length = length + 1;
		int* n = new int[Length];
		n[0] = 0;
		for (int i = 0; i < length; i++)
			n[i + 1] = digits_of_number[i];
		n[Length - 1]++;
		for (int i = Length - 1; i >= 1; i--)
			if (n[i] == 10) {
				n[i] = 0;
				n[i - 1]++;
			}
		if (!n[0]) {
			Length--;
			int* c = new int[Length];
			for (int i = 0; i < Length; i++)
				c[i] = n[i + 1];
			return Natural(c, Length);
		}
		return Natural(n, Length);
	}

	//N-4 Сложение натуральных чисел
	Natural ADD_NN_N(Natural number) {
		string result = "";
		int* digits_max, * digits_min;
		int number_of_tens = 0, length_diff, length_min;
		if (this->COM_NN_D(number) == 2) {
			digits_min = number.Digits_of_number(); length_min = number.Length();
			digits_max = digits_of_number; length_diff = length - length_min;
		}
		else {
			digits_min = digits_of_number; length_min = length;
			digits_max = number.Digits_of_number(); length_diff = number.Length() - length_min;
		}
		for (int i = length_min - 1; i >= 0; i--) {
			result = to_string((digits_max[i + length_diff] + digits_min[i] + number_of_tens) % 10) + result;
			number_of_tens = (digits_max[i + length_diff] + digits_min[i] + number_of_tens) / 10;
		}
		if (length_diff == 0 && number_of_tens != 0) result = to_string(number_of_tens) + result;
		else {
			for (int i = length_diff - 1; i >= 0; i--) {
				result = to_string((digits_max[i] + number_of_tens) % 10) + result;
				number_of_tens = (digits_max[i] + number_of_tens) / 10;
			}
		}
		return Natural(result);
	}

	//N-5 Вычитание из первого большего натурального числа второго меньшего или равного
	Natural SUB_NN_N(Natural number) {
		int i;
		string result = "";
		if (this->COM_NN_D(number) == 0) return Natural("0");
		else {
			if (this->COM_NN_D(number) == 2) {
				bool zaim = 0;
				for (i = length - 1; i >= 0; i--)
				{
					if (i >= length - number.Length())
					{
						if (digits_of_number[i] - number.Digits_of_number()[i - length + number.Length()] < 0) {
							zaim = 1;
							result = to_string(digits_of_number[i] - number.Digits_of_number()[i - length + number.Length()] + 10) + result;
						}
						else result = to_string(digits_of_number[i] - number.Digits_of_number()[i - length + number.Length()]) + result;
					}
					else
					{
						if (digits_of_number[i] < 0) { result = to_string(digits_of_number[i] + 10) + result; zaim = 1; }
						else result = to_string(digits_of_number[i]) + result;
					}
					digits_of_number[i - 1] = digits_of_number[i - 1] - zaim;
					zaim = 0;
				}
				return Natural(result);
			}
			else {
				cout << "Нарушение правил натурального вычитания" << endl;
				return Natural("0");
			}
		}
	}

	//N-6 Умножение натурального числа на цифру 
	Natural MUL_ND_N(int numeral) {
		if (numeral == 0 || digits_of_number[0] == 0) return Natural("0"); //Умножение на 0 
		else
		{
			string result = "";
			int number_of_tens = 0;
			for (int i = length; i > 0; i--) //Умножение на цифру
			{
				result = to_string((numeral * digits_of_number[i - 1] + number_of_tens) % 10) + result;
				number_of_tens = (numeral * digits_of_number[i - 1] + number_of_tens) / 10;
			}
			if (number_of_tens != 0) result = to_string(number_of_tens) + result; //Если наибольший разряд результата совпадает с разрядом исходного числа
			return Natural(result);
		}
	}

	//N-7 Умножение натурального числа на 10^k
	Natural MUL_Nk_N(int k)
	{
		if (!digits_of_number[0])
			return Natural("0");
		int* arr;
		int S = length;
		arr = new int[length + k];
		for (int i = 0; i < length; i++)
			arr[i] = digits_of_number[i];
		for (int i = length; i < length + k; i++)
			arr[i] = 0;
		S += k;
		return Natural(arr, S);
	}

	//N-8 Умножение натуральных чисел
	Natural MUL_NN_N(Natural number) {
		int k, p = 0, * sosi = number.Digits_of_number();
		int Size = length > number.Length() ? length * 2 : number.Length() * 2;
		if ((digits_of_number[0] == 0 && length == 1) || (sosi[0] == 0 && number.Length() == 1)) {
			return Natural("0");
		}
		else {
			Natural proizved("0");
			Natural result("0");
			for (int i = number.Length() - 1; i >= 0; i--) {
				proizved = this->MUL_ND_N(sosi[i]);
				proizved = proizved.MUL_Nk_N(number.Length() - i - 1);
				result = result.ADD_NN_N(proizved);
			}
			return result;
		}
	}

	//N-9 Вычитание из натурального другого, умноженного на цифру, для неотрицательного результата
	Natural SUB_NDN_N(Natural number, int numeral) {
		number = number.MUL_ND_N(numeral);
		return this->SUB_NN_N(number);
	}

	//N-10 Вычисление первой цифры деления большего натурального на меньшее, домноженное на 10^k,где k - номер позиции этой цифры (номер считается с нуля)
	Natural DIV_NN_Dk(Natural number) {
		int length = 1;
		int* result;
		result = new int[length + 1];
		result[0] = 1;
		Natural N_1(Digits_of_number(), Length());
		Natural N_2 = number;
		Natural rez(result, length);
		switch (N_1.COM_NN_D(N_2)) {
		case 0: {
			length = 0;
			break;
		}
		case 1: {
			length = N_2.Length() - N_1.Length() - 1;
			while (N_1.MUL_NN_N(rez.ADD_1N_N().MUL_Nk_N(length)).COM_NN_D(N_2) != 2) {
				rez = rez.ADD_1N_N();
			}
			break;
		}
		case 2: {
			length = N_1.Length() - N_2.Length() - 1;
			while (N_1.COM_NN_D(N_2.MUL_NN_N(rez.ADD_1N_N().MUL_Nk_N(length))) != 1) {
				rez = rez.ADD_1N_N();
			}
			break;
		}
		}
		return rez.MUL_Nk_N(length);
	}

	//N-11 Частное от деления большего натурального числа на меньшее или равное натуральное с остатком(делитель отличен от нуля)
	Natural DIV_NN_N(Natural number) {
		int length = 1;
		int* result;
		result = new int[length + 1];
		result[0] = 0;
		Natural N_1(Digits_of_number(), Length());
		Natural N_2 = number;
		Natural rez(result, length);
		switch (N_1.COM_NN_D(N_2)) {
		case 0: {
			length = 0;
			break;
		}
		case 1: {
			while(N_2.Length() - N_1.Length() > 0) {
				rez = rez.ADD_NN_N(N_1.DIV_NN_Dk(N_2));
				N_2 = N_2.SUB_NN_N(N_1.MUL_NN_N(N_1.DIV_NN_Dk(N_2)));
			}
			break;
		}
		case 2: {
			while (N_1.Length() - N_2.Length() > 0) {
				rez = rez.ADD_NN_N(N_1.DIV_NN_Dk(N_2));
				N_1 = N_1.SUB_NN_N(N_2.MUL_NN_N(N_1.DIV_NN_Dk(N_2)));
			}
			break;
		}
		}
		return rez;
	}

	//N-12 Остаток от деления большего натурального числа на меньшее или равное натуральное(делитель отличен от нуля)
	Natural MOD_NN_N(Natural number) {
		Natural N_1(Digits_of_number(), Length());
		Natural N_2 = number;
		switch (N_1.COM_NN_D(N_2)) {
		case 0: {
			return Natural("0");
			break;
		}
		case 1: {
			while (N_2.Length() - N_1.Length() > 0) {
				N_2 = N_2.SUB_NN_N(N_1.MUL_NN_N(N_1.DIV_NN_Dk(N_2)));
			}
			return N_2;
			break;
		}
		case 2: {
			while (N_1.Length() - N_2.Length() > 0) {
				N_1 = N_1.SUB_NN_N(N_2.MUL_NN_N(N_1.DIV_NN_Dk(N_2)));
			}
			return N_1;
			break;
		}
		}
	}

	//N-13 НОД натуральных чисел
	Natural GCF_NN_N(Natural number) {
		int length = 1;
		int* result;
		result = new int[length + 1];
		result[0] = 0;
		Natural rez(result, length);
		Natural N_1(Digits_of_number(), Length());
		Natural N_2 = number;
		while (N_1.Digits_of_number()[0] != 0 && N_2.Digits_of_number()[0] != 0){
			switch (N_1.COM_NN_D(N_2)) {
			case 0: {
				break;
			}
			case 1: {
				N_2 = N_2.MOD_NN_N(N_1);
				break;
			}
			case 2: {
				N_1 = N_1.MOD_NN_N(N_2);
				break;
			}
			}
		}
		switch (N_1.COM_NN_D(N_2)) {
		case 0: {

			return N_1;
			break;
		}
		case 1: {
			return N_2;
			break;
		}
		case 2: {
			return N_1;
			break;
		}
		}
		
	}

	//N-14 НОК натуральных чисел
	Natural LCM_NN_N(Natural number) {
		int length = 1;
		int* result;
		Natural rez(result, length);
		rez = MUL_NN_N(number);
		rez = rez.DIV_NN_N(GCF_NN_N(number));
		return rez;
	}
};
