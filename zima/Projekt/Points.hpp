#ifndef POINTS_H
#define POINTS_H

#include <iostream>
#include <cmath>
#include <string>
#include <fstream>

//Klasa N wymiarowego wektora
class Wektor{
    public:
        int N;
        float *values;
        Wektor(int size){
            N = size;
            values = new float[N];
        }
        float& operator[](int i){
            if(i<N)
                return values[i];
            throw std::out_of_range("Wektor index out of range!");
        }
        Wektor& operator=(const Wektor& b) 
        {
            N = b.N;
            values = new float[N];
            for(int i = 0;i< N;i++){
                values[i] = b.values[i];
            }
            return *this;
        }
        //Funkcja zwraca odleglosc pomiedzy wektorami wedlug metryki euklidesowej
        float distance(Wektor b){
            if(b.N != N){
                std::cout<<"Nie mozna znalezc dystansu pomiedzy punktami z innymi wymiarami!\n"<< to_string()<<std::endl;
                return -1;
            }
            if(N==0){
                std::cout<<"Napotkano pusty wektor\n";
            }
            float sum = 0;
            for(int i = 0;i<N;i++){
                sum+= (values[i] - b[i])*(values[i] - b[i]);
            }
            //Mozna przyspieszyc dzialanie funkcji poprzez zwrocenie samej sumy
            // poniewaz funkcja jest uzywana jedynie do porownywania dwoch odleglosci
            return sqrtf(sum);
        }
        std::string to_string(){

            std::string wynik = "[";
            for(int i = 0;i<N;i++)
            {
                wynik+= std::to_string(values[i])+", ";
            }
            wynik[wynik.length()-2]= ']';
            return wynik;
        }
        bool operator==(Wektor &b){
            if(N != b.N){return false;}
            for(int i=0;i<N;i++){
                if (values[i]!=b[i])
                {
                    return false;
                }
            }
            return true;
        }
};

class Points{
    public:
        struct Node{
            Node *left, *right;
            Wektor vec;
            Node(Wektor x): vec{x}{  
                left = nullptr;
                right = nullptr;
             }
        };
        Node *root;
        //Konstruktor przyjmuje jako argument wymiar przestrzeni
        Points(int dimension){
            _size = 0;
            root = nullptr;
            N = dimension;
        }
        //Funkcja dodajaca punkt do przestrzeni
        void insert(Wektor x){
            if(x.N != N){
                std::cout<<"Cannot insert vector which has dimmension diffrent from database!\n";
                return;
            }
            Node *new_node =new Node(x);
            int currentDepth = 0;
            Node *currentNode = root;
            while(currentNode != nullptr){
                if(x[currentDepth] > (currentNode->vec)[currentDepth] )
                {
                    if(currentNode->right){
                        currentNode = currentNode->right;}
                    else{
                        currentNode->right = new_node;
                        _size++;
                        return;
                    }
                }else{
                    if(currentNode->left){
                    currentNode = currentNode->left;}
                    else{
                        currentNode->left = new_node;
                        _size++;   
                        return; 
                    }
                }
                currentDepth = (currentDepth+1) % N;
            }
            root = new_node;
            _size++;
            return;
        }
        int get_dimension(){
            return N;
        }
        int size(){
            return _size;
        }
        //Funkcja szukajaca najblizszego sasiada dla wektora w
        Wektor find_nearest(Wektor w){
            if(w.N != N){
                throw std::out_of_range("Nie mozna znalezc sasiada dla punktu o wymiarze innym niz baza!");
            }
            if(_size == 0){
                throw std::out_of_range("Cannot search an empty tree");
            }
            float shortest_distance = root->vec.distance(w);
            Wektor current_best = (root->vec);
            nearest_neighbourrec(w,root,&shortest_distance,current_best,0);
            return current_best;
        }
        //Funkcja zapisuje objekt do pliku
        void save_to_file(std::string filename){
            std::ofstream plik_wyjsciowy(filename);
            plik_wyjsciowy << N << std::endl;
            internal_save(plik_wyjsciowy,root);
            plik_wyjsciowy.close();
        }
        //Funkcja laduje wartosci drzewa z pliku zapisanego wczesniej funkcja save_to_file
        int load_from_file(std::string filename){
            std::ifstream plik_wejsciowy(filename);
            int wymiar = 0;
            plik_wejsciowy >> wymiar;
            N = wymiar;
            root = nullptr;
            _size = 0;
            while(!plik_wejsciowy.eof()){
                load_vec(plik_wejsciowy,N);
            }
            return wymiar;
        }
        //Funkcja wyswietla strukture drzewa
        void print(Node *n = nullptr,int depth = 0){
            if(n == nullptr){
                n = root;
            }
            std::cout<<n->vec.to_string()<<", numer osi podzialu przestrzeni: "<<depth%N<<std::endl;
            
            if(n->left){
                for(int i = 0;i<depth;i++){
                    std::cout<<" ";
                }
                std::cout<<"-left:";
                print(n->left,depth+1);
            }
            if(n->right){
                for(int i = 0;i<depth;i++){
                    std::cout<<" ";
                }
                std::cout<<"-right";
                print(n->right,depth+1);
            }
                
        }

    private:
        int N;
        int _size;
        //Funkcja znajduje najblizszego sasiada 
        void nearest_neighbourrec(Wektor x,Node* cur ,float *shortest ,Wektor &best,int depth){
            int currentdepth = depth % N;
            Node *oppositenode = nullptr;
            // std::cout<<"visit: "<<cur->vec.to_string()<<std::endl;
            if(x[currentdepth]>(cur->vec[currentdepth])){
                if(cur->right != nullptr){
                nearest_neighbourrec(x,cur->right,shortest,best,depth+1);
                }
                oppositenode = cur->left;
            }else{
                if(cur->left != nullptr)
                {
                    nearest_neighbourrec(x,cur->left,shortest,best,depth+1);
                }
                oppositenode = cur->right;

            }

            float dist  = cur->vec.distance(x);
            if(!(x == cur->vec)){ 
                if(dist < *shortest ){
                    best = (cur->vec);
                    *shortest = dist;
                }
            }
            if(std::fabs(x[currentdepth]-cur->vec[currentdepth])<*shortest){
                if(oppositenode != nullptr){
                    nearest_neighbourrec(x,oppositenode,shortest,best,depth+1);
                }
            }
        }
        //Funkcja obsluguje zapis do pliku
        void internal_save(std::ofstream &plik,Node *cur){
            if(cur == nullptr){
                return;
            }
            for(int i = 0;i<N;i++){
                plik<< cur->vec[i]<<" ";
            }
            plik<<"\n";
            internal_save(plik,cur->left);
            internal_save(plik,cur->right);
            return;
        }
        //Funkcja obsluguje ladowanie danych do wektora ze strumienia
        std::ifstream &load_vec(std::ifstream &strumien,int n){
            Wektor a = Wektor(n);
            float x;
            for(int i = 0;i<n;i++){
                strumien>>x;
                a[i] = x;
                if(strumien.eof()){
                    return strumien;
                }
            }
            insert(a);
            return strumien;
        }
        
};

#endif