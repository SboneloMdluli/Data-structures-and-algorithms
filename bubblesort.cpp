#include <vector>
#include <iostream>

using namespace std;


void bubblesort(vector<int> &nums){


	for(int i=0;i<nums.size()-1;i++){
	    for(int j =0; j<nums.size()-1-i;j++){
		
		if(nums[j] > nums[j+1]){
		  swap(nums[j],nums[j+1]);
		}
		nn
	    }
	}

}


int main(){

	vector<int> nums = {1,5,8,1,4,1,11};
	
	bubblesort(nums);
	
	for(auto x: nums){
		cout << x <<" ";
	}
	
	
}
