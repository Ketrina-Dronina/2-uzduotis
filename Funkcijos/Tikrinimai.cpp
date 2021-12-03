#include "My_lib.h"
#include "Studentas.h"

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

int StudentuSK()
{
	int n;
	cin >> n;
	while (n < 1)
	{
		cout << "Bloga Ivestis. Prasome ivesti skaciu didesni uz 1" << endl;
		cin.clear();
		cin.ignore();
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

template <class X>
void sortByVidurkis(X &studentas)
{
	sort(studentas.begin(), studentas.end(), compare);
}