#include "My_lib.h"
#include "Funkcijos.h"
#include "Main_h.h"
#include "Strategija2.cpp"

void filtrasVector(vector<Studentas> &studentai, vector<Studentas> &galvociai, vector<Studentas> &vargsiukai, string file)
{
  vector<Studentas>::iterator it;
  auto start = std::chrono::high_resolution_clock::now();
  auto st = start;
  sort(studentai.begin(), studentai.end(), compare);
  std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start; // Skirtumas (s)
  cout << file << " failo filtravimas uztruko: " << diff.count() << " s\n";
  auto start2 = std::chrono::high_resolution_clock::now();
  auto st2 = start2;
  for (it = studentai.begin(); it != studentai.end(); ++it)
  {
    if (it->vidurkis < 5.00)
    {
      galvociai.assign(studentai.begin(), it);
      vargsiukai.assign(it, studentai.end());
      break;
    }
  }
  std::chrono::duration<double> diff2 = std::chrono::high_resolution_clock::now() - start2; // Skirtumas (s)
  cout << file << " failo filtravimas i dvi grupes uztruko: " << diff2.count() << " s\n";
}

void filtrasDeque(deque<Studentas> &studentai, deque<Studentas> &galvociai, deque<Studentas> &vargsiukai, string file)
{
  deque<Studentas>::iterator it;
  auto start = std::chrono::high_resolution_clock::now();
  auto st = start;
  sort(studentai.begin(), studentai.end(), compare);
  std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start; // Skirtumas (s)
  cout << file << " failo filtravimas uztruko: " << diff.count() << " s\n";
  auto start2 = std::chrono::high_resolution_clock::now();
  auto st2 = start2;
  for (it = studentai.begin(); it != studentai.end(); ++it)
  {
    if (it->vidurkis < 5.00)
    {
      galvociai.assign(studentai.begin(), it);
      vargsiukai.assign(it, studentai.end());
      break;
    }
  }
  std::chrono::duration<double> diff2 = std::chrono::high_resolution_clock::now() - start2; // Skirtumas (s)
  cout << file << " failo filtravimas i dvi grupes uztruko: " << diff2.count() << " s\n";
}

void filtrasList(list<Studentas> &studentai, list<Studentas> &galvociai, list<Studentas> &vargsiukai, string file)
{
  list<Studentas>::iterator it;
  auto start = std::chrono::high_resolution_clock::now();
  auto st = start;
  studentai.sort(compare);
  std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start; // Skirtumas (s)
  cout << file << " failo filtravimas uztruko: " << diff.count() << " s\n";
  auto start2 = std::chrono::high_resolution_clock::now();
  auto st2 = start2;
  for (it = studentai.begin(); it != studentai.end(); ++it)
  {
    if (it->vidurkis < 5.00)
    {
      galvociai.assign(studentai.begin(), it);
      vargsiukai.assign(it, studentai.end());
      break;
    }
  }
  std::chrono::duration<double> diff2 = std::chrono::high_resolution_clock::now() - start2; // Skirtumas (s)
  cout << file << " failo filtravimas i dvi grupes uztruko :" << diff2.count() << " s\n";
}

void benchmark(int pasirinkimas, int strategija)
{
  string file;
  file = "studentai10000";
  if (strategija == 1)
  {
    if (pasirinkimas == 1)
    {
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
        cout << "Programos veikimo trukme: " << diff.count() << endl;
        cout << "" << endl;
      }
    }
    else if (pasirinkimas == 2)
    {
      deque<Studentas> studentai;
      deque<Studentas> galvociai;
      deque<Studentas> vargsiukai;
      for (int i = 0; i < 5; i++)
      {
        auto start = std::chrono::high_resolution_clock::now();
        auto st = start;
        BenchmarkIvedimas(studentai, file);
        filtrasDeque(studentai, galvociai, vargsiukai, file);
        FiltroIsvedimas(galvociai, vargsiukai, file);
        file = file + "0";
        if (i != 4)
        {
          studentai.clear();
          galvociai.clear();
          vargsiukai.clear();
        }
        std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
        cout << "Programos veikimo trukme: " << diff.count() << endl;
        cout << "" << endl;
      }
    }
    else
    {
      list<Studentas> studentai;
      list<Studentas> galvociai;
      list<Studentas> vargsiukai;
      for (int i = 0; i < 5; i++)
      {
        auto start = std::chrono::high_resolution_clock::now();
        auto st = start;
        BenchmarkIvedimas(studentai, file);
        filtrasList(studentai, galvociai, vargsiukai, file);
        ListIsvedimas(galvociai, vargsiukai, file);
        file = file + "0";
        if (i != 4)
        {
          studentai.clear();
          galvociai.clear();
          vargsiukai.clear();
        }
        std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
        cout << "Programos veikimo trukme: " << diff.count() << " s" << endl;
        cout << "" << endl;
      }
    }
  }
  else
  {
    if (pasirinkimas == 1)
    {
      vector<Studentas> studentai;
      vector<Studentas> vargsiukai;
      for (int i = 0; i < 5; i++)
      {
        auto start = std::chrono::high_resolution_clock::now();
        auto st = start;
        BenchmarkIvedimas(studentai, file);
        filtrasVectorStrategija2(studentai, vargsiukai, file);
        FiltroIsvedimas(studentai, vargsiukai, file);
        file = file + "0";
        if (i != 4)
        {
          studentai.clear();
          vargsiukai.clear();
        }
        std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
        cout << "Programos veikimo trukme: " << diff.count() << endl;
        cout << "" << endl;
      }
    }
    else if (pasirinkimas == 2)
    {
      deque<Studentas> studentai;
      deque<Studentas> vargsiukai;
      for (int i = 0; i < 5; i++)
      {
        auto start = std::chrono::high_resolution_clock::now();
        auto st = start;
        BenchmarkIvedimas(studentai, file);
        filtrasDequeStrategija2(studentai, vargsiukai, file);
        FiltroIsvedimas(studentai, vargsiukai, file);
        file = file + "0";
        if (i != 4)
        {
          studentai.clear();
          vargsiukai.clear();
        }
        std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
        cout << "Programos veikimo trukme: " << diff.count() << endl;
        cout << "" << endl;
      }
    }
    else
    {
      list<Studentas> studentai;
      list<Studentas> vargsiukai;
      for (int i = 0; i < 5; i++)
      {
        auto start = std::chrono::high_resolution_clock::now();
        auto st = start;
        BenchmarkIvedimas(studentai, file);
        filtrasListStrategija2(studentai, vargsiukai, file);
        ListIsvedimas(studentai, vargsiukai, file);
        file = file + "0";
        if (i != 4)
        {
          studentai.clear();
          vargsiukai.clear();
        }
        std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
        cout << "Programos veikimo trukme: " << diff.count() << " s" << endl;
        cout << "" << endl;
      }
    }
  }
}