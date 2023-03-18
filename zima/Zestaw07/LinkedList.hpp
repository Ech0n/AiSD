#ifndef LIST_H
#define LIST_H

#include<iostream>

template <class T>
class List {
    private:
        /*
        Struktura reprezentujaca pojedynczy element listy
        */
        struct Node{
            Node *next;
            Node *prev;
            T value;
            Node(T val = 0)
            {
                value = val;
                next = nullptr;
                prev = nullptr;
            }
        };
        Node *head; //wskazuje na pierwszy element listy
        Node *tail; //wskazuje na ostatni element listy
        int length; //Prechowuje dlugosc listy
    public:
        /*
            Iterator dwu kierunkowy
        */

        struct Iterator{
            public:
                Node* n;  //Wskaznik na node odpowiadajacy iteratorowi
                Iterator(Node *ptr = nullptr){  //Konstruktor
                    n = ptr;
                }
                T& operator*(){ //Operator: *
                    return n->value;}  
                T* operator->(){    //Operator: ->
                    return &(n->value);} 
                bool operator==(const Iterator &prawy){ // Operator porownania ==
                    return this->n==prawy.n;}
                bool operator!=(const Iterator &prawy){ //Operator nie rownosci !=
                    return !(this->n==prawy.n);} 
                Iterator &operator++(){ //operator inkrementacji (prefix)
                    n = n->next;
                    return *this;  
                }
                Iterator& operator--(){ //operator dekrementacji (prefix)
                    this->n = this->n->prev;
                    return *this;
                }
                
        };
        Iterator begin(){return Iterator(head);}    //Zwraca iterator wskazujacy na pierwsyz elemtn
        Iterator end(){return Iterator(nullptr);}   //Zwraca iterator wskazujacy na koniec listy
        Iterator last(){return Iterator(tail);}   //Zwraca iterator wskazujacy na koniec listy

        List(){ //Konstruktor listy
            length = 0;
            head = nullptr;
            tail = nullptr;
        }
        void push_front(T x){ //Dodaje element na poczatek listy
            insert(begin(),x);
        }
        T pop_front() // Usuwa i zwraca element z początku listy
        {
            if(!head){  //Jezeli poczatkowy element nie istnieje to nie mozna dodac i lista jest pusta
                throw std::out_of_range("Nie mozna wykonac operacji pop_front na pustej tablicy!");
            }
            T value = head->value;
            erase(begin());
            return value;
        }
        void push_back(T x) // Dołącza element na koniec listy
        {
            Node *n = new Node(x);  //nowy element
            n->prev = tail;         
            if(tail)    //Jezeli lista nie jest pusta to nowy element jest nastepnikiem obecnie ostatniego
                tail->next = n;
            else        // wpp musimy ustawic nowy poczatek listy
                head = n;

            tail = n;   //Ustawiamy nowy koniec listy
            length++;
        }
        T pop_back()// Usuwa i zwraca element z końca listy
        {
            if(tail){   //jezeli lista nie jest pusta
                T value = tail->value;
                erase(Iterator(tail));
                return value;

            }else{
                throw std::out_of_range("Nie mozna wykonac operacji pop_back na pustej liscie");
            }
        }
        int size(){return length;} // Zwraca liczbę elementów w liście
        bool empty() // Zwraca true gdy lista jest pusta
        {
            return (head==nullptr);
        }
        void clear() // Czyści listę
        {
            if(head)
            {
                Node *n =head;
                while(n!=nullptr)
                {
                    Node *t = n->next;
                    delete n;
                    n = t;
                }

                head = nullptr;
                tail = nullptr;
                length = 0;
            }
            else{
                throw std::out_of_range("Nie mozna oproznic pustej listy!");
            }

        }
        Iterator find(T x) // Zwraca iterator pierwszego elementu o wartości x
        {
            for(Iterator it = begin();it!=end();++it){
                if(*it==x)
                    return it;
            }
            return end();
        }
        Iterator erase(Iterator it) // Usuwa i zwraca element na ktory wskazuje it
        {
            Iterator ret; //Iterator ktory zwrocimy jako wynik
            if(it.n){     //Sprawdzamy czy it wskazuje na jakis element
                if(it!=begin())   //Czy it -> head
                    it.n->prev->next = it.n->next;
                else{
                    head = it.n->next;
                }
                if(it.n!=tail){   //Czy it -> tail
                    it.n->next->prev = it.n->prev;
                    ret = Iterator(it.n->next);
                }else{
                    ret = end();
                    tail = it.n->prev;
                }
            }

            delete it.n;  //Usuwamy nie potrzebny element list z pamieci
            length--;
            return ret;
        }
        Iterator insert(Iterator i, T x)// Wstawia element x przed pozycję i
        {
            Node *wsk = new Node(x);    //Nowy element do wstawienia
            
            wsk->next = i.n; 
            
            if(i.n){  //Jezeli i wskazuje na jakis element (nie jest koncem listy)
                wsk->prev = i.n->prev;
                i.n->prev = wsk;
            }else{
                wsk->prev = tail;
                tail = wsk;
            }

            if(wsk->prev){  //Sprawdzamy czy wsk nie wskazuje na nullptr, jezeli tak to jest nowym poczatkiem
                wsk->prev->next = wsk;
            }else{
                head = wsk;
            }

            length++;
            return wsk;
        }
        int remove(T x) // Usuwa wystąpienia x i zwraca ich liczbę
        {
            int ile = 0;
            for(Iterator it = begin();it != end();++it){
                while( *it == x ){
                    it = erase(it);
                    ile++;
                }
            }
            return ile;
        }
        
};

#endif