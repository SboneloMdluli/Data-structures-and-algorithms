//SEARCH A SORTED ARRAY FOR THE FIRST ELEMENT LARGER THAN k in log(n)

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int largerK(vector<int>& nums, int& k){

        if(nums.size()==0)
             return -1;
                        
        if(nums[0]>k)
           return 0;
        
        int left = 0;
        int right = nums.size()-1;
        int mid;

        while(right>=left){
            mid = floor(left + (right-left)/2);

            if(nums[mid]<=k){
                left = mid + 1;
            }
            
            if(nums[mid]>k){
                right = mid -1;
            }
            
            if(nums[mid]>k && nums[mid-1]<=k ){
                 return mid;
            }
            
        }
        
        return -1;

}

int main(){

        int k =7;
        vector<int>nums ={-3,-2,5,5,5,10,11};
        
        cout << largerK(nums,k) <<endl;

}

