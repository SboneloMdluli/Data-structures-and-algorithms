//Program to check if an array contains unique elements

#include <iostream>

using namespace std;

bool isUnique(int Arr [],int &size){
        
      char char_set[260] = {0}; //O(1) additional space
      
      for(int i=0; i < size; i++){ // O(n)
      
        int pos = int (Arr[i]);
      
        if(char_set[pos]>0){
            return false;
        }
        
        char_set[pos] = 1;
      }
      
      
     return true;
}


int main(){

       int Arr[] = {1,2,1,6};
       
       int size = sizeof(Arr)/sizeof(Arr[0]);

       if(isUnique(Arr,size)){
       
       cout << "unique" <<endl;
       }else
        cout << "not unique" <<endl;        

}
