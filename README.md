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

## Programos veikimo laikai:

### Failų generavimas:
| Failo dydis (studentų sk., namų darbų sk.) | laikas (s) |
|--------------------------------------------|------------|
| 1000, 10                                   | 0.00       |
| 10000, 10                                  | 0.04       |
| 100000, 10                                 | 0.32       |
| 1000000, 10                                | 3.28       |
| 10000000, 10                               | 41.58      |

### Studentų duomenų apdorojimas naudojant vector konteinerį:
| Failo dydis (studentų sk., namų darbų sk.) | Nuskaitymo iš failo laikas (s) | Studentų išrikiavimo laikas (s) | Studentų suskirstymas į 2 grupes laikas (s) | Gerų studentų (galutinis >= 5) išvedimo į failą laikas (s) | Blogų studentų (galutinis < 5) išvedimo į failą laikas (s) | Visos programos laikas (s) |
|--------------------------------------------|--------------------------------|---------------------------------|---------------------------------------------|-------------------------------------------------------------|-------------------------------------------------------------|----------------------------|
| 1000, 10                                   | 0.03                           | 0                               | 0                                           | 0                                                           | 0                                                           | 0.03                      |
| 10000, 10                                  | 0.052                          | 0.003                           | 0.001                                       | 0.011                                                       | 0.006                                                       | 0.073                      |
| 100000, 10                                 | 0.246                          | 0.023                           | 0.013                                       | 0.039                                                       | 0.034                                                       | 0.355                      |
| 1000000, 10                                | 2.284                          | 0.268                           | 0.115                                       | 0.395                                                       | 0.389                                                       | 3.451                      |
| 10000000, 10                               | 25.119                         | 3.46                            | 1.249                                       | 4.243                                                       | 3.977                                                       | 38.048                     |
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
## Testuota naudojant:
- Ubuntu 20.04
- g++ 9.4.0
- GNU Make 4.2.1
- CPU Intel(R) Core(TM) i7-6700K CPU @ 4.00GHz
- RAM 2x8GB 2133MHz
- SSD Samsung 860 PRO 512GB

## Versijos:
- [v0.1](https://github.com/rimvydascivilis/OP/releases/tag/v0.1):
- [v0.2](https://github.com/rimvydascivilis/OP/releases/tag/v0.2):
- [v0.3](https://github.com/rimvydascivilis/OP/releases/tag/v0.3):
- [v0.4](https://github.com/rimvydascivilis/OP/releases/tag/v0.4.0):
- [v0.5](https://github.com/rimvydascivilis/OP/releases/tag/v0.5.0):