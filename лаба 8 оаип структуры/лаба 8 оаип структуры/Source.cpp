#include <iostream>
#include <fstream>
#include <string>
#include  <windows.h>

using namespace std;

class Student
{
public:
	string name, surname, patronymic;
	float ph, vm;
};

void readFile(bool &file_not_founded, Student *arr_of_accounts, int &number_of_accounts);
void menu();
void show(Student *arr_of_students, int number_of_students);
void showCleverStudents(Student *arr_of_students, int number_of_accounts);
void del(Student *arr_of_students, int &number_of_students);
void add(Student *arr_of_students, int &number_of_students);
void Update(Student *arr_of_students, int number_of_students);
void writeFile(Student *arr_of_students, int number_of_students);
void check(Student *arr_of_students, int  &number_of_students);

int const SIZE_ARR = 2;
string const FILE_FOLDER = "\\files\\statistics.txt";

void main()
{
	SetConsoleCP(1251);            //��� ������ � ������ ������� �������� �� �����
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	Student arr_of_students[SIZE_ARR];
	int number_of_students = 0;
	bool flag_exit = true, file_not_founded = false;
	readFile(file_not_founded, arr_of_students, number_of_students);
	if (file_not_founded == true) { cout << "��������, ����������, ���� ����: " << FILE_FOLDER << endl; system("pause"); return; }
	check(arr_of_students, number_of_students);

	while (flag_exit)
	{
		menu();
		int item;
		cin >> item;
		switch (item)
		{
		case 0: flag_exit = false; break;
		case 1: show(arr_of_students, number_of_students); break;
		case 2: showCleverStudents(arr_of_students, number_of_students); break;
		case 3: add(arr_of_students, number_of_students); break;
		case 4: del(arr_of_students, number_of_students); break;
		case 5: Update(arr_of_students, number_of_students); break;
		}
	}
	check(arr_of_students, number_of_students);
	writeFile(arr_of_students, number_of_students);
	cout << endl;
	system("pause");
	return;
}
//functions
void readFile(bool &file_not_founded, Student *arr_of_students, int &number_of_students)
{
	int i = 0;
	ifstream f_in(FILE_FOLDER);
	if (!f_in.is_open()) { cout << "������ �������� �����" << endl; file_not_founded = true; }
	else
	{
		cout << "���� ��� ������ ������" << endl;
		while (!f_in.eof())
		{
			if (i < SIZE_ARR)
			{
				f_in >> arr_of_students[i].name >> arr_of_students[i].surname >> arr_of_students[i].patronymic >> arr_of_students[i].ph >> arr_of_students[i].vm; i++; number_of_students++;	
			} else
			if (i == SIZE_ARR) break;
		}
	}
	f_in.close();
	return;
}

void menu()
{
	cout << "���� ��� ������ � �������������:" << endl;
	cout << "1 - ����������� ���� ���������" << endl;
	cout << "2 - ���������� ���� ���������, � ������� �� ������ � �� 8 � ����" << endl;
	cout << "3 - �������� �������� � ������" << endl;
	cout << "4 - ������� �������� �� ������" << endl;
	cout << "5 - ������������� ������ � ��������" << endl;
	cout << "0 - �����" << endl << endl;
	return;
}

void  show(Student *arr_of_students, int number_of_accounts)
{
	cout << "������� ���� ��������� :" << endl << "======================================================" << endl << "�  ���                                ������   ��" << endl;
	if (number_of_accounts != 0)
		for (int i = 0; i < number_of_accounts; i++)
		{
			cout << i + 1 << "  " << arr_of_students[i].name << " " << arr_of_students[i].surname << " " << arr_of_students[i].patronymic;
			if (arr_of_students[i].name.size()+ arr_of_students[i].surname.size()+ arr_of_students[i].patronymic.size()<33)
				for (int j = 0; j<33-(arr_of_students[i].name.size() + arr_of_students[i].surname.size() + arr_of_students[i].patronymic.size()); j++) cout << " ";
			cout << arr_of_students[i].ph;
			if (arr_of_students[i].ph < 1) cout << "        "; else cout << "        ";
			cout << arr_of_students[i].vm << endl;
		}
	cout << endl << "======================================================" << endl;
	return;
}

void  showCleverStudents(Student *arr_of_students, int number_of_accounts)
{
	int counter = 1;
	cout << "������� ���������-���������� :" << endl << "======================================================" << endl << "�    ���                                    " << "������   ��" << endl;
	if (number_of_accounts != 0)
		for (int i = 0; i < number_of_accounts; i++)
		{
			if (arr_of_students[i].ph >= 8 && arr_of_students[i].vm >= 8)
			{
				cout << counter << "    " << arr_of_students[i].name << " " << arr_of_students[i].surname << " " << arr_of_students[i].patronymic;
				if (arr_of_students[i].name.size() + arr_of_students[i].surname.size() + arr_of_students[i].patronymic.size()<37)
					for (int j = 0; j < 37 - (arr_of_students[i].name.size() + arr_of_students[i].surname.size() + arr_of_students[i].patronymic.size()); j++) cout << " ";
				cout << arr_of_students[i].ph;
				if (arr_of_students[i].ph < 1) cout << "        "; else cout << "        ";
				cout<<arr_of_students[i].vm << endl;
				counter++;
			}
		}
	cout << endl << "======================================================" << endl;
	return;
}

void add(Student *arr_of_students, int &number_of_students)
{
	if (number_of_students < SIZE_ARR)
	{
		cout << "������� ��� �������� � ������� �� ������ � �� ����� ������" << endl << endl;
		cin >> arr_of_students[number_of_students].name >> arr_of_students[number_of_students].surname >> arr_of_students[number_of_students].patronymic >> arr_of_students[number_of_students].ph >> arr_of_students[number_of_students].vm;
		number_of_students += 1;
		cout << "������� ������ ������� ���������" << endl << endl;
	}
	else cout << "������ �������� ������� ������, �� ������� ����� �������� ������ ��� ������ , ���� ����������" << endl << endl;
	return;
}

void del(Student *arr_of_students, int &number_of_students)
{
	if (number_of_students == 0) { cout << "������� ������" << endl << endl; return; }
	int num_account;
	bool flag = true;
	while (flag)
	{
		cout << "������ �� � �������� ������ �������?" << endl;
		cin >> num_account;
		if (num_account>number_of_students || num_account<1) cout << "������ � �������� �� ����������" << endl; else flag = false;
	}
	if (num_account != number_of_students)
	{
		for (int i = num_account - 1; i < number_of_students - 1; i++)
		{
			arr_of_students[i].name = arr_of_students[i + 1].name;
			arr_of_students[i].surname = arr_of_students[i + 1].surname;
			arr_of_students[i].patronymic = arr_of_students[i + 1].patronymic;
			arr_of_students[i].ph = arr_of_students[i + 1].ph;
			arr_of_students[i].vm = arr_of_students[i + 1].vm;
		}
		number_of_students -= 1;
	}
	else number_of_students -= 1;
	cout << "������� ������� ������" << endl << endl;
	return;
}

void Update(Student *arr_of_students, int number_of_students)
{
	if (number_of_students == 0) { cout << "������������� ������" << endl << endl; return; }
	int num_account;
	bool flag = true;
	while (flag)
	{
		cout << "������� � ��������, ���������� � ������� ������ ��������" << endl;
		cin >> num_account;
		if (num_account > number_of_students || num_account<1) cout << "������ � �������� �� ����������" << endl; else flag = false;
	}
	cout << "������� ����������� ��� �������� � ������� �� ������ � �� ����� ������" << endl << endl;
	cin >> arr_of_students[num_account - 1].name >> arr_of_students[num_account - 1].surname >> arr_of_students[num_account - 1].patronymic >> arr_of_students[num_account - 1].ph >> arr_of_students[num_account - 1].vm;
	cout << "������� ������ ������� ���������" << endl << endl;
	return;
}

void writeFile(Student *arr_of_students, int number_of_students)
{
	ofstream f_out(FILE_FOLDER);
	for (int i = 0; i < number_of_students; i++)
	{
		f_out << arr_of_students[i].name << " " << arr_of_students[i].surname << " " << arr_of_students[i].patronymic << " " << arr_of_students[i].ph << " " << arr_of_students[i].vm;
		if (i != number_of_students - 1) f_out << endl;
	}
	f_out.close();
	cout << "���� ��� ������� �����������" << endl;
	return;
}

void check(Student *arr_of_students, int  &number_of_students)
{
	if (number_of_students > 0)
	{
		for (int i = 0; i < number_of_students; i++)

			if (arr_of_students[i].name == "" || arr_of_students[i].surname == "" || arr_of_students[i].ph > 10 || arr_of_students[i].ph < 0 || arr_of_students[i].vm > 10 || arr_of_students[i].vm< 0)
				if (i + 1 != number_of_students)
				{
					for (int j = i; j < number_of_students - 1; j++)
					{
						(*(arr_of_students+j)).name = arr_of_students[j + 1].name;
						arr_of_students+j->surname = arr_of_students[j + 1].surname;
						arr_of_students[j].patronymic = arr_of_students[j + 1].patronymic;
						arr_of_students[j].ph = arr_of_students[j + 1].ph;
						arr_of_students[j].vm = arr_of_students[j + 1].vm;
					}
					number_of_students -= 1;
				}
				else number_of_students -= 1;
	}
	return;
}