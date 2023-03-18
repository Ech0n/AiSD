#include <iostream>
using namespace std;

template<class T, int N>
class Stack{
    public:
        Stack(){
            stos = new T[N];
            end = 0;
        }
        template<class U>
        void push(U&& x){
            if(end<N){
                stos[end]=x;
                end++;
            }else{
                cout<<"Wykroczona za limit tablicy\n";
            }
        }
        T pop(){
            if(end>0){
                end--;
                T temp = stos[end];
                stos[end]=0;
                return temp;
            }else
            {
                cout<<"Stos jest pusty"<<endl;
                return 0;
            }
        }
        T& top(){
            return stos[end-1];
        }
        int size()
        {
            return end;
        }
        bool empty()
        {
            if(end>0){
                return false;
            }
            return true;
        }
    private:
        T *stos;
        int end;
};