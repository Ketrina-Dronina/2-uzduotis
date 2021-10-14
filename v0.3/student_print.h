#ifndef STUDENT_PRINT_H
#define STUDENT_PRINT_H

#include <vector>
#include <string>

void student_print(vector<studentas> grupe, string type)
{
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
   
};

#endif