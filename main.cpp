#include "Funkcijos/My_lib.h"
#include "Funkcijos/Main_h.h"
#include "Funkcijos/Funkcijos.h"
#include "Funkcijos/Studentas.h"

int main()
{
	int pasirinkimas;
	cout << "Kokiu budu generuosite failus? Sugeneruoti naujus failus/ivesti ranka - 1, nuskaityti is failo - 2: ";
	cin >> pasirinkimas;
	do
	{
		try
		{
			if (pasirinkimas != 1 && pasirinkimas != 2)
				throw std::invalid_argument("\n---Pakartokite ivedima, pastebimas netinkamas simbolis\n");
		}
		catch (const std::invalid_argument &e)
		{
			cout << e.what();
			cin.clear();
			cout << "Kokiu budu generuosite failus? Sugeneruoti naujus/jau esamus failus - 1, nuskaityti is failo - 2: ";
			cin >> pasirinkimas;
		}

	} while (pasirinkimas != 1 && pasirinkimas != 2);

	if (pasirinkimas == 1) //SUGENERUOTI FAILUS
	{
		vector<Studentas> studentai;
		vector<Studentas> vargsiukai;
		string a;
		cout << "Ar norite sugeneruoti studentu failus (1000 - 10000000) (t-taip)/(n-ne)?: ";
		cin >> a;
		while (a == "t")
		{
			for (size_t studSk = 1000; studSk <= 10000000; studSk *= 10)
			{
				RandomIvedimas(studSk);
			}
			break;
		}
		string x;
		string file;
		cout << "Ar norite ivesti studentus ranka(R) ar is failo(F)?: ";
		cin >> x;
		do
		{
			try
			{
				if (x != "R" && x != "r" && x != "F" && x != "f")
					throw std::invalid_argument("\n---Pakartokite ivedima, pastebimas netinkamas simbolis\n");
			}
			catch (const std::invalid_argument &e)
			{
				cout << e.what();
				cin.clear();
				cout << "Ar norite ivesti studentus ranka(R) ar is failo(F)?" << endl;
				cin >> x;
			}
		} while (x != "R" && x != "r" && x != "F" && x != "f");

		if (x == "R" || x == "r")
		{
			while (true)
			{
				Ivedimas(studentai);
				if (Rtikrinimas() != "t")
				{
					break;
				}
			}
			sortByVidurkis(studentai);
			Isvedimas(studentai);
		}
		else
		{
			cout << "Iveskite .txt failo pavadinima: ";
			cin >> file;
			fileIvedimas(studentai, file);
			sortByVidurkis(studentai);
			fileIsvedimas(studentai);
		}
		return 0;
	}
	else if (pasirinkimas == 2) // NUSKAITYTI IS FAILO
	{
		benchmark();
	}
	system("pause");
}