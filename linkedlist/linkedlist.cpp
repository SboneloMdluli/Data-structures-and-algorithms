#include <iostream>
#include <string>
#include <exception>

using namespace std;

template <typename T>
class Exception {

        public:
           Exception(const string& msg) : msg_(msg) {}
          ~Exception() {}

           string getMessage() const {return msg_;}
        private:
           string msg_;
};


template <typename T>
class node {
   public:
   T elem; // store data     
   node<T>* next; // next pointer
};      

template <typename T>
class linkedlist{
        public :
                linkedlist();
                ~linkedlist();
                bool isEmpty() const;
                void addFront(const T& elem);
                void deleteNode(const T& elem);
                void deleteFront();
                void addBack(const T& elem);
                void deleteBack();
                const T peek() const;
                const int size();
                void reverse();
                void printList() const;

        private:
                node<T> *head;
                int Size;
};

template <typename T>
linkedlist<T>::linkedlist(){
        head = NULL;
        Size = 0;
}

template <typename T>
bool linkedlist<T> :: isEmpty() const{
        //head will point to null if the linkedlist is empty [head] --> NULL
        return head==NULL;
}

template <typename T>
void linkedlist<T> :: addFront(const T& elem){
        //O(1)
        node<T> *newNode = new node<T>; // create new node 
        newNode->elem = elem; // store parsed in data to newly created node
        newNode->next =  head; // link new node with existing linkedlist
        head = newNode; // shift the head to poiunt to new node
        Size++;
}

template <typename T>
linkedlist<T> :: ~linkedlist(){
    while(!isEmpty()){
        deleteFront();
    }
}

template <typename T>
const int linkedlist<T>::size(){return Size;}

template <typename T>
void linkedlist<T> :: deleteFront(){
        //O(1)
       try {
                if(head == NULL){
                throw(Exception<T>("deleting empty linkedlist"));
                }
                else{
                        node<T> *oldHead = head;
                        head =  head->next;
                        delete oldHead;
                        Size--;
                                
                }
           }
           
       catch(Exception<T>& e) {
                 cout << e.getMessage() <<endl;
        }

        
}

template <typename T>
void linkedlist<T> :: deleteNode(const T& elem){
        //O(n)
        //could do better O(1) if we could keep index of where the elements are in the list
        // which is nothing more but a hashtable but only if we know the size since 
        // in a hashtable the size must be know before allocations
        int oldSize = size();
        node<T> *curr=head,*trail;

       
       try {
                if(head == NULL){
                throw(Exception<T>("deleting empty linkedlist"));
                }
                
               if(head->next == NULL && curr->elem == elem){ 
                deleteFront(); 
          
                }
        
                while(curr != NULL){
                        //cout << curr->elem <<endl; 
                        if(curr->elem == elem){
                            trail->next = curr->next;
                            delete curr;
                            Size --;
                        }
                         
                         trail = curr;
                         curr = curr->next;        
                }
                
                if(oldSize == size())
                        cout<<"element not found"<<endl;
                }
                   
       catch(Exception<T>& e) {
                         cout << e.getMessage() <<endl;
        }
           
   
}


template <typename T>
const T linkedlist<T> :: peek() const{ // return front element
         try {
                if(head == NULL){
                throw(Exception<T>("empty linkedlist"));
                }
                else{
                      return head->elem; 
                }
           }
           
        catch(Exception<T>& e) {
                 cout << e.getMessage() <<endl;
        }
  
      
}


template <typename T>
void linkedlist<T>:: printList()const{

        node<T> *curr = head;
        while(curr != NULL){
                cout<<curr->elem <<"-->";
                curr = curr->next;
        }
        cout << "\n";
}

template <typename T>
void linkedlist<T> :: reverse(){
        node<T> *curr = head, *prev = NULL, *next = NULL;
        try {
                if(head == NULL)
                throw(Exception<T>("empty linkedlist"));
           }
           
        catch(Exception<T>& e) {
                 cout << e.getMessage() <<endl;
        }
        
        while(curr != NULL){  
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;     
        }
        
                head = prev;
}


int main(){

        linkedlist<float> list;
        list.addFront(1.4);
        list.addFront(1.8);
        list.addFront(4.079);
        list.printList();
        cout << list.peek() <<endl;
        cout << list.size() <<endl;
        list.deleteFront();
        list.addFront(40);
        list.deleteNode(1.4);
        list.printList();
        list.reverse();
        list.printList();
        cout << list.size() <<endl;
        
        return 0;
}
