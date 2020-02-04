//Get first duplicate element in array with 1 <= num[i] <= size

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int getDup(vector<int>& num){

     
                     
        for(unsigned int i=0; i<num.size();i++){
            
            if(num[num[i]-1]<0){
            
               return abs(num[i]);
            }
            
            num[abs(num[i])-1] = - num[abs(num[i])-1];

        }
        
        return -1;
}


int main(){
        
        vector<int> num = {1,3,5,5,3,6};
        
        cout << getDup(num) <<endl;
}
