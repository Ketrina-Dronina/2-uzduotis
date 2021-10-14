#ifndef COMPARE_ALPHABET_H
#define COMPARE_ALPHABET_H

bool compare_alphabet(studentas a, studentas b)
{
    if (a.pavarde != b.pavarde) return a.pavarde < b.pavarde;
    else return a.vardas < b.vardas;
};

#endif