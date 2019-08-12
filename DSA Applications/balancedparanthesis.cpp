//Program to check if an expression contains balanced paranthesis

#include <stack>
#include <unordered_map>
#include <iostream>

using namespace std;

bool balanced_par(char str[],int &size){

       //O(n) space
       stack <char> lookup;
       unordered_map <char,char> complement_prthns;
       
       //O(1) space
       complement_prthns.insert(make_pair('}','{'));
       complement_prthns.insert(make_pair(')','('));
       complement_prthns.insert(make_pair(']','['));
       
       //O(n) runtime
       if(str[0] == '}' || str[0] == ')' || str[0]==']')
            return false;

       for(int i=0; i <size; i++){
        
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

        char str[] = "[{{}}(){}]";
        int size = sizeof(str)/sizeof(str[0]);
        
        if (balanced_par(str,size))
                cout <<"balanced"<<endl;
        else 
               cout << "not balanced"<<endl;
        
}
