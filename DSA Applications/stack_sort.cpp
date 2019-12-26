//Algorithm to sort a stack in ascending order

#include <stack>
#include <iostream>

using namespace std;

void sort_stack (stack<int> &num){

     stack<int> sorted; // sorted stack
     
     //O(n^2)
     while(!num.empty()){
        
        int temp = num.top(); // get top element
        num.pop();
        
        while(!sorted.empty() && sorted.top() < temp){
            
            num.push(sorted.top());
            sorted.pop();
        
       }
       
        sorted.push(temp);
     
     }
     
    // return sorted;
    while(!sorted.empty()){

        cout << sorted.top() <<endl; // get top element
        sorted.pop();
        
    }
}


int main(){

      stack<int> num ;
      num.push(6);
      num.push(3);
      num.push(1);
      num.push(4);
      num.push(7);
      num.push(2);
      
  //    stack<int> sorted ;
     sort_stack(num);
      
  
}

