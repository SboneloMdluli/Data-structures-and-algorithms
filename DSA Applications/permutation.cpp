#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> perm;
        //(nlg(n))
        sort(nums.begin(),nums.end());
    	
	//O(n!)
        do{
            perm.emplace_back(nums);
        
        }while(next_permutation(nums.begin(),nums.end()));
    
        return perm;
}

int main(){

	vector<int> nums = {-1,0,1};

	for(auto x : permute(nums)){
	   for(auto y : x){
		cout << y <<" ";
           }
		cout << '\n';
	}

}
