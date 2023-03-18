#include <iostream>
#include <string>
#include "TemplateStack.hpp"

using namespace std; 

//Funckja zwracajaca priorytet danego znaku w notacji ONP
int priority(char x){
    switch(x){
        case '(':return 0;
        case '+':return 1;
        case '-':return 1;
        case '*':return 2;
        case '/':return 2;
        default:  return -1;
    }
}

int main()
{
    Stack<char,150 > stos ; //stos przechowujacy operatory
    string word;    // zmienna do ktorej wczytywane beda dane z wejscia
    bool firstoutput = true; //zmienna potrzebna do poprawnego formatowania
    while(cin >> word ){ //wczytywanie danych odzielnych spacja
        if(word=="("){  //Jezeli ( to dodaj do stosu
            stos.push(word[0]);
        }
        else if(word==")"){ //Jezeli ')' to zdejmuj ze stosu dopoki nie natrafisz na (
            while(stos.top()!='('){
                cout<< " "<< stos.pop();
            }
            stos.pop();
        }
        else if(word=="+"||word=="-"||word=="*" || word=="/"){  //Jezeli na trafisz na operator to zdejmuj ze stosu do poki naszczycie nie bedzie operator z nizszym priorytetem
            while(priority(stos.top())>=priority(word[0])){
                cout<< " "<<stos.pop();
            }
            stos.push(word[0]);
        }
        else{
            //Jezeli pierwsze wyjscie to nie wyswietlaj " " przed liczba wpp wyswietl " "+word
            if(firstoutput)
            {
                cout<<word;
                firstoutput = false;
            }else
            cout<< " "<<word;

        }    
    }
    //Zdejmij ze stosu wszystkie pozostale na nim operatory
    while(!stos.empty())
    {
        if(stos.top()!='('){
            cout<< " "<<stos.pop();
        }
        else
        stos.pop();
    }
 

    return 0;
}