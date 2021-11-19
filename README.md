# 1-uzduotis (v1.0)
Optimizuokite studentų rūšiavimo (dalijimo) į dvi kategorijas realizaciją: t.y. visiems trims konteinerių tipams (vector, deque, list) išmatuokite programos veikimo spartą priklausomai nuo studentų dalijimo į dvi kategorijas strategijos:
- 1 strategija: Bendro studentai konteinerio (vector ir list tipų) skaidymas (rūšiavimas) į du naujus to paties tipo konteinerius: "vargšiukų" ir "kietiakų". Tokiu būdu tas pats studentas yra dvejuose konteineriuose: bendrame studentai ir viename iš suskaidytų (vargšiukai arba kietiakai).
- 2 strategija: Bendro studentų konteinerio (vector ir list) skaidymas (rūšiavimas) panaudojant tik vieną naują konteinerį: "vargšiukai".
# Programos veikimo sparta
![Untitled](https://user-images.githubusercontent.com/91048600/142675212-c75f2737-4167-4c47-84e9-d6129e5c01bb.png)

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
# v0.1
Programa, kuri nuskaito vartotojų įvedamus reikiamus duomenis: a) studento vardą ir pavardę; b) namų darbų ir egzamino rezultatą. Baigus duomenų įvedimą, suskaičiuoja galutinį balą ir j5 pateikia į ekraną dviejų skaičių po kablelio tikslumu.
- Papildyta programa: vietoj vidurkio galutinio balo skaičiavimui būtų galima naudoti ir medianą.
- Papildykite programa: namų darbų skaičius (n) yra nežinomas iš anksto, t.y. tik įvedimo metu vartotojas nusprendžia kuomet jis jau įvedė visų namų darbų rezultatus. Ši dalis realizuota ̨dviem būdais, kur namų darbų rezultatus saugant į: a) tradicinį dinaminį C masyvą. b) std::vector tipo konteinerį.
- Papildykite programa: studento gautieji balai už namų darbus bei egzaminą būtų generuojami atsitiktinai.

![DA](https://user-images.githubusercontent.com/91048600/142658525-4d011c33-9548-4ed4-862d-9df922b633e8.png)
![image](https://user-images.githubusercontent.com/91048600/142658909-a63de670-6610-4892-9d43-229683bb2697.png)
# v0.2
- Papildykite programos versiją (v0.1) taip, kad būtų galima duomenis ne tik įvesti bet ir nuskaityti iš failo.
Reikalavimai output’ui: studentai turi būti surūšiuoti pagal vardus (ar pavardes) ir visi stulpeliai būtų gražiai "išlygiuoti".
![Untitled](https://user-images.githubusercontent.com/91048600/142659449-4611c59e-a7c9-4fbb-97b8-9ae966c58b6e.png)
# v0.3
Programoje naudojamos struct'ūros.
- Funkcijas, naujus duomenų tipus (struct’ūras) perkelkite į antraštinius (angl. header (*.h)) failus, t.y. tokiu būdu turėtumete sukurtame projekte turėti kelis *.cpp failus, kaip ir kelis *.h failus.
- Kur tikslinga, bent minimaliai panaudokite išimčių valdymą (angl. Exception Handling).

![Untitled](https://user-images.githubusercontent.com/91048600/142659971-1a4c82c9-6ade-4d22-92a7-339f51d3e9e0.png)
# v0.4
- Sugeneruoti penkis atsitiktinius studentų sąrašų failus, sudarytus iš: 1 000, 10 000, 100 000, 1 000 000, 10 000 000 įrašų.
- Surusiuokite (padalinkite) studentus į dvi kategorijas: a) Studentai, kurių galutinis balas < 5.0 galėtume vadinti “vargšiukai”, “nuskriaustukai” ir pan. b) Studentai, kurių galutinis balas >= 5.0 galėtume vadinti "kietiakiai", "galvočiai" ir pan.
- Surūšiuotus studentus išveskite į du naujus failus.
- Atlikite programos veikimo greičio (spartos) analizę: a)failų kūrimą; b)duomenų nuskaitymą iš failų; c)studentų rūšiavimą į dvi grupes/kategorijas; d)surūšiuotų studentų išvedimą į du naujus failus.
![Untitled](https://user-images.githubusercontent.com/91048600/142661176-91b168fc-dca9-4dee-95c3-59939f9f2adb.png)
# v0.5
Konteinerių testavimas: Išmatuokite patobulintos v0.4 realizacijos veikimo spartą priklausomai nuo naudojamo vieno iš dvejų konteinerių: std::vector, std::list.
- Duomenų nuskaitymas iš failų; studentų rūšiąvimą į dvi grupes/kategorijas; Testavimas atliekamas su tais pačiais failais iš 1000, 10000, 100000, 1000000, 10000000 įrašų. Visi rezultatai turi būti apdoroti ir aprašyti readme.md faile, pateikiant testavimo sistemos parametrus (CPU, RAM, HDD (magnetinis, SSD)).
![Untitled](https://user-images.githubusercontent.com/91048600/142664648-4238cb96-5d07-40cd-a331-7a8191497db4.png)
# v1.0
Optimizuokite studentų rūšiavimo (dalijimo) į dvi kategorijas realizaciją: t.y. visiems trims konteinerių tipams (vector, deque, list) išmatuokite programos veikimo spartą priklausomai nuo studentų dalijimo į dvi kategorijas strategijos:
- 1 strategija: Bendro studentai konteinerio (vector ir list tipų) skaidymas (rūšiavimas) į du naujus to paties tipo konteinerius: "vargšiukų" ir "kietiakų". Tokiu būdu tas pats studentas yra dvejuose konteineriuose: bendrame studentai ir viename iš suskaidytų (vargšiukai arba kietiakai).
- 2 strategija: Bendro studentų konteinerio (vector ir list) skaidymas (rūšiavimas) panaudojant tik vieną naują konteinerį: "vargšiukai".
