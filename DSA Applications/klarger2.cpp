#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int klarger(vector<int>& nums, int k){

       if(nums.size()<1)
            return -1;
        //O(nlog(n))
        sort(nums.begin(),nums.end());
        return nums[nums.size()-k];
}

int main(){
       
       vector<int> nums = {3,2,1,5,6,4};
       
      
       cout << klarger(nums,2) <<endl;

}        
