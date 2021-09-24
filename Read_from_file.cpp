#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <time.h>
#include <numeric>
#include <fstream>
#include <sstream>
using namespace std;
using std::cout;
using std::cin;
using std::string;
using std::setw;
using std::endl;
using std::setprecision;
using std::left;
using std::sort;
using std::vector;
using std::accumulate;
using std::fixed;
using std::ifstream;
using std::getline;
using std::stringstream;

struct studentas
{
    string vardas, pavarde;
    int nd_kiek;
    vector <float> nd;
    float egz;
    float galutinis_vid, galutinis_med;
};
bool has_digit(string s)
{
    return (s.find_first_of("0123456789") != string::npos);
}
float mediana(vector <float> pazymiai)
{
    float median;
    int n = pazymiai.size();
    sort(pazymiai.begin(), pazymiai.end());
    if (n % 2 == 0) median = (pazymiai[n / 2] + pazymiai[n / 2 + 1]) / 2.0;
    else median = pazymiai[n / 2];
    return median;
}
bool compare_alphabet(studentas a, studentas b)
{
    if (a.pavarde != b.pavarde) return a.pavarde < b.pavarde;
    else return a.vardas < b.vardas;
}
void student_print(vector<studentas> grupe, string type)
{
    //sort(grupe.begin(), grupe.end(), compare_alphabet);
    ofstream output;
    output.open("Rezultatai.txt");
    output << "\n";
    output << "----------------------------------------------------------------------------------------------\n";
    output << "------------------***@mif.vu.lt " << setw(60) << "Prisijungta prie sistemos\n";
    output << "Galutiniu pazymiu skaiciuoklis\n";
    output << "--------------------------------------------------------------------------\n";
    output << setw(20) << left << "Vardas"
         << setw(20) << left << "Pavarde"
         << setw(18) << left << "Galutinis(Vid.) /"
         << left << "Galutinis(Med.)\n"
         << "--------------------------------------------------------------------------\n";
    for (int i = 0; i < grupe.size(); i++)
    {
        output << setw(20) << left << grupe[i].vardas
            << setw(20) << left << grupe[i].pavarde
            << setw(18) << left << fixed << setprecision(2) << grupe[i].galutinis_vid;
        output << mediana(grupe[i].nd);
        output << "\n\n";
    }
   
}
int main()
{
    srand(time(NULL));
    float vid, med;
    string input_type, galutinis_type, read_type;
    studentas temp_student;
    vector <studentas> grupe;

    cout << "--------------------------------------------------------------------------\n";
    cout << "***@mif.vu.lt " << setw(60) << "Prisijungta prie sistemos\n";
    cout << "Galutiniu pazymiu skaiciuoklis\n";
    cout << "--------------------------------------------------------------------------\n";

    do
    {
        cout << "Norint, jog studentu duomenys butu nuskaityti is failo - IVESKITE F. Norite suvesti duomenis patys? - IVESKITE R : ";
        cin >> read_type;
        if (read_type != "F" && read_type != "f" && read_type != "R" && read_type != "r") { cout << "\n---Pakartokite ivedima, pastebimas netinkamas simbolis\n"; }
    } while (read_type != "F" && read_type != "f" && read_type != "R" && read_type != "r");

    if (read_type == "F" || read_type == "f")
    {
        int rows = 0, cols = 0;
        float temp_paz;
        string eil, item;
        ifstream open_f("studentai10000.txt");
        if (open_f.fail()) { cout << "Nepavyko atidaryti failo."; return 0; } else { cout << "-\n"; }
        while (open_f)
        {
            if (!open_f.eof())
            {
                getline(open_f, eil);
                rows++;
                if (rows == 1) { stringstream ss(eil); while (ss >> item) cols++; }
                open_f >> temp_student.vardas >> temp_student.pavarde;
                temp_student.nd.reserve(cols - 3);
                for (int j = 0; j < cols - 3; j++)
                {
                    open_f >> temp_paz;
                    if (temp_paz < 1 || temp_paz > 10) { cout << "\n---Pakartokite ivedima, pastebimas netinkamas simbolis\n"; return 0; }
                    else temp_student.nd.push_back(temp_paz);
                }
                open_f >> temp_student.egz;
                vid = accumulate(temp_student.nd.begin(), temp_student.nd.end(), 0.0) / temp_student.nd.size();
                temp_student.galutinis_vid = 0.4 * vid + 0.6 * temp_student.egz;
                med = mediana(temp_student.nd);
                temp_student.galutinis_med = 0.4 * med + 0.6 * temp_student.egz;
                grupe.push_back(temp_student);
                temp_student.nd.clear();

            }
            else break;
        }

        open_f.close();

    }
    if (read_type == "R" || read_type == "r")
    {
        int n, x;
        float laik_paz;
        cout << "Iveskite studentu skaiciu: ";
        cin >> n;
        while (n < 0) { cout << "\n---Pakartokite ivedima, pastebimas netinkamas simbolis\n"; cin >> n; }
        grupe.reserve(n);

        do
        {
            cout << "Norint, jog studentu pazymiai butu suvesti automatiskai - IVESKITE A. Norite suvesti duomenis patys? - IVESKITE R : ";
            cin >> input_type;
            if (input_type != "a" && input_type != "A" && input_type != "r" && input_type != "R") { cout << "\n---Pakartokite ivedima, pastebimas netinkamas simbolis\n"; }
        } while (input_type != "a" && input_type != "A" && input_type != "r" && input_type != "R");

        for (int i = 0; i < n; i++)
        {
            cout << "\nIveskite " << i + 1 << " studento duomenis: ";
            do
            {
                cout << "\nStudento Vardas ir Pavarde: ";
                cin >> temp_student.vardas >> temp_student.pavarde;
                if (temp_student.vardas.length() < 0 || temp_student.pavarde.length() < 0 || temp_student.vardas.length() > 25 || temp_student.pavarde.length() > 25 || has_digit(temp_student.vardas) || has_digit(temp_student.pavarde))
                { cout << "\n---Pakartokite ivedima, pastebimas netinkamas simbolis\n"; }
            } while (temp_student.vardas.length() < 0 || temp_student.pavarde.length() < 0 || temp_student.vardas.length() > 25 || temp_student.pavarde.length() > 25 || has_digit(temp_student.vardas) || has_digit(temp_student.pavarde));
        
            if (input_type == "R" || input_type == "r") //suvedimas ranka
            {
                do
                {
                    cin.clear();
                    cin.ignore();
                    cout << "Gautas egzamino rezultatas: ";
                    cin >> temp_student.egz;
                    if (temp_student.egz < 0 || temp_student.egz > 10 || !cin) { cout << "\n---Pakartokite ivedima is naujo, pastebimas netinkamas simbolis\n"; }
                } while (temp_student.egz < 0 || temp_student.egz > 10 || !cin);
                cout << "Studento pazymiai uz atliktus namu darbus (kai baigsite, iveskite -1): ";
                int counter = 0;
                do {
                    cin >> laik_paz;
                    temp_student.nd.push_back(laik_paz);
                    if (temp_student.nd.at(counter) != -1)
                    {
                        if (!(cin >> temp_student.nd.at(counter)))
                        {
                            cin.clear();
                            cin.ignore();
                            cout << "\n---Pakartokite ivedima is naujo, pastebimas netinkamas simbolis\n";
                            cout << "Studento pazymiai uz atliktus namu darbus (kai baigsite, iveskite -1): ";
                        }
                        else
                        temp_student.galutinis_vid = temp_student.galutinis_vid + temp_student.nd.at(counter);
                    }
                    counter++;
                } while (temp_student.nd.at(counter) != -1);
                counter--;
                vid = accumulate(temp_student.nd.begin(), temp_student.nd.end(), 0.0) / temp_student.nd.size();
                temp_student.galutinis_vid = 0.4 * vid + 0.6 * temp_student.egz;
                med = mediana(temp_student.nd);
                temp_student.galutinis_med = 0.4 * med + 0.6 * temp_student.egz;
                
            }
            else if(input_type == "A"|| input_type == "a")
            {
                cout << "Kiek nd pazymiu studentai turi? : ";
                cin >> x;

                temp_student.nd.reserve(x);
                for (int j = 0; j < x; j++)
                {
                    temp_student.nd.push_back(rand() % 10 + 1);
                }
                temp_student.egz = rand() % 10 + 1;
                vid = accumulate(temp_student.nd.begin(), temp_student.nd.end(), 0.0) / temp_student.nd.size();
                temp_student.galutinis_vid = 0.4 * vid + 0.6 * temp_student.egz;
                med = mediana(temp_student.nd);
                temp_student.galutinis_med = 0.4 * med + 0.6 * temp_student.egz;
            }
        }
    }
    student_print(grupe, galutinis_type);
}
