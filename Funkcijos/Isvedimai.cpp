#include "My_lib.h"
#include "Funkcijos.h"
#include "Studentas.h"

template <class X>
void Isvedimas(X &studentas)
{
    vector<Studentas>::iterator it;
    cout << "Norite galutini pazymi vidurkiu(v), mediana(m) ar abiem(bet koks simbolis)" << endl;
    string galutinis = Rtikrinimas();
    if (galutinis == "v" || galutinis == "V")
    {
        cout << left << setw(20) << "Vardas" << left << setw(15) << "Pavarde" << left << setw(15) << "Galutinis(vid.)" << endl;
        cout << "-----------------------------------------------------" << endl;
        for (it = studentas.begin(); it != studentas.end(); ++it)
        {
            cout << left << setw(20) << it->pavarde();
            cout << left << setw(15) << it->vardas();
            cout << left << setw(15) << fixed << setprecision(2) << it->galVidurkis() << endl;
        }
    }
    else if (galutinis == "m")
    {
        cout << left << setw(20) << "Vardas" << left << setw(15) << "Pavarde" << left << setw(15) << "Galutinis(med.)" << endl;
        cout << "-----------------------------------------------------" << endl;
        for (it = studentas.begin(); it != studentas.end(); ++it)
        {
            cout << left << setw(20) << it->pavarde();
            cout << left << setw(15) << it->vardas();
            cout << left << setw(15) << fixed << setprecision(2) << it->galMediana() << endl;
        }
    }
    else
    {
        cout << left << setw(20) << "Vardas" << left << setw(15) << "Pavarde" << left << setw(16) << "Galutinis(vid.) / Galutinis(med.)" << endl;
        cout << "------------------------------------------------------------------" << endl;
        for (it = studentas.begin(); it != studentas.end(); ++it)
        {
            cout << left << setw(20) << it->pavarde();
            cout << left << setw(25) << it->vardas();
            cout << left << setw(10) << fixed << setprecision(2) << it->galVidurkis();
            cout << left << setw(10) << fixed << setprecision(2) << it->galMediana() << endl;
        }
    }
}

template <class X>
void fileIsvedimas(X &studentas)
{
    ofstream pushf("Rezultatai.txt");
    vector<Studentas>::iterator it;

    cout << "Norite galutini pazymi vidurkiu(v), mediana(m) ar abiem(bet koks simbolis)" << endl;
    string galutinis = Rtikrinimas();
    if (galutinis == "v")
    {
        pushf << left << setw(20) << "Vardas" << left << setw(15) << "Pavarde" << left << setw(15) << "Galutinis(vid.)" << endl;
        pushf << "-----------------------------------------------------" << endl;
        for (it = studentas.begin(); it != studentas.end(); ++it)
        {
            pushf << left << setw(20) << it->pavarde();
            pushf << left << setw(15) << it->vardas();
            pushf << left << setw(15) << fixed << setprecision(2) << it->galVidurkis() << endl;
        }
    }
    else if (galutinis == "m")
    {
        pushf << left << setw(20) << "Vardas" << left << setw(15) << "Pavarde" << left << setw(15) << "Galutinis(med.)" << endl;
        pushf << "------------------------------------------------------" << endl;
        for (it = studentas.begin(); it != studentas.end(); ++it)
        {
            pushf << left << setw(20) << it->pavarde();
            pushf << left << setw(15) << it->vardas();
            pushf << left << setw(15) << fixed << setprecision(2) << it->galMediana() << endl;
        }
    }
    else
    {
        pushf << left << setw(20) << "Vardas" << left << setw(15) << "Pavarde" << left << setw(16) << "Galutinis(vid.) / Galutinis(med.)" << endl;
        pushf << "------------------------------------------------------------------" << endl;
        for (it = studentas.begin(); it != studentas.end(); ++it)
        {
            pushf << left << setw(20) << it->pavarde();
            pushf << left << setw(25) << it->vardas();
            pushf << left << setw(10) << fixed << setprecision(2) << it->galVidurkis() << endl;
            pushf << left << setw(10) << fixed << setprecision(2) << it->galMediana() << endl;
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
    for (auto &galvociai : galvociai)
    {
        pushK << left << setw(20) << galvociai.pavarde();
        pushK << left << setw(15) << galvociai.vardas();
        pushK << left << setw(15) << fixed << setprecision(2) << galvociai.galVidurkis() << endl;
    }
    pushK.close();
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start; // Skirtumas (s)
    cout << file << " failo ivedimas i galvocius uztruko: " << diff.count() << " s\n";
    auto start2 = std::chrono::high_resolution_clock::now();
    auto st2 = start2;
    pushN << left << setw(20) << "Vardas" << left << setw(15) << "Pavarde" << left << setw(15) << "Galutinis(vid.)" << endl;
    pushN << "-----------------------------------------------------" << endl;
    for (auto &vargsiukai : vargsiukai)
    {
        pushN << left << setw(20) << vargsiukai.pavarde();
        pushN << left << setw(15) << vargsiukai.vardas();
        pushN << left << setw(15) << fixed << setprecision(2) << vargsiukai.galVidurkis() << endl;
    }
    pushN.close();
    std::chrono::duration<double> diff2 = std::chrono::high_resolution_clock::now() - start2; // Skirtumas (s)
    cout << file << " failo ivedimas i vargsiukus uztruko: " << diff2.count() << " s\n";
}