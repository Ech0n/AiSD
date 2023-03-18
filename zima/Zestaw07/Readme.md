==================================================
Autor: Mateusz Dyszewski        Krakow, 11.01.2023
==================================================

*Programy:
===========
    Dict.x:
        Program wczytuje z pliku tekstowego podanego jako argument pary ktore umieszcza w slowniku. Nastepnie program otrzymuje ze standardowego wejscia klucze i sprawdza czy istnieja w slowniku

*Pliki:
===================================================
    Slowa.txt:
        Plik tekstowy z 32 parami slow

*Biblioteki:
===================================================
    Dict.hpp:
        Zawiera implementacje Slownika oraz funkcji hashujacych
    LinkedList.hpp:
        Zawiera implementacje szablonowej listy wskaznikowej

*Uruchamianie:
===================================================
    make: 
        Kompiluje wszystkie programy
    ./Dict.x <nazwa pliku>
        Uruchamia program Dict.x 
    make tar
        Pakuje zawartosc folderu do archiwum tar
    make clean
        Czysci zawartosc folderu