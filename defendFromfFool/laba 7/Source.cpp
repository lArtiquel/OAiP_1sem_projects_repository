#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

void main()
{

	setlocale(LC_ALL, "rus");
		string s = "";
		char c;
		int n;
	cout << "введите строку символов:" << endl;
		while (1)
		{
			c = _getche();
			if ((int)c > 47 && (int)c < 58)
			{
				s += c;
			}
			else
				if (c == '\r') break;
		}

		cout <<"num str"<< s<<endl;
		system("pause");
	return;
}