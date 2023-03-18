#ifndef BINTREE_H
#define BINTREE_H

#include <iostream>

class BinaryTree{
    public:
        struct Node{
            int value;
            Node* l;
            Node* r;
            Node(int x):value{x},l{nullptr},r{nullptr}{};
        };
        BinaryTree():root{nullptr},_size{0},_depth{0}{};
        void insert(int);
        Node* search(int);
        Node*  searchRecursive(int);    
        int size();
        int minimum();
        int maximum();
        int depth();
        void inorder(Node*);
        void preorder(Node*);
        void postorder(Node*);
        Node* root;
    private:
        Node* internalRecurisveSearch(int,Node*);
        int _size;
        int _depth;

};

void BinaryTree::insert(int x){
    Node* new_node = new Node(x);
    if(root == nullptr){
        root = new_node;
        _size++;
        _depth = 1;
        return;
    }
    int depth = 2;
    Node* cur = root;
    while(cur != nullptr){
        if(x<cur->value){
            if(cur->l==nullptr){
                cur->l = new_node;
                if(depth>_depth)
                    _depth = depth;
                _size++;
                return;
            }
            cur = cur->l;
        }else{
            if(cur->r==nullptr){
                cur->r = new_node;
                _size++;
                if(depth>_depth)
                    _depth = depth;
                return;
            }
            cur = cur->r;
        }
        depth++;
    }
}

BinaryTree::Node* BinaryTree::search(int x){
    Node* cur = root;
    while(cur!=nullptr){
        if(x==cur->value){
            return cur;
        }
        else if(x<cur->value){
            cur = cur->l;
        }else{
            cur = cur->r;
        }
    }
    return nullptr;
}

BinaryTree::Node* BinaryTree::searchRecursive(int x){
    return internalRecurisveSearch(x,root);
}

BinaryTree::Node* BinaryTree::internalRecurisveSearch(int x,Node* cur){
    int val = cur->value;
    if(x==val){
        return cur;
    }else if(x<val && cur->l){
        return internalRecurisveSearch(x,cur->l);
    }else if(x>val && cur->r){
        return internalRecurisveSearch(x,cur->r);
    }else{
        return nullptr;
    }
}

int BinaryTree::size(){
    return _size;
}
int BinaryTree::minimum(){
    if(root==nullptr){
        throw std::out_of_range("Nie mozna uzyc funkcji minimum na pustym drzewie!");
    }
    Node* cur = root;
    while(cur->l != nullptr){
        cur = cur->l;
    }
    return cur->value;
}
int BinaryTree::maximum(){
    if(root==nullptr){
        throw std::out_of_range("Nie mozna uzyc funkcji maximum  na pustym drzewie!");
    }
    Node* cur = root;
    while(cur->r != nullptr){
        cur = cur->r;
    }
    return cur->value;
}

int BinaryTree::depth(){
    return _depth;
}

void BinaryTree::inorder(Node* n = nullptr){
    if(n == nullptr){
        n = root;
    }
    if(n->l)
        inorder(n->l);
    std::cout<<n->value<<" ";
    if(n->r)
        inorder(n->r);
}

void BinaryTree::preorder(Node* n = nullptr){
    if(n == nullptr){
        n = root;
    }
    std::cout<<n->value<<" ";
    if(n->l)
        preorder(n->l);
    if(n->r)
        preorder(n->r);
}
void BinaryTree::postorder(Node* n = nullptr){
    if(n == nullptr){
        n = root;
    }
    if(n->l)
        postorder(n->l);
    if(n->r)
        postorder(n->r);
    std::cout<<n->value<<std::endl;
}

#endif