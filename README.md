# 1-uzduotis (v0.5)

Konteinerių testavimas: Išmatuokite patobulintos v0.4 realizacijos veikimo spartą priklausomai nuo naudojamo vieno iš dvejų konteinerių:

std::vector
std::list
T.y., jeigu Jūs turite susikurę struktūrą Studentai (ar kaip jūs ją pavadinote) ir iki v0.4 naudojote std::vector<Studentai>, tai turite ištirti: ar pasikeistų ir kaip pasikeistų programos sparta, jei vietoje std::vector<Studentai> naudotumėte std::list<Studentai>.

Labai svarbu, kadangi tiek failų kūrimas, tiek ir surūšiuotų rezultatų išvedimas į failus nepriklauso nuo naudojamo konteinerio, todėl šioje užduotyje reiktų matuoti tik šiuos programoje atliekamus žingsnius:

duomenų nuskaitymą iš failų;
studentų rūšiąvimą į dvi grupes/kategorijas;
Testavimas atliekamas su tais pačiais failais iš 1000, 10000, 100000, 1000000, 10000000 įrašų. Visi rezultatai turi būti apdoroti ir aprašyti readme.md faile, pateikiant testavimo sistemos parametrus (CPU, RAM, HDD (magnetinis, SSD)). 
