#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void backtrack (vector<int> &nums,vector<vector<int>> &res ,int i){

    if(i == nums.size()){
        res.emplace_back(nums);
    }
    
    for(int j =i; j< nums.size(); j++){
        swap(nums[i],nums[j]);
        backtrack(nums,res,i+1);
        // backtrack
        swap(nums[i],nums[j]);
    }
    
}

vector<vector<int>> permute (vector<int> &nums){
    vector<vector<int>> res;
    backtrack(nums,res,0);
    return res;
    
}

int main()
{
    vector<int> nums = {-1,0,1};

	for(auto x : permute(nums)){
	   for(auto y : x){
		cout << y <<" ";
           }
		cout << '\n';
	}

    return 0;
}

