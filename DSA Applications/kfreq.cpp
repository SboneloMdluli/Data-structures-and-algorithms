// algorithm to return k most frequent elements of an array

#include <iostream>
#include <map>
#include <vector>
#include <utility> 
#include <algorithm>  

using namespace std;

bool compareInterval(pair<int,int> i1, pair<int,int> i2) 
{ 
    return (i1.first > i2.first); 
} 

vector<int> kFrequent(int Arr[], int &k, int &size){
    typedef pair <int, int> pair;
    vector <pair> pairs;
    map<int,int> lookup;    // record occurence
    vector<int> frequency; // maintain frequency
     
    //O(n)
    for(int i =0; i<size; i++){    
        lookup[Arr[i]]++;
    }
        
    //O(n)
    while(auto i: lookup){
        pairs.emplace_back(i.second,i.first);
    }
    
     //O(nlog(n)) 
     sort(pairs.begin(), pairs.end(), compareInterval); 
     
    
     //O(k)
     for(int i=0 ; i<k; i++){
        frequency.emplace_back(pairs[i].second);
     }
    
    return frequency;
}

int main(){

        int Arr[] = {1,1,6,6,6,0,3,4,4};
        int k =3;
        int size = sizeof(Arr)/sizeof(Arr[0]);
        
        for (int& x : kFrequent(Arr,k,size)){
            cout << x <<" ";
        }
}
