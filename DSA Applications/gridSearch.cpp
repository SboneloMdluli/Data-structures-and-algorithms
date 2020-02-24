//2D binary search O(lg(n))
#include <iostream>
#include <vector>

using namespace std;

bool grid_search(vector<vector<int>>&num, int k){
        
        if(num.size()==0)
              return false;
        
        int left = 0;
        int rows = num.size();
        int cols = num[0].size();
        int right = rows*cols-1;
        int mid;
        
        while(right>=left){
        
           mid = left + (right-left)/2;
           
           if(num[mid/cols][mid%cols]==k){
                return true;
           }
           
           if(num[mid/cols][mid%cols]>k){
              right = mid-1;
           }else{
              left = mid+1;
           }
        
        }
        
        return false;

}

int main(){

        vector<vector<int>> grid = {
        
                {1,3,5,6},
                {7,8,9,10},
                {12,14,20,21}
        
        };
        
        
        if(grid_search(grid,14)){
            cout <<"found"<<endl;
        }

}
