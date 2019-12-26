// k frequent elements optimised
#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

vector<int> kf(vector<int>& nums, int k){
      
        unordered_map<int,int> lookup;        
        // create map
        for(auto x: nums){
             lookup[x]++;
        }
        
        // create min priority queue
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
         
        // nlg(n) 
        for(auto i : lookup){
             pq.emplace(i.second,i.first);
             
             if(pq.size()>k)
                pq.pop();
        }
        
        vector<int> kfreq;
        
        while(pq.size()>0){
            kfreq.emplace_back(pq.top().second);
            pq.pop();
        }

        return kfreq;
}

int main(){

        vector<int> nums = {1,1,1,2,3,3,2,2};
        int k = 2;
        for(auto x: kf(nums,k)){
           cout << x <<" ";
        }

}
