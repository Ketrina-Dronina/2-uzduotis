#include "Funkcijos/My_lib.h"
#include "Funkcijos/Main_h.h"
#include "Funkcijos/Funkcijos.h"

void pasirinkimai()
{
	cout << "Kuri konteineri naudosite? (vector - 1, deque - 2, list - 3)" << endl;
}
void strategija()
{
	cout << "Kuria strategija naudosite? (1 stategija - 1, 2 strategija - 2)" << endl;

	//Iveskite 1 norint atlikti spartos analize naudojant 2 naujus konteinerius - 1 strategija
	//Iveskite 2 norint atlikti spartos analize naudojant 1 nauja konteineri - 2 strategija
}

int main()
{
	string pasirinkimas;
	int spartosP;
	int strateg;
	cout << "Ar norite atlikti spartos analize(A) ar norite ivesti ranka(R)?" << endl;
	cin >> pasirinkimas;
	do
	{
		try
		{
			if (pasirinkimas != "A" && pasirinkimas != "a" && pasirinkimas != "R" && pasirinkimas != "r")
				throw std::invalid_argument("\n---Pakartokite ivedima, pastebimas netinkamas simbolis\n");
		}
		catch (const std::invalid_argument &e)
		{
			cout << e.what();
			cin.clear();
			cout << "Ar norite atlikti spartos analize(A) ar norite ivesti ranka(R)?" << endl;
			cin >> pasirinkimas;
		}
	} while (pasirinkimas != "A" && pasirinkimas != "a" && pasirinkimas != "R" && pasirinkimas != "r");

	if (pasirinkimas == "A" || pasirinkimas == "a")
	{
		strategija();
		cin >> strateg;
		do
		{
			try
			{
				if (strateg != 1 && strateg != 2)
					throw std::invalid_argument("\n---Pakartokite ivedima, pastebimas netinkamas simbolis\n");
			}
			catch (const std::invalid_argument &e)
			{
				cout << e.what();
				cin.clear();
				strategija();
				cin >> strateg;
			}
		} while (strateg != 1 && strateg != 2);

		pasirinkimai();
		cin >> spartosP;
		do
		{
			try
			{
				if (spartosP < 1 || strateg > 3)
					throw std::invalid_argument("\n---Pakartokite ivedima, pastebimas netinkamas simbolis\n");
			}
			catch (const std::invalid_argument &e)
			{
				cout << e.what();
				cin.clear();
				strategija();
				cin >> strateg;
			}
		} while (strateg < 1 || strateg > 3);
		benchmark(spartosP, strateg);
	}
	else //Pasirinkimas R/r
	{
		vector<Studentas> studentai;
		vector<Studentas> vargsiukai;
		cout << "Ar norite sugeneruoti studentu faila (t-taip)/(n-ne)?" << endl;
		string a;
		int studSk;
		cin >> a;
		while (a == "t")
		{
			cin.clear();
			cout << "Iveskite studentu kieki" << endl;
			studSk = StudentuSK();
			RandomIvedimas(studSk);
			cout << "Ar norite sugeneruoti dar viena faila (t-taip)/(n-ne)?" << endl;
			cin >> a;
		}

		cout << "Ar norite ivesti studentus ranka(R) ar is failo(F)?" << endl;
		string x;
		string file;
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
				Studentas studentas;
				Ivedimas(studentas);
				vidurkis(studentas);
				mediana(studentas);
				studentai.push_back(studentas);
				if (Rtikrinimas() != "t")
				{
					break;
				}
			}
			sort(studentai.begin(), studentai.end(), compare);
			Isvedimas(studentai);
		}
		else
		{
			cout << "Iveskite .txt failo pavadinima" << endl;
			cin >> file;
			fileIvedimas(studentai, file);
			cout << "Norite faila filtruoti ar rusiuoti? (f-filtruoti, r-rusiuoti)" << endl;
			cin >> pasirinkimas;
			do
			{
				try
				{
					if (pasirinkimas != "F" && pasirinkimas != "f" && pasirinkimas != "R" && pasirinkimas != "r")
						throw std::invalid_argument("\n---Pakartokite ivedima, pastebimas netinkamas simbolis\n");
				}
				catch (const std::invalid_argument &e)
				{
					cout << e.what();
					cin.clear();
					cout << "Norite faila filtruoti ar rusiuoti? (f-filtruoti, r-rusiuoti)" << endl;
					cin >> pasirinkimas;
				}
			} while (pasirinkimas != "F" && pasirinkimas != "f" && pasirinkimas != "R" && pasirinkimas != "r");

			if (pasirinkimas == "F" || pasirinkimas == "f")
			{
				filtras(studentai, vargsiukai, file);
				FiltroIsvedimas(studentai, vargsiukai, file);
			}
			else
			{
				sort(studentai.begin(), studentai.end(), compare);
				fileIsvedimas(studentai);
			}

			//Isvedimas(A, i);
		}
		return 0;
	}
	system("pause");
}