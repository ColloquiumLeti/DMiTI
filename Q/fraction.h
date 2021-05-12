#pragma once
#include <vector>
#include <conio.h>
#include <string>
#include "Natural.h"
#include "Integer.h"
using namespace std;
class fraction
{
public:
	//Конструктор для готовых данных

	fraction(int ch_n,vector<int> ch_digit, bool sign, int zn_n,vector<int> zn_digit)
	{
		this->ch_n = ch_n; //Кол-во символов числителя
		this->ch_digit = ch_digit; //Цифры числителя
		this->sign = sign; // Знак
		this->zn_n = zn_n;
		this->zn_digit = zn_digit;
	}

	//Пустой конструктор

	fraction()
	{
		this->ch_n = 0; //Кол-во символов числителя
		this->ch_digit.clear(); //Цифры числителя
		this->sign = 0; // Знак
		this->zn_n = 0;
		this->zn_digit.clear();
	}

	//Для всех функций преобразования из дробей в целые или натуральные необходим REVERSE(), т.к. числа хранятся в обратном порядке (число 123 как (3,2,1))

	Integer FracToInt(vector<int> digits, int len, bool sign)
	{
		int* nums;
		nums = new int(len);
		reverse(digits.begin(), digits.end());
		for (int i = 0; i < digits.size(); i++)
			nums[i]=digits[i];
		Integer integ(nums, len, sign);
		return integ;
	}
	vector<int> IntToFrac(Integer integ)
	{
		vector<int> nums;
		int* digits;
		digits = new int(integ.Length());
		digits = integ.Digits_of_number();
		for (int i = 0; i < integ.Length(); i++)
			nums.push_back(digits[i]);
		reverse(nums.begin(), nums.end());
		return nums;
	}
	vector<int> NatToFrac(Natural nat)
	{
		vector<int> nums;
		int* digits;
		digits = new int(nat.Length());
		digits = nat.Digits_of_number();
		for (int i = 0; i < nat.Length(); i++)
			nums.push_back(digits[i]);
		reverse(nums.begin(), nums.end());
		return nums;
	}
	Natural FracToNat(vector<int> digits,int len)
	{
		int* nums;
		reverse(digits.begin(), digits.end());
		nums = new int [len];
		for (int i = 0; i < len; i++)
			nums[i] = digits[i];
		Natural Nat(nums, len);
		return Nat;
	}

	//Сложение

	fraction ADD_QQ_Q(fraction drob2)
	{
		fraction drob3;
		vector<int> temp1, temp2;
		Natural n1 = FracToNat(zn_digit, zn_n);
		Natural n2 = FracToNat(drob2.zn_digit, drob2.zn_n);
		drob3.zn_digit = NatToFrac(n1.LCM_NN_N(n2)); // Знаменатель дроби - НОК двух дробей
		drob3.zn_n = drob3.zn_digit.size();
		Natural n3 = FracToNat(drob3.zn_digit, drob3.zn_n);
		temp1 = NatToFrac(n1.DIV_NN_N(n3)); // Число, при умножении на которе первый знаменатель становится = НОК
		Integer in1 = FracToInt(ch_digit, ch_n, sign);
		Integer in2 = FracToInt(temp1, temp1.size(), 0);
		temp1 = IntToFrac(in1.MUL_ZZ_Z(in2)); // Числитель первой дроби, умноженный на это число
		temp2 = NatToFrac(n2.DIV_NN_N(n3)); // То же самое для второй дроби
		Integer in3 = FracToInt(temp2, temp2.size(), 0);
		Integer in4 = FracToInt(drob2.ch_digit, drob2.ch_n, drob2.sign);
		temp2 = IntToFrac(in3.MUL_ZZ_Z(in4));
		in2 = FracToInt(temp2, temp2.size(), drob2.sign);
		in3 = FracToInt(temp1, temp1.size(), sign);
		in4 = in3.ADD_ZZ_Z(in2);
		drob3.ch_digit = IntToFrac(in3.ADD_ZZ_Z(in2)); // Вычитаем из числителя первой дроби числитель второй
		drob3.ch_n = drob3.ch_digit.size();
		drob3.sign = in4.Sign();
		return drob3;
	}

	//Вычитание

	fraction SUB_QQ_Q(fraction drob2)
	{
		fraction drob3;
		vector<int> temp1, temp2;
		Natural n1 = FracToNat(zn_digit,zn_n);
		Natural n2 = FracToNat(drob2.zn_digit, drob2.zn_n);
		drob3.zn_digit = NatToFrac(n1.LCM_NN_N(n2)); // Знаменатель дроби - НОК двух дробей
		drob3.zn_n = drob3.zn_digit.size();
		Natural n3 = FracToNat(drob3.zn_digit, drob3.zn_n);
		temp1 = NatToFrac(n1.DIV_NN_N(n3)); // Число, при умножении на которе первый знаменатель становится = НОК
		Integer in1 = FracToInt(ch_digit, ch_n, sign);
		Integer in2 = FracToInt(temp1, temp1.size(), 0);
		temp1 = IntToFrac(in1.MUL_ZZ_Z(in2)); // Числитель первой дроби, умноженный на это число
		temp2 = NatToFrac(n2.DIV_NN_N(n3)); // То же самое для второй дроби
		Integer in3 = FracToInt(temp2, temp2.size(), 0);
		Integer in4 = FracToInt(drob2.ch_digit, drob2.ch_n, drob2.sign);
		temp2 = IntToFrac(in3.MUL_ZZ_Z(in4));
		in2 = FracToInt(temp2, temp2.size(), drob2.sign);
		in3 = FracToInt(temp1, temp1.size(), sign);
		in4 = in3.SUB_ZZ_Z(in2);
		drob3.ch_digit = IntToFrac(in3.SUB_ZZ_Z(in2)); // Вычитаем из числителя первой дроби числитель второй
		drob3.ch_n = drob3.ch_digit.size();
		drob3.sign = in4.Sign();
		return drob3;
	}

	//Работает, но если переполняется long int, используемый в MOD_NN_N, то ничерта не работает

	bool INT_Q_B()
	{
		Natural n1 = FracToNat(zn_digit, zn_n);
		Natural n2 = FracToNat(ch_digit, ch_n);
		vector<int> attempt = NatToFrac(n1.MOD_NN_N(n2));
		if ((attempt[0] == 0)&&(attempt.size()==1)) // Если при делении числителя на знаменатель остаток = 0, то число целое, иначе - нет
			return 1;
		else return 0;
	}

	//Сокращение дробей

	fraction RED_Q_Q() //  ABS_Z_N(модуль)  GCF_NN_N(НОД натуральных чисел) DIV_ZZ_Z(Частное от деления целого на целое (делитель отличен от нуля)
	{
		Integer chisl = FracToInt(ch_digit, ch_n, sign);
		Natural znam = FracToNat(zn_digit, zn_n);
		Natural X = znam.GCF_NN_N(chisl.ABS_Z_N()); // от модуля находим НОД
		Integer X_I(X.Digits_of_number(), X.Length(), 0);
		Integer znam_I(znam.Digits_of_number(), znam.Length(), 0);
		chisl = chisl.DIV_ZZ_Z(X_I);
		znam_I = znam_I.DIV_ZZ_Z(X_I);
		znam = Natural(znam_I.Digits_of_number(), znam_I.Length());
		if (chisl.Digits_of_number()[0] == 0) { chisl.Digits_of_number()[0] = 1; } // костылёчки 
		if (znam.Digits_of_number()[0] == 0) { znam.Digits_of_number()[0] = 1; }
		vector<int> temp1, temp2;
		temp1 = IntToFrac(chisl);
		temp2 = NatToFrac(znam);
		fraction sokr(temp1.size(), temp1, chisl.Sign(), temp2.size(), temp2);
		return sokr;
	}

	// метод, делающий из целого числа дробь, допустим число 6 можно представить как 36/6

	fraction TRANS_Z_Q(Integer int_input)
	{
		fraction drob4;
		drob4.ch_digit = IntToFrac(int_input);
		drob4.ch_n = drob4.ch_digit.size();
		drob4.sign = int_input.Sign();
		Natural chisl = FracToNat(ch_digit, ch_n); //числитель
		drob4.zn_digit = drob4.ch_digit;
		drob4.zn_n = drob4.ch_n;
		drob4.ch_digit = NatToFrac(chisl.MUL_NN_N(chisl)); // числитель умноженный на числитель
		drob4.ch_n = drob4.ch_digit.size();
		Natural znam = chisl; // знаменатель
		return  drob4;

	}

	//метод, преобразующий дробь в целое, если знаменатель равен единице

	Integer TRANS_Q_Z()
	{
		Integer chisl = FracToInt(ch_digit, ch_n, sign); //числитель
		if (zn_n == 1 && zn_digit[0] == 1)
			return chisl;
		else
			cout << "Знаменатель не равен единице!";
	}

	int get_ch_len()
	{
		return ch_n;
	}
	vector<int> get_ch()
	{
		return ch_digit;
	}
	int get_zn_len()
	{
		return zn_n;
	}
	vector<int> get_zn()
	{
		return zn_digit;
	}
	bool get_sign()
	{
		return sign;
	}
private:
	bool sign; //Знак
	int ch_n; //Кол-во цифр числителя
	vector <int> ch_digit; //Цифры числителя
	int zn_n; //Аналогично со знаменателем
	vector <int> zn_digit;
};
