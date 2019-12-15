#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int>& nums){

        int max_a =0, left = 0, right = nums.size()-1;
        int local_area=0; 
        
        //O(n)        
        while(right>=left){
        
             local_area = (right-left)*min(nums[left],nums[right]);
             
             if(nums[left]<=nums[right]){
                left++;
             }else{
                right--;
             }
             
             max_a = max(local_area,max_a);
        
        }
     
        return max_a;
}


int main(){

        vector<int> nums ={1,8,6,2,5,4,8,3,7};
        
        cout << maxArea(nums) <<endl;

}
