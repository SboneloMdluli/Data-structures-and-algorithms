#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int klarger(vector<int>& nums, int k){

        priority_queue<int,vector<int>,greater<int>> pq;
        
        //O(nlog(k))
        for(int x: nums){
                        
             pq.emplace(x);
             
             if(pq.size()>k){
                pq.pop();
             }
                
        }
        return pq.top();
}

int main(){
       
       vector<int> nums = {3,2,1,5,6,4};
       
      
       cout << klarger(nums,2) <<endl;

}        
