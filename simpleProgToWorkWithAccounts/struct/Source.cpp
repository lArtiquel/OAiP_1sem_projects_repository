#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;
class Account
{	
	public:
	string login;
	string password;
	int role;
};

void readFileAccounts(bool &file_not_founded, Account *arr_of_accounts, int &number_of_accounts);
void menuAccounts();
void showAccounts(Account *arr_of_accounts, int number_of_accounts);
void del_accounts(Account *arr_of_accounts, int &number_of_accounts);
void addAccount(Account *arr_of_accounts, int &number_of_accounts);
void UpdateAccount(Account *arr_of_accounts, int number_of_accounts);
void writeFileAccounts(Account *arr_of_accounts, int number_of_accounts);
void checkAccounts(Account *arr_of_accounts, int  &number_of_accounts);

int const SIZE_ARR_OF_ACCOUNTS = 2;
string const FILE_OF_ACCOUNTS = "D://����//VISUAL STUDIA PROJECTS//struct//struct//files//Accounts.txt";

void main()
{
	SetConsoleCP(1251);              
	SetConsoleOutputCP(1251);    //��� ����������� ���������� � ������ ������� ����
	setlocale(LC_ALL, "rus");
	Account arr_of_accounts[SIZE_ARR_OF_ACCOUNTS];
	int number_of_accounts=0;
	bool flag_exit=true,file_not_founded=false;
	readFileAccounts(file_not_founded,arr_of_accounts, number_of_accounts);
	if (file_not_founded == true) { cout << "create file at this folder: " << FILE_OF_ACCOUNTS << endl; system("pause"); return; }
	checkAccounts(arr_of_accounts, number_of_accounts);

	while(flag_exit)
	{
	menuAccounts();
	int item;
	cin>>item;
	switch (item)
	{
	case 0: flag_exit=false;break;
	case 1: showAccounts(arr_of_accounts, number_of_accounts);break;
	case 2: addAccount(arr_of_accounts, number_of_accounts);break;
	case 3: del_accounts(arr_of_accounts, number_of_accounts);break;
	case 4: UpdateAccount(arr_of_accounts, number_of_accounts);break;
	}
	}
	writeFileAccounts(arr_of_accounts, number_of_accounts);
	cout << endl;
	system("pause");
	return;
}

void readFileAccounts(bool &file_not_founded, Account *arr_of_accounts, int &number_of_accounts)
{
	int i = 0;
	ifstream f_in(FILE_OF_ACCOUNTS);
	if (!f_in.is_open()) {cout << "Error opening file" << endl; file_not_founded = true;} else 
	{
		cout << "File is opened" << endl;
		while (!f_in.eof())
		{
			if (i < SIZE_ARR_OF_ACCOUNTS)
				{
					f_in >> arr_of_accounts[i].login >> arr_of_accounts[i].password >> arr_of_accounts[i].role; i++; number_of_accounts++;
				}
			if (i == SIZE_ARR_OF_ACCOUNTS) break;
		}
	}
	f_in.close();
	return;
}

void menuAccounts()
{
	cout << "���� ��� ����� � �������� �������� �������������:"<<endl;
	cout << "1 - ����������� ��� ������� ������"<<endl;
	cout << "2 - �������� ������� ������" << endl;
	cout << "3 - ������� ������� ������" << endl;
	cout << "4 - ������������� ������� ������" << endl;
	cout << "0 - �����" << endl << endl;
	return;
}

void  showAccounts(Account *arr_of_accounts, int number_of_accounts)
{	
	cout << "������� ������� ������� ������������� :" << endl << "======================================" <<endl<<"�     �����        ������       ���� "<< endl;
	if (number_of_accounts!=0)
		for (int i = 0; i < number_of_accounts; i++)
		{
			cout << i + 1 << "     " << arr_of_accounts[i].login;
			if (arr_of_accounts[i].login.size() < 14)
				for (int j = 0; j < 13 - arr_of_accounts[i].login.size(); j++) cout << " ";
			cout << arr_of_accounts[i].password;
			if (arr_of_accounts[i].password.size() < 14)
				for (int j = 0;j < 13 - arr_of_accounts[i].password.size(); j++) cout << " ";
			cout << arr_of_accounts[i].role << endl;
			if (i == number_of_accounts - 1) cout << endl;
		}
	cout << "======================================" << endl;
	return;
}

void addAccount(Account *arr_of_accounts,int &number_of_accounts)
{
	if (number_of_accounts < SIZE_ARR_OF_ACCOUNTS)
	{
	cout << "������� �����, ������ � ������������� ������� ������������(0-������������,1-�������������)." << endl;
	cout << "�.�.������������� ������� � ������ � ������ �� �����������." <<endl; 
	cin >> arr_of_accounts[number_of_accounts].login >> arr_of_accounts[number_of_accounts].password >> arr_of_accounts[number_of_accounts].role;
	number_of_accounts += 1;
	cout << "������� ������ ������� ���������" << endl<<endl;
	}
	else cout << "������ �������� ������� ������, �� ������� ����� �������� ������ ��� ������, ���� ����������" << endl <<endl;
	return;
}

void del_accounts(Account *arr_of_accounts,int &number_of_accounts)
{
	if (number_of_accounts == 0) { cout << "������� ������" << endl << endl; return; }
	int num_account;
	bool flag = true;
	while (flag)
	{	
		cout << "����� � �������a ������ �������?" << endl;
		cin >> num_account;
		if (num_account>number_of_accounts || num_account<1) cout << "������ �������� �� ����������" << endl; else flag = false;
	}
	if (num_account != number_of_accounts)
	{
		for (int i = num_account - 1; i < number_of_accounts - 1; i++)
		{
			arr_of_accounts[i].login = arr_of_accounts[i + 1].login;
			arr_of_accounts[i].password = arr_of_accounts[i + 1].password;
			arr_of_accounts[i].role = arr_of_accounts[i + 1].role;
		}
		number_of_accounts -= 1;
	} else number_of_accounts -= 1;	
	cout << "������� ������� ������"<<endl<<endl;
	return;
}

void UpdateAccount(Account *arr_of_accounts, int number_of_accounts)
{
	if (number_of_accounts == 0) { cout << "������������� ������" << endl << endl; return; }
	int num_account;
	bool flag = true;
	while (flag)
	{	
		cout << "����� �� ������ ������� ������ ��������?" << endl;
		cin >> num_account;
		if (num_account > number_of_accounts || num_account<1) cout << "������ �������� �� ����������" << endl; else flag = false;
	}
	cout << "������� �����, ������ � �������������� ������� ������������(0-������������,1-�������������)." << endl;
	cout << "�.�.������������� ������� � ������ � ������ �� �����������." << endl;
	cin >> arr_of_accounts[num_account - 1].login >> arr_of_accounts[num_account - 1].password >> arr_of_accounts[num_account - 1].role;
	cout<<"������� ������ ������� ���������"<< endl << endl;
	return;
}

void writeFileAccounts(Account *arr_of_accounts, int number_of_accounts)
{		
		checkAccounts(arr_of_accounts, number_of_accounts);
		ofstream f_out(FILE_OF_ACCOUNTS);
		for (int i = 0; i < number_of_accounts; i++)
		{
			f_out << arr_of_accounts[i].login << " " << arr_of_accounts[i].password << " " << arr_of_accounts[i].role;
			if (i != number_of_accounts - 1) f_out << endl;
		}
		f_out.close();
		cout << "���� ��� ������� �����������" << endl;
		return;
}

void checkAccounts(Account *arr_of_accounts,int  &number_of_accounts)
{
	if (number_of_accounts > 0)
	{
		for (int i = 0; i < number_of_accounts; i++)
		{
			if (arr_of_accounts[i].login == "" || arr_of_accounts[i].password == "" || arr_of_accounts[i].role > 1 || arr_of_accounts[i].role < 0)
			{
				if (i+1 != number_of_accounts)
				{
					for (int j=i; j < number_of_accounts - 1; j++)
					{
						arr_of_accounts[i].login = arr_of_accounts[i + 1].login;
						arr_of_accounts[i].password = arr_of_accounts[i + 1].password;
						arr_of_accounts[i].role = arr_of_accounts[i + 1].role;
					}
					number_of_accounts -= 1;
				}
				else number_of_accounts -= 1;
			}
		}
	}
return;	
}