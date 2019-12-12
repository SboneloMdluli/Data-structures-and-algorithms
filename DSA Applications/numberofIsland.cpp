#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& grid, int i, int j){
         
        if(i<0 || i>=grid.size() || j<0 ||j>=grid[i].size() || grid[i][j]!=1){
            return;
        }
              
        if(grid[i][j]==1){
             grid[i][j] = 0;
        } 
        
        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
                     
}

int numIsland(vector<vector<int>>& grid){

        if(grid.size()==0)
             return 0;
        
        int count=0;
        for(int i=0; i<grid.size();i++){
        
            for(int j=0;j<grid[i].size();j++){
                            
                  if(grid[i][j]==1){
                      dfs(grid,i,j);
                       count++;
                   }
              }
        }
        
        return count;

}

int main(){

        vector<vector<int>>grid = {
                {1,1,0,1,0},
                {1,0,0,0,1},
                {0,1,1,0,0}
        
        };

        cout << numIsland(grid) <<endl;
}

