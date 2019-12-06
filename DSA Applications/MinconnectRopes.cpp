#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int minCost(vector<int>& num){
    
    if (num.size() ==  0)
        return 0;
        
    priority_queue< int, vector<int>, greater<int> > p_q(num.begin(), num.end());
    
    int res, sum=0;
    
    while (p_q.size() > 1)  {
        res = 0;
        res += p_q.top(); 
        p_q.pop();

        res += p_q.top(); 
        p_q.pop();

        p_q.push(res);
        
        sum +=res;
    }
    return sum;
}


int main(){

      vector<int> num = {2, 2, 3, 3};
      cout<< minCost(num) <<endl;
}
