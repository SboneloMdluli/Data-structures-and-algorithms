#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums){
        
        vector<vector<int>> res;
        
        if(nums.size()<3)
             return res;
        
        int target,left,right;
        int size = nums.size();
        // n log(n)
        sort(nums.begin(),nums.end());
        
        //n^2
        for(int i =0; i <size-1;i++){
            
            target = -nums[i];         
            left = i+1;
            right = size-1;
            
            if (nums[i] > 0 || nums[right] < 0)
                break;
                
            while(left<right){
        
                    //found triplet   
                 if(nums[left]+nums[right] == target){
                       vector<int> temp = {nums[left],nums[right], nums[i]};
                       res.emplace_back(temp);
                    
                        //skip duplicates
                        while(left<right && nums[left+1]==nums[left]){
                               left++;
                        }
                                    
                       while(left < right && nums[right]==nums[right-1]){
                            right++;
                        } 
                                
                        left++;
                        right--;  
                } 
                    

               if(nums[left]+nums[right] > target){
                   right--;
               }else{
                    left++;
               }
            
            }
              
        }
        
        return res;

}


int main(){

        vector<int> nums = {1,-1,0,5,4,-3,-1,2,5,-2,3,0,-10,0};
        
        for(auto x: threeSum(nums)){
             for(auto y: x){
                cout << y << " "; 
             }
             cout <<'\n';
        }
        


}
