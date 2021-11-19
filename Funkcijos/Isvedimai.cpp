#include "My_lib.h"
#include "Funkcijos.h"

void Isvedimas(vector<Studentas> &studentas)
{
	int Studgal = studentas.size();
	cout << "Norite galutini pazymi vidurkiu(v), mediana(m) ar abiem(bet koks simbolis)" << endl;
	string galutinis = Rtikrinimas();
	if (galutinis == "v" || galutinis == "V")
	{
		cout << left << setw(20) << "Vardas" << left << setw(15) << "Pavarde" << left << setw(15) << "Galutinis(vid.)" << endl;
		cout << "-----------------------------------------------------" << endl;
		for (int i = 0; i < Studgal; i++)
		{
			cout << left << setw(20) << studentas[i].vardas;
			cout << left << setw(15) << studentas[i].pavarde;
			cout << left << setw(15) << fixed << setprecision(2) << studentas[i].vidurkis << endl;
		}
	}
	else if (galutinis == "m" || galutinis == "M")
	{
		cout << left << setw(20) << "Vardas" << left << setw(15) << "Pavarde" << left << setw(15) << "Galutinis(med.)" << endl;
		cout << "-----------------------------------------------------" << endl;
		for (int i = 0; i < Studgal; i++)
		{
			cout << left << setw(20) << studentas[i].vardas;
			cout << left << setw(15) << studentas[i].pavarde;
			cout << left << setw(15) << fixed << setprecision(2) << studentas[i].mediana << endl;
		}
	}
	else
	{
		cout << left << setw(20) << "Vardas" << left << setw(15) << "Pavarde" << left << setw(16) << "Galutinis(vid.) / Galutinis(med.)" << endl;
		cout << "------------------------------------------------------------------" << endl;
		for (int i = 0; i < Studgal; i++)
		{
			cout << left << setw(20) << studentas[i].vardas;
			cout << left << setw(25) << studentas[i].pavarde;
			cout << left << setw(10) << fixed << setprecision(2) << studentas[i].vidurkis;
			cout << left << setw(10) << fixed << setprecision(2) << studentas[i].mediana << endl;
		}
	}
}
void fileIsvedimas(vector<Studentas> &studentas)
{
	ofstream pushf("Rezultatai.txt");

	int Studgal = studentas.size();
	cout << "Norite galutini pazymi vidurkiu(v), mediana(m) ar abiem(bet koks simbolis)" << endl;
	string galutinis = Rtikrinimas();
	if (galutinis == "v")
	{
		pushf << left << setw(20) << "Vardas" << left << setw(15) << "Pavarde" << left << setw(15) << "Galutinis(vid.)" << endl;
		pushf << "-----------------------------------------------------" << endl;
		for (int i = 0; i < Studgal; i++)
		{
			pushf << left << setw(20) << studentas[i].vardas;
			pushf << left << setw(15) << studentas[i].pavarde;
			pushf << left << setw(15) << fixed << setprecision(2) << studentas[i].vidurkis << endl;
		}
	}
	else if (galutinis == "m")
	{
		pushf << left << setw(20) << "Vardas" << left << setw(15) << "Pavarde" << left << setw(15) << "Galutinis(med.)" << endl;
		pushf << "------------------------------------------------------" << endl;
		for (int i = 0; i < Studgal; i++)
		{
			pushf << left << setw(20) << studentas[i].vardas;
			pushf << left << setw(15) << studentas[i].pavarde;
			pushf << left << setw(15) << fixed << setprecision(2) << studentas[i].mediana << endl;
		}
	}
	else
	{
		pushf << left << setw(20) << "Vardas" << left << setw(15) << "Pavarde" << left << setw(16) << "Galutinis(vid.) / Galutinis(med.)" << endl;
		pushf << "------------------------------------------------------------------" << endl;
		for (int i = 0; i < Studgal; i++)
		{
			pushf << left << setw(20) << studentas[i].vardas;
			pushf << left << setw(25) << studentas[i].pavarde;
			pushf << left << setw(10) << fixed << setprecision(2) << studentas[i].vidurkis;
			pushf << left << setw(10) << fixed << setprecision(2) << studentas[i].mediana << endl;
		}
	}
	pushf.close();
}
template <class X>
void FiltroIsvedimas(X &galvociai, X &vargsiukai, string file)
{
	ofstream pushK("Galvociai.txt");
	ofstream pushN("Vargsiukai.txt");
	auto start = std::chrono::high_resolution_clock::now();
	auto st = start;
	pushK << left << setw(20) << "Vardas" << left << setw(15) << "Pavarde" << left << setw(15) << "Galutinis(vid.)" << endl;
	pushK << "-----------------------------------------------------" << endl;
	for (int i = 0; i < galvociai.size(); i++)
	{
		
		pushK << left << setw(20) << galvociai[i].vardas;
		pushK << left << setw(15) << galvociai[i].pavarde;
		pushK << left << setw(15) << fixed << setprecision(2) << galvociai[i].vidurkis << endl;
	}
	pushK.close();
	std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start; // Skirtumas (s)
	cout << file << " failo ivedimas i galvocius uztruko: " << diff.count() << " s\n";
	auto start2 = std::chrono::high_resolution_clock::now();
	auto st2 = start2;
	pushN << left << setw(20) << "Vardas" << left << setw(15) << "Pavarde" << left << setw(15) << "Galutinis(vid.)" << endl;
	pushN << "-----------------------------------------------------" << endl;
	for (int i = 0; i < vargsiukai.size(); i++)
	{
		pushN << left << setw(20) << vargsiukai[i].vardas;
		pushN << left << setw(15) << vargsiukai[i].pavarde;
		pushN << left << setw(15) << fixed << setprecision(2) << vargsiukai[i].vidurkis << endl;
	}
	pushN.close();
	std::chrono::duration<double> diff2 = std::chrono::high_resolution_clock::now() - start2; // Skirtumas (s)
	cout << file << " failo ivedimas i vargsiukus uztruko: " << diff2.count() << " s\n";
}

void ListIsvedimas(list<Studentas> &galvociai, list<Studentas> &vargsiukai, string file)
{
	std::list<Studentas>::iterator it;
	ofstream pushK("Galvociai.txt", std::ofstream::out | std::ofstream::trunc);
	ofstream pushN("Vargsiukai.txt", std::ofstream::out | std::ofstream::trunc);
	auto start = std::chrono::high_resolution_clock::now();
	auto st = start;
	pushK << left << setw(20) << "Vardas" << left << setw(15) << "Pavarde" << left << setw(15) << "Galutinis(vid.)" << endl;
	pushK << "-----------------------------------------------------" << endl;
	for (it = galvociai.begin(); it != galvociai.end(); ++it)
	{
		pushK << left << setw(20) << it->vardas;
		pushK << left << setw(15) << it->pavarde;
		pushK << left << setw(15) << fixed << setprecision(2) << it->vidurkis << endl;
	}
	pushK.close();
	std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start; // Skirtumas (s)
	cout << file << " failo ivedimas i galvocius uztruko: " << diff.count() << " s\n";
	auto start2 = std::chrono::high_resolution_clock::now();
	auto st2 = start2;
	pushN << left << setw(20) << "Pavarde" << left << setw(15) << "Vardas" << left << setw(15) << "Galutinis(vid.)" << endl;
	pushN << "-----------------------------------------------------" << endl;
	for (it = vargsiukai.begin(); it != vargsiukai.end(); ++it)
	{
		pushN << left << setw(20) << it->pavarde;
		pushN << left << setw(15) << it->vardas;
		pushN << left << setw(15) << fixed << setprecision(2) << it->vidurkis << endl;
	}
	pushN.close();
	std::chrono::duration<double> diff2 = std::chrono::high_resolution_clock::now() - start2; // Skirtumas (s)
	cout << file << " failo ivedimas i vargsiukus uztruko: " << diff2.count() << " s\n";
}