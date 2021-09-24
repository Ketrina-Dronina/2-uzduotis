#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using std::string;

struct studentas {
    string vardas, pavarde;
    int nd[10]{};
    float egz;
    float galutinis;
};
// skaiciuojam mediana
void skaiciuok_mediana(int nd_pazymiai[])
{
    int counter = 0;
    for (int i = 0; i < 10; i++)
    {
        if (nd_pazymiai[i] > 0) { counter++; }
        if (nd_pazymiai[i] == -1)
        {
            nd_pazymiai[i] = 0;
            break;
        }
    }
    if (counter % 2 == 0) 
    {
        cout << fixed << setprecision(2) << float(((nd_pazymiai[counter / 2 - 1]) + (nd_pazymiai[(counter / 2)])) / 2.0);
    }
    else
    {
        cout << fixed << setprecision(2) << float((nd_pazymiai[(counter / 2)]));
    }
    cout << endl;
}
// sugeneruoja atsitiktini skaiciu periode [1,10]
int generate_random_mark()
{
    srand(time(NULL));
    return rand() % 10 + 1;
}
// automatiskai suveda pazymius ir egz. pazymius (atsitiktinai sugeneruoja)
void automatizuotas_ivedimas(studentas Eil[], int i, int nd_kiekis)
{
    Eil[i].egz = generate_random_mark();
    for (int x = 0; x < nd_kiekis; x++)
    {
        Eil[i].nd[x] = generate_random_mark();
    }
    Eil[i].galutinis = Eil[i].galutinis / nd_kiekis;
    Eil[i].galutinis = Eil[i].galutinis * 0.4 + 0.6 * Eil[i].egz;
}
// vartotojas suveda pazymius ir egzamino pazymi
void suvedimas_ranka(studentas Eil[], int i)
{
    do
    {
        cin.clear();
        cin.ignore();
        cout << "Gautas egzamino rezultatas: ";
        cin >> Eil[i].egz;
        if (Eil[i].egz < 0 || Eil[i].egz > 10 || !cin) { cout << "\n---Pakartokite ivedima is naujo, pastebimas netinkamas simbolis\n"; }
    } while (Eil[i].egz < 0 || Eil[i].egz > 10 || !cin);
    cout << "Studento pazymiai uz atliktus namu darbus (kai baigsite, iveskite -1): ";
    int counter = 0;
    do
    {
        cin >> Eil[i].nd[counter];
        if (Eil[i].nd[counter] != -1 ) 
        {
            if (!(cin >> Eil[i].nd[counter]))
            {
                cin.clear();
                cin.ignore();
                cout << "\n---Pakartokite ivedima is naujo, pastebimas netinkamas simbolis\n";
                cout << "Studento pazymiai uz atliktus namu darbus (kai baigsite, iveskite -1): ";
            }
            else
            Eil[i].galutinis = Eil[i].galutinis + Eil[i].nd[counter];
        }
        counter++;
    } while (Eil[i].nd[counter - 1] != -1);
    counter--;
    Eil[i].galutinis = Eil[i].galutinis / counter;
    Eil[i].galutinis = Eil[i].galutinis * 0.4 + 0.6 * Eil[i].egz;
}
// patikrinam ar vardas ir pavarde neturi skaiciu
bool has_digit(string s)
{
    return (s.find_first_of("0123456789") != string::npos);
}
// vardams ir pavardems suvesti jei vartotojas pasirenka automatizuota suvedima
void duomenu_ivedimas(studentas Eil[], int i)
{
    cout << "\nIveskite " << i + 1 << " studento duomenis: ";
    do {
        cout << "\nStudento Vardas ir Pavarde: ";
        cin >> Eil[i].vardas >> Eil[i].pavarde;
        if (Eil[i].vardas.length() < 0 || Eil[i].pavarde.length() < 0 || Eil[i].vardas.length() > 25 || Eil[i].pavarde.length() > 25 || has_digit(Eil[i].vardas) || has_digit(Eil[i].pavarde))
        { cout << "\n---Pakartokite ivedima, pastebimas netinkamas simbolis\n"; }
    } while (Eil[i].vardas.length() < 0 || Eil[i].pavarde.length() < 0 || Eil[i].vardas.length() > 25 || Eil[i].pavarde.length() > 25 || has_digit(Eil[i].vardas) || has_digit(Eil[i].pavarde));
}
//atspausdinam rezultatus
void spausdink(studentas Eil[], int studentu_sk)
{
    cout << "\n\n";
    cout << setw(20) << left << "Vardas"
         << setw(20) << left << "Pavarde"
         << setw(18) << left << "Galutinis(Vid.) /"
         << left << "Galutinis(Med.)\n"
         << "--------------------------------------------------------------------------\n";
    for (int i = 0; i < studentu_sk; i++)
    {
        cout << setw(20) << left << Eil[i].vardas
            << setw(20) << left << Eil[i].pavarde
            << setw(18) << left << fixed << setprecision(2) << Eil[i].galutinis;
        skaiciuok_mediana(Eil[i].nd);
    }
    cout << "\n\n";
}
// pagrindine funkcija
int main()
{
    int studentu_sk;
    char temp;
    do
    {
        cout << "--------------------------------------------------------------------------\n";
        cout << "***@mif.vu.lt " << setw(60) << "Prisijungta prie sistemos\n";
        cout << "Galutiniu pazymiu skaiciuoklis\n";
        cout << "--------------------------------------------------------------------------\n";
        cout << "Iveskite turimu studentu kieki kurse: ";
        cin >> studentu_sk;
    }
    while (int(studentu_sk) < 0 || int(studentu_sk) > 100);
    studentas Eil[100];
    
    do
    {
        cout << "Norint, jog studentu pazymiai butu suvesti automatiskai - IVESKITE A. Norite suvesti duomenis patys? - IVESKITE R : ";
        cin >> temp;
        if (temp != 'a' && temp != 'A' && temp != 'r' && temp != 'R') { cout << "\n---Pakartokite ivedima, pastebimas netinkamas simbolis\n"; }
    } while (temp != 'a' && temp != 'A' && temp != 'r' && temp != 'R');
    for (int i = 0; i < studentu_sk; i++)
    {
        duomenu_ivedimas(Eil, i); // jei vartotojas pasirinks kad nori automatiskai generuoti nd pazymius
        if (temp == 'r' || temp == 'R') { suvedimas_ranka(Eil, i); }
        else { automatizuotas_ivedimas(Eil, i, 5); }
    }

    spausdink(Eil, studentu_sk);
    return 0;
}