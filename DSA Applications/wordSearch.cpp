#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool dfs(vector<vector<char>>& puzzle, int i, int j, int pos, string& word){

        if(i<0 || i>=puzzle.size() || j<0 || j>=puzzle[i].size() ||puzzle[i][j]!=word[pos] )
               return false;
                    
        if(pos==word.size()-1){
             return true;
        }      
        
        char vis = puzzle[i][j];
        puzzle[i][j] = '*';
        
        bool found = dfs(puzzle, i+1, j, pos+1,word)
                        || dfs(puzzle, i-1,  j, pos+1,word)
                        || dfs(puzzle, i,  j+1, pos+1,word)
                        || dfs(puzzle, i, j-1, pos+1,word);
                       
       puzzle[i][j]=vis;
       
       return found;
}

bool wordFound(vector<vector<char>>& puzzle, string& word ){

      if(puzzle.size()==0||word.size()==0)
          return false;
      
      for(int i=0;i<puzzle.size();i++){
      
          for(int j=0;j<puzzle[i].size();j++){
          
                if(puzzle[i][j]==word[0] && dfs(puzzle, i, j, 0, word)){
                    return true;
                }
           }
      
      }          

      return false;
}

int main(){

        string word ="WEB";
        vector<vector<char>> puzzle = {
                   {'A','B','S'},
                   {'S','E','E'},
                   {'p','W','W',}     
        
        };
        
        if(wordFound(puzzle,word)){
              cout <<"found"<<endl;
        }
        
}
