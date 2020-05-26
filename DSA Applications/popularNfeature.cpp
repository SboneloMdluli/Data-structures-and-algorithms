#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <sstream>
#include <queue>
#include <cctype>
#include <algorithm>

using namespace std;

class cmp{
    public:
    bool operator()(pair<int,string>p,pair<int,string>q){
        if(p.first==q.first){
            return p.second<q.second;  //for alphabetical order
        }
        return p.first>q.first;  
    }
};
bool isNotAlnum(char c) {
    if(c==' ')
        return false;    //when we return false char is not removed
    return isalnum(c) == 0; //isalnum return 1  for alphanumeric
}
vector<string> solution(int k,vector<string>&keywords,vector<string>&reviews){
    unordered_set<string>hashkey;
    unordered_map<string,int>count;
    for(auto s:keywords)//considaring all keywords are lower case else we can convert to lower case.
        hashkey.insert(s);

    for(auto rev:reviews){
        unordered_set<string>added; //
        rev.erase(remove_if(rev.begin(), rev.end(), isNotAlnum), rev.end());
        //delete ! . , ? non alphanum char except ' '//instead of deleting we can replace them with space
        for(auto &c:rev)//convert to lower case
                c=::tolower(c);
       
        istringstream iss(rev);
        string temp;
        while(getline(iss,temp,' ')){
            if(hashkey.find(temp)!=hashkey.end() && added.find(temp)==added.end()){
                count[temp]++;
                added.insert(temp);
            }
        }
    }
    priority_queue<pair<int,string>,vector<pair<int,string>>,cmp>q;
    for(auto m:count){
        q.push(make_pair(m.second,m.first));
        if(q.size()>k)
            q.pop();
    }
    vector<string>res(k);
    int i=k-1;
    while(!q.empty()){
        res[i--]=q.top().second;
        q.pop();
    }
    return res;
}
int main() {
    int k=2;
    vector<string>keywords{ "storage","battery","hover","alexa","waterproof"};
    vector<string>reviews{"I wish my Kindle had even more stoareg",
"I wish the battery life of my Kindle lasted 2 years", "I read in the bath and would enjoy a waterproof Kindle","Waterproof and increased battery are my top two requests","I want to take my Kindle into the shower. Waterproof please waterproof!","It would be neat if my Kindle would hover on my desk when not in use.","How cool would it be if my Kidle charged in the sun via solar power?" };

    vector<string>res = solution(k,keywords,reviews);
    for(auto s:res)
        cout<<s<<" ";
}
