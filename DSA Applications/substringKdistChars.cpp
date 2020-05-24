#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;


vector<string> genKsubstr(string s,int K){
    
    vector<string> res;
    map<string,int> words;
    
    for(int i=0;i<s.size();i++){
        int charset[256] = {0};
        int end = i;
        string substr = "";
      
        while(substr.size()<K && end<s.size()){
            int strVal = int(s[end]);
    
            if(charset[strVal]!=0){
                break;
            }
            substr+=s[end];
            end++;
            charset[strVal]++;
        }
    
 
        auto val = words.find(substr);
        
        if(val == words.end() && substr.size()==K){
            res.push_back(substr);
        }
        
        words[substr]++;
    }
    
    return res;
}


int main()
{
    string s = "awaglknagawunagwkwagl";
    int k = 4;
    vector<string> substringComb = genKsubstr(s,k);
    
    for(auto word: substringComb){
        cout << word << endl;
    }
    
    return 0;
}

