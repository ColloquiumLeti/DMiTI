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


	//������������
	Natural(string number) { //������������� ������� ���� Natural(������ ������, �� ����)
		int counter=0;
		bool true_input = 1;
		setlocale(LC_ALL, "Russian");
		for (counter = 0; counter < number.length(); counter++) { //�������� �� ���������� ����
			if (!isdigit(number[counter]) && number[counter] != '.') true_input = false;
		}
		if (true_input==true)
		{
			for (counter = 0; counter < number.length(); counter++) { 
				if (number[counter] == '.') break;
			}
			if (counter != 0) number.erase(counter); //���� ����� - ���������� �����, �� �� ����� ������� ������ ����� �����
			for (counter = 0; counter < number.length(); counter++) {
				if (number[counter] != '0') break;
			}
			if (counter == number.length())
			{
				//���������� ������� ���� ��� ����
				length = 1;
				digits_of_number = new int[1];
				digits_of_number[0] = 0;
			}
			else
			{
				if (counter != 0) number.erase(0, counter); //���� �������� � ����� ���� ���������� ����, ��� ����������
				//���������� ������� ���� ��� ������������ ����� (������� ������� ������� - ������ ����� �����)
				length = number.length();
				digits_of_number = new int[length];
				for (counter = 0; counter < length; counter++)
				{
					digits_of_number[counter] = number[counter] - '0';
				}
			}
		}
		else //���� ��������� ������ �������� ������� ����� ���� � �����, �� ����� ������������� 0. ������������ ����
		{
			cout << "Invalid input" << endl; //����� ��������� � ������������ �����
			length = 1;
			digits_of_number = new int[1];
			digits_of_number[0] = 0;
		}
	};

	Natural(int digits[], int size_of_array) { //����������� Natural ��� �������� ������� ����� � ����� �����
		digits_of_number = new int[size_of_array];
		for (int i = 0; i < size_of_array; i++) digits_of_number[i] = digits[i];
		length = size_of_array;
	}

	//������ ��� ����������� �����
	
	//N-1 ��������� ����������� �����: 2 - ���� ������ ������ �������, 0 - ���� �����, 1- �����
	int COM_NN_D(Natural number) {
		if (length > number.Length()) return 2;
		else
		{
			if (length < number.Length()) return 1;
			else
			{
				int* digits = number.Digits_of_number();
				int counter = 0;
				while ((digits_of_number[counter] == digits[counter])&&(counter < length-1)) counter++;
				if (counter==length-1 && digits_of_number[counter] == digits[counter]) return 0;
				else
				{
					if (digits_of_number[counter] > digits[counter]) return 2;
					else return 1;
				}
			}
		}
	}

    //N-2 �������� �� ����: ���� ����� �� ����� ����, �� "��"(1) ����� "���"(0)
	bool NZER_N_B() {
		if (digits_of_number[0] == 0) return 0;
		else return 1;
	};

	//N-3 ���������� 1 � ������������ �����
	Natural ADD_1N_N()
	{
		int Length = length + 1;
		int* n = new int[Length];
		n[0] = 0;
		for (int i = 0; i < length; i++)
			n[i + 1] = digits_of_number[i];
		n[Length - 1]++;
		for (int i = Length - 1; i >= 1; i--)
			if (n[i] == 10)
			{
				n[i] = 0;
				n[i - 1]++;
			}
		if (!n[0])
		{
			Length--;
			int* c = new int[Length];
			for (int i = 0; i < Length; i++)
				c[i] = n[i + 1];
			return Natural(c, Length);
		}
		return Natural(n, Length);
	}

	//N-4 �������� ����������� �����
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
			digits_max = number.Digits_of_number(); length_diff = number.Length()-length_min;
		}
		for (int i = length_min-1; i >= 0; i--)
		{
			result = to_string((digits_max[i + length_diff] + digits_min[i] + number_of_tens) % 10) + result;
			number_of_tens = (digits_max[i + length_diff] + digits_min[i] + number_of_tens) / 10;
		}
		if (length_diff == 0 && number_of_tens != 0) result = to_string(number_of_tens) + result;
		else
		{
			for (int i = length_diff-1; i >= 0; i--)
			{
				result = to_string((digits_max[i] + number_of_tens) % 10) + result;
				number_of_tens = (digits_max[i] + number_of_tens) / 10;
			}
		}
		return Natural(result);
	}

	//N-5 ��������� �� ������� �������� ������������ ����� ������� �������� ��� �������
	Natural SUB_NN_N(Natural number)
	{
		int i;
		string result = "";
		if (this->COM_NN_D(number) == 0) return Natural("0");
		else {
			if (this->COM_NN_D(number) == 2){
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
			else{
				cout << "��������� ������ ������������ ���������" << endl;
				return Natural("0");
			}
		}
	}

	//N-6 ��������� ������������ ����� �� ����� 
	Natural MUL_ND_N(int numeral) {
		if (numeral == 0 || digits_of_number[0] == 0) return Natural("0"); //��������� �� 0 
		else
		{
			string result="";
			int number_of_tens = 0;
			for (int i = length; i > 0; i--) //��������� �� �����
			{
				result = to_string((numeral * digits_of_number[i - 1] + number_of_tens)%10) + result;
				number_of_tens = (numeral * digits_of_number[i - 1] + number_of_tens) / 10;
			}
			if (number_of_tens != 0) result = to_string(number_of_tens) + result; //���� ���������� ������ ���������� ��������� � �������� ��������� �����
			return Natural(result);
		}
	}

	//N-7 ��������� ������������ ����� �� 10^k
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

	//N-8 ��������� ����������� �����
	Natural MUL_NN_N(Natural number)
	{
		int k, p = 0, * sosi = number.Digits_of_number();
		int Size = length > number.Length() ? length * 2 : number.Length() * 2;
		if ((digits_of_number[0] == 0 && length == 1) || (sosi[0] == 0 && number.Length() == 1)) {
			return Natural("0");
		}
		else
		{
			Natural proizved("0");
			Natural result("0");
			for (int i = number.Length() - 1; i >= 0; i--)
			{
				proizved = this->MUL_ND_N(sosi[i]);
				proizved = proizved.MUL_Nk_N(number.Length() - i - 1);
				result = result.ADD_NN_N(proizved);
			}
			return result;
		}
	}

	//N-9 ��������� �� ������������ �������, ����������� �� �����, ��� ���������������� ����������
	Natural SUB_NDN_N(Natural number, int numeral) {
		number = number.MUL_ND_N(numeral);
		return this->SUB_NN_N(number);
	}

	//N-10 ���������� ������ ����� ������� �������� ������������ �� �������, ����������� �� 10^k,��� k - ����� ������� ���� ����� (����� ��������� � ����)
	Natural DIV_NN_Dk(Natural number) {

		int size_max, size_min, k = 0, i, size_result = 0, test_result, * max = 0, * min = 0, no_arr_min = 0;

		long int no_arr_max = 0, no_arr_result = 0;

		if (this->COM_NN_D(number) == 0) {

			cout << 1;

			return Natural(0);

		}

		if (this->COM_NN_D(number) == 1) {

			size_min = length;

			size_max = number.Length();

			min = digits_of_number;

			max = number.Digits_of_number();

		}

		if (this->COM_NN_D(number) == 2) {

			size_max = length;

			size_min = number.Length();

			max = digits_of_number;

			min = number.Digits_of_number();

		}

		for (i = size_min - 1; i > -1; i--) {

			no_arr_min = no_arr_min + min[i] * pow(10, size_min - i - 1);

		}

		for (i = size_max - 1; i > -1; i--) {

			no_arr_max = no_arr_max + max[i] * pow(10, size_max - i - 1);

		}

		if (no_arr_min == 0) {

			cout << "�� ���� ������ ������!" << endl;

		}

		while ((no_arr_result / 10) > 0) {

			k++;

			no_arr_result = no_arr_result / 10;

		}

		no_arr_result = no_arr_result * pow(10, k);

		test_result = no_arr_result;

		while ((test_result / 10) > 0) {

			size_result++;

			test_result = test_result / 10;

		}

		string result = "";

		for (i = size_result + 1; i > 0; i--) {

			result = to_string(no_arr_result % 10) + result;

			no_arr_result = no_arr_result / 10;

		}

		return Natural(result);

	}
	
	//N-11 ������� �� ������� �������� ������������ ����� �� ������� ��� ������ ����������� � ��������(�������� ������� �� ����)

	Natural DIV_NN_N(Natural number) {

		int size_max, size_min, k = 0, i, size_result = 0, * max = 0, * min = 0, no_arr_min = 0;

		long double no_arr_max = 0, no_arr_result = 0, test_result;

		int* result = new int[size_result];

		if (this->COM_NN_D(number) == 0) {

			cout << 1;

			return Natural(0);

		}

		if (this->COM_NN_D(number) == 1) {

			size_min = length;

			size_max = number.Length();

			min = digits_of_number;

			max = number.Digits_of_number();

		}

		if (this->COM_NN_D(number) == 2) {

			size_max = length;

			size_min = number.Length();

			max = digits_of_number;

			min = number.Digits_of_number();

		}

		for (i = size_min - 1; i > -1; i--) {

			no_arr_min = no_arr_min + min[i] * pow(10, size_min - i - 1);

		}

		for (i = size_max - 1; i > -1; i--) {

			no_arr_max = no_arr_max + max[i] * pow(10, size_max - i - 1);

		}

		if (no_arr_min == 0) {

			cout << "�� ���� ������ ������!" << endl;

		}

		no_arr_result = long double(no_arr_max / no_arr_min);

		if (int(no_arr_result) == no_arr_result) {

			test_result = no_arr_result;

			while ((test_result / 10) > 0) {

				size_result++;

				test_result = test_result / 10;

			}

			string result = "";

			for (i = size_result + 1; i > 0; i--) {

				result = to_string(int(no_arr_result) % 10) + result;

				no_arr_result = no_arr_result / 10;

			}

			return Natural(result);

		}

		else {

			cout << no_arr_result;

			return Natural(0);

		}

	}

	//N-12 ������� �� ������� �������� ������������ ����� �� ������� ��� ������ �����������(�������� ������� �� ����)

	Natural MOD_NN_N(Natural number) {

		int size_max, size_min, k = 0, i, size_result = 0, * max = 0, * min = 0;

		long int no_arr_max = 0, no_arr_result = 0, test_result, no_arr_min = 0;

		if (this->COM_NN_D(number) == 0) {

			cout << 1;

			return Natural(0);

		}

		if (this->COM_NN_D(number) == 1) {

			size_min = length;

			size_max = number.Length();

			min = digits_of_number;

			max = number.Digits_of_number();

		}

		if (this->COM_NN_D(number) == 2) {

			size_max = length;

			size_min = number.Length();

			max = digits_of_number;

			min = number.Digits_of_number();

		}

		for (i = size_min - 1; i > -1; i--) {

			no_arr_min = no_arr_min + min[i] * pow(10, size_min - i - 1);

		}

		for (i = size_max - 1; i > -1; i--) {

			no_arr_max = no_arr_max + max[i] * pow(10, size_max - i - 1);

		}

		if (no_arr_min == 0) {

			cout << "�� ���� ������ ������!" << endl;

		}

		no_arr_result = no_arr_max % no_arr_min;

		test_result = no_arr_result;

		while ((test_result / 10) > 0) {

			size_result++;

			test_result = test_result / 10;

		}

		string result = "";

		for (i = size_result + 1; i > 0; i--) {

			result = to_string(int(no_arr_result) % 10) + result;

			no_arr_result = no_arr_result / 10;

		}

		return Natural(result);

	}

	//N-13 ��� ����������� �����

	Natural GCF_NN_N(Natural number) {

		int size_max, size_min, k = 0, i, size_result = 0, test_result, * max = 0, * min = 0, no_arr_min = 0, x, y;

		long int no_arr_max = 0, no_arr_result = 0;

		if (this->COM_NN_D(number) == 0) {

			cout << 1;

			return Natural(0);

		}

		if (this->COM_NN_D(number) == 1) {

			size_min = length;

			size_max = number.Length();

			min = digits_of_number;

			max = number.Digits_of_number();

		}

		if (this->COM_NN_D(number) == 2) {

			size_max = length;

			size_min = number.Length();

			max = digits_of_number;

			min = number.Digits_of_number();

		}

		for (i = size_min - 1; i > -1; i--) {

			no_arr_min = no_arr_min + min[i] * pow(10, size_min - i - 1);

		}

		for (i = size_max - 1; i > -1; i--) {

			no_arr_max = no_arr_max + max[i] * pow(10, size_max - i - 1);

		}

		if (no_arr_min == 0) {

			cout << "��� 0 ������ ����� ���!" << endl;

			Natural(0);

		}

		while (no_arr_max % no_arr_min != 0) { // ������� ���

			x = no_arr_max / no_arr_min;

			y = no_arr_min;

			no_arr_min = no_arr_max - (no_arr_min * x);

			no_arr_max = y;

		}

		no_arr_result = no_arr_min;

		test_result = no_arr_result;

		while ((test_result / 10) > 0) {

			size_result++;

			test_result = test_result / 10;

		}

		string result = "";

		for (i = size_result + 1; i > 0; i--) {

			result = to_string(no_arr_result % 10) + result;

			no_arr_result = no_arr_result / 10;

		}

		return Natural(result);

	}

	//N-14 ��� ����������� �����

	Natural LCM_NN_N(Natural number) {

		int size_max, size_min, k = 0, i, size_result = 0, test_result, * max = 0, * min = 0, no_arr_min = 0, x, y, nok, nod, test_nod;

		long int no_arr_max = 0, no_arr_result = 0;

		if (this->COM_NN_D(number) == 0) {

			cout << 1;

			return Natural(0);

		}

		if (this->COM_NN_D(number) == 1) {

			size_min = length;

			size_max = number.Length();

			min = digits_of_number;

			max = number.Digits_of_number();

		}

		if (this->COM_NN_D(number) == 2) {

			size_max = length;

			size_min = number.Length();

			max = digits_of_number;

			min = number.Digits_of_number();

		}

		for (i = size_min - 1; i > -1; i--) {

			no_arr_min = no_arr_min + min[i] * pow(10, size_min - i - 1);

		}

		for (i = size_max - 1; i > -1; i--) {

			no_arr_max = no_arr_max + max[i] * pow(10, size_max - i - 1);

		}

		if (no_arr_min == 0) {

			cout << "��� 0 ������ ����� ���!" << endl;

			Natural(0);

		}

		nod = no_arr_min;

		test_nod = no_arr_max;

		while (test_nod % nod != 0) { // ������� ���

			x = test_nod / nod;

			y = nod;

			nod = test_nod - (nod * x);

			test_nod = y;

		}

		no_arr_result = (no_arr_max * no_arr_min) / nod; // ������� ���

		test_result = no_arr_result;

		while ((test_result / 10) > 0) {

			size_result++;

			test_result = test_result / 10;

		}

		string result = "";

		for (i = size_result + 1; i > 0; i--) {

			result = to_string(no_arr_result % 10) + result;

			no_arr_result = no_arr_result / 10;

		}

		return Natural(result);

	}
};
