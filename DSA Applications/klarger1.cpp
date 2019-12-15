#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int klarger(vector<int>& nums, int k){

        if(nums.size()==0)
          return -1;
        
        //O(n)
        priority_queue<int,vector<int>,greater<int>> pq(nums.begin(),nums.end());
        
        //O((n-k)log(k))
        while(pq.size()>k){
             pq.pop();
        }
                     
        return pq.top();
}

int main(){
       
       vector<int> nums = {3,2,1,5,6,4};
       
      
       cout << klarger(nums,2) <<endl;

}        
