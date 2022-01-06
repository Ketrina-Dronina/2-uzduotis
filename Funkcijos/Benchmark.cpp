#include "My_lib.h"
#include "Funkcijos.h"
#include "Main_h.h"
#include "Studentas.h"

void filtrasVector(vector<Studentas> &studentai, vector<Studentas> &galvociai, vector<Studentas> &vargsiukai, string file)
{
  vector<Studentas>::iterator it;
  auto start = std::chrono::high_resolution_clock::now();
  auto st = start;
  sortByVidurkis(studentai);
  std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start; // Skirtumas (s)
  cout << file << " failo filtravimas uztruko: " << diff.count() << " s\n";
  auto start2 = std::chrono::high_resolution_clock::now();
  auto st2 = start2;
  for (it = studentai.begin(); it != studentai.end(); ++it)
  {
    if (it->galVidurkis() < 5.00)
    {
      galvociai.assign(studentai.begin(), it);
      vargsiukai.assign(it, studentai.end());
      break;
    }
  }
  std::chrono::duration<double> diff2 = std::chrono::high_resolution_clock::now() - start2; // Skirtumas (s)
  cout << file << " failo filtravimas i dvi grupes uztruko: " << diff2.count() << " s\n";
}

void benchmark()
{
  string file;
  file = "studentai1000";

  vector<Studentas> studentai;
  vector<Studentas> galvociai;
  vector<Studentas> vargsiukai;
  for (int i = 0; i < 5; i++)
  {
    auto start = std::chrono::high_resolution_clock::now();
    auto st = start;
    BenchmarkIvedimas(studentai, file);
    filtrasVector(studentai, galvociai, vargsiukai, file);
    FiltroIsvedimas(galvociai, vargsiukai, file);
    file = file + "0";
    if (i != 4)
    {
      studentai.clear();
      galvociai.clear();
      vargsiukai.clear();
    }
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    cout << "Programos trukme: " << diff.count() << endl;
    cout << "" << endl;
  }
}
