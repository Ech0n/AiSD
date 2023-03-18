#include <iostream>
#include "BinaryTree.hpp"

int main(){

    BinaryTree tree = BinaryTree();
    int ile_polecen;
    std::cin >> ile_polecen;
    int liczba;
    for(int i = 0; i<ile_polecen;i++)
    {
        std::cin >> liczba;
        tree.insert(liczba);
    }
    std::cout<<tree.size()<<" "<<tree.depth()<<" "<<tree.minimum()<<" "<<tree.maximum()<<"\n";
    tree.preorder();
    for(int i = 1;i<=9;i++){
        std::cout<<std::endl;
        if(tree.search(i)!=nullptr){
            std::cout<<"Yes";
        }else{
            std::cout<<"No";
        }
    }
    return 0;
}