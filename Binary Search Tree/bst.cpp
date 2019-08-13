#include <iostream>

using namespace std;

template <typename T>
class node {
        
    node(){
        left = NULL
        right = NULL;
        parent = NULL;
    }

    T elem; // store data 
    node<T>* left;  
    node<T>* right;
    node<T>* parent;
};

template <typename T>
class bst {
        public:
          int const size();
          bool isEmpty() const;
          void add(const T& elem);
          node<T> *node add(node<T> *root, T key);
        
        private:
          node<T> *root;
          int size;
};

template <typename T>
bst<T>::bst(){
        root = NULL;
        size = 0;
}

template <typename T>
bool bst<T>::isEmpty() const{
        return size() == 0;
}

template <typename T>
int const bst<T>::size(){
        return size;
}

template <typename T>
void bst<T> :: add(const T& elem){<T>
        //O(1)
        if (root == NULL){
                node<T> *newNode = new node<T>; // create new node 
                newNode->elem = elem;
                root = newNode;
                size++;
        }
}


