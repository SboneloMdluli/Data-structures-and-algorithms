#include <iostream>
#include <climits>
#include <vector>

using namespace std;

void dfs(vector<vector<char>>& island, int x, int y, int steps,int& res) { 
    if (x < 0 || x >= island.size() || y < 0 || y >= island[0].size() || island[x][y] == 'D' || steps > res) 
        return;
        
    if (island[x][y] == 'X') {
        res = min(res, steps);
        return;
    }

    island[x][y] = 'D';
    dfs (island,x+1,y,steps+1,res);
    dfs (island,x-1,y,steps+1,res);
    dfs (island,x,y+1,steps+1,res);
    dfs (island,x,y-1,steps+1,res);
}

int minStepsDFS(vector<vector<char>>& island) {
    int res = INT_MAX;
    dfs(island,0, 0, 0,res);
    if (res == INT_MAX) {
        return -1;
    }else{
        return res;
    }
}

int main() {
    vector<vector<char>> island = {{'O', 'O', 'O', 'O'},
                                   {'D', 'O', 'D', 'O'},
                                   {'O', 'O', 'O', 'O'}, 
                                   {'X', 'D', 'D', 'O'}};

   

    cout << minStepsDFS(island) << endl;
}
