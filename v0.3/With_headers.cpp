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

#include "studentas.h"
#include "has_digit.h"
#include "mediana.h"
#include "compare_alphabet.h"
#include "student_print.h"

int main()
{
    srand(time(NULL));
    float vid, med;
    string input_type, galutinis_type, read_type;
    studentas temp_student;
    vector <studentas> grupe;

    std::cout << "--------------------------------------------------------------------------\n";
    std::cout << "***@mif.vu.lt " << std::setw(60) << "Prisijungta prie sistemos\n";
    std::cout << "Galutiniu pazymiu skaiciuoklis\n";
    std::cout << "--------------------------------------------------------------------------\n";

    std::cout << "Norint, jog studentu duomenys butu nuskaityti is failo - IVESKITE F. Norite suvesti duomenis patys? - IVESKITE R : ";
    std::cin >> read_type;
    do
    {
        try{
            if (read_type != "F" && read_type != "f" && read_type != "R" && read_type != "r")
            throw std::invalid_argument("\n---Pakartokite ivedima, pastebimas netinkamas simbolis\n");
        }
        catch (std::invalid_argument& e) {
            std::cout << e.what();
            std::cin.clear();
            std::cout << "IVESKITE F arba R: ";
            std::cin >> read_type;
        }  
    } while (read_type != "F" && read_type != "f" && read_type != "R" && read_type != "r");

    if (read_type == "F" || read_type == "f")
    {
        int rows = 0, cols = 0;
        float temp_paz;
        string eil, item;
        std::ifstream open_f("studentai10000.txt");
        try
        {
            if (open_f.fail())
            throw std::runtime_error("Nepavyko atidaryti failo.");
        }
        catch(const std::runtime_error& e)
        {
            std::cout << e.what();
            exit(1);
        }
        while (open_f)
        {
            if (!open_f.eof())
            {
                getline(open_f, eil);
                rows++;
                if (rows == 1) { std::stringstream ss(eil); while (ss >> item) cols++; }
                open_f >> temp_student.vardas >> temp_student.pavarde;
                temp_student.nd.reserve(cols - 3);
                for (int j = 0; j < cols - 3; j++)
                {
                    open_f >> temp_paz;
                    try
                    {
                        if (temp_paz < 1 || temp_paz > 10)
                        throw std::runtime_error("\n---Pakartokite ivedima, pastebimas netinkamas simbolis\n");
                    }
                    catch(const std::runtime_error& e)
                    {
                        std::cout << e.what();
                        exit(1);
                    }
                    
                    temp_student.nd.push_back(temp_paz);
                }
                open_f >> temp_student.egz;
                try
                {
                    if (temp_student.egz < 1 || temp_student.egz > 10)
                    throw std::runtime_error("\n---Pakartokite ivedima, pastebimas netinkamas simbolis\n");
                }
                catch(const std::runtime_error& e)
                {
                    std::cout << e.what();
                    exit(1);
                }
                
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
        std::cout << "Iveskite studentu skaiciu: ";
        std::cin >> n;
        do
        {
            try
            {
                if(n < 0)
                throw std::invalid_argument("\n---Pakartokite ivedima, pastebimas netinkamas simbolis\n");
            }
            catch(const std::invalid_argument& e)
            {
                std::cout << e.what();
                std::cin.clear();
                std::cout << "Iveskite studentu skaiciu: ";
                std::cin >> n;
            }
            
        } while (n < 0);

        std::cout << "Norint, jog studentu pazymiai butu suvesti automatiskai - IVESKITE A. Norite suvesti duomenis patys? - IVESKITE R : ";
        std::cin >> input_type;
        do
        {
            try
            {
                if (input_type != "a" && input_type != "A" && input_type != "r" && input_type != "R")
                throw std::invalid_argument("\n---Pakartokite ivedima, pastebimas netinkamas simbolis\n");
            }
            catch(const std::invalid_argument& e)
            {
                std::cout << e.what();
                std::cin.clear();
                std::cout << "IVESKITE A arba R: ";
                std::cin >> input_type;
            } 
        } while (input_type != "a" && input_type != "A" && input_type != "r" && input_type != "R");

        for (int i = 0; i < n; i++)
        {
            std::cout << "\nIveskite " << i + 1 << " studento duomenis: ";
            std::cout << "\nStudento Vardas ir Pavarde: ";
            std::cin >> temp_student.vardas >> temp_student.pavarde;
            do
            {
                try
                {
                    if (temp_student.vardas.length() < 0 || temp_student.pavarde.length() < 0 || temp_student.vardas.length() > 25 || temp_student.pavarde.length() > 25 || has_digit(temp_student.vardas) || has_digit(temp_student.pavarde))
                    throw std::invalid_argument("\n---Pakartokite ivedima, pastebimas netinkamas simbolis\n");
                }
                catch(const std::invalid_argument& e)
                {
                    std::cout << e.what();
                    std::cin.clear();
                    std::cout << "\nStudento Vardas ir Pavarde: ";
                    std::cin >> temp_student.vardas >> temp_student.pavarde;
                }
            } while (temp_student.vardas.length() < 0 || temp_student.pavarde.length() < 0 || temp_student.vardas.length() > 25 || temp_student.pavarde.length() > 25 || has_digit(temp_student.vardas) || has_digit(temp_student.pavarde));
        
            if (input_type == "R" || input_type == "r") //suvedimas ranka
            {
                std::cout << "Gautas egzamino rezultatas: ";
                std::cin >> temp_student.egz;
                do
                {
                    try
                    {
                        if (temp_student.egz < 0 || temp_student.egz > 10 || !std::cin)
                        throw std::invalid_argument("\n---Pakartokite ivedima, pastebimas netinkamas simbolis\n");
                    }
                    catch(const std::invalid_argument& e)
                    {
                        std::cout << e.what();
                        std::cin.clear();
                        std::cout << "Gautas egzamino rezultatas: ";
                        std::cin >> temp_student.egz;
                    }
                } while (temp_student.egz < 0 || temp_student.egz > 10 || !std::cin);
                
                std::cout << "Studento pazymiai uz atliktus namu darbus (kai baigsite, iveskite -1): ";
                int counter = 0;
                
                do
                {
                    std::cin >> laik_paz;
                    temp_student.nd.push_back(laik_paz);
                    if (temp_student.nd.at(counter) != -1)
                    {
                        do
                        {
                            try
                            {
                                if (!(std::cin >> temp_student.nd.at(counter)))
                                throw std::invalid_argument("\n---Pakartokite ivedima, pastebimas netinkamas simbolis\n");
                            }
                            catch(const std::invalid_argument& e)
                            {
                                std::cout << e.what();
                                std::cin.clear();
                                std::cout << "Studento pazymiai uz atliktus namu darbus (kai baigsite, iveskite -1): ";
                                std::cin >> laik_paz;
                            }
                            
                        } while (temp_student.nd.at(counter) != -1);

                    }
                    else
                    {
                        do
                        {
                            temp_student.galutinis_vid = temp_student.galutinis_vid + temp_student.nd.at(counter);
                            counter++;
                        } while (temp_student.nd.at(counter) != -1);
                        
                        
                    }
                } while (temp_student.nd.at(counter) != -1);
                counter--;
                vid = accumulate(temp_student.nd.begin(), temp_student.nd.end(), 0.0) / temp_student.nd.size();
                temp_student.galutinis_vid = 0.4 * vid + 0.6 * temp_student.egz;
                med = mediana(temp_student.nd);
                temp_student.galutinis_med = 0.4 * med + 0.6 * temp_student.egz;
                grupe.push_back(temp_student);
                temp_student.nd.clear();
                
            }
            if(input_type == "A"|| input_type == "a")
            {
                do
                {
                    std::cout << "Kiek nd pazymiu studentai turi? : ";
                    std::cin >> x;
                    try
                    {
                        if (x <= 0)
                        throw std::invalid_argument("\n---Pakartokite ivedima, pastebimas netinkamas simbolis\n");

                    }
                    catch(const std::invalid_argument& e)
                    {
                        std::cout << e.what() << endl;
                        std::cin.clear();
                        std::cout << "Kiek nd pazymiu studentai turi? : ";
                        std::cin >> x;
                    } 
                } while (x <= 0);
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
                grupe.push_back(temp_student);
                temp_student.nd.clear();
            }
        }
    }
    student_print(grupe, galutinis_type);
    cin.get();
}