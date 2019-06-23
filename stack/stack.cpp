#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class Stack {
public:
    int size() const { return elem.size(); }
    bool empty() const { return elem.empty();}
    void push(const T&);
    void printStack();
    T pop();
    T peek();
private:
    std::vector<T> elem;
};

template<typename T>
void Stack<T>::printStack() {      

    //vector<T>::iterator ptr; 
   
    for (int i=size()-1; i>=0; i--) 
        cout << elem[i] << " "; 
    
    cout << "\n";
}


template<typename T>
void Stack<T>::push(const T& t) {
    elem.push_back(t);
}

template<typename T>
T Stack<T>::pop() {
    if (empty()) {
        throw std::out_of_range("underflow");
    }
    auto x = elem.back();  
    elem.pop_back();
    return x;
}

template<typename T>
T Stack<T>::peek() {
    if (empty()) {
        throw std::out_of_range("underflow");
    }
    return elem.back();
}

int main(){

     Stack<int> numCollection;
     numCollection.push(1);
     numCollection.push(4);
     numCollection.push(7);
     numCollection.push(6);
     cout << numCollection.peek()<<endl;
     numCollection.printStack();
     numCollection.pop();
     numCollection.printStack();
     cout << numCollection.peek()<<endl;
     
}
