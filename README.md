# 2023 m. ISI 1k. objektinio programavimo darbas

## Funkcionalumas:
- galima įvesti studentų duomenis:
    - rankiniu būdu.
    - iš failo.
- Programa nuskaito įvestus duomenis:
    - Studento vardą.
    - pavardę.
    - Namų darbų rezulttus.
    - egzamino rezultatą.
- Naudotojas gali pasirinkti, jog balai būtu sugeneruoti atsitiktinai.
- Programa suskaičiuoja galutinį balą (0.4 * *namų darbų balas* + 0.6 * *egzamino rezultatas*).
- Namų darbų balą galima apskaičiuoti:
    - Vidurkiu
    - Medianą

## Makefile:
- `make run` paleidžia programą
- `make main` sukompliuoja programą
- `make funtions.o` sukompliuoja funkcijų failą
- `make clean` išvalo nereikalingus failus.

## Įvedimo failo pavyzdys:
```
Vardas Pavardė ND1 ND2 ND3 ND4 ND5 Egzaminas
Vardenis Pavardenis 10 9 8 7 6 5
Vardenis1 Pavardenis1 10 9 8 7 6 5
```

## Failai:
- `main.cpp` - pagrindinis failas.
- `MyLib.h` - bibliotekos header failas.
- `funkcijos.cpp` - funkcijų failas.
- `funkcijos.h` - funkcijų header failas.
- `Makefile` - makefile failas.

## Programos veikimo laikas:

### Failų generavimas:
| Failo dydis (studentų sk., namų darbų sk.) | laikas (s) |
|--------------------------------------------|------------|
| 1000, 10                                   | 0.00       |
| 10000, 10                                  | 0.04       |
| 100000, 10                                 | 0.32       |
| 1000000, 10                                | 3.28       |
| 10000000, 10                               | 41.58      |

### Studentų duomenų apdorojimas:
| Failo dydis (studentų sk., namų darbų sk.) | Nuskaitymo iš failo laikas (s) | Studentų išrikiavimo laikas (s) | Studentų suskirstymas į 2 grupes laikas (s) | Gerų studentų (galutinis >= 5) išvedimo į failą laikas (s) | Blogų studentų (galutinis < 5) išvedimo į failą laikas (s) | Visos programos laikas (s) |
|--------------------------------------------|--------------------------------|---------------------------------|---------------------------------------------|-------------------------------------------------------------|-------------------------------------------------------------|----------------------------|
| 1000, 10                                   | 0.03                           | 0                               | 0                                           | 0                                                           | 0                                                           | 0.03                      |
| 10000, 10                                  | 0.052                          | 0.003                           | 0.001                                       | 0.011                                                       | 0.006                                                       | 0.073                      |
| 100000, 10                                 | 0.246                          | 0.023                           | 0.013                                       | 0.039                                                       | 0.034                                                       | 0.355                      |
| 1000000, 10                                | 2.284                          | 0.268                           | 0.115                                       | 0.395                                                       | 0.389                                                       | 3.451                      |
| 10000000, 10                               | 25.119                         | 3.46                            | 1.249                                       | 4.243                                                       | 3.977                                                       | 38.048                     |
## Testuota naudojant:
- Ubuntu 20.04
- g++ 9.4.0
- GNU Make 4.2.1
