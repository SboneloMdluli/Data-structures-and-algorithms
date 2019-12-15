#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int pivot(vector<int>& nums){
       
       int left = 0, right = nums.size()-1;
         
       int mid; 
       
       while(right>left){
       
           mid =  left + (right-left)/2;
        
           if(nums[mid]>nums[right]){
        
               left = mid +1;
            }else{
               right = mid;
           }
       
       }
            
       return left;
}



int search(vector<int>& nums,int k){

        if(nums.size()==0)
            return -1;
        
        int left = 0, right = nums.size()-1;
        int pvt = pivot(nums);
        
        if(k>=nums[pvt] && k <= nums[right]){
           left = pvt;
        } else{
        
           right = pvt-1;
        }
        
        int mid;
        while(right >=left){
            
            mid = left +(right-left)/2;
            
            if(nums[mid]==k){
                return mid;
            }
                
            if(nums[mid]>k){
            
               right = mid-1; 
            
            }else{
            
                left = mid +1;
            }            
        
        }
        
        return -1;
}


int main(){

        vector<int> nums = {};
     
        cout << search(nums,7) ; 
}

