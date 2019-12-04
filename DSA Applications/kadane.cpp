#include <iostream>
#include <vector>

using namespace std;

int maxSubarry(vector<int>& num){
        
        if(num.size()==0)
            return 0;

        int sum = 0, global_sum =0;
        
        //O(n)
        for(const auto x: num){
             sum += x;
             
             if(sum<0){
                sum =0;
             }
             
             global_sum = max(global_sum,sum); 
        }

        return global_sum;
}


int main(){

        vector<int> num={-10,4,5,5,-4,8,1,0};
        cout << maxSubarry(num) << endl;
 
}
