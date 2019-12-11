//get min path in O(m*n)

#include <iostream>
#include <vector>

using namespace std;

int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> sum (grid.size(),vector<int>(grid[0].size(),0));
        
        sum[0][0] = grid[0][0];
        
        // compute 1st row path       
        for(int row=1;row<grid.size();row++){
            sum[row][0] = sum[row-1][0] + grid[row][0];
        }
        
        // compute 1st column path
        for(int col=1;col<grid[0].size();col++){
            sum[0][col] = sum[0][col-1] + grid[0][col];
        }
        
        // use dp to get min path to each cell
        for(int row =1;row<grid.size();row++){
            for(int col=1;col<grid[row].size();col++){
                sum[row][col]= min(sum[row][col-1],sum[row-1][col])+grid[row][col];
            }
        }
        
        
        return sum[sum.size()-1][sum[0].size()-1];
}
    
    
int main(){

        vector<vector<int>> grid ={
                {1,3,1},
                {1,5,1},
                {4,2,1}
        };
        
       cout << minPathSum(grid) <<endl;

}
