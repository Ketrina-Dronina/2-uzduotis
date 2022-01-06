# 2-uzduotis (v2.0). Naujų tipų kūrimas ir jų naudojimas
Pratęskite (tuo pačiu ir patobulinkite) 1-osios užduoties Jūsų turimą programos realizaciją (versiją v1.0) taip, kad vietoje Jūsų sukurtos Studentas (StudentoInfo) ar dar kitaip pavadintos Studentų structūros jos pagrindu sukurkite class'ę, vadovaujantis per teorijos paskaitas nurodomomis "geromis praktikomis".
# Įdiegimo ir naudojimo instrukcija
Įdiegimas (1 būdas)

Windows naudotojams:
mingw32-make -f MakeFileWin
MacOS, Linux ar kitos UNIX sistemos naudotojams:
make -f MakeFile

Įdiegimas (2 būdas)

- Iš skilties "releases" pasirinkti norimą programos versiją ir atsisiųsti
- Atsisiųstą kodą sukompiliuoti per komandinę eilutę (CMD) arba naudojamu IDE (g++ -o programa main.cpp functions.cpp)
- Paleisti gautą vykdomąjį failą (.exe)
(./programa
Arba tiesiog atidaryti .exe failą tame aplanke kur atsisiuntėte programą)

Naudojimas

- Paleidus failą iš pradžių pasirinkti ar norima sugeneruoti duomenis automatiškai ir nuskaityti ar įvesti duomenis pačiam, nuskaityti iš failo.
- Jei pasirinkta generuoti ir nuskaityti automatiškai, galimas pasirinkimas ar generuoti naują failą ar pereiti prie failo nuskaitymo.
- Jei pasirinkta sugeneruoti naujus failus pasirenkame kokio dydžio failą generuoti.
- Jei pasirenkama negeneruoti failo pereinama prie nuskaitymo, pasirenkame į kokio tipo konteinerį nuskaityti failą, tuomet pasirenkame kokio dydžio failą nuskaityti.
- Pasirinkus įvesti pačiam, įvesti studento vardą ir pavardę.
- Toliau atsakyti į programos užklausas įvedant t- TAIP, n- NE.
- Pasirinkti ar norime, jog galutinis pažymis būtų skaičiuojamas kaip mediana - t, jei norime jog būtų išvestas vidurkis - n. 

# Versijos
# v1.1
Ankstesnės atliktos užduoties pagrindu susikurti naują repoziciją, t.y., visa git istorija iki v1.0 turi išlikti.

Palyginkite abiejų Jūsų programų: naudojančios struct iš ankstesniojo darbo ir naudojančio class tipo Studentus iš dabartinės realizacijos spartą (veikimo laiką), naudojant vieną fiksuotą konteinerį, pvz. vektorių, pačią greičiausią dalijimo strategiją ir 100000 ir 1000000 dydžio failus. Gautus rezultatus aprašykite README.md faile.

Atlikite eksperimentinę analizę priklausomai nuo kompiliatoriaus optimizavimo lygio, nurodomo per flag'us: O1, O2, O3 ir papildykite README.md failą gautais rezultatais su optimizavimo flag'ais.

# Struct prieš Class naudojant vektorius programos veikimo sparta pagal 1 strategija
![Untitled](https://user-images.githubusercontent.com/91048600/144633878-9e8abe3d-bea7-4900-8b7d-3e1db84b7e80.png)

# v1.2

Realizuokite visus reikiamus (realizuokitė "Rule of three") ir tinkamus (turinčius prasmę) ir tik šiuos operatorius Jūsų turimai Studentas klasei.

# Class prieš Class Rule of three naudojant vektorius programos veikimo sparta pagal 1 strategija
![Untitled](https://user-images.githubusercontent.com/91048600/144647374-b40d3021-e232-4ab7-aa1d-e5bda780c143.png)

# v1.5

Sukurta bazinė klasė žmogus, kuri laiko vardą ir pavardę.

# Programos veikimo sparta

                      1000    10000   100000   1000000   10000000
      Nuskaitymas   0,004s   0,042s   0,453s    3,311s     51,88s
      Filtravimas       0s   0,015s   0,176s    2,241s     33,19s
      Rūšiavimas        0s   0,001s   0,021s    0,180s     3,040s

# v2.0

Sukurkite dokumentaciją panaudojant Doxygen. Įkelkite dokumentaciją (kaip atskirą doxygen HTML katalogą) į repoziciją.
Pridėti catch testai ir setup folderis.
