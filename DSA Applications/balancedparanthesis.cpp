// check if string has balanced parenthesis

#include <stack>
#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;

bool balanced_par(string& str){

       if(str.size()==0){
	   return true;
       }

       stack <char> lookup;
       unordered_map <char,char> complement_prthns;
       
       complement_prthns.insert(make_pair('}','{'));
       complement_prthns.insert(make_pair(')','('));
       complement_prthns.insert(make_pair(']','['));
       
       if(str[0] == '}' || str[0] == ')' || str[0]==']')
            return false;

       for(int i=0; i <	str.size() ; i++){
        
          if(str[i] == '{' || str[i] == '(' || str[i]=='[' ){
                         
              lookup.push(str[i]);
          }       
      
      
          if(str[i] == '}' || str[i] == ')' || str[i]==']' ){
              
              auto val = complement_prthns.find(str[i]); 
              
              if(!lookup.empty() && val->second == lookup.top()){
                
                lookup.pop();
               
              }else{
            
                return false;
                
              }
          }   
       
       }
       
       return lookup.empty();
}

int main(){

        string str = "[{{}}(){}]";
        
        if (balanced_par(str))
                cout <<"balanced"<<endl;
        else
               cout << "not balanced"<<endl;
}

