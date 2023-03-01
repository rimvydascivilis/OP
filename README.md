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

## Įvedimo failas pavyzdys:
```
Vardas Pavardė ND1 ND2 ND3 ND4 ND5 Egzaminas
Vardenis Pavardenis 10 9 8 7 6 5
Vardenis1 Pavardenis1 10 9 8 7 6 5
```

## Testuota naudojant:
- Ubuntu 20.04
- g++ 9.4.0

## Makefile:
- `make main` paleidžia programą
- `make clean` išvalo nereikalingus failus.