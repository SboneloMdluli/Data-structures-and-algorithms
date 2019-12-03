//Algorithm to find the occurence of a number in a sorted array 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findOccurences (vector<int>& num,int k){

      //lg(n)
      if(num.size()==0){
           return 0;
      }        
      
      int first = lower_bound(num.begin(),num.end(),k)-num.begin();
      int last = upper_bound(num.begin(),num.end(),k)-num.begin();
      
      return last-first;
}


int main(){

       vector<int> num={1,1,1,1,2,3,4,4,4,4,5,7,12,12,23};
       
       cout << findOccurences(num,4) <<endl;

}
