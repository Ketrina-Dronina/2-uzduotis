#ifndef MY_LIB_H_INCLUDED
#define MY_LIB_H_INCLUDED

#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <chrono>
#include <random>
#include <sstream>
#include <fstream>
#include <functional>
#include <list>
#include <deque>

using std::cin;
using std::cout;
using std::deque;
using std::endl;
using std::exception;
using std::fixed;
using std::getline;
using std::ifstream;
using std::istringstream;
using std::left;
using std::list;
using std::ofstream;
using std::remove;
using std::setprecision;
using std::setw;
using std::sort;
using std::string;
using std::stringstream;
using std::swap;
using std::vector;

struct Studentas
{
    string vardas;
    string pavarde;
    double vidurkis;
    int egzaminas;
    double mediana;
    vector<int> pazymiai;
};

#endif