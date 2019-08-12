// Algorithm to check if a string has palindrome permutation

#include <iostream>

using namespace std;

bool palindrome_per(char str[],int &size){

    int char_set[256] = {0};
    int odd_count = 1;
    
    //O(n)
    for(int i=0;i <size ;i++){
    
        int pos = int (str[i]);
       
         char_set[pos] ++;     
    }
    
    //O(1)
    for(int i=0;i < 256;i++){
    
       odd_count += char_set[i] % 2;
              
    }
   
    return odd_count %2;    
}

int main(){

        char str[] = "tactcoa";
        int size = sizeof(str)/sizeof(str[0]);
         
        if(palindrome_per(str,size)){
             cout << "palindrome permutation " <<endl;
        }

}
