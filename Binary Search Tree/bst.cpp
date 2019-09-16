#include <iostream>
#include <stack>
#include <vector>

using namespace std;

template <typename T>
class node {
    public:    
    node(){
        node<T>* left = nullptr;
        node<T>* right = nullptr;
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
          bool isleaf(const T& elem);
          bool contains(const T& elem);
          T const min();
          T const max();
          void deleteNode(const T& elem);
          
        private:
          vector<T> postorder(node<T> *newNode);
          vector<T> preorder(node<T> *newNode);
          vector<T> inorder(node<T> *newNode);
          node<T> *insert(node<T> *root,const T& key);
          node<T> *contains(node<T> *newNode,const T& key);
          node<T> *min(node<T> *newNode);
          node<T> *max(node<T> *newNode);
          void deleteNode(node<T> *&newNode,const T& key);
          int Size;
          int Min;
          int Max;
};


template <typename T>
bst<T>::bst(){
        root = nullptr;
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
 
    //store unique elements
    if(! contains(key) ){
      root = insert(root, key);
      Size++;
    }
}

template <typename T>
node<T> *bst<T>:: insert(node<T> *newNode,const T& key){
   // make root
    if (newNode == nullptr) {
      node<T> *newNode = new node<T>; // create new node 
      newNode-> elem = key;
      
      return newNode;
    } 
    
    // recursively insert new elem based on the bst invarient
    if (key < newNode->elem) 
        newNode->left  = insert(newNode->left, key); 
    else if (key > newNode->elem) 
        newNode->right = insert(newNode->right, key);   
     
    return newNode;
}


template <typename T>
node<T> *bst<T>:: contains(node<T> *newNode,const T& key){
    //O(h)
    if (newNode == nullptr || key == newNode->elem) {
      return newNode;
    } 
        
    // recursively search for an elem
    if (key < newNode->elem) 
        return contains(newNode->left,key); 
  
    return  contains(newNode->right,key); 
}

template <typename T>
bool bst<T>:: contains(const T& elem){
        if( contains(root,elem)==nullptr){
            return false;
        }
        return contains(root,elem)->elem == elem;
}


template <typename T>
bool bst<T>:: isleaf(const T& elem){

        return contains(root,elem)->left == nullptr &&  contains(root,elem)->right == nullptr;
}

template <typename T>
node<T> * bst<T>:: min(node<T> *newNode){
    
     if(newNode==nullptr){
        return newNode;
     }
        
     Min = newNode->elem;
     return min(newNode->left);
          
}

template <typename T>
T const bst<T>:: min(){
       min(root);
       return Min;
}

template <typename T>
node<T> * bst<T>:: max(node<T> *newNode){
    
     if(newNode==nullptr){
        return newNode;
     }
        
     Max = newNode->elem;
     return max(newNode->right);
          
}

template <typename T>
T const bst<T>:: max(){
       max(root);
       return Max;
}


template <typename T>
void bst<T>::deleteNode(node<T> *&newNode,const T& key){

	if (key < newNode->elem){
		deleteNode(newNode->left, key);
	}

	else if (key > newNode->elem){
		deleteNode(newNode->right, key);
	}

	else{
		// if leaf node
		if (isleaf(key))
		{
			// delete leaf
			delete newNode;
			newNode = nullptr;
		}
        }

	
}

template <typename T>
void bst<T>:: deleteNode(const T& elem){
      
     deleteNode(root,elem);
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
            lastNode = nullptr;
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
    FirstTree.insert(10); // duplicate elem
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
    
    FirstTree.deleteNode(90);
    
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
    
    if(FirstTree.contains(90))
        cout << "found"<<endl;
        
    if(FirstTree.isleaf(31))
        cout <<"root"<<endl;
        
    cout <<"Finding min"<<endl;    
    cout <<FirstTree.min()<<endl;
    
    cout <<"Finding max"<<endl;    
    cout <<FirstTree.max()<<endl;
    
   
}
