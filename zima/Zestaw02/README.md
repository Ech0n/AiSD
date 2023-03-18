==================================================
Autor: Mateusz Dyszewski        Krakow, 29.10.2022
==================================================

*Dzialanie:
===========
    Queue.x:
        Program wczytuje dane ze standardowego wejscia zawierajace instrukcje, ktore program nastepnie wykonuje.
    Generator.x:
        Program generuje dane do pliku dane.txt dla programu Queue.x
    Radix.x:
        Program wczytuje ze standardowego wejscia liczby ktore dodaje na biezaco do vectora. Nastepnie program sortuje liczby za pomoca algorytmu radix sort wykorzystujacego 10 kolejek. Program wypisuje posortowane liczby

*Biblioteki:
===============
    ArrayQueue:
        Biblioteka implementujaca kolejke za pomoca tablicy
    LinkedQueue:
        Biblioteka implementujaca kolejke za pomoca wskaznikow
    TemplateQueue:
        Szablon klasy kolejki za pomoca wskaznikow

*Uruchamianie:
===============
    make : 
        Kompiluje wszystkie programy
    ./<nazwa_progrmau> :
        Uruchamia skompilowany wczesniej program
    make tar
        Pakuje zawartosc folderu do archiwum tar
    make clean
        Czysci zawartosc folderu