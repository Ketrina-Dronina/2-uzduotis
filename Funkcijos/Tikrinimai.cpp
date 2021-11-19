#include "My_lib.h"

string Rtikrinimas()
{
	string n;
	cin >> n;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "\n---Pakartokite ivedima, pastebimas netinkamas simbolis\n";
		cin >> n;
	}
	return n;
}

int Sktikrinimas()
{
	int n;
	cin >> n;
	while (n < 1 || n > 10)
	{
		cin.clear();
		cin.ignore();
		cout << "\n---Pakartokite ivedima, pastebimas netinkamas simbolis\n";
		cin >> n;
	}
	return n;
}

int Paztikrinimas()
{
	int n;
	cin >> n;
	while (n < 0 || n > 10)
	{
		cin.clear();
		cin.ignore();
		cout << "\n---Pakartokite ivedima, pastebimas netinkamas simbolis\n";
		cin >> n;
	}
	return n;
}

bool filetikrinimas(int n)
{
	if (n > 0 && n < 11)
	{
		return true;
	}
	else
		return false;
}

int StudentuSK()
{
	int n;
	cin >> n;
	while (n < 1)
	{
		cin.clear();
		cin.ignore();
		cout << "\n---Pakartokite ivedima, pastebimas netinkamas simbolis\n";
		cin >> n;
	}
	return n;
}

bool compare(const Studentas &studentas1, const Studentas &studentas2)
{
	return studentas1.vidurkis > studentas2.vidurkis;
}

auto Find(const Studentas &studentas)
{
	return studentas.vidurkis < 5;
}