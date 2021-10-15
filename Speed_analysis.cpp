#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <numeric>
#include <chrono>
using namespace std;

struct studentas {
    string vardas, pavarde;
    vector<int> nd = {0};
    float egz;
    float galutinis;
};
int Random(){
    return rand() % 10 + 1;
}
vector<int>nd_auto(int nd_kiekis){
    vector<int> skaiciai;
    for(int i=0; i<nd_kiekis; i++){
        skaiciai.push_back(Random());
    }
    return skaiciai;
}
float generate_random_mark(vector<int> skaiciai){
    studentas Eil;
    Eil.galutinis = 0.4 * accumulate(skaiciai.begin(), skaiciai.end(), 0) / skaiciai.size() + 0.6 * Random();
	return Eil.galutinis;
}
int generavimas(vector<int> pazymiai){
    int kiek;
    cout << "-----------------------------------------------------------------------------\n";
    cout << "***@mif.vu.lt " << setw(64) << "Prisijungta prie sistemos\n";
    cout << "Galutiniu pazymiu skaiciuoklis ir programos veikimo greicio (spartos) analize\n";
    cout << "-----------------------------------------------------------------------------\n";
	cout << "IVESKITE koki kieki studentu norite sugeneruoti: ";
	cin >> kiek;
	string pavadinimas = "Studentai_" + to_string(kiek) + ".txt";
    auto start = chrono::high_resolution_clock::now();
	auto st = start;
	ofstream out_data(pavadinimas);
	vector<int> skaiciai;
	studentas Eil;
    out_data << setw(20) << left << "Vardas"
             << setw(20) << left << "Pavarde"
             << left << "Galutinis(Vid.)\n";
	for (int s = 1; s <= kiek; s = s + 1){
		skaiciai = nd_auto(5);
		out_data << setw(20) << left << "Vardas" + to_string(s)
             	 << setw(20) << left << "Pavarde" + to_string(s)
             	 << setw(18) << left << fixed << setprecision(2) << generate_random_mark(skaiciai) << endl;
		skaiciai.clear();
	}
    auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> diff = end - start;
    cout << "Failas uzdarytas." << endl;
	cout << "Failo su " + to_string(kiek) + " studentu/-ais kurimas uztruko: " << diff.count() << " s\n";
	return kiek;
}
void readFromFile(vector<studentas>& Eil, int kiek){
    int student_counter = 0;
	ifstream fileRead;
	string pavadinimas = "Studentai_" + to_string(kiek) + ".txt";
	string buff;
	fileRead.open(pavadinimas);
	if (fileRead.is_open()) {

        auto start = chrono::high_resolution_clock::now();
		auto st = start;
		getline(fileRead >> ws, buff);
		while (student_counter < kiek)
		{
			Eil.resize(Eil.size() + 1);
			fileRead >> Eil.at(student_counter).vardas;
			fileRead >> Eil.at(student_counter).pavarde;
			fileRead >> Eil.at(student_counter).galutinis;
			student_counter++;
		}
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double> diff = end - start;
		cout << "Failo su " + to_string(kiek) + " studentu/-ais nuskaitymas uztruko: " << diff.count() << " s\n";
	}
}
int main(){
	vector<int> skaiciai;
	int kiek = generavimas(skaiciai);
	vector<studentas> studentai;
	readFromFile(studentai, kiek);
	vector<studentas> galvociai;
	vector<studentas> vargsiukai;
	int varg = 0;
	int gal = 0;

	auto start = chrono::high_resolution_clock::now();
	auto st = start;
	for (int i = 0; i < kiek; i++) {
		float pazymys = 5.00;
		if (studentai.at(i).galutinis < pazymys) {
			vargsiukai.push_back(studentai.at(i));
			varg++;
		}
	}
	for (int j = 0; j < kiek; j++) {
		float pazimys = 5.00;
		if (studentai.at(j).galutinis >= pazimys) {
			galvociai.push_back(studentai.at(j));
			gal++;
		}
	}
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> diff = end - start;
	cout << "Failo rusiavimas su " + to_string(kiek)+ " studentais i dvi grupes uztruko : " << diff.count() << " s\n";

	string pavadinimas;
	pavadinimas = "Vargsiukai_" + to_string(kiek) + ".txt";
	ofstream varg_failas(pavadinimas);
	varg_failas << setw(20) << left << "Vardas"
                << setw(20) << left << "Pavarde"
                << left << "Galutinis(Vid.)\n";
	auto start1 = chrono::high_resolution_clock::now();
	auto st1 = start1;
	for (int i = 0; i < kiek; i++) {
		float pazymys  = 5.00;
		if (studentai.at(i).galutinis < pazymys ) {
			varg_failas << setw(20) << left <<  studentai.at(i).vardas
                        << setw(20) << left << studentai.at(i).pavarde
                        << setw(18) << left <<  fixed << setprecision(2) << studentai.at(i).galutinis << endl;
		}
		
	}
	auto end1 = chrono::high_resolution_clock::now();
	chrono::duration<double> diff1 = end1 - start1;
	cout << "Failo isvedimas su " + to_string(kiek) + " studentais i Vargsiukus uztruko : " << diff1.count() << " s\n";

	pavadinimas = "Galvociai_" + to_string(kiek) + ".txt";
	ofstream gal_failas(pavadinimas);
	gal_failas << setw(20) << left << "Vardas"
               << setw(20) << left << "Pavarde"
               << left << "Galutinis(Vid.)\n";
	auto start2= chrono::high_resolution_clock::now();
	auto st2 = start2;
	for (int j = 0; j < kiek; j++) {
		float pazymys = 5.00;
		if (studentai.at(j).galutinis >= pazymys) {
			gal_failas << setw(20) << left <<  studentai.at(j).vardas
                       << setw(20) << left << studentai.at(j).pavarde
                       << setw(18) << left <<  fixed << setprecision(2) << studentai.at(j).galutinis << endl;
		}
	}
	auto end2 = chrono::high_resolution_clock::now();
	chrono::duration<double> diff2 = end2 - start2;
	cout << "Failo isvedimas su " + to_string(kiek) + " studentais i Galvocius uztruko : " << diff2.count() << " s\n";	
}