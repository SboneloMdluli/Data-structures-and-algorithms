//Get duplicates elements in array with 1 < num[i] < size

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> getDup(vector<int>& num){

        vector<int> res;
        
        if(num.size()==0)
             return res;
                     
        for(int i=0; i<num.size();i++){
            
            if(num[num[i]-1]<0){
            
               res.emplace_back(abs(num[i]));
            }
            
            num[num[i]-1] = - num[num[i]-1];

        }
        
        return res;
}


int main(){
        
        vector<int> num = {1,2,5,5,3,6,3};
        
        for(auto x : getDup(num)){
            cout << x <<" ";
        }
        cout<<'\n';
}
