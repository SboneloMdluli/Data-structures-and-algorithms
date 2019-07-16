#include <iostream>
#include <cmath> 
#include <vector>

using namespace std;

template <typename T>
class maxHeap{
    public :
        void swap(int x, int y);
        bool empty(){return Arr.size()==0;}
        void maxHeapify(const int& i);
        void insert(const T&);
        void make_maxHeap();
        void print(){
           for(T elem : Arr){
                cout << elem <<" ";
           }
           cout << "" <<endl;
        };
        
        void extractMax(){
               Arr.erase (Arr.begin());
               make_maxHeap();
        }
        
        void increase_key(int i,T key);
                
     
        const T getMax() const{return Arr[0];}

    private:
        vector<T> Arr;
};

template <typename T>
void maxHeap<T>::increase_key(int i, T key)
{
        // O(lg n) , we have to go from root to node of interest which is the same as 
        // height of the tree
        if (key < Arr[i]){
           cout << "key is smaller than curr key"<<endl;
        }
        else{
           Arr[i] = key;
           // compare new key with parent (if new key is greater than parent swap)
           while(Arr[i] > Arr[floor(i/2)]){
                swap(i, floor(i/2)); // swap child with parent 
                i = floor(i/2);  // do this so that we can check if parent & ancestor
                // meet the heap invarient 
                // we cound have used recursion for this
                
           }
        
        }
            
}


template <typename T>
void maxHeap<T>::insert(const T& x)
{
        Arr.push_back(x);
        make_maxHeap();
            
}

template <typename T>
void maxHeap<T>::swap(int pos_i, int pos_j){
        Arr[pos_i] = Arr[pos_i]^Arr[pos_j];
        Arr[pos_j] = Arr[pos_i]^Arr[pos_j];
        Arr[pos_i] = Arr[pos_i]^Arr[pos_j];
}

template <typename T>
void maxHeap<T>::maxHeapify(const int& i){
 //O(lg(n))

 // get children indices
 T right = 2*i+2;
 T left = 2*i+1;
 T largest;
 // get index largest elem between parent and childeren
 if(left <= Arr.size()  && Arr[left] > Arr[i]){
 
  largest = left;
 
 }
 else{
 
    largest = i;
 
 }
 
 if(right <= Arr.size() && Arr[right] > Arr[largest]){
 
   largest = right;
 }

 // check if largest is the parent
 if (largest != i){
  // make largest elem to be the parent by swapping largest with current largest elem
  swap(i,largest);
   // make a recursive call to the function only from that node
   // and make a heap root to leaves
  maxHeapify(largest); 
 
 }

}


template <typename T>
void maxHeap<T>::make_maxHeap(){
 
  //O(n)
 //only refer to the first half of the array because the other half contains leaf nodes
 //and we assume they are trival max_heaps
 if (Arr.size() > 3){
     for(int i = floor(Arr.size()/2 -1); i>=0; i--){
       maxHeapify(i);
    }
   
 }else{
        
       for(int i = 3; i>=0; i--){
       maxHeapify(i);
    }
 }
 
}

int main(){

       maxHeap<int> numHeap;

       numHeap.insert(35);
       numHeap.insert(33);
       numHeap.insert(42);
       numHeap.insert(10);
       numHeap.insert(14);
       numHeap.insert(19);
       numHeap.insert(27);
       numHeap.insert(44);
       numHeap.insert(26);
       numHeap.insert(31);
            
       numHeap.print();
    
     
       numHeap.increase_key(6,34);
     
       numHeap.print();

}


