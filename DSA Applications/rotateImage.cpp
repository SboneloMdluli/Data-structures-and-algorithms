#include <iostream>
#include <vector>
                                     
using namespace std;

void rotate(vector<vector<int>>& grid){

        for(int rows=0; rows<grid.size();rows++){
        
              for(int cols=rows; cols<grid[rows].size();cols++ ){
                   swap(grid[cols][rows],grid[rows][cols]);
              }
        
        }
 
        for(int rows=0; rows<grid.size();rows++){
        
              for(int cols=0; cols<grid[rows].size()/2;cols++ ){
                   int size = grid[rows].size()-1;
                   swap(grid[rows][cols],grid[rows][size-cols]);
              }
        }
                
}


int main(){

        vector<vector<int>> grid={
                {1,2,3},
                {4,5,6},
                {7,8,9}
        };
        
        rotate(grid);
        
        for(auto x: grid){
             for(auto y : x ){
                cout << y <<" ";
             }
             cout <<'\n';
        }        
       
}


