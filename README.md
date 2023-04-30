# 2023 m. ISI 1k. objektinio programavimo darbas

## Funkcionalumas:
- Galima įvesti studentų duomenis:
    - rankiniu būdu.
    - iš failo.
- Galima sugeneruoti 5 studentų failus su atsitiktiniais duomenimis.
- Programa nuskaito įvestus duomenis:
    - Studento vardą.
    - pavardę.
    - Namų darbų rezulttus.
    - egzamino rezultatą.
- Naudotojas gali pasirinkti, jog vieno studento balai būtu sugeneruoti atsitiktinai.
- Programa suskaičiuoja galutinį balą (0.4 * *namų darbų balas* + 0.6 * *egzamino rezultatas*).
- Namų darbų balą galima apskaičiuoti:
    - Vidurkiu
    - Medianą
- Programa suskirsto studentus į 2 grupes:
    - Geri studentai (galutinis >= 5)
    - Blogi studentai (galutinis < 5)
- Programa išveda rezultatus į 2 failus:
    - `geriStudentai.txt` (galutinis >= 5)
    - `blogiStudentai.txt` (galutinis < 5)

## Programos paleidimas
- Repozitorijos klonavimas `git clone https://github.com/rimvydascivilis/OP.git`
- Direktorijos pakeitimas `cd OP`
- Sukompiliuoti programą `make <Konteinerio tipas>` ([Žiurėkite į Makefile skiltį](#Makefile))
- Programos paleidimas `./build/program`

## Makefile:
- `make vector` sukompliuoja programą naudojant vector konteinerį.
- `make list` sukompliuoja programą naudojant list konteinerį.
- `make deque` sukompliuoja programą naudojant deque konteinerį.
- `make clean` išvalo nereikalingus failus.

## Įvedimo failo pavyzdys:
```
Vardas Pavardė ND1 ND2 ND3 ND4 ND5 Egzaminas
Vardenis Pavardenis 10 9 8 7 6 5
Vardenis1 Pavardenis1 10 9 8 7 6 5
```

## Programos testavimas:

### Failų generavimas:
| Failo dydis (studentų sk., namų darbų sk.) | laikas (s) |
|--------------------------------------------|------------|
| 1000, 10                                   | 0.00       |
| 10000, 10                                  | 0.04       |
| 100000, 10                                 | 0.32       |
| 1000000, 10                                | 3.28       |
| 10000000, 10                               | 41.58      |

### Testavimas su skirtingais konteineriais:

#### Vector konteineris:
| Failo dydis (studentų sk., namų darbų sk.) | Nuskaitymo iš failo laikas (s) | Studentų išrikiavimo laikas (s) | Studentų suskirstymas į 2 grupes laikas (s) |
|--------------------------------------------|--------------------------------|---------------------------------|---------------------------------------------|
| 1000, 10                                   | 0.002                          | 0                               | 0                                           |
| 10000, 10                                  | 0.022                          | 0.001                           | 0.001                                       |
| 100000, 10                                 | 0.216                          | 0.023                           | 0.013                                       |
| 1000000, 10                                | 2.14                           | 0.277                           | 0.129                                       |
| 10000000, 10                               | 24.894                         | 3.916                           | 2.23                                        |

#### List konteineris:
| Failo dydis (studentų sk., namų darbų sk.) | Nuskaitymo iš failo laikas (s) | Studentų išrikiavimo laikas (s) | Studentų suskirstymas į 2 grupes laikas (s) |
|--------------------------------------------|--------------------------------|---------------------------------|---------------------------------------------|
| 1000, 10                                   | 0.002                          | 0                               | 0                                           |
| 10000, 10                                  | 0.024                          | 0                               | 0                                           |
| 100000, 10                                 | 0.218                          | 0.012                           | 0.013                                       |
| 1000000, 10                                | 2.162                          | 0.175                           | 0.07                                        |
| 10000000, 10                               | 22.847                         | 1.632                           | 0.733                                       |

#### Deque konteineris:
| Failo dydis (studentų sk., namų darbų sk.) | Nuskaitymo iš failo laikas (s) | Studentų išrikiavimo laikas (s) | Studentų suskirstymas į 2 grupes laikas (s) |
|--------------------------------------------|--------------------------------|---------------------------------|---------------------------------------------|
| 1000, 10                                   | 0.002                          | 0                               | 0                                           |
| 10000, 10                                  | 0.022                          | 0.002                           | 0.001                                       |
| 100000, 10                                 | 0.217                          | 0.031                           | 0.009                                       |
| 1000000, 10                                | 2.414                          | 0.489                           | 0.09                                        |
| 10000000, 10                               | 22.601                         | 5.214                           | 0.967                                       |

### Studentų skirtymo į 2 grupes testavimas su skirtingais konteineriais:
#### Vector konteineris:
| Failo dydis (studentų sk., namų darbų sk.) | Studentų suskirstymas A strategijos laikas (s) | Studentų suskirstymas B strategijos laikas (s) | Studentų suskirstymas C strategijos laikas (s) | Atminties naudojimas A strategija (mb) | Atminties naudojimas B strategija (mb) | Atminties naudojimas C strategija (mb) |
|--------------------------------------------|------------------------------------------------|------------------------------------------------|------------------------------------------------|----------------------------------------|----------------------------------------|----------------------------------------|
| 1000, 10                                   | 0                                              | 0                                              | 0                                              | 3.8828125                              | 3.7890625                              | 3.9453125                              |
| 10000, 10                                  | 0.002                                          | 0.097                                          | 0.002                                          | 6.94140625                             | 6.328125                               | 7.30078125                             |
| 100000, 10                                 | 0.022                                          | 11.395                                         | 0.03                                           | 39.44921875                            | 33.72265625                            | 42.21484375                            |
| 1000000, 10                                | 0.215                                          | -                                              | 0.369                                          | 301.6875                               | -                                      | 347.734375                             |
| 10000000, 10                               | 2.627                                          | -                                              | 4.181                                          | 2788.0625                              | -                                      | 3210.16796875                          |

#### List konteineris:
| Failo dydis (studentų sk., namų darbų sk.) | Studentų suskirstymas A strategijos laikas (s) | Studentų suskirstymas B strategijos laikas (s) | Studentų suskirstymas C strategijos laikas (s) | Atminties naudojimas A strategija (mb) | Atminties naudojimas B strategija (mb) | Atminties naudojimas C strategija (mb) |
|--------------------------------------------|------------------------------------------------|------------------------------------------------|------------------------------------------------|----------------------------------------|----------------------------------------|----------------------------------------|
| 1000, 10                                   | 0                                              | 0                                              | 0                                              | 3.75                                   | 3.65234375                             | 3.87890625                             |
| 10000, 10                                  | 0                                              | 0                                              | 0.004                                          | 5.58203125                             | 5.5859375                              | 6.859375                               |
| 100000, 10                                 | 0.013                                          | 0.014                                          | 0.046                                          | 26.38671875                            | 26.15625                               | 37.1015625                             |
| 1000000, 10                                | 0.155                                          | 0.15                                           | 0.587                                          | 222.46484375                           | 223.50390625                           | 339.23046875                           |
| 10000000, 10                               | 1.799                                          | 1.424                                          | 6.534                                          | 1919.48828125                          | 1919.671875                            | 3359.640625                            |

#### Deque konteineris:
| Failo dydis (studentų sk., namų darbų sk.) | Studentų suskirstymas A strategijos laikas (s) | Studentų suskirstymas B strategijos laikas (s) | Studentų suskirstymas C strategijos laikas (s) | Atminties naudojimas A strategija (mb) | Atminties naudojimas B strategija (mb) | Atminties naudojimas C strategija (mb) |
|--------------------------------------------|------------------------------------------------|------------------------------------------------|------------------------------------------------|----------------------------------------|----------------------------------------|----------------------------------------|
| 1000, 10                                   | 0                                              | 0.001                                          | 0                                              | 3.765625                               | 3.80078125                             | 3.8359375                              |
| 10000, 10                                  | 0.002                                          | 0.113                                          | 0.001                                          | 5.44921875                             | 5.515625                               | 6.59375                                |
| 100000, 10                                 | 0.014                                          | 16.822                                         | 0.028                                          | 24.3984375                             | 24.38671875                            | 33.65234375                            |
| 1000000, 10                                | 0.164                                          | -                                              | 0.44                                           | 209.51171875                           | -                                      | 307.046875                             |
| 10000000, 10                               | 2.412                                          | -                                              | 5.283                                          | 1838.12890625                          | -                                      | 3021.1640625                           |

## Testuota naudojant:
- Ubuntu 20.04
- g++ 9.4.0
- GNU Make 4.2.1
- CPU Intel(R) Core(TM) i7-6700K CPU @ 4.00GHz
- RAM 2x8GB 2133MHz
- SSD Samsung 860 PRO 512GB

## Versijos:
- [v0.1](https://github.com/rimvydascivilis/OP/releases/tag/v0.1):
    - Studentų duomenų nuskaitymas iš komandinės eilutės ir apskaičiavimas galutinio balo
- [v0.2](https://github.com/rimvydascivilis/OP/releases/tag/v0.2):
    - Studentų duomenų nuskaitymas iš failo ir išvedimas į failą
- [v0.3](https://github.com/rimvydascivilis/OP/releases/tag/v0.3):
    - Kodo refactoring'as
- [v0.4](https://github.com/rimvydascivilis/OP/releases/tag/v0.4.0):
    - failų generavimas
- [v0.5](https://github.com/rimvydascivilis/OP/releases/tag/v0.5.0):
    - Programa perdaryta, kad veiktų su trimis konteineriais: vector, list, deque
    - Konteinerių testavimas:
        - Greičiausias konteineris: deque
        - Antras greičiausias konteineris: list
        - Lėčiausias konteineris: vector
- [v1.0](https://github.com/rimvydascivilis/OP/releases/tag/v1.0.1):
    - Studentų duomenų skaidymas į 2 grupes skirtingais būdais:
        - A strategija: studentai, kurių galutinis balas yra mažesnis už 5, yra perkelti į naują konteinerį *blogiStudentai*, o kurių galutinis balas yra didesnis arba lygus 5, yra perkelti į naują konteinerį *geriStudentai*
        - B strategija: studentai, kurių galutinis balas yra mažesnis už 5, yra ištrinami iš konteinerio
        - C strategija: `std::partition()` funkcija
    - Strategijų testavimas greičio atžvilgiu:
        - Greičiausia strategija: A
        - Antra greičiausia strategija: B
        - Lėčiausia strategija: C
    - Strategijų testavimas atminties atžvilgiu:
        - Strategija, naudojanti mažiausią atminties kiekį: B
        - Strategija, naudojanti vidutinį atminties kiekį: A
        - Strategija, naudojanti daugiausią atminties kiekį: C
