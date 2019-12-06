//ALgorithm to return a range where specific sum in an array is found (only positive nums)

#include <iostream>
#include <vector>
using namespace std;

vector<int> Sum_karray(vector<int> Arr, int &sum){
             
        vector<int> res(2,0);
        
        if(Arr.size()==0)
            return res;
        
        int curr_sum = 0;
        int start=0, end=0;
        
        for(int i = 0; i<= Arr.size() ; i++){
        
                while(curr_sum > sum){
                    curr_sum -= Arr[start];  
                    start++;
                }
               
                if(curr_sum==sum){
                    end = i-1;
                    break;
                }
                    
                 curr_sum += Arr[i];
        }
        
         res[0]=start; 
         res[1]=end;
         
         return res;
                
}


int main(){

        vector<int> arr = {3,4,5,4,6,4,0,10};
                
        int sum = 20;
        for(auto x :Sum_karray(arr,sum)){
           cout << x << " ";
        }
        
}
