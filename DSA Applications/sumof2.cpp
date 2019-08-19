//algorithm to determine the position on 2 numbers summing to a target value in an array

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector <int> sumOfTwo(int Arr[], const int &target, const int &size){

        unordered_map<int,int> lookup; // number = key, index = value 
        vector <int> IDs;
        
        //O(n)
        for(int i=0; i<size; i++){
        
                int composite = target - Arr[i] -30;
                
                auto val = lookup.find(composite);
                
                if(val != lookup.end() ){ // if such element is found

                     IDs.push_back(i);
                     IDs.push_back(val->second);

                }
                 if(IDs.size()==2){
                       break;
                 }
                
                lookup.insert(make_pair(Arr[i],i));
        
        }
        return IDs;
}

int main(){

        int Vals [] = {100,180,40,120,10};
        int target = 250;
        
        int size = sizeof(Vals)/sizeof(Vals[0]);
       
        vector <int> IDs = sumOfTwo(Vals,target,size);
        
        for(auto &x : IDs){
                cout << x <<" ";
        }

}
