//binary search
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int search(vector<int>& num, int k){

        if(num.size()==0){
            return false;
        }

        int left =0, mid;
        int right = num.size()-1;
        
        while(right >= left){
        
            mid = floor( left + (right - left)/2);
            
            if(num[mid]==k){
                return mid;
            }  
             
            if(num[mid]<k){
                left = mid+1;
            }else{
            
                right = mid-1;
            }  
        }

        return -1;
}


int main(){

        vector<int> num ={1,2,2,5,10,11};
        
        cout << search(num,1)<<endl;

}

