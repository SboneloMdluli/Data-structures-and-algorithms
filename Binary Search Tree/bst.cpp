#include <iostream>
#include <stack>
#include <vector>

using namespace std;

template <typename T>
class node {
    public:    
    node(){
        node<T>* left = NULL;
        node<T>* right = NULL;
    }

    T elem;
    node<T>* left;  
    node<T>* right;

};


template <typename T>
class bst{
        public:
          bst();
          int const size();
          bool isEmpty() const;
          void insert(const T& elem);
          vector<T> postorder();
          vector<T> inorder();
          vector<T> preorder();
          node<T> *root;
          
        private:
          vector<T> postorder(node<T> *newNode);
          vector<T> preorder(node<T> *newNode);
          vector<T> inorder(node<T> *newNode);
          node<T> *insert(node<T> *root,const T& key);
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
void bst<T> :: insert(const T& key){
 
    {
      root = insert(root, key);
      Size++;
    }
}

template <typename T>
node<T> *bst<T>:: insert(node<T> *newNode,const T& key){
   // make root
    if (newNode == NULL) {
      node<T> *newNode = new node<T>; // create new node 
      newNode-> elem = key;
      
      return newNode;
    } 
    
    // recurvely insert new elem based on the bst invarient
    if (key < newNode->elem) 
        newNode->left  = insert(newNode->left, key); 
    else if (key > newNode->elem) 
        newNode->right = insert(newNode->right, key);   
     
    return newNode;
}


template <typename T>
vector<T> bst<T>::preorder() 
{ 
    return preorder(root); 
} 

template <typename T>
vector<T> bst<T>::inorder() 
{ 
    return inorder(root); 
} 


template <typename T>
vector<T> bst<T>::postorder() 
{ 
    return postorder(root); 
} 


template <typename T>
vector<T> bst<T>:: preorder(node<T> *newNode) {
            stack< node<T> * > S;
            vector<T> V;
            if(!root)
               return V;
            S.push(newNode);
            while(!S.empty()){
                node<T> *temp = new node<T>;
                temp = S.top();
                V.push_back(temp->elem);
                S.pop();
                if(temp->right)
                    S.push(temp->right);
                if(temp->left)
                     S.push(temp->left);
            }
            return V;
}


template <typename T>
vector<T> bst<T>:: inorder(node<T> *newNode) {
        stack< node<T> * > S;
        vector<T> V;
        while(newNode || !S.empty()){
             while(newNode){
                S.push(newNode);
                newNode = newNode->left;
            }
            newNode = S.top();
            S.pop();
            V.push_back(newNode->elem);
            newNode = newNode->right;
        }
        return V;
}


template <typename T>
vector<T> bst<T>:: postorder(node<T> *newNode) {
            stack< node<T> * > S;
            vector<T> V;
            node<T> *lastNode = new node<T>; 
            lastNode = NULL;
            node<T> *topNode = new node<T>; 
           
            while(newNode || !S.empty()){
                while(newNode){
                    S.push(newNode);
                    newNode = newNode->left;
                }
                topNode = S.top();
                if(topNode->right && topNode->right != lastNode){
                    newNode = topNode->right;
                }
                else{
                    V.push_back(topNode->elem);
                    lastNode = S.top();
                    S.pop();
                }
            }
            return V;
}

int main(){

    bst<int> FirstTree;
    FirstTree.insert(25);
    FirstTree.insert(15); 
    FirstTree.insert(50);
    FirstTree.insert(10);
    FirstTree.insert(22);
    FirstTree.insert(35);
    FirstTree.insert(70);
    FirstTree.insert(4);
    FirstTree.insert(12);
    FirstTree.insert(18);
    FirstTree.insert(24);
    FirstTree.insert(31);
    FirstTree.insert(44);
    FirstTree.insert(66);
    FirstTree.insert(90);
    
     
    vector<int> preorder = FirstTree.preorder();
    vector<int> inorder = FirstTree.inorder();
    vector<int> postorder = FirstTree.postorder();
     
    cout <<"size = " << FirstTree.size() <<endl;
     
    cout << "preorder"<<endl;
    for(auto val: preorder){
      cout << val <<" ";
    } 
    cout << "\n";
    
    cout << "inorder"<<endl;
    for(auto val: inorder){
      cout << val <<" ";
    } 
    cout << "\n";
    
    cout << "postorder"<<endl;
    for(auto val: postorder){
      cout << val <<" ";
    } 
    cout << "\n";
;
}
