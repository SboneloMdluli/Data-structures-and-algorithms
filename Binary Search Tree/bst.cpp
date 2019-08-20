#include <iostream>

using namespace std;

template <typename T>
class node {
    
    public:
    node(){
        node<T>* left = NULL;
        node<T>* right = NULL;
    }

    T elem; // store data 
    node<T>* left;  
    node<T>* right;
    
};

template <typename T>
class bst{
        public:
          bst();
          int const size();
          bool isEmpty() const;
          void add(const T& elem);
          void inorder();
          node<T> *root;
          
        private:
          node<T> *add(node<T> *root,const T& key);
          void inorder(node<T> *newNode);
          int Size;
};

template <typename T>
bst<T>::bst(){
        root = NULL;
        Size = 0;
}

template <typename T>
bool bst<T>::isEmpty() const{
        return size() == 0;
}

template <typename T>
int const bst<T>::size(){
        return Size;
}

template <typename T>
void bst<T> :: add(const T& key){
 
    {
      root = add(root, key);
      Size++;
    }
}

template <typename T>
node<T> *bst<T>:: add(node<T> *newNode,const T& key){
   // make root
    if (newNode == NULL) {
      node<T> *newNode = new node<T>; // create new node 
      newNode-> elem = key;
      
      return newNode;
    } 
    
    if (key < newNode->elem) 
        newNode->left  = add(newNode->left, key); 
    else if (key > newNode->elem) 
        newNode->right = add(newNode->right, key);   
     
    return newNode;
}

template <typename T>
void bst<T>::inorder(node<T> *newNode) 
{ 
    if (newNode != NULL) 
    { 
       inorder(newNode->left); 
       cout << newNode->elem<<endl; 
       inorder(newNode->right); 
    } 
} 


template <typename T>
void bst<T>::inorder() 
{ 
    inorder(root); 
} 


int main(){

    bst<int> FirstTree;
    FirstTree.add(3);
    FirstTree.add(2); 
    FirstTree.add(1);
    FirstTree.add(4);
       
    FirstTree.inorder();
}
