==================================================
Autor: Mateusz Dyszewski        Krakow, 20.10.2022
==================================================

*Dzialanie:
===========
    Stack.x:
        Program wczytuje dane ze standardowego wejscia zawierajace instrukcje, ktore program nastepnie wykorzystuje.
    Generator.x:
        Program generuje do pliku dane.txt dane dla programu Stack.x
    ONP.x:
        Program wczytuje ze standardowego wyjscia operacje matematyczna zapisana w notacji infiksowej i zwraca ja zapisana w ONP

*Biblioteki:
===============
    ArrayStack:
        Biblioteka implementujaca stos za pomoca tablicy
    LinkedStack:
        Biblioteka implementujaca stos za pomoca wskaznikow
    onpStack: //Nie wykorzystana w programie
        Biblioteka implementujaca stos za pomoca tablicy do wykorzystania w programie "ONP.x". Ostatecznie biblioteka nie wykorzystana w programie.
    TemplateStack:
        Szablon klasy stosu za pomoca tablicy

*Uruchamianie:
===============
    make <nazwa_programu>: //np. make ONP.x
        Kompiluje wybrany program
    ./<nazwa_progrmau> :
        Uruchamia skompilowany wczesniej program
    make tar
        Pakuje zawartosc folderu do archiwum tar
    make clean
        Czysci zawartosc folderu