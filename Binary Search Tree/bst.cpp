#include <iostream>

using namespace std;

template <typename T>
class node {
        
    node(){
        left = NULL;
        right = NULL;
    }

    T elem; // store data 
    node<T>* left;  
    node<T>* right;
};

template <typename T>
class bst{
        public:
          int const size();
          bool isEmpty() const;
          void add(const T& elem);
          void inorder();
          node<T> *root;
          
        private:
          node<T> * add(node<T> *root,const T& key);
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
void bst<T> :: add(const T& key){
    //O(1)
       // Otherwise add this element to the binary tree
    {
      root = add(root, key);
      size++;
    }
}

template <typename T>
node<T> *bst<T>:: add(node<T> *root,const T& key){
   // make root
    if (node == null) {
      node<T> *newNode = new node<T>; // create new node 
      newNode-> elem = key;

    } /* Otherwise, recur down the tree */
    
    if (key < node->key) 
        node->left  = add(node->left, key); 
    else if (key > node->key) 
        node->right = add(node->right, key);   

    return node;
}

template <typename T>
void bst<T>::inorder() 
{ 
    if (*root != NULL) 
    { 
        inorder(root->left); 
        cout << root->key<<endl; 
        inorder(root->right); 
    } 
} 
