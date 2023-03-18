==================================================
Autor: Mateusz Dyszewski        Krakow, 26.01.2023
==================================================

*Dzialanie:
===========
    Points.x:
        Program wczytuje ze standardowego wejscia instrukcje do wykonania na Obiekcie klasy Points. Klasa Points wewnetrznie implementuje drzewo k-d.
        Jak powinny wygladac instrukcje:
            Pierwsza linijka przyjmuje wymiar przestrzeni = N
            Druga linijka przyjmuje ilosc polecen = k
            Pozostale k linijek moga posiadac ponizsze instrukcje:
                Dodanie punktu x do bazy:
                    R x1 x2 ... xN
                Wyswietlenie punktow struktury drzewa:
                    P
                Znalezienie najblizszego sasiada dla punktu y:
                    N y1 y2 ... yN
                Zapisanie drzewa do pliku :
                    S <sciezka do pliku>
                Wyswietlenie wymiaru drzewa:
                    D
                Wyswietlenie rozmiaru drzewa:
                    H
        Aby wczytac baze punktow z pliku nalezy podac sciezke do niej jako argument przy uruchamianiu programu. Wtedy tez pomijamy etap podawania wymiaru przestrzeni w pierwszej linijce. Pod linkiem (https://www.desmos.com/calculator/p0xvczctyo) stworzylem wykres w kalkulatorze graficznym desmos, przedstawiajacy podzial przestrzeni dla przykladowej bazy zawartej w pliku "przyklad.points", ktora mozemy otworzyc komenda "./Points.x ./przyklad.points". Wykres pomaga rowniez zaprezentowac ze funkcja szukania najblizszego sasiada rzeczywisice dziala.

*Uruchamianie:
===============
    make : 
        Kompiluje wszystkie programy
    ./Points.x:
        Uruchamia skompilowany wczesniej program
    make tar
        Pakuje zawartosc folderu do archiwum tar
    make clean
        Czysci zawartosc folderu