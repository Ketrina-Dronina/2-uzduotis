# 1-uzduotis

Parašykite programą, kuri nuskaito šiuos studentų duomenis:
a) vardą ir pavardę.
b) n atliktų namų darbų (nd) rezultatus (10-balėje sistemoje), o taip pat egzamino (egz) rezultatą.

Tuomet iš šių duomenų, suskaičiuoja galutinį balą (galutinis): Galutinis = 0.4 * vidurkis + 0.6 * egzaminas.

# Užduoties vertinimo kriterijai
Galutinai repozitorijoje turi būti paskelbti 6 releas'ai: v0.1, v0.2, v0.3, v0.4, v0.5 ir v1.0.

Iki versijos (v0.5) svarbiausia, kad Jūsų programos atliktų tai, kas yra prašoma užduotyse. Jeigu yra prašomą kažką panaudoti, pvz. antraštės (header) failus, iššimtis (exceptions) ir pan. - vadinasi juos ir turite panaudoti Jūsų realizacijose. Tačiau tikrai nebus baudžiama už tai, jeigu Jūsų realizacijos nebus labai efektyvios ar "modernios" - tą mes mokysimės ir tobulėsime viso kurso (kaip ir tolesnio gyvenimo) metu - svarbu daryti savarankiškai, tačiau diskutuoti su kolegomis ir dėstytojais drąsiai!

Tuomet natūralus klausimas - o už ką gi bus baudžiama, jeigu yra svarbu tik kad veiktų? Ogi bus baudžiama už tai, jeigu veiks "bug'ovai" ? Pvz.:

Kas nutiktų, jeigu ten kur reikia "rankomis" suvesti duomenis aš vietoj balo įvedu kažkokį kitą simbolį, pvz. "s" raidę? Ar Jūsų programa "neužlūžtų"? Juk natūralu, kad taip neturėtų įvykti, o programa tiesiog turėtų informuotų apie situaciją ir pagal ją priimtų atitinkamą sprendimą.
Kas nutiktų, jeigu neįvesčiau nė vieno namų darbų? Ar nesigautų dalyba iš nulio?
Kas nutiktų, jeigu studentų duomenų failas neegzistuoja? Arba jame toje vietoje kur turi būti namų darbų/egzamino balai, būtų ne skaičius, o koks nors kitas simbolis, pvz. "s" raidė?
Bus vertinamas pačio darbo ir rezultatų apipavidalinimas, t.y.:

Kiekvienai versijai turi būti padarytas atskiras releas'as, o įvairūs efektyvumo tyrimai būtų išsamiai aprašyti ir pakomentuoti Jūsų repozicijos README.md faile.
Galiausiai, bus atsižvelgiama į suplanuotų darbų atlikimo grafiko, t.y. bus baudžiama: už nustatytų terminų nesilaikymą.
